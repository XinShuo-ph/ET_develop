#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * initial_data_setup_method;
} RESTRICTED_INITBASE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_INITBASE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, initial_data_setup_method, CCTK_PARAMETER__INITBASE__initial_data_setup_method); \


#ifndef CCTK_PARAMETER__INITBASE__initial_data_setup_method
#  define CCTK_PARAMETER__INITBASE__initial_data_setup_method RESTRICTED_INITBASE_STRUCT.initial_data_setup_method
#endif

