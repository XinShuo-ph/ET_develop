#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,MinimumDistanceTo2Bp1,)&&\
CCTK_DECLARE(CCTK_REAL,cr,)&&\
CCTK_DECLARE(CCTK_REAL,mass,)&&\
CCTK_DECLARE(CCTK_INT,l_max,)&&\
COMMON /NullSHRExtractrest/MinimumDistanceTo2Bp1, cr, mass, l_max&&\
CCTK_DECLARE(CCTK_REAL,Afact,)&&\
CCTK_DECLARE(CCTK_REAL,elld_min_coef,)&&\
CCTK_DECLARE(CCTK_REAL,fcoef,)&&\
CCTK_DECLARE(CCTK_REAL,rl_min_coef,)&&\
CCTK_DECLARE(CCTK_STRING,SchIEF_time,)&&\
CCTK_DECLARE(CCTK_STRING,WT_metric,)&&\
CCTK_DECLARE(CCTK_INT,WT_spherical_harmonics,)&&\
CCTK_DECLARE(CCTK_INT,WT_spherical_harmonics_on_nullgrid,)&&\
CCTK_DECLARE(CCTK_INT,ana_metric,)&&\
CCTK_DECLARE(CCTK_INT,debug_switch_on,)&&\
CCTK_DECLARE(CCTK_INT,elld_min_pow,)&&\
CCTK_DECLARE(CCTK_INT,halt_on_negative_elld,)&&\
CCTK_DECLARE(CCTK_INT,halt_on_negative_rl,)&&\
CCTK_DECLARE(CCTK_INT,rl_min_pow,)&&\
COMMON /NullSHRExtractpriv/Afact, elld_min_coef, fcoef, rl_min_coef, SchIEF_time, WT_metric, WT_spherical_harmonics, WT_spherical_harmonics_on_nullgrid, ana_metric, debug_switch_on, elld_min_pow, halt_on_negative_elld, halt_on_negative_rl, rl_min_pow&&\
CCTK_DECLARE(CCTK_REAL,CCTKH0,)&&\
CCTK_DECLARE(CCTK_REAL,CCTKH1,)&&\
CCTK_DECLARE(CCTK_REAL,CCTKH2,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH3,)&&\
CCTK_DECLARE(CCTK_INT,cctk_itlast,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH4,)&&\
COMMON /CACTUSrest/CCTKH0, CCTKH1, CCTKH2, CCTKH3, cctk_itlast, CCTKH4&&\
CCTK_DECLARE(CCTK_REAL,CCTKH14,)&&\
CCTK_DECLARE(CCTK_STRING,boundary_data,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH16,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH5,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH6,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH7,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH8,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH9,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH10,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH11,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH12,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH13,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH15,)&&\
CCTK_DECLARE(CCTK_INT,first_order_scheme,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH17,)&&\
COMMON /NULLEVOLVErest/CCTKH14, boundary_data, CCTKH16, CCTKH5, CCTKH6, CCTKH7, CCTKH8, CCTKH9, CCTKH10, CCTKH11, CCTKH12, CCTKH13, CCTKH15, first_order_scheme, CCTKH17&&\
CCTK_DECLARE(CCTK_REAL,null_rwt,)&&\
CCTK_DECLARE(CCTK_REAL,null_xin,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ev_outside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ghost_pts,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_pts_inside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_stencil_size,)&&\
CCTK_DECLARE(CCTK_INT,N_radial_pts,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH18,)&&\
COMMON /NULLGRIDrest/null_rwt, null_xin, N_ang_ev_outside_eq, N_ang_ghost_pts, N_ang_pts_inside_eq, N_ang_stencil_size, N_radial_pts, CCTKH18&&\

