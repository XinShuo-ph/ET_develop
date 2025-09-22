#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT ML_CCZ4_MaxNumConstrainedVars;
} PRIVATE_ML_CCZ4_HELPER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_ML_CCZ4_HELPER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, ML_CCZ4_MaxNumConstrainedVars, CCTK_PARAMETER__ML_CCZ4_HELPER__ML_CCZ4_MaxNumConstrainedVars); \


#ifndef CCTK_PARAMETER__ML_CCZ4_HELPER__ML_CCZ4_MaxNumConstrainedVars
#  define CCTK_PARAMETER__ML_CCZ4_HELPER__ML_CCZ4_MaxNumConstrainedVars PRIVATE_ML_CCZ4_HELPER_STRUCT.ML_CCZ4_MaxNumConstrainedVars
#endif

