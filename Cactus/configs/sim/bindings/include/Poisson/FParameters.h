#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,charge,)&&\
CCTK_DECLARE(CCTK_REAL,radius,)&&\
CCTK_DECLARE(CCTK_STRING,options,)&&\
CCTK_DECLARE(CCTK_STRING,solver,)&&\
COMMON /Poissonpriv/charge, radius, options, solver&&\

