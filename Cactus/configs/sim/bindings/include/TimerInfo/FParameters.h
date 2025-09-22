#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,clock,)&&\
CCTK_DECLARE(CCTK_STRING,timer,)&&\
CCTK_DECLARE(CCTK_INT,every,)&&\
COMMON /TimerInfopriv/clock, timer, every&&\

