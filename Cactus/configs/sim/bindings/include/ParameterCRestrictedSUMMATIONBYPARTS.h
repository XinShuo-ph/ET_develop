#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL diss_fraction[3];
  CCTK_REAL epsdis;
  CCTK_REAL h_scaling[3];
  CCTK_REAL poison_value;
  const char * dissipation_type;
  const char * norm_type;
  const char * operator_type;
  const char * vars;
  CCTK_INT check_grid_sizes;
  CCTK_INT onesided_interpatch_boundaries;
  CCTK_INT onesided_outer_boundaries;
  CCTK_INT order;
  CCTK_INT poison_derivatives;
  CCTK_INT poison_dissipation;
  CCTK_INT sbp_1st_deriv;
  CCTK_INT sbp_2nd_deriv;
  CCTK_INT sbp_upwind_deriv;
  CCTK_INT scale_with_h;
  CCTK_INT use_dissipation;
  CCTK_INT use_shiftout;
  CCTK_INT use_variable_deltas;
  CCTK_INT zero_derivs_y;
  CCTK_INT zero_derivs_z;
} RESTRICTED_SUMMATIONBYPARTS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_SUMMATIONBYPARTS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, diss_fraction, CCTK_PARAMETER__SUMMATIONBYPARTS__diss_fraction); \
  CCTK_DECLARE_INIT (CCTK_REAL const, epsdis, CCTK_PARAMETER__SUMMATIONBYPARTS__epsdis); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, h_scaling, CCTK_PARAMETER__SUMMATIONBYPARTS__h_scaling); \
  CCTK_DECLARE_INIT (CCTK_REAL const, poison_value, CCTK_PARAMETER__SUMMATIONBYPARTS__poison_value); \
  CCTK_DECLARE_INIT (const char * const, dissipation_type, CCTK_PARAMETER__SUMMATIONBYPARTS__dissipation_type); \
  CCTK_DECLARE_INIT (const char * const, norm_type, CCTK_PARAMETER__SUMMATIONBYPARTS__norm_type); \
  CCTK_DECLARE_INIT (const char * const, operator_type, CCTK_PARAMETER__SUMMATIONBYPARTS__operator_type); \
  CCTK_DECLARE_INIT (const char * const, vars, CCTK_PARAMETER__SUMMATIONBYPARTS__vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_grid_sizes, CCTK_PARAMETER__SUMMATIONBYPARTS__check_grid_sizes); \
  CCTK_DECLARE_INIT (CCTK_INT const, onesided_interpatch_boundaries, CCTK_PARAMETER__SUMMATIONBYPARTS__onesided_interpatch_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, onesided_outer_boundaries, CCTK_PARAMETER__SUMMATIONBYPARTS__onesided_outer_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, order, CCTK_PARAMETER__SUMMATIONBYPARTS__order); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_derivatives, CCTK_PARAMETER__SUMMATIONBYPARTS__poison_derivatives); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_dissipation, CCTK_PARAMETER__SUMMATIONBYPARTS__poison_dissipation); \
  CCTK_DECLARE_INIT (CCTK_INT const, sbp_1st_deriv, CCTK_PARAMETER__SUMMATIONBYPARTS__sbp_1st_deriv); \
  CCTK_DECLARE_INIT (CCTK_INT const, sbp_2nd_deriv, CCTK_PARAMETER__SUMMATIONBYPARTS__sbp_2nd_deriv); \
  CCTK_DECLARE_INIT (CCTK_INT const, sbp_upwind_deriv, CCTK_PARAMETER__SUMMATIONBYPARTS__sbp_upwind_deriv); \
  CCTK_DECLARE_INIT (CCTK_INT const, scale_with_h, CCTK_PARAMETER__SUMMATIONBYPARTS__scale_with_h); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_dissipation, CCTK_PARAMETER__SUMMATIONBYPARTS__use_dissipation); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_shiftout, CCTK_PARAMETER__SUMMATIONBYPARTS__use_shiftout); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_variable_deltas, CCTK_PARAMETER__SUMMATIONBYPARTS__use_variable_deltas); \
  CCTK_DECLARE_INIT (CCTK_INT const, zero_derivs_y, CCTK_PARAMETER__SUMMATIONBYPARTS__zero_derivs_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, zero_derivs_z, CCTK_PARAMETER__SUMMATIONBYPARTS__zero_derivs_z); \


#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__diss_fraction
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__diss_fraction RESTRICTED_SUMMATIONBYPARTS_STRUCT.diss_fraction
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__epsdis
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__epsdis RESTRICTED_SUMMATIONBYPARTS_STRUCT.epsdis
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__h_scaling
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__h_scaling RESTRICTED_SUMMATIONBYPARTS_STRUCT.h_scaling
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__poison_value
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__poison_value RESTRICTED_SUMMATIONBYPARTS_STRUCT.poison_value
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__dissipation_type
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__dissipation_type RESTRICTED_SUMMATIONBYPARTS_STRUCT.dissipation_type
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__norm_type
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__norm_type RESTRICTED_SUMMATIONBYPARTS_STRUCT.norm_type
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__operator_type
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__operator_type RESTRICTED_SUMMATIONBYPARTS_STRUCT.operator_type
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__vars
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__vars RESTRICTED_SUMMATIONBYPARTS_STRUCT.vars
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__check_grid_sizes
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__check_grid_sizes RESTRICTED_SUMMATIONBYPARTS_STRUCT.check_grid_sizes
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__onesided_interpatch_boundaries
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__onesided_interpatch_boundaries RESTRICTED_SUMMATIONBYPARTS_STRUCT.onesided_interpatch_boundaries
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__onesided_outer_boundaries
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__onesided_outer_boundaries RESTRICTED_SUMMATIONBYPARTS_STRUCT.onesided_outer_boundaries
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__order
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__order RESTRICTED_SUMMATIONBYPARTS_STRUCT.order
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__poison_derivatives
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__poison_derivatives RESTRICTED_SUMMATIONBYPARTS_STRUCT.poison_derivatives
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__poison_dissipation
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__poison_dissipation RESTRICTED_SUMMATIONBYPARTS_STRUCT.poison_dissipation
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__sbp_1st_deriv
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__sbp_1st_deriv RESTRICTED_SUMMATIONBYPARTS_STRUCT.sbp_1st_deriv
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__sbp_2nd_deriv
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__sbp_2nd_deriv RESTRICTED_SUMMATIONBYPARTS_STRUCT.sbp_2nd_deriv
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__sbp_upwind_deriv
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__sbp_upwind_deriv RESTRICTED_SUMMATIONBYPARTS_STRUCT.sbp_upwind_deriv
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__scale_with_h
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__scale_with_h RESTRICTED_SUMMATIONBYPARTS_STRUCT.scale_with_h
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__use_dissipation
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__use_dissipation RESTRICTED_SUMMATIONBYPARTS_STRUCT.use_dissipation
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__use_shiftout
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__use_shiftout RESTRICTED_SUMMATIONBYPARTS_STRUCT.use_shiftout
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__use_variable_deltas
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__use_variable_deltas RESTRICTED_SUMMATIONBYPARTS_STRUCT.use_variable_deltas
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__zero_derivs_y
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__zero_derivs_y RESTRICTED_SUMMATIONBYPARTS_STRUCT.zero_derivs_y
#endif
#ifndef CCTK_PARAMETER__SUMMATIONBYPARTS__zero_derivs_z
#  define CCTK_PARAMETER__SUMMATIONBYPARTS__zero_derivs_z RESTRICTED_SUMMATIONBYPARTS_STRUCT.zero_derivs_z
#endif

