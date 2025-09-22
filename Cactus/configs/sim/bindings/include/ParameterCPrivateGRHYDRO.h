#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT constrain_to_1D;
  CCTK_INT use_cxx_code;
  CCTK_INT verbose;
} PRIVATE_GRHYDRO_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_GRHYDRO_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, constrain_to_1D, CCTK_PARAMETER__GRHYDRO__constrain_to_1D); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_cxx_code, CCTK_PARAMETER__GRHYDRO__use_cxx_code); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__GRHYDRO__verbose); \


#ifndef CCTK_PARAMETER__GRHYDRO__constrain_to_1D
#  define CCTK_PARAMETER__GRHYDRO__constrain_to_1D PRIVATE_GRHYDRO_STRUCT.constrain_to_1D
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__use_cxx_code
#  define CCTK_PARAMETER__GRHYDRO__use_cxx_code PRIVATE_GRHYDRO_STRUCT.use_cxx_code
#endif
#ifndef CCTK_PARAMETER__GRHYDRO__verbose
#  define CCTK_PARAMETER__GRHYDRO__verbose PRIVATE_GRHYDRO_STRUCT.verbose
#endif

