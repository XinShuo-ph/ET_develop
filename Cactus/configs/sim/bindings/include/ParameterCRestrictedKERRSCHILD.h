#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL M;
  CCTK_REAL a;
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
  CCTK_INT KerrSchild_MaxNumArrayEvolvedVars;
  CCTK_INT KerrSchild_MaxNumEvolvedVars;
  CCTK_INT KerrSchild_always_calc_every;
  CCTK_INT KerrSchild_always_calc_offset;
  CCTK_INT KerrSchild_exact_calc_every;
  CCTK_INT KerrSchild_exact_calc_offset;
  CCTK_INT KerrSchild_initial_calc_every;
  CCTK_INT KerrSchild_initial_calc_offset;
  CCTK_INT other_timelevels;
  CCTK_INT rhs_timelevels;
  CCTK_INT tile_size;
  CCTK_INT timelevels;
  CCTK_INT verbose;
} RESTRICTED_KERRSCHILD_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_KERRSCHILD_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, M, CCTK_PARAMETER__KERRSCHILD__M); \
  CCTK_DECLARE_INIT (CCTK_REAL const, a, CCTK_PARAMETER__KERRSCHILD__a); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boostx, CCTK_PARAMETER__KERRSCHILD__boostx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boosty, CCTK_PARAMETER__KERRSCHILD__boosty); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boostz, CCTK_PARAMETER__KERRSCHILD__boostz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, lapsefactor, CCTK_PARAMETER__KERRSCHILD__lapsefactor); \
  CCTK_DECLARE_INIT (CCTK_REAL const, phi, CCTK_PARAMETER__KERRSCHILD__phi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positionx, CCTK_PARAMETER__KERRSCHILD__positionx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positiony, CCTK_PARAMETER__KERRSCHILD__positiony); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positionz, CCTK_PARAMETER__KERRSCHILD__positionz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, psi, CCTK_PARAMETER__KERRSCHILD__psi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddx, CCTK_PARAMETER__KERRSCHILD__shiftaddx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddy, CCTK_PARAMETER__KERRSCHILD__shiftaddy); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddz, CCTK_PARAMETER__KERRSCHILD__shiftaddz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, theta, CCTK_PARAMETER__KERRSCHILD__theta); \
  CCTK_DECLARE_INIT (CCTK_REAL const, timeoffset, CCTK_PARAMETER__KERRSCHILD__timeoffset); \
  CCTK_DECLARE_INIT (CCTK_INT const, KerrSchild_MaxNumArrayEvolvedVars, CCTK_PARAMETER__KERRSCHILD__KerrSchild_MaxNumArrayEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, KerrSchild_MaxNumEvolvedVars, CCTK_PARAMETER__KERRSCHILD__KerrSchild_MaxNumEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, KerrSchild_always_calc_every, CCTK_PARAMETER__KERRSCHILD__KerrSchild_always_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, KerrSchild_always_calc_offset, CCTK_PARAMETER__KERRSCHILD__KerrSchild_always_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, KerrSchild_exact_calc_every, CCTK_PARAMETER__KERRSCHILD__KerrSchild_exact_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, KerrSchild_exact_calc_offset, CCTK_PARAMETER__KERRSCHILD__KerrSchild_exact_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, KerrSchild_initial_calc_every, CCTK_PARAMETER__KERRSCHILD__KerrSchild_initial_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, KerrSchild_initial_calc_offset, CCTK_PARAMETER__KERRSCHILD__KerrSchild_initial_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, other_timelevels, CCTK_PARAMETER__KERRSCHILD__other_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, rhs_timelevels, CCTK_PARAMETER__KERRSCHILD__rhs_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, tile_size, CCTK_PARAMETER__KERRSCHILD__tile_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, timelevels, CCTK_PARAMETER__KERRSCHILD__timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__KERRSCHILD__verbose); \


#ifndef CCTK_PARAMETER__KERRSCHILD__M
#  define CCTK_PARAMETER__KERRSCHILD__M RESTRICTED_KERRSCHILD_STRUCT.M
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__a
#  define CCTK_PARAMETER__KERRSCHILD__a RESTRICTED_KERRSCHILD_STRUCT.a
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__boostx
#  define CCTK_PARAMETER__KERRSCHILD__boostx RESTRICTED_KERRSCHILD_STRUCT.boostx
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__boosty
#  define CCTK_PARAMETER__KERRSCHILD__boosty RESTRICTED_KERRSCHILD_STRUCT.boosty
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__boostz
#  define CCTK_PARAMETER__KERRSCHILD__boostz RESTRICTED_KERRSCHILD_STRUCT.boostz
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__lapsefactor
#  define CCTK_PARAMETER__KERRSCHILD__lapsefactor RESTRICTED_KERRSCHILD_STRUCT.lapsefactor
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__phi
#  define CCTK_PARAMETER__KERRSCHILD__phi RESTRICTED_KERRSCHILD_STRUCT.phi
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__positionx
#  define CCTK_PARAMETER__KERRSCHILD__positionx RESTRICTED_KERRSCHILD_STRUCT.positionx
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__positiony
#  define CCTK_PARAMETER__KERRSCHILD__positiony RESTRICTED_KERRSCHILD_STRUCT.positiony
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__positionz
#  define CCTK_PARAMETER__KERRSCHILD__positionz RESTRICTED_KERRSCHILD_STRUCT.positionz
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__psi
#  define CCTK_PARAMETER__KERRSCHILD__psi RESTRICTED_KERRSCHILD_STRUCT.psi
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__shiftaddx
#  define CCTK_PARAMETER__KERRSCHILD__shiftaddx RESTRICTED_KERRSCHILD_STRUCT.shiftaddx
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__shiftaddy
#  define CCTK_PARAMETER__KERRSCHILD__shiftaddy RESTRICTED_KERRSCHILD_STRUCT.shiftaddy
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__shiftaddz
#  define CCTK_PARAMETER__KERRSCHILD__shiftaddz RESTRICTED_KERRSCHILD_STRUCT.shiftaddz
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__theta
#  define CCTK_PARAMETER__KERRSCHILD__theta RESTRICTED_KERRSCHILD_STRUCT.theta
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__timeoffset
#  define CCTK_PARAMETER__KERRSCHILD__timeoffset RESTRICTED_KERRSCHILD_STRUCT.timeoffset
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__KerrSchild_MaxNumArrayEvolvedVars
#  define CCTK_PARAMETER__KERRSCHILD__KerrSchild_MaxNumArrayEvolvedVars RESTRICTED_KERRSCHILD_STRUCT.KerrSchild_MaxNumArrayEvolvedVars
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__KerrSchild_MaxNumEvolvedVars
#  define CCTK_PARAMETER__KERRSCHILD__KerrSchild_MaxNumEvolvedVars RESTRICTED_KERRSCHILD_STRUCT.KerrSchild_MaxNumEvolvedVars
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__KerrSchild_always_calc_every
#  define CCTK_PARAMETER__KERRSCHILD__KerrSchild_always_calc_every RESTRICTED_KERRSCHILD_STRUCT.KerrSchild_always_calc_every
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__KerrSchild_always_calc_offset
#  define CCTK_PARAMETER__KERRSCHILD__KerrSchild_always_calc_offset RESTRICTED_KERRSCHILD_STRUCT.KerrSchild_always_calc_offset
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__KerrSchild_exact_calc_every
#  define CCTK_PARAMETER__KERRSCHILD__KerrSchild_exact_calc_every RESTRICTED_KERRSCHILD_STRUCT.KerrSchild_exact_calc_every
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__KerrSchild_exact_calc_offset
#  define CCTK_PARAMETER__KERRSCHILD__KerrSchild_exact_calc_offset RESTRICTED_KERRSCHILD_STRUCT.KerrSchild_exact_calc_offset
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__KerrSchild_initial_calc_every
#  define CCTK_PARAMETER__KERRSCHILD__KerrSchild_initial_calc_every RESTRICTED_KERRSCHILD_STRUCT.KerrSchild_initial_calc_every
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__KerrSchild_initial_calc_offset
#  define CCTK_PARAMETER__KERRSCHILD__KerrSchild_initial_calc_offset RESTRICTED_KERRSCHILD_STRUCT.KerrSchild_initial_calc_offset
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__other_timelevels
#  define CCTK_PARAMETER__KERRSCHILD__other_timelevels RESTRICTED_KERRSCHILD_STRUCT.other_timelevels
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__rhs_timelevels
#  define CCTK_PARAMETER__KERRSCHILD__rhs_timelevels RESTRICTED_KERRSCHILD_STRUCT.rhs_timelevels
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__tile_size
#  define CCTK_PARAMETER__KERRSCHILD__tile_size RESTRICTED_KERRSCHILD_STRUCT.tile_size
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__timelevels
#  define CCTK_PARAMETER__KERRSCHILD__timelevels RESTRICTED_KERRSCHILD_STRUCT.timelevels
#endif
#ifndef CCTK_PARAMETER__KERRSCHILD__verbose
#  define CCTK_PARAMETER__KERRSCHILD__verbose RESTRICTED_KERRSCHILD_STRUCT.verbose
#endif

