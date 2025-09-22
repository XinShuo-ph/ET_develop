#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * events_dcache;
  const char * events_flops;
  const char * events_icache;
  const char * events_ipc;
  const char * events_memory;
  CCTK_INT define_statistics_clocks;
  CCTK_INT dgemm_N;
  CCTK_INT out_every;
  CCTK_INT per_thread_statistics;
  CCTK_INT use_multiplexing;
  CCTK_INT verbose;
} PRIVATE_PAPI_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_PAPI_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, events_dcache, CCTK_PARAMETER__PAPI__events_dcache); \
  CCTK_DECLARE_INIT (const char * const, events_flops, CCTK_PARAMETER__PAPI__events_flops); \
  CCTK_DECLARE_INIT (const char * const, events_icache, CCTK_PARAMETER__PAPI__events_icache); \
  CCTK_DECLARE_INIT (const char * const, events_ipc, CCTK_PARAMETER__PAPI__events_ipc); \
  CCTK_DECLARE_INIT (const char * const, events_memory, CCTK_PARAMETER__PAPI__events_memory); \
  CCTK_DECLARE_INIT (CCTK_INT const, define_statistics_clocks, CCTK_PARAMETER__PAPI__define_statistics_clocks); \
  CCTK_DECLARE_INIT (CCTK_INT const, dgemm_N, CCTK_PARAMETER__PAPI__dgemm_N); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_every, CCTK_PARAMETER__PAPI__out_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, per_thread_statistics, CCTK_PARAMETER__PAPI__per_thread_statistics); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_multiplexing, CCTK_PARAMETER__PAPI__use_multiplexing); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__PAPI__verbose); \


#ifndef CCTK_PARAMETER__PAPI__events_dcache
#  define CCTK_PARAMETER__PAPI__events_dcache PRIVATE_PAPI_STRUCT.events_dcache
#endif
#ifndef CCTK_PARAMETER__PAPI__events_flops
#  define CCTK_PARAMETER__PAPI__events_flops PRIVATE_PAPI_STRUCT.events_flops
#endif
#ifndef CCTK_PARAMETER__PAPI__events_icache
#  define CCTK_PARAMETER__PAPI__events_icache PRIVATE_PAPI_STRUCT.events_icache
#endif
#ifndef CCTK_PARAMETER__PAPI__events_ipc
#  define CCTK_PARAMETER__PAPI__events_ipc PRIVATE_PAPI_STRUCT.events_ipc
#endif
#ifndef CCTK_PARAMETER__PAPI__events_memory
#  define CCTK_PARAMETER__PAPI__events_memory PRIVATE_PAPI_STRUCT.events_memory
#endif
#ifndef CCTK_PARAMETER__PAPI__define_statistics_clocks
#  define CCTK_PARAMETER__PAPI__define_statistics_clocks PRIVATE_PAPI_STRUCT.define_statistics_clocks
#endif
#ifndef CCTK_PARAMETER__PAPI__dgemm_N
#  define CCTK_PARAMETER__PAPI__dgemm_N PRIVATE_PAPI_STRUCT.dgemm_N
#endif
#ifndef CCTK_PARAMETER__PAPI__out_every
#  define CCTK_PARAMETER__PAPI__out_every PRIVATE_PAPI_STRUCT.out_every
#endif
#ifndef CCTK_PARAMETER__PAPI__per_thread_statistics
#  define CCTK_PARAMETER__PAPI__per_thread_statistics PRIVATE_PAPI_STRUCT.per_thread_statistics
#endif
#ifndef CCTK_PARAMETER__PAPI__use_multiplexing
#  define CCTK_PARAMETER__PAPI__use_multiplexing PRIVATE_PAPI_STRUCT.use_multiplexing
#endif
#ifndef CCTK_PARAMETER__PAPI__verbose
#  define CCTK_PARAMETER__PAPI__verbose PRIVATE_PAPI_STRUCT.verbose
#endif

