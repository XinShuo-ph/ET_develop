#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL preal;
  const char * pstring;
  CCTK_INT pboolean;
  CCTK_INT pint;
} PRIVATE_TESTTYPES_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TESTTYPES_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, preal, CCTK_PARAMETER__TESTTYPES__preal); \
  CCTK_DECLARE_INIT (const char * const, pstring, CCTK_PARAMETER__TESTTYPES__pstring); \
  CCTK_DECLARE_INIT (CCTK_INT const, pboolean, CCTK_PARAMETER__TESTTYPES__pboolean); \
  CCTK_DECLARE_INIT (CCTK_INT const, pint, CCTK_PARAMETER__TESTTYPES__pint); \


#ifndef CCTK_PARAMETER__TESTTYPES__preal
#  define CCTK_PARAMETER__TESTTYPES__preal PRIVATE_TESTTYPES_STRUCT.preal
#endif
#ifndef CCTK_PARAMETER__TESTTYPES__pstring
#  define CCTK_PARAMETER__TESTTYPES__pstring PRIVATE_TESTTYPES_STRUCT.pstring
#endif
#ifndef CCTK_PARAMETER__TESTTYPES__pboolean
#  define CCTK_PARAMETER__TESTTYPES__pboolean PRIVATE_TESTTYPES_STRUCT.pboolean
#endif
#ifndef CCTK_PARAMETER__TESTTYPES__pint
#  define CCTK_PARAMETER__TESTTYPES__pint PRIVATE_TESTTYPES_STRUCT.pint
#endif

