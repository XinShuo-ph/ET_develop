#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_INT,periodic,)&&\
CCTK_DECLARE(CCTK_INT,periodic_x,)&&\
CCTK_DECLARE(CCTK_INT,periodic_y,)&&\
CCTK_DECLARE(CCTK_INT,periodic_z,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /PeriodicCarpetpriv/periodic, periodic_x, periodic_y, periodic_z, verbose&&\

