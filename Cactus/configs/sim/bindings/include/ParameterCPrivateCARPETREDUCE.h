#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT debug_iweight;
  CCTK_INT min_max_time_interpolation;
  CCTK_INT verbose;
} PRIVATE_CARPETREDUCE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETREDUCE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, debug_iweight, CCTK_PARAMETER__CARPETREDUCE__debug_iweight); \
  CCTK_DECLARE_INIT (CCTK_INT const, min_max_time_interpolation, CCTK_PARAMETER__CARPETREDUCE__min_max_time_interpolation); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARPETREDUCE__verbose); \


#ifndef CCTK_PARAMETER__CARPETREDUCE__debug_iweight
#  define CCTK_PARAMETER__CARPETREDUCE__debug_iweight PRIVATE_CARPETREDUCE_STRUCT.debug_iweight
#endif
#ifndef CCTK_PARAMETER__CARPETREDUCE__min_max_time_interpolation
#  define CCTK_PARAMETER__CARPETREDUCE__min_max_time_interpolation PRIVATE_CARPETREDUCE_STRUCT.min_max_time_interpolation
#endif
#ifndef CCTK_PARAMETER__CARPETREDUCE__verbose
#  define CCTK_PARAMETER__CARPETREDUCE__verbose PRIVATE_CARPETREDUCE_STRUCT.verbose
#endif

