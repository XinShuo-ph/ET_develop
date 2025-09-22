#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL radius[101];
  const char * coord_system;
  const char * integration_method;
  const char * interpolator_name;
  const char * interpolator_pars;
  const char * mode_type;
  const char * variables;
  CCTK_INT enable_test;
  CCTK_INT hdf5_chunk_size;
  CCTK_INT l_max;
  CCTK_INT l_min;
  CCTK_INT l_mode;
  CCTK_INT m_mode;
  CCTK_INT nphi;
  CCTK_INT nradii;
  CCTK_INT ntheta;
  CCTK_INT out_1d_every;
  CCTK_INT out_every;
  CCTK_INT output_ascii;
  CCTK_INT output_hdf5;
  CCTK_INT test_l;
  CCTK_INT test_m;
  CCTK_INT test_mode_proportional_to_r;
  CCTK_INT test_sw;
  CCTK_INT verbose;
} RESTRICTED_MULTIPOLE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_MULTIPOLE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius, CCTK_PARAMETER__MULTIPOLE__radius); \
  CCTK_DECLARE_INIT (const char * const, coord_system, CCTK_PARAMETER__MULTIPOLE__coord_system); \
  CCTK_DECLARE_INIT (const char * const, integration_method, CCTK_PARAMETER__MULTIPOLE__integration_method); \
  CCTK_DECLARE_INIT (const char * const, interpolator_name, CCTK_PARAMETER__MULTIPOLE__interpolator_name); \
  CCTK_DECLARE_INIT (const char * const, interpolator_pars, CCTK_PARAMETER__MULTIPOLE__interpolator_pars); \
  CCTK_DECLARE_INIT (const char * const, mode_type, CCTK_PARAMETER__MULTIPOLE__mode_type); \
  CCTK_DECLARE_INIT (const char * const, variables, CCTK_PARAMETER__MULTIPOLE__variables); \
  CCTK_DECLARE_INIT (CCTK_INT const, enable_test, CCTK_PARAMETER__MULTIPOLE__enable_test); \
  CCTK_DECLARE_INIT (CCTK_INT const, hdf5_chunk_size, CCTK_PARAMETER__MULTIPOLE__hdf5_chunk_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, l_max, CCTK_PARAMETER__MULTIPOLE__l_max); \
  CCTK_DECLARE_INIT (CCTK_INT const, l_min, CCTK_PARAMETER__MULTIPOLE__l_min); \
  CCTK_DECLARE_INIT (CCTK_INT const, l_mode, CCTK_PARAMETER__MULTIPOLE__l_mode); \
  CCTK_DECLARE_INIT (CCTK_INT const, m_mode, CCTK_PARAMETER__MULTIPOLE__m_mode); \
  CCTK_DECLARE_INIT (CCTK_INT const, nphi, CCTK_PARAMETER__MULTIPOLE__nphi); \
  CCTK_DECLARE_INIT (CCTK_INT const, nradii, CCTK_PARAMETER__MULTIPOLE__nradii); \
  CCTK_DECLARE_INIT (CCTK_INT const, ntheta, CCTK_PARAMETER__MULTIPOLE__ntheta); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_1d_every, CCTK_PARAMETER__MULTIPOLE__out_1d_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_every, CCTK_PARAMETER__MULTIPOLE__out_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_ascii, CCTK_PARAMETER__MULTIPOLE__output_ascii); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_hdf5, CCTK_PARAMETER__MULTIPOLE__output_hdf5); \
  CCTK_DECLARE_INIT (CCTK_INT const, test_l, CCTK_PARAMETER__MULTIPOLE__test_l); \
  CCTK_DECLARE_INIT (CCTK_INT const, test_m, CCTK_PARAMETER__MULTIPOLE__test_m); \
  CCTK_DECLARE_INIT (CCTK_INT const, test_mode_proportional_to_r, CCTK_PARAMETER__MULTIPOLE__test_mode_proportional_to_r); \
  CCTK_DECLARE_INIT (CCTK_INT const, test_sw, CCTK_PARAMETER__MULTIPOLE__test_sw); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__MULTIPOLE__verbose); \


#ifndef CCTK_PARAMETER__MULTIPOLE__radius
#  define CCTK_PARAMETER__MULTIPOLE__radius RESTRICTED_MULTIPOLE_STRUCT.radius
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__coord_system
#  define CCTK_PARAMETER__MULTIPOLE__coord_system RESTRICTED_MULTIPOLE_STRUCT.coord_system
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__integration_method
#  define CCTK_PARAMETER__MULTIPOLE__integration_method RESTRICTED_MULTIPOLE_STRUCT.integration_method
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__interpolator_name
#  define CCTK_PARAMETER__MULTIPOLE__interpolator_name RESTRICTED_MULTIPOLE_STRUCT.interpolator_name
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__interpolator_pars
#  define CCTK_PARAMETER__MULTIPOLE__interpolator_pars RESTRICTED_MULTIPOLE_STRUCT.interpolator_pars
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__mode_type
#  define CCTK_PARAMETER__MULTIPOLE__mode_type RESTRICTED_MULTIPOLE_STRUCT.mode_type
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__variables
#  define CCTK_PARAMETER__MULTIPOLE__variables RESTRICTED_MULTIPOLE_STRUCT.variables
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__enable_test
#  define CCTK_PARAMETER__MULTIPOLE__enable_test RESTRICTED_MULTIPOLE_STRUCT.enable_test
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__hdf5_chunk_size
#  define CCTK_PARAMETER__MULTIPOLE__hdf5_chunk_size RESTRICTED_MULTIPOLE_STRUCT.hdf5_chunk_size
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__l_max
#  define CCTK_PARAMETER__MULTIPOLE__l_max RESTRICTED_MULTIPOLE_STRUCT.l_max
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__l_min
#  define CCTK_PARAMETER__MULTIPOLE__l_min RESTRICTED_MULTIPOLE_STRUCT.l_min
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__l_mode
#  define CCTK_PARAMETER__MULTIPOLE__l_mode RESTRICTED_MULTIPOLE_STRUCT.l_mode
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__m_mode
#  define CCTK_PARAMETER__MULTIPOLE__m_mode RESTRICTED_MULTIPOLE_STRUCT.m_mode
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__nphi
#  define CCTK_PARAMETER__MULTIPOLE__nphi RESTRICTED_MULTIPOLE_STRUCT.nphi
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__nradii
#  define CCTK_PARAMETER__MULTIPOLE__nradii RESTRICTED_MULTIPOLE_STRUCT.nradii
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__ntheta
#  define CCTK_PARAMETER__MULTIPOLE__ntheta RESTRICTED_MULTIPOLE_STRUCT.ntheta
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__out_1d_every
#  define CCTK_PARAMETER__MULTIPOLE__out_1d_every RESTRICTED_MULTIPOLE_STRUCT.out_1d_every
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__out_every
#  define CCTK_PARAMETER__MULTIPOLE__out_every RESTRICTED_MULTIPOLE_STRUCT.out_every
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__output_ascii
#  define CCTK_PARAMETER__MULTIPOLE__output_ascii RESTRICTED_MULTIPOLE_STRUCT.output_ascii
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__output_hdf5
#  define CCTK_PARAMETER__MULTIPOLE__output_hdf5 RESTRICTED_MULTIPOLE_STRUCT.output_hdf5
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__test_l
#  define CCTK_PARAMETER__MULTIPOLE__test_l RESTRICTED_MULTIPOLE_STRUCT.test_l
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__test_m
#  define CCTK_PARAMETER__MULTIPOLE__test_m RESTRICTED_MULTIPOLE_STRUCT.test_m
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__test_mode_proportional_to_r
#  define CCTK_PARAMETER__MULTIPOLE__test_mode_proportional_to_r RESTRICTED_MULTIPOLE_STRUCT.test_mode_proportional_to_r
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__test_sw
#  define CCTK_PARAMETER__MULTIPOLE__test_sw RESTRICTED_MULTIPOLE_STRUCT.test_sw
#endif
#ifndef CCTK_PARAMETER__MULTIPOLE__verbose
#  define CCTK_PARAMETER__MULTIPOLE__verbose RESTRICTED_MULTIPOLE_STRUCT.verbose
#endif

