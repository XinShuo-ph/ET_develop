#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL excluded_centre_x[10];
  CCTK_REAL excluded_centre_y[10];
  CCTK_REAL excluded_centre_z[10];
  CCTK_REAL excluded_radius[10];
  CCTK_REAL excluded_surface_factor[10];
  CCTK_INT exclude_exterior[10];
  CCTK_INT excluded_surface[10];
  CCTK_INT verbose;
} PRIVATE_CARPETMASK_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETMASK_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, excluded_centre_x, CCTK_PARAMETER__CARPETMASK__excluded_centre_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, excluded_centre_y, CCTK_PARAMETER__CARPETMASK__excluded_centre_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, excluded_centre_z, CCTK_PARAMETER__CARPETMASK__excluded_centre_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, excluded_radius, CCTK_PARAMETER__CARPETMASK__excluded_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, excluded_surface_factor, CCTK_PARAMETER__CARPETMASK__excluded_surface_factor); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, exclude_exterior, CCTK_PARAMETER__CARPETMASK__exclude_exterior); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, excluded_surface, CCTK_PARAMETER__CARPETMASK__excluded_surface); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARPETMASK__verbose); \


#ifndef CCTK_PARAMETER__CARPETMASK__excluded_centre_x
#  define CCTK_PARAMETER__CARPETMASK__excluded_centre_x PRIVATE_CARPETMASK_STRUCT.excluded_centre_x
#endif
#ifndef CCTK_PARAMETER__CARPETMASK__excluded_centre_y
#  define CCTK_PARAMETER__CARPETMASK__excluded_centre_y PRIVATE_CARPETMASK_STRUCT.excluded_centre_y
#endif
#ifndef CCTK_PARAMETER__CARPETMASK__excluded_centre_z
#  define CCTK_PARAMETER__CARPETMASK__excluded_centre_z PRIVATE_CARPETMASK_STRUCT.excluded_centre_z
#endif
#ifndef CCTK_PARAMETER__CARPETMASK__excluded_radius
#  define CCTK_PARAMETER__CARPETMASK__excluded_radius PRIVATE_CARPETMASK_STRUCT.excluded_radius
#endif
#ifndef CCTK_PARAMETER__CARPETMASK__excluded_surface_factor
#  define CCTK_PARAMETER__CARPETMASK__excluded_surface_factor PRIVATE_CARPETMASK_STRUCT.excluded_surface_factor
#endif
#ifndef CCTK_PARAMETER__CARPETMASK__exclude_exterior
#  define CCTK_PARAMETER__CARPETMASK__exclude_exterior PRIVATE_CARPETMASK_STRUCT.exclude_exterior
#endif
#ifndef CCTK_PARAMETER__CARPETMASK__excluded_surface
#  define CCTK_PARAMETER__CARPETMASK__excluded_surface PRIVATE_CARPETMASK_STRUCT.excluded_surface
#endif
#ifndef CCTK_PARAMETER__CARPETMASK__verbose
#  define CCTK_PARAMETER__CARPETMASK__verbose PRIVATE_CARPETMASK_STRUCT.verbose
#endif

