#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,null_rwt,)&&\
CCTK_DECLARE(CCTK_REAL,null_xin,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ev_outside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ghost_pts,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_pts_inside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_stencil_size,)&&\
CCTK_DECLARE(CCTK_INT,N_radial_pts,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /NullGridrest/null_rwt, null_xin, N_ang_ev_outside_eq, N_ang_ghost_pts, N_ang_pts_inside_eq, N_ang_stencil_size, N_radial_pts, verbose&&\

