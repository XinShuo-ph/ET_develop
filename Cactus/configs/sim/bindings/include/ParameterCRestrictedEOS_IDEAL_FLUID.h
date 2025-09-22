#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL eos_ideal_fluid_gamma;
} RESTRICTED_EOS_IDEAL_FLUID_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_EOS_IDEAL_FLUID_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, eos_ideal_fluid_gamma, CCTK_PARAMETER__EOS_IDEAL_FLUID__eos_ideal_fluid_gamma); \


#ifndef CCTK_PARAMETER__EOS_IDEAL_FLUID__eos_ideal_fluid_gamma
#  define CCTK_PARAMETER__EOS_IDEAL_FLUID__eos_ideal_fluid_gamma RESTRICTED_EOS_IDEAL_FLUID_STRUCT.eos_ideal_fluid_gamma
#endif

