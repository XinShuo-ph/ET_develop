#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL array2d_dx_i;
  CCTK_REAL array2d_dx_j;
  CCTK_REAL array2d_dy_i;
  CCTK_REAL array2d_dy_j;
  CCTK_REAL array2d_dz_i;
  CCTK_REAL array2d_dz_j;
  CCTK_REAL array2d_x0;
  CCTK_REAL array2d_y0;
  CCTK_REAL array2d_z0;
  CCTK_REAL colormap_bias;
  CCTK_REAL colormap_max;
  CCTK_REAL colormap_min;
  CCTK_REAL out2D_xyplane_z;
  CCTK_REAL out2D_xzplane_y;
  CCTK_REAL out2D_yzplane_x;
  const char * colormap;
  const char * gridpoints;
  const char * interpolator_coordinates;
  const char * interpolator_name;
  const char * interpolator_options;
  const char * mode;
  const char * out_dir;
  const char * out_vars;
  CCTK_INT array2d_npoints_i;
  CCTK_INT array2d_npoints_j;
  CCTK_INT colormap_factor;
  CCTK_INT colormap_quality;
  CCTK_INT multiply_by_radius;
  CCTK_INT out2D_xyplane_zi;
  CCTK_INT out2D_xzplane_yi;
  CCTK_INT out2D_yzplane_xi;
  CCTK_INT out_every;
  CCTK_INT refinement_factor;
} PRIVATE_IOJPEG_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_IOJPEG_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dx_i, CCTK_PARAMETER__IOJPEG__array2d_dx_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dx_j, CCTK_PARAMETER__IOJPEG__array2d_dx_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dy_i, CCTK_PARAMETER__IOJPEG__array2d_dy_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dy_j, CCTK_PARAMETER__IOJPEG__array2d_dy_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dz_i, CCTK_PARAMETER__IOJPEG__array2d_dz_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dz_j, CCTK_PARAMETER__IOJPEG__array2d_dz_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_x0, CCTK_PARAMETER__IOJPEG__array2d_x0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_y0, CCTK_PARAMETER__IOJPEG__array2d_y0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_z0, CCTK_PARAMETER__IOJPEG__array2d_z0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, colormap_bias, CCTK_PARAMETER__IOJPEG__colormap_bias); \
  CCTK_DECLARE_INIT (CCTK_REAL const, colormap_max, CCTK_PARAMETER__IOJPEG__colormap_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const, colormap_min, CCTK_PARAMETER__IOJPEG__colormap_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out2D_xyplane_z, CCTK_PARAMETER__IOJPEG__out2D_xyplane_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out2D_xzplane_y, CCTK_PARAMETER__IOJPEG__out2D_xzplane_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out2D_yzplane_x, CCTK_PARAMETER__IOJPEG__out2D_yzplane_x); \
  CCTK_DECLARE_INIT (const char * const, colormap, CCTK_PARAMETER__IOJPEG__colormap); \
  CCTK_DECLARE_INIT (const char * const, gridpoints, CCTK_PARAMETER__IOJPEG__gridpoints); \
  CCTK_DECLARE_INIT (const char * const, interpolator_coordinates, CCTK_PARAMETER__IOJPEG__interpolator_coordinates); \
  CCTK_DECLARE_INIT (const char * const, interpolator_name, CCTK_PARAMETER__IOJPEG__interpolator_name); \
  CCTK_DECLARE_INIT (const char * const, interpolator_options, CCTK_PARAMETER__IOJPEG__interpolator_options); \
  CCTK_DECLARE_INIT (const char * const, mode, CCTK_PARAMETER__IOJPEG__mode); \
  CCTK_DECLARE_INIT (const char * const, out_dir, CCTK_PARAMETER__IOJPEG__out_dir); \
  CCTK_DECLARE_INIT (const char * const, out_vars, CCTK_PARAMETER__IOJPEG__out_vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, array2d_npoints_i, CCTK_PARAMETER__IOJPEG__array2d_npoints_i); \
  CCTK_DECLARE_INIT (CCTK_INT const, array2d_npoints_j, CCTK_PARAMETER__IOJPEG__array2d_npoints_j); \
  CCTK_DECLARE_INIT (CCTK_INT const, colormap_factor, CCTK_PARAMETER__IOJPEG__colormap_factor); \
  CCTK_DECLARE_INIT (CCTK_INT const, colormap_quality, CCTK_PARAMETER__IOJPEG__colormap_quality); \
  CCTK_DECLARE_INIT (CCTK_INT const, multiply_by_radius, CCTK_PARAMETER__IOJPEG__multiply_by_radius); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_xyplane_zi, CCTK_PARAMETER__IOJPEG__out2D_xyplane_zi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_xzplane_yi, CCTK_PARAMETER__IOJPEG__out2D_xzplane_yi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_yzplane_xi, CCTK_PARAMETER__IOJPEG__out2D_yzplane_xi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_every, CCTK_PARAMETER__IOJPEG__out_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, refinement_factor, CCTK_PARAMETER__IOJPEG__refinement_factor); \


#ifndef CCTK_PARAMETER__IOJPEG__array2d_dx_i
#  define CCTK_PARAMETER__IOJPEG__array2d_dx_i PRIVATE_IOJPEG_STRUCT.array2d_dx_i
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_dx_j
#  define CCTK_PARAMETER__IOJPEG__array2d_dx_j PRIVATE_IOJPEG_STRUCT.array2d_dx_j
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_dy_i
#  define CCTK_PARAMETER__IOJPEG__array2d_dy_i PRIVATE_IOJPEG_STRUCT.array2d_dy_i
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_dy_j
#  define CCTK_PARAMETER__IOJPEG__array2d_dy_j PRIVATE_IOJPEG_STRUCT.array2d_dy_j
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_dz_i
#  define CCTK_PARAMETER__IOJPEG__array2d_dz_i PRIVATE_IOJPEG_STRUCT.array2d_dz_i
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_dz_j
#  define CCTK_PARAMETER__IOJPEG__array2d_dz_j PRIVATE_IOJPEG_STRUCT.array2d_dz_j
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_x0
#  define CCTK_PARAMETER__IOJPEG__array2d_x0 PRIVATE_IOJPEG_STRUCT.array2d_x0
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_y0
#  define CCTK_PARAMETER__IOJPEG__array2d_y0 PRIVATE_IOJPEG_STRUCT.array2d_y0
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_z0
#  define CCTK_PARAMETER__IOJPEG__array2d_z0 PRIVATE_IOJPEG_STRUCT.array2d_z0
#endif
#ifndef CCTK_PARAMETER__IOJPEG__colormap_bias
#  define CCTK_PARAMETER__IOJPEG__colormap_bias PRIVATE_IOJPEG_STRUCT.colormap_bias
#endif
#ifndef CCTK_PARAMETER__IOJPEG__colormap_max
#  define CCTK_PARAMETER__IOJPEG__colormap_max PRIVATE_IOJPEG_STRUCT.colormap_max
#endif
#ifndef CCTK_PARAMETER__IOJPEG__colormap_min
#  define CCTK_PARAMETER__IOJPEG__colormap_min PRIVATE_IOJPEG_STRUCT.colormap_min
#endif
#ifndef CCTK_PARAMETER__IOJPEG__out2D_xyplane_z
#  define CCTK_PARAMETER__IOJPEG__out2D_xyplane_z PRIVATE_IOJPEG_STRUCT.out2D_xyplane_z
#endif
#ifndef CCTK_PARAMETER__IOJPEG__out2D_xzplane_y
#  define CCTK_PARAMETER__IOJPEG__out2D_xzplane_y PRIVATE_IOJPEG_STRUCT.out2D_xzplane_y
#endif
#ifndef CCTK_PARAMETER__IOJPEG__out2D_yzplane_x
#  define CCTK_PARAMETER__IOJPEG__out2D_yzplane_x PRIVATE_IOJPEG_STRUCT.out2D_yzplane_x
#endif
#ifndef CCTK_PARAMETER__IOJPEG__colormap
#  define CCTK_PARAMETER__IOJPEG__colormap PRIVATE_IOJPEG_STRUCT.colormap
#endif
#ifndef CCTK_PARAMETER__IOJPEG__gridpoints
#  define CCTK_PARAMETER__IOJPEG__gridpoints PRIVATE_IOJPEG_STRUCT.gridpoints
#endif
#ifndef CCTK_PARAMETER__IOJPEG__interpolator_coordinates
#  define CCTK_PARAMETER__IOJPEG__interpolator_coordinates PRIVATE_IOJPEG_STRUCT.interpolator_coordinates
#endif
#ifndef CCTK_PARAMETER__IOJPEG__interpolator_name
#  define CCTK_PARAMETER__IOJPEG__interpolator_name PRIVATE_IOJPEG_STRUCT.interpolator_name
#endif
#ifndef CCTK_PARAMETER__IOJPEG__interpolator_options
#  define CCTK_PARAMETER__IOJPEG__interpolator_options PRIVATE_IOJPEG_STRUCT.interpolator_options
#endif
#ifndef CCTK_PARAMETER__IOJPEG__mode
#  define CCTK_PARAMETER__IOJPEG__mode PRIVATE_IOJPEG_STRUCT.mode
#endif
#ifndef CCTK_PARAMETER__IOJPEG__out_dir
#  define CCTK_PARAMETER__IOJPEG__out_dir PRIVATE_IOJPEG_STRUCT.out_dir
#endif
#ifndef CCTK_PARAMETER__IOJPEG__out_vars
#  define CCTK_PARAMETER__IOJPEG__out_vars PRIVATE_IOJPEG_STRUCT.out_vars
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_npoints_i
#  define CCTK_PARAMETER__IOJPEG__array2d_npoints_i PRIVATE_IOJPEG_STRUCT.array2d_npoints_i
#endif
#ifndef CCTK_PARAMETER__IOJPEG__array2d_npoints_j
#  define CCTK_PARAMETER__IOJPEG__array2d_npoints_j PRIVATE_IOJPEG_STRUCT.array2d_npoints_j
#endif
#ifndef CCTK_PARAMETER__IOJPEG__colormap_factor
#  define CCTK_PARAMETER__IOJPEG__colormap_factor PRIVATE_IOJPEG_STRUCT.colormap_factor
#endif
#ifndef CCTK_PARAMETER__IOJPEG__colormap_quality
#  define CCTK_PARAMETER__IOJPEG__colormap_quality PRIVATE_IOJPEG_STRUCT.colormap_quality
#endif
#ifndef CCTK_PARAMETER__IOJPEG__multiply_by_radius
#  define CCTK_PARAMETER__IOJPEG__multiply_by_radius PRIVATE_IOJPEG_STRUCT.multiply_by_radius
#endif
#ifndef CCTK_PARAMETER__IOJPEG__out2D_xyplane_zi
#  define CCTK_PARAMETER__IOJPEG__out2D_xyplane_zi PRIVATE_IOJPEG_STRUCT.out2D_xyplane_zi
#endif
#ifndef CCTK_PARAMETER__IOJPEG__out2D_xzplane_yi
#  define CCTK_PARAMETER__IOJPEG__out2D_xzplane_yi PRIVATE_IOJPEG_STRUCT.out2D_xzplane_yi
#endif
#ifndef CCTK_PARAMETER__IOJPEG__out2D_yzplane_xi
#  define CCTK_PARAMETER__IOJPEG__out2D_yzplane_xi PRIVATE_IOJPEG_STRUCT.out2D_yzplane_xi
#endif
#ifndef CCTK_PARAMETER__IOJPEG__out_every
#  define CCTK_PARAMETER__IOJPEG__out_every PRIVATE_IOJPEG_STRUCT.out_every
#endif
#ifndef CCTK_PARAMETER__IOJPEG__refinement_factor
#  define CCTK_PARAMETER__IOJPEG__refinement_factor PRIVATE_IOJPEG_STRUCT.refinement_factor
#endif

