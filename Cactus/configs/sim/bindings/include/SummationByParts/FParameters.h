#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,diss_fraction,(3))&&\
CCTK_DECLARE(CCTK_REAL,epsdis,)&&\
CCTK_DECLARE(CCTK_REAL,h_scaling,(3))&&\
CCTK_DECLARE(CCTK_REAL,poison_value,)&&\
CCTK_DECLARE(CCTK_STRING,dissipation_type,)&&\
CCTK_DECLARE(CCTK_STRING,norm_type,)&&\
CCTK_DECLARE(CCTK_STRING,operator_type,)&&\
CCTK_DECLARE(CCTK_STRING,vars,)&&\
CCTK_DECLARE(CCTK_INT,check_grid_sizes,)&&\
CCTK_DECLARE(CCTK_INT,onesided_interpatch_boundaries,)&&\
CCTK_DECLARE(CCTK_INT,onesided_outer_boundaries,)&&\
CCTK_DECLARE(CCTK_INT,order,)&&\
CCTK_DECLARE(CCTK_INT,poison_derivatives,)&&\
CCTK_DECLARE(CCTK_INT,poison_dissipation,)&&\
CCTK_DECLARE(CCTK_INT,sbp_1st_deriv,)&&\
CCTK_DECLARE(CCTK_INT,sbp_2nd_deriv,)&&\
CCTK_DECLARE(CCTK_INT,sbp_upwind_deriv,)&&\
CCTK_DECLARE(CCTK_INT,scale_with_h,)&&\
CCTK_DECLARE(CCTK_INT,use_dissipation,)&&\
CCTK_DECLARE(CCTK_INT,use_shiftout,)&&\
CCTK_DECLARE(CCTK_INT,use_variable_deltas,)&&\
CCTK_DECLARE(CCTK_INT,zero_derivs_y,)&&\
CCTK_DECLARE(CCTK_INT,zero_derivs_z,)&&\
COMMON /SummationByPartsrest/diss_fraction, epsdis, h_scaling, poison_value, dissipation_type, norm_type, operator_type, vars, check_grid_sizes, onesided_interpatch_boundaries, onesided_outer_boundaries, order, poison_derivatives, poison_dissipation, sbp_1st_deriv, sbp_2nd_deriv, sbp_upwind_deriv, scale_with_h, use_dissipation, use_shiftout, use_variable_deltas, zero_derivs_y, zero_derivs_z&&\

