#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,symmetry_boundary_x,)&&\
CCTK_DECLARE(CCTK_REAL,symmetry_boundary_y,)&&\
CCTK_DECLARE(CCTK_STRING,hyperslabber,)&&\
CCTK_DECLARE(CCTK_INT,check_boundaries,)&&\
CCTK_DECLARE(CCTK_INT,poison_boundaries,)&&\
CCTK_DECLARE(CCTK_INT,poison_value,)&&\
CCTK_DECLARE(CCTK_INT,use_coordbase,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /RotatingSymmetry180priv/symmetry_boundary_x, symmetry_boundary_y, hyperslabber, check_boundaries, poison_boundaries, poison_value, use_coordbase, verbose&&\

