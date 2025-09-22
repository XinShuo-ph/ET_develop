#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * mask_type;
} PRIVATE_NULLPSIINT_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NULLPSIINT_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, mask_type, CCTK_PARAMETER__NULLPSIINT__mask_type); \


#ifndef CCTK_PARAMETER__NULLPSIINT__mask_type
#  define CCTK_PARAMETER__NULLPSIINT__mask_type PRIVATE_NULLPSIINT_STRUCT.mask_type
#endif

