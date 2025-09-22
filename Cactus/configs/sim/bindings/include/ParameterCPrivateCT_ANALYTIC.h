#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * free_data;
} PRIVATE_CT_ANALYTIC_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CT_ANALYTIC_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, free_data, CCTK_PARAMETER__CT_ANALYTIC__free_data); \


#ifndef CCTK_PARAMETER__CT_ANALYTIC__free_data
#  define CCTK_PARAMETER__CT_ANALYTIC__free_data PRIVATE_CT_ANALYTIC_STRUCT.free_data
#endif

