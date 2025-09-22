#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Minkowski_scale[10];
  CCTK_REAL centre_x[10];
  CCTK_REAL centre_y[10];
  CCTK_REAL centre_z[10];
  CCTK_REAL lapse_scale[10];
  CCTK_REAL radius[10];
  CCTK_REAL radius_x[10];
  CCTK_REAL radius_y[10];
  CCTK_REAL radius_z[10];
  CCTK_REAL reduction_factor[10];
  CCTK_REAL smoothing_eps;
  CCTK_REAL smoothing_factor;
  CCTK_REAL smoothing_zone_width[10];
  const char * method;
  const char * region_shape[10];
  const char * smoothing_function[10];
  CCTK_INT num_regions;
  CCTK_INT overwrite_geometry[10];
  CCTK_INT overwrite_lapse[10];
  CCTK_INT overwrite_shift[10];
  CCTK_INT reduce_rhs[10];
  CCTK_INT smooth_regions;
  CCTK_INT smoothing_iterations;
  CCTK_INT smoothing_order;
  CCTK_INT surface_index[10];
  CCTK_INT use_user_regions;
  CCTK_INT verbose;
} PRIVATE_NOEXCISION_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NOEXCISION_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, Minkowski_scale, CCTK_PARAMETER__NOEXCISION__Minkowski_scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, centre_x, CCTK_PARAMETER__NOEXCISION__centre_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, centre_y, CCTK_PARAMETER__NOEXCISION__centre_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, centre_z, CCTK_PARAMETER__NOEXCISION__centre_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, lapse_scale, CCTK_PARAMETER__NOEXCISION__lapse_scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius, CCTK_PARAMETER__NOEXCISION__radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x, CCTK_PARAMETER__NOEXCISION__radius_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y, CCTK_PARAMETER__NOEXCISION__radius_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z, CCTK_PARAMETER__NOEXCISION__radius_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, reduction_factor, CCTK_PARAMETER__NOEXCISION__reduction_factor); \
  CCTK_DECLARE_INIT (CCTK_REAL const, smoothing_eps, CCTK_PARAMETER__NOEXCISION__smoothing_eps); \
  CCTK_DECLARE_INIT (CCTK_REAL const, smoothing_factor, CCTK_PARAMETER__NOEXCISION__smoothing_factor); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, smoothing_zone_width, CCTK_PARAMETER__NOEXCISION__smoothing_zone_width); \
  CCTK_DECLARE_INIT (const char * const, method, CCTK_PARAMETER__NOEXCISION__method); \
  CCTK_DECLARE_INIT (const char * const * const, region_shape, CCTK_PARAMETER__NOEXCISION__region_shape); \
  CCTK_DECLARE_INIT (const char * const * const, smoothing_function, CCTK_PARAMETER__NOEXCISION__smoothing_function); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_regions, CCTK_PARAMETER__NOEXCISION__num_regions); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, overwrite_geometry, CCTK_PARAMETER__NOEXCISION__overwrite_geometry); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, overwrite_lapse, CCTK_PARAMETER__NOEXCISION__overwrite_lapse); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, overwrite_shift, CCTK_PARAMETER__NOEXCISION__overwrite_shift); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, reduce_rhs, CCTK_PARAMETER__NOEXCISION__reduce_rhs); \
  CCTK_DECLARE_INIT (CCTK_INT const, smooth_regions, CCTK_PARAMETER__NOEXCISION__smooth_regions); \
  CCTK_DECLARE_INIT (CCTK_INT const, smoothing_iterations, CCTK_PARAMETER__NOEXCISION__smoothing_iterations); \
  CCTK_DECLARE_INIT (CCTK_INT const, smoothing_order, CCTK_PARAMETER__NOEXCISION__smoothing_order); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, surface_index, CCTK_PARAMETER__NOEXCISION__surface_index); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_user_regions, CCTK_PARAMETER__NOEXCISION__use_user_regions); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__NOEXCISION__verbose); \


#ifndef CCTK_PARAMETER__NOEXCISION__Minkowski_scale
#  define CCTK_PARAMETER__NOEXCISION__Minkowski_scale PRIVATE_NOEXCISION_STRUCT.Minkowski_scale
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__centre_x
#  define CCTK_PARAMETER__NOEXCISION__centre_x PRIVATE_NOEXCISION_STRUCT.centre_x
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__centre_y
#  define CCTK_PARAMETER__NOEXCISION__centre_y PRIVATE_NOEXCISION_STRUCT.centre_y
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__centre_z
#  define CCTK_PARAMETER__NOEXCISION__centre_z PRIVATE_NOEXCISION_STRUCT.centre_z
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__lapse_scale
#  define CCTK_PARAMETER__NOEXCISION__lapse_scale PRIVATE_NOEXCISION_STRUCT.lapse_scale
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__radius
#  define CCTK_PARAMETER__NOEXCISION__radius PRIVATE_NOEXCISION_STRUCT.radius
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__radius_x
#  define CCTK_PARAMETER__NOEXCISION__radius_x PRIVATE_NOEXCISION_STRUCT.radius_x
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__radius_y
#  define CCTK_PARAMETER__NOEXCISION__radius_y PRIVATE_NOEXCISION_STRUCT.radius_y
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__radius_z
#  define CCTK_PARAMETER__NOEXCISION__radius_z PRIVATE_NOEXCISION_STRUCT.radius_z
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__reduction_factor
#  define CCTK_PARAMETER__NOEXCISION__reduction_factor PRIVATE_NOEXCISION_STRUCT.reduction_factor
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__smoothing_eps
#  define CCTK_PARAMETER__NOEXCISION__smoothing_eps PRIVATE_NOEXCISION_STRUCT.smoothing_eps
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__smoothing_factor
#  define CCTK_PARAMETER__NOEXCISION__smoothing_factor PRIVATE_NOEXCISION_STRUCT.smoothing_factor
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__smoothing_zone_width
#  define CCTK_PARAMETER__NOEXCISION__smoothing_zone_width PRIVATE_NOEXCISION_STRUCT.smoothing_zone_width
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__method
#  define CCTK_PARAMETER__NOEXCISION__method PRIVATE_NOEXCISION_STRUCT.method
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__region_shape
#  define CCTK_PARAMETER__NOEXCISION__region_shape PRIVATE_NOEXCISION_STRUCT.region_shape
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__smoothing_function
#  define CCTK_PARAMETER__NOEXCISION__smoothing_function PRIVATE_NOEXCISION_STRUCT.smoothing_function
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__num_regions
#  define CCTK_PARAMETER__NOEXCISION__num_regions PRIVATE_NOEXCISION_STRUCT.num_regions
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__overwrite_geometry
#  define CCTK_PARAMETER__NOEXCISION__overwrite_geometry PRIVATE_NOEXCISION_STRUCT.overwrite_geometry
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__overwrite_lapse
#  define CCTK_PARAMETER__NOEXCISION__overwrite_lapse PRIVATE_NOEXCISION_STRUCT.overwrite_lapse
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__overwrite_shift
#  define CCTK_PARAMETER__NOEXCISION__overwrite_shift PRIVATE_NOEXCISION_STRUCT.overwrite_shift
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__reduce_rhs
#  define CCTK_PARAMETER__NOEXCISION__reduce_rhs PRIVATE_NOEXCISION_STRUCT.reduce_rhs
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__smooth_regions
#  define CCTK_PARAMETER__NOEXCISION__smooth_regions PRIVATE_NOEXCISION_STRUCT.smooth_regions
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__smoothing_iterations
#  define CCTK_PARAMETER__NOEXCISION__smoothing_iterations PRIVATE_NOEXCISION_STRUCT.smoothing_iterations
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__smoothing_order
#  define CCTK_PARAMETER__NOEXCISION__smoothing_order PRIVATE_NOEXCISION_STRUCT.smoothing_order
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__surface_index
#  define CCTK_PARAMETER__NOEXCISION__surface_index PRIVATE_NOEXCISION_STRUCT.surface_index
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__use_user_regions
#  define CCTK_PARAMETER__NOEXCISION__use_user_regions PRIVATE_NOEXCISION_STRUCT.use_user_regions
#endif
#ifndef CCTK_PARAMETER__NOEXCISION__verbose
#  define CCTK_PARAMETER__NOEXCISION__verbose PRIVATE_NOEXCISION_STRUCT.verbose
#endif

