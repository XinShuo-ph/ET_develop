#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Bx_init;
  CCTK_REAL By_init;
  CCTK_REAL Bz_init;
  CCTK_REAL Monopole_point_Bx;
  CCTK_REAL R_Gauss;
  CCTK_REAL alfvenwave_pressure;
  CCTK_REAL atmosphere_vel[3];
  CCTK_REAL bh_bondi_pos_x[100];
  CCTK_REAL bh_bondi_pos_y[100];
  CCTK_REAL bh_bondi_pos_z[100];
  CCTK_REAL bondi_beta_sonicpt;
  CCTK_REAL bondi_bmag;
  CCTK_REAL bondi_central_mass[100];
  CCTK_REAL bondi_central_spin[100];
  CCTK_REAL bondi_freeze_inner_radius;
  CCTK_REAL bondi_freeze_outer_radius;
  CCTK_REAL bondi_radial_offset;
  CCTK_REAL bondi_rmax[100];
  CCTK_REAL bondi_rmin[100];
  CCTK_REAL cyl_press_inner;
  CCTK_REAL cyl_press_outer;
  CCTK_REAL cyl_r_inner;
  CCTK_REAL cyl_r_outer;
  CCTK_REAL cyl_rho_inner;
  CCTK_REAL cyl_rho_outer;
  CCTK_REAL dens_init;
  CCTK_REAL eps_init;
  CCTK_REAL gxx_init;
  CCTK_REAL gxy_init;
  CCTK_REAL gxz_init;
  CCTK_REAL gyy_init;
  CCTK_REAL gyz_init;
  CCTK_REAL gzz_init;
  CCTK_REAL mdot_sonicpt_bondi;
  CCTK_REAL n_bondi_pts[100];
  CCTK_REAL poloidal_A_b;
  CCTK_REAL poloidal_P_cut;
  CCTK_REAL poloidal_rho_max;
  CCTK_REAL press_init;
  CCTK_REAL r_sonicpt_bondi;
  CCTK_REAL rho_init;
  CCTK_REAL rotor_bvcxl;
  CCTK_REAL rotor_bvcyl;
  CCTK_REAL rotor_bvczl;
  CCTK_REAL rotor_pressin;
  CCTK_REAL rotor_pressout;
  CCTK_REAL rotor_r_rot;
  CCTK_REAL rotor_rhoin;
  CCTK_REAL rotor_rhoout;
  CCTK_REAL rotor_rsmooth_rel;
  CCTK_REAL rotor_v_max;
  CCTK_REAL rotor_xc;
  CCTK_REAL rotor_yc;
  CCTK_REAL shock_radius;
  CCTK_REAL shock_xpos;
  CCTK_REAL shock_ypos;
  CCTK_REAL shock_zpos;
  CCTK_REAL simple_wave_constant_c_0;
  CCTK_REAL simple_wave_v_max;
  CCTK_REAL sx_init;
  CCTK_REAL sy_init;
  CCTK_REAL sz_init;
  CCTK_REAL tau_init;
  CCTK_REAL velx_init;
  CCTK_REAL vely_init;
  CCTK_REAL velz_init;
  const char * advectedloop_case;
  const char * advectedloop_delA;
  const char * advectedloop_type;
  const char * alfvenwave_type;
  const char * bondi_Bvec_method;
  const char * bondi_coordinates;
  const char * monopole_type;
  const char * shock_case;
  const char * shocktube_type;
  CCTK_INT attenuate_atmosphere;
  CCTK_INT bondi_evolve_only_annulus;
  CCTK_INT bondi_overwrite_boundary;
  CCTK_INT change_shock_direction;
  CCTK_INT num_bondi_sols;
  CCTK_INT poloidal_P_p;
  CCTK_INT poloidal_n_p;
  CCTK_INT rotor_use_smoothing;
  CCTK_INT set_bondi_beta_sonicpt;
  CCTK_INT use_c2p_with_entropy_eqn;
} PRIVATE_GRHYDRO_INITDATA_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_GRHYDRO_INITDATA_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, Bx_init, CCTK_PARAMETER__GRHYDRO_INITDATA__Bx_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, By_init, CCTK_PARAMETER__GRHYDRO_INITDATA__By_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Bz_init, CCTK_PARAMETER__GRHYDRO_INITDATA__Bz_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Monopole_point_Bx, CCTK_PARAMETER__GRHYDRO_INITDATA__Monopole_point_Bx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, R_Gauss, CCTK_PARAMETER__GRHYDRO_INITDATA__R_Gauss); \
  CCTK_DECLARE_INIT (CCTK_REAL const, alfvenwave_pressure, CCTK_PARAMETER__GRHYDRO_INITDATA__alfvenwave_pressure); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, atmosphere_vel, CCTK_PARAMETER__GRHYDRO_INITDATA__atmosphere_vel); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, bh_bondi_pos_x, CCTK_PARAMETER__GRHYDRO_INITDATA__bh_bondi_pos_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, bh_bondi_pos_y, CCTK_PARAMETER__GRHYDRO_INITDATA__bh_bondi_pos_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, bh_bondi_pos_z, CCTK_PARAMETER__GRHYDRO_INITDATA__bh_bondi_pos_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bondi_beta_sonicpt, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_beta_sonicpt); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bondi_bmag, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_bmag); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, bondi_central_mass, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_central_mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, bondi_central_spin, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_central_spin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bondi_freeze_inner_radius, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_freeze_inner_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bondi_freeze_outer_radius, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_freeze_outer_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bondi_radial_offset, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_radial_offset); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, bondi_rmax, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_rmax); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, bondi_rmin, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_rmin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, cyl_press_inner, CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_press_inner); \
  CCTK_DECLARE_INIT (CCTK_REAL const, cyl_press_outer, CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_press_outer); \
  CCTK_DECLARE_INIT (CCTK_REAL const, cyl_r_inner, CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_r_inner); \
  CCTK_DECLARE_INIT (CCTK_REAL const, cyl_r_outer, CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_r_outer); \
  CCTK_DECLARE_INIT (CCTK_REAL const, cyl_rho_inner, CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_rho_inner); \
  CCTK_DECLARE_INIT (CCTK_REAL const, cyl_rho_outer, CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_rho_outer); \
  CCTK_DECLARE_INIT (CCTK_REAL const, dens_init, CCTK_PARAMETER__GRHYDRO_INITDATA__dens_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, eps_init, CCTK_PARAMETER__GRHYDRO_INITDATA__eps_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gxx_init, CCTK_PARAMETER__GRHYDRO_INITDATA__gxx_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gxy_init, CCTK_PARAMETER__GRHYDRO_INITDATA__gxy_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gxz_init, CCTK_PARAMETER__GRHYDRO_INITDATA__gxz_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gyy_init, CCTK_PARAMETER__GRHYDRO_INITDATA__gyy_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gyz_init, CCTK_PARAMETER__GRHYDRO_INITDATA__gyz_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gzz_init, CCTK_PARAMETER__GRHYDRO_INITDATA__gzz_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, mdot_sonicpt_bondi, CCTK_PARAMETER__GRHYDRO_INITDATA__mdot_sonicpt_bondi); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, n_bondi_pts, CCTK_PARAMETER__GRHYDRO_INITDATA__n_bondi_pts); \
  CCTK_DECLARE_INIT (CCTK_REAL const, poloidal_A_b, CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_A_b); \
  CCTK_DECLARE_INIT (CCTK_REAL const, poloidal_P_cut, CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_P_cut); \
  CCTK_DECLARE_INIT (CCTK_REAL const, poloidal_rho_max, CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_rho_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const, press_init, CCTK_PARAMETER__GRHYDRO_INITDATA__press_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, r_sonicpt_bondi, CCTK_PARAMETER__GRHYDRO_INITDATA__r_sonicpt_bondi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rho_init, CCTK_PARAMETER__GRHYDRO_INITDATA__rho_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_bvcxl, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_bvcxl); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_bvcyl, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_bvcyl); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_bvczl, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_bvczl); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_pressin, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_pressin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_pressout, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_pressout); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_r_rot, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_r_rot); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_rhoin, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_rhoin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_rhoout, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_rhoout); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_rsmooth_rel, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_rsmooth_rel); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_v_max, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_v_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_xc, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_xc); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotor_yc, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_yc); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shock_radius, CCTK_PARAMETER__GRHYDRO_INITDATA__shock_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shock_xpos, CCTK_PARAMETER__GRHYDRO_INITDATA__shock_xpos); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shock_ypos, CCTK_PARAMETER__GRHYDRO_INITDATA__shock_ypos); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shock_zpos, CCTK_PARAMETER__GRHYDRO_INITDATA__shock_zpos); \
  CCTK_DECLARE_INIT (CCTK_REAL const, simple_wave_constant_c_0, CCTK_PARAMETER__GRHYDRO_INITDATA__simple_wave_constant_c_0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, simple_wave_v_max, CCTK_PARAMETER__GRHYDRO_INITDATA__simple_wave_v_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const, sx_init, CCTK_PARAMETER__GRHYDRO_INITDATA__sx_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, sy_init, CCTK_PARAMETER__GRHYDRO_INITDATA__sy_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, sz_init, CCTK_PARAMETER__GRHYDRO_INITDATA__sz_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, tau_init, CCTK_PARAMETER__GRHYDRO_INITDATA__tau_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, velx_init, CCTK_PARAMETER__GRHYDRO_INITDATA__velx_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, vely_init, CCTK_PARAMETER__GRHYDRO_INITDATA__vely_init); \
  CCTK_DECLARE_INIT (CCTK_REAL const, velz_init, CCTK_PARAMETER__GRHYDRO_INITDATA__velz_init); \
  CCTK_DECLARE_INIT (const char * const, advectedloop_case, CCTK_PARAMETER__GRHYDRO_INITDATA__advectedloop_case); \
  CCTK_DECLARE_INIT (const char * const, advectedloop_delA, CCTK_PARAMETER__GRHYDRO_INITDATA__advectedloop_delA); \
  CCTK_DECLARE_INIT (const char * const, advectedloop_type, CCTK_PARAMETER__GRHYDRO_INITDATA__advectedloop_type); \
  CCTK_DECLARE_INIT (const char * const, alfvenwave_type, CCTK_PARAMETER__GRHYDRO_INITDATA__alfvenwave_type); \
  CCTK_DECLARE_INIT (const char * const, bondi_Bvec_method, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_Bvec_method); \
  CCTK_DECLARE_INIT (const char * const, bondi_coordinates, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_coordinates); \
  CCTK_DECLARE_INIT (const char * const, monopole_type, CCTK_PARAMETER__GRHYDRO_INITDATA__monopole_type); \
  CCTK_DECLARE_INIT (const char * const, shock_case, CCTK_PARAMETER__GRHYDRO_INITDATA__shock_case); \
  CCTK_DECLARE_INIT (const char * const, shocktube_type, CCTK_PARAMETER__GRHYDRO_INITDATA__shocktube_type); \
  CCTK_DECLARE_INIT (CCTK_INT const, attenuate_atmosphere, CCTK_PARAMETER__GRHYDRO_INITDATA__attenuate_atmosphere); \
  CCTK_DECLARE_INIT (CCTK_INT const, bondi_evolve_only_annulus, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_evolve_only_annulus); \
  CCTK_DECLARE_INIT (CCTK_INT const, bondi_overwrite_boundary, CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_overwrite_boundary); \
  CCTK_DECLARE_INIT (CCTK_INT const, change_shock_direction, CCTK_PARAMETER__GRHYDRO_INITDATA__change_shock_direction); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_bondi_sols, CCTK_PARAMETER__GRHYDRO_INITDATA__num_bondi_sols); \
  CCTK_DECLARE_INIT (CCTK_INT const, poloidal_P_p, CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_P_p); \
  CCTK_DECLARE_INIT (CCTK_INT const, poloidal_n_p, CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_n_p); \
  CCTK_DECLARE_INIT (CCTK_INT const, rotor_use_smoothing, CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_use_smoothing); \
  CCTK_DECLARE_INIT (CCTK_INT const, set_bondi_beta_sonicpt, CCTK_PARAMETER__GRHYDRO_INITDATA__set_bondi_beta_sonicpt); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_c2p_with_entropy_eqn, CCTK_PARAMETER__GRHYDRO_INITDATA__use_c2p_with_entropy_eqn); \


#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__Bx_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__Bx_init PRIVATE_GRHYDRO_INITDATA_STRUCT.Bx_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__By_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__By_init PRIVATE_GRHYDRO_INITDATA_STRUCT.By_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__Bz_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__Bz_init PRIVATE_GRHYDRO_INITDATA_STRUCT.Bz_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__Monopole_point_Bx
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__Monopole_point_Bx PRIVATE_GRHYDRO_INITDATA_STRUCT.Monopole_point_Bx
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__R_Gauss
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__R_Gauss PRIVATE_GRHYDRO_INITDATA_STRUCT.R_Gauss
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__alfvenwave_pressure
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__alfvenwave_pressure PRIVATE_GRHYDRO_INITDATA_STRUCT.alfvenwave_pressure
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__atmosphere_vel
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__atmosphere_vel PRIVATE_GRHYDRO_INITDATA_STRUCT.atmosphere_vel
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bh_bondi_pos_x
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bh_bondi_pos_x PRIVATE_GRHYDRO_INITDATA_STRUCT.bh_bondi_pos_x
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bh_bondi_pos_y
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bh_bondi_pos_y PRIVATE_GRHYDRO_INITDATA_STRUCT.bh_bondi_pos_y
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bh_bondi_pos_z
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bh_bondi_pos_z PRIVATE_GRHYDRO_INITDATA_STRUCT.bh_bondi_pos_z
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_beta_sonicpt
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_beta_sonicpt PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_beta_sonicpt
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_bmag
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_bmag PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_bmag
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_central_mass
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_central_mass PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_central_mass
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_central_spin
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_central_spin PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_central_spin
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_freeze_inner_radius
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_freeze_inner_radius PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_freeze_inner_radius
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_freeze_outer_radius
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_freeze_outer_radius PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_freeze_outer_radius
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_radial_offset
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_radial_offset PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_radial_offset
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_rmax
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_rmax PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_rmax
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_rmin
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_rmin PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_rmin
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_press_inner
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_press_inner PRIVATE_GRHYDRO_INITDATA_STRUCT.cyl_press_inner
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_press_outer
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_press_outer PRIVATE_GRHYDRO_INITDATA_STRUCT.cyl_press_outer
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_r_inner
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_r_inner PRIVATE_GRHYDRO_INITDATA_STRUCT.cyl_r_inner
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_r_outer
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_r_outer PRIVATE_GRHYDRO_INITDATA_STRUCT.cyl_r_outer
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_rho_inner
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_rho_inner PRIVATE_GRHYDRO_INITDATA_STRUCT.cyl_rho_inner
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_rho_outer
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__cyl_rho_outer PRIVATE_GRHYDRO_INITDATA_STRUCT.cyl_rho_outer
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__dens_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__dens_init PRIVATE_GRHYDRO_INITDATA_STRUCT.dens_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__eps_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__eps_init PRIVATE_GRHYDRO_INITDATA_STRUCT.eps_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__gxx_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__gxx_init PRIVATE_GRHYDRO_INITDATA_STRUCT.gxx_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__gxy_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__gxy_init PRIVATE_GRHYDRO_INITDATA_STRUCT.gxy_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__gxz_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__gxz_init PRIVATE_GRHYDRO_INITDATA_STRUCT.gxz_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__gyy_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__gyy_init PRIVATE_GRHYDRO_INITDATA_STRUCT.gyy_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__gyz_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__gyz_init PRIVATE_GRHYDRO_INITDATA_STRUCT.gyz_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__gzz_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__gzz_init PRIVATE_GRHYDRO_INITDATA_STRUCT.gzz_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__mdot_sonicpt_bondi
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__mdot_sonicpt_bondi PRIVATE_GRHYDRO_INITDATA_STRUCT.mdot_sonicpt_bondi
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__n_bondi_pts
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__n_bondi_pts PRIVATE_GRHYDRO_INITDATA_STRUCT.n_bondi_pts
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_A_b
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_A_b PRIVATE_GRHYDRO_INITDATA_STRUCT.poloidal_A_b
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_P_cut
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_P_cut PRIVATE_GRHYDRO_INITDATA_STRUCT.poloidal_P_cut
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_rho_max
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_rho_max PRIVATE_GRHYDRO_INITDATA_STRUCT.poloidal_rho_max
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__press_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__press_init PRIVATE_GRHYDRO_INITDATA_STRUCT.press_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__r_sonicpt_bondi
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__r_sonicpt_bondi PRIVATE_GRHYDRO_INITDATA_STRUCT.r_sonicpt_bondi
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rho_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rho_init PRIVATE_GRHYDRO_INITDATA_STRUCT.rho_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_bvcxl
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_bvcxl PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_bvcxl
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_bvcyl
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_bvcyl PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_bvcyl
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_bvczl
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_bvczl PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_bvczl
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_pressin
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_pressin PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_pressin
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_pressout
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_pressout PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_pressout
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_r_rot
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_r_rot PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_r_rot
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_rhoin
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_rhoin PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_rhoin
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_rhoout
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_rhoout PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_rhoout
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_rsmooth_rel
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_rsmooth_rel PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_rsmooth_rel
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_v_max
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_v_max PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_v_max
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_xc
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_xc PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_xc
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_yc
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_yc PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_yc
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__shock_radius
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__shock_radius PRIVATE_GRHYDRO_INITDATA_STRUCT.shock_radius
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__shock_xpos
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__shock_xpos PRIVATE_GRHYDRO_INITDATA_STRUCT.shock_xpos
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__shock_ypos
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__shock_ypos PRIVATE_GRHYDRO_INITDATA_STRUCT.shock_ypos
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__shock_zpos
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__shock_zpos PRIVATE_GRHYDRO_INITDATA_STRUCT.shock_zpos
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__simple_wave_constant_c_0
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__simple_wave_constant_c_0 PRIVATE_GRHYDRO_INITDATA_STRUCT.simple_wave_constant_c_0
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__simple_wave_v_max
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__simple_wave_v_max PRIVATE_GRHYDRO_INITDATA_STRUCT.simple_wave_v_max
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__sx_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__sx_init PRIVATE_GRHYDRO_INITDATA_STRUCT.sx_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__sy_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__sy_init PRIVATE_GRHYDRO_INITDATA_STRUCT.sy_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__sz_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__sz_init PRIVATE_GRHYDRO_INITDATA_STRUCT.sz_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__tau_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__tau_init PRIVATE_GRHYDRO_INITDATA_STRUCT.tau_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__velx_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__velx_init PRIVATE_GRHYDRO_INITDATA_STRUCT.velx_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__vely_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__vely_init PRIVATE_GRHYDRO_INITDATA_STRUCT.vely_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__velz_init
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__velz_init PRIVATE_GRHYDRO_INITDATA_STRUCT.velz_init
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__advectedloop_case
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__advectedloop_case PRIVATE_GRHYDRO_INITDATA_STRUCT.advectedloop_case
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__advectedloop_delA
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__advectedloop_delA PRIVATE_GRHYDRO_INITDATA_STRUCT.advectedloop_delA
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__advectedloop_type
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__advectedloop_type PRIVATE_GRHYDRO_INITDATA_STRUCT.advectedloop_type
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__alfvenwave_type
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__alfvenwave_type PRIVATE_GRHYDRO_INITDATA_STRUCT.alfvenwave_type
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_Bvec_method
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_Bvec_method PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_Bvec_method
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_coordinates
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_coordinates PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_coordinates
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__monopole_type
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__monopole_type PRIVATE_GRHYDRO_INITDATA_STRUCT.monopole_type
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__shock_case
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__shock_case PRIVATE_GRHYDRO_INITDATA_STRUCT.shock_case
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__shocktube_type
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__shocktube_type PRIVATE_GRHYDRO_INITDATA_STRUCT.shocktube_type
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__attenuate_atmosphere
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__attenuate_atmosphere PRIVATE_GRHYDRO_INITDATA_STRUCT.attenuate_atmosphere
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_evolve_only_annulus
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_evolve_only_annulus PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_evolve_only_annulus
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_overwrite_boundary
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__bondi_overwrite_boundary PRIVATE_GRHYDRO_INITDATA_STRUCT.bondi_overwrite_boundary
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__change_shock_direction
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__change_shock_direction PRIVATE_GRHYDRO_INITDATA_STRUCT.change_shock_direction
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__num_bondi_sols
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__num_bondi_sols PRIVATE_GRHYDRO_INITDATA_STRUCT.num_bondi_sols
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_P_p
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_P_p PRIVATE_GRHYDRO_INITDATA_STRUCT.poloidal_P_p
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_n_p
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__poloidal_n_p PRIVATE_GRHYDRO_INITDATA_STRUCT.poloidal_n_p
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_use_smoothing
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__rotor_use_smoothing PRIVATE_GRHYDRO_INITDATA_STRUCT.rotor_use_smoothing
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__set_bondi_beta_sonicpt
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__set_bondi_beta_sonicpt PRIVATE_GRHYDRO_INITDATA_STRUCT.set_bondi_beta_sonicpt
#endif
#ifndef CCTK_PARAMETER__GRHYDRO_INITDATA__use_c2p_with_entropy_eqn
#  define CCTK_PARAMETER__GRHYDRO_INITDATA__use_c2p_with_entropy_eqn PRIVATE_GRHYDRO_INITDATA_STRUCT.use_c2p_with_entropy_eqn
#endif

