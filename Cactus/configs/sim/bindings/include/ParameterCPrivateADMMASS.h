#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL ADMMass_distance_from_grid_boundary[100];
  CCTK_REAL ADMMass_surface_distance[100];
  CCTK_REAL ADMMass_volume_radius[100];
  CCTK_REAL ADMMass_x_max[100];
  CCTK_REAL ADMMass_x_min[100];
  CCTK_REAL ADMMass_x_pos[100];
  CCTK_REAL ADMMass_y_max[100];
  CCTK_REAL ADMMass_y_min[100];
  CCTK_REAL ADMMass_y_pos[100];
  CCTK_REAL ADMMass_z_max[100];
  CCTK_REAL ADMMass_z_min[100];
  CCTK_REAL ADMMass_z_pos[100];
  CCTK_INT ADMMass_Debug;
  CCTK_INT ADMMass_Excise_Horizons;
  CCTK_INT ADMMass_number;
  CCTK_INT ADMMass_use_all_volume_as_volume_radius;
  CCTK_INT ADMMass_use_surface_distance_as_volume_radius;
} PRIVATE_ADMMASS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_ADMMASS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_distance_from_grid_boundary, CCTK_PARAMETER__ADMMASS__ADMMass_distance_from_grid_boundary); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_surface_distance, CCTK_PARAMETER__ADMMASS__ADMMass_surface_distance); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_volume_radius, CCTK_PARAMETER__ADMMASS__ADMMass_volume_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_x_max, CCTK_PARAMETER__ADMMASS__ADMMass_x_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_x_min, CCTK_PARAMETER__ADMMASS__ADMMass_x_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_x_pos, CCTK_PARAMETER__ADMMASS__ADMMass_x_pos); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_y_max, CCTK_PARAMETER__ADMMASS__ADMMass_y_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_y_min, CCTK_PARAMETER__ADMMASS__ADMMass_y_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_y_pos, CCTK_PARAMETER__ADMMASS__ADMMass_y_pos); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_z_max, CCTK_PARAMETER__ADMMASS__ADMMass_z_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_z_min, CCTK_PARAMETER__ADMMASS__ADMMass_z_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, ADMMass_z_pos, CCTK_PARAMETER__ADMMASS__ADMMass_z_pos); \
  CCTK_DECLARE_INIT (CCTK_INT const, ADMMass_Debug, CCTK_PARAMETER__ADMMASS__ADMMass_Debug); \
  CCTK_DECLARE_INIT (CCTK_INT const, ADMMass_Excise_Horizons, CCTK_PARAMETER__ADMMASS__ADMMass_Excise_Horizons); \
  CCTK_DECLARE_INIT (CCTK_INT const, ADMMass_number, CCTK_PARAMETER__ADMMASS__ADMMass_number); \
  CCTK_DECLARE_INIT (CCTK_INT const, ADMMass_use_all_volume_as_volume_radius, CCTK_PARAMETER__ADMMASS__ADMMass_use_all_volume_as_volume_radius); \
  CCTK_DECLARE_INIT (CCTK_INT const, ADMMass_use_surface_distance_as_volume_radius, CCTK_PARAMETER__ADMMASS__ADMMass_use_surface_distance_as_volume_radius); \


#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_distance_from_grid_boundary
#  define CCTK_PARAMETER__ADMMASS__ADMMass_distance_from_grid_boundary PRIVATE_ADMMASS_STRUCT.ADMMass_distance_from_grid_boundary
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_surface_distance
#  define CCTK_PARAMETER__ADMMASS__ADMMass_surface_distance PRIVATE_ADMMASS_STRUCT.ADMMass_surface_distance
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_volume_radius
#  define CCTK_PARAMETER__ADMMASS__ADMMass_volume_radius PRIVATE_ADMMASS_STRUCT.ADMMass_volume_radius
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_x_max
#  define CCTK_PARAMETER__ADMMASS__ADMMass_x_max PRIVATE_ADMMASS_STRUCT.ADMMass_x_max
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_x_min
#  define CCTK_PARAMETER__ADMMASS__ADMMass_x_min PRIVATE_ADMMASS_STRUCT.ADMMass_x_min
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_x_pos
#  define CCTK_PARAMETER__ADMMASS__ADMMass_x_pos PRIVATE_ADMMASS_STRUCT.ADMMass_x_pos
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_y_max
#  define CCTK_PARAMETER__ADMMASS__ADMMass_y_max PRIVATE_ADMMASS_STRUCT.ADMMass_y_max
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_y_min
#  define CCTK_PARAMETER__ADMMASS__ADMMass_y_min PRIVATE_ADMMASS_STRUCT.ADMMass_y_min
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_y_pos
#  define CCTK_PARAMETER__ADMMASS__ADMMass_y_pos PRIVATE_ADMMASS_STRUCT.ADMMass_y_pos
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_z_max
#  define CCTK_PARAMETER__ADMMASS__ADMMass_z_max PRIVATE_ADMMASS_STRUCT.ADMMass_z_max
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_z_min
#  define CCTK_PARAMETER__ADMMASS__ADMMass_z_min PRIVATE_ADMMASS_STRUCT.ADMMass_z_min
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_z_pos
#  define CCTK_PARAMETER__ADMMASS__ADMMass_z_pos PRIVATE_ADMMASS_STRUCT.ADMMass_z_pos
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_Debug
#  define CCTK_PARAMETER__ADMMASS__ADMMass_Debug PRIVATE_ADMMASS_STRUCT.ADMMass_Debug
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_Excise_Horizons
#  define CCTK_PARAMETER__ADMMASS__ADMMass_Excise_Horizons PRIVATE_ADMMASS_STRUCT.ADMMass_Excise_Horizons
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_number
#  define CCTK_PARAMETER__ADMMASS__ADMMass_number PRIVATE_ADMMASS_STRUCT.ADMMass_number
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_use_all_volume_as_volume_radius
#  define CCTK_PARAMETER__ADMMASS__ADMMass_use_all_volume_as_volume_radius PRIVATE_ADMMASS_STRUCT.ADMMass_use_all_volume_as_volume_radius
#endif
#ifndef CCTK_PARAMETER__ADMMASS__ADMMass_use_surface_distance_as_volume_radius
#  define CCTK_PARAMETER__ADMMASS__ADMMass_use_surface_distance_as_volume_radius PRIVATE_ADMMASS_STRUCT.ADMMass_use_surface_distance_as_volume_radius
#endif

