#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL threshold_percentage;
  const char * xml_clock;
  CCTK_INT disable_cactus_timer_set;
  CCTK_INT disable_timer_trees;
  CCTK_INT output_precision;
  CCTK_INT verbose;
} PRIVATE_TIMERS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TIMERS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, threshold_percentage, CCTK_PARAMETER__TIMERS__threshold_percentage); \
  CCTK_DECLARE_INIT (const char * const, xml_clock, CCTK_PARAMETER__TIMERS__xml_clock); \
  CCTK_DECLARE_INIT (CCTK_INT const, disable_cactus_timer_set, CCTK_PARAMETER__TIMERS__disable_cactus_timer_set); \
  CCTK_DECLARE_INIT (CCTK_INT const, disable_timer_trees, CCTK_PARAMETER__TIMERS__disable_timer_trees); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_precision, CCTK_PARAMETER__TIMERS__output_precision); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__TIMERS__verbose); \


#ifndef CCTK_PARAMETER__TIMERS__threshold_percentage
#  define CCTK_PARAMETER__TIMERS__threshold_percentage PRIVATE_TIMERS_STRUCT.threshold_percentage
#endif
#ifndef CCTK_PARAMETER__TIMERS__xml_clock
#  define CCTK_PARAMETER__TIMERS__xml_clock PRIVATE_TIMERS_STRUCT.xml_clock
#endif
#ifndef CCTK_PARAMETER__TIMERS__disable_cactus_timer_set
#  define CCTK_PARAMETER__TIMERS__disable_cactus_timer_set PRIVATE_TIMERS_STRUCT.disable_cactus_timer_set
#endif
#ifndef CCTK_PARAMETER__TIMERS__disable_timer_trees
#  define CCTK_PARAMETER__TIMERS__disable_timer_trees PRIVATE_TIMERS_STRUCT.disable_timer_trees
#endif
#ifndef CCTK_PARAMETER__TIMERS__output_precision
#  define CCTK_PARAMETER__TIMERS__output_precision PRIVATE_TIMERS_STRUCT.output_precision
#endif
#ifndef CCTK_PARAMETER__TIMERS__verbose
#  define CCTK_PARAMETER__TIMERS__verbose PRIVATE_TIMERS_STRUCT.verbose
#endif

