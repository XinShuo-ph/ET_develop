#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL interp_radius;
  CCTK_INT arrsize;
  CCTK_INT interpolation_order;
} PRIVATE_DEMOINTERP_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_DEMOINTERP_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, interp_radius, CCTK_PARAMETER__DEMOINTERP__interp_radius); \
  CCTK_DECLARE_INIT (CCTK_INT const, arrsize, CCTK_PARAMETER__DEMOINTERP__arrsize); \
  CCTK_DECLARE_INIT (CCTK_INT const, interpolation_order, CCTK_PARAMETER__DEMOINTERP__interpolation_order); \


#ifndef CCTK_PARAMETER__DEMOINTERP__interp_radius
#  define CCTK_PARAMETER__DEMOINTERP__interp_radius PRIVATE_DEMOINTERP_STRUCT.interp_radius
#endif
#ifndef CCTK_PARAMETER__DEMOINTERP__arrsize
#  define CCTK_PARAMETER__DEMOINTERP__arrsize PRIVATE_DEMOINTERP_STRUCT.arrsize
#endif
#ifndef CCTK_PARAMETER__DEMOINTERP__interpolation_order
#  define CCTK_PARAMETER__DEMOINTERP__interpolation_order PRIVATE_DEMOINTERP_STRUCT.interpolation_order
#endif

