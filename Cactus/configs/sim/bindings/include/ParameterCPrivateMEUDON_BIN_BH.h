#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * filename;
} PRIVATE_MEUDON_BIN_BH_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_MEUDON_BIN_BH_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, filename, CCTK_PARAMETER__MEUDON_BIN_BH__filename); \


#ifndef CCTK_PARAMETER__MEUDON_BIN_BH__filename
#  define CCTK_PARAMETER__MEUDON_BIN_BH__filename PRIVATE_MEUDON_BIN_BH_STRUCT.filename
#endif

