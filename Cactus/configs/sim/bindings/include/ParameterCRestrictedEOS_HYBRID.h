#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL eos_gamma_supernuclear;
  CCTK_REAL eos_gamma_th;
  CCTK_REAL rho_nuc;
} RESTRICTED_EOS_HYBRID_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_EOS_HYBRID_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, eos_gamma_supernuclear, CCTK_PARAMETER__EOS_HYBRID__eos_gamma_supernuclear); \
  CCTK_DECLARE_INIT (CCTK_REAL const, eos_gamma_th, CCTK_PARAMETER__EOS_HYBRID__eos_gamma_th); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rho_nuc, CCTK_PARAMETER__EOS_HYBRID__rho_nuc); \


#ifndef CCTK_PARAMETER__EOS_HYBRID__eos_gamma_supernuclear
#  define CCTK_PARAMETER__EOS_HYBRID__eos_gamma_supernuclear RESTRICTED_EOS_HYBRID_STRUCT.eos_gamma_supernuclear
#endif
#ifndef CCTK_PARAMETER__EOS_HYBRID__eos_gamma_th
#  define CCTK_PARAMETER__EOS_HYBRID__eos_gamma_th RESTRICTED_EOS_HYBRID_STRUCT.eos_gamma_th
#endif
#ifndef CCTK_PARAMETER__EOS_HYBRID__rho_nuc
#  define CCTK_PARAMETER__EOS_HYBRID__rho_nuc RESTRICTED_EOS_HYBRID_STRUCT.rho_nuc
#endif

