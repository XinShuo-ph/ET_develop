#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,stereo_patch_type,)&&\
CCTK_DECLARE(CCTK_INT,deriv_accuracy,)&&\
CCTK_DECLARE(CCTK_INT,poison_test,)&&\
COMMON /NullInterprest/stereo_patch_type, deriv_accuracy, poison_test&&\
CCTK_DECLARE(CCTK_REAL,mask_testinterp_tolerance,)&&\
CCTK_DECLARE(CCTK_REAL,poison_value,)&&\
CCTK_DECLARE(CCTK_STRING,interpolation_name,)&&\
CCTK_DECLARE(CCTK_INT,extended_guard_zone,)&&\
CCTK_DECLARE(CCTK_INT,interpolation_order,)&&\
CCTK_DECLARE(CCTK_INT,skip_interpolation,)&&\
CCTK_DECLARE(CCTK_INT,use_edge_check,)&&\
COMMON /NullInterppriv/mask_testinterp_tolerance, poison_value, interpolation_name, extended_guard_zone, interpolation_order, skip_interpolation, use_edge_check&&\
CCTK_DECLARE(CCTK_REAL,CCTKH1,)&&\
CCTK_DECLARE(CCTK_REAL,CCTKH2,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ev_outside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ghost_pts,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_pts_inside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_stencil_size,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH0,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH3,)&&\
COMMON /NULLGRIDrest/CCTKH1, CCTKH2, N_ang_ev_outside_eq, N_ang_ghost_pts, N_ang_pts_inside_eq, N_ang_stencil_size, CCTKH0, CCTKH3&&\

