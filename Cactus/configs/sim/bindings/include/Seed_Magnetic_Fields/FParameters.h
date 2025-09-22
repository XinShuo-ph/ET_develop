#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,A_b,)&&\
CCTK_DECLARE(CCTK_REAL,P_cut,)&&\
CCTK_DECLARE(CCTK_REAL,n_s,)&&\
CCTK_DECLARE(CCTK_INT,enable_IllinoisGRMHD_staggered_A_fields,)&&\
COMMON /seed_magnetic_fieldsrest/A_b, P_cut, n_s, enable_IllinoisGRMHD_staggered_A_fields&&\

