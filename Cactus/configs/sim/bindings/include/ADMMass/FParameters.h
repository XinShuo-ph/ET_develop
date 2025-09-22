#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,ADMMass_distance_from_grid_boundary,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_surface_distance,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_volume_radius,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_x_max,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_x_min,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_x_pos,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_y_max,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_y_min,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_y_pos,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_z_max,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_z_min,(100))&&\
CCTK_DECLARE(CCTK_REAL,ADMMass_z_pos,(100))&&\
CCTK_DECLARE(CCTK_INT,ADMMass_Debug,)&&\
CCTK_DECLARE(CCTK_INT,ADMMass_Excise_Horizons,)&&\
CCTK_DECLARE(CCTK_INT,ADMMass_number,)&&\
CCTK_DECLARE(CCTK_INT,ADMMass_use_all_volume_as_volume_radius,)&&\
CCTK_DECLARE(CCTK_INT,ADMMass_use_surface_distance_as_volume_radius,)&&\
COMMON /ADMMasspriv/ADMMass_distance_from_grid_boundary, ADMMass_surface_distance, ADMMass_volume_radius, ADMMass_x_max, ADMMass_x_min, ADMMass_x_pos, ADMMass_y_max, ADMMass_y_min, ADMMass_y_pos, ADMMass_z_max, ADMMass_z_min, ADMMass_z_pos, ADMMass_Debug, ADMMass_Excise_Horizons, ADMMass_number, ADMMass_use_all_volume_as_volume_radius, ADMMass_use_surface_distance_as_volume_radius&&\

