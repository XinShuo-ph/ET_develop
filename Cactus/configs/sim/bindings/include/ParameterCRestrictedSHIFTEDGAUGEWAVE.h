#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL amp;
  CCTK_REAL boostx;
  CCTK_REAL boosty;
  CCTK_REAL boostz;
  CCTK_REAL lapsefactor;
  CCTK_REAL period;
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
  CCTK_INT ShiftedGaugeWave_MaxNumArrayEvolvedVars;
  CCTK_INT ShiftedGaugeWave_MaxNumEvolvedVars;
  CCTK_INT ShiftedGaugeWave_always_calc_every;
  CCTK_INT ShiftedGaugeWave_always_calc_offset;
  CCTK_INT ShiftedGaugeWave_exact_calc_every;
  CCTK_INT ShiftedGaugeWave_exact_calc_offset;
  CCTK_INT ShiftedGaugeWave_initial_calc_every;
  CCTK_INT ShiftedGaugeWave_initial_calc_offset;
  CCTK_INT other_timelevels;
  CCTK_INT rhs_timelevels;
  CCTK_INT tile_size;
  CCTK_INT timelevels;
  CCTK_INT verbose;
} RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, amp, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__amp); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boostx, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__boostx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boosty, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__boosty); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boostz, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__boostz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, lapsefactor, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__lapsefactor); \
  CCTK_DECLARE_INIT (CCTK_REAL const, period, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__period); \
  CCTK_DECLARE_INIT (CCTK_REAL const, phi, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__phi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positionx, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__positionx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positiony, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__positiony); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positionz, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__positionz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, psi, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__psi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddx, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__shiftaddx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddy, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__shiftaddy); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddz, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__shiftaddz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, theta, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__theta); \
  CCTK_DECLARE_INIT (CCTK_REAL const, timeoffset, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__timeoffset); \
  CCTK_DECLARE_INIT (CCTK_INT const, ShiftedGaugeWave_MaxNumArrayEvolvedVars, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_MaxNumArrayEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, ShiftedGaugeWave_MaxNumEvolvedVars, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_MaxNumEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, ShiftedGaugeWave_always_calc_every, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_always_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, ShiftedGaugeWave_always_calc_offset, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_always_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, ShiftedGaugeWave_exact_calc_every, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_exact_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, ShiftedGaugeWave_exact_calc_offset, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_exact_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, ShiftedGaugeWave_initial_calc_every, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_initial_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, ShiftedGaugeWave_initial_calc_offset, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_initial_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, other_timelevels, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__other_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, rhs_timelevels, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__rhs_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, tile_size, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__tile_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, timelevels, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__SHIFTEDGAUGEWAVE__verbose); \


#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__amp
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__amp RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.amp
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__boostx
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__boostx RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.boostx
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__boosty
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__boosty RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.boosty
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__boostz
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__boostz RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.boostz
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__lapsefactor
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__lapsefactor RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.lapsefactor
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__period
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__period RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.period
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__phi
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__phi RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.phi
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__positionx
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__positionx RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.positionx
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__positiony
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__positiony RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.positiony
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__positionz
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__positionz RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.positionz
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__psi
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__psi RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.psi
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__shiftaddx
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__shiftaddx RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.shiftaddx
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__shiftaddy
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__shiftaddy RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.shiftaddy
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__shiftaddz
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__shiftaddz RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.shiftaddz
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__theta
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__theta RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.theta
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__timeoffset
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__timeoffset RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.timeoffset
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_MaxNumArrayEvolvedVars
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_MaxNumArrayEvolvedVars RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.ShiftedGaugeWave_MaxNumArrayEvolvedVars
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_MaxNumEvolvedVars
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_MaxNumEvolvedVars RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.ShiftedGaugeWave_MaxNumEvolvedVars
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_always_calc_every
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_always_calc_every RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.ShiftedGaugeWave_always_calc_every
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_always_calc_offset
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_always_calc_offset RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.ShiftedGaugeWave_always_calc_offset
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_exact_calc_every
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_exact_calc_every RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.ShiftedGaugeWave_exact_calc_every
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_exact_calc_offset
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_exact_calc_offset RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.ShiftedGaugeWave_exact_calc_offset
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_initial_calc_every
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_initial_calc_every RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.ShiftedGaugeWave_initial_calc_every
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_initial_calc_offset
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__ShiftedGaugeWave_initial_calc_offset RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.ShiftedGaugeWave_initial_calc_offset
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__other_timelevels
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__other_timelevels RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.other_timelevels
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__rhs_timelevels
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__rhs_timelevels RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.rhs_timelevels
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__tile_size
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__tile_size RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.tile_size
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__timelevels
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__timelevels RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.timelevels
#endif
#ifndef CCTK_PARAMETER__SHIFTEDGAUGEWAVE__verbose
#  define CCTK_PARAMETER__SHIFTEDGAUGEWAVE__verbose RESTRICTED_SHIFTEDGAUGEWAVE_STRUCT.verbose
#endif

