#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * elliptic_verbose;
} RESTRICTED_ELLBASE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_ELLBASE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, elliptic_verbose, CCTK_PARAMETER__ELLBASE__elliptic_verbose); \


#ifndef CCTK_PARAMETER__ELLBASE__elliptic_verbose
#  define CCTK_PARAMETER__ELLBASE__elliptic_verbose RESTRICTED_ELLBASE_STRUCT.elliptic_verbose
#endif

