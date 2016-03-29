// -*-c++-*-
#define SWAP(a,b) {__local void *tmp=a;a=b;b=tmp;}
__kernel void prescan(__global float* vecin,
		      __global float* vecout,
		      unsigned int sz)
{
  int i= get_global_id(0);
  __local float vIn[7];//={ 3, 1, 7, 0, 4, 1, 6, 3 };
  __local float vOutL[8];
  __local float vOutR[8];
  
  
  barrier(CLK_LOCAL_MEM_FENCE);
  vIn[i]=vecin[i];
  barrier(CLK_LOCAL_MEM_FENCE);
  vOutL[i+1]=vecin[i];
  barrier(CLK_LOCAL_MEM_FENCE);
  vOutR[i+1]=vecin[i];
  barrier(CLK_LOCAL_MEM_FENCE);
  vOutL[0]=0.0;
  barrier(CLK_LOCAL_MEM_FENCE);
  vOutR[0]=0.0;
  float tmp;
  
  
  
  for(int offset = 1; offset<sz; offset*=2){
  	barrier(CLK_LOCAL_MEM_FENCE);
  	if(i>=offset){
  		vOutR[i]= vOutL[i] + vOutL[i-offset];
  	}
  	barrier(CLK_LOCAL_MEM_FENCE);
  	tmp=vOutR[i];
  	barrier(CLK_LOCAL_MEM_FENCE);
  	vOutR[i]=vOutL[i];
  	barrier(CLK_LOCAL_MEM_FENCE);
  	vOutL[i]=tmp;
  	barrier(CLK_LOCAL_MEM_FENCE);
  	//SWAP(vOutL,vOutR)
  	
  }
  
  vecout[i]=vOutR[i];
  

}
