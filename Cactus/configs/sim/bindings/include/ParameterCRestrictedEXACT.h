#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Alvi__mass1;
  CCTK_REAL Alvi__mass2;
  CCTK_REAL Alvi__separation;
  CCTK_REAL Bertotti__Lambda;
  CCTK_REAL Bianchi_I__scale;
  CCTK_REAL Goedel__scale;
  CCTK_REAL Gowdy_wave__amplitude;
  CCTK_REAL Kasner_generalized__p1;
  CCTK_REAL Kasner_generalized__p2;
  CCTK_REAL Kasner_like__q;
  CCTK_REAL Kerr_BoyerLindquist__mass;
  CCTK_REAL Kerr_BoyerLindquist__spin;
  CCTK_REAL Kerr_KerrSchild__boost_v;
  CCTK_REAL Kerr_KerrSchild__epsilon;
  CCTK_REAL Kerr_KerrSchild__mass;
  CCTK_REAL Kerr_KerrSchild__spin;
  CCTK_REAL Kerr_KerrSchild__t;
  CCTK_REAL Kerr_KerrSchild__x;
  CCTK_REAL Kerr_KerrSchild__y;
  CCTK_REAL Kerr_KerrSchild__z;
  CCTK_REAL Lemaitre__Lambda;
  CCTK_REAL Lemaitre__R0;
  CCTK_REAL Lemaitre__epsilon0;
  CCTK_REAL Lemaitre__kappa;
  CCTK_REAL Minkowski_conf_wave__amplitude;
  CCTK_REAL Minkowski_conf_wave__wavelength;
  CCTK_REAL Minkowski_funny__amplitude;
  CCTK_REAL Minkowski_funny__sigma;
  CCTK_REAL Minkowski_gauge_wave__amplitude;
  CCTK_REAL Minkowski_gauge_wave__lambda;
  CCTK_REAL Minkowski_gauge_wave__omega;
  CCTK_REAL Minkowski_gauge_wave__phase;
  CCTK_REAL Minkowski_shift__amplitude;
  CCTK_REAL Minkowski_shift__sigma;
  CCTK_REAL Schwarzschild_BL__epsilon;
  CCTK_REAL Schwarzschild_BL__mass;
  CCTK_REAL Schwarzschild_EF__epsilon;
  CCTK_REAL Schwarzschild_EF__mass;
  CCTK_REAL Schwarzschild_Lemaitre__Lambda;
  CCTK_REAL Schwarzschild_Lemaitre__mass;
  CCTK_REAL Schwarzschild_Novikov__epsilon;
  CCTK_REAL Schwarzschild_Novikov__mass;
  CCTK_REAL Schwarzschild_PG__epsilon;
  CCTK_REAL Schwarzschild_PG__mass;
  CCTK_REAL Thorne_fakebinary__Omega0;
  CCTK_REAL Thorne_fakebinary__epsilon;
  CCTK_REAL Thorne_fakebinary__mass;
  CCTK_REAL Thorne_fakebinary__separation;
  CCTK_REAL Thorne_fakebinary__smoothing;
  CCTK_REAL anti_de_Sitter_Lambda__scale;
  CCTK_REAL boost_rotation_symmetric__amp;
  CCTK_REAL boost_rotation_symmetric__min_d;
  CCTK_REAL boost_rotation_symmetric__scale;
  CCTK_REAL bowl__center;
  CCTK_REAL bowl__sigma;
  CCTK_REAL bowl__sigma_t;
  CCTK_REAL bowl__strength;
  CCTK_REAL bowl__t0;
  CCTK_REAL bowl__x_scale;
  CCTK_REAL bowl__y_scale;
  CCTK_REAL bowl__z_scale;
  CCTK_REAL constant_density_star__mass;
  CCTK_REAL constant_density_star__radius;
  CCTK_REAL de_Sitter_Lambda__scale;
  CCTK_REAL de_Sitter__scale;
  CCTK_REAL multi_BH__Hubble;
  CCTK_REAL multi_BH__mass1;
  CCTK_REAL multi_BH__mass2;
  CCTK_REAL multi_BH__mass3;
  CCTK_REAL multi_BH__mass4;
  CCTK_REAL multi_BH__x1;
  CCTK_REAL multi_BH__x2;
  CCTK_REAL multi_BH__x3;
  CCTK_REAL multi_BH__x4;
  CCTK_REAL multi_BH__y1;
  CCTK_REAL multi_BH__y2;
  CCTK_REAL multi_BH__y3;
  CCTK_REAL multi_BH__y4;
  CCTK_REAL multi_BH__z1;
  CCTK_REAL multi_BH__z2;
  CCTK_REAL multi_BH__z3;
  CCTK_REAL multi_BH__z4;
  const char * Minkowski_gauge_wave__what_fn;
  const char * Thorne_fakebinary__atype;
  const char * bowl__shape;
  const char * exact_model;
  CCTK_INT Kerr_KerrSchild__parabolic;
  CCTK_INT Kerr_KerrSchild__power;
  CCTK_INT Minkowski_conf_wave__direction;
  CCTK_INT Minkowski_gauge_wave__diagonal;
  CCTK_INT Thorne_fakebinary__retarded;
  CCTK_INT bowl__evolve;
  CCTK_INT multi_BH__nBH;
} RESTRICTED_EXACT_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_EXACT_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, Alvi__mass1, CCTK_PARAMETER__EXACT__Alvi__mass1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Alvi__mass2, CCTK_PARAMETER__EXACT__Alvi__mass2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Alvi__separation, CCTK_PARAMETER__EXACT__Alvi__separation); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Bertotti__Lambda, CCTK_PARAMETER__EXACT__Bertotti__Lambda); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Bianchi_I__scale, CCTK_PARAMETER__EXACT__Bianchi_I__scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Goedel__scale, CCTK_PARAMETER__EXACT__Goedel__scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Gowdy_wave__amplitude, CCTK_PARAMETER__EXACT__Gowdy_wave__amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kasner_generalized__p1, CCTK_PARAMETER__EXACT__Kasner_generalized__p1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kasner_generalized__p2, CCTK_PARAMETER__EXACT__Kasner_generalized__p2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kasner_like__q, CCTK_PARAMETER__EXACT__Kasner_like__q); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_BoyerLindquist__mass, CCTK_PARAMETER__EXACT__Kerr_BoyerLindquist__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_BoyerLindquist__spin, CCTK_PARAMETER__EXACT__Kerr_BoyerLindquist__spin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_KerrSchild__boost_v, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__boost_v); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_KerrSchild__epsilon, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__epsilon); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_KerrSchild__mass, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_KerrSchild__spin, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__spin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_KerrSchild__t, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__t); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_KerrSchild__x, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_KerrSchild__y, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kerr_KerrSchild__z, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Lemaitre__Lambda, CCTK_PARAMETER__EXACT__Lemaitre__Lambda); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Lemaitre__R0, CCTK_PARAMETER__EXACT__Lemaitre__R0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Lemaitre__epsilon0, CCTK_PARAMETER__EXACT__Lemaitre__epsilon0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Lemaitre__kappa, CCTK_PARAMETER__EXACT__Lemaitre__kappa); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_conf_wave__amplitude, CCTK_PARAMETER__EXACT__Minkowski_conf_wave__amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_conf_wave__wavelength, CCTK_PARAMETER__EXACT__Minkowski_conf_wave__wavelength); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_funny__amplitude, CCTK_PARAMETER__EXACT__Minkowski_funny__amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_funny__sigma, CCTK_PARAMETER__EXACT__Minkowski_funny__sigma); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_gauge_wave__amplitude, CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_gauge_wave__lambda, CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__lambda); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_gauge_wave__omega, CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__omega); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_gauge_wave__phase, CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__phase); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_shift__amplitude, CCTK_PARAMETER__EXACT__Minkowski_shift__amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Minkowski_shift__sigma, CCTK_PARAMETER__EXACT__Minkowski_shift__sigma); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_BL__epsilon, CCTK_PARAMETER__EXACT__Schwarzschild_BL__epsilon); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_BL__mass, CCTK_PARAMETER__EXACT__Schwarzschild_BL__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_EF__epsilon, CCTK_PARAMETER__EXACT__Schwarzschild_EF__epsilon); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_EF__mass, CCTK_PARAMETER__EXACT__Schwarzschild_EF__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_Lemaitre__Lambda, CCTK_PARAMETER__EXACT__Schwarzschild_Lemaitre__Lambda); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_Lemaitre__mass, CCTK_PARAMETER__EXACT__Schwarzschild_Lemaitre__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_Novikov__epsilon, CCTK_PARAMETER__EXACT__Schwarzschild_Novikov__epsilon); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_Novikov__mass, CCTK_PARAMETER__EXACT__Schwarzschild_Novikov__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_PG__epsilon, CCTK_PARAMETER__EXACT__Schwarzschild_PG__epsilon); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Schwarzschild_PG__mass, CCTK_PARAMETER__EXACT__Schwarzschild_PG__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Thorne_fakebinary__Omega0, CCTK_PARAMETER__EXACT__Thorne_fakebinary__Omega0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Thorne_fakebinary__epsilon, CCTK_PARAMETER__EXACT__Thorne_fakebinary__epsilon); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Thorne_fakebinary__mass, CCTK_PARAMETER__EXACT__Thorne_fakebinary__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Thorne_fakebinary__separation, CCTK_PARAMETER__EXACT__Thorne_fakebinary__separation); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Thorne_fakebinary__smoothing, CCTK_PARAMETER__EXACT__Thorne_fakebinary__smoothing); \
  CCTK_DECLARE_INIT (CCTK_REAL const, anti_de_Sitter_Lambda__scale, CCTK_PARAMETER__EXACT__anti_de_Sitter_Lambda__scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boost_rotation_symmetric__amp, CCTK_PARAMETER__EXACT__boost_rotation_symmetric__amp); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boost_rotation_symmetric__min_d, CCTK_PARAMETER__EXACT__boost_rotation_symmetric__min_d); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boost_rotation_symmetric__scale, CCTK_PARAMETER__EXACT__boost_rotation_symmetric__scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bowl__center, CCTK_PARAMETER__EXACT__bowl__center); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bowl__sigma, CCTK_PARAMETER__EXACT__bowl__sigma); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bowl__sigma_t, CCTK_PARAMETER__EXACT__bowl__sigma_t); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bowl__strength, CCTK_PARAMETER__EXACT__bowl__strength); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bowl__t0, CCTK_PARAMETER__EXACT__bowl__t0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bowl__x_scale, CCTK_PARAMETER__EXACT__bowl__x_scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bowl__y_scale, CCTK_PARAMETER__EXACT__bowl__y_scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const, bowl__z_scale, CCTK_PARAMETER__EXACT__bowl__z_scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const, constant_density_star__mass, CCTK_PARAMETER__EXACT__constant_density_star__mass); \
  CCTK_DECLARE_INIT (CCTK_REAL const, constant_density_star__radius, CCTK_PARAMETER__EXACT__constant_density_star__radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, de_Sitter_Lambda__scale, CCTK_PARAMETER__EXACT__de_Sitter_Lambda__scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const, de_Sitter__scale, CCTK_PARAMETER__EXACT__de_Sitter__scale); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__Hubble, CCTK_PARAMETER__EXACT__multi_BH__Hubble); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__mass1, CCTK_PARAMETER__EXACT__multi_BH__mass1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__mass2, CCTK_PARAMETER__EXACT__multi_BH__mass2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__mass3, CCTK_PARAMETER__EXACT__multi_BH__mass3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__mass4, CCTK_PARAMETER__EXACT__multi_BH__mass4); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__x1, CCTK_PARAMETER__EXACT__multi_BH__x1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__x2, CCTK_PARAMETER__EXACT__multi_BH__x2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__x3, CCTK_PARAMETER__EXACT__multi_BH__x3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__x4, CCTK_PARAMETER__EXACT__multi_BH__x4); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__y1, CCTK_PARAMETER__EXACT__multi_BH__y1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__y2, CCTK_PARAMETER__EXACT__multi_BH__y2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__y3, CCTK_PARAMETER__EXACT__multi_BH__y3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__y4, CCTK_PARAMETER__EXACT__multi_BH__y4); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__z1, CCTK_PARAMETER__EXACT__multi_BH__z1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__z2, CCTK_PARAMETER__EXACT__multi_BH__z2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__z3, CCTK_PARAMETER__EXACT__multi_BH__z3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, multi_BH__z4, CCTK_PARAMETER__EXACT__multi_BH__z4); \
  CCTK_DECLARE_INIT (const char * const, Minkowski_gauge_wave__what_fn, CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__what_fn); \
  CCTK_DECLARE_INIT (const char * const, Thorne_fakebinary__atype, CCTK_PARAMETER__EXACT__Thorne_fakebinary__atype); \
  CCTK_DECLARE_INIT (const char * const, bowl__shape, CCTK_PARAMETER__EXACT__bowl__shape); \
  CCTK_DECLARE_INIT (const char * const, exact_model, CCTK_PARAMETER__EXACT__exact_model); \
  CCTK_DECLARE_INIT (CCTK_INT const, Kerr_KerrSchild__parabolic, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__parabolic); \
  CCTK_DECLARE_INIT (CCTK_INT const, Kerr_KerrSchild__power, CCTK_PARAMETER__EXACT__Kerr_KerrSchild__power); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_conf_wave__direction, CCTK_PARAMETER__EXACT__Minkowski_conf_wave__direction); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_gauge_wave__diagonal, CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__diagonal); \
  CCTK_DECLARE_INIT (CCTK_INT const, Thorne_fakebinary__retarded, CCTK_PARAMETER__EXACT__Thorne_fakebinary__retarded); \
  CCTK_DECLARE_INIT (CCTK_INT const, bowl__evolve, CCTK_PARAMETER__EXACT__bowl__evolve); \
  CCTK_DECLARE_INIT (CCTK_INT const, multi_BH__nBH, CCTK_PARAMETER__EXACT__multi_BH__nBH); \


#ifndef CCTK_PARAMETER__EXACT__Alvi__mass1
#  define CCTK_PARAMETER__EXACT__Alvi__mass1 RESTRICTED_EXACT_STRUCT.Alvi__mass1
#endif
#ifndef CCTK_PARAMETER__EXACT__Alvi__mass2
#  define CCTK_PARAMETER__EXACT__Alvi__mass2 RESTRICTED_EXACT_STRUCT.Alvi__mass2
#endif
#ifndef CCTK_PARAMETER__EXACT__Alvi__separation
#  define CCTK_PARAMETER__EXACT__Alvi__separation RESTRICTED_EXACT_STRUCT.Alvi__separation
#endif
#ifndef CCTK_PARAMETER__EXACT__Bertotti__Lambda
#  define CCTK_PARAMETER__EXACT__Bertotti__Lambda RESTRICTED_EXACT_STRUCT.Bertotti__Lambda
#endif
#ifndef CCTK_PARAMETER__EXACT__Bianchi_I__scale
#  define CCTK_PARAMETER__EXACT__Bianchi_I__scale RESTRICTED_EXACT_STRUCT.Bianchi_I__scale
#endif
#ifndef CCTK_PARAMETER__EXACT__Goedel__scale
#  define CCTK_PARAMETER__EXACT__Goedel__scale RESTRICTED_EXACT_STRUCT.Goedel__scale
#endif
#ifndef CCTK_PARAMETER__EXACT__Gowdy_wave__amplitude
#  define CCTK_PARAMETER__EXACT__Gowdy_wave__amplitude RESTRICTED_EXACT_STRUCT.Gowdy_wave__amplitude
#endif
#ifndef CCTK_PARAMETER__EXACT__Kasner_generalized__p1
#  define CCTK_PARAMETER__EXACT__Kasner_generalized__p1 RESTRICTED_EXACT_STRUCT.Kasner_generalized__p1
#endif
#ifndef CCTK_PARAMETER__EXACT__Kasner_generalized__p2
#  define CCTK_PARAMETER__EXACT__Kasner_generalized__p2 RESTRICTED_EXACT_STRUCT.Kasner_generalized__p2
#endif
#ifndef CCTK_PARAMETER__EXACT__Kasner_like__q
#  define CCTK_PARAMETER__EXACT__Kasner_like__q RESTRICTED_EXACT_STRUCT.Kasner_like__q
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_BoyerLindquist__mass
#  define CCTK_PARAMETER__EXACT__Kerr_BoyerLindquist__mass RESTRICTED_EXACT_STRUCT.Kerr_BoyerLindquist__mass
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_BoyerLindquist__spin
#  define CCTK_PARAMETER__EXACT__Kerr_BoyerLindquist__spin RESTRICTED_EXACT_STRUCT.Kerr_BoyerLindquist__spin
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__boost_v
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__boost_v RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__boost_v
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__epsilon
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__epsilon RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__epsilon
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__mass
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__mass RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__mass
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__spin
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__spin RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__spin
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__t
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__t RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__t
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__x
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__x RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__x
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__y
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__y RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__y
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__z
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__z RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__z
#endif
#ifndef CCTK_PARAMETER__EXACT__Lemaitre__Lambda
#  define CCTK_PARAMETER__EXACT__Lemaitre__Lambda RESTRICTED_EXACT_STRUCT.Lemaitre__Lambda
#endif
#ifndef CCTK_PARAMETER__EXACT__Lemaitre__R0
#  define CCTK_PARAMETER__EXACT__Lemaitre__R0 RESTRICTED_EXACT_STRUCT.Lemaitre__R0
#endif
#ifndef CCTK_PARAMETER__EXACT__Lemaitre__epsilon0
#  define CCTK_PARAMETER__EXACT__Lemaitre__epsilon0 RESTRICTED_EXACT_STRUCT.Lemaitre__epsilon0
#endif
#ifndef CCTK_PARAMETER__EXACT__Lemaitre__kappa
#  define CCTK_PARAMETER__EXACT__Lemaitre__kappa RESTRICTED_EXACT_STRUCT.Lemaitre__kappa
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_conf_wave__amplitude
#  define CCTK_PARAMETER__EXACT__Minkowski_conf_wave__amplitude RESTRICTED_EXACT_STRUCT.Minkowski_conf_wave__amplitude
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_conf_wave__wavelength
#  define CCTK_PARAMETER__EXACT__Minkowski_conf_wave__wavelength RESTRICTED_EXACT_STRUCT.Minkowski_conf_wave__wavelength
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_funny__amplitude
#  define CCTK_PARAMETER__EXACT__Minkowski_funny__amplitude RESTRICTED_EXACT_STRUCT.Minkowski_funny__amplitude
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_funny__sigma
#  define CCTK_PARAMETER__EXACT__Minkowski_funny__sigma RESTRICTED_EXACT_STRUCT.Minkowski_funny__sigma
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__amplitude
#  define CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__amplitude RESTRICTED_EXACT_STRUCT.Minkowski_gauge_wave__amplitude
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__lambda
#  define CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__lambda RESTRICTED_EXACT_STRUCT.Minkowski_gauge_wave__lambda
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__omega
#  define CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__omega RESTRICTED_EXACT_STRUCT.Minkowski_gauge_wave__omega
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__phase
#  define CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__phase RESTRICTED_EXACT_STRUCT.Minkowski_gauge_wave__phase
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_shift__amplitude
#  define CCTK_PARAMETER__EXACT__Minkowski_shift__amplitude RESTRICTED_EXACT_STRUCT.Minkowski_shift__amplitude
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_shift__sigma
#  define CCTK_PARAMETER__EXACT__Minkowski_shift__sigma RESTRICTED_EXACT_STRUCT.Minkowski_shift__sigma
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_BL__epsilon
#  define CCTK_PARAMETER__EXACT__Schwarzschild_BL__epsilon RESTRICTED_EXACT_STRUCT.Schwarzschild_BL__epsilon
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_BL__mass
#  define CCTK_PARAMETER__EXACT__Schwarzschild_BL__mass RESTRICTED_EXACT_STRUCT.Schwarzschild_BL__mass
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_EF__epsilon
#  define CCTK_PARAMETER__EXACT__Schwarzschild_EF__epsilon RESTRICTED_EXACT_STRUCT.Schwarzschild_EF__epsilon
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_EF__mass
#  define CCTK_PARAMETER__EXACT__Schwarzschild_EF__mass RESTRICTED_EXACT_STRUCT.Schwarzschild_EF__mass
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_Lemaitre__Lambda
#  define CCTK_PARAMETER__EXACT__Schwarzschild_Lemaitre__Lambda RESTRICTED_EXACT_STRUCT.Schwarzschild_Lemaitre__Lambda
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_Lemaitre__mass
#  define CCTK_PARAMETER__EXACT__Schwarzschild_Lemaitre__mass RESTRICTED_EXACT_STRUCT.Schwarzschild_Lemaitre__mass
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_Novikov__epsilon
#  define CCTK_PARAMETER__EXACT__Schwarzschild_Novikov__epsilon RESTRICTED_EXACT_STRUCT.Schwarzschild_Novikov__epsilon
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_Novikov__mass
#  define CCTK_PARAMETER__EXACT__Schwarzschild_Novikov__mass RESTRICTED_EXACT_STRUCT.Schwarzschild_Novikov__mass
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_PG__epsilon
#  define CCTK_PARAMETER__EXACT__Schwarzschild_PG__epsilon RESTRICTED_EXACT_STRUCT.Schwarzschild_PG__epsilon
#endif
#ifndef CCTK_PARAMETER__EXACT__Schwarzschild_PG__mass
#  define CCTK_PARAMETER__EXACT__Schwarzschild_PG__mass RESTRICTED_EXACT_STRUCT.Schwarzschild_PG__mass
#endif
#ifndef CCTK_PARAMETER__EXACT__Thorne_fakebinary__Omega0
#  define CCTK_PARAMETER__EXACT__Thorne_fakebinary__Omega0 RESTRICTED_EXACT_STRUCT.Thorne_fakebinary__Omega0
#endif
#ifndef CCTK_PARAMETER__EXACT__Thorne_fakebinary__epsilon
#  define CCTK_PARAMETER__EXACT__Thorne_fakebinary__epsilon RESTRICTED_EXACT_STRUCT.Thorne_fakebinary__epsilon
#endif
#ifndef CCTK_PARAMETER__EXACT__Thorne_fakebinary__mass
#  define CCTK_PARAMETER__EXACT__Thorne_fakebinary__mass RESTRICTED_EXACT_STRUCT.Thorne_fakebinary__mass
#endif
#ifndef CCTK_PARAMETER__EXACT__Thorne_fakebinary__separation
#  define CCTK_PARAMETER__EXACT__Thorne_fakebinary__separation RESTRICTED_EXACT_STRUCT.Thorne_fakebinary__separation
#endif
#ifndef CCTK_PARAMETER__EXACT__Thorne_fakebinary__smoothing
#  define CCTK_PARAMETER__EXACT__Thorne_fakebinary__smoothing RESTRICTED_EXACT_STRUCT.Thorne_fakebinary__smoothing
#endif
#ifndef CCTK_PARAMETER__EXACT__anti_de_Sitter_Lambda__scale
#  define CCTK_PARAMETER__EXACT__anti_de_Sitter_Lambda__scale RESTRICTED_EXACT_STRUCT.anti_de_Sitter_Lambda__scale
#endif
#ifndef CCTK_PARAMETER__EXACT__boost_rotation_symmetric__amp
#  define CCTK_PARAMETER__EXACT__boost_rotation_symmetric__amp RESTRICTED_EXACT_STRUCT.boost_rotation_symmetric__amp
#endif
#ifndef CCTK_PARAMETER__EXACT__boost_rotation_symmetric__min_d
#  define CCTK_PARAMETER__EXACT__boost_rotation_symmetric__min_d RESTRICTED_EXACT_STRUCT.boost_rotation_symmetric__min_d
#endif
#ifndef CCTK_PARAMETER__EXACT__boost_rotation_symmetric__scale
#  define CCTK_PARAMETER__EXACT__boost_rotation_symmetric__scale RESTRICTED_EXACT_STRUCT.boost_rotation_symmetric__scale
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__center
#  define CCTK_PARAMETER__EXACT__bowl__center RESTRICTED_EXACT_STRUCT.bowl__center
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__sigma
#  define CCTK_PARAMETER__EXACT__bowl__sigma RESTRICTED_EXACT_STRUCT.bowl__sigma
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__sigma_t
#  define CCTK_PARAMETER__EXACT__bowl__sigma_t RESTRICTED_EXACT_STRUCT.bowl__sigma_t
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__strength
#  define CCTK_PARAMETER__EXACT__bowl__strength RESTRICTED_EXACT_STRUCT.bowl__strength
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__t0
#  define CCTK_PARAMETER__EXACT__bowl__t0 RESTRICTED_EXACT_STRUCT.bowl__t0
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__x_scale
#  define CCTK_PARAMETER__EXACT__bowl__x_scale RESTRICTED_EXACT_STRUCT.bowl__x_scale
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__y_scale
#  define CCTK_PARAMETER__EXACT__bowl__y_scale RESTRICTED_EXACT_STRUCT.bowl__y_scale
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__z_scale
#  define CCTK_PARAMETER__EXACT__bowl__z_scale RESTRICTED_EXACT_STRUCT.bowl__z_scale
#endif
#ifndef CCTK_PARAMETER__EXACT__constant_density_star__mass
#  define CCTK_PARAMETER__EXACT__constant_density_star__mass RESTRICTED_EXACT_STRUCT.constant_density_star__mass
#endif
#ifndef CCTK_PARAMETER__EXACT__constant_density_star__radius
#  define CCTK_PARAMETER__EXACT__constant_density_star__radius RESTRICTED_EXACT_STRUCT.constant_density_star__radius
#endif
#ifndef CCTK_PARAMETER__EXACT__de_Sitter_Lambda__scale
#  define CCTK_PARAMETER__EXACT__de_Sitter_Lambda__scale RESTRICTED_EXACT_STRUCT.de_Sitter_Lambda__scale
#endif
#ifndef CCTK_PARAMETER__EXACT__de_Sitter__scale
#  define CCTK_PARAMETER__EXACT__de_Sitter__scale RESTRICTED_EXACT_STRUCT.de_Sitter__scale
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__Hubble
#  define CCTK_PARAMETER__EXACT__multi_BH__Hubble RESTRICTED_EXACT_STRUCT.multi_BH__Hubble
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__mass1
#  define CCTK_PARAMETER__EXACT__multi_BH__mass1 RESTRICTED_EXACT_STRUCT.multi_BH__mass1
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__mass2
#  define CCTK_PARAMETER__EXACT__multi_BH__mass2 RESTRICTED_EXACT_STRUCT.multi_BH__mass2
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__mass3
#  define CCTK_PARAMETER__EXACT__multi_BH__mass3 RESTRICTED_EXACT_STRUCT.multi_BH__mass3
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__mass4
#  define CCTK_PARAMETER__EXACT__multi_BH__mass4 RESTRICTED_EXACT_STRUCT.multi_BH__mass4
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__x1
#  define CCTK_PARAMETER__EXACT__multi_BH__x1 RESTRICTED_EXACT_STRUCT.multi_BH__x1
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__x2
#  define CCTK_PARAMETER__EXACT__multi_BH__x2 RESTRICTED_EXACT_STRUCT.multi_BH__x2
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__x3
#  define CCTK_PARAMETER__EXACT__multi_BH__x3 RESTRICTED_EXACT_STRUCT.multi_BH__x3
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__x4
#  define CCTK_PARAMETER__EXACT__multi_BH__x4 RESTRICTED_EXACT_STRUCT.multi_BH__x4
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__y1
#  define CCTK_PARAMETER__EXACT__multi_BH__y1 RESTRICTED_EXACT_STRUCT.multi_BH__y1
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__y2
#  define CCTK_PARAMETER__EXACT__multi_BH__y2 RESTRICTED_EXACT_STRUCT.multi_BH__y2
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__y3
#  define CCTK_PARAMETER__EXACT__multi_BH__y3 RESTRICTED_EXACT_STRUCT.multi_BH__y3
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__y4
#  define CCTK_PARAMETER__EXACT__multi_BH__y4 RESTRICTED_EXACT_STRUCT.multi_BH__y4
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__z1
#  define CCTK_PARAMETER__EXACT__multi_BH__z1 RESTRICTED_EXACT_STRUCT.multi_BH__z1
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__z2
#  define CCTK_PARAMETER__EXACT__multi_BH__z2 RESTRICTED_EXACT_STRUCT.multi_BH__z2
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__z3
#  define CCTK_PARAMETER__EXACT__multi_BH__z3 RESTRICTED_EXACT_STRUCT.multi_BH__z3
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__z4
#  define CCTK_PARAMETER__EXACT__multi_BH__z4 RESTRICTED_EXACT_STRUCT.multi_BH__z4
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__what_fn
#  define CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__what_fn RESTRICTED_EXACT_STRUCT.Minkowski_gauge_wave__what_fn
#endif
#ifndef CCTK_PARAMETER__EXACT__Thorne_fakebinary__atype
#  define CCTK_PARAMETER__EXACT__Thorne_fakebinary__atype RESTRICTED_EXACT_STRUCT.Thorne_fakebinary__atype
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__shape
#  define CCTK_PARAMETER__EXACT__bowl__shape RESTRICTED_EXACT_STRUCT.bowl__shape
#endif
#ifndef CCTK_PARAMETER__EXACT__exact_model
#  define CCTK_PARAMETER__EXACT__exact_model RESTRICTED_EXACT_STRUCT.exact_model
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__parabolic
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__parabolic RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__parabolic
#endif
#ifndef CCTK_PARAMETER__EXACT__Kerr_KerrSchild__power
#  define CCTK_PARAMETER__EXACT__Kerr_KerrSchild__power RESTRICTED_EXACT_STRUCT.Kerr_KerrSchild__power
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_conf_wave__direction
#  define CCTK_PARAMETER__EXACT__Minkowski_conf_wave__direction RESTRICTED_EXACT_STRUCT.Minkowski_conf_wave__direction
#endif
#ifndef CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__diagonal
#  define CCTK_PARAMETER__EXACT__Minkowski_gauge_wave__diagonal RESTRICTED_EXACT_STRUCT.Minkowski_gauge_wave__diagonal
#endif
#ifndef CCTK_PARAMETER__EXACT__Thorne_fakebinary__retarded
#  define CCTK_PARAMETER__EXACT__Thorne_fakebinary__retarded RESTRICTED_EXACT_STRUCT.Thorne_fakebinary__retarded
#endif
#ifndef CCTK_PARAMETER__EXACT__bowl__evolve
#  define CCTK_PARAMETER__EXACT__bowl__evolve RESTRICTED_EXACT_STRUCT.bowl__evolve
#endif
#ifndef CCTK_PARAMETER__EXACT__multi_BH__nBH
#  define CCTK_PARAMETER__EXACT__multi_BH__nBH RESTRICTED_EXACT_STRUCT.multi_BH__nBH
#endif

