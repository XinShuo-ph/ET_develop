#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Trigger_Checked_Value[10];
  const char * Trigger_Checked_Parameter_Name[10];
  const char * Trigger_Checked_Parameter_Thorn[10];
  const char * Trigger_Checked_Variable[10];
  const char * Trigger_Output_Method[10];
  const char * Trigger_Output_Variables[10];
  const char * Trigger_Reaction[10];
  const char * Trigger_Reduction[10];
  const char * Trigger_Relation[10];
  const char * Trigger_Steered_Parameter_Name[10];
  const char * Trigger_Steered_Parameter_Thorn[10];
  const char * Trigger_Steered_Parameter_Value[10];
  const char * Trigger_Steered_Scalar[10];
  const char * Trigger_Steered_Scalar_Value[10];
  CCTK_INT Trigger_Debug;
  CCTK_INT Trigger_Number;
  CCTK_INT Trigger_Once[10];
  CCTK_INT Trigger_Steered_Scalar_Index[10];
} PRIVATE_TRIGGER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TRIGGER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, Trigger_Checked_Value, CCTK_PARAMETER__TRIGGER__Trigger_Checked_Value); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Checked_Parameter_Name, CCTK_PARAMETER__TRIGGER__Trigger_Checked_Parameter_Name); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Checked_Parameter_Thorn, CCTK_PARAMETER__TRIGGER__Trigger_Checked_Parameter_Thorn); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Checked_Variable, CCTK_PARAMETER__TRIGGER__Trigger_Checked_Variable); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Output_Method, CCTK_PARAMETER__TRIGGER__Trigger_Output_Method); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Output_Variables, CCTK_PARAMETER__TRIGGER__Trigger_Output_Variables); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Reaction, CCTK_PARAMETER__TRIGGER__Trigger_Reaction); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Reduction, CCTK_PARAMETER__TRIGGER__Trigger_Reduction); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Relation, CCTK_PARAMETER__TRIGGER__Trigger_Relation); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Steered_Parameter_Name, CCTK_PARAMETER__TRIGGER__Trigger_Steered_Parameter_Name); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Steered_Parameter_Thorn, CCTK_PARAMETER__TRIGGER__Trigger_Steered_Parameter_Thorn); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Steered_Parameter_Value, CCTK_PARAMETER__TRIGGER__Trigger_Steered_Parameter_Value); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Steered_Scalar, CCTK_PARAMETER__TRIGGER__Trigger_Steered_Scalar); \
  CCTK_DECLARE_INIT (const char * const * const, Trigger_Steered_Scalar_Value, CCTK_PARAMETER__TRIGGER__Trigger_Steered_Scalar_Value); \
  CCTK_DECLARE_INIT (CCTK_INT const, Trigger_Debug, CCTK_PARAMETER__TRIGGER__Trigger_Debug); \
  CCTK_DECLARE_INIT (CCTK_INT const, Trigger_Number, CCTK_PARAMETER__TRIGGER__Trigger_Number); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, Trigger_Once, CCTK_PARAMETER__TRIGGER__Trigger_Once); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, Trigger_Steered_Scalar_Index, CCTK_PARAMETER__TRIGGER__Trigger_Steered_Scalar_Index); \


#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Checked_Value
#  define CCTK_PARAMETER__TRIGGER__Trigger_Checked_Value PRIVATE_TRIGGER_STRUCT.Trigger_Checked_Value
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Checked_Parameter_Name
#  define CCTK_PARAMETER__TRIGGER__Trigger_Checked_Parameter_Name PRIVATE_TRIGGER_STRUCT.Trigger_Checked_Parameter_Name
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Checked_Parameter_Thorn
#  define CCTK_PARAMETER__TRIGGER__Trigger_Checked_Parameter_Thorn PRIVATE_TRIGGER_STRUCT.Trigger_Checked_Parameter_Thorn
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Checked_Variable
#  define CCTK_PARAMETER__TRIGGER__Trigger_Checked_Variable PRIVATE_TRIGGER_STRUCT.Trigger_Checked_Variable
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Output_Method
#  define CCTK_PARAMETER__TRIGGER__Trigger_Output_Method PRIVATE_TRIGGER_STRUCT.Trigger_Output_Method
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Output_Variables
#  define CCTK_PARAMETER__TRIGGER__Trigger_Output_Variables PRIVATE_TRIGGER_STRUCT.Trigger_Output_Variables
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Reaction
#  define CCTK_PARAMETER__TRIGGER__Trigger_Reaction PRIVATE_TRIGGER_STRUCT.Trigger_Reaction
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Reduction
#  define CCTK_PARAMETER__TRIGGER__Trigger_Reduction PRIVATE_TRIGGER_STRUCT.Trigger_Reduction
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Relation
#  define CCTK_PARAMETER__TRIGGER__Trigger_Relation PRIVATE_TRIGGER_STRUCT.Trigger_Relation
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Steered_Parameter_Name
#  define CCTK_PARAMETER__TRIGGER__Trigger_Steered_Parameter_Name PRIVATE_TRIGGER_STRUCT.Trigger_Steered_Parameter_Name
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Steered_Parameter_Thorn
#  define CCTK_PARAMETER__TRIGGER__Trigger_Steered_Parameter_Thorn PRIVATE_TRIGGER_STRUCT.Trigger_Steered_Parameter_Thorn
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Steered_Parameter_Value
#  define CCTK_PARAMETER__TRIGGER__Trigger_Steered_Parameter_Value PRIVATE_TRIGGER_STRUCT.Trigger_Steered_Parameter_Value
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Steered_Scalar
#  define CCTK_PARAMETER__TRIGGER__Trigger_Steered_Scalar PRIVATE_TRIGGER_STRUCT.Trigger_Steered_Scalar
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Steered_Scalar_Value
#  define CCTK_PARAMETER__TRIGGER__Trigger_Steered_Scalar_Value PRIVATE_TRIGGER_STRUCT.Trigger_Steered_Scalar_Value
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Debug
#  define CCTK_PARAMETER__TRIGGER__Trigger_Debug PRIVATE_TRIGGER_STRUCT.Trigger_Debug
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Number
#  define CCTK_PARAMETER__TRIGGER__Trigger_Number PRIVATE_TRIGGER_STRUCT.Trigger_Number
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Once
#  define CCTK_PARAMETER__TRIGGER__Trigger_Once PRIVATE_TRIGGER_STRUCT.Trigger_Once
#endif
#ifndef CCTK_PARAMETER__TRIGGER__Trigger_Steered_Scalar_Index
#  define CCTK_PARAMETER__TRIGGER__Trigger_Steered_Scalar_Index PRIVATE_TRIGGER_STRUCT.Trigger_Steered_Scalar_Index
#endif

