#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,amplitude,)&&\
CCTK_DECLARE(CCTK_STRING,bc_vars,)&&\
CCTK_DECLARE(CCTK_STRING,id_vars,)&&\
CCTK_DECLARE(CCTK_INT,apply_bc_noise,)&&\
CCTK_DECLARE(CCTK_INT,apply_id_noise,)&&\
CCTK_DECLARE(CCTK_INT,noise_boundaries,(6))&&\
CCTK_DECLARE(CCTK_INT,noise_stencil,(3))&&\
COMMON /Noisepriv/amplitude, bc_vars, id_vars, apply_bc_noise, apply_id_noise, noise_boundaries, noise_stencil&&\

