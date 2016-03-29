#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <stdexcept>
#include <CL/cl.h>

using namespace std;


char *cl_get_platform_info(cl_platform_id platform, cl_platform_info param_name)
{
  char *info;
  size_t sz;
  clGetPlatformInfo(platform,param_name,0, nullptr,&sz);
  info=new char[sz];
  clGetPlatformInfo(platform,param_name,sz,info,nullptr);
  return info;
}

char *cl_get_device_info(cl_device_id device, cl_device_info param_name)
{
  char *info;
  size_t sz;
  clGetDeviceInfo(device,param_name,0, nullptr,&sz);
  info=new char[sz];
  clGetDeviceInfo(device,param_name,sz,info,nullptr);
  return info;
}



int main(void)
{
  try {
    cl_platform_id *platforms;
    cl_uint nplatforms;
    cl_int err;

    const cl_uint vecsz = 8;
    float vec[vecsz] = { 3, 1, 7, 0, 4, 1, 6, 3 };
    float vecout[vecsz]; // Result of the prescan
    
    // Detect platforms available
    err = clGetPlatformIDs(0,nullptr,&nplatforms);
    if (err != CL_SUCCESS) {
      throw runtime_error("No platform available!");
    }

    cout << nplatforms << " platform(s) found." << endl;
    platforms = new cl_platform_id[nplatforms];
    clGetPlatformIDs(nplatforms,platforms,nullptr);
    for (unsigned int i = 0; i < nplatforms; ++i) {
      char * name = cl_get_platform_info(platforms[0],CL_PLATFORM_NAME);
      char * vendor = cl_get_platform_info(platforms[0],CL_PLATFORM_VENDOR);
      cout << name << "\n" << vendor << endl;
      delete[] name;
      delete[] vendor;
    }
    cl_device_id device;
    cl_uint num_devices;
    unsigned int i;
    bool device_found = false;
    // Searching for a platform with any device
    for (i = 0; i < nplatforms; ++i) {
      err = clGetDeviceIDs(platforms[i],CL_DEVICE_TYPE_ALL,0,nullptr,
			   &num_devices);
      device_found = (err == CL_SUCCESS && num_devices > 0);
      if (device_found) {
	break;
      }
    }
    if (!device_found) throw runtime_error("No device available");
    clGetDeviceIDs(platforms[i],CL_DEVICE_TYPE_ALL,1,&device,nullptr);
    char *name = cl_get_device_info(device,CL_DEVICE_NAME);
    char *vendor = cl_get_device_info(device,CL_DEVICE_VENDOR);
    cout << "Device found: " << endl;
    cout << name << "\n" << vendor << endl;
    
    // Creating the context
    cl_context context = clCreateContext(nullptr,1,&device,nullptr,
					 nullptr,&err);
    if (err != CL_SUCCESS) throw runtime_error("Could not create a context!");
    
    // Creating the program to be run on the GPU
    ifstream fic("prescan.cl");
    string program_buffer((std::istreambuf_iterator<char>(fic)),
			  std::istreambuf_iterator<char>());
    size_t program_size=program_buffer.size();
    const char* buf = program_buffer.c_str();
    cl_program program = clCreateProgramWithSource(context,1,
						   (const char**)(&buf),
						   &program_size,
						   &err);
    if (err != CL_SUCCESS) throw runtime_error("Could not create a program!");
    
    err = clBuildProgram(program,1,&device,nullptr,nullptr,nullptr);
    if (err != CL_SUCCESS) {
      size_t log_size;
      char *program_log;
      /* Find size of log and print to std output */
      clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 
			    0, nullptr, &log_size);
      program_log = new char[log_size + 1];
      program_log[log_size] = '\0';
      clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 
			    log_size + 1, program_log, nullptr);
      cout << program_log << endl;
      delete[] program_log;
      
      throw runtime_error("Could not build the program!");
    }
    
    cl_kernel kernel = clCreateKernel(program,"prescan",&err);
    if (err != CL_SUCCESS) {
      throw runtime_error("Could not create the kernel prescan");
    }

    // Creating the buffers for exchanging data
    cl_mem inbuf, outbuf;
    
    inbuf = clCreateBuffer(context,CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
			  sizeof(vec),vec,&err);
    if (err != CL_SUCCESS) {
      throw runtime_error("Could not create a buffer for vec!");
    }
    outbuf = clCreateBuffer(context,CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR,
			  sizeof(vecout),vecout,&err);
    if (err != CL_SUCCESS) {
      throw runtime_error("Could not create a buffer for vecout!");
    }

    // Creating the argument for the kernel
    clSetKernelArg(kernel,0,sizeof(cl_mem),&inbuf);
    clSetKernelArg(kernel,1,sizeof(cl_mem),&outbuf);
    clSetKernelArg(kernel,2,sizeof(cl_uint),&vecsz);

    
    // Creating the command queue for the GPU
    cl_command_queue queue = clCreateCommandQueue(context, device, 0,&err);
    if (err != CL_SUCCESS) {
      throw runtime_error("Could not create a command queue!");
    }

    // 1 dim, 'vecsz' work-items/ 1 workgroup for all
    size_t local_ws[1] = { vecsz }; 
    size_t global_ws[1] = { vecsz }; 
    // Enqueueing the kernel to execute it on the GPU
    err = clEnqueueNDRangeKernel(queue,kernel,1,nullptr,
				 global_ws,local_ws,0,nullptr,nullptr);
    if (err != CL_SUCCESS) {
      throw runtime_error("Could not enqueue the kernel!");
    }
    // Read the output
    err = clEnqueueReadBuffer(queue,outbuf,CL_TRUE,0,
			      sizeof(vecout),vecout,0,
			      nullptr,nullptr);
    if (err != CL_SUCCESS) {
      throw runtime_error("Could not enqueue the reading command for vecout!");
    }

    // Printing the result
    for (size_t i=0; i < vecsz; ++i) {
      cout << vecout[i] << " ";
    }
    cout << "\n";


    // Freeing all resources
    clReleaseMemObject(inbuf);
    clReleaseMemObject(outbuf);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(queue);
    clReleaseProgram(program);
    clReleaseContext(context);
    
  } catch (const exception& e) {
    cout << e.what() << endl;
  }
}
