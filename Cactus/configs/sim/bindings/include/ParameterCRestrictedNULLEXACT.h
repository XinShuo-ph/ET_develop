#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT NullExact_MaxEvolvedArraySize;
  CCTK_INT NullExact_NumArrayEvolvedVars;
  CCTK_INT l_in_Ylm;
  CCTK_INT m_in_Ylm;
} RESTRICTED_NULLEXACT_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_NULLEXACT_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, NullExact_MaxEvolvedArraySize, CCTK_PARAMETER__NULLEXACT__NullExact_MaxEvolvedArraySize); \
  CCTK_DECLARE_INIT (CCTK_INT const, NullExact_NumArrayEvolvedVars, CCTK_PARAMETER__NULLEXACT__NullExact_NumArrayEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, l_in_Ylm, CCTK_PARAMETER__NULLEXACT__l_in_Ylm); \
  CCTK_DECLARE_INIT (CCTK_INT const, m_in_Ylm, CCTK_PARAMETER__NULLEXACT__m_in_Ylm); \


#ifndef CCTK_PARAMETER__NULLEXACT__NullExact_MaxEvolvedArraySize
#  define CCTK_PARAMETER__NULLEXACT__NullExact_MaxEvolvedArraySize RESTRICTED_NULLEXACT_STRUCT.NullExact_MaxEvolvedArraySize
#endif
#ifndef CCTK_PARAMETER__NULLEXACT__NullExact_NumArrayEvolvedVars
#  define CCTK_PARAMETER__NULLEXACT__NullExact_NumArrayEvolvedVars RESTRICTED_NULLEXACT_STRUCT.NullExact_NumArrayEvolvedVars
#endif
#ifndef CCTK_PARAMETER__NULLEXACT__l_in_Ylm
#  define CCTK_PARAMETER__NULLEXACT__l_in_Ylm RESTRICTED_NULLEXACT_STRUCT.l_in_Ylm
#endif
#ifndef CCTK_PARAMETER__NULLEXACT__m_in_Ylm
#  define CCTK_PARAMETER__NULLEXACT__m_in_Ylm RESTRICTED_NULLEXACT_STRUCT.m_in_Ylm
#endif

