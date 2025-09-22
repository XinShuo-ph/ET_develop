#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL outInfo_dt;
  CCTK_REAL real_max;
  CCTK_REAL real_min;
  const char * outInfo_criterion;
  const char * outInfo_reductions;
  const char * outInfo_vars;
  CCTK_INT int_width;
  CCTK_INT iter_width;
  CCTK_INT outHeader_every;
  CCTK_INT outInfo_every;
  CCTK_INT real_prec;
  CCTK_INT real_prec_sci;
  CCTK_INT real_width;
  CCTK_INT time_prec;
  CCTK_INT time_width;
} PRIVATE_CARPETIOBASIC_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETIOBASIC_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, outInfo_dt, CCTK_PARAMETER__CARPETIOBASIC__outInfo_dt); \
  CCTK_DECLARE_INIT (CCTK_REAL const, real_max, CCTK_PARAMETER__CARPETIOBASIC__real_max); \
  CCTK_DECLARE_INIT (CCTK_REAL const, real_min, CCTK_PARAMETER__CARPETIOBASIC__real_min); \
  CCTK_DECLARE_INIT (const char * const, outInfo_criterion, CCTK_PARAMETER__CARPETIOBASIC__outInfo_criterion); \
  CCTK_DECLARE_INIT (const char * const, outInfo_reductions, CCTK_PARAMETER__CARPETIOBASIC__outInfo_reductions); \
  CCTK_DECLARE_INIT (const char * const, outInfo_vars, CCTK_PARAMETER__CARPETIOBASIC__outInfo_vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, int_width, CCTK_PARAMETER__CARPETIOBASIC__int_width); \
  CCTK_DECLARE_INIT (CCTK_INT const, iter_width, CCTK_PARAMETER__CARPETIOBASIC__iter_width); \
  CCTK_DECLARE_INIT (CCTK_INT const, outHeader_every, CCTK_PARAMETER__CARPETIOBASIC__outHeader_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, outInfo_every, CCTK_PARAMETER__CARPETIOBASIC__outInfo_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, real_prec, CCTK_PARAMETER__CARPETIOBASIC__real_prec); \
  CCTK_DECLARE_INIT (CCTK_INT const, real_prec_sci, CCTK_PARAMETER__CARPETIOBASIC__real_prec_sci); \
  CCTK_DECLARE_INIT (CCTK_INT const, real_width, CCTK_PARAMETER__CARPETIOBASIC__real_width); \
  CCTK_DECLARE_INIT (CCTK_INT const, time_prec, CCTK_PARAMETER__CARPETIOBASIC__time_prec); \
  CCTK_DECLARE_INIT (CCTK_INT const, time_width, CCTK_PARAMETER__CARPETIOBASIC__time_width); \


#ifndef CCTK_PARAMETER__CARPETIOBASIC__outInfo_dt
#  define CCTK_PARAMETER__CARPETIOBASIC__outInfo_dt PRIVATE_CARPETIOBASIC_STRUCT.outInfo_dt
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__real_max
#  define CCTK_PARAMETER__CARPETIOBASIC__real_max PRIVATE_CARPETIOBASIC_STRUCT.real_max
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__real_min
#  define CCTK_PARAMETER__CARPETIOBASIC__real_min PRIVATE_CARPETIOBASIC_STRUCT.real_min
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__outInfo_criterion
#  define CCTK_PARAMETER__CARPETIOBASIC__outInfo_criterion PRIVATE_CARPETIOBASIC_STRUCT.outInfo_criterion
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__outInfo_reductions
#  define CCTK_PARAMETER__CARPETIOBASIC__outInfo_reductions PRIVATE_CARPETIOBASIC_STRUCT.outInfo_reductions
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__outInfo_vars
#  define CCTK_PARAMETER__CARPETIOBASIC__outInfo_vars PRIVATE_CARPETIOBASIC_STRUCT.outInfo_vars
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__int_width
#  define CCTK_PARAMETER__CARPETIOBASIC__int_width PRIVATE_CARPETIOBASIC_STRUCT.int_width
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__iter_width
#  define CCTK_PARAMETER__CARPETIOBASIC__iter_width PRIVATE_CARPETIOBASIC_STRUCT.iter_width
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__outHeader_every
#  define CCTK_PARAMETER__CARPETIOBASIC__outHeader_every PRIVATE_CARPETIOBASIC_STRUCT.outHeader_every
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__outInfo_every
#  define CCTK_PARAMETER__CARPETIOBASIC__outInfo_every PRIVATE_CARPETIOBASIC_STRUCT.outInfo_every
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__real_prec
#  define CCTK_PARAMETER__CARPETIOBASIC__real_prec PRIVATE_CARPETIOBASIC_STRUCT.real_prec
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__real_prec_sci
#  define CCTK_PARAMETER__CARPETIOBASIC__real_prec_sci PRIVATE_CARPETIOBASIC_STRUCT.real_prec_sci
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__real_width
#  define CCTK_PARAMETER__CARPETIOBASIC__real_width PRIVATE_CARPETIOBASIC_STRUCT.real_width
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__time_prec
#  define CCTK_PARAMETER__CARPETIOBASIC__time_prec PRIVATE_CARPETIOBASIC_STRUCT.time_prec
#endif
#ifndef CCTK_PARAMETER__CARPETIOBASIC__time_width
#  define CCTK_PARAMETER__CARPETIOBASIC__time_width PRIVATE_CARPETIOBASIC_STRUCT.time_width
#endif

