#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,options,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
CCTK_DECLARE(CCTK_INT,veryverbose,)&&\
COMMON /TATPETScpriv/options, verbose, veryverbose&&\

