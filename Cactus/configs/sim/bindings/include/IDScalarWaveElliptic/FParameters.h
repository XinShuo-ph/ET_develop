#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,charge,)&&\
CCTK_DECLARE(CCTK_REAL,radius,)&&\
CCTK_DECLARE(CCTK_STRING,solver,)&&\
CCTK_DECLARE(CCTK_INT,output_tmp,)&&\
CCTK_DECLARE(CCTK_INT,sor_maxit,)&&\
COMMON /IDScalarWaveEllipticpriv/charge, radius, solver, output_tmp, sor_maxit&&\
CCTK_DECLARE(CCTK_STRING,initial_data,)&&\
COMMON /IDSCALARWAVErest/initial_data&&\

