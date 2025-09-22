#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_INT,NullPsiInt_MaxEvolvedArraySize,)&&\
CCTK_DECLARE(CCTK_INT,NullPsiInt_NumArrayEvolvedVars,)&&\
COMMON /NullPsiIntrest/NullPsiInt_MaxEvolvedArraySize, NullPsiInt_NumArrayEvolvedVars&&\
CCTK_DECLARE(CCTK_STRING,mask_type,)&&\
COMMON /NullPsiIntpriv/mask_type&&\
CCTK_DECLARE(CCTK_INT,MoL_Max_Evolved_Array_Size,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH0,)&&\
CCTK_DECLARE(CCTK_INT,MoL_Num_ArrayEvolved_Vars,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH1,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH2,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH3,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH4,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH5,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH6,)&&\
COMMON /METHODOFLINESrest/MoL_Max_Evolved_Array_Size, CCTKH0, MoL_Num_ArrayEvolved_Vars, CCTKH1, CCTKH2, CCTKH3, CCTKH4, CCTKH5, CCTKH6&&\
CCTK_DECLARE(CCTK_REAL,CCTKH7,)&&\
CCTK_DECLARE(CCTK_REAL,CCTKH8,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ev_outside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_ghost_pts,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_pts_inside_eq,)&&\
CCTK_DECLARE(CCTK_INT,N_ang_stencil_size,)&&\
CCTK_DECLARE(CCTK_INT,N_radial_pts,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH9,)&&\
COMMON /NULLGRIDrest/CCTKH7, CCTKH8, N_ang_ev_outside_eq, N_ang_ghost_pts, N_ang_pts_inside_eq, N_ang_stencil_size, N_radial_pts, CCTKH9&&\

