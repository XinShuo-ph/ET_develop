#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT avoid_origin_upper_x;
  CCTK_INT avoid_origin_upper_y;
  CCTK_INT avoid_origin_upper_z;
  CCTK_INT avoid_origin_x;
  CCTK_INT avoid_origin_y;
  CCTK_INT avoid_origin_z;
  CCTK_INT reflection_upper_x;
  CCTK_INT reflection_upper_y;
  CCTK_INT reflection_upper_z;
  CCTK_INT reflection_x;
  CCTK_INT reflection_y;
  CCTK_INT reflection_z;
  CCTK_INT verbose;
} PRIVATE_REFLECTIONSYMMETRY_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_REFLECTIONSYMMETRY_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, avoid_origin_upper_x, CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_upper_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, avoid_origin_upper_y, CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_upper_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, avoid_origin_upper_z, CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_upper_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, avoid_origin_x, CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, avoid_origin_y, CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, avoid_origin_z, CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, reflection_upper_x, CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_upper_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, reflection_upper_y, CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_upper_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, reflection_upper_z, CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_upper_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, reflection_x, CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, reflection_y, CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, reflection_z, CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__REFLECTIONSYMMETRY__verbose); \


#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_upper_x
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_upper_x PRIVATE_REFLECTIONSYMMETRY_STRUCT.avoid_origin_upper_x
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_upper_y
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_upper_y PRIVATE_REFLECTIONSYMMETRY_STRUCT.avoid_origin_upper_y
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_upper_z
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_upper_z PRIVATE_REFLECTIONSYMMETRY_STRUCT.avoid_origin_upper_z
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_x
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_x PRIVATE_REFLECTIONSYMMETRY_STRUCT.avoid_origin_x
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_y
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_y PRIVATE_REFLECTIONSYMMETRY_STRUCT.avoid_origin_y
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_z
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__avoid_origin_z PRIVATE_REFLECTIONSYMMETRY_STRUCT.avoid_origin_z
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_upper_x
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_upper_x PRIVATE_REFLECTIONSYMMETRY_STRUCT.reflection_upper_x
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_upper_y
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_upper_y PRIVATE_REFLECTIONSYMMETRY_STRUCT.reflection_upper_y
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_upper_z
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_upper_z PRIVATE_REFLECTIONSYMMETRY_STRUCT.reflection_upper_z
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_x
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_x PRIVATE_REFLECTIONSYMMETRY_STRUCT.reflection_x
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_y
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_y PRIVATE_REFLECTIONSYMMETRY_STRUCT.reflection_y
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_z
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__reflection_z PRIVATE_REFLECTIONSYMMETRY_STRUCT.reflection_z
#endif
#ifndef CCTK_PARAMETER__REFLECTIONSYMMETRY__verbose
#  define CCTK_PARAMETER__REFLECTIONSYMMETRY__verbose PRIVATE_REFLECTIONSYMMETRY_STRUCT.verbose
#endif

