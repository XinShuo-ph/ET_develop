#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,events_dcache,)&&\
CCTK_DECLARE(CCTK_STRING,events_flops,)&&\
CCTK_DECLARE(CCTK_STRING,events_icache,)&&\
CCTK_DECLARE(CCTK_STRING,events_ipc,)&&\
CCTK_DECLARE(CCTK_STRING,events_memory,)&&\
CCTK_DECLARE(CCTK_INT,define_statistics_clocks,)&&\
CCTK_DECLARE(CCTK_INT,dgemm_N,)&&\
CCTK_DECLARE(CCTK_INT,out_every,)&&\
CCTK_DECLARE(CCTK_INT,per_thread_statistics,)&&\
CCTK_DECLARE(CCTK_INT,use_multiplexing,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /PAPIpriv/events_dcache, events_flops, events_icache, events_ipc, events_memory, define_statistics_clocks, dgemm_N, out_every, per_thread_statistics, use_multiplexing, verbose&&\

