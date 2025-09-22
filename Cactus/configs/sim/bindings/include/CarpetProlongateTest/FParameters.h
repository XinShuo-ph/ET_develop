#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,interp_xmax,)&&\
CCTK_DECLARE(CCTK_REAL,interp_xmin,)&&\
CCTK_DECLARE(CCTK_REAL,interp_ymax,)&&\
CCTK_DECLARE(CCTK_REAL,interp_ymin,)&&\
CCTK_DECLARE(CCTK_REAL,interp_zmax,)&&\
CCTK_DECLARE(CCTK_REAL,interp_zmin,)&&\
CCTK_DECLARE(CCTK_STRING,interpolator,)&&\
CCTK_DECLARE(CCTK_STRING,interpolator_options,)&&\
CCTK_DECLARE(CCTK_STRING,prolongation,)&&\
CCTK_DECLARE(CCTK_INT,interp_nx,)&&\
CCTK_DECLARE(CCTK_INT,interp_ny,)&&\
CCTK_DECLARE(CCTK_INT,interp_nz,)&&\
CCTK_DECLARE(CCTK_INT,power_t,)&&\
CCTK_DECLARE(CCTK_INT,power_x,)&&\
CCTK_DECLARE(CCTK_INT,power_y,)&&\
CCTK_DECLARE(CCTK_INT,power_z,)&&\
COMMON /CarpetProlongateTestpriv/interp_xmax, interp_xmin, interp_ymax, interp_ymin, interp_zmax, interp_zmin, interpolator, interpolator_options, prolongation, interp_nx, interp_ny, interp_nz, power_t, power_x, power_y, power_z&&\

