#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT calculate_constraints;
} RESTRICTED_NULLCONSTR_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_NULLCONSTR_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, calculate_constraints, CCTK_PARAMETER__NULLCONSTR__calculate_constraints); \


#ifndef CCTK_PARAMETER__NULLCONSTR__calculate_constraints
#  define CCTK_PARAMETER__NULLCONSTR__calculate_constraints RESTRICTED_NULLCONSTR_STRUCT.calculate_constraints
#endif

