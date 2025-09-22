#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,interp_radius,)&&\
CCTK_DECLARE(CCTK_INT,arrsize,)&&\
CCTK_DECLARE(CCTK_INT,interpolation_order,)&&\
COMMON /DemoInterppriv/interp_radius, arrsize, interpolation_order&&\

