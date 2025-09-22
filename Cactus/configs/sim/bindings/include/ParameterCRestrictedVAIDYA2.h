#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL M;
  CCTK_REAL boostx;
  CCTK_REAL boosty;
  CCTK_REAL boostz;
  CCTK_REAL dM;
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
  CCTK_INT Vaidya2_MaxNumArrayEvolvedVars;
  CCTK_INT Vaidya2_MaxNumEvolvedVars;
  CCTK_INT Vaidya2_always_calc_every;
  CCTK_INT Vaidya2_always_calc_offset;
  CCTK_INT Vaidya2_exact_calc_every;
  CCTK_INT Vaidya2_exact_calc_offset;
  CCTK_INT Vaidya2_initial_calc_every;
  CCTK_INT Vaidya2_initial_calc_offset;
  CCTK_INT other_timelevels;
  CCTK_INT rhs_timelevels;
  CCTK_INT tile_size;
  CCTK_INT timelevels;
  CCTK_INT verbose;
} RESTRICTED_VAIDYA2_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_VAIDYA2_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, M, CCTK_PARAMETER__VAIDYA2__M); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boostx, CCTK_PARAMETER__VAIDYA2__boostx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boosty, CCTK_PARAMETER__VAIDYA2__boosty); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boostz, CCTK_PARAMETER__VAIDYA2__boostz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, dM, CCTK_PARAMETER__VAIDYA2__dM); \
  CCTK_DECLARE_INIT (CCTK_REAL const, lapsefactor, CCTK_PARAMETER__VAIDYA2__lapsefactor); \
  CCTK_DECLARE_INIT (CCTK_REAL const, phi, CCTK_PARAMETER__VAIDYA2__phi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positionx, CCTK_PARAMETER__VAIDYA2__positionx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positiony, CCTK_PARAMETER__VAIDYA2__positiony); \
  CCTK_DECLARE_INIT (CCTK_REAL const, positionz, CCTK_PARAMETER__VAIDYA2__positionz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, psi, CCTK_PARAMETER__VAIDYA2__psi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddx, CCTK_PARAMETER__VAIDYA2__shiftaddx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddy, CCTK_PARAMETER__VAIDYA2__shiftaddy); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shiftaddz, CCTK_PARAMETER__VAIDYA2__shiftaddz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, theta, CCTK_PARAMETER__VAIDYA2__theta); \
  CCTK_DECLARE_INIT (CCTK_REAL const, timeoffset, CCTK_PARAMETER__VAIDYA2__timeoffset); \
  CCTK_DECLARE_INIT (CCTK_INT const, Vaidya2_MaxNumArrayEvolvedVars, CCTK_PARAMETER__VAIDYA2__Vaidya2_MaxNumArrayEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, Vaidya2_MaxNumEvolvedVars, CCTK_PARAMETER__VAIDYA2__Vaidya2_MaxNumEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, Vaidya2_always_calc_every, CCTK_PARAMETER__VAIDYA2__Vaidya2_always_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, Vaidya2_always_calc_offset, CCTK_PARAMETER__VAIDYA2__Vaidya2_always_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, Vaidya2_exact_calc_every, CCTK_PARAMETER__VAIDYA2__Vaidya2_exact_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, Vaidya2_exact_calc_offset, CCTK_PARAMETER__VAIDYA2__Vaidya2_exact_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, Vaidya2_initial_calc_every, CCTK_PARAMETER__VAIDYA2__Vaidya2_initial_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, Vaidya2_initial_calc_offset, CCTK_PARAMETER__VAIDYA2__Vaidya2_initial_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, other_timelevels, CCTK_PARAMETER__VAIDYA2__other_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, rhs_timelevels, CCTK_PARAMETER__VAIDYA2__rhs_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, tile_size, CCTK_PARAMETER__VAIDYA2__tile_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, timelevels, CCTK_PARAMETER__VAIDYA2__timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__VAIDYA2__verbose); \


#ifndef CCTK_PARAMETER__VAIDYA2__M
#  define CCTK_PARAMETER__VAIDYA2__M RESTRICTED_VAIDYA2_STRUCT.M
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__boostx
#  define CCTK_PARAMETER__VAIDYA2__boostx RESTRICTED_VAIDYA2_STRUCT.boostx
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__boosty
#  define CCTK_PARAMETER__VAIDYA2__boosty RESTRICTED_VAIDYA2_STRUCT.boosty
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__boostz
#  define CCTK_PARAMETER__VAIDYA2__boostz RESTRICTED_VAIDYA2_STRUCT.boostz
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__dM
#  define CCTK_PARAMETER__VAIDYA2__dM RESTRICTED_VAIDYA2_STRUCT.dM
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__lapsefactor
#  define CCTK_PARAMETER__VAIDYA2__lapsefactor RESTRICTED_VAIDYA2_STRUCT.lapsefactor
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__phi
#  define CCTK_PARAMETER__VAIDYA2__phi RESTRICTED_VAIDYA2_STRUCT.phi
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__positionx
#  define CCTK_PARAMETER__VAIDYA2__positionx RESTRICTED_VAIDYA2_STRUCT.positionx
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__positiony
#  define CCTK_PARAMETER__VAIDYA2__positiony RESTRICTED_VAIDYA2_STRUCT.positiony
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__positionz
#  define CCTK_PARAMETER__VAIDYA2__positionz RESTRICTED_VAIDYA2_STRUCT.positionz
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__psi
#  define CCTK_PARAMETER__VAIDYA2__psi RESTRICTED_VAIDYA2_STRUCT.psi
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__shiftaddx
#  define CCTK_PARAMETER__VAIDYA2__shiftaddx RESTRICTED_VAIDYA2_STRUCT.shiftaddx
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__shiftaddy
#  define CCTK_PARAMETER__VAIDYA2__shiftaddy RESTRICTED_VAIDYA2_STRUCT.shiftaddy
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__shiftaddz
#  define CCTK_PARAMETER__VAIDYA2__shiftaddz RESTRICTED_VAIDYA2_STRUCT.shiftaddz
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__theta
#  define CCTK_PARAMETER__VAIDYA2__theta RESTRICTED_VAIDYA2_STRUCT.theta
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__timeoffset
#  define CCTK_PARAMETER__VAIDYA2__timeoffset RESTRICTED_VAIDYA2_STRUCT.timeoffset
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__Vaidya2_MaxNumArrayEvolvedVars
#  define CCTK_PARAMETER__VAIDYA2__Vaidya2_MaxNumArrayEvolvedVars RESTRICTED_VAIDYA2_STRUCT.Vaidya2_MaxNumArrayEvolvedVars
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__Vaidya2_MaxNumEvolvedVars
#  define CCTK_PARAMETER__VAIDYA2__Vaidya2_MaxNumEvolvedVars RESTRICTED_VAIDYA2_STRUCT.Vaidya2_MaxNumEvolvedVars
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__Vaidya2_always_calc_every
#  define CCTK_PARAMETER__VAIDYA2__Vaidya2_always_calc_every RESTRICTED_VAIDYA2_STRUCT.Vaidya2_always_calc_every
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__Vaidya2_always_calc_offset
#  define CCTK_PARAMETER__VAIDYA2__Vaidya2_always_calc_offset RESTRICTED_VAIDYA2_STRUCT.Vaidya2_always_calc_offset
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__Vaidya2_exact_calc_every
#  define CCTK_PARAMETER__VAIDYA2__Vaidya2_exact_calc_every RESTRICTED_VAIDYA2_STRUCT.Vaidya2_exact_calc_every
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__Vaidya2_exact_calc_offset
#  define CCTK_PARAMETER__VAIDYA2__Vaidya2_exact_calc_offset RESTRICTED_VAIDYA2_STRUCT.Vaidya2_exact_calc_offset
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__Vaidya2_initial_calc_every
#  define CCTK_PARAMETER__VAIDYA2__Vaidya2_initial_calc_every RESTRICTED_VAIDYA2_STRUCT.Vaidya2_initial_calc_every
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__Vaidya2_initial_calc_offset
#  define CCTK_PARAMETER__VAIDYA2__Vaidya2_initial_calc_offset RESTRICTED_VAIDYA2_STRUCT.Vaidya2_initial_calc_offset
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__other_timelevels
#  define CCTK_PARAMETER__VAIDYA2__other_timelevels RESTRICTED_VAIDYA2_STRUCT.other_timelevels
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__rhs_timelevels
#  define CCTK_PARAMETER__VAIDYA2__rhs_timelevels RESTRICTED_VAIDYA2_STRUCT.rhs_timelevels
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__tile_size
#  define CCTK_PARAMETER__VAIDYA2__tile_size RESTRICTED_VAIDYA2_STRUCT.tile_size
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__timelevels
#  define CCTK_PARAMETER__VAIDYA2__timelevels RESTRICTED_VAIDYA2_STRUCT.timelevels
#endif
#ifndef CCTK_PARAMETER__VAIDYA2__verbose
#  define CCTK_PARAMETER__VAIDYA2__verbose RESTRICTED_VAIDYA2_STRUCT.verbose
#endif

