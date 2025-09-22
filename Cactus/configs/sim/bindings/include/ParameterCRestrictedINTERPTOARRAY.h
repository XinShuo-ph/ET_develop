#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL array1d_dx_i;
  CCTK_REAL array1d_dy_i;
  CCTK_REAL array1d_dz_i;
  CCTK_REAL array1d_x0;
  CCTK_REAL array1d_y0;
  CCTK_REAL array1d_z0;
  CCTK_REAL array2d_dx_i;
  CCTK_REAL array2d_dx_j;
  CCTK_REAL array2d_dy_i;
  CCTK_REAL array2d_dy_j;
  CCTK_REAL array2d_dz_i;
  CCTK_REAL array2d_dz_j;
  CCTK_REAL array2d_x0;
  CCTK_REAL array2d_y0;
  CCTK_REAL array2d_z0;
  CCTK_REAL array3d_dx_i;
  CCTK_REAL array3d_dx_j;
  CCTK_REAL array3d_dx_k;
  CCTK_REAL array3d_dy_i;
  CCTK_REAL array3d_dy_j;
  CCTK_REAL array3d_dy_k;
  CCTK_REAL array3d_dz_i;
  CCTK_REAL array3d_dz_j;
  CCTK_REAL array3d_dz_k;
  CCTK_REAL array3d_x0;
  CCTK_REAL array3d_y0;
  CCTK_REAL array3d_z0;
  CCTK_REAL parray1d_dx_i;
  CCTK_REAL parray1d_dy_i;
  CCTK_REAL parray1d_dz_i;
  CCTK_REAL parray1d_x0;
  CCTK_REAL parray1d_y0;
  CCTK_REAL parray1d_z0;
  CCTK_REAL parray2d_dx_i;
  CCTK_REAL parray2d_dx_j;
  CCTK_REAL parray2d_dy_i;
  CCTK_REAL parray2d_dy_j;
  CCTK_REAL parray2d_dz_i;
  CCTK_REAL parray2d_dz_j;
  CCTK_REAL parray2d_x0;
  CCTK_REAL parray2d_y0;
  CCTK_REAL parray2d_z0;
  CCTK_REAL parray3d_dx_i;
  CCTK_REAL parray3d_dx_j;
  CCTK_REAL parray3d_dx_k;
  CCTK_REAL parray3d_dy_i;
  CCTK_REAL parray3d_dy_j;
  CCTK_REAL parray3d_dy_k;
  CCTK_REAL parray3d_dz_i;
  CCTK_REAL parray3d_dz_j;
  CCTK_REAL parray3d_dz_k;
  CCTK_REAL parray3d_x0;
  CCTK_REAL parray3d_y0;
  CCTK_REAL parray3d_z0;
  CCTK_REAL scalar_x0;
  CCTK_REAL scalar_y0;
  CCTK_REAL scalar_z0;
  const char * array1d_vars[100];
  const char * array2d_vars[100];
  const char * array3d_vars[100];
  const char * interpolator_coordinates;
  const char * interpolator_name;
  const char * interpolator_options;
  const char * parray1d_vars[100];
  const char * parray2d_vars[100];
  const char * parray3d_vars[100];
  const char * scalar_vars[100];
  CCTK_INT array1d_npoints_i;
  CCTK_INT array1d_spacederivs[100];
  CCTK_INT array1d_timederivs[100];
  CCTK_INT array2d_npoints_i;
  CCTK_INT array2d_npoints_j;
  CCTK_INT array3d_npoints_i;
  CCTK_INT array3d_npoints_j;
  CCTK_INT array3d_npoints_k;
  CCTK_INT carpetinterp2_interpolator_order;
  CCTK_INT narrays1d;
  CCTK_INT narrays2d;
  CCTK_INT narrays3d;
  CCTK_INT nghosts;
  CCTK_INT nparrays1d;
  CCTK_INT nparrays2d;
  CCTK_INT nparrays3d;
  CCTK_INT nscalars;
  CCTK_INT parray1d_npoints_i;
  CCTK_INT parray1d_spacederivs[100];
  CCTK_INT parray1d_timederivs[100];
  CCTK_INT parray2d_npoints_i;
  CCTK_INT parray2d_npoints_j;
  CCTK_INT parray3d_npoints_i;
  CCTK_INT parray3d_npoints_j;
  CCTK_INT parray3d_npoints_k;
  CCTK_INT use_carpetinterp2;
} RESTRICTED_INTERPTOARRAY_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_INTERPTOARRAY_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, array1d_dx_i, CCTK_PARAMETER__INTERPTOARRAY__array1d_dx_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array1d_dy_i, CCTK_PARAMETER__INTERPTOARRAY__array1d_dy_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array1d_dz_i, CCTK_PARAMETER__INTERPTOARRAY__array1d_dz_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array1d_x0, CCTK_PARAMETER__INTERPTOARRAY__array1d_x0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array1d_y0, CCTK_PARAMETER__INTERPTOARRAY__array1d_y0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array1d_z0, CCTK_PARAMETER__INTERPTOARRAY__array1d_z0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dx_i, CCTK_PARAMETER__INTERPTOARRAY__array2d_dx_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dx_j, CCTK_PARAMETER__INTERPTOARRAY__array2d_dx_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dy_i, CCTK_PARAMETER__INTERPTOARRAY__array2d_dy_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dy_j, CCTK_PARAMETER__INTERPTOARRAY__array2d_dy_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dz_i, CCTK_PARAMETER__INTERPTOARRAY__array2d_dz_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_dz_j, CCTK_PARAMETER__INTERPTOARRAY__array2d_dz_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_x0, CCTK_PARAMETER__INTERPTOARRAY__array2d_x0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_y0, CCTK_PARAMETER__INTERPTOARRAY__array2d_y0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array2d_z0, CCTK_PARAMETER__INTERPTOARRAY__array2d_z0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_dx_i, CCTK_PARAMETER__INTERPTOARRAY__array3d_dx_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_dx_j, CCTK_PARAMETER__INTERPTOARRAY__array3d_dx_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_dx_k, CCTK_PARAMETER__INTERPTOARRAY__array3d_dx_k); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_dy_i, CCTK_PARAMETER__INTERPTOARRAY__array3d_dy_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_dy_j, CCTK_PARAMETER__INTERPTOARRAY__array3d_dy_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_dy_k, CCTK_PARAMETER__INTERPTOARRAY__array3d_dy_k); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_dz_i, CCTK_PARAMETER__INTERPTOARRAY__array3d_dz_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_dz_j, CCTK_PARAMETER__INTERPTOARRAY__array3d_dz_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_dz_k, CCTK_PARAMETER__INTERPTOARRAY__array3d_dz_k); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_x0, CCTK_PARAMETER__INTERPTOARRAY__array3d_x0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_y0, CCTK_PARAMETER__INTERPTOARRAY__array3d_y0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, array3d_z0, CCTK_PARAMETER__INTERPTOARRAY__array3d_z0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray1d_dx_i, CCTK_PARAMETER__INTERPTOARRAY__parray1d_dx_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray1d_dy_i, CCTK_PARAMETER__INTERPTOARRAY__parray1d_dy_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray1d_dz_i, CCTK_PARAMETER__INTERPTOARRAY__parray1d_dz_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray1d_x0, CCTK_PARAMETER__INTERPTOARRAY__parray1d_x0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray1d_y0, CCTK_PARAMETER__INTERPTOARRAY__parray1d_y0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray1d_z0, CCTK_PARAMETER__INTERPTOARRAY__parray1d_z0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray2d_dx_i, CCTK_PARAMETER__INTERPTOARRAY__parray2d_dx_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray2d_dx_j, CCTK_PARAMETER__INTERPTOARRAY__parray2d_dx_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray2d_dy_i, CCTK_PARAMETER__INTERPTOARRAY__parray2d_dy_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray2d_dy_j, CCTK_PARAMETER__INTERPTOARRAY__parray2d_dy_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray2d_dz_i, CCTK_PARAMETER__INTERPTOARRAY__parray2d_dz_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray2d_dz_j, CCTK_PARAMETER__INTERPTOARRAY__parray2d_dz_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray2d_x0, CCTK_PARAMETER__INTERPTOARRAY__parray2d_x0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray2d_y0, CCTK_PARAMETER__INTERPTOARRAY__parray2d_y0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray2d_z0, CCTK_PARAMETER__INTERPTOARRAY__parray2d_z0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_dx_i, CCTK_PARAMETER__INTERPTOARRAY__parray3d_dx_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_dx_j, CCTK_PARAMETER__INTERPTOARRAY__parray3d_dx_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_dx_k, CCTK_PARAMETER__INTERPTOARRAY__parray3d_dx_k); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_dy_i, CCTK_PARAMETER__INTERPTOARRAY__parray3d_dy_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_dy_j, CCTK_PARAMETER__INTERPTOARRAY__parray3d_dy_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_dy_k, CCTK_PARAMETER__INTERPTOARRAY__parray3d_dy_k); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_dz_i, CCTK_PARAMETER__INTERPTOARRAY__parray3d_dz_i); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_dz_j, CCTK_PARAMETER__INTERPTOARRAY__parray3d_dz_j); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_dz_k, CCTK_PARAMETER__INTERPTOARRAY__parray3d_dz_k); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_x0, CCTK_PARAMETER__INTERPTOARRAY__parray3d_x0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_y0, CCTK_PARAMETER__INTERPTOARRAY__parray3d_y0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, parray3d_z0, CCTK_PARAMETER__INTERPTOARRAY__parray3d_z0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, scalar_x0, CCTK_PARAMETER__INTERPTOARRAY__scalar_x0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, scalar_y0, CCTK_PARAMETER__INTERPTOARRAY__scalar_y0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, scalar_z0, CCTK_PARAMETER__INTERPTOARRAY__scalar_z0); \
  CCTK_DECLARE_INIT (const char * const * const, array1d_vars, CCTK_PARAMETER__INTERPTOARRAY__array1d_vars); \
  CCTK_DECLARE_INIT (const char * const * const, array2d_vars, CCTK_PARAMETER__INTERPTOARRAY__array2d_vars); \
  CCTK_DECLARE_INIT (const char * const * const, array3d_vars, CCTK_PARAMETER__INTERPTOARRAY__array3d_vars); \
  CCTK_DECLARE_INIT (const char * const, interpolator_coordinates, CCTK_PARAMETER__INTERPTOARRAY__interpolator_coordinates); \
  CCTK_DECLARE_INIT (const char * const, interpolator_name, CCTK_PARAMETER__INTERPTOARRAY__interpolator_name); \
  CCTK_DECLARE_INIT (const char * const, interpolator_options, CCTK_PARAMETER__INTERPTOARRAY__interpolator_options); \
  CCTK_DECLARE_INIT (const char * const * const, parray1d_vars, CCTK_PARAMETER__INTERPTOARRAY__parray1d_vars); \
  CCTK_DECLARE_INIT (const char * const * const, parray2d_vars, CCTK_PARAMETER__INTERPTOARRAY__parray2d_vars); \
  CCTK_DECLARE_INIT (const char * const * const, parray3d_vars, CCTK_PARAMETER__INTERPTOARRAY__parray3d_vars); \
  CCTK_DECLARE_INIT (const char * const * const, scalar_vars, CCTK_PARAMETER__INTERPTOARRAY__scalar_vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, array1d_npoints_i, CCTK_PARAMETER__INTERPTOARRAY__array1d_npoints_i); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, array1d_spacederivs, CCTK_PARAMETER__INTERPTOARRAY__array1d_spacederivs); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, array1d_timederivs, CCTK_PARAMETER__INTERPTOARRAY__array1d_timederivs); \
  CCTK_DECLARE_INIT (CCTK_INT const, array2d_npoints_i, CCTK_PARAMETER__INTERPTOARRAY__array2d_npoints_i); \
  CCTK_DECLARE_INIT (CCTK_INT const, array2d_npoints_j, CCTK_PARAMETER__INTERPTOARRAY__array2d_npoints_j); \
  CCTK_DECLARE_INIT (CCTK_INT const, array3d_npoints_i, CCTK_PARAMETER__INTERPTOARRAY__array3d_npoints_i); \
  CCTK_DECLARE_INIT (CCTK_INT const, array3d_npoints_j, CCTK_PARAMETER__INTERPTOARRAY__array3d_npoints_j); \
  CCTK_DECLARE_INIT (CCTK_INT const, array3d_npoints_k, CCTK_PARAMETER__INTERPTOARRAY__array3d_npoints_k); \
  CCTK_DECLARE_INIT (CCTK_INT const, carpetinterp2_interpolator_order, CCTK_PARAMETER__INTERPTOARRAY__carpetinterp2_interpolator_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, narrays1d, CCTK_PARAMETER__INTERPTOARRAY__narrays1d); \
  CCTK_DECLARE_INIT (CCTK_INT const, narrays2d, CCTK_PARAMETER__INTERPTOARRAY__narrays2d); \
  CCTK_DECLARE_INIT (CCTK_INT const, narrays3d, CCTK_PARAMETER__INTERPTOARRAY__narrays3d); \
  CCTK_DECLARE_INIT (CCTK_INT const, nghosts, CCTK_PARAMETER__INTERPTOARRAY__nghosts); \
  CCTK_DECLARE_INIT (CCTK_INT const, nparrays1d, CCTK_PARAMETER__INTERPTOARRAY__nparrays1d); \
  CCTK_DECLARE_INIT (CCTK_INT const, nparrays2d, CCTK_PARAMETER__INTERPTOARRAY__nparrays2d); \
  CCTK_DECLARE_INIT (CCTK_INT const, nparrays3d, CCTK_PARAMETER__INTERPTOARRAY__nparrays3d); \
  CCTK_DECLARE_INIT (CCTK_INT const, nscalars, CCTK_PARAMETER__INTERPTOARRAY__nscalars); \
  CCTK_DECLARE_INIT (CCTK_INT const, parray1d_npoints_i, CCTK_PARAMETER__INTERPTOARRAY__parray1d_npoints_i); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, parray1d_spacederivs, CCTK_PARAMETER__INTERPTOARRAY__parray1d_spacederivs); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, parray1d_timederivs, CCTK_PARAMETER__INTERPTOARRAY__parray1d_timederivs); \
  CCTK_DECLARE_INIT (CCTK_INT const, parray2d_npoints_i, CCTK_PARAMETER__INTERPTOARRAY__parray2d_npoints_i); \
  CCTK_DECLARE_INIT (CCTK_INT const, parray2d_npoints_j, CCTK_PARAMETER__INTERPTOARRAY__parray2d_npoints_j); \
  CCTK_DECLARE_INIT (CCTK_INT const, parray3d_npoints_i, CCTK_PARAMETER__INTERPTOARRAY__parray3d_npoints_i); \
  CCTK_DECLARE_INIT (CCTK_INT const, parray3d_npoints_j, CCTK_PARAMETER__INTERPTOARRAY__parray3d_npoints_j); \
  CCTK_DECLARE_INIT (CCTK_INT const, parray3d_npoints_k, CCTK_PARAMETER__INTERPTOARRAY__parray3d_npoints_k); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_carpetinterp2, CCTK_PARAMETER__INTERPTOARRAY__use_carpetinterp2); \


#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_dx_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_dx_i RESTRICTED_INTERPTOARRAY_STRUCT.array1d_dx_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_dy_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_dy_i RESTRICTED_INTERPTOARRAY_STRUCT.array1d_dy_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_dz_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_dz_i RESTRICTED_INTERPTOARRAY_STRUCT.array1d_dz_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_x0
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_x0 RESTRICTED_INTERPTOARRAY_STRUCT.array1d_x0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_y0
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_y0 RESTRICTED_INTERPTOARRAY_STRUCT.array1d_y0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_z0
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_z0 RESTRICTED_INTERPTOARRAY_STRUCT.array1d_z0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_dx_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_dx_i RESTRICTED_INTERPTOARRAY_STRUCT.array2d_dx_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_dx_j
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_dx_j RESTRICTED_INTERPTOARRAY_STRUCT.array2d_dx_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_dy_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_dy_i RESTRICTED_INTERPTOARRAY_STRUCT.array2d_dy_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_dy_j
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_dy_j RESTRICTED_INTERPTOARRAY_STRUCT.array2d_dy_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_dz_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_dz_i RESTRICTED_INTERPTOARRAY_STRUCT.array2d_dz_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_dz_j
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_dz_j RESTRICTED_INTERPTOARRAY_STRUCT.array2d_dz_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_x0
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_x0 RESTRICTED_INTERPTOARRAY_STRUCT.array2d_x0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_y0
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_y0 RESTRICTED_INTERPTOARRAY_STRUCT.array2d_y0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_z0
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_z0 RESTRICTED_INTERPTOARRAY_STRUCT.array2d_z0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_dx_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_dx_i RESTRICTED_INTERPTOARRAY_STRUCT.array3d_dx_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_dx_j
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_dx_j RESTRICTED_INTERPTOARRAY_STRUCT.array3d_dx_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_dx_k
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_dx_k RESTRICTED_INTERPTOARRAY_STRUCT.array3d_dx_k
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_dy_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_dy_i RESTRICTED_INTERPTOARRAY_STRUCT.array3d_dy_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_dy_j
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_dy_j RESTRICTED_INTERPTOARRAY_STRUCT.array3d_dy_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_dy_k
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_dy_k RESTRICTED_INTERPTOARRAY_STRUCT.array3d_dy_k
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_dz_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_dz_i RESTRICTED_INTERPTOARRAY_STRUCT.array3d_dz_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_dz_j
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_dz_j RESTRICTED_INTERPTOARRAY_STRUCT.array3d_dz_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_dz_k
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_dz_k RESTRICTED_INTERPTOARRAY_STRUCT.array3d_dz_k
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_x0
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_x0 RESTRICTED_INTERPTOARRAY_STRUCT.array3d_x0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_y0
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_y0 RESTRICTED_INTERPTOARRAY_STRUCT.array3d_y0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_z0
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_z0 RESTRICTED_INTERPTOARRAY_STRUCT.array3d_z0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_dx_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_dx_i RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_dx_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_dy_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_dy_i RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_dy_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_dz_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_dz_i RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_dz_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_x0
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_x0 RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_x0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_y0
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_y0 RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_y0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_z0
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_z0 RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_z0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_dx_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_dx_i RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_dx_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_dx_j
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_dx_j RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_dx_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_dy_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_dy_i RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_dy_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_dy_j
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_dy_j RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_dy_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_dz_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_dz_i RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_dz_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_dz_j
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_dz_j RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_dz_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_x0
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_x0 RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_x0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_y0
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_y0 RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_y0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_z0
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_z0 RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_z0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_dx_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_dx_i RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_dx_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_dx_j
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_dx_j RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_dx_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_dx_k
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_dx_k RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_dx_k
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_dy_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_dy_i RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_dy_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_dy_j
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_dy_j RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_dy_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_dy_k
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_dy_k RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_dy_k
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_dz_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_dz_i RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_dz_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_dz_j
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_dz_j RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_dz_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_dz_k
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_dz_k RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_dz_k
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_x0
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_x0 RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_x0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_y0
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_y0 RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_y0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_z0
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_z0 RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_z0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__scalar_x0
#  define CCTK_PARAMETER__INTERPTOARRAY__scalar_x0 RESTRICTED_INTERPTOARRAY_STRUCT.scalar_x0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__scalar_y0
#  define CCTK_PARAMETER__INTERPTOARRAY__scalar_y0 RESTRICTED_INTERPTOARRAY_STRUCT.scalar_y0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__scalar_z0
#  define CCTK_PARAMETER__INTERPTOARRAY__scalar_z0 RESTRICTED_INTERPTOARRAY_STRUCT.scalar_z0
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_vars
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_vars RESTRICTED_INTERPTOARRAY_STRUCT.array1d_vars
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_vars
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_vars RESTRICTED_INTERPTOARRAY_STRUCT.array2d_vars
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_vars
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_vars RESTRICTED_INTERPTOARRAY_STRUCT.array3d_vars
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__interpolator_coordinates
#  define CCTK_PARAMETER__INTERPTOARRAY__interpolator_coordinates RESTRICTED_INTERPTOARRAY_STRUCT.interpolator_coordinates
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__interpolator_name
#  define CCTK_PARAMETER__INTERPTOARRAY__interpolator_name RESTRICTED_INTERPTOARRAY_STRUCT.interpolator_name
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__interpolator_options
#  define CCTK_PARAMETER__INTERPTOARRAY__interpolator_options RESTRICTED_INTERPTOARRAY_STRUCT.interpolator_options
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_vars
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_vars RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_vars
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_vars
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_vars RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_vars
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_vars
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_vars RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_vars
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__scalar_vars
#  define CCTK_PARAMETER__INTERPTOARRAY__scalar_vars RESTRICTED_INTERPTOARRAY_STRUCT.scalar_vars
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_npoints_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_npoints_i RESTRICTED_INTERPTOARRAY_STRUCT.array1d_npoints_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_spacederivs
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_spacederivs RESTRICTED_INTERPTOARRAY_STRUCT.array1d_spacederivs
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array1d_timederivs
#  define CCTK_PARAMETER__INTERPTOARRAY__array1d_timederivs RESTRICTED_INTERPTOARRAY_STRUCT.array1d_timederivs
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_npoints_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_npoints_i RESTRICTED_INTERPTOARRAY_STRUCT.array2d_npoints_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array2d_npoints_j
#  define CCTK_PARAMETER__INTERPTOARRAY__array2d_npoints_j RESTRICTED_INTERPTOARRAY_STRUCT.array2d_npoints_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_npoints_i
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_npoints_i RESTRICTED_INTERPTOARRAY_STRUCT.array3d_npoints_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_npoints_j
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_npoints_j RESTRICTED_INTERPTOARRAY_STRUCT.array3d_npoints_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__array3d_npoints_k
#  define CCTK_PARAMETER__INTERPTOARRAY__array3d_npoints_k RESTRICTED_INTERPTOARRAY_STRUCT.array3d_npoints_k
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__carpetinterp2_interpolator_order
#  define CCTK_PARAMETER__INTERPTOARRAY__carpetinterp2_interpolator_order RESTRICTED_INTERPTOARRAY_STRUCT.carpetinterp2_interpolator_order
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__narrays1d
#  define CCTK_PARAMETER__INTERPTOARRAY__narrays1d RESTRICTED_INTERPTOARRAY_STRUCT.narrays1d
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__narrays2d
#  define CCTK_PARAMETER__INTERPTOARRAY__narrays2d RESTRICTED_INTERPTOARRAY_STRUCT.narrays2d
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__narrays3d
#  define CCTK_PARAMETER__INTERPTOARRAY__narrays3d RESTRICTED_INTERPTOARRAY_STRUCT.narrays3d
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__nghosts
#  define CCTK_PARAMETER__INTERPTOARRAY__nghosts RESTRICTED_INTERPTOARRAY_STRUCT.nghosts
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__nparrays1d
#  define CCTK_PARAMETER__INTERPTOARRAY__nparrays1d RESTRICTED_INTERPTOARRAY_STRUCT.nparrays1d
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__nparrays2d
#  define CCTK_PARAMETER__INTERPTOARRAY__nparrays2d RESTRICTED_INTERPTOARRAY_STRUCT.nparrays2d
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__nparrays3d
#  define CCTK_PARAMETER__INTERPTOARRAY__nparrays3d RESTRICTED_INTERPTOARRAY_STRUCT.nparrays3d
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__nscalars
#  define CCTK_PARAMETER__INTERPTOARRAY__nscalars RESTRICTED_INTERPTOARRAY_STRUCT.nscalars
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_npoints_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_npoints_i RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_npoints_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_spacederivs
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_spacederivs RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_spacederivs
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray1d_timederivs
#  define CCTK_PARAMETER__INTERPTOARRAY__parray1d_timederivs RESTRICTED_INTERPTOARRAY_STRUCT.parray1d_timederivs
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_npoints_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_npoints_i RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_npoints_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray2d_npoints_j
#  define CCTK_PARAMETER__INTERPTOARRAY__parray2d_npoints_j RESTRICTED_INTERPTOARRAY_STRUCT.parray2d_npoints_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_npoints_i
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_npoints_i RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_npoints_i
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_npoints_j
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_npoints_j RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_npoints_j
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__parray3d_npoints_k
#  define CCTK_PARAMETER__INTERPTOARRAY__parray3d_npoints_k RESTRICTED_INTERPTOARRAY_STRUCT.parray3d_npoints_k
#endif
#ifndef CCTK_PARAMETER__INTERPTOARRAY__use_carpetinterp2
#  define CCTK_PARAMETER__INTERPTOARRAY__use_carpetinterp2 RESTRICTED_INTERPTOARRAY_STRUCT.use_carpetinterp2
#endif

