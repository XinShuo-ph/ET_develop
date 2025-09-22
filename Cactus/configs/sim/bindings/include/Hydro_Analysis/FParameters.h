#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,Hydro_Analysis_core_rho_rel_min,)&&\
CCTK_DECLARE(CCTK_REAL,Hydro_Analysis_r_core,)&&\
CCTK_DECLARE(CCTK_STRING,Hydro_Analysis_interpolator_coordinates,)&&\
CCTK_DECLARE(CCTK_STRING,Hydro_Analysis_interpolator_name,)&&\
CCTK_DECLARE(CCTK_STRING,Hydro_Analysis_interpolator_options,)&&\
CCTK_DECLARE(CCTK_INT,Hydro_Analysis_average_multiple_maxima_locations,)&&\
CCTK_DECLARE(CCTK_INT,Hydro_Analysis_comp_core_rho_centroid,)&&\
CCTK_DECLARE(CCTK_INT,Hydro_Analysis_comp_rho_max,)&&\
CCTK_DECLARE(CCTK_INT,Hydro_Analysis_comp_rho_max_every,)&&\
CCTK_DECLARE(CCTK_INT,Hydro_Analysis_comp_rho_max_origin_distance,)&&\
CCTK_DECLARE(CCTK_INT,Hydro_Analysis_comp_vol_weighted_center_of_mass,)&&\
CCTK_DECLARE(CCTK_INT,Hydro_Analysis_rho_max_loc_only_positive_x,)&&\
CCTK_DECLARE(CCTK_INT,Hydro_Analysis_rho_max_loc_use_rotatingsymmetry180,)&&\
CCTK_DECLARE(CCTK_INT,Hydro_Analysis_rho_max_origin_distance_npoints,)&&\
CCTK_DECLARE(CCTK_INT,verbosity_level,)&&\
COMMON /Hydro_Analysispriv/Hydro_Analysis_core_rho_rel_min, Hydro_Analysis_r_core, Hydro_Analysis_interpolator_coordinates, Hydro_Analysis_interpolator_name, Hydro_Analysis_interpolator_options, Hydro_Analysis_average_multiple_maxima_locations, Hydro_Analysis_comp_core_rho_centroid, Hydro_Analysis_comp_rho_max, Hydro_Analysis_comp_rho_max_every, Hydro_Analysis_comp_rho_max_origin_distance, Hydro_Analysis_comp_vol_weighted_center_of_mass, Hydro_Analysis_rho_max_loc_only_positive_x, Hydro_Analysis_rho_max_loc_use_rotatingsymmetry180, Hydro_Analysis_rho_max_origin_distance_npoints, verbosity_level&&\
CCTK_DECLARE(CCTK_STRING,CCTKH0,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH1,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH2,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH3,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH4,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH6,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH7,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH8,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH9,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH10,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH11,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH12,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH13,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH14,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH15,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH5,)&&\
CCTK_DECLARE(CCTK_INT,timelevels,)&&\
COMMON /HYDROBASErest/CCTKH0, CCTKH1, CCTKH2, CCTKH3, CCTKH4, CCTKH6, CCTKH7, CCTKH8, CCTKH9, CCTKH10, CCTKH11, CCTKH12, CCTKH13, CCTKH14, CCTKH15, CCTKH5, timelevels&&\

