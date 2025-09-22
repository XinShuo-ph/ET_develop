#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT EHFinder_MaxNumEvolvedVars;
  CCTK_INT EHFinder_Max_Evolved_Array_Size;
  CCTK_INT EHFinder_Num_ArrayEvolved_Vars;
} RESTRICTED_EHFINDER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_EHFINDER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, EHFinder_MaxNumEvolvedVars, CCTK_PARAMETER__EHFINDER__EHFinder_MaxNumEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, EHFinder_Max_Evolved_Array_Size, CCTK_PARAMETER__EHFINDER__EHFinder_Max_Evolved_Array_Size); \
  CCTK_DECLARE_INIT (CCTK_INT const, EHFinder_Num_ArrayEvolved_Vars, CCTK_PARAMETER__EHFINDER__EHFinder_Num_ArrayEvolved_Vars); \


#ifndef CCTK_PARAMETER__EHFINDER__EHFinder_MaxNumEvolvedVars
#  define CCTK_PARAMETER__EHFINDER__EHFinder_MaxNumEvolvedVars RESTRICTED_EHFINDER_STRUCT.EHFinder_MaxNumEvolvedVars
#endif
#ifndef CCTK_PARAMETER__EHFINDER__EHFinder_Max_Evolved_Array_Size
#  define CCTK_PARAMETER__EHFINDER__EHFinder_Max_Evolved_Array_Size RESTRICTED_EHFINDER_STRUCT.EHFinder_Max_Evolved_Array_Size
#endif
#ifndef CCTK_PARAMETER__EHFINDER__EHFinder_Num_ArrayEvolved_Vars
#  define CCTK_PARAMETER__EHFINDER__EHFinder_Num_ArrayEvolved_Vars RESTRICTED_EHFINDER_STRUCT.EHFinder_Num_ArrayEvolved_Vars
#endif

