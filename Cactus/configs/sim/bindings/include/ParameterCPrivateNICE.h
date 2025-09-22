#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT Nice_nice;
} PRIVATE_NICE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NICE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, Nice_nice, CCTK_PARAMETER__NICE__Nice_nice); \


#ifndef CCTK_PARAMETER__NICE__Nice_nice
#  define CCTK_PARAMETER__NICE__Nice_nice PRIVATE_NICE_STRUCT.Nice_nice
#endif

