#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,ah_max_epsdis,)&&\
CCTK_DECLARE(CCTK_REAL,ah_radius_offset,)&&\
CCTK_DECLARE(CCTK_REAL,ah_slope,)&&\
CCTK_DECLARE(CCTK_REAL,epsdis,)&&\
CCTK_DECLARE(CCTK_REAL,epsdis_for_level,(32))&&\
CCTK_DECLARE(CCTK_REAL,ob_slope,)&&\
CCTK_DECLARE(CCTK_REAL,outer_boundary_max_epsdis,)&&\
CCTK_DECLARE(CCTK_STRING,vars,)&&\
CCTK_DECLARE(CCTK_INT,extra_dissipation_at_outerbound,)&&\
CCTK_DECLARE(CCTK_INT,extra_dissipation_in_horizons,)&&\
CCTK_DECLARE(CCTK_INT,horizon_number,(100))&&\
CCTK_DECLARE(CCTK_INT,order,)&&\
CCTK_DECLARE(CCTK_INT,outer_bound_npoints,)&&\
CCTK_DECLARE(CCTK_INT,respect_emask,)&&\
CCTK_DECLARE(CCTK_INT,surface_number,(100))&&\
CCTK_DECLARE(CCTK_INT,update_ah_every,)&&\
CCTK_DECLARE(CCTK_INT,use_dissipation_near_excision,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /Dissipationrest/ah_max_epsdis, ah_radius_offset, ah_slope, epsdis, epsdis_for_level, ob_slope, outer_boundary_max_epsdis, vars, extra_dissipation_at_outerbound, extra_dissipation_in_horizons, horizon_number, order, outer_bound_npoints, respect_emask, surface_number, update_ah_every, use_dissipation_near_excision, verbose&&\
CCTK_DECLARE(CCTK_INT,use_mask,)&&\
COMMON /SPACEMASKrest/use_mask&&\

