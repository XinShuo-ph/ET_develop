#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,amplitude,)&&\
CCTK_DECLARE(CCTK_REAL,sigma,)&&\
CCTK_DECLARE(CCTK_REAL,xcenter,)&&\
CCTK_DECLARE(CCTK_REAL,ycenter,)&&\
CCTK_DECLARE(CCTK_STRING,bound,)&&\
COMMON /WaveToy2DF77priv/amplitude, sigma, xcenter, ycenter, bound&&\

