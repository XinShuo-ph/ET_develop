#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,custom_bound,)&&\
CCTK_DECLARE(CCTK_STRING,custom_options,)&&\
COMMON /WaveToyExtrapriv/custom_bound, custom_options&&\
CCTK_DECLARE(CCTK_STRING,bound,)&&\
COMMON /WAVETOYrest/bound&&\

