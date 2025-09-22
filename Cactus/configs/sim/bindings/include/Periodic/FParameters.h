#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_INT,check_boundaries,)&&\
CCTK_DECLARE(CCTK_INT,periodic,)&&\
CCTK_DECLARE(CCTK_INT,periodic_x,)&&\
CCTK_DECLARE(CCTK_INT,periodic_y,)&&\
CCTK_DECLARE(CCTK_INT,periodic_z,)&&\
CCTK_DECLARE(CCTK_INT,poison_boundaries,)&&\
CCTK_DECLARE(CCTK_INT,poison_value,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /Periodicpriv/check_boundaries, periodic, periodic_x, periodic_y, periodic_z, poison_boundaries, poison_value, verbose&&\

