#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT timer_output;
  CCTK_INT use_alltoallv;
} PRIVATE_SLAB_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_SLAB_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, timer_output, CCTK_PARAMETER__SLAB__timer_output); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_alltoallv, CCTK_PARAMETER__SLAB__use_alltoallv); \


#ifndef CCTK_PARAMETER__SLAB__timer_output
#  define CCTK_PARAMETER__SLAB__timer_output PRIVATE_SLAB_STRUCT.timer_output
#endif
#ifndef CCTK_PARAMETER__SLAB__use_alltoallv
#  define CCTK_PARAMETER__SLAB__use_alltoallv PRIVATE_SLAB_STRUCT.use_alltoallv
#endif

