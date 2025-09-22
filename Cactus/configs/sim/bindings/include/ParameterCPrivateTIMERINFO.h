#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * clock;
  const char * timer;
  CCTK_INT every;
} PRIVATE_TIMERINFO_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TIMERINFO_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, clock, CCTK_PARAMETER__TIMERINFO__clock); \
  CCTK_DECLARE_INIT (const char * const, timer, CCTK_PARAMETER__TIMERINFO__timer); \
  CCTK_DECLARE_INIT (CCTK_INT const, every, CCTK_PARAMETER__TIMERINFO__every); \


#ifndef CCTK_PARAMETER__TIMERINFO__clock
#  define CCTK_PARAMETER__TIMERINFO__clock PRIVATE_TIMERINFO_STRUCT.clock
#endif
#ifndef CCTK_PARAMETER__TIMERINFO__timer
#  define CCTK_PARAMETER__TIMERINFO__timer PRIVATE_TIMERINFO_STRUCT.timer
#endif
#ifndef CCTK_PARAMETER__TIMERINFO__every
#  define CCTK_PARAMETER__TIMERINFO__every PRIVATE_TIMERINFO_STRUCT.every
#endif

