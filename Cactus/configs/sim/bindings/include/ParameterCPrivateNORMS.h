#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * gridfunctions_1st;
  const char * gridfunctions_2nd;
  CCTK_INT max_nr_vars;
  CCTK_INT verbose;
} PRIVATE_NORMS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NORMS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, gridfunctions_1st, CCTK_PARAMETER__NORMS__gridfunctions_1st); \
  CCTK_DECLARE_INIT (const char * const, gridfunctions_2nd, CCTK_PARAMETER__NORMS__gridfunctions_2nd); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_nr_vars, CCTK_PARAMETER__NORMS__max_nr_vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__NORMS__verbose); \


#ifndef CCTK_PARAMETER__NORMS__gridfunctions_1st
#  define CCTK_PARAMETER__NORMS__gridfunctions_1st PRIVATE_NORMS_STRUCT.gridfunctions_1st
#endif
#ifndef CCTK_PARAMETER__NORMS__gridfunctions_2nd
#  define CCTK_PARAMETER__NORMS__gridfunctions_2nd PRIVATE_NORMS_STRUCT.gridfunctions_2nd
#endif
#ifndef CCTK_PARAMETER__NORMS__max_nr_vars
#  define CCTK_PARAMETER__NORMS__max_nr_vars PRIVATE_NORMS_STRUCT.max_nr_vars
#endif
#ifndef CCTK_PARAMETER__NORMS__verbose
#  define CCTK_PARAMETER__NORMS__verbose PRIVATE_NORMS_STRUCT.verbose
#endif

