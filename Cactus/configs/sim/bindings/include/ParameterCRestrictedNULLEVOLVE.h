#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Diagnostics_Coord_x;
  const char * boundary_data;
  const char * initial_J_data;
  CCTK_INT DEBUG_skip_B_update;
  CCTK_INT DEBUG_skip_CB_update;
  CCTK_INT DEBUG_skip_CK_update;
  CCTK_INT DEBUG_skip_J_update;
  CCTK_INT DEBUG_skip_NU_update;
  CCTK_INT DEBUG_skip_Q_update;
  CCTK_INT DEBUG_skip_U_update;
  CCTK_INT DEBUG_skip_W_update;
  CCTK_INT DEBUG_skip_evolution;
  CCTK_INT debug_verbose;
  CCTK_INT first_order_scheme;
  CCTK_INT old_J_xderiv;
} RESTRICTED_NULLEVOLVE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_NULLEVOLVE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, Diagnostics_Coord_x, CCTK_PARAMETER__NULLEVOLVE__Diagnostics_Coord_x); \
  CCTK_DECLARE_INIT (const char * const, boundary_data, CCTK_PARAMETER__NULLEVOLVE__boundary_data); \
  CCTK_DECLARE_INIT (const char * const, initial_J_data, CCTK_PARAMETER__NULLEVOLVE__initial_J_data); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_B_update, CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_B_update); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_CB_update, CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_CB_update); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_CK_update, CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_CK_update); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_J_update, CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_J_update); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_NU_update, CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_NU_update); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_Q_update, CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_Q_update); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_U_update, CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_U_update); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_W_update, CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_W_update); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_evolution, CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_evolution); \
  CCTK_DECLARE_INIT (CCTK_INT const, debug_verbose, CCTK_PARAMETER__NULLEVOLVE__debug_verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, first_order_scheme, CCTK_PARAMETER__NULLEVOLVE__first_order_scheme); \
  CCTK_DECLARE_INIT (CCTK_INT const, old_J_xderiv, CCTK_PARAMETER__NULLEVOLVE__old_J_xderiv); \


#ifndef CCTK_PARAMETER__NULLEVOLVE__Diagnostics_Coord_x
#  define CCTK_PARAMETER__NULLEVOLVE__Diagnostics_Coord_x RESTRICTED_NULLEVOLVE_STRUCT.Diagnostics_Coord_x
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__boundary_data
#  define CCTK_PARAMETER__NULLEVOLVE__boundary_data RESTRICTED_NULLEVOLVE_STRUCT.boundary_data
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__initial_J_data
#  define CCTK_PARAMETER__NULLEVOLVE__initial_J_data RESTRICTED_NULLEVOLVE_STRUCT.initial_J_data
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_B_update
#  define CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_B_update RESTRICTED_NULLEVOLVE_STRUCT.DEBUG_skip_B_update
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_CB_update
#  define CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_CB_update RESTRICTED_NULLEVOLVE_STRUCT.DEBUG_skip_CB_update
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_CK_update
#  define CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_CK_update RESTRICTED_NULLEVOLVE_STRUCT.DEBUG_skip_CK_update
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_J_update
#  define CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_J_update RESTRICTED_NULLEVOLVE_STRUCT.DEBUG_skip_J_update
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_NU_update
#  define CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_NU_update RESTRICTED_NULLEVOLVE_STRUCT.DEBUG_skip_NU_update
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_Q_update
#  define CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_Q_update RESTRICTED_NULLEVOLVE_STRUCT.DEBUG_skip_Q_update
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_U_update
#  define CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_U_update RESTRICTED_NULLEVOLVE_STRUCT.DEBUG_skip_U_update
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_W_update
#  define CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_W_update RESTRICTED_NULLEVOLVE_STRUCT.DEBUG_skip_W_update
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_evolution
#  define CCTK_PARAMETER__NULLEVOLVE__DEBUG_skip_evolution RESTRICTED_NULLEVOLVE_STRUCT.DEBUG_skip_evolution
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__debug_verbose
#  define CCTK_PARAMETER__NULLEVOLVE__debug_verbose RESTRICTED_NULLEVOLVE_STRUCT.debug_verbose
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__first_order_scheme
#  define CCTK_PARAMETER__NULLEVOLVE__first_order_scheme RESTRICTED_NULLEVOLVE_STRUCT.first_order_scheme
#endif
#ifndef CCTK_PARAMETER__NULLEVOLVE__old_J_xderiv
#  define CCTK_PARAMETER__NULLEVOLVE__old_J_xderiv RESTRICTED_NULLEVOLVE_STRUCT.old_J_xderiv
#endif

