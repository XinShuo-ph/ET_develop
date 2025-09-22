#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Afact;
  CCTK_REAL elld_min_coef;
  CCTK_REAL fcoef;
  CCTK_REAL rl_min_coef;
  const char * SchIEF_time;
  const char * WT_metric;
  CCTK_INT WT_spherical_harmonics;
  CCTK_INT WT_spherical_harmonics_on_nullgrid;
  CCTK_INT ana_metric;
  CCTK_INT debug_switch_on;
  CCTK_INT elld_min_pow;
  CCTK_INT halt_on_negative_elld;
  CCTK_INT halt_on_negative_rl;
  CCTK_INT rl_min_pow;
} PRIVATE_NULLSHREXTRACT_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NULLSHREXTRACT_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, Afact, CCTK_PARAMETER__NULLSHREXTRACT__Afact); \
  CCTK_DECLARE_INIT (CCTK_REAL const, elld_min_coef, CCTK_PARAMETER__NULLSHREXTRACT__elld_min_coef); \
  CCTK_DECLARE_INIT (CCTK_REAL const, fcoef, CCTK_PARAMETER__NULLSHREXTRACT__fcoef); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rl_min_coef, CCTK_PARAMETER__NULLSHREXTRACT__rl_min_coef); \
  CCTK_DECLARE_INIT (const char * const, SchIEF_time, CCTK_PARAMETER__NULLSHREXTRACT__SchIEF_time); \
  CCTK_DECLARE_INIT (const char * const, WT_metric, CCTK_PARAMETER__NULLSHREXTRACT__WT_metric); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_spherical_harmonics, CCTK_PARAMETER__NULLSHREXTRACT__WT_spherical_harmonics); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_spherical_harmonics_on_nullgrid, CCTK_PARAMETER__NULLSHREXTRACT__WT_spherical_harmonics_on_nullgrid); \
  CCTK_DECLARE_INIT (CCTK_INT const, ana_metric, CCTK_PARAMETER__NULLSHREXTRACT__ana_metric); \
  CCTK_DECLARE_INIT (CCTK_INT const, debug_switch_on, CCTK_PARAMETER__NULLSHREXTRACT__debug_switch_on); \
  CCTK_DECLARE_INIT (CCTK_INT const, elld_min_pow, CCTK_PARAMETER__NULLSHREXTRACT__elld_min_pow); \
  CCTK_DECLARE_INIT (CCTK_INT const, halt_on_negative_elld, CCTK_PARAMETER__NULLSHREXTRACT__halt_on_negative_elld); \
  CCTK_DECLARE_INIT (CCTK_INT const, halt_on_negative_rl, CCTK_PARAMETER__NULLSHREXTRACT__halt_on_negative_rl); \
  CCTK_DECLARE_INIT (CCTK_INT const, rl_min_pow, CCTK_PARAMETER__NULLSHREXTRACT__rl_min_pow); \


#ifndef CCTK_PARAMETER__NULLSHREXTRACT__Afact
#  define CCTK_PARAMETER__NULLSHREXTRACT__Afact PRIVATE_NULLSHREXTRACT_STRUCT.Afact
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__elld_min_coef
#  define CCTK_PARAMETER__NULLSHREXTRACT__elld_min_coef PRIVATE_NULLSHREXTRACT_STRUCT.elld_min_coef
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__fcoef
#  define CCTK_PARAMETER__NULLSHREXTRACT__fcoef PRIVATE_NULLSHREXTRACT_STRUCT.fcoef
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__rl_min_coef
#  define CCTK_PARAMETER__NULLSHREXTRACT__rl_min_coef PRIVATE_NULLSHREXTRACT_STRUCT.rl_min_coef
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__SchIEF_time
#  define CCTK_PARAMETER__NULLSHREXTRACT__SchIEF_time PRIVATE_NULLSHREXTRACT_STRUCT.SchIEF_time
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__WT_metric
#  define CCTK_PARAMETER__NULLSHREXTRACT__WT_metric PRIVATE_NULLSHREXTRACT_STRUCT.WT_metric
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__WT_spherical_harmonics
#  define CCTK_PARAMETER__NULLSHREXTRACT__WT_spherical_harmonics PRIVATE_NULLSHREXTRACT_STRUCT.WT_spherical_harmonics
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__WT_spherical_harmonics_on_nullgrid
#  define CCTK_PARAMETER__NULLSHREXTRACT__WT_spherical_harmonics_on_nullgrid PRIVATE_NULLSHREXTRACT_STRUCT.WT_spherical_harmonics_on_nullgrid
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__ana_metric
#  define CCTK_PARAMETER__NULLSHREXTRACT__ana_metric PRIVATE_NULLSHREXTRACT_STRUCT.ana_metric
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__debug_switch_on
#  define CCTK_PARAMETER__NULLSHREXTRACT__debug_switch_on PRIVATE_NULLSHREXTRACT_STRUCT.debug_switch_on
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__elld_min_pow
#  define CCTK_PARAMETER__NULLSHREXTRACT__elld_min_pow PRIVATE_NULLSHREXTRACT_STRUCT.elld_min_pow
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__halt_on_negative_elld
#  define CCTK_PARAMETER__NULLSHREXTRACT__halt_on_negative_elld PRIVATE_NULLSHREXTRACT_STRUCT.halt_on_negative_elld
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__halt_on_negative_rl
#  define CCTK_PARAMETER__NULLSHREXTRACT__halt_on_negative_rl PRIVATE_NULLSHREXTRACT_STRUCT.halt_on_negative_rl
#endif
#ifndef CCTK_PARAMETER__NULLSHREXTRACT__rl_min_pow
#  define CCTK_PARAMETER__NULLSHREXTRACT__rl_min_pow PRIVATE_NULLSHREXTRACT_STRUCT.rl_min_pow
#endif

