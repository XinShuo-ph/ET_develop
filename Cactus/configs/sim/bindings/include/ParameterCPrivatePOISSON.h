#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL charge;
  CCTK_REAL radius;
  const char * options;
  const char * solver;
} PRIVATE_POISSON_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_POISSON_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, charge, CCTK_PARAMETER__POISSON__charge); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius, CCTK_PARAMETER__POISSON__radius); \
  CCTK_DECLARE_INIT (const char * const, options, CCTK_PARAMETER__POISSON__options); \
  CCTK_DECLARE_INIT (const char * const, solver, CCTK_PARAMETER__POISSON__solver); \


#ifndef CCTK_PARAMETER__POISSON__charge
#  define CCTK_PARAMETER__POISSON__charge PRIVATE_POISSON_STRUCT.charge
#endif
#ifndef CCTK_PARAMETER__POISSON__radius
#  define CCTK_PARAMETER__POISSON__radius PRIVATE_POISSON_STRUCT.radius
#endif
#ifndef CCTK_PARAMETER__POISSON__options
#  define CCTK_PARAMETER__POISSON__options PRIVATE_POISSON_STRUCT.options
#endif
#ifndef CCTK_PARAMETER__POISSON__solver
#  define CCTK_PARAMETER__POISSON__solver PRIVATE_POISSON_STRUCT.solver
#endif

