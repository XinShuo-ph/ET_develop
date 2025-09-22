#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL GRHydro_Y_e_max;
  CCTK_REAL GRHydro_Y_e_min;
  CCTK_REAL GRHydro_atmo_tolerance;
  CCTK_REAL GRHydro_del_ptol;
  CCTK_REAL GRHydro_eos_rf_prec;
  CCTK_REAL GRHydro_eps_min;
  CCTK_REAL GRHydro_hot_atmo_Y_e;
  CCTK_REAL GRHydro_hot_atmo_temp;
  CCTK_REAL GRHydro_lorentz_overshoot_cutoff;
  CCTK_REAL GRHydro_max_temp;
  CCTK_REAL GRHydro_perc_ptol;
  CCTK_REAL GRHydro_rho_central;
  CCTK_REAL Tmunu_damping_radius_max;
  CCTK_REAL Tmunu_damping_radius_min;
  CCTK_REAL atmo_falloff_power;
  CCTK_REAL atmo_falloff_radius;
  CCTK_REAL atmo_tolerance_power;
  CCTK_REAL atmo_tolerance_radius;
  CCTK_REAL c2p_reset_pressure_to_value;
  CCTK_REAL comoving_factor;
  CCTK_REAL comoving_tanh_factor;
  CCTK_REAL comoving_tanh_offset;
  CCTK_REAL enhanced_ppm_C2;
  CCTK_REAL enhanced_ppm_C3;
  CCTK_REAL initial_Gamma;
  CCTK_REAL initial_atmosphere_factor;
  CCTK_REAL initial_k;
  CCTK_REAL initial_rho_abs_min;
  CCTK_REAL initial_rho_rel_min;
  CCTK_REAL kap_dc;
  CCTK_REAL max_magnetic_to_gas_pressure_ratio;
  CCTK_REAL min_tracer;
  CCTK_REAL mp5_alpha;
  CCTK_REAL mp5_eps;
  CCTK_REAL myfloor;
  CCTK_REAL ppm_epsilon;
  CCTK_REAL ppm_epsilon_shock;
  CCTK_REAL ppm_eta1;
  CCTK_REAL ppm_eta2;
  CCTK_REAL ppm_k0;
  CCTK_REAL ppm_omega1;
  CCTK_REAL ppm_omega2;
  CCTK_REAL ppm_omega_tracer;
  CCTK_REAL ppm_small;
  CCTK_REAL rho_abs_min;
  CCTK_REAL rho_abs_min_after_recovery;
  CCTK_REAL rho_rel_min;
  CCTK_REAL setcharmax;
  CCTK_REAL setcharmin;
  CCTK_REAL sqrtdet_thr;
  CCTK_REAL tau_rel_min;
  CCTK_REAL weno_eps;
  const char * Avec_gauge;
  const char * EoS_Change_type;
  const char * GRHydro_c2p_failed_action;
  const char * GRHydro_eos_table;
  const char * GRHydro_eos_type;
  const char * HLLE_type;
  const char * bound;
  const char * comoving_attenuate;
  const char * comoving_v_method;
  const char * gradient_method;
  const char * left_eigenvectors;
  const char * method_type;
  const char * numerical_viscosity;
  const char * particle_interpolator;
  const char * ppm_flatten;
  const char * psidcspeed;
  const char * recon_method;
  const char * recon_vars;
  const char * riemann_solver;
  const char * tvd_limiter;
  const char * use_evolution_mask;
  CCTK_INT Check_Rho_Minimum;
  CCTK_INT EoS_Change;
  CCTK_INT GRHydro_MaxNumConstrainedVars;
  CCTK_INT GRHydro_MaxNumEvolvedVars;
  CCTK_INT GRHydro_MaxNumEvolvedVarsSlow;
  CCTK_INT GRHydro_MaxNumSandRVars;
  CCTK_INT GRHydro_NaN_verbose;
  CCTK_INT GRHydro_c2p_reset_eps_tau_hot_eos;
  CCTK_INT GRHydro_c2p_warn_from_reflevel;
  CCTK_INT GRHydro_c2p_warnlevel;
  CCTK_INT GRHydro_countmax;
  CCTK_INT GRHydro_countmin;
  CCTK_INT GRHydro_enable_internal_excision;
  CCTK_INT GRHydro_eos_hot_eps_fix;
  CCTK_INT GRHydro_eos_hot_prim2con_warn;
  CCTK_INT GRHydro_hydro_excision;
  CCTK_INT GRHydro_oppm_reflevel;
  CCTK_INT GRHydro_polish;
  CCTK_INT GRHydro_stencil;
  CCTK_INT WENO_order;
  CCTK_INT apply_H_viscosity;
  CCTK_INT c2p_reset_pressure;
  CCTK_INT c2p_resort_to_bisection;
  CCTK_INT calculate_bcom;
  CCTK_INT check_for_trivial_rp;
  CCTK_INT clean_divergence;
  CCTK_INT con2prim_oct_hack;
  CCTK_INT decouple_normal_Bfield;
  CCTK_INT eno_order;
  CCTK_INT evolve_tracer;
  CCTK_INT mp5_adaptive_eps;
  CCTK_INT number_of_arrays;
  CCTK_INT number_of_particles;
  CCTK_INT number_of_tracers;
  CCTK_INT particle_interpolation_order;
  CCTK_INT ppm_detect;
  CCTK_INT ppm_mppm;
  CCTK_INT ppm_mppm_debug_eigenvalues;
  CCTK_INT reconstruct_Wv;
  CCTK_INT reconstruct_temper;
  CCTK_INT set_trivial_rp_grid_function;
  CCTK_INT sources_spatial_order;
  CCTK_INT sync_conserved_only;
  CCTK_INT track_divB;
  CCTK_INT transport_constraints;
  CCTK_INT use_MoL_slow_multirate_sector;
  CCTK_INT use_enhanced_ppm;
  CCTK_INT use_min_tracer;
  CCTK_INT use_optimized_ppm;
  CCTK_INT use_weighted_fluxes;
  CCTK_INT weno_adaptive_epsilon;
  CCTK_INT wk_atmosphere;
} RESTRICTED_GRHYDRO_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_GRHYDRO_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_Y_e_max, CCTK_PARAMETER__GRHYDRO__GRHydro_Y_e_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_Y_e_min, CCTK_PARAMETER__GRHYDRO__GRHydro_Y_e_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_atmo_tolerance, CCTK_PARAMETER__GRHYDRO__GRHydro_atmo_tolerance); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_del_ptol, CCTK_PARAMETER__GRHYDRO__GRHydro_del_ptol); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_eos_rf_prec, CCTK_PARAMETER__GRHYDRO__GRHydro_eos_rf_prec); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_eps_min, CCTK_PARAMETER__GRHYDRO__GRHydro_eps_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_hot_atmo_Y_e, CCTK_PARAMETER__GRHYDRO__GRHydro_hot_atmo_Y_e); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_hot_atmo_temp, CCTK_PARAMETER__GRHYDRO__GRHydro_hot_atmo_temp); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_lorentz_overshoot_cutoff, CCTK_PARAMETER__GRHYDRO__GRHydro_lorentz_overshoot_cutoff); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_max_temp, CCTK_PARAMETER__GRHYDRO__GRHydro_max_temp); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_perc_ptol, CCTK_PARAMETER__GRHYDRO__GRHydro_perc_ptol); \
  CCTK_DECLARE_INIT (CCTK_REAL const, GRHydro_rho_central, CCTK_PARAMETER__GRHYDRO__GRHydro_rho_central); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Tmunu_damping_radius_max, CCTK_PARAMETER__GRHYDRO__Tmunu_damping_radius_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Tmunu_damping_radius_min, CCTK_PARAMETER__GRHYDRO__Tmunu_damping_radius_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const, atmo_falloff_power, CCTK_PARAMETER__GRHYDRO__atmo_falloff_power); \
  CCTK_DECLARE_INIT (CCTK_REAL const, atmo_falloff_radius, CCTK_PARAMETER__GRHYDRO__atmo_falloff_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, atmo_tolerance_power, CCTK_PARAMETER__GRHYDRO__atmo_tolerance_power); \
  CCTK_DECLARE_INIT (CCTK_REAL const, atmo_tolerance_radius, CCTK_PARAMETER__GRHYDRO__atmo_tolerance_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, c2p_reset_pressure_to_value, CCTK_PARAMETER__GRHYDRO__c2p_reset_pressure_to_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const, comoving_factor, CCTK_PARAMETER__GRHYDRO__comoving_factor); \
  CCTK_DECLARE_INIT (CCTK_REAL const, comoving_tanh_factor, CCTK_PARAMETER__GRHYDRO__comoving_tanh_factor); \
  CCTK_DECLARE_INIT (CCTK_REAL const, comoving_tanh_offset, CCTK_PARAMETER__GRHYDRO__comoving_tanh_offset); \
  CCTK_DECLARE_INIT (CCTK_REAL const, enhanced_ppm_C2, CCTK_PARAMETER__GRHYDRO__enhanced_ppm_C2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, enhanced_ppm_C3, CCTK_PARAMETER__GRHYDRO__enhanced_ppm_C3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, initial_Gamma, CCTK_PARAMETER__GRHYDRO__initial_Gamma); \
  CCTK_DECLARE_INIT (CCTK_REAL const, initial_atmosphere_factor, CCTK_PARAMETER__GRHYDRO__initial_atmosphere_factor); \
  CCTK_DECLARE_INIT (CCTK_REAL const, initial_k, CCTK_PARAMETER__GRHYDRO__initial_k); \
  CCTK_DECLARE_INIT (CCTK_REAL const, initial_rho_abs_min, CCTK_PARAMETER__GRHYDRO__initial_rho_abs_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const, initial_rho_rel_min, CCTK_PARAMETER__GRHYDRO__initial_rho_rel_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const, kap_dc, CCTK_PARAMETER__GRHYDRO__kap_dc); \
  CCTK_DECLARE_INIT (CCTK_REAL const, max_magnetic_to_gas_pressure_ratio, CCTK_PARAMETER__GRHYDRO__max_magnetic_to_gas_pressure_ratio); \
  CCTK_DECLARE_INIT (CCTK_REAL const, min_tracer, CCTK_PARAMETER__GRHYDRO__min_tracer); \
  CCTK_DECLARE_INIT (CCTK_REAL const, mp5_alpha, CCTK_PARAMETER__GRHYDRO__mp5_alpha); \
  CCTK_DECLARE_INIT (CCTK_REAL const, mp5_eps, CCTK_PARAMETER__GRHYDRO__mp5_eps); \
  CCTK_DECLARE_INIT (CCTK_REAL const, myfloor, CCTK_PARAMETER__GRHYDRO__myfloor); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ppm_epsilon, CCTK_PARAMETER__GRHYDRO__ppm_epsilon); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ppm_epsilon_shock, CCTK_PARAMETER__GRHYDRO__ppm_epsilon_shock); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ppm_eta1, CCTK_PARAMETER__GRHYDRO__ppm_eta1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ppm_eta2, CCTK_PARAMETER__GRHYDRO__ppm_eta2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ppm_k0, CCTK_PARAMETER__GRHYDRO__ppm_k0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ppm_omega1, CCTK_PARAMETER__GRHYDRO__ppm_omega1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ppm_omega2, CCTK_PARAMETER__GRHYDRO__ppm_omega2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ppm_omega_tracer, CCTK_PARAMETER__GRHYDRO__ppm_omega_tracer); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ppm_small, CCTK_PARAMETER__GRHYDRO__ppm_small); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rho_abs_min, CCTK_PARAMETER__GRHYDRO__rho_abs_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rho_abs_min_after_recovery, CCTK_PARAMETER__GRHYDRO__rho_abs_min_after_recovery); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rho_rel_min, CCTK_PARAMETER__GRHYDRO__rho_rel_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const, setcharmax, CCTK_PARAMETER__GRHYDRO__setcharmax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, setcharmin, CCTK_PARAMETER__GRHYDRO__setcharmin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, sqrtdet_thr, CCTK_PARAMETER__GRHYDRO__sqrtdet_thr); \
  CCTK_DECLARE_INIT (CCTK_REAL const, tau_rel_min, CCTK_PARAMETER__GRHYDRO__tau_rel_min); \
  CCTK_DECLARE_INIT (CCTK_REAL const, weno_eps, CCTK_PARAMETER__GRHYDRO__weno_eps); \
  CCTK_DECLARE_INIT (const char * const, Avec_gauge, CCTK_PARAMETER__GRHYDRO__Avec_gauge); \
  CCTK_DECLARE_INIT (const char * const, EoS_Change_type, CCTK_PARAMETER__GRHYDRO__EoS_Change_type); \
  CCTK_DECLARE_INIT (const char * const, GRHydro_c2p_failed_action, CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_failed_action); \
  CCTK_DECLARE_INIT (const char * const, GRHydro_eos_table, CCTK_PARAMETER__GRHYDRO__GRHydro_eos_table); \
  CCTK_DECLARE_INIT (const char * const, GRHydro_eos_type, CCTK_PARAMETER__GRHYDRO__GRHydro_eos_type); \
  CCTK_DECLARE_INIT (const char * const, HLLE_type, CCTK_PARAMETER__GRHYDRO__HLLE_type); \
  CCTK_DECLARE_INIT (const char * const, bound, CCTK_PARAMETER__GRHYDRO__bound); \
  CCTK_DECLARE_INIT (const char * const, comoving_attenuate, CCTK_PARAMETER__GRHYDRO__comoving_attenuate); \
  CCTK_DECLARE_INIT (const char * const, comoving_v_method, CCTK_PARAMETER__GRHYDRO__comoving_v_method); \
  CCTK_DECLARE_INIT (const char * const, gradient_method, CCTK_PARAMETER__GRHYDRO__gradient_method); \
  CCTK_DECLARE_INIT (const char * const, left_eigenvectors, CCTK_PARAMETER__GRHYDRO__left_eigenvectors); \
  CCTK_DECLARE_INIT (const char * const, method_type, CCTK_PARAMETER__GRHYDRO__method_type); \
  CCTK_DECLARE_INIT (const char * const, numerical_viscosity, CCTK_PARAMETER__GRHYDRO__numerical_viscosity); \
  CCTK_DECLARE_INIT (const char * const, particle_interpolator, CCTK_PARAMETER__GRHYDRO__particle_interpolator); \
  CCTK_DECLARE_INIT (const char * const, ppm_flatten, CCTK_PARAMETER__GRHYDRO__ppm_flatten); \
  CCTK_DECLARE_INIT (const char * const, psidcspeed, CCTK_PARAMETER__GRHYDRO__psidcspeed); \
  CCTK_DECLARE_INIT (const char * const, recon_method, CCTK_PARAMETER__GRHYDRO__recon_method); \
  CCTK_DECLARE_INIT (const char * const, recon_vars, CCTK_PARAMETER__GRHYDRO__recon_vars); \
  CCTK_DECLARE_INIT (const char * const, riemann_solver, CCTK_PARAMETER__GRHYDRO__riemann_solver); \
  CCTK_DECLARE_INIT (const char * const, tvd_limiter, CCTK_PARAMETER__GRHYDRO__tvd_limiter); \
  CCTK_DECLARE_INIT (const char * const, use_evolution_mask, CCTK_PARAMETER__GRHYDRO__use_evolution_mask); \
  CCTK_DECLARE_INIT (CCTK_INT const, Check_Rho_Minimum, CCTK_PARAMETER__GRHYDRO__Check_Rho_Minimum); \
  CCTK_DECLARE_INIT (CCTK_INT const, EoS_Change, CCTK_PARAMETER__GRHYDRO__EoS_Change); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_MaxNumConstrainedVars, CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumConstrainedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_MaxNumEvolvedVars, CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_MaxNumEvolvedVarsSlow, CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumEvolvedVarsSlow); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_MaxNumSandRVars, CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumSandRVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_NaN_verbose, CCTK_PARAMETER__GRHYDRO__GRHydro_NaN_verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_c2p_reset_eps_tau_hot_eos, CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_reset_eps_tau_hot_eos); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_c2p_warn_from_reflevel, CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_warn_from_reflevel); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_c2p_warnlevel, CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_warnlevel); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_countmax, CCTK_PARAMETER__GRHYDRO__GRHydro_countmax); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_countmin, CCTK_PARAMETER__GRHYDRO__GRHydro_countmin); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_enable_internal_excision, CCTK_PARAMETER__GRHYDRO__GRHydro_enable_internal_excision); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_eos_hot_eps_fix, CCTK_PARAMETER__GRHYDRO__GRHydro_eos_hot_eps_fix); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_eos_hot_prim2con_warn, CCTK_PARAMETER__GRHYDRO__GRHydro_eos_hot_prim2con_warn); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_hydro_excision, CCTK_PARAMETER__GRHYDRO__GRHydro_hydro_excision); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_oppm_reflevel, CCTK_PARAMETER__GRHYDRO__GRHydro_oppm_reflevel); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_polish, CCTK_PARAMETER__GRHYDRO__GRHydro_polish); \
  CCTK_DECLARE_INIT (CCTK_INT const, GRHydro_stencil, CCTK_PARAMETER__GRHYDRO__GRHydro_stencil); \
  CCTK_DECLARE_INIT (CCTK_INT const, WENO_order, CCTK_PARAMETER__GRHYDRO__WENO_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, apply_H_viscosity, CCTK_PARAMETER__GRHYDRO__apply_H_viscosity); \
  CCTK_DECLARE_INIT (CCTK_INT const, c2p_reset_pressure, CCTK_PARAMETER__GRHYDRO__c2p_reset_pressure); \
  CCTK_DECLARE_INIT (CCTK_INT const, c2p_resort_to_bisection, CCTK_PARAMETER__GRHYDRO__c2p_resort_to_bisection); \
  CCTK_DECLARE_INIT (CCTK_INT const, calculate_bcom, CCTK_PARAMETER__GRHYDRO__calculate_bcom); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_for_trivial_rp, CCTK_PARAMETER__GRHYDRO__check_for_trivial_rp); \
  CCTK_DECLARE_INIT (CCTK_INT const, clean_divergence, CCTK_PARAMETER__GRHYDRO__clean_divergence); \
  CCTK_DECLARE_INIT (CCTK_INT const, con2prim_oct_hack, CCTK_PARAMETER__GRHYDRO__con2prim_oct_hack); \
  CCTK_DECLARE_INIT (CCTK_INT const, decouple_normal_Bfield, CCTK_PARAMETER__GRHYDRO__decouple_normal_Bfield); \
  CCTK_DECLARE_INIT (CCTK_INT const, eno_order, CCTK_PARAMETER__GRHYDRO__eno_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, evolve_tracer, CCTK_PARAMETER__GRHYDRO__evolve_tracer); \
  CCTK_DECLARE_INIT (CCTK_INT const, mp5_adaptive_eps, CCTK_PARAMETER__GRHYDRO__mp5_adaptive_eps); \
  CCTK_DECLARE_INIT (CCTK_INT const, number_of_arrays, CCTK_PARAMETER__GRHYDRO__number_of_arrays); \
  CCTK_DECLARE_INIT (CCTK_INT const, number_of_particles, CCTK_PARAMETER__GRHYDRO__number_of_particles); \
  CCTK_DECLARE_INIT (CCTK_INT const, number_of_tracers, CCTK_PARAMETER__GRHYDRO__number_of_tracers); \
  CCTK_DECLARE_INIT (CCTK_INT const, particle_interpolation_order, CCTK_PARAMETER__GRHYDRO__particle_interpolation_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, ppm_detect, CCTK_PARAMETER__GRHYDRO__ppm_detect); \
  CCTK_DECLARE_INIT (CCTK_INT const, ppm_mppm, CCTK_PARAMETER__GRHYDRO__ppm_mppm); \
  CCTK_DECLARE_INIT (CCTK_INT const, ppm_mppm_debug_eigenvalues, CCTK_PARAMETER__GRHYDRO__ppm_mppm_debug_eigenvalues); \
  CCTK_DECLARE_INIT (CCTK_INT const, reconstruct_Wv, CCTK_PARAMETER__GRHYDRO__reconstruct_Wv); \
  CCTK_DECLARE_INIT (CCTK_INT const, reconstruct_temper, CCTK_PARAMETER__GRHYDRO__reconstruct_temper); \
  CCTK_DECLARE_INIT (CCTK_INT const, set_trivial_rp_grid_function, CCTK_PARAMETER__GRHYDRO__set_trivial_rp_grid_function); \
  CCTK_DECLARE_INIT (CCTK_INT const, sources_spatial_order, CCTK_PARAMETER__GRHYDRO__sources_spatial_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, sync_conserved_only, CCTK_PARAMETER__GRHYDRO__sync_conserved_only); \
  CCTK_DECLARE_INIT (CCTK_INT const, track_divB, CCTK_PARAMETER__GRHYDRO__track_divB); \
  CCTK_DECLARE_INIT (CCTK_INT const, transport_constraints, CCTK_PARAMETER__GRHYDRO__transport_constraints); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_MoL_slow_multirate_sector, CCTK_PARAMETER__GRHYDRO__use_MoL_slow_multirate_sector); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_enhanced_ppm, CCTK_PARAMETER__GRHYDRO__use_enhanced_ppm); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_min_tracer, CCTK_PARAMETER__GRHYDRO__use_min_tracer); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_optimized_ppm, CCTK_PARAMETER__GRHYDRO__use_optimized_ppm); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_weighted_fluxes, CCTK_PARAMETER__GRHYDRO__use_weighted_fluxes); \
  CCTK_DECLARE_INIT (CCTK_INT const, weno_adaptive_epsilon, CCTK_PARAMETER__GRHYDRO__weno_adaptive_epsilon); \
  CCTK_DECLARE_INIT (CCTK_INT const, wk_atmosphere, CCTK_PARAMETER__GRHYDRO__wk_atmosphere); \


#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_Y_e_max
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_Y_e_max RESTRICTED_GRHYDRO_STRUCT.GRHydro_Y_e_max
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_Y_e_min
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_Y_e_min RESTRICTED_GRHYDRO_STRUCT.GRHydro_Y_e_min
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_atmo_tolerance
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_atmo_tolerance RESTRICTED_GRHYDRO_STRUCT.GRHydro_atmo_tolerance
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_del_ptol
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_del_ptol RESTRICTED_GRHYDRO_STRUCT.GRHydro_del_ptol
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_eos_rf_prec
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_eos_rf_prec RESTRICTED_GRHYDRO_STRUCT.GRHydro_eos_rf_prec
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_eps_min
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_eps_min RESTRICTED_GRHYDRO_STRUCT.GRHydro_eps_min
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_hot_atmo_Y_e
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_hot_atmo_Y_e RESTRICTED_GRHYDRO_STRUCT.GRHydro_hot_atmo_Y_e
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_hot_atmo_temp
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_hot_atmo_temp RESTRICTED_GRHYDRO_STRUCT.GRHydro_hot_atmo_temp
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_lorentz_overshoot_cutoff
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_lorentz_overshoot_cutoff RESTRICTED_GRHYDRO_STRUCT.GRHydro_lorentz_overshoot_cutoff
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_max_temp
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_max_temp RESTRICTED_GRHYDRO_STRUCT.GRHydro_max_temp
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_perc_ptol
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_perc_ptol RESTRICTED_GRHYDRO_STRUCT.GRHydro_perc_ptol
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_rho_central
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_rho_central RESTRICTED_GRHYDRO_STRUCT.GRHydro_rho_central
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__Tmunu_damping_radius_max
#  define CCTK_PARAMETER__GRHYDRO__Tmunu_damping_radius_max RESTRICTED_GRHYDRO_STRUCT.Tmunu_damping_radius_max
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__Tmunu_damping_radius_min
#  define CCTK_PARAMETER__GRHYDRO__Tmunu_damping_radius_min RESTRICTED_GRHYDRO_STRUCT.Tmunu_damping_radius_min
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__atmo_falloff_power
#  define CCTK_PARAMETER__GRHYDRO__atmo_falloff_power RESTRICTED_GRHYDRO_STRUCT.atmo_falloff_power
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__atmo_falloff_radius
#  define CCTK_PARAMETER__GRHYDRO__atmo_falloff_radius RESTRICTED_GRHYDRO_STRUCT.atmo_falloff_radius
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__atmo_tolerance_power
#  define CCTK_PARAMETER__GRHYDRO__atmo_tolerance_power RESTRICTED_GRHYDRO_STRUCT.atmo_tolerance_power
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__atmo_tolerance_radius
#  define CCTK_PARAMETER__GRHYDRO__atmo_tolerance_radius RESTRICTED_GRHYDRO_STRUCT.atmo_tolerance_radius
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__c2p_reset_pressure_to_value
#  define CCTK_PARAMETER__GRHYDRO__c2p_reset_pressure_to_value RESTRICTED_GRHYDRO_STRUCT.c2p_reset_pressure_to_value
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__comoving_factor
#  define CCTK_PARAMETER__GRHYDRO__comoving_factor RESTRICTED_GRHYDRO_STRUCT.comoving_factor
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__comoving_tanh_factor
#  define CCTK_PARAMETER__GRHYDRO__comoving_tanh_factor RESTRICTED_GRHYDRO_STRUCT.comoving_tanh_factor
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__comoving_tanh_offset
#  define CCTK_PARAMETER__GRHYDRO__comoving_tanh_offset RESTRICTED_GRHYDRO_STRUCT.comoving_tanh_offset
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__enhanced_ppm_C2
#  define CCTK_PARAMETER__GRHYDRO__enhanced_ppm_C2 RESTRICTED_GRHYDRO_STRUCT.enhanced_ppm_C2
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__enhanced_ppm_C3
#  define CCTK_PARAMETER__GRHYDRO__enhanced_ppm_C3 RESTRICTED_GRHYDRO_STRUCT.enhanced_ppm_C3
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__initial_Gamma
#  define CCTK_PARAMETER__GRHYDRO__initial_Gamma RESTRICTED_GRHYDRO_STRUCT.initial_Gamma
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__initial_atmosphere_factor
#  define CCTK_PARAMETER__GRHYDRO__initial_atmosphere_factor RESTRICTED_GRHYDRO_STRUCT.initial_atmosphere_factor
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__initial_k
#  define CCTK_PARAMETER__GRHYDRO__initial_k RESTRICTED_GRHYDRO_STRUCT.initial_k
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__initial_rho_abs_min
#  define CCTK_PARAMETER__GRHYDRO__initial_rho_abs_min RESTRICTED_GRHYDRO_STRUCT.initial_rho_abs_min
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__initial_rho_rel_min
#  define CCTK_PARAMETER__GRHYDRO__initial_rho_rel_min RESTRICTED_GRHYDRO_STRUCT.initial_rho_rel_min
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__kap_dc
#  define CCTK_PARAMETER__GRHYDRO__kap_dc RESTRICTED_GRHYDRO_STRUCT.kap_dc
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__max_magnetic_to_gas_pressure_ratio
#  define CCTK_PARAMETER__GRHYDRO__max_magnetic_to_gas_pressure_ratio RESTRICTED_GRHYDRO_STRUCT.max_magnetic_to_gas_pressure_ratio
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__min_tracer
#  define CCTK_PARAMETER__GRHYDRO__min_tracer RESTRICTED_GRHYDRO_STRUCT.min_tracer
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__mp5_alpha
#  define CCTK_PARAMETER__GRHYDRO__mp5_alpha RESTRICTED_GRHYDRO_STRUCT.mp5_alpha
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__mp5_eps
#  define CCTK_PARAMETER__GRHYDRO__mp5_eps RESTRICTED_GRHYDRO_STRUCT.mp5_eps
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__myfloor
#  define CCTK_PARAMETER__GRHYDRO__myfloor RESTRICTED_GRHYDRO_STRUCT.myfloor
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_epsilon
#  define CCTK_PARAMETER__GRHYDRO__ppm_epsilon RESTRICTED_GRHYDRO_STRUCT.ppm_epsilon
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_epsilon_shock
#  define CCTK_PARAMETER__GRHYDRO__ppm_epsilon_shock RESTRICTED_GRHYDRO_STRUCT.ppm_epsilon_shock
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_eta1
#  define CCTK_PARAMETER__GRHYDRO__ppm_eta1 RESTRICTED_GRHYDRO_STRUCT.ppm_eta1
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_eta2
#  define CCTK_PARAMETER__GRHYDRO__ppm_eta2 RESTRICTED_GRHYDRO_STRUCT.ppm_eta2
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_k0
#  define CCTK_PARAMETER__GRHYDRO__ppm_k0 RESTRICTED_GRHYDRO_STRUCT.ppm_k0
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_omega1
#  define CCTK_PARAMETER__GRHYDRO__ppm_omega1 RESTRICTED_GRHYDRO_STRUCT.ppm_omega1
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_omega2
#  define CCTK_PARAMETER__GRHYDRO__ppm_omega2 RESTRICTED_GRHYDRO_STRUCT.ppm_omega2
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_omega_tracer
#  define CCTK_PARAMETER__GRHYDRO__ppm_omega_tracer RESTRICTED_GRHYDRO_STRUCT.ppm_omega_tracer
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_small
#  define CCTK_PARAMETER__GRHYDRO__ppm_small RESTRICTED_GRHYDRO_STRUCT.ppm_small
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__rho_abs_min
#  define CCTK_PARAMETER__GRHYDRO__rho_abs_min RESTRICTED_GRHYDRO_STRUCT.rho_abs_min
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__rho_abs_min_after_recovery
#  define CCTK_PARAMETER__GRHYDRO__rho_abs_min_after_recovery RESTRICTED_GRHYDRO_STRUCT.rho_abs_min_after_recovery
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__rho_rel_min
#  define CCTK_PARAMETER__GRHYDRO__rho_rel_min RESTRICTED_GRHYDRO_STRUCT.rho_rel_min
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__setcharmax
#  define CCTK_PARAMETER__GRHYDRO__setcharmax RESTRICTED_GRHYDRO_STRUCT.setcharmax
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__setcharmin
#  define CCTK_PARAMETER__GRHYDRO__setcharmin RESTRICTED_GRHYDRO_STRUCT.setcharmin
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__sqrtdet_thr
#  define CCTK_PARAMETER__GRHYDRO__sqrtdet_thr RESTRICTED_GRHYDRO_STRUCT.sqrtdet_thr
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__tau_rel_min
#  define CCTK_PARAMETER__GRHYDRO__tau_rel_min RESTRICTED_GRHYDRO_STRUCT.tau_rel_min
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__weno_eps
#  define CCTK_PARAMETER__GRHYDRO__weno_eps RESTRICTED_GRHYDRO_STRUCT.weno_eps
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__Avec_gauge
#  define CCTK_PARAMETER__GRHYDRO__Avec_gauge RESTRICTED_GRHYDRO_STRUCT.Avec_gauge
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__EoS_Change_type
#  define CCTK_PARAMETER__GRHYDRO__EoS_Change_type RESTRICTED_GRHYDRO_STRUCT.EoS_Change_type
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_failed_action
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_failed_action RESTRICTED_GRHYDRO_STRUCT.GRHydro_c2p_failed_action
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_eos_table
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_eos_table RESTRICTED_GRHYDRO_STRUCT.GRHydro_eos_table
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_eos_type
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_eos_type RESTRICTED_GRHYDRO_STRUCT.GRHydro_eos_type
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__HLLE_type
#  define CCTK_PARAMETER__GRHYDRO__HLLE_type RESTRICTED_GRHYDRO_STRUCT.HLLE_type
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__bound
#  define CCTK_PARAMETER__GRHYDRO__bound RESTRICTED_GRHYDRO_STRUCT.bound
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__comoving_attenuate
#  define CCTK_PARAMETER__GRHYDRO__comoving_attenuate RESTRICTED_GRHYDRO_STRUCT.comoving_attenuate
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__comoving_v_method
#  define CCTK_PARAMETER__GRHYDRO__comoving_v_method RESTRICTED_GRHYDRO_STRUCT.comoving_v_method
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__gradient_method
#  define CCTK_PARAMETER__GRHYDRO__gradient_method RESTRICTED_GRHYDRO_STRUCT.gradient_method
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__left_eigenvectors
#  define CCTK_PARAMETER__GRHYDRO__left_eigenvectors RESTRICTED_GRHYDRO_STRUCT.left_eigenvectors
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__method_type
#  define CCTK_PARAMETER__GRHYDRO__method_type RESTRICTED_GRHYDRO_STRUCT.method_type
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__numerical_viscosity
#  define CCTK_PARAMETER__GRHYDRO__numerical_viscosity RESTRICTED_GRHYDRO_STRUCT.numerical_viscosity
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__particle_interpolator
#  define CCTK_PARAMETER__GRHYDRO__particle_interpolator RESTRICTED_GRHYDRO_STRUCT.particle_interpolator
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_flatten
#  define CCTK_PARAMETER__GRHYDRO__ppm_flatten RESTRICTED_GRHYDRO_STRUCT.ppm_flatten
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__psidcspeed
#  define CCTK_PARAMETER__GRHYDRO__psidcspeed RESTRICTED_GRHYDRO_STRUCT.psidcspeed
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__recon_method
#  define CCTK_PARAMETER__GRHYDRO__recon_method RESTRICTED_GRHYDRO_STRUCT.recon_method
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__recon_vars
#  define CCTK_PARAMETER__GRHYDRO__recon_vars RESTRICTED_GRHYDRO_STRUCT.recon_vars
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__riemann_solver
#  define CCTK_PARAMETER__GRHYDRO__riemann_solver RESTRICTED_GRHYDRO_STRUCT.riemann_solver
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__tvd_limiter
#  define CCTK_PARAMETER__GRHYDRO__tvd_limiter RESTRICTED_GRHYDRO_STRUCT.tvd_limiter
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__use_evolution_mask
#  define CCTK_PARAMETER__GRHYDRO__use_evolution_mask RESTRICTED_GRHYDRO_STRUCT.use_evolution_mask
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__Check_Rho_Minimum
#  define CCTK_PARAMETER__GRHYDRO__Check_Rho_Minimum RESTRICTED_GRHYDRO_STRUCT.Check_Rho_Minimum
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__EoS_Change
#  define CCTK_PARAMETER__GRHYDRO__EoS_Change RESTRICTED_GRHYDRO_STRUCT.EoS_Change
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumConstrainedVars
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumConstrainedVars RESTRICTED_GRHYDRO_STRUCT.GRHydro_MaxNumConstrainedVars
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumEvolvedVars
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumEvolvedVars RESTRICTED_GRHYDRO_STRUCT.GRHydro_MaxNumEvolvedVars
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumEvolvedVarsSlow
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumEvolvedVarsSlow RESTRICTED_GRHYDRO_STRUCT.GRHydro_MaxNumEvolvedVarsSlow
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumSandRVars
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_MaxNumSandRVars RESTRICTED_GRHYDRO_STRUCT.GRHydro_MaxNumSandRVars
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_NaN_verbose
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_NaN_verbose RESTRICTED_GRHYDRO_STRUCT.GRHydro_NaN_verbose
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_reset_eps_tau_hot_eos
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_reset_eps_tau_hot_eos RESTRICTED_GRHYDRO_STRUCT.GRHydro_c2p_reset_eps_tau_hot_eos
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_warn_from_reflevel
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_warn_from_reflevel RESTRICTED_GRHYDRO_STRUCT.GRHydro_c2p_warn_from_reflevel
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_warnlevel
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_c2p_warnlevel RESTRICTED_GRHYDRO_STRUCT.GRHydro_c2p_warnlevel
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_countmax
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_countmax RESTRICTED_GRHYDRO_STRUCT.GRHydro_countmax
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_countmin
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_countmin RESTRICTED_GRHYDRO_STRUCT.GRHydro_countmin
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_enable_internal_excision
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_enable_internal_excision RESTRICTED_GRHYDRO_STRUCT.GRHydro_enable_internal_excision
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_eos_hot_eps_fix
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_eos_hot_eps_fix RESTRICTED_GRHYDRO_STRUCT.GRHydro_eos_hot_eps_fix
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_eos_hot_prim2con_warn
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_eos_hot_prim2con_warn RESTRICTED_GRHYDRO_STRUCT.GRHydro_eos_hot_prim2con_warn
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_hydro_excision
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_hydro_excision RESTRICTED_GRHYDRO_STRUCT.GRHydro_hydro_excision
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_oppm_reflevel
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_oppm_reflevel RESTRICTED_GRHYDRO_STRUCT.GRHydro_oppm_reflevel
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_polish
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_polish RESTRICTED_GRHYDRO_STRUCT.GRHydro_polish
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__GRHydro_stencil
#  define CCTK_PARAMETER__GRHYDRO__GRHydro_stencil RESTRICTED_GRHYDRO_STRUCT.GRHydro_stencil
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__WENO_order
#  define CCTK_PARAMETER__GRHYDRO__WENO_order RESTRICTED_GRHYDRO_STRUCT.WENO_order
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__apply_H_viscosity
#  define CCTK_PARAMETER__GRHYDRO__apply_H_viscosity RESTRICTED_GRHYDRO_STRUCT.apply_H_viscosity
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__c2p_reset_pressure
#  define CCTK_PARAMETER__GRHYDRO__c2p_reset_pressure RESTRICTED_GRHYDRO_STRUCT.c2p_reset_pressure
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__c2p_resort_to_bisection
#  define CCTK_PARAMETER__GRHYDRO__c2p_resort_to_bisection RESTRICTED_GRHYDRO_STRUCT.c2p_resort_to_bisection
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__calculate_bcom
#  define CCTK_PARAMETER__GRHYDRO__calculate_bcom RESTRICTED_GRHYDRO_STRUCT.calculate_bcom
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__check_for_trivial_rp
#  define CCTK_PARAMETER__GRHYDRO__check_for_trivial_rp RESTRICTED_GRHYDRO_STRUCT.check_for_trivial_rp
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__clean_divergence
#  define CCTK_PARAMETER__GRHYDRO__clean_divergence RESTRICTED_GRHYDRO_STRUCT.clean_divergence
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__con2prim_oct_hack
#  define CCTK_PARAMETER__GRHYDRO__con2prim_oct_hack RESTRICTED_GRHYDRO_STRUCT.con2prim_oct_hack
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__decouple_normal_Bfield
#  define CCTK_PARAMETER__GRHYDRO__decouple_normal_Bfield RESTRICTED_GRHYDRO_STRUCT.decouple_normal_Bfield
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__eno_order
#  define CCTK_PARAMETER__GRHYDRO__eno_order RESTRICTED_GRHYDRO_STRUCT.eno_order
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__evolve_tracer
#  define CCTK_PARAMETER__GRHYDRO__evolve_tracer RESTRICTED_GRHYDRO_STRUCT.evolve_tracer
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__mp5_adaptive_eps
#  define CCTK_PARAMETER__GRHYDRO__mp5_adaptive_eps RESTRICTED_GRHYDRO_STRUCT.mp5_adaptive_eps
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__number_of_arrays
#  define CCTK_PARAMETER__GRHYDRO__number_of_arrays RESTRICTED_GRHYDRO_STRUCT.number_of_arrays
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__number_of_particles
#  define CCTK_PARAMETER__GRHYDRO__number_of_particles RESTRICTED_GRHYDRO_STRUCT.number_of_particles
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__number_of_tracers
#  define CCTK_PARAMETER__GRHYDRO__number_of_tracers RESTRICTED_GRHYDRO_STRUCT.number_of_tracers
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__particle_interpolation_order
#  define CCTK_PARAMETER__GRHYDRO__particle_interpolation_order RESTRICTED_GRHYDRO_STRUCT.particle_interpolation_order
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_detect
#  define CCTK_PARAMETER__GRHYDRO__ppm_detect RESTRICTED_GRHYDRO_STRUCT.ppm_detect
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_mppm
#  define CCTK_PARAMETER__GRHYDRO__ppm_mppm RESTRICTED_GRHYDRO_STRUCT.ppm_mppm
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__ppm_mppm_debug_eigenvalues
#  define CCTK_PARAMETER__GRHYDRO__ppm_mppm_debug_eigenvalues RESTRICTED_GRHYDRO_STRUCT.ppm_mppm_debug_eigenvalues
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__reconstruct_Wv
#  define CCTK_PARAMETER__GRHYDRO__reconstruct_Wv RESTRICTED_GRHYDRO_STRUCT.reconstruct_Wv
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__reconstruct_temper
#  define CCTK_PARAMETER__GRHYDRO__reconstruct_temper RESTRICTED_GRHYDRO_STRUCT.reconstruct_temper
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__set_trivial_rp_grid_function
#  define CCTK_PARAMETER__GRHYDRO__set_trivial_rp_grid_function RESTRICTED_GRHYDRO_STRUCT.set_trivial_rp_grid_function
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__sources_spatial_order
#  define CCTK_PARAMETER__GRHYDRO__sources_spatial_order RESTRICTED_GRHYDRO_STRUCT.sources_spatial_order
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__sync_conserved_only
#  define CCTK_PARAMETER__GRHYDRO__sync_conserved_only RESTRICTED_GRHYDRO_STRUCT.sync_conserved_only
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__track_divB
#  define CCTK_PARAMETER__GRHYDRO__track_divB RESTRICTED_GRHYDRO_STRUCT.track_divB
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__transport_constraints
#  define CCTK_PARAMETER__GRHYDRO__transport_constraints RESTRICTED_GRHYDRO_STRUCT.transport_constraints
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__use_MoL_slow_multirate_sector
#  define CCTK_PARAMETER__GRHYDRO__use_MoL_slow_multirate_sector RESTRICTED_GRHYDRO_STRUCT.use_MoL_slow_multirate_sector
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__use_enhanced_ppm
#  define CCTK_PARAMETER__GRHYDRO__use_enhanced_ppm RESTRICTED_GRHYDRO_STRUCT.use_enhanced_ppm
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__use_min_tracer
#  define CCTK_PARAMETER__GRHYDRO__use_min_tracer RESTRICTED_GRHYDRO_STRUCT.use_min_tracer
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__use_optimized_ppm
#  define CCTK_PARAMETER__GRHYDRO__use_optimized_ppm RESTRICTED_GRHYDRO_STRUCT.use_optimized_ppm
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__use_weighted_fluxes
#  define CCTK_PARAMETER__GRHYDRO__use_weighted_fluxes RESTRICTED_GRHYDRO_STRUCT.use_weighted_fluxes
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__weno_adaptive_epsilon
#  define CCTK_PARAMETER__GRHYDRO__weno_adaptive_epsilon RESTRICTED_GRHYDRO_STRUCT.weno_adaptive_epsilon
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__wk_atmosphere
#  define CCTK_PARAMETER__GRHYDRO__wk_atmosphere RESTRICTED_GRHYDRO_STRUCT.wk_atmosphere
#endif

