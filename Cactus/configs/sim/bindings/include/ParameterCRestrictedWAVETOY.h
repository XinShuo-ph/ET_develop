#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * bound;
} RESTRICTED_WAVETOY_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_WAVETOY_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, bound, CCTK_PARAMETER__WAVETOY__bound); \


#ifndef CCTK_PARAMETER__WAVETOY__bound
#  define CCTK_PARAMETER__WAVETOY__bound RESTRICTED_WAVETOY_STRUCT.bound
#endif

