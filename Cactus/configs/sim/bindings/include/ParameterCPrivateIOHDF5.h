#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * out_dir;
  const char * out_vars;
  CCTK_INT checkpoint;
  CCTK_INT checkpoint_next;
  CCTK_INT out_every;
} PRIVATE_IOHDF5_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_IOHDF5_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, out_dir, CCTK_PARAMETER__IOHDF5__out_dir); \
  CCTK_DECLARE_INIT (const char * const, out_vars, CCTK_PARAMETER__IOHDF5__out_vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, checkpoint, CCTK_PARAMETER__IOHDF5__checkpoint); \
  CCTK_DECLARE_INIT (CCTK_INT const, checkpoint_next, CCTK_PARAMETER__IOHDF5__checkpoint_next); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_every, CCTK_PARAMETER__IOHDF5__out_every); \


#ifndef CCTK_PARAMETER__IOHDF5__out_dir
#  define CCTK_PARAMETER__IOHDF5__out_dir PRIVATE_IOHDF5_STRUCT.out_dir
#endif
#ifndef CCTK_PARAMETER__IOHDF5__out_vars
#  define CCTK_PARAMETER__IOHDF5__out_vars PRIVATE_IOHDF5_STRUCT.out_vars
#endif
#ifndef CCTK_PARAMETER__IOHDF5__checkpoint
#  define CCTK_PARAMETER__IOHDF5__checkpoint PRIVATE_IOHDF5_STRUCT.checkpoint
#endif
#ifndef CCTK_PARAMETER__IOHDF5__checkpoint_next
#  define CCTK_PARAMETER__IOHDF5__checkpoint_next PRIVATE_IOHDF5_STRUCT.checkpoint_next
#endif
#ifndef CCTK_PARAMETER__IOHDF5__out_every
#  define CCTK_PARAMETER__IOHDF5__out_every PRIVATE_IOHDF5_STRUCT.out_every
#endif

