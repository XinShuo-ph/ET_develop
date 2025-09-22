#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL tolerance;
  CCTK_INT test_symmetric_interpolation;
  CCTK_INT warn_level;
} PRIVATE_TESTLOCALINTERP2_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TESTLOCALINTERP2_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, tolerance, CCTK_PARAMETER__TESTLOCALINTERP2__tolerance); \
  CCTK_DECLARE_INIT (CCTK_INT const, test_symmetric_interpolation, CCTK_PARAMETER__TESTLOCALINTERP2__test_symmetric_interpolation); \
  CCTK_DECLARE_INIT (CCTK_INT const, warn_level, CCTK_PARAMETER__TESTLOCALINTERP2__warn_level); \


#ifndef CCTK_PARAMETER__TESTLOCALINTERP2__tolerance
#  define CCTK_PARAMETER__TESTLOCALINTERP2__tolerance PRIVATE_TESTLOCALINTERP2_STRUCT.tolerance
#endif
#ifndef CCTK_PARAMETER__TESTLOCALINTERP2__test_symmetric_interpolation
#  define CCTK_PARAMETER__TESTLOCALINTERP2__test_symmetric_interpolation PRIVATE_TESTLOCALINTERP2_STRUCT.test_symmetric_interpolation
#endif
#ifndef CCTK_PARAMETER__TESTLOCALINTERP2__warn_level
#  define CCTK_PARAMETER__TESTLOCALINTERP2__warn_level PRIVATE_TESTLOCALINTERP2_STRUCT.warn_level
#endif

