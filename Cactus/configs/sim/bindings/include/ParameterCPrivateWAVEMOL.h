#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * bound;
} PRIVATE_WAVEMOL_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_WAVEMOL_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, bound, CCTK_PARAMETER__WAVEMOL__bound); \


#ifndef CCTK_PARAMETER__WAVEMOL__bound
#  define CCTK_PARAMETER__WAVEMOL__bound PRIVATE_WAVEMOL_STRUCT.bound
#endif

