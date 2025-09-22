#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,tolerance,)&&\
CCTK_DECLARE(CCTK_INT,test_symmetric_interpolation,)&&\
CCTK_DECLARE(CCTK_INT,warn_level,)&&\
COMMON /TestLocalInterp2priv/tolerance, test_symmetric_interpolation, warn_level&&\

