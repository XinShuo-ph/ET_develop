#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,M,)&&\
CCTK_DECLARE(CCTK_REAL,boostx,)&&\
CCTK_DECLARE(CCTK_REAL,boosty,)&&\
CCTK_DECLARE(CCTK_REAL,boostz,)&&\
CCTK_DECLARE(CCTK_REAL,epsilon,)&&\
CCTK_DECLARE(CCTK_REAL,lapsefactor,)&&\
CCTK_DECLARE(CCTK_REAL,phi,)&&\
CCTK_DECLARE(CCTK_REAL,positionx,)&&\
CCTK_DECLARE(CCTK_REAL,positiony,)&&\
CCTK_DECLARE(CCTK_REAL,positionz,)&&\
CCTK_DECLARE(CCTK_REAL,psi,)&&\
CCTK_DECLARE(CCTK_REAL,shiftaddx,)&&\
CCTK_DECLARE(CCTK_REAL,shiftaddy,)&&\
CCTK_DECLARE(CCTK_REAL,shiftaddz,)&&\
CCTK_DECLARE(CCTK_REAL,theta,)&&\
CCTK_DECLARE(CCTK_REAL,timeoffset,)&&\
CCTK_DECLARE(CCTK_INT,ModifiedSchwarzschildBL_MaxNumArrayEvolvedVars,)&&\
CCTK_DECLARE(CCTK_INT,ModifiedSchwarzschildBL_MaxNumEvolvedVars,)&&\
CCTK_DECLARE(CCTK_INT,ModifiedSchwarzschildBL_always_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,ModifiedSchwarzschildBL_always_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,ModifiedSchwarzschildBL_exact_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,ModifiedSchwarzschildBL_exact_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,ModifiedSchwarzschildBL_initial_calc_every,)&&\
CCTK_DECLARE(CCTK_INT,ModifiedSchwarzschildBL_initial_calc_offset,)&&\
CCTK_DECLARE(CCTK_INT,other_timelevels,)&&\
CCTK_DECLARE(CCTK_INT,rhs_timelevels,)&&\
CCTK_DECLARE(CCTK_INT,tile_size,)&&\
CCTK_DECLARE(CCTK_INT,timelevels,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /ModifiedSchwarzschildBLrest/M, boostx, boosty, boostz, epsilon, lapsefactor, phi, positionx, positiony, positionz, psi, shiftaddx, shiftaddy, shiftaddz, theta, timeoffset, ModifiedSchwarzschildBL_MaxNumArrayEvolvedVars, ModifiedSchwarzschildBL_MaxNumEvolvedVars, ModifiedSchwarzschildBL_always_calc_every, ModifiedSchwarzschildBL_always_calc_offset, ModifiedSchwarzschildBL_exact_calc_every, ModifiedSchwarzschildBL_exact_calc_offset, ModifiedSchwarzschildBL_initial_calc_every, ModifiedSchwarzschildBL_initial_calc_offset, other_timelevels, rhs_timelevels, tile_size, timelevels, verbose&&\
CCTK_DECLARE(CCTK_STRING,exact_method,)&&\
COMMON /ModifiedSchwarzschildBLpriv/exact_method&&\
CCTK_DECLARE(CCTK_STRING,CCTKH0,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH1,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH2,)&&\
CCTK_DECLARE(CCTK_STRING,evolution_method,)&&\
CCTK_DECLARE(CCTK_STRING,initial_data,)&&\
CCTK_DECLARE(CCTK_STRING,initial_dtlapse,)&&\
CCTK_DECLARE(CCTK_STRING,initial_dtshift,)&&\
CCTK_DECLARE(CCTK_STRING,initial_lapse,)&&\
CCTK_DECLARE(CCTK_STRING,initial_shift,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH3,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH4,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH6,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH8,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH9,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH10,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH5,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH7,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH11,)&&\
COMMON /ADMBASErest/CCTKH0, CCTKH1, CCTKH2, evolution_method, initial_data, initial_dtlapse, initial_dtshift, initial_lapse, initial_shift, CCTKH3, CCTKH4, CCTKH6, CCTKH8, CCTKH9, CCTKH10, CCTKH5, CCTKH7, CCTKH11&&\
CCTK_DECLARE(CCTK_STRING,CCTKH15,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH16,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH17,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH19,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH12,)&&\
CCTK_DECLARE(CCTK_INT,assume_stress_energy_state,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH13,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH14,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH18,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH20,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH21,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH22,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH23,)&&\
COMMON /GENERICFDrest/CCTKH15, CCTKH16, CCTKH17, CCTKH19, CCTKH12, assume_stress_energy_state, CCTKH13, CCTKH14, CCTKH18, CCTKH20, CCTKH21, CCTKH22, CCTKH23&&\
CCTK_DECLARE(CCTK_INT,CCTKH24,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH25,)&&\
CCTK_DECLARE(CCTK_INT,MoL_Num_ArrayEvolved_Vars,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH26,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH27,)&&\
CCTK_DECLARE(CCTK_INT,MoL_Num_Evolved_Vars,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH28,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH29,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH30,)&&\
COMMON /METHODOFLINESrest/CCTKH24, CCTKH25, MoL_Num_ArrayEvolved_Vars, CCTKH26, CCTKH27, MoL_Num_Evolved_Vars, CCTKH28, CCTKH29, CCTKH30&&\

