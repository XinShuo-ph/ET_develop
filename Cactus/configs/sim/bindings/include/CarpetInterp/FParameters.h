#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,ipoison,)&&\
CCTK_DECLARE(CCTK_REAL,poison,)&&\
CCTK_DECLARE(CCTK_INT,barriers,)&&\
CCTK_DECLARE(CCTK_INT,check_tree_search,)&&\
CCTK_DECLARE(CCTK_INT,tree_search,)&&\
COMMON /CarpetInterppriv/ipoison, poison, barriers, check_tree_search, tree_search&&\

