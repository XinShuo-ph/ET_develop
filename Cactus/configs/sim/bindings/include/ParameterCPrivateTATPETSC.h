#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * options;
  CCTK_INT verbose;
  CCTK_INT veryverbose;
} PRIVATE_TATPETSC_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TATPETSC_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, options, CCTK_PARAMETER__TATPETSC__options); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__TATPETSC__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, veryverbose, CCTK_PARAMETER__TATPETSC__veryverbose); \


#ifndef CCTK_PARAMETER__TATPETSC__options
#  define CCTK_PARAMETER__TATPETSC__options PRIVATE_TATPETSC_STRUCT.options
#endif
#ifndef CCTK_PARAMETER__TATPETSC__verbose
#  define CCTK_PARAMETER__TATPETSC__verbose PRIVATE_TATPETSC_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__TATPETSC__veryverbose
#  define CCTK_PARAMETER__TATPETSC__veryverbose PRIVATE_TATPETSC_STRUCT.veryverbose
#endif

