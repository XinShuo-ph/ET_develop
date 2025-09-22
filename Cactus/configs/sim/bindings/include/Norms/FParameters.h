#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,gridfunctions_1st,)&&\
CCTK_DECLARE(CCTK_STRING,gridfunctions_2nd,)&&\
CCTK_DECLARE(CCTK_INT,max_nr_vars,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /Normspriv/gridfunctions_1st, gridfunctions_2nd, max_nr_vars, verbose&&\

