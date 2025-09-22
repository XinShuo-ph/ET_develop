#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,enforce_vars,)&&\
CCTK_DECLARE(CCTK_INT,enforce_mask,)&&\
CCTK_DECLARE(CCTK_INT,enlarge_evolved_region_by,)&&\
CCTK_DECLARE(CCTK_INT,provide_buffer_mask,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
CCTK_DECLARE(CCTK_INT,writeNaNs,)&&\
COMMON /CarpetEvolutionMaskpriv/enforce_vars, enforce_mask, enlarge_evolved_region_by, provide_buffer_mask, verbose, writeNaNs&&\

