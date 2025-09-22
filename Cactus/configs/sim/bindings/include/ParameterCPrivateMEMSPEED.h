#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT skip_largemem_benchmarks;
  CCTK_INT verbose;
} PRIVATE_MEMSPEED_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_MEMSPEED_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, skip_largemem_benchmarks, CCTK_PARAMETER__MEMSPEED__skip_largemem_benchmarks); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__MEMSPEED__verbose); \


#ifndef CCTK_PARAMETER__MEMSPEED__skip_largemem_benchmarks
#  define CCTK_PARAMETER__MEMSPEED__skip_largemem_benchmarks PRIVATE_MEMSPEED_STRUCT.skip_largemem_benchmarks
#endif
#ifndef CCTK_PARAMETER__MEMSPEED__verbose
#  define CCTK_PARAMETER__MEMSPEED__verbose PRIVATE_MEMSPEED_STRUCT.verbose
#endif

