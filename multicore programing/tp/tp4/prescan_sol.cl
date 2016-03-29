// -*-c++-*-
__kernel void prescan(__global float* vecin,
		      __global float* vecout,
		      unsigned int sz)
{
  __local float dbuf[256];

  int id = get_global_id(0);
  int vout = 0, vin = 1;

  dbuf[vout*sz+id] = (id > 0) ? vecin[id-1] : 0.0;
  barrier(CLK_LOCAL_MEM_FENCE);
  for (int ofs = 1; ofs < sz; ofs *=2) {
    vout = 1 - vout;
    vin = 1 - vin;
    dbuf[vout*sz+id] = dbuf[vin*sz+id];
    if (id >= ofs) {
      dbuf[vout*sz+id] += dbuf[vin*sz+id-ofs];
    }
    barrier(CLK_LOCAL_MEM_FENCE);
  }
  vecout[id] = dbuf[vout*sz+id];
}
