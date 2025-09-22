#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,eos_gamma,)&&\
CCTK_DECLARE(CCTK_REAL,eos_k,)&&\
CCTK_DECLARE(CCTK_REAL,gamma_ini,)&&\
CCTK_DECLARE(CCTK_INT,use_cgs,)&&\
COMMON /EOS_2d_Polytroperest/eos_gamma, eos_k, gamma_ini, use_cgs&&\

