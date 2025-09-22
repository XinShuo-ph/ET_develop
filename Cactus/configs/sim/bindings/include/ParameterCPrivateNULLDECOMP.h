#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT store_ylms;
  CCTK_INT use_rsYlm;
} PRIVATE_NULLDECOMP_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NULLDECOMP_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, store_ylms, CCTK_PARAMETER__NULLDECOMP__store_ylms); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_rsYlm, CCTK_PARAMETER__NULLDECOMP__use_rsYlm); \


#ifndef CCTK_PARAMETER__NULLDECOMP__store_ylms
#  define CCTK_PARAMETER__NULLDECOMP__store_ylms PRIVATE_NULLDECOMP_STRUCT.store_ylms
#endif
#ifndef CCTK_PARAMETER__NULLDECOMP__use_rsYlm
#  define CCTK_PARAMETER__NULLDECOMP__use_rsYlm PRIVATE_NULLDECOMP_STRUCT.use_rsYlm
#endif

