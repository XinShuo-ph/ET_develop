#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * extcurv_boundary;
  const char * extcurv_boundary_options;
  CCTK_INT calc_extcurv;
  CCTK_INT copy_to_next;
  CCTK_INT copy_to_prev;
  CCTK_INT copy_to_prev2;
} PRIVATE_CALCK_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CALCK_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, extcurv_boundary, CCTK_PARAMETER__CALCK__extcurv_boundary); \
  CCTK_DECLARE_INIT (const char * const, extcurv_boundary_options, CCTK_PARAMETER__CALCK__extcurv_boundary_options); \
  CCTK_DECLARE_INIT (CCTK_INT const, calc_extcurv, CCTK_PARAMETER__CALCK__calc_extcurv); \
  CCTK_DECLARE_INIT (CCTK_INT const, copy_to_next, CCTK_PARAMETER__CALCK__copy_to_next); \
  CCTK_DECLARE_INIT (CCTK_INT const, copy_to_prev, CCTK_PARAMETER__CALCK__copy_to_prev); \
  CCTK_DECLARE_INIT (CCTK_INT const, copy_to_prev2, CCTK_PARAMETER__CALCK__copy_to_prev2); \


#ifndef CCTK_PARAMETER__CALCK__extcurv_boundary
#  define CCTK_PARAMETER__CALCK__extcurv_boundary PRIVATE_CALCK_STRUCT.extcurv_boundary
#endif
#ifndef CCTK_PARAMETER__CALCK__extcurv_boundary_options
#  define CCTK_PARAMETER__CALCK__extcurv_boundary_options PRIVATE_CALCK_STRUCT.extcurv_boundary_options
#endif
#ifndef CCTK_PARAMETER__CALCK__calc_extcurv
#  define CCTK_PARAMETER__CALCK__calc_extcurv PRIVATE_CALCK_STRUCT.calc_extcurv
#endif
#ifndef CCTK_PARAMETER__CALCK__copy_to_next
#  define CCTK_PARAMETER__CALCK__copy_to_next PRIVATE_CALCK_STRUCT.copy_to_next
#endif
#ifndef CCTK_PARAMETER__CALCK__copy_to_prev
#  define CCTK_PARAMETER__CALCK__copy_to_prev PRIVATE_CALCK_STRUCT.copy_to_prev
#endif
#ifndef CCTK_PARAMETER__CALCK__copy_to_prev2
#  define CCTK_PARAMETER__CALCK__copy_to_prev2 PRIVATE_CALCK_STRUCT.copy_to_prev2
#endif

