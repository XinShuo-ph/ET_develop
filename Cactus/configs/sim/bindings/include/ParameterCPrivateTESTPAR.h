#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL real1[10];
  CCTK_REAL real2[10];
  const char * out_dir;
  const char * string1;
  const char * string2;
  const char * string3;
  const char * string4;
  const char * string5;
  const char * string6;
  const char * string7;
  const char * string8;
  const char * string9;
  CCTK_INT bool1[10];
  CCTK_INT bool2[10];
  CCTK_INT int1[10];
  CCTK_INT int2[10];
} PRIVATE_TESTPAR_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TESTPAR_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, real1, CCTK_PARAMETER__TESTPAR__real1); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, real2, CCTK_PARAMETER__TESTPAR__real2); \
  CCTK_DECLARE_INIT (const char * const, out_dir, CCTK_PARAMETER__TESTPAR__out_dir); \
  CCTK_DECLARE_INIT (const char * const, string1, CCTK_PARAMETER__TESTPAR__string1); \
  CCTK_DECLARE_INIT (const char * const, string2, CCTK_PARAMETER__TESTPAR__string2); \
  CCTK_DECLARE_INIT (const char * const, string3, CCTK_PARAMETER__TESTPAR__string3); \
  CCTK_DECLARE_INIT (const char * const, string4, CCTK_PARAMETER__TESTPAR__string4); \
  CCTK_DECLARE_INIT (const char * const, string5, CCTK_PARAMETER__TESTPAR__string5); \
  CCTK_DECLARE_INIT (const char * const, string6, CCTK_PARAMETER__TESTPAR__string6); \
  CCTK_DECLARE_INIT (const char * const, string7, CCTK_PARAMETER__TESTPAR__string7); \
  CCTK_DECLARE_INIT (const char * const, string8, CCTK_PARAMETER__TESTPAR__string8); \
  CCTK_DECLARE_INIT (const char * const, string9, CCTK_PARAMETER__TESTPAR__string9); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, bool1, CCTK_PARAMETER__TESTPAR__bool1); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, bool2, CCTK_PARAMETER__TESTPAR__bool2); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, int1, CCTK_PARAMETER__TESTPAR__int1); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, int2, CCTK_PARAMETER__TESTPAR__int2); \


#ifndef CCTK_PARAMETER__TESTPAR__real1
#  define CCTK_PARAMETER__TESTPAR__real1 PRIVATE_TESTPAR_STRUCT.real1
#endif
#ifndef CCTK_PARAMETER__TESTPAR__real2
#  define CCTK_PARAMETER__TESTPAR__real2 PRIVATE_TESTPAR_STRUCT.real2
#endif
#ifndef CCTK_PARAMETER__TESTPAR__out_dir
#  define CCTK_PARAMETER__TESTPAR__out_dir PRIVATE_TESTPAR_STRUCT.out_dir
#endif
#ifndef CCTK_PARAMETER__TESTPAR__string1
#  define CCTK_PARAMETER__TESTPAR__string1 PRIVATE_TESTPAR_STRUCT.string1
#endif
#ifndef CCTK_PARAMETER__TESTPAR__string2
#  define CCTK_PARAMETER__TESTPAR__string2 PRIVATE_TESTPAR_STRUCT.string2
#endif
#ifndef CCTK_PARAMETER__TESTPAR__string3
#  define CCTK_PARAMETER__TESTPAR__string3 PRIVATE_TESTPAR_STRUCT.string3
#endif
#ifndef CCTK_PARAMETER__TESTPAR__string4
#  define CCTK_PARAMETER__TESTPAR__string4 PRIVATE_TESTPAR_STRUCT.string4
#endif
#ifndef CCTK_PARAMETER__TESTPAR__string5
#  define CCTK_PARAMETER__TESTPAR__string5 PRIVATE_TESTPAR_STRUCT.string5
#endif
#ifndef CCTK_PARAMETER__TESTPAR__string6
#  define CCTK_PARAMETER__TESTPAR__string6 PRIVATE_TESTPAR_STRUCT.string6
#endif
#ifndef CCTK_PARAMETER__TESTPAR__string7
#  define CCTK_PARAMETER__TESTPAR__string7 PRIVATE_TESTPAR_STRUCT.string7
#endif
#ifndef CCTK_PARAMETER__TESTPAR__string8
#  define CCTK_PARAMETER__TESTPAR__string8 PRIVATE_TESTPAR_STRUCT.string8
#endif
#ifndef CCTK_PARAMETER__TESTPAR__string9
#  define CCTK_PARAMETER__TESTPAR__string9 PRIVATE_TESTPAR_STRUCT.string9
#endif
#ifndef CCTK_PARAMETER__TESTPAR__bool1
#  define CCTK_PARAMETER__TESTPAR__bool1 PRIVATE_TESTPAR_STRUCT.bool1
#endif
#ifndef CCTK_PARAMETER__TESTPAR__bool2
#  define CCTK_PARAMETER__TESTPAR__bool2 PRIVATE_TESTPAR_STRUCT.bool2
#endif
#ifndef CCTK_PARAMETER__TESTPAR__int1
#  define CCTK_PARAMETER__TESTPAR__int1 PRIVATE_TESTPAR_STRUCT.int1
#endif
#ifndef CCTK_PARAMETER__TESTPAR__int2
#  define CCTK_PARAMETER__TESTPAR__int2 PRIVATE_TESTPAR_STRUCT.int2
#endif

