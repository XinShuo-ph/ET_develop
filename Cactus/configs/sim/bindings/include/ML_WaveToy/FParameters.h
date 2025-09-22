#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,amplitude,)&&\
CCTK_DECLARE(CCTK_REAL,width,)&&\
CCTK_DECLARE(CCTK_INT,ML_WaveToy_MaxNumArrayEvolvedVars,)&&\
CCTK_DECLARE(CCTK_INT,ML_WaveToy_MaxNumEvolvedVars,)&&\
CCTK_DECLARE(CCTK_INT,WT_Dirichlet_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WT_Dirichlet_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WT_EnergyBoundary_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WT_EnergyBoundary_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WT_Energy_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WT_Energy_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WT_Gaussian_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WT_Gaussian_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WT_RHS_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WT_RHS_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WT_Standing_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WT_Standing_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,other_timelevels,)&&\
CCTK_DECLARE(CCTK_INT,rhs_timelevels,)&&\
CCTK_DECLARE(CCTK_INT,tile_size,)&&\
CCTK_DECLARE(CCTK_INT,timelevels,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /ML_WaveToyrest/amplitude, width, ML_WaveToy_MaxNumArrayEvolvedVars, ML_WaveToy_MaxNumEvolvedVars, WT_Dirichlet_calc_every, WT_Dirichlet_calc_offset, WT_EnergyBoundary_calc_every, WT_EnergyBoundary_calc_offset, WT_Energy_calc_every, WT_Energy_calc_offset, WT_Gaussian_calc_every, WT_Gaussian_calc_offset, WT_RHS_calc_every, WT_RHS_calc_offset, WT_Standing_calc_every, WT_Standing_calc_offset, other_timelevels, rhs_timelevels, tile_size, timelevels, verbose&&\
CCTK_DECLARE(CCTK_REAL,WT_rho_bound_limit,)&&\
CCTK_DECLARE(CCTK_REAL,WT_rho_bound_scalar,)&&\
CCTK_DECLARE(CCTK_REAL,WT_rho_bound_speed,)&&\
CCTK_DECLARE(CCTK_REAL,WT_u_bound_limit,)&&\
CCTK_DECLARE(CCTK_REAL,WT_u_bound_scalar,)&&\
CCTK_DECLARE(CCTK_REAL,WT_u_bound_speed,)&&\
CCTK_DECLARE(CCTK_REAL,rho_bound_limit,)&&\
CCTK_DECLARE(CCTK_REAL,rho_bound_scalar,)&&\
CCTK_DECLARE(CCTK_REAL,rho_bound_speed,)&&\
CCTK_DECLARE(CCTK_REAL,u_bound_limit,)&&\
CCTK_DECLARE(CCTK_REAL,u_bound_scalar,)&&\
CCTK_DECLARE(CCTK_REAL,u_bound_speed,)&&\
CCTK_DECLARE(CCTK_STRING,WT_rho_bound,)&&\
CCTK_DECLARE(CCTK_STRING,WT_u_bound,)&&\
CCTK_DECLARE(CCTK_STRING,initial_data,)&&\
CCTK_DECLARE(CCTK_STRING,rho_bound,)&&\
CCTK_DECLARE(CCTK_STRING,u_bound,)&&\
COMMON /ML_WaveToypriv/WT_rho_bound_limit, WT_rho_bound_scalar, WT_rho_bound_speed, WT_u_bound_limit, WT_u_bound_scalar, WT_u_bound_speed, rho_bound_limit, rho_bound_scalar, rho_bound_speed, u_bound_limit, u_bound_scalar, u_bound_speed, WT_rho_bound, WT_u_bound, initial_data, rho_bound, u_bound&&\
CCTK_DECLARE(CCTK_STRING,CCTKH3,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH4,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH5,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH7,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH0,)&&\
CCTK_DECLARE(CCTK_INT,assume_stress_energy_state,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH1,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH2,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH6,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH8,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH9,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH10,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH11,)&&\
COMMON /GENERICFDrest/CCTKH3, CCTKH4, CCTKH5, CCTKH7, CCTKH0, assume_stress_energy_state, CCTKH1, CCTKH2, CCTKH6, CCTKH8, CCTKH9, CCTKH10, CCTKH11&&\
CCTK_DECLARE(CCTK_INT,CCTKH12,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH13,)&&\
CCTK_DECLARE(CCTK_INT,MoL_Num_ArrayEvolved_Vars,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH14,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH15,)&&\
CCTK_DECLARE(CCTK_INT,MoL_Num_Evolved_Vars,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH16,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH17,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH18,)&&\
COMMON /METHODOFLINESrest/CCTKH12, CCTKH13, MoL_Num_ArrayEvolved_Vars, CCTKH14, CCTKH15, MoL_Num_Evolved_Vars, CCTKH16, CCTKH17, CCTKH18&&\

