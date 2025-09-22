#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL null_rwt;
  CCTK_REAL null_xin;
  CCTK_INT N_ang_ev_outside_eq;
  CCTK_INT N_ang_ghost_pts;
  CCTK_INT N_ang_pts_inside_eq;
  CCTK_INT N_ang_stencil_size;
  CCTK_INT N_radial_pts;
  CCTK_INT verbose;
} RESTRICTED_NULLGRID_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_NULLGRID_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, null_rwt, CCTK_PARAMETER__NULLGRID__null_rwt); \
  CCTK_DECLARE_INIT (CCTK_REAL const, null_xin, CCTK_PARAMETER__NULLGRID__null_xin); \
  CCTK_DECLARE_INIT (CCTK_INT const, N_ang_ev_outside_eq, CCTK_PARAMETER__NULLGRID__N_ang_ev_outside_eq); \
  CCTK_DECLARE_INIT (CCTK_INT const, N_ang_ghost_pts, CCTK_PARAMETER__NULLGRID__N_ang_ghost_pts); \
  CCTK_DECLARE_INIT (CCTK_INT const, N_ang_pts_inside_eq, CCTK_PARAMETER__NULLGRID__N_ang_pts_inside_eq); \
  CCTK_DECLARE_INIT (CCTK_INT const, N_ang_stencil_size, CCTK_PARAMETER__NULLGRID__N_ang_stencil_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, N_radial_pts, CCTK_PARAMETER__NULLGRID__N_radial_pts); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__NULLGRID__verbose); \


#ifndef CCTK_PARAMETER__NULLGRID__null_rwt
#  define CCTK_PARAMETER__NULLGRID__null_rwt RESTRICTED_NULLGRID_STRUCT.null_rwt
#endif
#ifndef CCTK_PARAMETER__NULLGRID__null_xin
#  define CCTK_PARAMETER__NULLGRID__null_xin RESTRICTED_NULLGRID_STRUCT.null_xin
#endif
#ifndef CCTK_PARAMETER__NULLGRID__N_ang_ev_outside_eq
#  define CCTK_PARAMETER__NULLGRID__N_ang_ev_outside_eq RESTRICTED_NULLGRID_STRUCT.N_ang_ev_outside_eq
#endif
#ifndef CCTK_PARAMETER__NULLGRID__N_ang_ghost_pts
#  define CCTK_PARAMETER__NULLGRID__N_ang_ghost_pts RESTRICTED_NULLGRID_STRUCT.N_ang_ghost_pts
#endif
#ifndef CCTK_PARAMETER__NULLGRID__N_ang_pts_inside_eq
#  define CCTK_PARAMETER__NULLGRID__N_ang_pts_inside_eq RESTRICTED_NULLGRID_STRUCT.N_ang_pts_inside_eq
#endif
#ifndef CCTK_PARAMETER__NULLGRID__N_ang_stencil_size
#  define CCTK_PARAMETER__NULLGRID__N_ang_stencil_size RESTRICTED_NULLGRID_STRUCT.N_ang_stencil_size
#endif
#ifndef CCTK_PARAMETER__NULLGRID__N_radial_pts
#  define CCTK_PARAMETER__NULLGRID__N_radial_pts RESTRICTED_NULLGRID_STRUCT.N_radial_pts
#endif
#ifndef CCTK_PARAMETER__NULLGRID__verbose
#  define CCTK_PARAMETER__NULLGRID__verbose RESTRICTED_NULLGRID_STRUCT.verbose
#endif

