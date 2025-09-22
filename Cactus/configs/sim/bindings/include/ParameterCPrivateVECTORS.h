#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT verbose;
} PRIVATE_VECTORS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_VECTORS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__VECTORS__verbose); \


#ifndef CCTK_PARAMETER__VECTORS__verbose
#  define CCTK_PARAMETER__VECTORS__verbose PRIVATE_VECTORS_STRUCT.verbose
#endif

