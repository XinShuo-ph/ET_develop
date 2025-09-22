#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL cas_a[10];
  CCTK_REAL cas_b[10];
  CCTK_REAL center_x;
  CCTK_REAL center_y;
  CCTK_REAL center_z;
  CCTK_REAL initial_a[10];
  CCTK_REAL initial_b[10];
  CCTK_REAL initial_c[10];
  CCTK_REAL initial_rad[10];
  CCTK_REAL rotation_alpha[10];
  CCTK_REAL rotation_beta[10];
  CCTK_REAL rotation_gamma[10];
  CCTK_REAL shell_width;
  CCTK_REAL translate_x[10];
  CCTK_REAL translate_y[10];
  CCTK_REAL translate_z[10];
  const char * area_calculation_method;
  const char * area_interpolator;
  const char * eh_lapse_type;
  const char * eh_metric_type;
  const char * eh_shift_type;
  const char * file_type;
  const char * generator_distribution;
  const char * generator_interpolator;
  const char * generator_tracking_method;
  const char * initial_f[10];
  const char * mode;
  const char * pde_differences;
  const char * re_init_int_method;
  const char * surface_direction;
  const char * surface_interpolator;
  const char * upwind_type;
  CCTK_INT area_interpolation_order;
  CCTK_INT cheat;
  CCTK_INT cheat_iterations;
  CCTK_INT eh_number_level_sets;
  CCTK_INT evolve_generators;
  CCTK_INT generator_interpolation_order;
  CCTK_INT last_iteration_number;
  CCTK_INT maximum_surface_number;
  CCTK_INT n_array_ghosts;
  CCTK_INT nphi;
  CCTK_INT ntheta;
  CCTK_INT number_of_generators;
  CCTK_INT number_of_generators_phi;
  CCTK_INT number_of_generators_theta;
  CCTK_INT re_init_max_iter;
  CCTK_INT re_init_undo;
  CCTK_INT re_init_verbose;
  CCTK_INT re_initialize_every;
  CCTK_INT read_conformal_factor_once;
  CCTK_INT saved_iteration_every;
  CCTK_INT surface_interpolation_order;
  CCTK_INT use_inner_excision;
  CCTK_INT use_outer_excision;
  CCTK_INT use_user_center;
} PRIVATE_EHFINDER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_EHFINDER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, cas_a, CCTK_PARAMETER__EHFINDER__cas_a); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, cas_b, CCTK_PARAMETER__EHFINDER__cas_b); \
  CCTK_DECLARE_INIT (CCTK_REAL const, center_x, CCTK_PARAMETER__EHFINDER__center_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, center_y, CCTK_PARAMETER__EHFINDER__center_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, center_z, CCTK_PARAMETER__EHFINDER__center_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_a, CCTK_PARAMETER__EHFINDER__initial_a); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_b, CCTK_PARAMETER__EHFINDER__initial_b); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_c, CCTK_PARAMETER__EHFINDER__initial_c); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_rad, CCTK_PARAMETER__EHFINDER__initial_rad); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, rotation_alpha, CCTK_PARAMETER__EHFINDER__rotation_alpha); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, rotation_beta, CCTK_PARAMETER__EHFINDER__rotation_beta); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, rotation_gamma, CCTK_PARAMETER__EHFINDER__rotation_gamma); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shell_width, CCTK_PARAMETER__EHFINDER__shell_width); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, translate_x, CCTK_PARAMETER__EHFINDER__translate_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, translate_y, CCTK_PARAMETER__EHFINDER__translate_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, translate_z, CCTK_PARAMETER__EHFINDER__translate_z); \
  CCTK_DECLARE_INIT (const char * const, area_calculation_method, CCTK_PARAMETER__EHFINDER__area_calculation_method); \
  CCTK_DECLARE_INIT (const char * const, area_interpolator, CCTK_PARAMETER__EHFINDER__area_interpolator); \
  CCTK_DECLARE_INIT (const char * const, eh_lapse_type, CCTK_PARAMETER__EHFINDER__eh_lapse_type); \
  CCTK_DECLARE_INIT (const char * const, eh_metric_type, CCTK_PARAMETER__EHFINDER__eh_metric_type); \
  CCTK_DECLARE_INIT (const char * const, eh_shift_type, CCTK_PARAMETER__EHFINDER__eh_shift_type); \
  CCTK_DECLARE_INIT (const char * const, file_type, CCTK_PARAMETER__EHFINDER__file_type); \
  CCTK_DECLARE_INIT (const char * const, generator_distribution, CCTK_PARAMETER__EHFINDER__generator_distribution); \
  CCTK_DECLARE_INIT (const char * const, generator_interpolator, CCTK_PARAMETER__EHFINDER__generator_interpolator); \
  CCTK_DECLARE_INIT (const char * const, generator_tracking_method, CCTK_PARAMETER__EHFINDER__generator_tracking_method); \
  CCTK_DECLARE_INIT (const char * const * const, initial_f, CCTK_PARAMETER__EHFINDER__initial_f); \
  CCTK_DECLARE_INIT (const char * const, mode, CCTK_PARAMETER__EHFINDER__mode); \
  CCTK_DECLARE_INIT (const char * const, pde_differences, CCTK_PARAMETER__EHFINDER__pde_differences); \
  CCTK_DECLARE_INIT (const char * const, re_init_int_method, CCTK_PARAMETER__EHFINDER__re_init_int_method); \
  CCTK_DECLARE_INIT (const char * const, surface_direction, CCTK_PARAMETER__EHFINDER__surface_direction); \
  CCTK_DECLARE_INIT (const char * const, surface_interpolator, CCTK_PARAMETER__EHFINDER__surface_interpolator); \
  CCTK_DECLARE_INIT (const char * const, upwind_type, CCTK_PARAMETER__EHFINDER__upwind_type); \
  CCTK_DECLARE_INIT (CCTK_INT const, area_interpolation_order, CCTK_PARAMETER__EHFINDER__area_interpolation_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, cheat, CCTK_PARAMETER__EHFINDER__cheat); \
  CCTK_DECLARE_INIT (CCTK_INT const, cheat_iterations, CCTK_PARAMETER__EHFINDER__cheat_iterations); \
  CCTK_DECLARE_INIT (CCTK_INT const, eh_number_level_sets, CCTK_PARAMETER__EHFINDER__eh_number_level_sets); \
  CCTK_DECLARE_INIT (CCTK_INT const, evolve_generators, CCTK_PARAMETER__EHFINDER__evolve_generators); \
  CCTK_DECLARE_INIT (CCTK_INT const, generator_interpolation_order, CCTK_PARAMETER__EHFINDER__generator_interpolation_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, last_iteration_number, CCTK_PARAMETER__EHFINDER__last_iteration_number); \
  CCTK_DECLARE_INIT (CCTK_INT const, maximum_surface_number, CCTK_PARAMETER__EHFINDER__maximum_surface_number); \
  CCTK_DECLARE_INIT (CCTK_INT const, n_array_ghosts, CCTK_PARAMETER__EHFINDER__n_array_ghosts); \
  CCTK_DECLARE_INIT (CCTK_INT const, nphi, CCTK_PARAMETER__EHFINDER__nphi); \
  CCTK_DECLARE_INIT (CCTK_INT const, ntheta, CCTK_PARAMETER__EHFINDER__ntheta); \
  CCTK_DECLARE_INIT (CCTK_INT const, number_of_generators, CCTK_PARAMETER__EHFINDER__number_of_generators); \
  CCTK_DECLARE_INIT (CCTK_INT const, number_of_generators_phi, CCTK_PARAMETER__EHFINDER__number_of_generators_phi); \
  CCTK_DECLARE_INIT (CCTK_INT const, number_of_generators_theta, CCTK_PARAMETER__EHFINDER__number_of_generators_theta); \
  CCTK_DECLARE_INIT (CCTK_INT const, re_init_max_iter, CCTK_PARAMETER__EHFINDER__re_init_max_iter); \
  CCTK_DECLARE_INIT (CCTK_INT const, re_init_undo, CCTK_PARAMETER__EHFINDER__re_init_undo); \
  CCTK_DECLARE_INIT (CCTK_INT const, re_init_verbose, CCTK_PARAMETER__EHFINDER__re_init_verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, re_initialize_every, CCTK_PARAMETER__EHFINDER__re_initialize_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, read_conformal_factor_once, CCTK_PARAMETER__EHFINDER__read_conformal_factor_once); \
  CCTK_DECLARE_INIT (CCTK_INT const, saved_iteration_every, CCTK_PARAMETER__EHFINDER__saved_iteration_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, surface_interpolation_order, CCTK_PARAMETER__EHFINDER__surface_interpolation_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_inner_excision, CCTK_PARAMETER__EHFINDER__use_inner_excision); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_outer_excision, CCTK_PARAMETER__EHFINDER__use_outer_excision); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_user_center, CCTK_PARAMETER__EHFINDER__use_user_center); \


#ifndef CCTK_PARAMETER__EHFINDER__cas_a
#  define CCTK_PARAMETER__EHFINDER__cas_a PRIVATE_EHFINDER_STRUCT.cas_a
#endif
#ifndef CCTK_PARAMETER__EHFINDER__cas_b
#  define CCTK_PARAMETER__EHFINDER__cas_b PRIVATE_EHFINDER_STRUCT.cas_b
#endif
#ifndef CCTK_PARAMETER__EHFINDER__center_x
#  define CCTK_PARAMETER__EHFINDER__center_x PRIVATE_EHFINDER_STRUCT.center_x
#endif
#ifndef CCTK_PARAMETER__EHFINDER__center_y
#  define CCTK_PARAMETER__EHFINDER__center_y PRIVATE_EHFINDER_STRUCT.center_y
#endif
#ifndef CCTK_PARAMETER__EHFINDER__center_z
#  define CCTK_PARAMETER__EHFINDER__center_z PRIVATE_EHFINDER_STRUCT.center_z
#endif
#ifndef CCTK_PARAMETER__EHFINDER__initial_a
#  define CCTK_PARAMETER__EHFINDER__initial_a PRIVATE_EHFINDER_STRUCT.initial_a
#endif
#ifndef CCTK_PARAMETER__EHFINDER__initial_b
#  define CCTK_PARAMETER__EHFINDER__initial_b PRIVATE_EHFINDER_STRUCT.initial_b
#endif
#ifndef CCTK_PARAMETER__EHFINDER__initial_c
#  define CCTK_PARAMETER__EHFINDER__initial_c PRIVATE_EHFINDER_STRUCT.initial_c
#endif
#ifndef CCTK_PARAMETER__EHFINDER__initial_rad
#  define CCTK_PARAMETER__EHFINDER__initial_rad PRIVATE_EHFINDER_STRUCT.initial_rad
#endif
#ifndef CCTK_PARAMETER__EHFINDER__rotation_alpha
#  define CCTK_PARAMETER__EHFINDER__rotation_alpha PRIVATE_EHFINDER_STRUCT.rotation_alpha
#endif
#ifndef CCTK_PARAMETER__EHFINDER__rotation_beta
#  define CCTK_PARAMETER__EHFINDER__rotation_beta PRIVATE_EHFINDER_STRUCT.rotation_beta
#endif
#ifndef CCTK_PARAMETER__EHFINDER__rotation_gamma
#  define CCTK_PARAMETER__EHFINDER__rotation_gamma PRIVATE_EHFINDER_STRUCT.rotation_gamma
#endif
#ifndef CCTK_PARAMETER__EHFINDER__shell_width
#  define CCTK_PARAMETER__EHFINDER__shell_width PRIVATE_EHFINDER_STRUCT.shell_width
#endif
#ifndef CCTK_PARAMETER__EHFINDER__translate_x
#  define CCTK_PARAMETER__EHFINDER__translate_x PRIVATE_EHFINDER_STRUCT.translate_x
#endif
#ifndef CCTK_PARAMETER__EHFINDER__translate_y
#  define CCTK_PARAMETER__EHFINDER__translate_y PRIVATE_EHFINDER_STRUCT.translate_y
#endif
#ifndef CCTK_PARAMETER__EHFINDER__translate_z
#  define CCTK_PARAMETER__EHFINDER__translate_z PRIVATE_EHFINDER_STRUCT.translate_z
#endif
#ifndef CCTK_PARAMETER__EHFINDER__area_calculation_method
#  define CCTK_PARAMETER__EHFINDER__area_calculation_method PRIVATE_EHFINDER_STRUCT.area_calculation_method
#endif
#ifndef CCTK_PARAMETER__EHFINDER__area_interpolator
#  define CCTK_PARAMETER__EHFINDER__area_interpolator PRIVATE_EHFINDER_STRUCT.area_interpolator
#endif
#ifndef CCTK_PARAMETER__EHFINDER__eh_lapse_type
#  define CCTK_PARAMETER__EHFINDER__eh_lapse_type PRIVATE_EHFINDER_STRUCT.eh_lapse_type
#endif
#ifndef CCTK_PARAMETER__EHFINDER__eh_metric_type
#  define CCTK_PARAMETER__EHFINDER__eh_metric_type PRIVATE_EHFINDER_STRUCT.eh_metric_type
#endif
#ifndef CCTK_PARAMETER__EHFINDER__eh_shift_type
#  define CCTK_PARAMETER__EHFINDER__eh_shift_type PRIVATE_EHFINDER_STRUCT.eh_shift_type
#endif
#ifndef CCTK_PARAMETER__EHFINDER__file_type
#  define CCTK_PARAMETER__EHFINDER__file_type PRIVATE_EHFINDER_STRUCT.file_type
#endif
#ifndef CCTK_PARAMETER__EHFINDER__generator_distribution
#  define CCTK_PARAMETER__EHFINDER__generator_distribution PRIVATE_EHFINDER_STRUCT.generator_distribution
#endif
#ifndef CCTK_PARAMETER__EHFINDER__generator_interpolator
#  define CCTK_PARAMETER__EHFINDER__generator_interpolator PRIVATE_EHFINDER_STRUCT.generator_interpolator
#endif
#ifndef CCTK_PARAMETER__EHFINDER__generator_tracking_method
#  define CCTK_PARAMETER__EHFINDER__generator_tracking_method PRIVATE_EHFINDER_STRUCT.generator_tracking_method
#endif
#ifndef CCTK_PARAMETER__EHFINDER__initial_f
#  define CCTK_PARAMETER__EHFINDER__initial_f PRIVATE_EHFINDER_STRUCT.initial_f
#endif
#ifndef CCTK_PARAMETER__EHFINDER__mode
#  define CCTK_PARAMETER__EHFINDER__mode PRIVATE_EHFINDER_STRUCT.mode
#endif
#ifndef CCTK_PARAMETER__EHFINDER__pde_differences
#  define CCTK_PARAMETER__EHFINDER__pde_differences PRIVATE_EHFINDER_STRUCT.pde_differences
#endif
#ifndef CCTK_PARAMETER__EHFINDER__re_init_int_method
#  define CCTK_PARAMETER__EHFINDER__re_init_int_method PRIVATE_EHFINDER_STRUCT.re_init_int_method
#endif
#ifndef CCTK_PARAMETER__EHFINDER__surface_direction
#  define CCTK_PARAMETER__EHFINDER__surface_direction PRIVATE_EHFINDER_STRUCT.surface_direction
#endif
#ifndef CCTK_PARAMETER__EHFINDER__surface_interpolator
#  define CCTK_PARAMETER__EHFINDER__surface_interpolator PRIVATE_EHFINDER_STRUCT.surface_interpolator
#endif
#ifndef CCTK_PARAMETER__EHFINDER__upwind_type
#  define CCTK_PARAMETER__EHFINDER__upwind_type PRIVATE_EHFINDER_STRUCT.upwind_type
#endif
#ifndef CCTK_PARAMETER__EHFINDER__area_interpolation_order
#  define CCTK_PARAMETER__EHFINDER__area_interpolation_order PRIVATE_EHFINDER_STRUCT.area_interpolation_order
#endif
#ifndef CCTK_PARAMETER__EHFINDER__cheat
#  define CCTK_PARAMETER__EHFINDER__cheat PRIVATE_EHFINDER_STRUCT.cheat
#endif
#ifndef CCTK_PARAMETER__EHFINDER__cheat_iterations
#  define CCTK_PARAMETER__EHFINDER__cheat_iterations PRIVATE_EHFINDER_STRUCT.cheat_iterations
#endif
#ifndef CCTK_PARAMETER__EHFINDER__eh_number_level_sets
#  define CCTK_PARAMETER__EHFINDER__eh_number_level_sets PRIVATE_EHFINDER_STRUCT.eh_number_level_sets
#endif
#ifndef CCTK_PARAMETER__EHFINDER__evolve_generators
#  define CCTK_PARAMETER__EHFINDER__evolve_generators PRIVATE_EHFINDER_STRUCT.evolve_generators
#endif
#ifndef CCTK_PARAMETER__EHFINDER__generator_interpolation_order
#  define CCTK_PARAMETER__EHFINDER__generator_interpolation_order PRIVATE_EHFINDER_STRUCT.generator_interpolation_order
#endif
#ifndef CCTK_PARAMETER__EHFINDER__last_iteration_number
#  define CCTK_PARAMETER__EHFINDER__last_iteration_number PRIVATE_EHFINDER_STRUCT.last_iteration_number
#endif
#ifndef CCTK_PARAMETER__EHFINDER__maximum_surface_number
#  define CCTK_PARAMETER__EHFINDER__maximum_surface_number PRIVATE_EHFINDER_STRUCT.maximum_surface_number
#endif
#ifndef CCTK_PARAMETER__EHFINDER__n_array_ghosts
#  define CCTK_PARAMETER__EHFINDER__n_array_ghosts PRIVATE_EHFINDER_STRUCT.n_array_ghosts
#endif
#ifndef CCTK_PARAMETER__EHFINDER__nphi
#  define CCTK_PARAMETER__EHFINDER__nphi PRIVATE_EHFINDER_STRUCT.nphi
#endif
#ifndef CCTK_PARAMETER__EHFINDER__ntheta
#  define CCTK_PARAMETER__EHFINDER__ntheta PRIVATE_EHFINDER_STRUCT.ntheta
#endif
#ifndef CCTK_PARAMETER__EHFINDER__number_of_generators
#  define CCTK_PARAMETER__EHFINDER__number_of_generators PRIVATE_EHFINDER_STRUCT.number_of_generators
#endif
#ifndef CCTK_PARAMETER__EHFINDER__number_of_generators_phi
#  define CCTK_PARAMETER__EHFINDER__number_of_generators_phi PRIVATE_EHFINDER_STRUCT.number_of_generators_phi
#endif
#ifndef CCTK_PARAMETER__EHFINDER__number_of_generators_theta
#  define CCTK_PARAMETER__EHFINDER__number_of_generators_theta PRIVATE_EHFINDER_STRUCT.number_of_generators_theta
#endif
#ifndef CCTK_PARAMETER__EHFINDER__re_init_max_iter
#  define CCTK_PARAMETER__EHFINDER__re_init_max_iter PRIVATE_EHFINDER_STRUCT.re_init_max_iter
#endif
#ifndef CCTK_PARAMETER__EHFINDER__re_init_undo
#  define CCTK_PARAMETER__EHFINDER__re_init_undo PRIVATE_EHFINDER_STRUCT.re_init_undo
#endif
#ifndef CCTK_PARAMETER__EHFINDER__re_init_verbose
#  define CCTK_PARAMETER__EHFINDER__re_init_verbose PRIVATE_EHFINDER_STRUCT.re_init_verbose
#endif
#ifndef CCTK_PARAMETER__EHFINDER__re_initialize_every
#  define CCTK_PARAMETER__EHFINDER__re_initialize_every PRIVATE_EHFINDER_STRUCT.re_initialize_every
#endif
#ifndef CCTK_PARAMETER__EHFINDER__read_conformal_factor_once
#  define CCTK_PARAMETER__EHFINDER__read_conformal_factor_once PRIVATE_EHFINDER_STRUCT.read_conformal_factor_once
#endif
#ifndef CCTK_PARAMETER__EHFINDER__saved_iteration_every
#  define CCTK_PARAMETER__EHFINDER__saved_iteration_every PRIVATE_EHFINDER_STRUCT.saved_iteration_every
#endif
#ifndef CCTK_PARAMETER__EHFINDER__surface_interpolation_order
#  define CCTK_PARAMETER__EHFINDER__surface_interpolation_order PRIVATE_EHFINDER_STRUCT.surface_interpolation_order
#endif
#ifndef CCTK_PARAMETER__EHFINDER__use_inner_excision
#  define CCTK_PARAMETER__EHFINDER__use_inner_excision PRIVATE_EHFINDER_STRUCT.use_inner_excision
#endif
#ifndef CCTK_PARAMETER__EHFINDER__use_outer_excision
#  define CCTK_PARAMETER__EHFINDER__use_outer_excision PRIVATE_EHFINDER_STRUCT.use_outer_excision
#endif
#ifndef CCTK_PARAMETER__EHFINDER__use_user_center
#  define CCTK_PARAMETER__EHFINDER__use_user_center PRIVATE_EHFINDER_STRUCT.use_user_center
#endif

