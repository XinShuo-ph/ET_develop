#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL ah_max_epsdis;
  CCTK_REAL ah_radius_offset;
  CCTK_REAL ah_slope;
  CCTK_REAL epsdis;
  CCTK_REAL epsdis_for_level[32];
  CCTK_REAL ob_slope;
  CCTK_REAL outer_boundary_max_epsdis;
  const char * vars;
  CCTK_INT extra_dissipation_at_outerbound;
  CCTK_INT extra_dissipation_in_horizons;
  CCTK_INT horizon_number[100];
  CCTK_INT order;
  CCTK_INT outer_bound_npoints;
  CCTK_INT respect_emask;
  CCTK_INT surface_number[100];
  CCTK_INT update_ah_every;
  CCTK_INT use_dissipation_near_excision;
  CCTK_INT verbose;
} RESTRICTED_DISSIPATION_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_DISSIPATION_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, ah_max_epsdis, CCTK_PARAMETER__DISSIPATION__ah_max_epsdis); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ah_radius_offset, CCTK_PARAMETER__DISSIPATION__ah_radius_offset); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ah_slope, CCTK_PARAMETER__DISSIPATION__ah_slope); \
  CCTK_DECLARE_INIT (CCTK_REAL const, epsdis, CCTK_PARAMETER__DISSIPATION__epsdis); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, epsdis_for_level, CCTK_PARAMETER__DISSIPATION__epsdis_for_level); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ob_slope, CCTK_PARAMETER__DISSIPATION__ob_slope); \
  CCTK_DECLARE_INIT (CCTK_REAL const, outer_boundary_max_epsdis, CCTK_PARAMETER__DISSIPATION__outer_boundary_max_epsdis); \
  CCTK_DECLARE_INIT (const char * const, vars, CCTK_PARAMETER__DISSIPATION__vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, extra_dissipation_at_outerbound, CCTK_PARAMETER__DISSIPATION__extra_dissipation_at_outerbound); \
  CCTK_DECLARE_INIT (CCTK_INT const, extra_dissipation_in_horizons, CCTK_PARAMETER__DISSIPATION__extra_dissipation_in_horizons); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, horizon_number, CCTK_PARAMETER__DISSIPATION__horizon_number); \
  CCTK_DECLARE_INIT (CCTK_INT const, order, CCTK_PARAMETER__DISSIPATION__order); \
  CCTK_DECLARE_INIT (CCTK_INT const, outer_bound_npoints, CCTK_PARAMETER__DISSIPATION__outer_bound_npoints); \
  CCTK_DECLARE_INIT (CCTK_INT const, respect_emask, CCTK_PARAMETER__DISSIPATION__respect_emask); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, surface_number, CCTK_PARAMETER__DISSIPATION__surface_number); \
  CCTK_DECLARE_INIT (CCTK_INT const, update_ah_every, CCTK_PARAMETER__DISSIPATION__update_ah_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_dissipation_near_excision, CCTK_PARAMETER__DISSIPATION__use_dissipation_near_excision); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__DISSIPATION__verbose); \


#ifndef CCTK_PARAMETER__DISSIPATION__ah_max_epsdis
#  define CCTK_PARAMETER__DISSIPATION__ah_max_epsdis RESTRICTED_DISSIPATION_STRUCT.ah_max_epsdis
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__ah_radius_offset
#  define CCTK_PARAMETER__DISSIPATION__ah_radius_offset RESTRICTED_DISSIPATION_STRUCT.ah_radius_offset
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__ah_slope
#  define CCTK_PARAMETER__DISSIPATION__ah_slope RESTRICTED_DISSIPATION_STRUCT.ah_slope
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__epsdis
#  define CCTK_PARAMETER__DISSIPATION__epsdis RESTRICTED_DISSIPATION_STRUCT.epsdis
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__epsdis_for_level
#  define CCTK_PARAMETER__DISSIPATION__epsdis_for_level RESTRICTED_DISSIPATION_STRUCT.epsdis_for_level
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__ob_slope
#  define CCTK_PARAMETER__DISSIPATION__ob_slope RESTRICTED_DISSIPATION_STRUCT.ob_slope
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__outer_boundary_max_epsdis
#  define CCTK_PARAMETER__DISSIPATION__outer_boundary_max_epsdis RESTRICTED_DISSIPATION_STRUCT.outer_boundary_max_epsdis
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__vars
#  define CCTK_PARAMETER__DISSIPATION__vars RESTRICTED_DISSIPATION_STRUCT.vars
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__extra_dissipation_at_outerbound
#  define CCTK_PARAMETER__DISSIPATION__extra_dissipation_at_outerbound RESTRICTED_DISSIPATION_STRUCT.extra_dissipation_at_outerbound
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__extra_dissipation_in_horizons
#  define CCTK_PARAMETER__DISSIPATION__extra_dissipation_in_horizons RESTRICTED_DISSIPATION_STRUCT.extra_dissipation_in_horizons
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__horizon_number
#  define CCTK_PARAMETER__DISSIPATION__horizon_number RESTRICTED_DISSIPATION_STRUCT.horizon_number
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__order
#  define CCTK_PARAMETER__DISSIPATION__order RESTRICTED_DISSIPATION_STRUCT.order
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__outer_bound_npoints
#  define CCTK_PARAMETER__DISSIPATION__outer_bound_npoints RESTRICTED_DISSIPATION_STRUCT.outer_bound_npoints
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__respect_emask
#  define CCTK_PARAMETER__DISSIPATION__respect_emask RESTRICTED_DISSIPATION_STRUCT.respect_emask
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__surface_number
#  define CCTK_PARAMETER__DISSIPATION__surface_number RESTRICTED_DISSIPATION_STRUCT.surface_number
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__update_ah_every
#  define CCTK_PARAMETER__DISSIPATION__update_ah_every RESTRICTED_DISSIPATION_STRUCT.update_ah_every
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__use_dissipation_near_excision
#  define CCTK_PARAMETER__DISSIPATION__use_dissipation_near_excision RESTRICTED_DISSIPATION_STRUCT.use_dissipation_near_excision
#endif
#ifndef CCTK_PARAMETER__DISSIPATION__verbose
#  define CCTK_PARAMETER__DISSIPATION__verbose RESTRICTED_DISSIPATION_STRUCT.verbose
#endif

