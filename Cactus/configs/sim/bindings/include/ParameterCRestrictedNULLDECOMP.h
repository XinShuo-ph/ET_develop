#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT l_max;
} RESTRICTED_NULLDECOMP_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_NULLDECOMP_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, l_max, CCTK_PARAMETER__NULLDECOMP__l_max); \


#ifndef CCTK_PARAMETER__NULLDECOMP__l_max
#  define CCTK_PARAMETER__NULLDECOMP__l_max RESTRICTED_NULLDECOMP_STRUCT.l_max
#endif

