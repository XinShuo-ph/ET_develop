#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * petsc_KSP_type;
  const char * petsc_PC_type;
  const char * petsc_nablaform;
  const char * petsc_verbose;
  CCTK_INT petsc_coeff_to_one;
  CCTK_INT petsc_reuse;
} PRIVATE_ELLPETSC_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_ELLPETSC_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, petsc_KSP_type, CCTK_PARAMETER__ELLPETSC__petsc_KSP_type); \
  CCTK_DECLARE_INIT (const char * const, petsc_PC_type, CCTK_PARAMETER__ELLPETSC__petsc_PC_type); \
  CCTK_DECLARE_INIT (const char * const, petsc_nablaform, CCTK_PARAMETER__ELLPETSC__petsc_nablaform); \
  CCTK_DECLARE_INIT (const char * const, petsc_verbose, CCTK_PARAMETER__ELLPETSC__petsc_verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, petsc_coeff_to_one, CCTK_PARAMETER__ELLPETSC__petsc_coeff_to_one); \
  CCTK_DECLARE_INIT (CCTK_INT const, petsc_reuse, CCTK_PARAMETER__ELLPETSC__petsc_reuse); \


#ifndef CCTK_PARAMETER__ELLPETSC__petsc_KSP_type
#  define CCTK_PARAMETER__ELLPETSC__petsc_KSP_type PRIVATE_ELLPETSC_STRUCT.petsc_KSP_type
#endif
#ifndef CCTK_PARAMETER__ELLPETSC__petsc_PC_type
#  define CCTK_PARAMETER__ELLPETSC__petsc_PC_type PRIVATE_ELLPETSC_STRUCT.petsc_PC_type
#endif
#ifndef CCTK_PARAMETER__ELLPETSC__petsc_nablaform
#  define CCTK_PARAMETER__ELLPETSC__petsc_nablaform PRIVATE_ELLPETSC_STRUCT.petsc_nablaform
#endif
#ifndef CCTK_PARAMETER__ELLPETSC__petsc_verbose
#  define CCTK_PARAMETER__ELLPETSC__petsc_verbose PRIVATE_ELLPETSC_STRUCT.petsc_verbose
#endif
#ifndef CCTK_PARAMETER__ELLPETSC__petsc_coeff_to_one
#  define CCTK_PARAMETER__ELLPETSC__petsc_coeff_to_one PRIVATE_ELLPETSC_STRUCT.petsc_coeff_to_one
#endif
#ifndef CCTK_PARAMETER__ELLPETSC__petsc_reuse
#  define CCTK_PARAMETER__ELLPETSC__petsc_reuse PRIVATE_ELLPETSC_STRUCT.petsc_reuse
#endif

