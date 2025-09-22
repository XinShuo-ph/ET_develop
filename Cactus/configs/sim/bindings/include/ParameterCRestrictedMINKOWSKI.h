#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL boostx;
  CCTK_REAL boosty;
  CCTK_REAL boostz;
  CCTK_REAL lapsefactor;
  CCTK_REAL phi;
  CCTK_REAL positionx;
  CCTK_REAL positiony;
  CCTK_REAL positionz;
  CCTK_REAL psi;
  CCTK_REAL shiftaddx;
  CCTK_REAL shiftaddy;
  CCTK_REAL shiftaddz;
  CCTK_REAL theta;
  CCTK_REAL timeoffset;
  CCTK_INT Minkowski_MaxNumArrayEvolvedVars;
  CCTK_INT Minkowski_MaxNumEvolvedVars;
  CCTK_INT Minkowski_always_calc_every;
  CCTK_INT Minkowski_always_calc_offset;
  CCTK_INT Minkowski_exact_calc_every;
  CCTK_INT Minkowski_exact_calc_offset;
  CCTK_INT Minkowski_initial_calc_every;
  CCTK_INT Minkowski_initial_calc_offset;
  CCTK_INT other_timelevels;
  CCTK_INT rhs_timelevels;
  CCTK_INT tile_size;
  CCTK_INT timelevels;
  CCTK_INT verbose;
} RESTRICTED_MINKOWSKI_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_MINKOWSKI_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, boostx, CCTK_PARAMETER__MINKOWSKI__boostx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boosty, CCTK_PARAMETER__MINKOWSKI__boosty); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boostz, CCTK_PARAMETER__MINKOWSKI__boostz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, lapsefactor, CCTK_PARAMETER__MINKOWSKI__lapsefactor); \
  CCTK_DECLARE_INIT (CCTK_REAL const, phi, CCTK_PARAMETER__MINKOWSKI__phi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positionx, CCTK_PARAMETER__MINKOWSKI__positionx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positiony, CCTK_PARAMETER__MINKOWSKI__positiony); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positionz, CCTK_PARAMETER__MINKOWSKI__positionz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, psi, CCTK_PARAMETER__MINKOWSKI__psi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddx, CCTK_PARAMETER__MINKOWSKI__shiftaddx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddy, CCTK_PARAMETER__MINKOWSKI__shiftaddy); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddz, CCTK_PARAMETER__MINKOWSKI__shiftaddz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, theta, CCTK_PARAMETER__MINKOWSKI__theta); \
  CCTK_DECLARE_INIT (CCTK_REAL const, timeoffset, CCTK_PARAMETER__MINKOWSKI__timeoffset); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_MaxNumArrayEvolvedVars, CCTK_PARAMETER__MINKOWSKI__Minkowski_MaxNumArrayEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_MaxNumEvolvedVars, CCTK_PARAMETER__MINKOWSKI__Minkowski_MaxNumEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_always_calc_every, CCTK_PARAMETER__MINKOWSKI__Minkowski_always_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_always_calc_offset, CCTK_PARAMETER__MINKOWSKI__Minkowski_always_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_exact_calc_every, CCTK_PARAMETER__MINKOWSKI__Minkowski_exact_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_exact_calc_offset, CCTK_PARAMETER__MINKOWSKI__Minkowski_exact_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_initial_calc_every, CCTK_PARAMETER__MINKOWSKI__Minkowski_initial_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, Minkowski_initial_calc_offset, CCTK_PARAMETER__MINKOWSKI__Minkowski_initial_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, other_timelevels, CCTK_PARAMETER__MINKOWSKI__other_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, rhs_timelevels, CCTK_PARAMETER__MINKOWSKI__rhs_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, tile_size, CCTK_PARAMETER__MINKOWSKI__tile_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, timelevels, CCTK_PARAMETER__MINKOWSKI__timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__MINKOWSKI__verbose); \


#ifndef CCTK_PARAMETER__MINKOWSKI__boostx
#  define CCTK_PARAMETER__MINKOWSKI__boostx RESTRICTED_MINKOWSKI_STRUCT.boostx
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__boosty
#  define CCTK_PARAMETER__MINKOWSKI__boosty RESTRICTED_MINKOWSKI_STRUCT.boosty
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__boostz
#  define CCTK_PARAMETER__MINKOWSKI__boostz RESTRICTED_MINKOWSKI_STRUCT.boostz
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__lapsefactor
#  define CCTK_PARAMETER__MINKOWSKI__lapsefactor RESTRICTED_MINKOWSKI_STRUCT.lapsefactor
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__phi
#  define CCTK_PARAMETER__MINKOWSKI__phi RESTRICTED_MINKOWSKI_STRUCT.phi
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__positionx
#  define CCTK_PARAMETER__MINKOWSKI__positionx RESTRICTED_MINKOWSKI_STRUCT.positionx
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__positiony
#  define CCTK_PARAMETER__MINKOWSKI__positiony RESTRICTED_MINKOWSKI_STRUCT.positiony
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__positionz
#  define CCTK_PARAMETER__MINKOWSKI__positionz RESTRICTED_MINKOWSKI_STRUCT.positionz
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__psi
#  define CCTK_PARAMETER__MINKOWSKI__psi RESTRICTED_MINKOWSKI_STRUCT.psi
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__shiftaddx
#  define CCTK_PARAMETER__MINKOWSKI__shiftaddx RESTRICTED_MINKOWSKI_STRUCT.shiftaddx
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__shiftaddy
#  define CCTK_PARAMETER__MINKOWSKI__shiftaddy RESTRICTED_MINKOWSKI_STRUCT.shiftaddy
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__shiftaddz
#  define CCTK_PARAMETER__MINKOWSKI__shiftaddz RESTRICTED_MINKOWSKI_STRUCT.shiftaddz
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__theta
#  define CCTK_PARAMETER__MINKOWSKI__theta RESTRICTED_MINKOWSKI_STRUCT.theta
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__timeoffset
#  define CCTK_PARAMETER__MINKOWSKI__timeoffset RESTRICTED_MINKOWSKI_STRUCT.timeoffset
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__Minkowski_MaxNumArrayEvolvedVars
#  define CCTK_PARAMETER__MINKOWSKI__Minkowski_MaxNumArrayEvolvedVars RESTRICTED_MINKOWSKI_STRUCT.Minkowski_MaxNumArrayEvolvedVars
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__Minkowski_MaxNumEvolvedVars
#  define CCTK_PARAMETER__MINKOWSKI__Minkowski_MaxNumEvolvedVars RESTRICTED_MINKOWSKI_STRUCT.Minkowski_MaxNumEvolvedVars
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__Minkowski_always_calc_every
#  define CCTK_PARAMETER__MINKOWSKI__Minkowski_always_calc_every RESTRICTED_MINKOWSKI_STRUCT.Minkowski_always_calc_every
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__Minkowski_always_calc_offset
#  define CCTK_PARAMETER__MINKOWSKI__Minkowski_always_calc_offset RESTRICTED_MINKOWSKI_STRUCT.Minkowski_always_calc_offset
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__Minkowski_exact_calc_every
#  define CCTK_PARAMETER__MINKOWSKI__Minkowski_exact_calc_every RESTRICTED_MINKOWSKI_STRUCT.Minkowski_exact_calc_every
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__Minkowski_exact_calc_offset
#  define CCTK_PARAMETER__MINKOWSKI__Minkowski_exact_calc_offset RESTRICTED_MINKOWSKI_STRUCT.Minkowski_exact_calc_offset
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__Minkowski_initial_calc_every
#  define CCTK_PARAMETER__MINKOWSKI__Minkowski_initial_calc_every RESTRICTED_MINKOWSKI_STRUCT.Minkowski_initial_calc_every
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__Minkowski_initial_calc_offset
#  define CCTK_PARAMETER__MINKOWSKI__Minkowski_initial_calc_offset RESTRICTED_MINKOWSKI_STRUCT.Minkowski_initial_calc_offset
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__other_timelevels
#  define CCTK_PARAMETER__MINKOWSKI__other_timelevels RESTRICTED_MINKOWSKI_STRUCT.other_timelevels
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__rhs_timelevels
#  define CCTK_PARAMETER__MINKOWSKI__rhs_timelevels RESTRICTED_MINKOWSKI_STRUCT.rhs_timelevels
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__tile_size
#  define CCTK_PARAMETER__MINKOWSKI__tile_size RESTRICTED_MINKOWSKI_STRUCT.tile_size
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__timelevels
#  define CCTK_PARAMETER__MINKOWSKI__timelevels RESTRICTED_MINKOWSKI_STRUCT.timelevels
#endif
#ifndef CCTK_PARAMETER__MINKOWSKI__verbose
#  define CCTK_PARAMETER__MINKOWSKI__verbose RESTRICTED_MINKOWSKI_STRUCT.verbose
#endif

