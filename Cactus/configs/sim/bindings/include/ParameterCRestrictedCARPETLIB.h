#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT deadbeef;
  CCTK_INT poison_value;
  CCTK_INT restriction_order_space;
  CCTK_INT support_staggered_operators;
  CCTK_INT use_higher_order_restriction;
} RESTRICTED_CARPETLIB_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_CARPETLIB_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, deadbeef, CCTK_PARAMETER__CARPETLIB__deadbeef); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_value, CCTK_PARAMETER__CARPETLIB__poison_value); \
  CCTK_DECLARE_INIT (CCTK_INT const, restriction_order_space, CCTK_PARAMETER__CARPETLIB__restriction_order_space); \
  CCTK_DECLARE_INIT (CCTK_INT const, support_staggered_operators, CCTK_PARAMETER__CARPETLIB__support_staggered_operators); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_higher_order_restriction, CCTK_PARAMETER__CARPETLIB__use_higher_order_restriction); \


#ifndef CCTK_PARAMETER__CARPETLIB__deadbeef
#  define CCTK_PARAMETER__CARPETLIB__deadbeef RESTRICTED_CARPETLIB_STRUCT.deadbeef
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__poison_value
#  define CCTK_PARAMETER__CARPETLIB__poison_value RESTRICTED_CARPETLIB_STRUCT.poison_value
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__restriction_order_space
#  define CCTK_PARAMETER__CARPETLIB__restriction_order_space RESTRICTED_CARPETLIB_STRUCT.restriction_order_space
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__support_staggered_operators
#  define CCTK_PARAMETER__CARPETLIB__support_staggered_operators RESTRICTED_CARPETLIB_STRUCT.support_staggered_operators
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__use_higher_order_restriction
#  define CCTK_PARAMETER__CARPETLIB__use_higher_order_restriction RESTRICTED_CARPETLIB_STRUCT.use_higher_order_restriction
#endif

