#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL amp;
  CCTK_REAL error_tolerance;
  CCTK_REAL eta0;
  CCTK_REAL etamax;
  CCTK_REAL sigma;
  const char * interpolator_name;
  const char * interpolator_pars;
  const char * output_psi2D_file_name;
  CCTK_INT debug;
  CCTK_INT debug_i;
  CCTK_INT debug_ii;
  CCTK_INT debug_j;
  CCTK_INT debug_jj;
  CCTK_INT debug_k;
  CCTK_INT generate_StaticConformal_metric;
  CCTK_INT interpolation_order;
  CCTK_INT n;
  CCTK_INT ne;
  CCTK_INT nq;
  CCTK_INT output_psi2D;
} PRIVATE_IDAXIBRILLBH_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_IDAXIBRILLBH_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, amp, CCTK_PARAMETER__IDAXIBRILLBH__amp); \
  CCTK_DECLARE_INIT (CCTK_REAL const, error_tolerance, CCTK_PARAMETER__IDAXIBRILLBH__error_tolerance); \
  CCTK_DECLARE_INIT (CCTK_REAL const, eta0, CCTK_PARAMETER__IDAXIBRILLBH__eta0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, etamax, CCTK_PARAMETER__IDAXIBRILLBH__etamax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, sigma, CCTK_PARAMETER__IDAXIBRILLBH__sigma); \
  CCTK_DECLARE_INIT (const char * const, interpolator_name, CCTK_PARAMETER__IDAXIBRILLBH__interpolator_name); \
  CCTK_DECLARE_INIT (const char * const, interpolator_pars, CCTK_PARAMETER__IDAXIBRILLBH__interpolator_pars); \
  CCTK_DECLARE_INIT (const char * const, output_psi2D_file_name, CCTK_PARAMETER__IDAXIBRILLBH__output_psi2D_file_name); \
  CCTK_DECLARE_INIT (CCTK_INT const, debug, CCTK_PARAMETER__IDAXIBRILLBH__debug); \
  CCTK_DECLARE_INIT (CCTK_INT const, debug_i, CCTK_PARAMETER__IDAXIBRILLBH__debug_i); \
  CCTK_DECLARE_INIT (CCTK_INT const, debug_ii, CCTK_PARAMETER__IDAXIBRILLBH__debug_ii); \
  CCTK_DECLARE_INIT (CCTK_INT const, debug_j, CCTK_PARAMETER__IDAXIBRILLBH__debug_j); \
  CCTK_DECLARE_INIT (CCTK_INT const, debug_jj, CCTK_PARAMETER__IDAXIBRILLBH__debug_jj); \
  CCTK_DECLARE_INIT (CCTK_INT const, debug_k, CCTK_PARAMETER__IDAXIBRILLBH__debug_k); \
  CCTK_DECLARE_INIT (CCTK_INT const, generate_StaticConformal_metric, CCTK_PARAMETER__IDAXIBRILLBH__generate_StaticConformal_metric); \
  CCTK_DECLARE_INIT (CCTK_INT const, interpolation_order, CCTK_PARAMETER__IDAXIBRILLBH__interpolation_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, n, CCTK_PARAMETER__IDAXIBRILLBH__n); \
  CCTK_DECLARE_INIT (CCTK_INT const, ne, CCTK_PARAMETER__IDAXIBRILLBH__ne); \
  CCTK_DECLARE_INIT (CCTK_INT const, nq, CCTK_PARAMETER__IDAXIBRILLBH__nq); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_psi2D, CCTK_PARAMETER__IDAXIBRILLBH__output_psi2D); \


#ifndef CCTK_PARAMETER__IDAXIBRILLBH__amp
#  define CCTK_PARAMETER__IDAXIBRILLBH__amp PRIVATE_IDAXIBRILLBH_STRUCT.amp
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__error_tolerance
#  define CCTK_PARAMETER__IDAXIBRILLBH__error_tolerance PRIVATE_IDAXIBRILLBH_STRUCT.error_tolerance
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__eta0
#  define CCTK_PARAMETER__IDAXIBRILLBH__eta0 PRIVATE_IDAXIBRILLBH_STRUCT.eta0
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__etamax
#  define CCTK_PARAMETER__IDAXIBRILLBH__etamax PRIVATE_IDAXIBRILLBH_STRUCT.etamax
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__sigma
#  define CCTK_PARAMETER__IDAXIBRILLBH__sigma PRIVATE_IDAXIBRILLBH_STRUCT.sigma
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__interpolator_name
#  define CCTK_PARAMETER__IDAXIBRILLBH__interpolator_name PRIVATE_IDAXIBRILLBH_STRUCT.interpolator_name
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__interpolator_pars
#  define CCTK_PARAMETER__IDAXIBRILLBH__interpolator_pars PRIVATE_IDAXIBRILLBH_STRUCT.interpolator_pars
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__output_psi2D_file_name
#  define CCTK_PARAMETER__IDAXIBRILLBH__output_psi2D_file_name PRIVATE_IDAXIBRILLBH_STRUCT.output_psi2D_file_name
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__debug
#  define CCTK_PARAMETER__IDAXIBRILLBH__debug PRIVATE_IDAXIBRILLBH_STRUCT.debug
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__debug_i
#  define CCTK_PARAMETER__IDAXIBRILLBH__debug_i PRIVATE_IDAXIBRILLBH_STRUCT.debug_i
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__debug_ii
#  define CCTK_PARAMETER__IDAXIBRILLBH__debug_ii PRIVATE_IDAXIBRILLBH_STRUCT.debug_ii
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__debug_j
#  define CCTK_PARAMETER__IDAXIBRILLBH__debug_j PRIVATE_IDAXIBRILLBH_STRUCT.debug_j
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__debug_jj
#  define CCTK_PARAMETER__IDAXIBRILLBH__debug_jj PRIVATE_IDAXIBRILLBH_STRUCT.debug_jj
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__debug_k
#  define CCTK_PARAMETER__IDAXIBRILLBH__debug_k PRIVATE_IDAXIBRILLBH_STRUCT.debug_k
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__generate_StaticConformal_metric
#  define CCTK_PARAMETER__IDAXIBRILLBH__generate_StaticConformal_metric PRIVATE_IDAXIBRILLBH_STRUCT.generate_StaticConformal_metric
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__interpolation_order
#  define CCTK_PARAMETER__IDAXIBRILLBH__interpolation_order PRIVATE_IDAXIBRILLBH_STRUCT.interpolation_order
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__n
#  define CCTK_PARAMETER__IDAXIBRILLBH__n PRIVATE_IDAXIBRILLBH_STRUCT.n
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__ne
#  define CCTK_PARAMETER__IDAXIBRILLBH__ne PRIVATE_IDAXIBRILLBH_STRUCT.ne
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__nq
#  define CCTK_PARAMETER__IDAXIBRILLBH__nq PRIVATE_IDAXIBRILLBH_STRUCT.nq
#endif
#ifndef CCTK_PARAMETER__IDAXIBRILLBH__output_psi2D
#  define CCTK_PARAMETER__IDAXIBRILLBH__output_psi2D PRIVATE_IDAXIBRILLBH_STRUCT.output_psi2D
#endif

