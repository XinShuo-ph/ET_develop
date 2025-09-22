#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * custom_bound;
  const char * custom_options;
} PRIVATE_WAVETOYEXTRA_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_WAVETOYEXTRA_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, custom_bound, CCTK_PARAMETER__WAVETOYEXTRA__custom_bound); \
  CCTK_DECLARE_INIT (const char * const, custom_options, CCTK_PARAMETER__WAVETOYEXTRA__custom_options); \


#ifndef CCTK_PARAMETER__WAVETOYEXTRA__custom_bound
#  define CCTK_PARAMETER__WAVETOYEXTRA__custom_bound PRIVATE_WAVETOYEXTRA_STRUCT.custom_bound
#endif
#ifndef CCTK_PARAMETER__WAVETOYEXTRA__custom_options
#  define CCTK_PARAMETER__WAVETOYEXTRA__custom_options PRIVATE_WAVETOYEXTRA_STRUCT.custom_options
#endif

