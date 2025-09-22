#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL random_jump_probability;
  CCTK_REAL statistics_every_seconds;
  CCTK_REAL very_expensive_factor;
  const char * initial_setup;
  const char * statistics_filename;
  CCTK_INT align_with_cachelines;
  CCTK_INT explore_eagerly_before_iteration;
  CCTK_INT loopsize_i;
  CCTK_INT loopsize_j;
  CCTK_INT loopsize_k;
  CCTK_INT max_size_factor;
  CCTK_INT selftest;
  CCTK_INT settle_after_iteration;
  CCTK_INT tilesize_i;
  CCTK_INT tilesize_j;
  CCTK_INT tilesize_k;
  CCTK_INT tryout_iterations;
  CCTK_INT use_smt_threads;
  CCTK_INT verbose;
  CCTK_INT veryverbose;
} PRIVATE_LOOPCONTROL_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_LOOPCONTROL_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, random_jump_probability, CCTK_PARAMETER__LOOPCONTROL__random_jump_probability); \
  CCTK_DECLARE_INIT (CCTK_REAL const, statistics_every_seconds, CCTK_PARAMETER__LOOPCONTROL__statistics_every_seconds); \
  CCTK_DECLARE_INIT (CCTK_REAL const, very_expensive_factor, CCTK_PARAMETER__LOOPCONTROL__very_expensive_factor); \
  CCTK_DECLARE_INIT (const char * const, initial_setup, CCTK_PARAMETER__LOOPCONTROL__initial_setup); \
  CCTK_DECLARE_INIT (const char * const, statistics_filename, CCTK_PARAMETER__LOOPCONTROL__statistics_filename); \
  CCTK_DECLARE_INIT (CCTK_INT const, align_with_cachelines, CCTK_PARAMETER__LOOPCONTROL__align_with_cachelines); \
  CCTK_DECLARE_INIT (CCTK_INT const, explore_eagerly_before_iteration, CCTK_PARAMETER__LOOPCONTROL__explore_eagerly_before_iteration); \
  CCTK_DECLARE_INIT (CCTK_INT const, loopsize_i, CCTK_PARAMETER__LOOPCONTROL__loopsize_i); \
  CCTK_DECLARE_INIT (CCTK_INT const, loopsize_j, CCTK_PARAMETER__LOOPCONTROL__loopsize_j); \
  CCTK_DECLARE_INIT (CCTK_INT const, loopsize_k, CCTK_PARAMETER__LOOPCONTROL__loopsize_k); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_size_factor, CCTK_PARAMETER__LOOPCONTROL__max_size_factor); \
  CCTK_DECLARE_INIT (CCTK_INT const, selftest, CCTK_PARAMETER__LOOPCONTROL__selftest); \
  CCTK_DECLARE_INIT (CCTK_INT const, settle_after_iteration, CCTK_PARAMETER__LOOPCONTROL__settle_after_iteration); \
  CCTK_DECLARE_INIT (CCTK_INT const, tilesize_i, CCTK_PARAMETER__LOOPCONTROL__tilesize_i); \
  CCTK_DECLARE_INIT (CCTK_INT const, tilesize_j, CCTK_PARAMETER__LOOPCONTROL__tilesize_j); \
  CCTK_DECLARE_INIT (CCTK_INT const, tilesize_k, CCTK_PARAMETER__LOOPCONTROL__tilesize_k); \
  CCTK_DECLARE_INIT (CCTK_INT const, tryout_iterations, CCTK_PARAMETER__LOOPCONTROL__tryout_iterations); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_smt_threads, CCTK_PARAMETER__LOOPCONTROL__use_smt_threads); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__LOOPCONTROL__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, veryverbose, CCTK_PARAMETER__LOOPCONTROL__veryverbose); \


#ifndef CCTK_PARAMETER__LOOPCONTROL__random_jump_probability
#  define CCTK_PARAMETER__LOOPCONTROL__random_jump_probability PRIVATE_LOOPCONTROL_STRUCT.random_jump_probability
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__statistics_every_seconds
#  define CCTK_PARAMETER__LOOPCONTROL__statistics_every_seconds PRIVATE_LOOPCONTROL_STRUCT.statistics_every_seconds
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__very_expensive_factor
#  define CCTK_PARAMETER__LOOPCONTROL__very_expensive_factor PRIVATE_LOOPCONTROL_STRUCT.very_expensive_factor
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__initial_setup
#  define CCTK_PARAMETER__LOOPCONTROL__initial_setup PRIVATE_LOOPCONTROL_STRUCT.initial_setup
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__statistics_filename
#  define CCTK_PARAMETER__LOOPCONTROL__statistics_filename PRIVATE_LOOPCONTROL_STRUCT.statistics_filename
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__align_with_cachelines
#  define CCTK_PARAMETER__LOOPCONTROL__align_with_cachelines PRIVATE_LOOPCONTROL_STRUCT.align_with_cachelines
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__explore_eagerly_before_iteration
#  define CCTK_PARAMETER__LOOPCONTROL__explore_eagerly_before_iteration PRIVATE_LOOPCONTROL_STRUCT.explore_eagerly_before_iteration
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__loopsize_i
#  define CCTK_PARAMETER__LOOPCONTROL__loopsize_i PRIVATE_LOOPCONTROL_STRUCT.loopsize_i
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__loopsize_j
#  define CCTK_PARAMETER__LOOPCONTROL__loopsize_j PRIVATE_LOOPCONTROL_STRUCT.loopsize_j
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__loopsize_k
#  define CCTK_PARAMETER__LOOPCONTROL__loopsize_k PRIVATE_LOOPCONTROL_STRUCT.loopsize_k
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__max_size_factor
#  define CCTK_PARAMETER__LOOPCONTROL__max_size_factor PRIVATE_LOOPCONTROL_STRUCT.max_size_factor
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__selftest
#  define CCTK_PARAMETER__LOOPCONTROL__selftest PRIVATE_LOOPCONTROL_STRUCT.selftest
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__settle_after_iteration
#  define CCTK_PARAMETER__LOOPCONTROL__settle_after_iteration PRIVATE_LOOPCONTROL_STRUCT.settle_after_iteration
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__tilesize_i
#  define CCTK_PARAMETER__LOOPCONTROL__tilesize_i PRIVATE_LOOPCONTROL_STRUCT.tilesize_i
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__tilesize_j
#  define CCTK_PARAMETER__LOOPCONTROL__tilesize_j PRIVATE_LOOPCONTROL_STRUCT.tilesize_j
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__tilesize_k
#  define CCTK_PARAMETER__LOOPCONTROL__tilesize_k PRIVATE_LOOPCONTROL_STRUCT.tilesize_k
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__tryout_iterations
#  define CCTK_PARAMETER__LOOPCONTROL__tryout_iterations PRIVATE_LOOPCONTROL_STRUCT.tryout_iterations
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__use_smt_threads
#  define CCTK_PARAMETER__LOOPCONTROL__use_smt_threads PRIVATE_LOOPCONTROL_STRUCT.use_smt_threads
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__verbose
#  define CCTK_PARAMETER__LOOPCONTROL__verbose PRIVATE_LOOPCONTROL_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__LOOPCONTROL__veryverbose
#  define CCTK_PARAMETER__LOOPCONTROL__veryverbose PRIVATE_LOOPCONTROL_STRUCT.veryverbose
#endif

