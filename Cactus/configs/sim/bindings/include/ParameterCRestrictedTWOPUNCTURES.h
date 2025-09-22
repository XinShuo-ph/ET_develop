#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Newton_tol;
  CCTK_REAL TP_Extend_Radius;
  CCTK_REAL TP_Tiny;
  CCTK_REAL TP_epsilon;
  CCTK_REAL adm_tol;
  CCTK_REAL center_offset[3];
  CCTK_REAL initial_lapse_psi_exponent;
  CCTK_REAL par_P_minus[3];
  CCTK_REAL par_P_plus[3];
  CCTK_REAL par_S_minus[3];
  CCTK_REAL par_S_plus[3];
  CCTK_REAL par_b;
  CCTK_REAL par_m_minus;
  CCTK_REAL par_m_plus;
  CCTK_REAL target_M_minus;
  CCTK_REAL target_M_plus;
  const char * grid_setup_method;
  CCTK_INT Newton_maxit;
  CCTK_INT do_initial_debug_output;
  CCTK_INT do_residuum_debug_output;
  CCTK_INT give_bare_mass;
  CCTK_INT keep_u_around;
  CCTK_INT multiply_old_lapse;
  CCTK_INT npoints_A;
  CCTK_INT npoints_B;
  CCTK_INT npoints_phi;
  CCTK_INT rescale_sources;
  CCTK_INT schedule_in_ADMBase_InitialData;
  CCTK_INT solve_momentum_constraint;
  CCTK_INT swap_xz;
  CCTK_INT use_external_initial_guess;
  CCTK_INT use_sources;
  CCTK_INT verbose;
} RESTRICTED_TWOPUNCTURES_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_TWOPUNCTURES_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, Newton_tol, CCTK_PARAMETER__TWOPUNCTURES__Newton_tol); \
  CCTK_DECLARE_INIT (CCTK_REAL const, TP_Extend_Radius, CCTK_PARAMETER__TWOPUNCTURES__TP_Extend_Radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, TP_Tiny, CCTK_PARAMETER__TWOPUNCTURES__TP_Tiny); \
  CCTK_DECLARE_INIT (CCTK_REAL const, TP_epsilon, CCTK_PARAMETER__TWOPUNCTURES__TP_epsilon); \
  CCTK_DECLARE_INIT (CCTK_REAL const, adm_tol, CCTK_PARAMETER__TWOPUNCTURES__adm_tol); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, center_offset, CCTK_PARAMETER__TWOPUNCTURES__center_offset); \
  CCTK_DECLARE_INIT (CCTK_REAL const, initial_lapse_psi_exponent, CCTK_PARAMETER__TWOPUNCTURES__initial_lapse_psi_exponent); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, par_P_minus, CCTK_PARAMETER__TWOPUNCTURES__par_P_minus); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, par_P_plus, CCTK_PARAMETER__TWOPUNCTURES__par_P_plus); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, par_S_minus, CCTK_PARAMETER__TWOPUNCTURES__par_S_minus); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, par_S_plus, CCTK_PARAMETER__TWOPUNCTURES__par_S_plus); \
  CCTK_DECLARE_INIT (CCTK_REAL const, par_b, CCTK_PARAMETER__TWOPUNCTURES__par_b); \
  CCTK_DECLARE_INIT (CCTK_REAL const, par_m_minus, CCTK_PARAMETER__TWOPUNCTURES__par_m_minus); \
  CCTK_DECLARE_INIT (CCTK_REAL const, par_m_plus, CCTK_PARAMETER__TWOPUNCTURES__par_m_plus); \
  CCTK_DECLARE_INIT (CCTK_REAL const, target_M_minus, CCTK_PARAMETER__TWOPUNCTURES__target_M_minus); \
  CCTK_DECLARE_INIT (CCTK_REAL const, target_M_plus, CCTK_PARAMETER__TWOPUNCTURES__target_M_plus); \
  CCTK_DECLARE_INIT (const char * const, grid_setup_method, CCTK_PARAMETER__TWOPUNCTURES__grid_setup_method); \
  CCTK_DECLARE_INIT (CCTK_INT const, Newton_maxit, CCTK_PARAMETER__TWOPUNCTURES__Newton_maxit); \
  CCTK_DECLARE_INIT (CCTK_INT const, do_initial_debug_output, CCTK_PARAMETER__TWOPUNCTURES__do_initial_debug_output); \
  CCTK_DECLARE_INIT (CCTK_INT const, do_residuum_debug_output, CCTK_PARAMETER__TWOPUNCTURES__do_residuum_debug_output); \
  CCTK_DECLARE_INIT (CCTK_INT const, give_bare_mass, CCTK_PARAMETER__TWOPUNCTURES__give_bare_mass); \
  CCTK_DECLARE_INIT (CCTK_INT const, keep_u_around, CCTK_PARAMETER__TWOPUNCTURES__keep_u_around); \
  CCTK_DECLARE_INIT (CCTK_INT const, multiply_old_lapse, CCTK_PARAMETER__TWOPUNCTURES__multiply_old_lapse); \
  CCTK_DECLARE_INIT (CCTK_INT const, npoints_A, CCTK_PARAMETER__TWOPUNCTURES__npoints_A); \
  CCTK_DECLARE_INIT (CCTK_INT const, npoints_B, CCTK_PARAMETER__TWOPUNCTURES__npoints_B); \
  CCTK_DECLARE_INIT (CCTK_INT const, npoints_phi, CCTK_PARAMETER__TWOPUNCTURES__npoints_phi); \
  CCTK_DECLARE_INIT (CCTK_INT const, rescale_sources, CCTK_PARAMETER__TWOPUNCTURES__rescale_sources); \
  CCTK_DECLARE_INIT (CCTK_INT const, schedule_in_ADMBase_InitialData, CCTK_PARAMETER__TWOPUNCTURES__schedule_in_ADMBase_InitialData); \
  CCTK_DECLARE_INIT (CCTK_INT const, solve_momentum_constraint, CCTK_PARAMETER__TWOPUNCTURES__solve_momentum_constraint); \
  CCTK_DECLARE_INIT (CCTK_INT const, swap_xz, CCTK_PARAMETER__TWOPUNCTURES__swap_xz); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_external_initial_guess, CCTK_PARAMETER__TWOPUNCTURES__use_external_initial_guess); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_sources, CCTK_PARAMETER__TWOPUNCTURES__use_sources); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__TWOPUNCTURES__verbose); \


#ifndef CCTK_PARAMETER__TWOPUNCTURES__Newton_tol
#  define CCTK_PARAMETER__TWOPUNCTURES__Newton_tol RESTRICTED_TWOPUNCTURES_STRUCT.Newton_tol
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__TP_Extend_Radius
#  define CCTK_PARAMETER__TWOPUNCTURES__TP_Extend_Radius RESTRICTED_TWOPUNCTURES_STRUCT.TP_Extend_Radius
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__TP_Tiny
#  define CCTK_PARAMETER__TWOPUNCTURES__TP_Tiny RESTRICTED_TWOPUNCTURES_STRUCT.TP_Tiny
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__TP_epsilon
#  define CCTK_PARAMETER__TWOPUNCTURES__TP_epsilon RESTRICTED_TWOPUNCTURES_STRUCT.TP_epsilon
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__adm_tol
#  define CCTK_PARAMETER__TWOPUNCTURES__adm_tol RESTRICTED_TWOPUNCTURES_STRUCT.adm_tol
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__center_offset
#  define CCTK_PARAMETER__TWOPUNCTURES__center_offset RESTRICTED_TWOPUNCTURES_STRUCT.center_offset
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__initial_lapse_psi_exponent
#  define CCTK_PARAMETER__TWOPUNCTURES__initial_lapse_psi_exponent RESTRICTED_TWOPUNCTURES_STRUCT.initial_lapse_psi_exponent
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__par_P_minus
#  define CCTK_PARAMETER__TWOPUNCTURES__par_P_minus RESTRICTED_TWOPUNCTURES_STRUCT.par_P_minus
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__par_P_plus
#  define CCTK_PARAMETER__TWOPUNCTURES__par_P_plus RESTRICTED_TWOPUNCTURES_STRUCT.par_P_plus
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__par_S_minus
#  define CCTK_PARAMETER__TWOPUNCTURES__par_S_minus RESTRICTED_TWOPUNCTURES_STRUCT.par_S_minus
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__par_S_plus
#  define CCTK_PARAMETER__TWOPUNCTURES__par_S_plus RESTRICTED_TWOPUNCTURES_STRUCT.par_S_plus
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__par_b
#  define CCTK_PARAMETER__TWOPUNCTURES__par_b RESTRICTED_TWOPUNCTURES_STRUCT.par_b
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__par_m_minus
#  define CCTK_PARAMETER__TWOPUNCTURES__par_m_minus RESTRICTED_TWOPUNCTURES_STRUCT.par_m_minus
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__par_m_plus
#  define CCTK_PARAMETER__TWOPUNCTURES__par_m_plus RESTRICTED_TWOPUNCTURES_STRUCT.par_m_plus
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__target_M_minus
#  define CCTK_PARAMETER__TWOPUNCTURES__target_M_minus RESTRICTED_TWOPUNCTURES_STRUCT.target_M_minus
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__target_M_plus
#  define CCTK_PARAMETER__TWOPUNCTURES__target_M_plus RESTRICTED_TWOPUNCTURES_STRUCT.target_M_plus
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__grid_setup_method
#  define CCTK_PARAMETER__TWOPUNCTURES__grid_setup_method RESTRICTED_TWOPUNCTURES_STRUCT.grid_setup_method
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__Newton_maxit
#  define CCTK_PARAMETER__TWOPUNCTURES__Newton_maxit RESTRICTED_TWOPUNCTURES_STRUCT.Newton_maxit
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__do_initial_debug_output
#  define CCTK_PARAMETER__TWOPUNCTURES__do_initial_debug_output RESTRICTED_TWOPUNCTURES_STRUCT.do_initial_debug_output
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__do_residuum_debug_output
#  define CCTK_PARAMETER__TWOPUNCTURES__do_residuum_debug_output RESTRICTED_TWOPUNCTURES_STRUCT.do_residuum_debug_output
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__give_bare_mass
#  define CCTK_PARAMETER__TWOPUNCTURES__give_bare_mass RESTRICTED_TWOPUNCTURES_STRUCT.give_bare_mass
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__keep_u_around
#  define CCTK_PARAMETER__TWOPUNCTURES__keep_u_around RESTRICTED_TWOPUNCTURES_STRUCT.keep_u_around
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__multiply_old_lapse
#  define CCTK_PARAMETER__TWOPUNCTURES__multiply_old_lapse RESTRICTED_TWOPUNCTURES_STRUCT.multiply_old_lapse
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__npoints_A
#  define CCTK_PARAMETER__TWOPUNCTURES__npoints_A RESTRICTED_TWOPUNCTURES_STRUCT.npoints_A
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__npoints_B
#  define CCTK_PARAMETER__TWOPUNCTURES__npoints_B RESTRICTED_TWOPUNCTURES_STRUCT.npoints_B
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__npoints_phi
#  define CCTK_PARAMETER__TWOPUNCTURES__npoints_phi RESTRICTED_TWOPUNCTURES_STRUCT.npoints_phi
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__rescale_sources
#  define CCTK_PARAMETER__TWOPUNCTURES__rescale_sources RESTRICTED_TWOPUNCTURES_STRUCT.rescale_sources
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__schedule_in_ADMBase_InitialData
#  define CCTK_PARAMETER__TWOPUNCTURES__schedule_in_ADMBase_InitialData RESTRICTED_TWOPUNCTURES_STRUCT.schedule_in_ADMBase_InitialData
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__solve_momentum_constraint
#  define CCTK_PARAMETER__TWOPUNCTURES__solve_momentum_constraint RESTRICTED_TWOPUNCTURES_STRUCT.solve_momentum_constraint
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__swap_xz
#  define CCTK_PARAMETER__TWOPUNCTURES__swap_xz RESTRICTED_TWOPUNCTURES_STRUCT.swap_xz
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__use_external_initial_guess
#  define CCTK_PARAMETER__TWOPUNCTURES__use_external_initial_guess RESTRICTED_TWOPUNCTURES_STRUCT.use_external_initial_guess
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__use_sources
#  define CCTK_PARAMETER__TWOPUNCTURES__use_sources RESTRICTED_TWOPUNCTURES_STRUCT.use_sources
#endif
#ifndef CCTK_PARAMETER__TWOPUNCTURES__verbose
#  define CCTK_PARAMETER__TWOPUNCTURES__verbose RESTRICTED_TWOPUNCTURES_STRUCT.verbose
#endif

