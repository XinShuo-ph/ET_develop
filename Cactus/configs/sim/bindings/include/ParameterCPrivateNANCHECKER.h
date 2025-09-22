#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * action_if_found;
  const char * check_for;
  const char * check_vars;
  const char * restriction_mask;
  const char * verbose;
  CCTK_INT check_after;
  CCTK_INT check_every;
  CCTK_INT ignore_restricted_points;
  CCTK_INT out_NaNmask;
  CCTK_INT report_max;
} PRIVATE_NANCHECKER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NANCHECKER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, action_if_found, CCTK_PARAMETER__NANCHECKER__action_if_found); \
  CCTK_DECLARE_INIT (const char * const, check_for, CCTK_PARAMETER__NANCHECKER__check_for); \
  CCTK_DECLARE_INIT (const char * const, check_vars, CCTK_PARAMETER__NANCHECKER__check_vars); \
  CCTK_DECLARE_INIT (const char * const, restriction_mask, CCTK_PARAMETER__NANCHECKER__restriction_mask); \
  CCTK_DECLARE_INIT (const char * const, verbose, CCTK_PARAMETER__NANCHECKER__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_after, CCTK_PARAMETER__NANCHECKER__check_after); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_every, CCTK_PARAMETER__NANCHECKER__check_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, ignore_restricted_points, CCTK_PARAMETER__NANCHECKER__ignore_restricted_points); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_NaNmask, CCTK_PARAMETER__NANCHECKER__out_NaNmask); \
  CCTK_DECLARE_INIT (CCTK_INT const, report_max, CCTK_PARAMETER__NANCHECKER__report_max); \


#ifndef CCTK_PARAMETER__NANCHECKER__action_if_found
#  define CCTK_PARAMETER__NANCHECKER__action_if_found PRIVATE_NANCHECKER_STRUCT.action_if_found
#endif
#ifndef CCTK_PARAMETER__NANCHECKER__check_for
#  define CCTK_PARAMETER__NANCHECKER__check_for PRIVATE_NANCHECKER_STRUCT.check_for
#endif
#ifndef CCTK_PARAMETER__NANCHECKER__check_vars
#  define CCTK_PARAMETER__NANCHECKER__check_vars PRIVATE_NANCHECKER_STRUCT.check_vars
#endif
#ifndef CCTK_PARAMETER__NANCHECKER__restriction_mask
#  define CCTK_PARAMETER__NANCHECKER__restriction_mask PRIVATE_NANCHECKER_STRUCT.restriction_mask
#endif
#ifndef CCTK_PARAMETER__NANCHECKER__verbose
#  define CCTK_PARAMETER__NANCHECKER__verbose PRIVATE_NANCHECKER_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__NANCHECKER__check_after
#  define CCTK_PARAMETER__NANCHECKER__check_after PRIVATE_NANCHECKER_STRUCT.check_after
#endif
#ifndef CCTK_PARAMETER__NANCHECKER__check_every
#  define CCTK_PARAMETER__NANCHECKER__check_every PRIVATE_NANCHECKER_STRUCT.check_every
#endif
#ifndef CCTK_PARAMETER__NANCHECKER__ignore_restricted_points
#  define CCTK_PARAMETER__NANCHECKER__ignore_restricted_points PRIVATE_NANCHECKER_STRUCT.ignore_restricted_points
#endif
#ifndef CCTK_PARAMETER__NANCHECKER__out_NaNmask
#  define CCTK_PARAMETER__NANCHECKER__out_NaNmask PRIVATE_NANCHECKER_STRUCT.out_NaNmask
#endif
#ifndef CCTK_PARAMETER__NANCHECKER__report_max
#  define CCTK_PARAMETER__NANCHECKER__report_max PRIVATE_NANCHECKER_STRUCT.report_max
#endif

