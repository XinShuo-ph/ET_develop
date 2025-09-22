#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * out_vars;
  CCTK_INT out_every;
  CCTK_INT point_x;
  CCTK_INT point_y;
  CCTK_INT point_z;
} PRIVATE_SAMPLEIO_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_SAMPLEIO_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, out_vars, CCTK_PARAMETER__SAMPLEIO__out_vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_every, CCTK_PARAMETER__SAMPLEIO__out_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, point_x, CCTK_PARAMETER__SAMPLEIO__point_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, point_y, CCTK_PARAMETER__SAMPLEIO__point_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, point_z, CCTK_PARAMETER__SAMPLEIO__point_z); \


#ifndef CCTK_PARAMETER__SAMPLEIO__out_vars
#  define CCTK_PARAMETER__SAMPLEIO__out_vars PRIVATE_SAMPLEIO_STRUCT.out_vars
#endif
#ifndef CCTK_PARAMETER__SAMPLEIO__out_every
#  define CCTK_PARAMETER__SAMPLEIO__out_every PRIVATE_SAMPLEIO_STRUCT.out_every
#endif
#ifndef CCTK_PARAMETER__SAMPLEIO__point_x
#  define CCTK_PARAMETER__SAMPLEIO__point_x PRIVATE_SAMPLEIO_STRUCT.point_x
#endif
#ifndef CCTK_PARAMETER__SAMPLEIO__point_y
#  define CCTK_PARAMETER__SAMPLEIO__point_y PRIVATE_SAMPLEIO_STRUCT.point_y
#endif
#ifndef CCTK_PARAMETER__SAMPLEIO__point_z
#  define CCTK_PARAMETER__SAMPLEIO__point_z PRIVATE_SAMPLEIO_STRUCT.point_z
#endif

