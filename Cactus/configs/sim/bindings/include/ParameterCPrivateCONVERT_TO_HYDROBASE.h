#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT Convert_to_HydroBase_every;
} PRIVATE_CONVERT_TO_HYDROBASE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CONVERT_TO_HYDROBASE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, Convert_to_HydroBase_every, CCTK_PARAMETER__CONVERT_TO_HYDROBASE__Convert_to_HydroBase_every); \


#ifndef CCTK_PARAMETER__CONVERT_TO_HYDROBASE__Convert_to_HydroBase_every
#  define CCTK_PARAMETER__CONVERT_TO_HYDROBASE__Convert_to_HydroBase_every PRIVATE_CONVERT_TO_HYDROBASE_STRUCT.Convert_to_HydroBase_every
#endif

