#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * filename;
} PRIVATE_MEUDON_MAG_NS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_MEUDON_MAG_NS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, filename, CCTK_PARAMETER__MEUDON_MAG_NS__filename); \


#ifndef CCTK_PARAMETER__MEUDON_MAG_NS__filename
#  define CCTK_PARAMETER__MEUDON_MAG_NS__filename PRIVATE_MEUDON_MAG_NS_STRUCT.filename
#endif

