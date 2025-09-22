#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT compression_level;
} PRIVATE_IOHDF5UTIL_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_IOHDF5UTIL_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, compression_level, CCTK_PARAMETER__IOHDF5UTIL__compression_level); \


#ifndef CCTK_PARAMETER__IOHDF5UTIL__compression_level
#  define CCTK_PARAMETER__IOHDF5UTIL__compression_level PRIVATE_IOHDF5UTIL_STRUCT.compression_level
#endif

