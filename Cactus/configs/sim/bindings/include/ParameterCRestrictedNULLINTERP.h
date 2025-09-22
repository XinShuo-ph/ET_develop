#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * stereo_patch_type;
  CCTK_INT deriv_accuracy;
  CCTK_INT poison_test;
} RESTRICTED_NULLINTERP_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_NULLINTERP_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, stereo_patch_type, CCTK_PARAMETER__NULLINTERP__stereo_patch_type); \
  CCTK_DECLARE_INIT (CCTK_INT const, deriv_accuracy, CCTK_PARAMETER__NULLINTERP__deriv_accuracy); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_test, CCTK_PARAMETER__NULLINTERP__poison_test); \


#ifndef CCTK_PARAMETER__NULLINTERP__stereo_patch_type
#  define CCTK_PARAMETER__NULLINTERP__stereo_patch_type RESTRICTED_NULLINTERP_STRUCT.stereo_patch_type
#endif
#ifndef CCTK_PARAMETER__NULLINTERP__deriv_accuracy
#  define CCTK_PARAMETER__NULLINTERP__deriv_accuracy RESTRICTED_NULLINTERP_STRUCT.deriv_accuracy
#endif
#ifndef CCTK_PARAMETER__NULLINTERP__poison_test
#  define CCTK_PARAMETER__NULLINTERP__poison_test RESTRICTED_NULLINTERP_STRUCT.poison_test
#endif

