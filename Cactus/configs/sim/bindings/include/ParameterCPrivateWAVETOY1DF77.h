#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL amplitude;
  CCTK_REAL center;
  CCTK_REAL sigma;
  const char * bound;
} PRIVATE_WAVETOY1DF77_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_WAVETOY1DF77_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, amplitude, CCTK_PARAMETER__WAVETOY1DF77__amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, center, CCTK_PARAMETER__WAVETOY1DF77__center); \
  CCTK_DECLARE_INIT (CCTK_REAL const, sigma, CCTK_PARAMETER__WAVETOY1DF77__sigma); \
  CCTK_DECLARE_INIT (const char * const, bound, CCTK_PARAMETER__WAVETOY1DF77__bound); \


#ifndef CCTK_PARAMETER__WAVETOY1DF77__amplitude
#  define CCTK_PARAMETER__WAVETOY1DF77__amplitude PRIVATE_WAVETOY1DF77_STRUCT.amplitude
#endif
#ifndef CCTK_PARAMETER__WAVETOY1DF77__center
#  define CCTK_PARAMETER__WAVETOY1DF77__center PRIVATE_WAVETOY1DF77_STRUCT.center
#endif
#ifndef CCTK_PARAMETER__WAVETOY1DF77__sigma
#  define CCTK_PARAMETER__WAVETOY1DF77__sigma PRIVATE_WAVETOY1DF77_STRUCT.sigma
#endif
#ifndef CCTK_PARAMETER__WAVETOY1DF77__bound
#  define CCTK_PARAMETER__WAVETOY1DF77__bound PRIVATE_WAVETOY1DF77_STRUCT.bound
#endif

