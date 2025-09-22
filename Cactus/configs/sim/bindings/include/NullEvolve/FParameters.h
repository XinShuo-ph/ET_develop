#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,Diagnostics_Coord_x,)&&\
CCTK_DECLARE(CCTK_STRING,boundary_data,)&&\
CCTK_DECLARE(CCTK_STRING,initial_J_data,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_B_update,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_CB_update,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_CK_update,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_J_update,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_NU_update,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_Q_update,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_U_update,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_W_update,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_evolution,)&&\
CCTK_DECLARE(CCTK_INT,debug_verbose,)&&\
CCTK_DECLARE(CCTK_INT,first_order_scheme,)&&\
CCTK_DECLARE(CCTK_INT,old_J_xderiv,)&&\
COMMON /NullEvolverest/Diagnostics_Coord_x, boundary_data, initial_J_data, DEBUG_skip_B_update, DEBUG_skip_CB_update, DEBUG_skip_CK_update, DEBUG_skip_J_update, DEBUG_skip_NU_update, DEBUG_skip_Q_update, DEBUG_skip_U_update, DEBUG_skip_W_update, DEBUG_skip_evolution, debug_verbose, first_order_scheme, old_J_xderiv&&\
CCTK_DECLARE(CCTK_REAL,ID_AMP,)&&\
CCTK_DECLARE(CCTK_REAL,Jcoeff_r0,)&&\
CCTK_DECLARE(CCTK_REAL,Jcoeff_r0i,)&&\
CCTK_DECLARE(CCTK_REAL,Jcoeff_r0r,)&&\
CCTK_DECLARE(CCTK_REAL,Jcoeff_r1,)&&\
CCTK_DECLARE(CCTK_REAL,Jcoeff_r1i,)&&\
CCTK_DECLARE(CCTK_REAL,Jcoeff_r1r,)&&\
CCTK_DECLARE(CCTK_REAL,Jcoeff_r3,)&&\
CCTK_DECLARE(CCTK_REAL,Jcoeff_r3i,)&&\
CCTK_DECLARE(CCTK_REAL,Jcoeff_r3r,)&&\
CCTK_DECLARE(CCTK_REAL,N_dissip_one_outside_eq,)&&\
CCTK_DECLARE(CCTK_REAL,N_dissip_zero_outside_eq,)&&\
CCTK_DECLARE(CCTK_REAL,dissip_J,)&&\
CCTK_DECLARE(CCTK_REAL,dissip_Jx,)&&\
CCTK_DECLARE(CCTK_REAL,dissip_Q,)&&\
CCTK_DECLARE(CCTK_REAL,dissip_W,)&&\
CCTK_DECLARE(CCTK_REAL,dissip_fudge_maxx,)&&\
CCTK_DECLARE(CCTK_REAL,null_dissip,)&&\
CCTK_DECLARE(CCTK_REAL,psmax,)&&\
CCTK_DECLARE(CCTK_REAL,psmin,)&&\
CCTK_DECLARE(CCTK_REAL,qsmax,)&&\
CCTK_DECLARE(CCTK_REAL,qsmin,)&&\
CCTK_DECLARE(CCTK_REAL,wrot,)&&\
CCTK_DECLARE(CCTK_REAL,xmax,)&&\
CCTK_DECLARE(CCTK_REAL,xmin,)&&\
CCTK_DECLARE(CCTK_STRING,dissip_mask_type,)&&\
CCTK_DECLARE(CCTK_INT,ID_POWER,)&&\
CCTK_DECLARE(CCTK_INT,ID_l,)&&\
CCTK_DECLARE(CCTK_INT,ID_m,)&&\
CCTK_DECLARE(CCTK_INT,dissip_fudge,)&&\
CCTK_DECLARE(CCTK_INT,use_rsYlm,)&&\
COMMON /NullEvolvepriv/ID_AMP, Jcoeff_r0, Jcoeff_r0i, Jcoeff_r0r, Jcoeff_r1, Jcoeff_r1i, Jcoeff_r1r, Jcoeff_r3, Jcoeff_r3i, Jcoeff_r3r, N_dissip_one_outside_eq, N_dissip_zero_outside_eq, dissip_J, dissip_Jx, dissip_Q, dissip_W, dissip_fudge_maxx, null_dissip, psmax, psmin, qsmax, qsmin, wrot, xmax, xmin, dissip_mask_type, ID_POWER, ID_l, ID_m, dissip_fudge, use_rsYlm&&\
CCTK_DECLARE(CCTK_REAL,CCTKH0,)&&\
CCTK_DECLARE(CCTK_REAL,cctk_initial_time,)&&\
CCTK_DECLARE(CCTK_REAL,CCTKH1,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH2,)&&\
CCTK_DECLARE(CCTK_INT,cctk_itlast,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH3,)&&\
COMMON /CACTUSrest/CCTKH0, cctk_initial_time, CCTKH1, CCTKH2, cctk_itlast, CCTKH3&&\
CCTK_DECLARE(CCTK_REAL,null_rwt,)&&\
CCTK_DECLARE(CCTK_REAL,null_xin,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ev_outside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ghost_pts,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_pts_inside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_stencil_size,)&&\
CCTK_DECLARE(CCTK_INT,N_radial_pts,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH4,)&&\
COMMON /NULLGRIDrest/null_rwt, null_xin, N_ang_ev_outside_eq, N_ang_ghost_pts, N_ang_pts_inside_eq, N_ang_stencil_size, N_radial_pts, CCTKH4&&\
CCTK_DECLARE(CCTK_STRING,CCTKH6,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH5,)&&\
CCTK_DECLARE(CCTK_INT,poison_test,)&&\
COMMON /NULLINTERPrest/CCTKH6, CCTKH5, poison_test&&\
CCTK_DECLARE(CCTK_STRING,timestep_method,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH7,)&&\
COMMON /TIMErest/timestep_method, CCTKH7&&\

