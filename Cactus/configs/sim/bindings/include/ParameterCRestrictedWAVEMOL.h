#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT WaveMoL_MaxNumConstrainedVars;
  CCTK_INT WaveMoL_MaxNumEvolvedVars;
} RESTRICTED_WAVEMOL_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_WAVEMOL_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, WaveMoL_MaxNumConstrainedVars, CCTK_PARAMETER__WAVEMOL__WaveMoL_MaxNumConstrainedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, WaveMoL_MaxNumEvolvedVars, CCTK_PARAMETER__WAVEMOL__WaveMoL_MaxNumEvolvedVars); \


#ifndef CCTK_PARAMETER__WAVEMOL__WaveMoL_MaxNumConstrainedVars
#  define CCTK_PARAMETER__WAVEMOL__WaveMoL_MaxNumConstrainedVars RESTRICTED_WAVEMOL_STRUCT.WaveMoL_MaxNumConstrainedVars
#endif
#ifndef CCTK_PARAMETER__WAVEMOL__WaveMoL_MaxNumEvolvedVars
#  define CCTK_PARAMETER__WAVEMOL__WaveMoL_MaxNumEvolvedVars RESTRICTED_WAVEMOL_STRUCT.WaveMoL_MaxNumEvolvedVars
#endif

