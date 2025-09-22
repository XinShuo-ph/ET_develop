#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT use_mask;
} RESTRICTED_SPACEMASK_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_SPACEMASK_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, use_mask, CCTK_PARAMETER__SPACEMASK__use_mask); \


#ifndef CCTK_PARAMETER__SPACEMASK__use_mask
#  define CCTK_PARAMETER__SPACEMASK__use_mask RESTRICTED_SPACEMASK_STRUCT.use_mask
#endif

