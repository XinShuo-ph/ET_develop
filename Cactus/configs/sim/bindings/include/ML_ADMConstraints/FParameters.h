#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_INT,ML_ADMConstraints_MaxNumArrayEvolvedVars,)&&\
CCTK_DECLARE(CCTK_INT,ML_ADMConstraints_MaxNumEvolvedVars,)&&\
CCTK_DECLARE(CCTK_INT,ML_ADMConstraints_evaluate_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,ML_ADMConstraints_evaluate_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,other_timelevels,)&&\
CCTK_DECLARE(CCTK_INT,rhs_timelevels,)&&\
CCTK_DECLARE(CCTK_INT,tile_size,)&&\
CCTK_DECLARE(CCTK_INT,timelevels,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /ML_ADMConstraintsrest/ML_ADMConstraints_MaxNumArrayEvolvedVars, ML_ADMConstraints_MaxNumEvolvedVars, ML_ADMConstraints_evaluate_calc_every, ML_ADMConstraints_evaluate_calc_offset, other_timelevels, rhs_timelevels, tile_size, timelevels, verbose&&\
CCTK_DECLARE(CCTK_STRING,jacobian_derivative_group,)&&\
CCTK_DECLARE(CCTK_STRING,jacobian_determinant_group,)&&\
CCTK_DECLARE(CCTK_STRING,jacobian_group,)&&\
CCTK_DECLARE(CCTK_STRING,jacobian_inverse_group,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH0,)&&\
CCTK_DECLARE(CCTK_INT,assume_stress_energy_state,)&&\
CCTK_DECLARE(CCTK_INT,assume_use_jacobian,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH1,)&&\
CCTK_DECLARE(CCTK_INT,jacobian_identity_map,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH2,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH3,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH4,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH5,)&&\
COMMON /GENERICFDrest/jacobian_derivative_group, jacobian_determinant_group, jacobian_group, jacobian_inverse_group, CCTKH0, assume_stress_energy_state, assume_use_jacobian, CCTKH1, jacobian_identity_map, CCTKH2, CCTKH3, CCTKH4, CCTKH5&&\
CCTK_DECLARE(CCTK_INT,CCTKH6,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH7,)&&\
CCTK_DECLARE(CCTK_INT,MoL_Num_ArrayEvolved_Vars,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH8,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH9,)&&\
CCTK_DECLARE(CCTK_INT,MoL_Num_Evolved_Vars,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH10,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH11,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH12,)&&\
COMMON /METHODOFLINESrest/CCTKH6, CCTKH7, MoL_Num_ArrayEvolved_Vars, CCTKH8, CCTKH9, MoL_Num_Evolved_Vars, CCTKH10, CCTKH11, CCTKH12&&\

