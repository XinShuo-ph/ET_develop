#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,offset,)&&\
CCTK_DECLARE(CCTK_REAL,xorig,)&&\
CCTK_DECLARE(CCTK_REAL,yorig,)&&\
CCTK_DECLARE(CCTK_REAL,zorig,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_MaxNumArrayEvolvedVars,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_MaxNumEvolvedVars,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_invars_calc_2nd_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_invars_calc_2nd_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_invars_calc_4th_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_invars_calc_4th_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_invars_calc_Nth_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_invars_calc_Nth_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psi4_calc_2nd_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psi4_calc_2nd_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psi4_calc_4th_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psi4_calc_4th_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psi4_calc_Nth_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psi4_calc_Nth_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psis_calc_2nd_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psis_calc_2nd_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psis_calc_4th_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psis_calc_4th_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psis_calc_Nth_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,WeylScal4_psis_calc_Nth_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,fdOrder,)&&\
CCTK_DECLARE(CCTK_INT,other_timelevels,)&&\
CCTK_DECLARE(CCTK_INT,rhs_timelevels,)&&\
CCTK_DECLARE(CCTK_INT,tile_size,)&&\
CCTK_DECLARE(CCTK_INT,timelevels,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /WeylScal4rest/offset, xorig, yorig, zorig, WeylScal4_MaxNumArrayEvolvedVars, WeylScal4_MaxNumEvolvedVars, WeylScal4_invars_calc_2nd_calc_every, WeylScal4_invars_calc_2nd_calc_offset, WeylScal4_invars_calc_4th_calc_every, WeylScal4_invars_calc_4th_calc_offset, WeylScal4_invars_calc_Nth_calc_every, WeylScal4_invars_calc_Nth_calc_offset, WeylScal4_psi4_calc_2nd_calc_every, WeylScal4_psi4_calc_2nd_calc_offset, WeylScal4_psi4_calc_4th_calc_every, WeylScal4_psi4_calc_4th_calc_offset, WeylScal4_psi4_calc_Nth_calc_every, WeylScal4_psi4_calc_Nth_calc_offset, WeylScal4_psis_calc_2nd_calc_every, WeylScal4_psis_calc_2nd_calc_offset, WeylScal4_psis_calc_4th_calc_every, WeylScal4_psis_calc_4th_calc_offset, WeylScal4_psis_calc_Nth_calc_every, WeylScal4_psis_calc_Nth_calc_offset, fdOrder, other_timelevels, rhs_timelevels, tile_size, timelevels, verbose&&\
CCTK_DECLARE(CCTK_STRING,calc_invariants,)&&\
CCTK_DECLARE(CCTK_STRING,calc_scalars,)&&\
CCTK_DECLARE(CCTK_STRING,fd_order,)&&\
COMMON /WeylScal4priv/calc_invariants, calc_scalars, fd_order&&\
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

