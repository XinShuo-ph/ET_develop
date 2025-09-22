#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * enforce_vars;
  CCTK_INT enforce_mask;
  CCTK_INT enlarge_evolved_region_by;
  CCTK_INT provide_buffer_mask;
  CCTK_INT verbose;
  CCTK_INT writeNaNs;
} PRIVATE_CARPETEVOLUTIONMASK_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETEVOLUTIONMASK_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, enforce_vars, CCTK_PARAMETER__CARPETEVOLUTIONMASK__enforce_vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, enforce_mask, CCTK_PARAMETER__CARPETEVOLUTIONMASK__enforce_mask); \
  CCTK_DECLARE_INIT (CCTK_INT const, enlarge_evolved_region_by, CCTK_PARAMETER__CARPETEVOLUTIONMASK__enlarge_evolved_region_by); \
  CCTK_DECLARE_INIT (CCTK_INT const, provide_buffer_mask, CCTK_PARAMETER__CARPETEVOLUTIONMASK__provide_buffer_mask); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARPETEVOLUTIONMASK__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, writeNaNs, CCTK_PARAMETER__CARPETEVOLUTIONMASK__writeNaNs); \


#ifndef CCTK_PARAMETER__CARPETEVOLUTIONMASK__enforce_vars
#  define CCTK_PARAMETER__CARPETEVOLUTIONMASK__enforce_vars PRIVATE_CARPETEVOLUTIONMASK_STRUCT.enforce_vars
#endif
#ifndef CCTK_PARAMETER__CARPETEVOLUTIONMASK__enforce_mask
#  define CCTK_PARAMETER__CARPETEVOLUTIONMASK__enforce_mask PRIVATE_CARPETEVOLUTIONMASK_STRUCT.enforce_mask
#endif
#ifndef CCTK_PARAMETER__CARPETEVOLUTIONMASK__enlarge_evolved_region_by
#  define CCTK_PARAMETER__CARPETEVOLUTIONMASK__enlarge_evolved_region_by PRIVATE_CARPETEVOLUTIONMASK_STRUCT.enlarge_evolved_region_by
#endif
#ifndef CCTK_PARAMETER__CARPETEVOLUTIONMASK__provide_buffer_mask
#  define CCTK_PARAMETER__CARPETEVOLUTIONMASK__provide_buffer_mask PRIVATE_CARPETEVOLUTIONMASK_STRUCT.provide_buffer_mask
#endif
#ifndef CCTK_PARAMETER__CARPETEVOLUTIONMASK__verbose
#  define CCTK_PARAMETER__CARPETEVOLUTIONMASK__verbose PRIVATE_CARPETEVOLUTIONMASK_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__CARPETEVOLUTIONMASK__writeNaNs
#  define CCTK_PARAMETER__CARPETEVOLUTIONMASK__writeNaNs PRIVATE_CARPETEVOLUTIONMASK_STRUCT.writeNaNs
#endif

