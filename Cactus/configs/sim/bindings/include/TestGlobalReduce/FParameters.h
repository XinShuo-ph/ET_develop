#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,amplitude,)&&\
CCTK_DECLARE(CCTK_REAL,radius,)&&\
CCTK_DECLARE(CCTK_REAL,sigma,)&&\
CCTK_DECLARE(CCTK_REAL,uniform_weight_value,)&&\
CCTK_DECLARE(CCTK_INT,array_nx,)&&\
CCTK_DECLARE(CCTK_INT,array_ny,)&&\
CCTK_DECLARE(CCTK_INT,array_nz,)&&\
CCTK_DECLARE(CCTK_INT,dest_proc,)&&\
CCTK_DECLARE(CCTK_INT,map_x,)&&\
CCTK_DECLARE(CCTK_INT,map_y,)&&\
CCTK_DECLARE(CCTK_INT,map_z,)&&\
COMMON /TestGlobalReducepriv/amplitude, radius, sigma, uniform_weight_value, array_nx, array_ny, array_nz, dest_proc, map_x, map_y, map_z&&\

