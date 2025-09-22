#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * TestParameter;
} PRIVATE_TESTTIMERS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TESTTIMERS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, TestParameter, CCTK_PARAMETER__TESTTIMERS__TestParameter); \


#ifndef CCTK_PARAMETER__TESTTIMERS__TestParameter
#  define CCTK_PARAMETER__TESTTIMERS__TestParameter PRIVATE_TESTTIMERS_STRUCT.TestParameter
#endif

