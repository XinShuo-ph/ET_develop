#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,Minkowski_scale,(10))&&\
CCTK_DECLARE(CCTK_REAL,centre_x,(10))&&\
CCTK_DECLARE(CCTK_REAL,centre_y,(10))&&\
CCTK_DECLARE(CCTK_REAL,centre_z,(10))&&\
CCTK_DECLARE(CCTK_REAL,lapse_scale,(10))&&\
CCTK_DECLARE(CCTK_REAL,radius,(10))&&\
CCTK_DECLARE(CCTK_REAL,radius_x,(10))&&\
CCTK_DECLARE(CCTK_REAL,radius_y,(10))&&\
CCTK_DECLARE(CCTK_REAL,radius_z,(10))&&\
CCTK_DECLARE(CCTK_REAL,reduction_factor,(10))&&\
CCTK_DECLARE(CCTK_REAL,smoothing_eps,)&&\
CCTK_DECLARE(CCTK_REAL,smoothing_factor,)&&\
CCTK_DECLARE(CCTK_REAL,smoothing_zone_width,(10))&&\
CCTK_DECLARE(CCTK_STRING,method,)&&\
CCTK_DECLARE(CCTK_STRING,region_shape,(10))&&\
CCTK_DECLARE(CCTK_STRING,smoothing_function,(10))&&\
CCTK_DECLARE(CCTK_INT,num_regions,)&&\
CCTK_DECLARE(CCTK_INT,overwrite_geometry,(10))&&\
CCTK_DECLARE(CCTK_INT,overwrite_lapse,(10))&&\
CCTK_DECLARE(CCTK_INT,overwrite_shift,(10))&&\
CCTK_DECLARE(CCTK_INT,reduce_rhs,(10))&&\
CCTK_DECLARE(CCTK_INT,smooth_regions,)&&\
CCTK_DECLARE(CCTK_INT,smoothing_iterations,)&&\
CCTK_DECLARE(CCTK_INT,smoothing_order,)&&\
CCTK_DECLARE(CCTK_INT,surface_index,(10))&&\
CCTK_DECLARE(CCTK_INT,use_user_regions,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /NoExcisionpriv/Minkowski_scale, centre_x, centre_y, centre_z, lapse_scale, radius, radius_x, radius_y, radius_z, reduction_factor, smoothing_eps, smoothing_factor, smoothing_zone_width, method, region_shape, smoothing_function, num_regions, overwrite_geometry, overwrite_lapse, overwrite_shift, reduce_rhs, smooth_regions, smoothing_iterations, smoothing_order, surface_index, use_user_regions, verbose&&\

