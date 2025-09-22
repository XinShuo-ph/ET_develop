#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * ricci_prolongation_type;
  CCTK_INT normalize_dtheta_dphi;
  CCTK_INT ricci_persist;
  CCTK_INT ricci_timelevels;
} PRIVATE_ADMANALYSIS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_ADMANALYSIS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, ricci_prolongation_type, CCTK_PARAMETER__ADMANALYSIS__ricci_prolongation_type); \
  CCTK_DECLARE_INIT (CCTK_INT const, normalize_dtheta_dphi, CCTK_PARAMETER__ADMANALYSIS__normalize_dtheta_dphi); \
  CCTK_DECLARE_INIT (CCTK_INT const, ricci_persist, CCTK_PARAMETER__ADMANALYSIS__ricci_persist); \
  CCTK_DECLARE_INIT (CCTK_INT const, ricci_timelevels, CCTK_PARAMETER__ADMANALYSIS__ricci_timelevels); \


#ifndef CCTK_PARAMETER__ADMANALYSIS__ricci_prolongation_type
#  define CCTK_PARAMETER__ADMANALYSIS__ricci_prolongation_type PRIVATE_ADMANALYSIS_STRUCT.ricci_prolongation_type
#endif
#ifndef CCTK_PARAMETER__ADMANALYSIS__normalize_dtheta_dphi
#  define CCTK_PARAMETER__ADMANALYSIS__normalize_dtheta_dphi PRIVATE_ADMANALYSIS_STRUCT.normalize_dtheta_dphi
#endif
#ifndef CCTK_PARAMETER__ADMANALYSIS__ricci_persist
#  define CCTK_PARAMETER__ADMANALYSIS__ricci_persist PRIVATE_ADMANALYSIS_STRUCT.ricci_persist
#endif
#ifndef CCTK_PARAMETER__ADMANALYSIS__ricci_timelevels
#  define CCTK_PARAMETER__ADMANALYSIS__ricci_timelevels PRIVATE_ADMANALYSIS_STRUCT.ricci_timelevels
#endif

