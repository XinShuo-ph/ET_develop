#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL brill3d_d;
  CCTK_REAL brill3d_e;
  CCTK_REAL brill3d_m;
  CCTK_REAL brill3d_n;
  CCTK_REAL brill3d_phi0;
  CCTK_REAL const_v0;
  CCTK_REAL eppley_a;
  CCTK_REAL eppley_r0;
  CCTK_REAL eppley_sigmar;
  CCTK_REAL eppley_sigmarho;
  CCTK_REAL exp_a;
  CCTK_REAL exp_rho0;
  CCTK_REAL exp_sigmaz;
  CCTK_REAL gundlach_a;
  CCTK_REAL gundlach_r0;
  CCTK_REAL gundlach_sigmar;
  CCTK_REAL gundlach_sigmarho;
  CCTK_REAL rhofudge;
  CCTK_REAL robin_inf;
  CCTK_REAL thresh;
  const char * bound;
  const char * q_function;
  const char * solver;
  CCTK_INT eppley_b;
  CCTK_INT eppley_c;
  CCTK_INT exp_b;
  CCTK_INT gundlach_b;
  CCTK_INT gundlach_c;
  CCTK_INT output_coeffs;
  CCTK_INT robin_falloff;
  CCTK_INT sor_maxit;
} PRIVATE_IDBRILLDATA_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_IDBRILLDATA_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, brill3d_d, CCTK_PARAMETER__IDBRILLDATA__brill3d_d); \
  CCTK_DECLARE_INIT (CCTK_REAL const, brill3d_e, CCTK_PARAMETER__IDBRILLDATA__brill3d_e); \
  CCTK_DECLARE_INIT (CCTK_REAL const, brill3d_m, CCTK_PARAMETER__IDBRILLDATA__brill3d_m); \
  CCTK_DECLARE_INIT (CCTK_REAL const, brill3d_n, CCTK_PARAMETER__IDBRILLDATA__brill3d_n); \
  CCTK_DECLARE_INIT (CCTK_REAL const, brill3d_phi0, CCTK_PARAMETER__IDBRILLDATA__brill3d_phi0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, const_v0, CCTK_PARAMETER__IDBRILLDATA__const_v0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, eppley_a, CCTK_PARAMETER__IDBRILLDATA__eppley_a); \
  CCTK_DECLARE_INIT (CCTK_REAL const, eppley_r0, CCTK_PARAMETER__IDBRILLDATA__eppley_r0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, eppley_sigmar, CCTK_PARAMETER__IDBRILLDATA__eppley_sigmar); \
  CCTK_DECLARE_INIT (CCTK_REAL const, eppley_sigmarho, CCTK_PARAMETER__IDBRILLDATA__eppley_sigmarho); \
  CCTK_DECLARE_INIT (CCTK_REAL const, exp_a, CCTK_PARAMETER__IDBRILLDATA__exp_a); \
  CCTK_DECLARE_INIT (CCTK_REAL const, exp_rho0, CCTK_PARAMETER__IDBRILLDATA__exp_rho0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, exp_sigmaz, CCTK_PARAMETER__IDBRILLDATA__exp_sigmaz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gundlach_a, CCTK_PARAMETER__IDBRILLDATA__gundlach_a); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gundlach_r0, CCTK_PARAMETER__IDBRILLDATA__gundlach_r0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gundlach_sigmar, CCTK_PARAMETER__IDBRILLDATA__gundlach_sigmar); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gundlach_sigmarho, CCTK_PARAMETER__IDBRILLDATA__gundlach_sigmarho); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rhofudge, CCTK_PARAMETER__IDBRILLDATA__rhofudge); \
  CCTK_DECLARE_INIT (CCTK_REAL const, robin_inf, CCTK_PARAMETER__IDBRILLDATA__robin_inf); \
  CCTK_DECLARE_INIT (CCTK_REAL const, thresh, CCTK_PARAMETER__IDBRILLDATA__thresh); \
  CCTK_DECLARE_INIT (const char * const, bound, CCTK_PARAMETER__IDBRILLDATA__bound); \
  CCTK_DECLARE_INIT (const char * const, q_function, CCTK_PARAMETER__IDBRILLDATA__q_function); \
  CCTK_DECLARE_INIT (const char * const, solver, CCTK_PARAMETER__IDBRILLDATA__solver); \
  CCTK_DECLARE_INIT (CCTK_INT const, eppley_b, CCTK_PARAMETER__IDBRILLDATA__eppley_b); \
  CCTK_DECLARE_INIT (CCTK_INT const, eppley_c, CCTK_PARAMETER__IDBRILLDATA__eppley_c); \
  CCTK_DECLARE_INIT (CCTK_INT const, exp_b, CCTK_PARAMETER__IDBRILLDATA__exp_b); \
  CCTK_DECLARE_INIT (CCTK_INT const, gundlach_b, CCTK_PARAMETER__IDBRILLDATA__gundlach_b); \
  CCTK_DECLARE_INIT (CCTK_INT const, gundlach_c, CCTK_PARAMETER__IDBRILLDATA__gundlach_c); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_coeffs, CCTK_PARAMETER__IDBRILLDATA__output_coeffs); \
  CCTK_DECLARE_INIT (CCTK_INT const, robin_falloff, CCTK_PARAMETER__IDBRILLDATA__robin_falloff); \
  CCTK_DECLARE_INIT (CCTK_INT const, sor_maxit, CCTK_PARAMETER__IDBRILLDATA__sor_maxit); \


#ifndef CCTK_PARAMETER__IDBRILLDATA__brill3d_d
#  define CCTK_PARAMETER__IDBRILLDATA__brill3d_d PRIVATE_IDBRILLDATA_STRUCT.brill3d_d
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__brill3d_e
#  define CCTK_PARAMETER__IDBRILLDATA__brill3d_e PRIVATE_IDBRILLDATA_STRUCT.brill3d_e
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__brill3d_m
#  define CCTK_PARAMETER__IDBRILLDATA__brill3d_m PRIVATE_IDBRILLDATA_STRUCT.brill3d_m
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__brill3d_n
#  define CCTK_PARAMETER__IDBRILLDATA__brill3d_n PRIVATE_IDBRILLDATA_STRUCT.brill3d_n
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__brill3d_phi0
#  define CCTK_PARAMETER__IDBRILLDATA__brill3d_phi0 PRIVATE_IDBRILLDATA_STRUCT.brill3d_phi0
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__const_v0
#  define CCTK_PARAMETER__IDBRILLDATA__const_v0 PRIVATE_IDBRILLDATA_STRUCT.const_v0
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__eppley_a
#  define CCTK_PARAMETER__IDBRILLDATA__eppley_a PRIVATE_IDBRILLDATA_STRUCT.eppley_a
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__eppley_r0
#  define CCTK_PARAMETER__IDBRILLDATA__eppley_r0 PRIVATE_IDBRILLDATA_STRUCT.eppley_r0
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__eppley_sigmar
#  define CCTK_PARAMETER__IDBRILLDATA__eppley_sigmar PRIVATE_IDBRILLDATA_STRUCT.eppley_sigmar
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__eppley_sigmarho
#  define CCTK_PARAMETER__IDBRILLDATA__eppley_sigmarho PRIVATE_IDBRILLDATA_STRUCT.eppley_sigmarho
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__exp_a
#  define CCTK_PARAMETER__IDBRILLDATA__exp_a PRIVATE_IDBRILLDATA_STRUCT.exp_a
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__exp_rho0
#  define CCTK_PARAMETER__IDBRILLDATA__exp_rho0 PRIVATE_IDBRILLDATA_STRUCT.exp_rho0
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__exp_sigmaz
#  define CCTK_PARAMETER__IDBRILLDATA__exp_sigmaz PRIVATE_IDBRILLDATA_STRUCT.exp_sigmaz
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__gundlach_a
#  define CCTK_PARAMETER__IDBRILLDATA__gundlach_a PRIVATE_IDBRILLDATA_STRUCT.gundlach_a
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__gundlach_r0
#  define CCTK_PARAMETER__IDBRILLDATA__gundlach_r0 PRIVATE_IDBRILLDATA_STRUCT.gundlach_r0
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__gundlach_sigmar
#  define CCTK_PARAMETER__IDBRILLDATA__gundlach_sigmar PRIVATE_IDBRILLDATA_STRUCT.gundlach_sigmar
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__gundlach_sigmarho
#  define CCTK_PARAMETER__IDBRILLDATA__gundlach_sigmarho PRIVATE_IDBRILLDATA_STRUCT.gundlach_sigmarho
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__rhofudge
#  define CCTK_PARAMETER__IDBRILLDATA__rhofudge PRIVATE_IDBRILLDATA_STRUCT.rhofudge
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__robin_inf
#  define CCTK_PARAMETER__IDBRILLDATA__robin_inf PRIVATE_IDBRILLDATA_STRUCT.robin_inf
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__thresh
#  define CCTK_PARAMETER__IDBRILLDATA__thresh PRIVATE_IDBRILLDATA_STRUCT.thresh
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__bound
#  define CCTK_PARAMETER__IDBRILLDATA__bound PRIVATE_IDBRILLDATA_STRUCT.bound
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__q_function
#  define CCTK_PARAMETER__IDBRILLDATA__q_function PRIVATE_IDBRILLDATA_STRUCT.q_function
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__solver
#  define CCTK_PARAMETER__IDBRILLDATA__solver PRIVATE_IDBRILLDATA_STRUCT.solver
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__eppley_b
#  define CCTK_PARAMETER__IDBRILLDATA__eppley_b PRIVATE_IDBRILLDATA_STRUCT.eppley_b
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__eppley_c
#  define CCTK_PARAMETER__IDBRILLDATA__eppley_c PRIVATE_IDBRILLDATA_STRUCT.eppley_c
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__exp_b
#  define CCTK_PARAMETER__IDBRILLDATA__exp_b PRIVATE_IDBRILLDATA_STRUCT.exp_b
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__gundlach_b
#  define CCTK_PARAMETER__IDBRILLDATA__gundlach_b PRIVATE_IDBRILLDATA_STRUCT.gundlach_b
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__gundlach_c
#  define CCTK_PARAMETER__IDBRILLDATA__gundlach_c PRIVATE_IDBRILLDATA_STRUCT.gundlach_c
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__output_coeffs
#  define CCTK_PARAMETER__IDBRILLDATA__output_coeffs PRIVATE_IDBRILLDATA_STRUCT.output_coeffs
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__robin_falloff
#  define CCTK_PARAMETER__IDBRILLDATA__robin_falloff PRIVATE_IDBRILLDATA_STRUCT.robin_falloff
#endif
#ifndef CCTK_PARAMETER__IDBRILLDATA__sor_maxit
#  define CCTK_PARAMETER__IDBRILLDATA__sor_maxit PRIVATE_IDBRILLDATA_STRUCT.sor_maxit
#endif

