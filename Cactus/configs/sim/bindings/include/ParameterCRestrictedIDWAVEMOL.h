#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * initial_data;
} RESTRICTED_IDWAVEMOL_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_IDWAVEMOL_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, initial_data, CCTK_PARAMETER__IDWAVEMOL__initial_data); \


#ifndef CCTK_PARAMETER__IDWAVEMOL__initial_data
#  define CCTK_PARAMETER__IDWAVEMOL__initial_data RESTRICTED_IDWAVEMOL_STRUCT.initial_data
#endif

