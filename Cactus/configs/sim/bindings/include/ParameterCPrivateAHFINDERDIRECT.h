#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL ILUCG__error_tolerance;
  CCTK_REAL Jacobian_perturbation_amplitude;
  CCTK_REAL Theta_norm_for_convergence;
  CCTK_REAL desired_value[101];
  CCTK_REAL desired_value_factor[101];
  CCTK_REAL desired_value_offset[101];
  CCTK_REAL dont_find_after_individual_time[101];
  CCTK_REAL find_after_individual_time[101];
  CCTK_REAL geometry__Schwarzschild_EF__Delta_xyz;
  CCTK_REAL geometry__Schwarzschild_EF__epsilon;
  CCTK_REAL geometry__Schwarzschild_EF__mass;
  CCTK_REAL geometry__Schwarzschild_EF__x_posn;
  CCTK_REAL geometry__Schwarzschild_EF__y_posn;
  CCTK_REAL geometry__Schwarzschild_EF__z_posn;
  CCTK_REAL initial_guess__Kerr_KerrSchild__mass[101];
  CCTK_REAL initial_guess__Kerr_KerrSchild__spin[101];
  CCTK_REAL initial_guess__Kerr_KerrSchild__x_posn[101];
  CCTK_REAL initial_guess__Kerr_KerrSchild__y_posn[101];
  CCTK_REAL initial_guess__Kerr_KerrSchild__z_posn[101];
  CCTK_REAL initial_guess__Kerr_Kerr__mass[101];
  CCTK_REAL initial_guess__Kerr_Kerr__spin[101];
  CCTK_REAL initial_guess__Kerr_Kerr__x_posn[101];
  CCTK_REAL initial_guess__Kerr_Kerr__y_posn[101];
  CCTK_REAL initial_guess__Kerr_Kerr__z_posn[101];
  CCTK_REAL initial_guess__coord_ellipsoid__x_center[101];
  CCTK_REAL initial_guess__coord_ellipsoid__x_radius[101];
  CCTK_REAL initial_guess__coord_ellipsoid__y_center[101];
  CCTK_REAL initial_guess__coord_ellipsoid__y_radius[101];
  CCTK_REAL initial_guess__coord_ellipsoid__z_center[101];
  CCTK_REAL initial_guess__coord_ellipsoid__z_radius[101];
  CCTK_REAL initial_guess__coord_sphere__radius[101];
  CCTK_REAL initial_guess__coord_sphere__x_center[101];
  CCTK_REAL initial_guess__coord_sphere__y_center[101];
  CCTK_REAL initial_guess__coord_sphere__z_center[101];
  CCTK_REAL mask_buffer_thickness;
  CCTK_REAL mask_radius_multiplier;
  CCTK_REAL mask_radius_offset;
  CCTK_REAL max_allowable_Delta_h_over_h;
  CCTK_REAL max_allowable_Theta;
  CCTK_REAL max_allowable_horizon_radius[101];
  CCTK_REAL min_horizon_radius_points_for_mask;
  CCTK_REAL old_style_mask_buffer_value;
  CCTK_REAL old_style_mask_inside_value;
  CCTK_REAL old_style_mask_outside_value;
  CCTK_REAL origin_x[101];
  CCTK_REAL origin_y[101];
  CCTK_REAL origin_z[101];
  CCTK_REAL pretracking_delta[101];
  CCTK_REAL pretracking_maximum_delta[101];
  CCTK_REAL pretracking_maximum_value[101];
  CCTK_REAL pretracking_minimum_delta[101];
  CCTK_REAL pretracking_minimum_value[101];
  CCTK_REAL pretracking_value[101];
  CCTK_REAL shiftout_factor[101];
  CCTK_REAL smoothing_factor[101];
  const char * ASCII_gnuplot_file_name_extension;
  const char * BH_diagnostics_base_file_name;
  const char * BH_diagnostics_directory;
  const char * BH_diagnostics_file_name_extension;
  const char * Delta_h_base_file_name;
  const char * HDF5_file_name_extension;
  const char * Jacobian_base_file_name;
  const char * Jacobian_compute_method;
  const char * Jacobian_store_solve_method;
  const char * OpenDX_control_file_name_extension;
  const char * Theta_base_file_name;
  const char * coordinate_system_name;
  const char * geometry_interpolator_name;
  const char * geometry_interpolator_pars;
  const char * h_base_file_name;
  const char * h_directory;
  const char * initial_guess__read_from_named_file__file_name[101];
  const char * initial_guess_method[101];
  const char * integral_method;
  const char * interpatch_interpolator_name;
  const char * interpatch_interpolator_pars;
  const char * mean_curvature_base_file_name;
  const char * method;
  const char * new_style_mask_bitfield_name;
  const char * new_style_mask_buffer_value;
  const char * new_style_mask_gridfn_name;
  const char * new_style_mask_inside_value;
  const char * new_style_mask_outside_value;
  const char * old_style_mask_gridfn_name;
  const char * patch_system_type[101];
  const char * surface_definition[101];
  const char * surface_interpolator_name;
  const char * surface_interpolator_pars;
  const char * surface_modification[101];
  const char * surface_selection[101];
  const char * track_origin_source_x[101];
  const char * track_origin_source_y[101];
  const char * track_origin_source_z[101];
  const char * verbose_level;
  const char * which_surface_to_store_info_by_name[101];
  CCTK_INT ILUCG__limit_CG_iterations;
  CCTK_INT N_horizons;
  CCTK_INT N_zones_per_right_angle[101];
  CCTK_INT UMFPACK__N_II_iterations;
  CCTK_INT check_that_geometry_is_finite;
  CCTK_INT check_that_h_is_finite;
  CCTK_INT debugging_output_at_each_Newton_iteration;
  CCTK_INT depends_on[101];
  CCTK_INT disable_horizon[101];
  CCTK_INT dont_find_after_individual[101];
  CCTK_INT find_after_individual[101];
  CCTK_INT find_every;
  CCTK_INT find_every_individual[101];
  CCTK_INT ghost_zone_width;
  CCTK_INT h_min_digits;
  CCTK_INT hardwire_Schwarzschild_EF_geometry;
  CCTK_INT mask_is_noshrink;
  CCTK_INT max_N_zones_per_right_angle;
  CCTK_INT max_Newton_iterations__initial;
  CCTK_INT max_Newton_iterations__subsequent;
  CCTK_INT max_allowable_Theta_growth_iterations;
  CCTK_INT max_allowable_Theta_nonshrink_iterations;
  CCTK_INT move_origins;
  CCTK_INT output_ASCII_files;
  CCTK_INT output_BH_diagnostics;
  CCTK_INT output_HDF5_files;
  CCTK_INT output_OpenDX_control_files;
  CCTK_INT output_Theta_every;
  CCTK_INT output_ghost_zones_for_h;
  CCTK_INT output_h_every;
  CCTK_INT output_initial_guess;
  CCTK_INT output_mean_curvature_every;
  CCTK_INT patch_overlap_width;
  CCTK_INT predict_origin_movement;
  CCTK_INT pretracking_max_iterations[101];
  CCTK_INT print_timing_stats;
  CCTK_INT reset_horizon_after_not_finding[101];
  CCTK_INT reshape_while_moving;
  CCTK_INT run_at_CCTK_ANALYSIS;
  CCTK_INT run_at_CCTK_POSTINITIAL;
  CCTK_INT run_at_CCTK_POSTPOSTINITIAL;
  CCTK_INT run_at_CCTK_POSTSTEP;
  CCTK_INT run_at_CCTK_POST_RECOVER_VARIABLES;
  CCTK_INT set_mask_for_all_horizons;
  CCTK_INT set_mask_for_individual_horizon[101];
  CCTK_INT set_new_style_mask;
  CCTK_INT set_old_style_mask;
  CCTK_INT test_all_Jacobian_compute_methods;
  CCTK_INT track_origin_from_grid_scalar[101];
  CCTK_INT use_pretracking[101];
  CCTK_INT want_expansion_gradients;
  CCTK_INT warn_level__gij_not_positive_definite__initial;
  CCTK_INT warn_level__gij_not_positive_definite__subsequent;
  CCTK_INT warn_level__nonfinite_geometry;
  CCTK_INT warn_level__point_outside__initial;
  CCTK_INT warn_level__point_outside__subsequent;
  CCTK_INT warn_level__skipping_finite_check;
  CCTK_INT which_horizon_to_announce_centroid;
  CCTK_INT which_surface_to_store_info[101];
} PRIVATE_AHFINDERDIRECT_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_AHFINDERDIRECT_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, ILUCG__error_tolerance, CCTK_PARAMETER__AHFINDERDIRECT__ILUCG__error_tolerance); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Jacobian_perturbation_amplitude, CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_perturbation_amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Theta_norm_for_convergence, CCTK_PARAMETER__AHFINDERDIRECT__Theta_norm_for_convergence); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, desired_value, CCTK_PARAMETER__AHFINDERDIRECT__desired_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, desired_value_factor, CCTK_PARAMETER__AHFINDERDIRECT__desired_value_factor); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, desired_value_offset, CCTK_PARAMETER__AHFINDERDIRECT__desired_value_offset); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, dont_find_after_individual_time, CCTK_PARAMETER__AHFINDERDIRECT__dont_find_after_individual_time); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, find_after_individual_time, CCTK_PARAMETER__AHFINDERDIRECT__find_after_individual_time); \
  CCTK_DECLARE_INIT (CCTK_REAL const, geometry__Schwarzschild_EF__Delta_xyz, CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__Delta_xyz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, geometry__Schwarzschild_EF__epsilon, CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__epsilon); \
  CCTK_DECLARE_INIT (CCTK_REAL const, geometry__Schwarzschild_EF__mass, CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, geometry__Schwarzschild_EF__x_posn, CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__x_posn); \
  CCTK_DECLARE_INIT (CCTK_REAL const, geometry__Schwarzschild_EF__y_posn, CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__y_posn); \
  CCTK_DECLARE_INIT (CCTK_REAL const, geometry__Schwarzschild_EF__z_posn, CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__z_posn); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_KerrSchild__mass, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_KerrSchild__spin, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__spin); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_KerrSchild__x_posn, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__x_posn); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_KerrSchild__y_posn, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__y_posn); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_KerrSchild__z_posn, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__z_posn); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_Kerr__mass, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_Kerr__spin, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__spin); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_Kerr__x_posn, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__x_posn); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_Kerr__y_posn, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__y_posn); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__Kerr_Kerr__z_posn, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__z_posn); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_ellipsoid__x_center, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__x_center); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_ellipsoid__x_radius, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__x_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_ellipsoid__y_center, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__y_center); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_ellipsoid__y_radius, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__y_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_ellipsoid__z_center, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__z_center); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_ellipsoid__z_radius, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__z_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_sphere__radius, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_sphere__x_center, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__x_center); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_sphere__y_center, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__y_center); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_guess__coord_sphere__z_center, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__z_center); \
  CCTK_DECLARE_INIT (CCTK_REAL const, mask_buffer_thickness, CCTK_PARAMETER__AHFINDERDIRECT__mask_buffer_thickness); \
  CCTK_DECLARE_INIT (CCTK_REAL const, mask_radius_multiplier, CCTK_PARAMETER__AHFINDERDIRECT__mask_radius_multiplier); \
  CCTK_DECLARE_INIT (CCTK_REAL const, mask_radius_offset, CCTK_PARAMETER__AHFINDERDIRECT__mask_radius_offset); \
  CCTK_DECLARE_INIT (CCTK_REAL const, max_allowable_Delta_h_over_h, CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Delta_h_over_h); \
  CCTK_DECLARE_INIT (CCTK_REAL const, max_allowable_Theta, CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Theta); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, max_allowable_horizon_radius, CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_horizon_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, min_horizon_radius_points_for_mask, CCTK_PARAMETER__AHFINDERDIRECT__min_horizon_radius_points_for_mask); \
  CCTK_DECLARE_INIT (CCTK_REAL const, old_style_mask_buffer_value, CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_buffer_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const, old_style_mask_inside_value, CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_inside_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const, old_style_mask_outside_value, CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_outside_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, origin_x, CCTK_PARAMETER__AHFINDERDIRECT__origin_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, origin_y, CCTK_PARAMETER__AHFINDERDIRECT__origin_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, origin_z, CCTK_PARAMETER__AHFINDERDIRECT__origin_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, pretracking_delta, CCTK_PARAMETER__AHFINDERDIRECT__pretracking_delta); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, pretracking_maximum_delta, CCTK_PARAMETER__AHFINDERDIRECT__pretracking_maximum_delta); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, pretracking_maximum_value, CCTK_PARAMETER__AHFINDERDIRECT__pretracking_maximum_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, pretracking_minimum_delta, CCTK_PARAMETER__AHFINDERDIRECT__pretracking_minimum_delta); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, pretracking_minimum_value, CCTK_PARAMETER__AHFINDERDIRECT__pretracking_minimum_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, pretracking_value, CCTK_PARAMETER__AHFINDERDIRECT__pretracking_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, shiftout_factor, CCTK_PARAMETER__AHFINDERDIRECT__shiftout_factor); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, smoothing_factor, CCTK_PARAMETER__AHFINDERDIRECT__smoothing_factor); \
  CCTK_DECLARE_INIT (const char * const, ASCII_gnuplot_file_name_extension, CCTK_PARAMETER__AHFINDERDIRECT__ASCII_gnuplot_file_name_extension); \
  CCTK_DECLARE_INIT (const char * const, BH_diagnostics_base_file_name, CCTK_PARAMETER__AHFINDERDIRECT__BH_diagnostics_base_file_name); \
  CCTK_DECLARE_INIT (const char * const, BH_diagnostics_directory, CCTK_PARAMETER__AHFINDERDIRECT__BH_diagnostics_directory); \
  CCTK_DECLARE_INIT (const char * const, BH_diagnostics_file_name_extension, CCTK_PARAMETER__AHFINDERDIRECT__BH_diagnostics_file_name_extension); \
  CCTK_DECLARE_INIT (const char * const, Delta_h_base_file_name, CCTK_PARAMETER__AHFINDERDIRECT__Delta_h_base_file_name); \
  CCTK_DECLARE_INIT (const char * const, HDF5_file_name_extension, CCTK_PARAMETER__AHFINDERDIRECT__HDF5_file_name_extension); \
  CCTK_DECLARE_INIT (const char * const, Jacobian_base_file_name, CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_base_file_name); \
  CCTK_DECLARE_INIT (const char * const, Jacobian_compute_method, CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_compute_method); \
  CCTK_DECLARE_INIT (const char * const, Jacobian_store_solve_method, CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_store_solve_method); \
  CCTK_DECLARE_INIT (const char * const, OpenDX_control_file_name_extension, CCTK_PARAMETER__AHFINDERDIRECT__OpenDX_control_file_name_extension); \
  CCTK_DECLARE_INIT (const char * const, Theta_base_file_name, CCTK_PARAMETER__AHFINDERDIRECT__Theta_base_file_name); \
  CCTK_DECLARE_INIT (const char * const, coordinate_system_name, CCTK_PARAMETER__AHFINDERDIRECT__coordinate_system_name); \
  CCTK_DECLARE_INIT (const char * const, geometry_interpolator_name, CCTK_PARAMETER__AHFINDERDIRECT__geometry_interpolator_name); \
  CCTK_DECLARE_INIT (const char * const, geometry_interpolator_pars, CCTK_PARAMETER__AHFINDERDIRECT__geometry_interpolator_pars); \
  CCTK_DECLARE_INIT (const char * const, h_base_file_name, CCTK_PARAMETER__AHFINDERDIRECT__h_base_file_name); \
  CCTK_DECLARE_INIT (const char * const, h_directory, CCTK_PARAMETER__AHFINDERDIRECT__h_directory); \
  CCTK_DECLARE_INIT (const char * const * const, initial_guess__read_from_named_file__file_name, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__read_from_named_file__file_name); \
  CCTK_DECLARE_INIT (const char * const * const, initial_guess_method, CCTK_PARAMETER__AHFINDERDIRECT__initial_guess_method); \
  CCTK_DECLARE_INIT (const char * const, integral_method, CCTK_PARAMETER__AHFINDERDIRECT__integral_method); \
  CCTK_DECLARE_INIT (const char * const, interpatch_interpolator_name, CCTK_PARAMETER__AHFINDERDIRECT__interpatch_interpolator_name); \
  CCTK_DECLARE_INIT (const char * const, interpatch_interpolator_pars, CCTK_PARAMETER__AHFINDERDIRECT__interpatch_interpolator_pars); \
  CCTK_DECLARE_INIT (const char * const, mean_curvature_base_file_name, CCTK_PARAMETER__AHFINDERDIRECT__mean_curvature_base_file_name); \
  CCTK_DECLARE_INIT (const char * const, method, CCTK_PARAMETER__AHFINDERDIRECT__method); \
  CCTK_DECLARE_INIT (const char * const, new_style_mask_bitfield_name, CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_bitfield_name); \
  CCTK_DECLARE_INIT (const char * const, new_style_mask_buffer_value, CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_buffer_value); \
  CCTK_DECLARE_INIT (const char * const, new_style_mask_gridfn_name, CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_gridfn_name); \
  CCTK_DECLARE_INIT (const char * const, new_style_mask_inside_value, CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_inside_value); \
  CCTK_DECLARE_INIT (const char * const, new_style_mask_outside_value, CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_outside_value); \
  CCTK_DECLARE_INIT (const char * const, old_style_mask_gridfn_name, CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_gridfn_name); \
  CCTK_DECLARE_INIT (const char * const * const, patch_system_type, CCTK_PARAMETER__AHFINDERDIRECT__patch_system_type); \
  CCTK_DECLARE_INIT (const char * const * const, surface_definition, CCTK_PARAMETER__AHFINDERDIRECT__surface_definition); \
  CCTK_DECLARE_INIT (const char * const, surface_interpolator_name, CCTK_PARAMETER__AHFINDERDIRECT__surface_interpolator_name); \
  CCTK_DECLARE_INIT (const char * const, surface_interpolator_pars, CCTK_PARAMETER__AHFINDERDIRECT__surface_interpolator_pars); \
  CCTK_DECLARE_INIT (const char * const * const, surface_modification, CCTK_PARAMETER__AHFINDERDIRECT__surface_modification); \
  CCTK_DECLARE_INIT (const char * const * const, surface_selection, CCTK_PARAMETER__AHFINDERDIRECT__surface_selection); \
  CCTK_DECLARE_INIT (const char * const * const, track_origin_source_x, CCTK_PARAMETER__AHFINDERDIRECT__track_origin_source_x); \
  CCTK_DECLARE_INIT (const char * const * const, track_origin_source_y, CCTK_PARAMETER__AHFINDERDIRECT__track_origin_source_y); \
  CCTK_DECLARE_INIT (const char * const * const, track_origin_source_z, CCTK_PARAMETER__AHFINDERDIRECT__track_origin_source_z); \
  CCTK_DECLARE_INIT (const char * const, verbose_level, CCTK_PARAMETER__AHFINDERDIRECT__verbose_level); \
  CCTK_DECLARE_INIT (const char * const * const, which_surface_to_store_info_by_name, CCTK_PARAMETER__AHFINDERDIRECT__which_surface_to_store_info_by_name); \
  CCTK_DECLARE_INIT (CCTK_INT const, ILUCG__limit_CG_iterations, CCTK_PARAMETER__AHFINDERDIRECT__ILUCG__limit_CG_iterations); \
  CCTK_DECLARE_INIT (CCTK_INT const, N_horizons, CCTK_PARAMETER__AHFINDERDIRECT__N_horizons); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, N_zones_per_right_angle, CCTK_PARAMETER__AHFINDERDIRECT__N_zones_per_right_angle); \
  CCTK_DECLARE_INIT (CCTK_INT const, UMFPACK__N_II_iterations, CCTK_PARAMETER__AHFINDERDIRECT__UMFPACK__N_II_iterations); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_that_geometry_is_finite, CCTK_PARAMETER__AHFINDERDIRECT__check_that_geometry_is_finite); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_that_h_is_finite, CCTK_PARAMETER__AHFINDERDIRECT__check_that_h_is_finite); \
  CCTK_DECLARE_INIT (CCTK_INT const, debugging_output_at_each_Newton_iteration, CCTK_PARAMETER__AHFINDERDIRECT__debugging_output_at_each_Newton_iteration); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, depends_on, CCTK_PARAMETER__AHFINDERDIRECT__depends_on); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, disable_horizon, CCTK_PARAMETER__AHFINDERDIRECT__disable_horizon); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, dont_find_after_individual, CCTK_PARAMETER__AHFINDERDIRECT__dont_find_after_individual); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, find_after_individual, CCTK_PARAMETER__AHFINDERDIRECT__find_after_individual); \
  CCTK_DECLARE_INIT (CCTK_INT const, find_every, CCTK_PARAMETER__AHFINDERDIRECT__find_every); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, find_every_individual, CCTK_PARAMETER__AHFINDERDIRECT__find_every_individual); \
  CCTK_DECLARE_INIT (CCTK_INT const, ghost_zone_width, CCTK_PARAMETER__AHFINDERDIRECT__ghost_zone_width); \
  CCTK_DECLARE_INIT (CCTK_INT const, h_min_digits, CCTK_PARAMETER__AHFINDERDIRECT__h_min_digits); \
  CCTK_DECLARE_INIT (CCTK_INT const, hardwire_Schwarzschild_EF_geometry, CCTK_PARAMETER__AHFINDERDIRECT__hardwire_Schwarzschild_EF_geometry); \
  CCTK_DECLARE_INIT (CCTK_INT const, mask_is_noshrink, CCTK_PARAMETER__AHFINDERDIRECT__mask_is_noshrink); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_N_zones_per_right_angle, CCTK_PARAMETER__AHFINDERDIRECT__max_N_zones_per_right_angle); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_Newton_iterations__initial, CCTK_PARAMETER__AHFINDERDIRECT__max_Newton_iterations__initial); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_Newton_iterations__subsequent, CCTK_PARAMETER__AHFINDERDIRECT__max_Newton_iterations__subsequent); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_allowable_Theta_growth_iterations, CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Theta_growth_iterations); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_allowable_Theta_nonshrink_iterations, CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Theta_nonshrink_iterations); \
  CCTK_DECLARE_INIT (CCTK_INT const, move_origins, CCTK_PARAMETER__AHFINDERDIRECT__move_origins); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_ASCII_files, CCTK_PARAMETER__AHFINDERDIRECT__output_ASCII_files); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_BH_diagnostics, CCTK_PARAMETER__AHFINDERDIRECT__output_BH_diagnostics); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_HDF5_files, CCTK_PARAMETER__AHFINDERDIRECT__output_HDF5_files); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_OpenDX_control_files, CCTK_PARAMETER__AHFINDERDIRECT__output_OpenDX_control_files); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_Theta_every, CCTK_PARAMETER__AHFINDERDIRECT__output_Theta_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_ghost_zones_for_h, CCTK_PARAMETER__AHFINDERDIRECT__output_ghost_zones_for_h); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_h_every, CCTK_PARAMETER__AHFINDERDIRECT__output_h_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_initial_guess, CCTK_PARAMETER__AHFINDERDIRECT__output_initial_guess); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_mean_curvature_every, CCTK_PARAMETER__AHFINDERDIRECT__output_mean_curvature_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, patch_overlap_width, CCTK_PARAMETER__AHFINDERDIRECT__patch_overlap_width); \
  CCTK_DECLARE_INIT (CCTK_INT const, predict_origin_movement, CCTK_PARAMETER__AHFINDERDIRECT__predict_origin_movement); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, pretracking_max_iterations, CCTK_PARAMETER__AHFINDERDIRECT__pretracking_max_iterations); \
  CCTK_DECLARE_INIT (CCTK_INT const, print_timing_stats, CCTK_PARAMETER__AHFINDERDIRECT__print_timing_stats); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, reset_horizon_after_not_finding, CCTK_PARAMETER__AHFINDERDIRECT__reset_horizon_after_not_finding); \
  CCTK_DECLARE_INIT (CCTK_INT const, reshape_while_moving, CCTK_PARAMETER__AHFINDERDIRECT__reshape_while_moving); \
  CCTK_DECLARE_INIT (CCTK_INT const, run_at_CCTK_ANALYSIS, CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_ANALYSIS); \
  CCTK_DECLARE_INIT (CCTK_INT const, run_at_CCTK_POSTINITIAL, CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POSTINITIAL); \
  CCTK_DECLARE_INIT (CCTK_INT const, run_at_CCTK_POSTPOSTINITIAL, CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POSTPOSTINITIAL); \
  CCTK_DECLARE_INIT (CCTK_INT const, run_at_CCTK_POSTSTEP, CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POSTSTEP); \
  CCTK_DECLARE_INIT (CCTK_INT const, run_at_CCTK_POST_RECOVER_VARIABLES, CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POST_RECOVER_VARIABLES); \
  CCTK_DECLARE_INIT (CCTK_INT const, set_mask_for_all_horizons, CCTK_PARAMETER__AHFINDERDIRECT__set_mask_for_all_horizons); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, set_mask_for_individual_horizon, CCTK_PARAMETER__AHFINDERDIRECT__set_mask_for_individual_horizon); \
  CCTK_DECLARE_INIT (CCTK_INT const, set_new_style_mask, CCTK_PARAMETER__AHFINDERDIRECT__set_new_style_mask); \
  CCTK_DECLARE_INIT (CCTK_INT const, set_old_style_mask, CCTK_PARAMETER__AHFINDERDIRECT__set_old_style_mask); \
  CCTK_DECLARE_INIT (CCTK_INT const, test_all_Jacobian_compute_methods, CCTK_PARAMETER__AHFINDERDIRECT__test_all_Jacobian_compute_methods); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, track_origin_from_grid_scalar, CCTK_PARAMETER__AHFINDERDIRECT__track_origin_from_grid_scalar); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, use_pretracking, CCTK_PARAMETER__AHFINDERDIRECT__use_pretracking); \
  CCTK_DECLARE_INIT (CCTK_INT const, want_expansion_gradients, CCTK_PARAMETER__AHFINDERDIRECT__want_expansion_gradients); \
  CCTK_DECLARE_INIT (CCTK_INT const, warn_level__gij_not_positive_definite__initial, CCTK_PARAMETER__AHFINDERDIRECT__warn_level__gij_not_positive_definite__initial); \
  CCTK_DECLARE_INIT (CCTK_INT const, warn_level__gij_not_positive_definite__subsequent, CCTK_PARAMETER__AHFINDERDIRECT__warn_level__gij_not_positive_definite__subsequent); \
  CCTK_DECLARE_INIT (CCTK_INT const, warn_level__nonfinite_geometry, CCTK_PARAMETER__AHFINDERDIRECT__warn_level__nonfinite_geometry); \
  CCTK_DECLARE_INIT (CCTK_INT const, warn_level__point_outside__initial, CCTK_PARAMETER__AHFINDERDIRECT__warn_level__point_outside__initial); \
  CCTK_DECLARE_INIT (CCTK_INT const, warn_level__point_outside__subsequent, CCTK_PARAMETER__AHFINDERDIRECT__warn_level__point_outside__subsequent); \
  CCTK_DECLARE_INIT (CCTK_INT const, warn_level__skipping_finite_check, CCTK_PARAMETER__AHFINDERDIRECT__warn_level__skipping_finite_check); \
  CCTK_DECLARE_INIT (CCTK_INT const, which_horizon_to_announce_centroid, CCTK_PARAMETER__AHFINDERDIRECT__which_horizon_to_announce_centroid); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, which_surface_to_store_info, CCTK_PARAMETER__AHFINDERDIRECT__which_surface_to_store_info); \


#ifndef CCTK_PARAMETER__AHFINDERDIRECT__ILUCG__error_tolerance
#  define CCTK_PARAMETER__AHFINDERDIRECT__ILUCG__error_tolerance PRIVATE_AHFINDERDIRECT_STRUCT.ILUCG__error_tolerance
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_perturbation_amplitude
#  define CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_perturbation_amplitude PRIVATE_AHFINDERDIRECT_STRUCT.Jacobian_perturbation_amplitude
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__Theta_norm_for_convergence
#  define CCTK_PARAMETER__AHFINDERDIRECT__Theta_norm_for_convergence PRIVATE_AHFINDERDIRECT_STRUCT.Theta_norm_for_convergence
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__desired_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__desired_value PRIVATE_AHFINDERDIRECT_STRUCT.desired_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__desired_value_factor
#  define CCTK_PARAMETER__AHFINDERDIRECT__desired_value_factor PRIVATE_AHFINDERDIRECT_STRUCT.desired_value_factor
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__desired_value_offset
#  define CCTK_PARAMETER__AHFINDERDIRECT__desired_value_offset PRIVATE_AHFINDERDIRECT_STRUCT.desired_value_offset
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__dont_find_after_individual_time
#  define CCTK_PARAMETER__AHFINDERDIRECT__dont_find_after_individual_time PRIVATE_AHFINDERDIRECT_STRUCT.dont_find_after_individual_time
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__find_after_individual_time
#  define CCTK_PARAMETER__AHFINDERDIRECT__find_after_individual_time PRIVATE_AHFINDERDIRECT_STRUCT.find_after_individual_time
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__Delta_xyz
#  define CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__Delta_xyz PRIVATE_AHFINDERDIRECT_STRUCT.geometry__Schwarzschild_EF__Delta_xyz
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__epsilon
#  define CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__epsilon PRIVATE_AHFINDERDIRECT_STRUCT.geometry__Schwarzschild_EF__epsilon
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__mass
#  define CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__mass PRIVATE_AHFINDERDIRECT_STRUCT.geometry__Schwarzschild_EF__mass
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__x_posn
#  define CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__x_posn PRIVATE_AHFINDERDIRECT_STRUCT.geometry__Schwarzschild_EF__x_posn
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__y_posn
#  define CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__y_posn PRIVATE_AHFINDERDIRECT_STRUCT.geometry__Schwarzschild_EF__y_posn
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__z_posn
#  define CCTK_PARAMETER__AHFINDERDIRECT__geometry__Schwarzschild_EF__z_posn PRIVATE_AHFINDERDIRECT_STRUCT.geometry__Schwarzschild_EF__z_posn
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__mass
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__mass PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_KerrSchild__mass
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__spin
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__spin PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_KerrSchild__spin
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__x_posn
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__x_posn PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_KerrSchild__x_posn
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__y_posn
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__y_posn PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_KerrSchild__y_posn
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__z_posn
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_KerrSchild__z_posn PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_KerrSchild__z_posn
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__mass
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__mass PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_Kerr__mass
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__spin
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__spin PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_Kerr__spin
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__x_posn
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__x_posn PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_Kerr__x_posn
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__y_posn
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__y_posn PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_Kerr__y_posn
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__z_posn
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__Kerr_Kerr__z_posn PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__Kerr_Kerr__z_posn
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__x_center
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__x_center PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_ellipsoid__x_center
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__x_radius
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__x_radius PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_ellipsoid__x_radius
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__y_center
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__y_center PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_ellipsoid__y_center
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__y_radius
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__y_radius PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_ellipsoid__y_radius
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__z_center
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__z_center PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_ellipsoid__z_center
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__z_radius
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_ellipsoid__z_radius PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_ellipsoid__z_radius
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__radius
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__radius PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_sphere__radius
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__x_center
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__x_center PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_sphere__x_center
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__y_center
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__y_center PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_sphere__y_center
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__z_center
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__coord_sphere__z_center PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__coord_sphere__z_center
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__mask_buffer_thickness
#  define CCTK_PARAMETER__AHFINDERDIRECT__mask_buffer_thickness PRIVATE_AHFINDERDIRECT_STRUCT.mask_buffer_thickness
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__mask_radius_multiplier
#  define CCTK_PARAMETER__AHFINDERDIRECT__mask_radius_multiplier PRIVATE_AHFINDERDIRECT_STRUCT.mask_radius_multiplier
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__mask_radius_offset
#  define CCTK_PARAMETER__AHFINDERDIRECT__mask_radius_offset PRIVATE_AHFINDERDIRECT_STRUCT.mask_radius_offset
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Delta_h_over_h
#  define CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Delta_h_over_h PRIVATE_AHFINDERDIRECT_STRUCT.max_allowable_Delta_h_over_h
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Theta
#  define CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Theta PRIVATE_AHFINDERDIRECT_STRUCT.max_allowable_Theta
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_horizon_radius
#  define CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_horizon_radius PRIVATE_AHFINDERDIRECT_STRUCT.max_allowable_horizon_radius
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__min_horizon_radius_points_for_mask
#  define CCTK_PARAMETER__AHFINDERDIRECT__min_horizon_radius_points_for_mask PRIVATE_AHFINDERDIRECT_STRUCT.min_horizon_radius_points_for_mask
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_buffer_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_buffer_value PRIVATE_AHFINDERDIRECT_STRUCT.old_style_mask_buffer_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_inside_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_inside_value PRIVATE_AHFINDERDIRECT_STRUCT.old_style_mask_inside_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_outside_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_outside_value PRIVATE_AHFINDERDIRECT_STRUCT.old_style_mask_outside_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__origin_x
#  define CCTK_PARAMETER__AHFINDERDIRECT__origin_x PRIVATE_AHFINDERDIRECT_STRUCT.origin_x
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__origin_y
#  define CCTK_PARAMETER__AHFINDERDIRECT__origin_y PRIVATE_AHFINDERDIRECT_STRUCT.origin_y
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__origin_z
#  define CCTK_PARAMETER__AHFINDERDIRECT__origin_z PRIVATE_AHFINDERDIRECT_STRUCT.origin_z
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__pretracking_delta
#  define CCTK_PARAMETER__AHFINDERDIRECT__pretracking_delta PRIVATE_AHFINDERDIRECT_STRUCT.pretracking_delta
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__pretracking_maximum_delta
#  define CCTK_PARAMETER__AHFINDERDIRECT__pretracking_maximum_delta PRIVATE_AHFINDERDIRECT_STRUCT.pretracking_maximum_delta
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__pretracking_maximum_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__pretracking_maximum_value PRIVATE_AHFINDERDIRECT_STRUCT.pretracking_maximum_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__pretracking_minimum_delta
#  define CCTK_PARAMETER__AHFINDERDIRECT__pretracking_minimum_delta PRIVATE_AHFINDERDIRECT_STRUCT.pretracking_minimum_delta
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__pretracking_minimum_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__pretracking_minimum_value PRIVATE_AHFINDERDIRECT_STRUCT.pretracking_minimum_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__pretracking_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__pretracking_value PRIVATE_AHFINDERDIRECT_STRUCT.pretracking_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__shiftout_factor
#  define CCTK_PARAMETER__AHFINDERDIRECT__shiftout_factor PRIVATE_AHFINDERDIRECT_STRUCT.shiftout_factor
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__smoothing_factor
#  define CCTK_PARAMETER__AHFINDERDIRECT__smoothing_factor PRIVATE_AHFINDERDIRECT_STRUCT.smoothing_factor
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__ASCII_gnuplot_file_name_extension
#  define CCTK_PARAMETER__AHFINDERDIRECT__ASCII_gnuplot_file_name_extension PRIVATE_AHFINDERDIRECT_STRUCT.ASCII_gnuplot_file_name_extension
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__BH_diagnostics_base_file_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__BH_diagnostics_base_file_name PRIVATE_AHFINDERDIRECT_STRUCT.BH_diagnostics_base_file_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__BH_diagnostics_directory
#  define CCTK_PARAMETER__AHFINDERDIRECT__BH_diagnostics_directory PRIVATE_AHFINDERDIRECT_STRUCT.BH_diagnostics_directory
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__BH_diagnostics_file_name_extension
#  define CCTK_PARAMETER__AHFINDERDIRECT__BH_diagnostics_file_name_extension PRIVATE_AHFINDERDIRECT_STRUCT.BH_diagnostics_file_name_extension
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__Delta_h_base_file_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__Delta_h_base_file_name PRIVATE_AHFINDERDIRECT_STRUCT.Delta_h_base_file_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__HDF5_file_name_extension
#  define CCTK_PARAMETER__AHFINDERDIRECT__HDF5_file_name_extension PRIVATE_AHFINDERDIRECT_STRUCT.HDF5_file_name_extension
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_base_file_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_base_file_name PRIVATE_AHFINDERDIRECT_STRUCT.Jacobian_base_file_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_compute_method
#  define CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_compute_method PRIVATE_AHFINDERDIRECT_STRUCT.Jacobian_compute_method
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_store_solve_method
#  define CCTK_PARAMETER__AHFINDERDIRECT__Jacobian_store_solve_method PRIVATE_AHFINDERDIRECT_STRUCT.Jacobian_store_solve_method
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__OpenDX_control_file_name_extension
#  define CCTK_PARAMETER__AHFINDERDIRECT__OpenDX_control_file_name_extension PRIVATE_AHFINDERDIRECT_STRUCT.OpenDX_control_file_name_extension
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__Theta_base_file_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__Theta_base_file_name PRIVATE_AHFINDERDIRECT_STRUCT.Theta_base_file_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__coordinate_system_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__coordinate_system_name PRIVATE_AHFINDERDIRECT_STRUCT.coordinate_system_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__geometry_interpolator_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__geometry_interpolator_name PRIVATE_AHFINDERDIRECT_STRUCT.geometry_interpolator_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__geometry_interpolator_pars
#  define CCTK_PARAMETER__AHFINDERDIRECT__geometry_interpolator_pars PRIVATE_AHFINDERDIRECT_STRUCT.geometry_interpolator_pars
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__h_base_file_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__h_base_file_name PRIVATE_AHFINDERDIRECT_STRUCT.h_base_file_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__h_directory
#  define CCTK_PARAMETER__AHFINDERDIRECT__h_directory PRIVATE_AHFINDERDIRECT_STRUCT.h_directory
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__read_from_named_file__file_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess__read_from_named_file__file_name PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess__read_from_named_file__file_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__initial_guess_method
#  define CCTK_PARAMETER__AHFINDERDIRECT__initial_guess_method PRIVATE_AHFINDERDIRECT_STRUCT.initial_guess_method
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__integral_method
#  define CCTK_PARAMETER__AHFINDERDIRECT__integral_method PRIVATE_AHFINDERDIRECT_STRUCT.integral_method
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__interpatch_interpolator_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__interpatch_interpolator_name PRIVATE_AHFINDERDIRECT_STRUCT.interpatch_interpolator_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__interpatch_interpolator_pars
#  define CCTK_PARAMETER__AHFINDERDIRECT__interpatch_interpolator_pars PRIVATE_AHFINDERDIRECT_STRUCT.interpatch_interpolator_pars
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__mean_curvature_base_file_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__mean_curvature_base_file_name PRIVATE_AHFINDERDIRECT_STRUCT.mean_curvature_base_file_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__method
#  define CCTK_PARAMETER__AHFINDERDIRECT__method PRIVATE_AHFINDERDIRECT_STRUCT.method
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_bitfield_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_bitfield_name PRIVATE_AHFINDERDIRECT_STRUCT.new_style_mask_bitfield_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_buffer_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_buffer_value PRIVATE_AHFINDERDIRECT_STRUCT.new_style_mask_buffer_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_gridfn_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_gridfn_name PRIVATE_AHFINDERDIRECT_STRUCT.new_style_mask_gridfn_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_inside_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_inside_value PRIVATE_AHFINDERDIRECT_STRUCT.new_style_mask_inside_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_outside_value
#  define CCTK_PARAMETER__AHFINDERDIRECT__new_style_mask_outside_value PRIVATE_AHFINDERDIRECT_STRUCT.new_style_mask_outside_value
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_gridfn_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__old_style_mask_gridfn_name PRIVATE_AHFINDERDIRECT_STRUCT.old_style_mask_gridfn_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__patch_system_type
#  define CCTK_PARAMETER__AHFINDERDIRECT__patch_system_type PRIVATE_AHFINDERDIRECT_STRUCT.patch_system_type
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__surface_definition
#  define CCTK_PARAMETER__AHFINDERDIRECT__surface_definition PRIVATE_AHFINDERDIRECT_STRUCT.surface_definition
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__surface_interpolator_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__surface_interpolator_name PRIVATE_AHFINDERDIRECT_STRUCT.surface_interpolator_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__surface_interpolator_pars
#  define CCTK_PARAMETER__AHFINDERDIRECT__surface_interpolator_pars PRIVATE_AHFINDERDIRECT_STRUCT.surface_interpolator_pars
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__surface_modification
#  define CCTK_PARAMETER__AHFINDERDIRECT__surface_modification PRIVATE_AHFINDERDIRECT_STRUCT.surface_modification
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__surface_selection
#  define CCTK_PARAMETER__AHFINDERDIRECT__surface_selection PRIVATE_AHFINDERDIRECT_STRUCT.surface_selection
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__track_origin_source_x
#  define CCTK_PARAMETER__AHFINDERDIRECT__track_origin_source_x PRIVATE_AHFINDERDIRECT_STRUCT.track_origin_source_x
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__track_origin_source_y
#  define CCTK_PARAMETER__AHFINDERDIRECT__track_origin_source_y PRIVATE_AHFINDERDIRECT_STRUCT.track_origin_source_y
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__track_origin_source_z
#  define CCTK_PARAMETER__AHFINDERDIRECT__track_origin_source_z PRIVATE_AHFINDERDIRECT_STRUCT.track_origin_source_z
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__verbose_level
#  define CCTK_PARAMETER__AHFINDERDIRECT__verbose_level PRIVATE_AHFINDERDIRECT_STRUCT.verbose_level
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__which_surface_to_store_info_by_name
#  define CCTK_PARAMETER__AHFINDERDIRECT__which_surface_to_store_info_by_name PRIVATE_AHFINDERDIRECT_STRUCT.which_surface_to_store_info_by_name
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__ILUCG__limit_CG_iterations
#  define CCTK_PARAMETER__AHFINDERDIRECT__ILUCG__limit_CG_iterations PRIVATE_AHFINDERDIRECT_STRUCT.ILUCG__limit_CG_iterations
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__N_horizons
#  define CCTK_PARAMETER__AHFINDERDIRECT__N_horizons PRIVATE_AHFINDERDIRECT_STRUCT.N_horizons
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__N_zones_per_right_angle
#  define CCTK_PARAMETER__AHFINDERDIRECT__N_zones_per_right_angle PRIVATE_AHFINDERDIRECT_STRUCT.N_zones_per_right_angle
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__UMFPACK__N_II_iterations
#  define CCTK_PARAMETER__AHFINDERDIRECT__UMFPACK__N_II_iterations PRIVATE_AHFINDERDIRECT_STRUCT.UMFPACK__N_II_iterations
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__check_that_geometry_is_finite
#  define CCTK_PARAMETER__AHFINDERDIRECT__check_that_geometry_is_finite PRIVATE_AHFINDERDIRECT_STRUCT.check_that_geometry_is_finite
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__check_that_h_is_finite
#  define CCTK_PARAMETER__AHFINDERDIRECT__check_that_h_is_finite PRIVATE_AHFINDERDIRECT_STRUCT.check_that_h_is_finite
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__debugging_output_at_each_Newton_iteration
#  define CCTK_PARAMETER__AHFINDERDIRECT__debugging_output_at_each_Newton_iteration PRIVATE_AHFINDERDIRECT_STRUCT.debugging_output_at_each_Newton_iteration
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__depends_on
#  define CCTK_PARAMETER__AHFINDERDIRECT__depends_on PRIVATE_AHFINDERDIRECT_STRUCT.depends_on
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__disable_horizon
#  define CCTK_PARAMETER__AHFINDERDIRECT__disable_horizon PRIVATE_AHFINDERDIRECT_STRUCT.disable_horizon
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__dont_find_after_individual
#  define CCTK_PARAMETER__AHFINDERDIRECT__dont_find_after_individual PRIVATE_AHFINDERDIRECT_STRUCT.dont_find_after_individual
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__find_after_individual
#  define CCTK_PARAMETER__AHFINDERDIRECT__find_after_individual PRIVATE_AHFINDERDIRECT_STRUCT.find_after_individual
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__find_every
#  define CCTK_PARAMETER__AHFINDERDIRECT__find_every PRIVATE_AHFINDERDIRECT_STRUCT.find_every
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__find_every_individual
#  define CCTK_PARAMETER__AHFINDERDIRECT__find_every_individual PRIVATE_AHFINDERDIRECT_STRUCT.find_every_individual
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__ghost_zone_width
#  define CCTK_PARAMETER__AHFINDERDIRECT__ghost_zone_width PRIVATE_AHFINDERDIRECT_STRUCT.ghost_zone_width
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__h_min_digits
#  define CCTK_PARAMETER__AHFINDERDIRECT__h_min_digits PRIVATE_AHFINDERDIRECT_STRUCT.h_min_digits
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__hardwire_Schwarzschild_EF_geometry
#  define CCTK_PARAMETER__AHFINDERDIRECT__hardwire_Schwarzschild_EF_geometry PRIVATE_AHFINDERDIRECT_STRUCT.hardwire_Schwarzschild_EF_geometry
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__mask_is_noshrink
#  define CCTK_PARAMETER__AHFINDERDIRECT__mask_is_noshrink PRIVATE_AHFINDERDIRECT_STRUCT.mask_is_noshrink
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__max_N_zones_per_right_angle
#  define CCTK_PARAMETER__AHFINDERDIRECT__max_N_zones_per_right_angle PRIVATE_AHFINDERDIRECT_STRUCT.max_N_zones_per_right_angle
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__max_Newton_iterations__initial
#  define CCTK_PARAMETER__AHFINDERDIRECT__max_Newton_iterations__initial PRIVATE_AHFINDERDIRECT_STRUCT.max_Newton_iterations__initial
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__max_Newton_iterations__subsequent
#  define CCTK_PARAMETER__AHFINDERDIRECT__max_Newton_iterations__subsequent PRIVATE_AHFINDERDIRECT_STRUCT.max_Newton_iterations__subsequent
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Theta_growth_iterations
#  define CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Theta_growth_iterations PRIVATE_AHFINDERDIRECT_STRUCT.max_allowable_Theta_growth_iterations
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Theta_nonshrink_iterations
#  define CCTK_PARAMETER__AHFINDERDIRECT__max_allowable_Theta_nonshrink_iterations PRIVATE_AHFINDERDIRECT_STRUCT.max_allowable_Theta_nonshrink_iterations
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__move_origins
#  define CCTK_PARAMETER__AHFINDERDIRECT__move_origins PRIVATE_AHFINDERDIRECT_STRUCT.move_origins
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__output_ASCII_files
#  define CCTK_PARAMETER__AHFINDERDIRECT__output_ASCII_files PRIVATE_AHFINDERDIRECT_STRUCT.output_ASCII_files
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__output_BH_diagnostics
#  define CCTK_PARAMETER__AHFINDERDIRECT__output_BH_diagnostics PRIVATE_AHFINDERDIRECT_STRUCT.output_BH_diagnostics
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__output_HDF5_files
#  define CCTK_PARAMETER__AHFINDERDIRECT__output_HDF5_files PRIVATE_AHFINDERDIRECT_STRUCT.output_HDF5_files
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__output_OpenDX_control_files
#  define CCTK_PARAMETER__AHFINDERDIRECT__output_OpenDX_control_files PRIVATE_AHFINDERDIRECT_STRUCT.output_OpenDX_control_files
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__output_Theta_every
#  define CCTK_PARAMETER__AHFINDERDIRECT__output_Theta_every PRIVATE_AHFINDERDIRECT_STRUCT.output_Theta_every
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__output_ghost_zones_for_h
#  define CCTK_PARAMETER__AHFINDERDIRECT__output_ghost_zones_for_h PRIVATE_AHFINDERDIRECT_STRUCT.output_ghost_zones_for_h
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__output_h_every
#  define CCTK_PARAMETER__AHFINDERDIRECT__output_h_every PRIVATE_AHFINDERDIRECT_STRUCT.output_h_every
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__output_initial_guess
#  define CCTK_PARAMETER__AHFINDERDIRECT__output_initial_guess PRIVATE_AHFINDERDIRECT_STRUCT.output_initial_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__output_mean_curvature_every
#  define CCTK_PARAMETER__AHFINDERDIRECT__output_mean_curvature_every PRIVATE_AHFINDERDIRECT_STRUCT.output_mean_curvature_every
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__patch_overlap_width
#  define CCTK_PARAMETER__AHFINDERDIRECT__patch_overlap_width PRIVATE_AHFINDERDIRECT_STRUCT.patch_overlap_width
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__predict_origin_movement
#  define CCTK_PARAMETER__AHFINDERDIRECT__predict_origin_movement PRIVATE_AHFINDERDIRECT_STRUCT.predict_origin_movement
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__pretracking_max_iterations
#  define CCTK_PARAMETER__AHFINDERDIRECT__pretracking_max_iterations PRIVATE_AHFINDERDIRECT_STRUCT.pretracking_max_iterations
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__print_timing_stats
#  define CCTK_PARAMETER__AHFINDERDIRECT__print_timing_stats PRIVATE_AHFINDERDIRECT_STRUCT.print_timing_stats
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__reset_horizon_after_not_finding
#  define CCTK_PARAMETER__AHFINDERDIRECT__reset_horizon_after_not_finding PRIVATE_AHFINDERDIRECT_STRUCT.reset_horizon_after_not_finding
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__reshape_while_moving
#  define CCTK_PARAMETER__AHFINDERDIRECT__reshape_while_moving PRIVATE_AHFINDERDIRECT_STRUCT.reshape_while_moving
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_ANALYSIS
#  define CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_ANALYSIS PRIVATE_AHFINDERDIRECT_STRUCT.run_at_CCTK_ANALYSIS
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POSTINITIAL
#  define CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POSTINITIAL PRIVATE_AHFINDERDIRECT_STRUCT.run_at_CCTK_POSTINITIAL
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POSTPOSTINITIAL
#  define CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POSTPOSTINITIAL PRIVATE_AHFINDERDIRECT_STRUCT.run_at_CCTK_POSTPOSTINITIAL
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POSTSTEP
#  define CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POSTSTEP PRIVATE_AHFINDERDIRECT_STRUCT.run_at_CCTK_POSTSTEP
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POST_RECOVER_VARIABLES
#  define CCTK_PARAMETER__AHFINDERDIRECT__run_at_CCTK_POST_RECOVER_VARIABLES PRIVATE_AHFINDERDIRECT_STRUCT.run_at_CCTK_POST_RECOVER_VARIABLES
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__set_mask_for_all_horizons
#  define CCTK_PARAMETER__AHFINDERDIRECT__set_mask_for_all_horizons PRIVATE_AHFINDERDIRECT_STRUCT.set_mask_for_all_horizons
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__set_mask_for_individual_horizon
#  define CCTK_PARAMETER__AHFINDERDIRECT__set_mask_for_individual_horizon PRIVATE_AHFINDERDIRECT_STRUCT.set_mask_for_individual_horizon
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__set_new_style_mask
#  define CCTK_PARAMETER__AHFINDERDIRECT__set_new_style_mask PRIVATE_AHFINDERDIRECT_STRUCT.set_new_style_mask
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__set_old_style_mask
#  define CCTK_PARAMETER__AHFINDERDIRECT__set_old_style_mask PRIVATE_AHFINDERDIRECT_STRUCT.set_old_style_mask
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__test_all_Jacobian_compute_methods
#  define CCTK_PARAMETER__AHFINDERDIRECT__test_all_Jacobian_compute_methods PRIVATE_AHFINDERDIRECT_STRUCT.test_all_Jacobian_compute_methods
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__track_origin_from_grid_scalar
#  define CCTK_PARAMETER__AHFINDERDIRECT__track_origin_from_grid_scalar PRIVATE_AHFINDERDIRECT_STRUCT.track_origin_from_grid_scalar
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__use_pretracking
#  define CCTK_PARAMETER__AHFINDERDIRECT__use_pretracking PRIVATE_AHFINDERDIRECT_STRUCT.use_pretracking
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__want_expansion_gradients
#  define CCTK_PARAMETER__AHFINDERDIRECT__want_expansion_gradients PRIVATE_AHFINDERDIRECT_STRUCT.want_expansion_gradients
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__warn_level__gij_not_positive_definite__initial
#  define CCTK_PARAMETER__AHFINDERDIRECT__warn_level__gij_not_positive_definite__initial PRIVATE_AHFINDERDIRECT_STRUCT.warn_level__gij_not_positive_definite__initial
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__warn_level__gij_not_positive_definite__subsequent
#  define CCTK_PARAMETER__AHFINDERDIRECT__warn_level__gij_not_positive_definite__subsequent PRIVATE_AHFINDERDIRECT_STRUCT.warn_level__gij_not_positive_definite__subsequent
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__warn_level__nonfinite_geometry
#  define CCTK_PARAMETER__AHFINDERDIRECT__warn_level__nonfinite_geometry PRIVATE_AHFINDERDIRECT_STRUCT.warn_level__nonfinite_geometry
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__warn_level__point_outside__initial
#  define CCTK_PARAMETER__AHFINDERDIRECT__warn_level__point_outside__initial PRIVATE_AHFINDERDIRECT_STRUCT.warn_level__point_outside__initial
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__warn_level__point_outside__subsequent
#  define CCTK_PARAMETER__AHFINDERDIRECT__warn_level__point_outside__subsequent PRIVATE_AHFINDERDIRECT_STRUCT.warn_level__point_outside__subsequent
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__warn_level__skipping_finite_check
#  define CCTK_PARAMETER__AHFINDERDIRECT__warn_level__skipping_finite_check PRIVATE_AHFINDERDIRECT_STRUCT.warn_level__skipping_finite_check
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__which_horizon_to_announce_centroid
#  define CCTK_PARAMETER__AHFINDERDIRECT__which_horizon_to_announce_centroid PRIVATE_AHFINDERDIRECT_STRUCT.which_horizon_to_announce_centroid
#endif
#ifndef CCTK_PARAMETER__AHFINDERDIRECT__which_surface_to_store_info
#  define CCTK_PARAMETER__AHFINDERDIRECT__which_surface_to_store_info PRIVATE_AHFINDERDIRECT_STRUCT.which_surface_to_store_info
#endif

