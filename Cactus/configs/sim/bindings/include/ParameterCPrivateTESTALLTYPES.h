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
} PRIVATE_TESTALLTYPES_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TESTALLTYPES_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, preal, CCTK_PARAMETER__TESTALLTYPES__preal); \
  CCTK_DECLARE_INIT (const char * const, pstring, CCTK_PARAMETER__TESTALLTYPES__pstring); \
  CCTK_DECLARE_INIT (CCTK_INT const, pboolean, CCTK_PARAMETER__TESTALLTYPES__pboolean); \
  CCTK_DECLARE_INIT (CCTK_INT const, pint, CCTK_PARAMETER__TESTALLTYPES__pint); \


#ifndef CCTK_PARAMETER__TESTALLTYPES__preal
#  define CCTK_PARAMETER__TESTALLTYPES__preal PRIVATE_TESTALLTYPES_STRUCT.preal
#endif
#ifndef CCTK_PARAMETER__TESTALLTYPES__pstring
#  define CCTK_PARAMETER__TESTALLTYPES__pstring PRIVATE_TESTALLTYPES_STRUCT.pstring
#endif
#ifndef CCTK_PARAMETER__TESTALLTYPES__pboolean
#  define CCTK_PARAMETER__TESTALLTYPES__pboolean PRIVATE_TESTALLTYPES_STRUCT.pboolean
#endif
#ifndef CCTK_PARAMETER__TESTALLTYPES__pint
#  define CCTK_PARAMETER__TESTALLTYPES__pint PRIVATE_TESTALLTYPES_STRUCT.pint
#endif

