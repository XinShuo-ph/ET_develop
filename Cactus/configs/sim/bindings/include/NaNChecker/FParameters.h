#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,action_if_found,)&&\
CCTK_DECLARE(CCTK_STRING,check_for,)&&\
CCTK_DECLARE(CCTK_STRING,check_vars,)&&\
CCTK_DECLARE(CCTK_STRING,restriction_mask,)&&\
CCTK_DECLARE(CCTK_STRING,verbose,)&&\
CCTK_DECLARE(CCTK_INT,check_after,)&&\
CCTK_DECLARE(CCTK_INT,check_every,)&&\
CCTK_DECLARE(CCTK_INT,ignore_restricted_points,)&&\
CCTK_DECLARE(CCTK_INT,out_NaNmask,)&&\
CCTK_DECLARE(CCTK_INT,report_max,)&&\
COMMON /NaNCheckerpriv/action_if_found, check_for, check_vars, restriction_mask, verbose, check_after, check_every, ignore_restricted_points, out_NaNmask, report_max&&\

