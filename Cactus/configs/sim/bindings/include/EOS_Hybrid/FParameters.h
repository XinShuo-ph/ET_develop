#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,eos_gamma_supernuclear,)&&\
CCTK_DECLARE(CCTK_REAL,eos_gamma_th,)&&\
CCTK_DECLARE(CCTK_REAL,rho_nuc,)&&\
COMMON /EOS_Hybridrest/eos_gamma_supernuclear, eos_gamma_th, rho_nuc&&\
CCTK_DECLARE(CCTK_REAL,eos_gamma,)&&\
CCTK_DECLARE(CCTK_REAL,eos_k,)&&\
CCTK_DECLARE(CCTK_REAL,gamma_ini,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH0,)&&\
COMMON /EOS_2D_POLYTROPErest/eos_gamma, eos_k, gamma_ini, CCTKH0&&\

