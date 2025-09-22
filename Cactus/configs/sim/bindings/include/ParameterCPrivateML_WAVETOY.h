#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL WT_rho_bound_limit;
  CCTK_REAL WT_rho_bound_scalar;
  CCTK_REAL WT_rho_bound_speed;
  CCTK_REAL WT_u_bound_limit;
  CCTK_REAL WT_u_bound_scalar;
  CCTK_REAL WT_u_bound_speed;
  CCTK_REAL rho_bound_limit;
  CCTK_REAL rho_bound_scalar;
  CCTK_REAL rho_bound_speed;
  CCTK_REAL u_bound_limit;
  CCTK_REAL u_bound_scalar;
  CCTK_REAL u_bound_speed;
  const char * WT_rho_bound;
  const char * WT_u_bound;
  const char * initial_data;
  const char * rho_bound;
  const char * u_bound;
} PRIVATE_ML_WAVETOY_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_ML_WAVETOY_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, WT_rho_bound_limit, CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound_limit); \
  CCTK_DECLARE_INIT (CCTK_REAL const, WT_rho_bound_scalar, CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound_scalar); \
  CCTK_DECLARE_INIT (CCTK_REAL const, WT_rho_bound_speed, CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound_speed); \
  CCTK_DECLARE_INIT (CCTK_REAL const, WT_u_bound_limit, CCTK_PARAMETER__ML_WAVETOY__WT_u_bound_limit); \
  CCTK_DECLARE_INIT (CCTK_REAL const, WT_u_bound_scalar, CCTK_PARAMETER__ML_WAVETOY__WT_u_bound_scalar); \
  CCTK_DECLARE_INIT (CCTK_REAL const, WT_u_bound_speed, CCTK_PARAMETER__ML_WAVETOY__WT_u_bound_speed); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rho_bound_limit, CCTK_PARAMETER__ML_WAVETOY__rho_bound_limit); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rho_bound_scalar, CCTK_PARAMETER__ML_WAVETOY__rho_bound_scalar); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rho_bound_speed, CCTK_PARAMETER__ML_WAVETOY__rho_bound_speed); \
  CCTK_DECLARE_INIT (CCTK_REAL const, u_bound_limit, CCTK_PARAMETER__ML_WAVETOY__u_bound_limit); \
  CCTK_DECLARE_INIT (CCTK_REAL const, u_bound_scalar, CCTK_PARAMETER__ML_WAVETOY__u_bound_scalar); \
  CCTK_DECLARE_INIT (CCTK_REAL const, u_bound_speed, CCTK_PARAMETER__ML_WAVETOY__u_bound_speed); \
  CCTK_DECLARE_INIT (const char * const, WT_rho_bound, CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound); \
  CCTK_DECLARE_INIT (const char * const, WT_u_bound, CCTK_PARAMETER__ML_WAVETOY__WT_u_bound); \
  CCTK_DECLARE_INIT (const char * const, initial_data, CCTK_PARAMETER__ML_WAVETOY__initial_data); \
  CCTK_DECLARE_INIT (const char * const, rho_bound, CCTK_PARAMETER__ML_WAVETOY__rho_bound); \
  CCTK_DECLARE_INIT (const char * const, u_bound, CCTK_PARAMETER__ML_WAVETOY__u_bound); \


#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound_limit
#  define CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound_limit PRIVATE_ML_WAVETOY_STRUCT.WT_rho_bound_limit
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound_scalar
#  define CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound_scalar PRIVATE_ML_WAVETOY_STRUCT.WT_rho_bound_scalar
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound_speed
#  define CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound_speed PRIVATE_ML_WAVETOY_STRUCT.WT_rho_bound_speed
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_u_bound_limit
#  define CCTK_PARAMETER__ML_WAVETOY__WT_u_bound_limit PRIVATE_ML_WAVETOY_STRUCT.WT_u_bound_limit
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_u_bound_scalar
#  define CCTK_PARAMETER__ML_WAVETOY__WT_u_bound_scalar PRIVATE_ML_WAVETOY_STRUCT.WT_u_bound_scalar
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_u_bound_speed
#  define CCTK_PARAMETER__ML_WAVETOY__WT_u_bound_speed PRIVATE_ML_WAVETOY_STRUCT.WT_u_bound_speed
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__rho_bound_limit
#  define CCTK_PARAMETER__ML_WAVETOY__rho_bound_limit PRIVATE_ML_WAVETOY_STRUCT.rho_bound_limit
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__rho_bound_scalar
#  define CCTK_PARAMETER__ML_WAVETOY__rho_bound_scalar PRIVATE_ML_WAVETOY_STRUCT.rho_bound_scalar
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__rho_bound_speed
#  define CCTK_PARAMETER__ML_WAVETOY__rho_bound_speed PRIVATE_ML_WAVETOY_STRUCT.rho_bound_speed
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__u_bound_limit
#  define CCTK_PARAMETER__ML_WAVETOY__u_bound_limit PRIVATE_ML_WAVETOY_STRUCT.u_bound_limit
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__u_bound_scalar
#  define CCTK_PARAMETER__ML_WAVETOY__u_bound_scalar PRIVATE_ML_WAVETOY_STRUCT.u_bound_scalar
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__u_bound_speed
#  define CCTK_PARAMETER__ML_WAVETOY__u_bound_speed PRIVATE_ML_WAVETOY_STRUCT.u_bound_speed
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound
#  define CCTK_PARAMETER__ML_WAVETOY__WT_rho_bound PRIVATE_ML_WAVETOY_STRUCT.WT_rho_bound
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_u_bound
#  define CCTK_PARAMETER__ML_WAVETOY__WT_u_bound PRIVATE_ML_WAVETOY_STRUCT.WT_u_bound
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__initial_data
#  define CCTK_PARAMETER__ML_WAVETOY__initial_data PRIVATE_ML_WAVETOY_STRUCT.initial_data
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__rho_bound
#  define CCTK_PARAMETER__ML_WAVETOY__rho_bound PRIVATE_ML_WAVETOY_STRUCT.rho_bound
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__u_bound
#  define CCTK_PARAMETER__ML_WAVETOY__u_bound PRIVATE_ML_WAVETOY_STRUCT.u_bound
#endif

