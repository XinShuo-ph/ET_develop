#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * calc_invariants;
  const char * calc_scalars;
  const char * fd_order;
} PRIVATE_WEYLSCAL4_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_WEYLSCAL4_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, calc_invariants, CCTK_PARAMETER__WEYLSCAL4__calc_invariants); \
  CCTK_DECLARE_INIT (const char * const, calc_scalars, CCTK_PARAMETER__WEYLSCAL4__calc_scalars); \
  CCTK_DECLARE_INIT (const char * const, fd_order, CCTK_PARAMETER__WEYLSCAL4__fd_order); \


#ifndef CCTK_PARAMETER__WEYLSCAL4__calc_invariants
#  define CCTK_PARAMETER__WEYLSCAL4__calc_invariants PRIVATE_WEYLSCAL4_STRUCT.calc_invariants
#endif
#ifndef CCTK_PARAMETER__WEYLSCAL4__calc_scalars
#  define CCTK_PARAMETER__WEYLSCAL4__calc_scalars PRIVATE_WEYLSCAL4_STRUCT.calc_scalars
#endif
#ifndef CCTK_PARAMETER__WEYLSCAL4__fd_order
#  define CCTK_PARAMETER__WEYLSCAL4__fd_order PRIVATE_WEYLSCAL4_STRUCT.fd_order
#endif

