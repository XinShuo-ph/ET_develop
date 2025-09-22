#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL outScalar_dt;
  const char * outScalar_criterion;
  const char * outScalar_dir;
  const char * outScalar_reductions;
  const char * outScalar_vars;
  CCTK_INT all_reductions_in_one_file;
  CCTK_INT one_file_per_group;
  CCTK_INT outScalar_every;
  CCTK_INT out_precision;
} PRIVATE_CARPETIOSCALAR_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETIOSCALAR_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, outScalar_dt, CCTK_PARAMETER__CARPETIOSCALAR__outScalar_dt); \
  CCTK_DECLARE_INIT (const char * const, outScalar_criterion, CCTK_PARAMETER__CARPETIOSCALAR__outScalar_criterion); \
  CCTK_DECLARE_INIT (const char * const, outScalar_dir, CCTK_PARAMETER__CARPETIOSCALAR__outScalar_dir); \
  CCTK_DECLARE_INIT (const char * const, outScalar_reductions, CCTK_PARAMETER__CARPETIOSCALAR__outScalar_reductions); \
  CCTK_DECLARE_INIT (const char * const, outScalar_vars, CCTK_PARAMETER__CARPETIOSCALAR__outScalar_vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, all_reductions_in_one_file, CCTK_PARAMETER__CARPETIOSCALAR__all_reductions_in_one_file); \
  CCTK_DECLARE_INIT (CCTK_INT const, one_file_per_group, CCTK_PARAMETER__CARPETIOSCALAR__one_file_per_group); \
  CCTK_DECLARE_INIT (CCTK_INT const, outScalar_every, CCTK_PARAMETER__CARPETIOSCALAR__outScalar_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_precision, CCTK_PARAMETER__CARPETIOSCALAR__out_precision); \


#ifndef CCTK_PARAMETER__CARPETIOSCALAR__outScalar_dt
#  define CCTK_PARAMETER__CARPETIOSCALAR__outScalar_dt PRIVATE_CARPETIOSCALAR_STRUCT.outScalar_dt
#endif
#ifndef CCTK_PARAMETER__CARPETIOSCALAR__outScalar_criterion
#  define CCTK_PARAMETER__CARPETIOSCALAR__outScalar_criterion PRIVATE_CARPETIOSCALAR_STRUCT.outScalar_criterion
#endif
#ifndef CCTK_PARAMETER__CARPETIOSCALAR__outScalar_dir
#  define CCTK_PARAMETER__CARPETIOSCALAR__outScalar_dir PRIVATE_CARPETIOSCALAR_STRUCT.outScalar_dir
#endif
#ifndef CCTK_PARAMETER__CARPETIOSCALAR__outScalar_reductions
#  define CCTK_PARAMETER__CARPETIOSCALAR__outScalar_reductions PRIVATE_CARPETIOSCALAR_STRUCT.outScalar_reductions
#endif
#ifndef CCTK_PARAMETER__CARPETIOSCALAR__outScalar_vars
#  define CCTK_PARAMETER__CARPETIOSCALAR__outScalar_vars PRIVATE_CARPETIOSCALAR_STRUCT.outScalar_vars
#endif
#ifndef CCTK_PARAMETER__CARPETIOSCALAR__all_reductions_in_one_file
#  define CCTK_PARAMETER__CARPETIOSCALAR__all_reductions_in_one_file PRIVATE_CARPETIOSCALAR_STRUCT.all_reductions_in_one_file
#endif
#ifndef CCTK_PARAMETER__CARPETIOSCALAR__one_file_per_group
#  define CCTK_PARAMETER__CARPETIOSCALAR__one_file_per_group PRIVATE_CARPETIOSCALAR_STRUCT.one_file_per_group
#endif
#ifndef CCTK_PARAMETER__CARPETIOSCALAR__outScalar_every
#  define CCTK_PARAMETER__CARPETIOSCALAR__outScalar_every PRIVATE_CARPETIOSCALAR_STRUCT.outScalar_every
#endif
#ifndef CCTK_PARAMETER__CARPETIOSCALAR__out_precision
#  define CCTK_PARAMETER__CARPETIOSCALAR__out_precision PRIVATE_CARPETIOSCALAR_STRUCT.out_precision
#endif

