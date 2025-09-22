#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL binary_charge;
  CCTK_REAL binary_omega;
  CCTK_REAL binary_radius;
  CCTK_REAL binary_size;
  const char * binary_verbose;
} PRIVATE_WAVEBINARYSOURCE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_WAVEBINARYSOURCE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, binary_charge, CCTK_PARAMETER__WAVEBINARYSOURCE__binary_charge); \
  CCTK_DECLARE_INIT (CCTK_REAL const, binary_omega, CCTK_PARAMETER__WAVEBINARYSOURCE__binary_omega); \
  CCTK_DECLARE_INIT (CCTK_REAL const, binary_radius, CCTK_PARAMETER__WAVEBINARYSOURCE__binary_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, binary_size, CCTK_PARAMETER__WAVEBINARYSOURCE__binary_size); \
  CCTK_DECLARE_INIT (const char * const, binary_verbose, CCTK_PARAMETER__WAVEBINARYSOURCE__binary_verbose); \


#ifndef CCTK_PARAMETER__WAVEBINARYSOURCE__binary_charge
#  define CCTK_PARAMETER__WAVEBINARYSOURCE__binary_charge PRIVATE_WAVEBINARYSOURCE_STRUCT.binary_charge
#endif
#ifndef CCTK_PARAMETER__WAVEBINARYSOURCE__binary_omega
#  define CCTK_PARAMETER__WAVEBINARYSOURCE__binary_omega PRIVATE_WAVEBINARYSOURCE_STRUCT.binary_omega
#endif
#ifndef CCTK_PARAMETER__WAVEBINARYSOURCE__binary_radius
#  define CCTK_PARAMETER__WAVEBINARYSOURCE__binary_radius PRIVATE_WAVEBINARYSOURCE_STRUCT.binary_radius
#endif
#ifndef CCTK_PARAMETER__WAVEBINARYSOURCE__binary_size
#  define CCTK_PARAMETER__WAVEBINARYSOURCE__binary_size PRIVATE_WAVEBINARYSOURCE_STRUCT.binary_size
#endif
#ifndef CCTK_PARAMETER__WAVEBINARYSOURCE__binary_verbose
#  define CCTK_PARAMETER__WAVEBINARYSOURCE__binary_verbose PRIVATE_WAVEBINARYSOURCE_STRUCT.binary_verbose
#endif

