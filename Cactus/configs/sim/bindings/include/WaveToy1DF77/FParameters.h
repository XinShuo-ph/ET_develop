#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,amplitude,)&&\
CCTK_DECLARE(CCTK_REAL,center,)&&\
CCTK_DECLARE(CCTK_REAL,sigma,)&&\
CCTK_DECLARE(CCTK_STRING,bound,)&&\
COMMON /WaveToy1DF77priv/amplitude, center, sigma, bound&&\

