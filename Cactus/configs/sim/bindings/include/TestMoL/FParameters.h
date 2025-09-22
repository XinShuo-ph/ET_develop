#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,RHSSlowexpression,)&&\
CCTK_DECLARE(CCTK_STRING,RHSexpression,)&&\
CCTK_DECLARE(CCTK_INT,evolve_grid_array,)&&\
CCTK_DECLARE(CCTK_INT,evolve_grid_function,)&&\
COMMON /TestMoLpriv/RHSSlowexpression, RHSexpression, evolve_grid_array, evolve_grid_function&&\

