#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,brill3d_d,)&&\
CCTK_DECLARE(CCTK_REAL,brill3d_e,)&&\
CCTK_DECLARE(CCTK_REAL,brill3d_m,)&&\
CCTK_DECLARE(CCTK_REAL,brill3d_n,)&&\
CCTK_DECLARE(CCTK_REAL,brill3d_phi0,)&&\
CCTK_DECLARE(CCTK_REAL,const_v0,)&&\
CCTK_DECLARE(CCTK_REAL,eppley_a,)&&\
CCTK_DECLARE(CCTK_REAL,eppley_r0,)&&\
CCTK_DECLARE(CCTK_REAL,eppley_sigmar,)&&\
CCTK_DECLARE(CCTK_REAL,eppley_sigmarho,)&&\
CCTK_DECLARE(CCTK_REAL,exp_a,)&&\
CCTK_DECLARE(CCTK_REAL,exp_rho0,)&&\
CCTK_DECLARE(CCTK_REAL,exp_sigmaz,)&&\
CCTK_DECLARE(CCTK_REAL,gundlach_a,)&&\
CCTK_DECLARE(CCTK_REAL,gundlach_r0,)&&\
CCTK_DECLARE(CCTK_REAL,gundlach_sigmar,)&&\
CCTK_DECLARE(CCTK_REAL,gundlach_sigmarho,)&&\
CCTK_DECLARE(CCTK_REAL,rhofudge,)&&\
CCTK_DECLARE(CCTK_REAL,robin_inf,)&&\
CCTK_DECLARE(CCTK_REAL,thresh,)&&\
CCTK_DECLARE(CCTK_STRING,bound,)&&\
CCTK_DECLARE(CCTK_STRING,q_function,)&&\
CCTK_DECLARE(CCTK_STRING,solver,)&&\
CCTK_DECLARE(CCTK_INT,eppley_b,)&&\
CCTK_DECLARE(CCTK_INT,eppley_c,)&&\
CCTK_DECLARE(CCTK_INT,exp_b,)&&\
CCTK_DECLARE(CCTK_INT,gundlach_b,)&&\
CCTK_DECLARE(CCTK_INT,gundlach_c,)&&\
CCTK_DECLARE(CCTK_INT,output_coeffs,)&&\
CCTK_DECLARE(CCTK_INT,robin_falloff,)&&\
CCTK_DECLARE(CCTK_INT,sor_maxit,)&&\
COMMON /IDBrillDatapriv/brill3d_d, brill3d_e, brill3d_m, brill3d_n, brill3d_phi0, const_v0, eppley_a, eppley_r0, eppley_sigmar, eppley_sigmarho, exp_a, exp_rho0, exp_sigmaz, gundlach_a, gundlach_r0, gundlach_sigmar, gundlach_sigmarho, rhofudge, robin_inf, thresh, bound, q_function, solver, eppley_b, eppley_c, exp_b, gundlach_b, gundlach_c, output_coeffs, robin_falloff, sor_maxit&&\
CCTK_DECLARE(CCTK_STRING,CCTKH0,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH1,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH2,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH3,)&&\
CCTK_DECLARE(CCTK_STRING,initial_data,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH4,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH5,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH6,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH7,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH8,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH9,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH11,)&&\
CCTK_DECLARE(CCTK_STRING,metric_type,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH13,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH14,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH10,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH12,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH15,)&&\
COMMON /ADMBASErest/CCTKH0, CCTKH1, CCTKH2, CCTKH3, initial_data, CCTKH4, CCTKH5, CCTKH6, CCTKH7, CCTKH8, CCTKH9, CCTKH11, metric_type, CCTKH13, CCTKH14, CCTKH10, CCTKH12, CCTKH15&&\
CCTK_DECLARE(CCTK_STRING,conformal_storage,)&&\
COMMON /STATICCONFORMALrest/conformal_storage&&\

