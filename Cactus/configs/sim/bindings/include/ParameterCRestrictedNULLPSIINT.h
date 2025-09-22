#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT NullPsiInt_MaxEvolvedArraySize;
  CCTK_INT NullPsiInt_NumArrayEvolvedVars;
} RESTRICTED_NULLPSIINT_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_NULLPSIINT_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, NullPsiInt_MaxEvolvedArraySize, CCTK_PARAMETER__NULLPSIINT__NullPsiInt_MaxEvolvedArraySize); \
  CCTK_DECLARE_INIT (CCTK_INT const, NullPsiInt_NumArrayEvolvedVars, CCTK_PARAMETER__NULLPSIINT__NullPsiInt_NumArrayEvolvedVars); \


#ifndef CCTK_PARAMETER__NULLPSIINT__NullPsiInt_MaxEvolvedArraySize
#  define CCTK_PARAMETER__NULLPSIINT__NullPsiInt_MaxEvolvedArraySize RESTRICTED_NULLPSIINT_STRUCT.NullPsiInt_MaxEvolvedArraySize
#endif
#ifndef CCTK_PARAMETER__NULLPSIINT__NullPsiInt_NumArrayEvolvedVars
#  define CCTK_PARAMETER__NULLPSIINT__NullPsiInt_NumArrayEvolvedVars RESTRICTED_NULLPSIINT_STRUCT.NullPsiInt_NumArrayEvolvedVars
#endif

