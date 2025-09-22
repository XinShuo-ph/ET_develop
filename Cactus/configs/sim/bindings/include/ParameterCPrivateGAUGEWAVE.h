#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * exact_method;
} PRIVATE_GAUGEWAVE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_GAUGEWAVE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, exact_method, CCTK_PARAMETER__GAUGEWAVE__exact_method); \


#ifndef CCTK_PARAMETER__GAUGEWAVE__exact_method
#  define CCTK_PARAMETER__GAUGEWAVE__exact_method PRIVATE_GAUGEWAVE_STRUCT.exact_method
#endif

