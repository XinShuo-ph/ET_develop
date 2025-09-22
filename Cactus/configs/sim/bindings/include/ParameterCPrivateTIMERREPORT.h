#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * all_timers_clock;
  const char * out_filename;
  CCTK_INT before_checkpoint;
  CCTK_INT n_top_timers;
  CCTK_INT next;
  CCTK_INT out_at;
  CCTK_INT out_every;
  CCTK_INT output_all_timers;
  CCTK_INT output_all_timers_readable;
  CCTK_INT output_all_timers_together;
  CCTK_INT output_schedule_timers;
} PRIVATE_TIMERREPORT_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TIMERREPORT_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, all_timers_clock, CCTK_PARAMETER__TIMERREPORT__all_timers_clock); \
  CCTK_DECLARE_INIT (const char * const, out_filename, CCTK_PARAMETER__TIMERREPORT__out_filename); \
  CCTK_DECLARE_INIT (CCTK_INT const, before_checkpoint, CCTK_PARAMETER__TIMERREPORT__before_checkpoint); \
  CCTK_DECLARE_INIT (CCTK_INT const, n_top_timers, CCTK_PARAMETER__TIMERREPORT__n_top_timers); \
  CCTK_DECLARE_INIT (CCTK_INT const, next, CCTK_PARAMETER__TIMERREPORT__next); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_at, CCTK_PARAMETER__TIMERREPORT__out_at); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_every, CCTK_PARAMETER__TIMERREPORT__out_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_all_timers, CCTK_PARAMETER__TIMERREPORT__output_all_timers); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_all_timers_readable, CCTK_PARAMETER__TIMERREPORT__output_all_timers_readable); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_all_timers_together, CCTK_PARAMETER__TIMERREPORT__output_all_timers_together); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_schedule_timers, CCTK_PARAMETER__TIMERREPORT__output_schedule_timers); \


#ifndef CCTK_PARAMETER__TIMERREPORT__all_timers_clock
#  define CCTK_PARAMETER__TIMERREPORT__all_timers_clock PRIVATE_TIMERREPORT_STRUCT.all_timers_clock
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__out_filename
#  define CCTK_PARAMETER__TIMERREPORT__out_filename PRIVATE_TIMERREPORT_STRUCT.out_filename
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__before_checkpoint
#  define CCTK_PARAMETER__TIMERREPORT__before_checkpoint PRIVATE_TIMERREPORT_STRUCT.before_checkpoint
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__n_top_timers
#  define CCTK_PARAMETER__TIMERREPORT__n_top_timers PRIVATE_TIMERREPORT_STRUCT.n_top_timers
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__next
#  define CCTK_PARAMETER__TIMERREPORT__next PRIVATE_TIMERREPORT_STRUCT.next
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__out_at
#  define CCTK_PARAMETER__TIMERREPORT__out_at PRIVATE_TIMERREPORT_STRUCT.out_at
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__out_every
#  define CCTK_PARAMETER__TIMERREPORT__out_every PRIVATE_TIMERREPORT_STRUCT.out_every
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__output_all_timers
#  define CCTK_PARAMETER__TIMERREPORT__output_all_timers PRIVATE_TIMERREPORT_STRUCT.output_all_timers
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__output_all_timers_readable
#  define CCTK_PARAMETER__TIMERREPORT__output_all_timers_readable PRIVATE_TIMERREPORT_STRUCT.output_all_timers_readable
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__output_all_timers_together
#  define CCTK_PARAMETER__TIMERREPORT__output_all_timers_together PRIVATE_TIMERREPORT_STRUCT.output_all_timers_together
#endif
#ifndef CCTK_PARAMETER__TIMERREPORT__output_schedule_timers
#  define CCTK_PARAMETER__TIMERREPORT__output_schedule_timers PRIVATE_TIMERREPORT_STRUCT.output_schedule_timers
#endif

