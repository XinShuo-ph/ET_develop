#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_INT,linearized_news,)&&\
COMMON /NullNewsrest/linearized_news&&\
CCTK_DECLARE(CCTK_REAL,eps_omega,)&&\
CCTK_DECLARE(CCTK_INT,DEBUG_skip_BondiNews,)&&\
CCTK_DECLARE(CCTK_INT,Jl_deriv_order,)&&\
CCTK_DECLARE(CCTK_INT,NewsSpinWeight,)&&\
CCTK_DECLARE(CCTK_INT,Ylm_at_Scri,)&&\
CCTK_DECLARE(CCTK_INT,compute_lin_strain,)&&\
CCTK_DECLARE(CCTK_INT,debug_output,)&&\
CCTK_DECLARE(CCTK_INT,filter_news,)&&\
CCTK_DECLARE(CCTK_INT,filter_omega,)&&\
CCTK_DECLARE(CCTK_INT,filter_scri_fields,)&&\
CCTK_DECLARE(CCTK_INT,first_order_scheme,)&&\
CCTK_DECLARE(CCTK_INT,interp_to_constant_uBondi,)&&\
CCTK_DECLARE(CCTK_INT,l_YlmScri,)&&\
CCTK_DECLARE(CCTK_INT,linearized_inertial_frame,)&&\
CCTK_DECLARE(CCTK_INT,m_YlmScri,)&&\
CCTK_DECLARE(CCTK_INT,mask_NewsB,)&&\
CCTK_DECLARE(CCTK_INT,mask_Psi4,)&&\
CCTK_DECLARE(CCTK_INT,max_timelevels,)&&\
CCTK_DECLARE(CCTK_INT,news_interp_order,)&&\
CCTK_DECLARE(CCTK_INT,use_linearized_omega,)&&\
CCTK_DECLARE(CCTK_INT,write_spherical_harmonics,)&&\
COMMON /NullNewspriv/eps_omega, DEBUG_skip_BondiNews, Jl_deriv_order, NewsSpinWeight, Ylm_at_Scri, compute_lin_strain, debug_output, filter_news, filter_omega, filter_scri_fields, first_order_scheme, interp_to_constant_uBondi, l_YlmScri, linearized_inertial_frame, m_YlmScri, mask_NewsB, mask_Psi4, max_timelevels, news_interp_order, use_linearized_omega, write_spherical_harmonics&&\
CCTK_DECLARE(CCTK_REAL,CCTKH0,)&&\
CCTK_DECLARE(CCTK_REAL,CCTKH1,)&&\
CCTK_DECLARE(CCTK_REAL,CCTKH2,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH3,)&&\
CCTK_DECLARE(CCTK_INT,cctk_itlast,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH4,)&&\
COMMON /CACTUSrest/CCTKH0, CCTKH1, CCTKH2, CCTKH3, cctk_itlast, CCTKH4&&\
CCTK_DECLARE(CCTK_REAL,null_rwt,)&&\
CCTK_DECLARE(CCTK_REAL,CCTKH5,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ev_outside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ghost_pts,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_pts_inside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_stencil_size,)&&\
CCTK_DECLARE(CCTK_INT,N_radial_pts,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH6,)&&\
COMMON /NULLGRIDrest/null_rwt, CCTKH5, N_ang_ev_outside_eq, N_ang_ghost_pts, N_ang_pts_inside_eq, N_ang_stencil_size, N_radial_pts, CCTKH6&&\

