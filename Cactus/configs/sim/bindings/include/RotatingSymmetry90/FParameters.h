#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_INT,check_boundaries,)&&\
CCTK_DECLARE(CCTK_INT,poison_boundaries,)&&\
CCTK_DECLARE(CCTK_INT,poison_value,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /RotatingSymmetry90priv/check_boundaries, poison_boundaries, poison_value, verbose&&\

