#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL imaginary_value;
  CCTK_REAL power_value;
  CCTK_REAL real_value;
} PRIVATE_TESTCOMPLEX_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TESTCOMPLEX_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, imaginary_value, CCTK_PARAMETER__TESTCOMPLEX__imaginary_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const, power_value, CCTK_PARAMETER__TESTCOMPLEX__power_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const, real_value, CCTK_PARAMETER__TESTCOMPLEX__real_value); \


#ifndef CCTK_PARAMETER__TESTCOMPLEX__imaginary_value
#  define CCTK_PARAMETER__TESTCOMPLEX__imaginary_value PRIVATE_TESTCOMPLEX_STRUCT.imaginary_value
#endif
#ifndef CCTK_PARAMETER__TESTCOMPLEX__power_value
#  define CCTK_PARAMETER__TESTCOMPLEX__power_value PRIVATE_TESTCOMPLEX_STRUCT.power_value
#endif
#ifndef CCTK_PARAMETER__TESTCOMPLEX__real_value
#  define CCTK_PARAMETER__TESTCOMPLEX__real_value PRIVATE_TESTCOMPLEX_STRUCT.real_value
#endif

