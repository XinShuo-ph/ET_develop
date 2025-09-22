#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL mask_testinterp_tolerance;
  CCTK_REAL poison_value;
  const char * interpolation_name;
  CCTK_INT extended_guard_zone;
  CCTK_INT interpolation_order;
  CCTK_INT skip_interpolation;
  CCTK_INT use_edge_check;
} PRIVATE_NULLINTERP_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NULLINTERP_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, mask_testinterp_tolerance, CCTK_PARAMETER__NULLINTERP__mask_testinterp_tolerance); \
  CCTK_DECLARE_INIT (CCTK_REAL const, poison_value, CCTK_PARAMETER__NULLINTERP__poison_value); \
  CCTK_DECLARE_INIT (const char * const, interpolation_name, CCTK_PARAMETER__NULLINTERP__interpolation_name); \
  CCTK_DECLARE_INIT (CCTK_INT const, extended_guard_zone, CCTK_PARAMETER__NULLINTERP__extended_guard_zone); \
  CCTK_DECLARE_INIT (CCTK_INT const, interpolation_order, CCTK_PARAMETER__NULLINTERP__interpolation_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, skip_interpolation, CCTK_PARAMETER__NULLINTERP__skip_interpolation); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_edge_check, CCTK_PARAMETER__NULLINTERP__use_edge_check); \


#ifndef CCTK_PARAMETER__NULLINTERP__mask_testinterp_tolerance
#  define CCTK_PARAMETER__NULLINTERP__mask_testinterp_tolerance PRIVATE_NULLINTERP_STRUCT.mask_testinterp_tolerance
#endif
#ifndef CCTK_PARAMETER__NULLINTERP__poison_value
#  define CCTK_PARAMETER__NULLINTERP__poison_value PRIVATE_NULLINTERP_STRUCT.poison_value
#endif
#ifndef CCTK_PARAMETER__NULLINTERP__interpolation_name
#  define CCTK_PARAMETER__NULLINTERP__interpolation_name PRIVATE_NULLINTERP_STRUCT.interpolation_name
#endif
#ifndef CCTK_PARAMETER__NULLINTERP__extended_guard_zone
#  define CCTK_PARAMETER__NULLINTERP__extended_guard_zone PRIVATE_NULLINTERP_STRUCT.extended_guard_zone
#endif
#ifndef CCTK_PARAMETER__NULLINTERP__interpolation_order
#  define CCTK_PARAMETER__NULLINTERP__interpolation_order PRIVATE_NULLINTERP_STRUCT.interpolation_order
#endif
#ifndef CCTK_PARAMETER__NULLINTERP__skip_interpolation
#  define CCTK_PARAMETER__NULLINTERP__skip_interpolation PRIVATE_NULLINTERP_STRUCT.skip_interpolation
#endif
#ifndef CCTK_PARAMETER__NULLINTERP__use_edge_check
#  define CCTK_PARAMETER__NULLINTERP__use_edge_check PRIVATE_NULLINTERP_STRUCT.use_edge_check
#endif

