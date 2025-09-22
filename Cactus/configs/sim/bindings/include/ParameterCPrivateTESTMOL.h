#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * RHSSlowexpression;
  const char * RHSexpression;
  CCTK_INT evolve_grid_array;
  CCTK_INT evolve_grid_function;
} PRIVATE_TESTMOL_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TESTMOL_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, RHSSlowexpression, CCTK_PARAMETER__TESTMOL__RHSSlowexpression); \
  CCTK_DECLARE_INIT (const char * const, RHSexpression, CCTK_PARAMETER__TESTMOL__RHSexpression); \
  CCTK_DECLARE_INIT (CCTK_INT const, evolve_grid_array, CCTK_PARAMETER__TESTMOL__evolve_grid_array); \
  CCTK_DECLARE_INIT (CCTK_INT const, evolve_grid_function, CCTK_PARAMETER__TESTMOL__evolve_grid_function); \


#ifndef CCTK_PARAMETER__TESTMOL__RHSSlowexpression
#  define CCTK_PARAMETER__TESTMOL__RHSSlowexpression PRIVATE_TESTMOL_STRUCT.RHSSlowexpression
#endif
#ifndef CCTK_PARAMETER__TESTMOL__RHSexpression
#  define CCTK_PARAMETER__TESTMOL__RHSexpression PRIVATE_TESTMOL_STRUCT.RHSexpression
#endif
#ifndef CCTK_PARAMETER__TESTMOL__evolve_grid_array
#  define CCTK_PARAMETER__TESTMOL__evolve_grid_array PRIVATE_TESTMOL_STRUCT.evolve_grid_array
#endif
#ifndef CCTK_PARAMETER__TESTMOL__evolve_grid_function
#  define CCTK_PARAMETER__TESTMOL__evolve_grid_function PRIVATE_TESTMOL_STRUCT.evolve_grid_function
#endif

