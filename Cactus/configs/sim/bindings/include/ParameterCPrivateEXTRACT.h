#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Cauchy_dr;
  CCTK_REAL Cauchy_r1;
  CCTK_REAL detector1;
  CCTK_REAL detector2;
  CCTK_REAL detector3;
  CCTK_REAL detector4;
  CCTK_REAL detector5;
  CCTK_REAL detector6;
  CCTK_REAL detector7;
  CCTK_REAL detector8;
  CCTK_REAL detector9;
  CCTK_REAL origin_x;
  CCTK_REAL origin_y;
  CCTK_REAL origin_z;
  const char * interpolation_operator;
  const char * timecoord;
  CCTK_INT Cauchy;
  CCTK_INT Cauchy_timestep;
  CCTK_INT Np;
  CCTK_INT Nt;
  CCTK_INT all_modes;
  CCTK_INT doADMmass;
  CCTK_INT do_momentum;
  CCTK_INT do_spin;
  CCTK_INT interpolation_order;
  CCTK_INT itout;
  CCTK_INT l_mode;
  CCTK_INT m_mode;
  CCTK_INT num_detectors;
  CCTK_INT verbose;
} PRIVATE_EXTRACT_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_EXTRACT_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, Cauchy_dr, CCTK_PARAMETER__EXTRACT__Cauchy_dr); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Cauchy_r1, CCTK_PARAMETER__EXTRACT__Cauchy_r1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, detector1, CCTK_PARAMETER__EXTRACT__detector1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, detector2, CCTK_PARAMETER__EXTRACT__detector2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, detector3, CCTK_PARAMETER__EXTRACT__detector3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, detector4, CCTK_PARAMETER__EXTRACT__detector4); \
  CCTK_DECLARE_INIT (CCTK_REAL const, detector5, CCTK_PARAMETER__EXTRACT__detector5); \
  CCTK_DECLARE_INIT (CCTK_REAL const, detector6, CCTK_PARAMETER__EXTRACT__detector6); \
  CCTK_DECLARE_INIT (CCTK_REAL const, detector7, CCTK_PARAMETER__EXTRACT__detector7); \
  CCTK_DECLARE_INIT (CCTK_REAL const, detector8, CCTK_PARAMETER__EXTRACT__detector8); \
  CCTK_DECLARE_INIT (CCTK_REAL const, detector9, CCTK_PARAMETER__EXTRACT__detector9); \
  CCTK_DECLARE_INIT (CCTK_REAL const, origin_x, CCTK_PARAMETER__EXTRACT__origin_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, origin_y, CCTK_PARAMETER__EXTRACT__origin_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, origin_z, CCTK_PARAMETER__EXTRACT__origin_z); \
  CCTK_DECLARE_INIT (const char * const, interpolation_operator, CCTK_PARAMETER__EXTRACT__interpolation_operator); \
  CCTK_DECLARE_INIT (const char * const, timecoord, CCTK_PARAMETER__EXTRACT__timecoord); \
  CCTK_DECLARE_INIT (CCTK_INT const, Cauchy, CCTK_PARAMETER__EXTRACT__Cauchy); \
  CCTK_DECLARE_INIT (CCTK_INT const, Cauchy_timestep, CCTK_PARAMETER__EXTRACT__Cauchy_timestep); \
  CCTK_DECLARE_INIT (CCTK_INT const, Np, CCTK_PARAMETER__EXTRACT__Np); \
  CCTK_DECLARE_INIT (CCTK_INT const, Nt, CCTK_PARAMETER__EXTRACT__Nt); \
  CCTK_DECLARE_INIT (CCTK_INT const, all_modes, CCTK_PARAMETER__EXTRACT__all_modes); \
  CCTK_DECLARE_INIT (CCTK_INT const, doADMmass, CCTK_PARAMETER__EXTRACT__doADMmass); \
  CCTK_DECLARE_INIT (CCTK_INT const, do_momentum, CCTK_PARAMETER__EXTRACT__do_momentum); \
  CCTK_DECLARE_INIT (CCTK_INT const, do_spin, CCTK_PARAMETER__EXTRACT__do_spin); \
  CCTK_DECLARE_INIT (CCTK_INT const, interpolation_order, CCTK_PARAMETER__EXTRACT__interpolation_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, itout, CCTK_PARAMETER__EXTRACT__itout); \
  CCTK_DECLARE_INIT (CCTK_INT const, l_mode, CCTK_PARAMETER__EXTRACT__l_mode); \
  CCTK_DECLARE_INIT (CCTK_INT const, m_mode, CCTK_PARAMETER__EXTRACT__m_mode); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_detectors, CCTK_PARAMETER__EXTRACT__num_detectors); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__EXTRACT__verbose); \


#ifndef CCTK_PARAMETER__EXTRACT__Cauchy_dr
#  define CCTK_PARAMETER__EXTRACT__Cauchy_dr PRIVATE_EXTRACT_STRUCT.Cauchy_dr
#endif
#ifndef CCTK_PARAMETER__EXTRACT__Cauchy_r1
#  define CCTK_PARAMETER__EXTRACT__Cauchy_r1 PRIVATE_EXTRACT_STRUCT.Cauchy_r1
#endif
#ifndef CCTK_PARAMETER__EXTRACT__detector1
#  define CCTK_PARAMETER__EXTRACT__detector1 PRIVATE_EXTRACT_STRUCT.detector1
#endif
#ifndef CCTK_PARAMETER__EXTRACT__detector2
#  define CCTK_PARAMETER__EXTRACT__detector2 PRIVATE_EXTRACT_STRUCT.detector2
#endif
#ifndef CCTK_PARAMETER__EXTRACT__detector3
#  define CCTK_PARAMETER__EXTRACT__detector3 PRIVATE_EXTRACT_STRUCT.detector3
#endif
#ifndef CCTK_PARAMETER__EXTRACT__detector4
#  define CCTK_PARAMETER__EXTRACT__detector4 PRIVATE_EXTRACT_STRUCT.detector4
#endif
#ifndef CCTK_PARAMETER__EXTRACT__detector5
#  define CCTK_PARAMETER__EXTRACT__detector5 PRIVATE_EXTRACT_STRUCT.detector5
#endif
#ifndef CCTK_PARAMETER__EXTRACT__detector6
#  define CCTK_PARAMETER__EXTRACT__detector6 PRIVATE_EXTRACT_STRUCT.detector6
#endif
#ifndef CCTK_PARAMETER__EXTRACT__detector7
#  define CCTK_PARAMETER__EXTRACT__detector7 PRIVATE_EXTRACT_STRUCT.detector7
#endif
#ifndef CCTK_PARAMETER__EXTRACT__detector8
#  define CCTK_PARAMETER__EXTRACT__detector8 PRIVATE_EXTRACT_STRUCT.detector8
#endif
#ifndef CCTK_PARAMETER__EXTRACT__detector9
#  define CCTK_PARAMETER__EXTRACT__detector9 PRIVATE_EXTRACT_STRUCT.detector9
#endif
#ifndef CCTK_PARAMETER__EXTRACT__origin_x
#  define CCTK_PARAMETER__EXTRACT__origin_x PRIVATE_EXTRACT_STRUCT.origin_x
#endif
#ifndef CCTK_PARAMETER__EXTRACT__origin_y
#  define CCTK_PARAMETER__EXTRACT__origin_y PRIVATE_EXTRACT_STRUCT.origin_y
#endif
#ifndef CCTK_PARAMETER__EXTRACT__origin_z
#  define CCTK_PARAMETER__EXTRACT__origin_z PRIVATE_EXTRACT_STRUCT.origin_z
#endif
#ifndef CCTK_PARAMETER__EXTRACT__interpolation_operator
#  define CCTK_PARAMETER__EXTRACT__interpolation_operator PRIVATE_EXTRACT_STRUCT.interpolation_operator
#endif
#ifndef CCTK_PARAMETER__EXTRACT__timecoord
#  define CCTK_PARAMETER__EXTRACT__timecoord PRIVATE_EXTRACT_STRUCT.timecoord
#endif
#ifndef CCTK_PARAMETER__EXTRACT__Cauchy
#  define CCTK_PARAMETER__EXTRACT__Cauchy PRIVATE_EXTRACT_STRUCT.Cauchy
#endif
#ifndef CCTK_PARAMETER__EXTRACT__Cauchy_timestep
#  define CCTK_PARAMETER__EXTRACT__Cauchy_timestep PRIVATE_EXTRACT_STRUCT.Cauchy_timestep
#endif
#ifndef CCTK_PARAMETER__EXTRACT__Np
#  define CCTK_PARAMETER__EXTRACT__Np PRIVATE_EXTRACT_STRUCT.Np
#endif
#ifndef CCTK_PARAMETER__EXTRACT__Nt
#  define CCTK_PARAMETER__EXTRACT__Nt PRIVATE_EXTRACT_STRUCT.Nt
#endif
#ifndef CCTK_PARAMETER__EXTRACT__all_modes
#  define CCTK_PARAMETER__EXTRACT__all_modes PRIVATE_EXTRACT_STRUCT.all_modes
#endif
#ifndef CCTK_PARAMETER__EXTRACT__doADMmass
#  define CCTK_PARAMETER__EXTRACT__doADMmass PRIVATE_EXTRACT_STRUCT.doADMmass
#endif
#ifndef CCTK_PARAMETER__EXTRACT__do_momentum
#  define CCTK_PARAMETER__EXTRACT__do_momentum PRIVATE_EXTRACT_STRUCT.do_momentum
#endif
#ifndef CCTK_PARAMETER__EXTRACT__do_spin
#  define CCTK_PARAMETER__EXTRACT__do_spin PRIVATE_EXTRACT_STRUCT.do_spin
#endif
#ifndef CCTK_PARAMETER__EXTRACT__interpolation_order
#  define CCTK_PARAMETER__EXTRACT__interpolation_order PRIVATE_EXTRACT_STRUCT.interpolation_order
#endif
#ifndef CCTK_PARAMETER__EXTRACT__itout
#  define CCTK_PARAMETER__EXTRACT__itout PRIVATE_EXTRACT_STRUCT.itout
#endif
#ifndef CCTK_PARAMETER__EXTRACT__l_mode
#  define CCTK_PARAMETER__EXTRACT__l_mode PRIVATE_EXTRACT_STRUCT.l_mode
#endif
#ifndef CCTK_PARAMETER__EXTRACT__m_mode
#  define CCTK_PARAMETER__EXTRACT__m_mode PRIVATE_EXTRACT_STRUCT.m_mode
#endif
#ifndef CCTK_PARAMETER__EXTRACT__num_detectors
#  define CCTK_PARAMETER__EXTRACT__num_detectors PRIVATE_EXTRACT_STRUCT.num_detectors
#endif
#ifndef CCTK_PARAMETER__EXTRACT__verbose
#  define CCTK_PARAMETER__EXTRACT__verbose PRIVATE_EXTRACT_STRUCT.verbose
#endif

