#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * memstat_file;
  const char * timestat_file;
  CCTK_INT barrier_between_stages;
  CCTK_INT barriers;
  CCTK_INT check_bboxes;
  CCTK_INT check_communication_schedule;
  CCTK_INT combine_recompose;
  CCTK_INT combine_sends;
  CCTK_INT commstate_verbose;
  CCTK_INT electric_fence;
  CCTK_INT fence_width;
  CCTK_INT interleave_communications;
  CCTK_INT interpolate_from_buffer_zones;
  CCTK_INT max_allowed_memory_MB;
  CCTK_INT max_core_size_MB;
  CCTK_INT max_memory_size_MB;
  CCTK_INT message_count_multiplier;
  CCTK_INT message_size_multiplier;
  CCTK_INT output_bboxes;
  CCTK_INT pad_to_cachelines;
  CCTK_INT poison_new_memory;
  CCTK_INT print_memstats_every;
  CCTK_INT print_timestats_every;
  CCTK_INT test_backtrace;
  CCTK_INT use_dgfe;
  CCTK_INT use_ipm_timing_regions;
  CCTK_INT use_loopcontrol_in_operators;
  CCTK_INT use_mpi_send;
  CCTK_INT use_mpi_ssend;
  CCTK_INT use_openmp;
  CCTK_INT verbose;
} PRIVATE_CARPETLIB_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETLIB_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, memstat_file, CCTK_PARAMETER__CARPETLIB__memstat_file); \
  CCTK_DECLARE_INIT (const char * const, timestat_file, CCTK_PARAMETER__CARPETLIB__timestat_file); \
  CCTK_DECLARE_INIT (CCTK_INT const, barrier_between_stages, CCTK_PARAMETER__CARPETLIB__barrier_between_stages); \
  CCTK_DECLARE_INIT (CCTK_INT const, barriers, CCTK_PARAMETER__CARPETLIB__barriers); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_bboxes, CCTK_PARAMETER__CARPETLIB__check_bboxes); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_communication_schedule, CCTK_PARAMETER__CARPETLIB__check_communication_schedule); \
  CCTK_DECLARE_INIT (CCTK_INT const, combine_recompose, CCTK_PARAMETER__CARPETLIB__combine_recompose); \
  CCTK_DECLARE_INIT (CCTK_INT const, combine_sends, CCTK_PARAMETER__CARPETLIB__combine_sends); \
  CCTK_DECLARE_INIT (CCTK_INT const, commstate_verbose, CCTK_PARAMETER__CARPETLIB__commstate_verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, electric_fence, CCTK_PARAMETER__CARPETLIB__electric_fence); \
  CCTK_DECLARE_INIT (CCTK_INT const, fence_width, CCTK_PARAMETER__CARPETLIB__fence_width); \
  CCTK_DECLARE_INIT (CCTK_INT const, interleave_communications, CCTK_PARAMETER__CARPETLIB__interleave_communications); \
  CCTK_DECLARE_INIT (CCTK_INT const, interpolate_from_buffer_zones, CCTK_PARAMETER__CARPETLIB__interpolate_from_buffer_zones); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_allowed_memory_MB, CCTK_PARAMETER__CARPETLIB__max_allowed_memory_MB); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_core_size_MB, CCTK_PARAMETER__CARPETLIB__max_core_size_MB); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_memory_size_MB, CCTK_PARAMETER__CARPETLIB__max_memory_size_MB); \
  CCTK_DECLARE_INIT (CCTK_INT const, message_count_multiplier, CCTK_PARAMETER__CARPETLIB__message_count_multiplier); \
  CCTK_DECLARE_INIT (CCTK_INT const, message_size_multiplier, CCTK_PARAMETER__CARPETLIB__message_size_multiplier); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_bboxes, CCTK_PARAMETER__CARPETLIB__output_bboxes); \
  CCTK_DECLARE_INIT (CCTK_INT const, pad_to_cachelines, CCTK_PARAMETER__CARPETLIB__pad_to_cachelines); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_new_memory, CCTK_PARAMETER__CARPETLIB__poison_new_memory); \
  CCTK_DECLARE_INIT (CCTK_INT const, print_memstats_every, CCTK_PARAMETER__CARPETLIB__print_memstats_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, print_timestats_every, CCTK_PARAMETER__CARPETLIB__print_timestats_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, test_backtrace, CCTK_PARAMETER__CARPETLIB__test_backtrace); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_dgfe, CCTK_PARAMETER__CARPETLIB__use_dgfe); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_ipm_timing_regions, CCTK_PARAMETER__CARPETLIB__use_ipm_timing_regions); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_loopcontrol_in_operators, CCTK_PARAMETER__CARPETLIB__use_loopcontrol_in_operators); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_mpi_send, CCTK_PARAMETER__CARPETLIB__use_mpi_send); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_mpi_ssend, CCTK_PARAMETER__CARPETLIB__use_mpi_ssend); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_openmp, CCTK_PARAMETER__CARPETLIB__use_openmp); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARPETLIB__verbose); \


#ifndef CCTK_PARAMETER__CARPETLIB__memstat_file
#  define CCTK_PARAMETER__CARPETLIB__memstat_file PRIVATE_CARPETLIB_STRUCT.memstat_file
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__timestat_file
#  define CCTK_PARAMETER__CARPETLIB__timestat_file PRIVATE_CARPETLIB_STRUCT.timestat_file
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__barrier_between_stages
#  define CCTK_PARAMETER__CARPETLIB__barrier_between_stages PRIVATE_CARPETLIB_STRUCT.barrier_between_stages
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__barriers
#  define CCTK_PARAMETER__CARPETLIB__barriers PRIVATE_CARPETLIB_STRUCT.barriers
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__check_bboxes
#  define CCTK_PARAMETER__CARPETLIB__check_bboxes PRIVATE_CARPETLIB_STRUCT.check_bboxes
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__check_communication_schedule
#  define CCTK_PARAMETER__CARPETLIB__check_communication_schedule PRIVATE_CARPETLIB_STRUCT.check_communication_schedule
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__combine_recompose
#  define CCTK_PARAMETER__CARPETLIB__combine_recompose PRIVATE_CARPETLIB_STRUCT.combine_recompose
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__combine_sends
#  define CCTK_PARAMETER__CARPETLIB__combine_sends PRIVATE_CARPETLIB_STRUCT.combine_sends
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__commstate_verbose
#  define CCTK_PARAMETER__CARPETLIB__commstate_verbose PRIVATE_CARPETLIB_STRUCT.commstate_verbose
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__electric_fence
#  define CCTK_PARAMETER__CARPETLIB__electric_fence PRIVATE_CARPETLIB_STRUCT.electric_fence
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__fence_width
#  define CCTK_PARAMETER__CARPETLIB__fence_width PRIVATE_CARPETLIB_STRUCT.fence_width
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__interleave_communications
#  define CCTK_PARAMETER__CARPETLIB__interleave_communications PRIVATE_CARPETLIB_STRUCT.interleave_communications
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__interpolate_from_buffer_zones
#  define CCTK_PARAMETER__CARPETLIB__interpolate_from_buffer_zones PRIVATE_CARPETLIB_STRUCT.interpolate_from_buffer_zones
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__max_allowed_memory_MB
#  define CCTK_PARAMETER__CARPETLIB__max_allowed_memory_MB PRIVATE_CARPETLIB_STRUCT.max_allowed_memory_MB
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__max_core_size_MB
#  define CCTK_PARAMETER__CARPETLIB__max_core_size_MB PRIVATE_CARPETLIB_STRUCT.max_core_size_MB
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__max_memory_size_MB
#  define CCTK_PARAMETER__CARPETLIB__max_memory_size_MB PRIVATE_CARPETLIB_STRUCT.max_memory_size_MB
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__message_count_multiplier
#  define CCTK_PARAMETER__CARPETLIB__message_count_multiplier PRIVATE_CARPETLIB_STRUCT.message_count_multiplier
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__message_size_multiplier
#  define CCTK_PARAMETER__CARPETLIB__message_size_multiplier PRIVATE_CARPETLIB_STRUCT.message_size_multiplier
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__output_bboxes
#  define CCTK_PARAMETER__CARPETLIB__output_bboxes PRIVATE_CARPETLIB_STRUCT.output_bboxes
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__pad_to_cachelines
#  define CCTK_PARAMETER__CARPETLIB__pad_to_cachelines PRIVATE_CARPETLIB_STRUCT.pad_to_cachelines
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__poison_new_memory
#  define CCTK_PARAMETER__CARPETLIB__poison_new_memory PRIVATE_CARPETLIB_STRUCT.poison_new_memory
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__print_memstats_every
#  define CCTK_PARAMETER__CARPETLIB__print_memstats_every PRIVATE_CARPETLIB_STRUCT.print_memstats_every
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__print_timestats_every
#  define CCTK_PARAMETER__CARPETLIB__print_timestats_every PRIVATE_CARPETLIB_STRUCT.print_timestats_every
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__test_backtrace
#  define CCTK_PARAMETER__CARPETLIB__test_backtrace PRIVATE_CARPETLIB_STRUCT.test_backtrace
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__use_dgfe
#  define CCTK_PARAMETER__CARPETLIB__use_dgfe PRIVATE_CARPETLIB_STRUCT.use_dgfe
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__use_ipm_timing_regions
#  define CCTK_PARAMETER__CARPETLIB__use_ipm_timing_regions PRIVATE_CARPETLIB_STRUCT.use_ipm_timing_regions
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__use_loopcontrol_in_operators
#  define CCTK_PARAMETER__CARPETLIB__use_loopcontrol_in_operators PRIVATE_CARPETLIB_STRUCT.use_loopcontrol_in_operators
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__use_mpi_send
#  define CCTK_PARAMETER__CARPETLIB__use_mpi_send PRIVATE_CARPETLIB_STRUCT.use_mpi_send
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__use_mpi_ssend
#  define CCTK_PARAMETER__CARPETLIB__use_mpi_ssend PRIVATE_CARPETLIB_STRUCT.use_mpi_ssend
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__use_openmp
#  define CCTK_PARAMETER__CARPETLIB__use_openmp PRIVATE_CARPETLIB_STRUCT.use_openmp
#endif
#ifndef CCTK_PARAMETER__CARPETLIB__verbose
#  define CCTK_PARAMETER__CARPETLIB__verbose PRIVATE_CARPETLIB_STRUCT.verbose
#endif

