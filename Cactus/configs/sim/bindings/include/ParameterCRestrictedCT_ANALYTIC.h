#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Kc;
  CCTK_REAL Ke;
  CCTK_REAL Pax;
  CCTK_REAL Pay;
  CCTK_REAL Paz;
  CCTK_REAL Pbx;
  CCTK_REAL Pby;
  CCTK_REAL Pbz;
  CCTK_REAL amp[20];
  CCTK_REAL ampC;
  CCTK_REAL ampC1;
  CCTK_REAL ampG;
  CCTK_REAL ampI;
  CCTK_REAL ampS;
  CCTK_REAL ampSg;
  CCTK_REAL ampV;
  CCTK_REAL ampVG;
  CCTK_REAL edgeL;
  CCTK_REAL eps;
  CCTK_REAL kx;
  CCTK_REAL ky;
  CCTK_REAL kz;
  CCTK_REAL l;
  CCTK_REAL massa;
  CCTK_REAL massb;
  CCTK_REAL phasex;
  CCTK_REAL phasey;
  CCTK_REAL phasez;
  CCTK_REAL rBall;
  CCTK_REAL sigma;
  CCTK_REAL sigmax[20];
  CCTK_REAL sigmay[20];
  CCTK_REAL sigmaz[20];
  CCTK_REAL vecA;
  CCTK_REAL x0[20];
  CCTK_REAL xa;
  CCTK_REAL xb;
  CCTK_REAL y0[20];
  CCTK_REAL ya;
  CCTK_REAL yb;
  CCTK_REAL z0[20];
  CCTK_REAL za;
  CCTK_REAL zb;
  CCTK_INT CT_Analytic_BY_Calc_calc_every;
  CCTK_INT CT_Analytic_BY_Calc_calc_offset;
  CCTK_INT CT_Analytic_ExactBoundary_calc_every;
  CCTK_INT CT_Analytic_ExactBoundary_calc_offset;
  CCTK_INT CT_Analytic_Exact_Calc_calc_every;
  CCTK_INT CT_Analytic_Exact_Calc_calc_offset;
  CCTK_INT CT_Analytic_ExpandingLattice_Calc_calc_every;
  CCTK_INT CT_Analytic_ExpandingLattice_Calc_calc_offset;
  CCTK_INT CT_Analytic_LumpBoundary_calc_every;
  CCTK_INT CT_Analytic_LumpBoundary_calc_offset;
  CCTK_INT CT_Analytic_Lump_Calc_calc_every;
  CCTK_INT CT_Analytic_Lump_Calc_calc_offset;
  CCTK_INT CT_Analytic_MaxNumArrayEvolvedVars;
  CCTK_INT CT_Analytic_MaxNumEvolvedVars;
  CCTK_INT CT_Analytic_Poisson_Calc_calc_every;
  CCTK_INT CT_Analytic_Poisson_Calc_calc_offset;
  CCTK_INT imaxF;
  CCTK_INT jmaxF;
  CCTK_INT kmaxF;
  CCTK_INT other_timelevels;
  CCTK_INT rhs_timelevels;
  CCTK_INT tile_size;
  CCTK_INT timelevels;
  CCTK_INT verbose;
} RESTRICTED_CT_ANALYTIC_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_CT_ANALYTIC_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, Kc, CCTK_PARAMETER__CT_ANALYTIC__Kc); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Ke, CCTK_PARAMETER__CT_ANALYTIC__Ke); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Pax, CCTK_PARAMETER__CT_ANALYTIC__Pax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Pay, CCTK_PARAMETER__CT_ANALYTIC__Pay); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Paz, CCTK_PARAMETER__CT_ANALYTIC__Paz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Pbx, CCTK_PARAMETER__CT_ANALYTIC__Pbx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Pby, CCTK_PARAMETER__CT_ANALYTIC__Pby); \
  CCTK_DECLARE_INIT (CCTK_REAL const, Pbz, CCTK_PARAMETER__CT_ANALYTIC__Pbz); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, amp, CCTK_PARAMETER__CT_ANALYTIC__amp); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ampC, CCTK_PARAMETER__CT_ANALYTIC__ampC); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ampC1, CCTK_PARAMETER__CT_ANALYTIC__ampC1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ampG, CCTK_PARAMETER__CT_ANALYTIC__ampG); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ampI, CCTK_PARAMETER__CT_ANALYTIC__ampI); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ampS, CCTK_PARAMETER__CT_ANALYTIC__ampS); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ampSg, CCTK_PARAMETER__CT_ANALYTIC__ampSg); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ampV, CCTK_PARAMETER__CT_ANALYTIC__ampV); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ampVG, CCTK_PARAMETER__CT_ANALYTIC__ampVG); \
  CCTK_DECLARE_INIT (CCTK_REAL const, edgeL, CCTK_PARAMETER__CT_ANALYTIC__edgeL); \
  CCTK_DECLARE_INIT (CCTK_REAL const, eps, CCTK_PARAMETER__CT_ANALYTIC__eps); \
  CCTK_DECLARE_INIT (CCTK_REAL const, kx, CCTK_PARAMETER__CT_ANALYTIC__kx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ky, CCTK_PARAMETER__CT_ANALYTIC__ky); \
  CCTK_DECLARE_INIT (CCTK_REAL const, kz, CCTK_PARAMETER__CT_ANALYTIC__kz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l, CCTK_PARAMETER__CT_ANALYTIC__l); \
  CCTK_DECLARE_INIT (CCTK_REAL const, massa, CCTK_PARAMETER__CT_ANALYTIC__massa); \
  CCTK_DECLARE_INIT (CCTK_REAL const, massb, CCTK_PARAMETER__CT_ANALYTIC__massb); \
  CCTK_DECLARE_INIT (CCTK_REAL const, phasex, CCTK_PARAMETER__CT_ANALYTIC__phasex); \
  CCTK_DECLARE_INIT (CCTK_REAL const, phasey, CCTK_PARAMETER__CT_ANALYTIC__phasey); \
  CCTK_DECLARE_INIT (CCTK_REAL const, phasez, CCTK_PARAMETER__CT_ANALYTIC__phasez); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rBall, CCTK_PARAMETER__CT_ANALYTIC__rBall); \
  CCTK_DECLARE_INIT (CCTK_REAL const, sigma, CCTK_PARAMETER__CT_ANALYTIC__sigma); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, sigmax, CCTK_PARAMETER__CT_ANALYTIC__sigmax); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, sigmay, CCTK_PARAMETER__CT_ANALYTIC__sigmay); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, sigmaz, CCTK_PARAMETER__CT_ANALYTIC__sigmaz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, vecA, CCTK_PARAMETER__CT_ANALYTIC__vecA); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, x0, CCTK_PARAMETER__CT_ANALYTIC__x0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, xa, CCTK_PARAMETER__CT_ANALYTIC__xa); \
  CCTK_DECLARE_INIT (CCTK_REAL const, xb, CCTK_PARAMETER__CT_ANALYTIC__xb); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, y0, CCTK_PARAMETER__CT_ANALYTIC__y0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ya, CCTK_PARAMETER__CT_ANALYTIC__ya); \
  CCTK_DECLARE_INIT (CCTK_REAL const, yb, CCTK_PARAMETER__CT_ANALYTIC__yb); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, z0, CCTK_PARAMETER__CT_ANALYTIC__z0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, za, CCTK_PARAMETER__CT_ANALYTIC__za); \
  CCTK_DECLARE_INIT (CCTK_REAL const, zb, CCTK_PARAMETER__CT_ANALYTIC__zb); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_BY_Calc_calc_every, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_BY_Calc_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_BY_Calc_calc_offset, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_BY_Calc_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_ExactBoundary_calc_every, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExactBoundary_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_ExactBoundary_calc_offset, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExactBoundary_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_Exact_Calc_calc_every, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Exact_Calc_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_Exact_Calc_calc_offset, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Exact_Calc_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_ExpandingLattice_Calc_calc_every, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExpandingLattice_Calc_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_ExpandingLattice_Calc_calc_offset, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExpandingLattice_Calc_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_LumpBoundary_calc_every, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_LumpBoundary_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_LumpBoundary_calc_offset, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_LumpBoundary_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_Lump_Calc_calc_every, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Lump_Calc_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_Lump_Calc_calc_offset, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Lump_Calc_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_MaxNumArrayEvolvedVars, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_MaxNumArrayEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_MaxNumEvolvedVars, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_MaxNumEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_Poisson_Calc_calc_every, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Poisson_Calc_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, CT_Analytic_Poisson_Calc_calc_offset, CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Poisson_Calc_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, imaxF, CCTK_PARAMETER__CT_ANALYTIC__imaxF); \
  CCTK_DECLARE_INIT (CCTK_INT const, jmaxF, CCTK_PARAMETER__CT_ANALYTIC__jmaxF); \
  CCTK_DECLARE_INIT (CCTK_INT const, kmaxF, CCTK_PARAMETER__CT_ANALYTIC__kmaxF); \
  CCTK_DECLARE_INIT (CCTK_INT const, other_timelevels, CCTK_PARAMETER__CT_ANALYTIC__other_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, rhs_timelevels, CCTK_PARAMETER__CT_ANALYTIC__rhs_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, tile_size, CCTK_PARAMETER__CT_ANALYTIC__tile_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, timelevels, CCTK_PARAMETER__CT_ANALYTIC__timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CT_ANALYTIC__verbose); \


#ifndef CCTK_PARAMETER__CT_ANALYTIC__Kc
#  define CCTK_PARAMETER__CT_ANALYTIC__Kc RESTRICTED_CT_ANALYTIC_STRUCT.Kc
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__Ke
#  define CCTK_PARAMETER__CT_ANALYTIC__Ke RESTRICTED_CT_ANALYTIC_STRUCT.Ke
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__Pax
#  define CCTK_PARAMETER__CT_ANALYTIC__Pax RESTRICTED_CT_ANALYTIC_STRUCT.Pax
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__Pay
#  define CCTK_PARAMETER__CT_ANALYTIC__Pay RESTRICTED_CT_ANALYTIC_STRUCT.Pay
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__Paz
#  define CCTK_PARAMETER__CT_ANALYTIC__Paz RESTRICTED_CT_ANALYTIC_STRUCT.Paz
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__Pbx
#  define CCTK_PARAMETER__CT_ANALYTIC__Pbx RESTRICTED_CT_ANALYTIC_STRUCT.Pbx
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__Pby
#  define CCTK_PARAMETER__CT_ANALYTIC__Pby RESTRICTED_CT_ANALYTIC_STRUCT.Pby
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__Pbz
#  define CCTK_PARAMETER__CT_ANALYTIC__Pbz RESTRICTED_CT_ANALYTIC_STRUCT.Pbz
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__amp
#  define CCTK_PARAMETER__CT_ANALYTIC__amp RESTRICTED_CT_ANALYTIC_STRUCT.amp
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ampC
#  define CCTK_PARAMETER__CT_ANALYTIC__ampC RESTRICTED_CT_ANALYTIC_STRUCT.ampC
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ampC1
#  define CCTK_PARAMETER__CT_ANALYTIC__ampC1 RESTRICTED_CT_ANALYTIC_STRUCT.ampC1
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ampG
#  define CCTK_PARAMETER__CT_ANALYTIC__ampG RESTRICTED_CT_ANALYTIC_STRUCT.ampG
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ampI
#  define CCTK_PARAMETER__CT_ANALYTIC__ampI RESTRICTED_CT_ANALYTIC_STRUCT.ampI
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ampS
#  define CCTK_PARAMETER__CT_ANALYTIC__ampS RESTRICTED_CT_ANALYTIC_STRUCT.ampS
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ampSg
#  define CCTK_PARAMETER__CT_ANALYTIC__ampSg RESTRICTED_CT_ANALYTIC_STRUCT.ampSg
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ampV
#  define CCTK_PARAMETER__CT_ANALYTIC__ampV RESTRICTED_CT_ANALYTIC_STRUCT.ampV
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ampVG
#  define CCTK_PARAMETER__CT_ANALYTIC__ampVG RESTRICTED_CT_ANALYTIC_STRUCT.ampVG
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__edgeL
#  define CCTK_PARAMETER__CT_ANALYTIC__edgeL RESTRICTED_CT_ANALYTIC_STRUCT.edgeL
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__eps
#  define CCTK_PARAMETER__CT_ANALYTIC__eps RESTRICTED_CT_ANALYTIC_STRUCT.eps
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__kx
#  define CCTK_PARAMETER__CT_ANALYTIC__kx RESTRICTED_CT_ANALYTIC_STRUCT.kx
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ky
#  define CCTK_PARAMETER__CT_ANALYTIC__ky RESTRICTED_CT_ANALYTIC_STRUCT.ky
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__kz
#  define CCTK_PARAMETER__CT_ANALYTIC__kz RESTRICTED_CT_ANALYTIC_STRUCT.kz
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__l
#  define CCTK_PARAMETER__CT_ANALYTIC__l RESTRICTED_CT_ANALYTIC_STRUCT.l
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__massa
#  define CCTK_PARAMETER__CT_ANALYTIC__massa RESTRICTED_CT_ANALYTIC_STRUCT.massa
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__massb
#  define CCTK_PARAMETER__CT_ANALYTIC__massb RESTRICTED_CT_ANALYTIC_STRUCT.massb
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__phasex
#  define CCTK_PARAMETER__CT_ANALYTIC__phasex RESTRICTED_CT_ANALYTIC_STRUCT.phasex
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__phasey
#  define CCTK_PARAMETER__CT_ANALYTIC__phasey RESTRICTED_CT_ANALYTIC_STRUCT.phasey
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__phasez
#  define CCTK_PARAMETER__CT_ANALYTIC__phasez RESTRICTED_CT_ANALYTIC_STRUCT.phasez
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__rBall
#  define CCTK_PARAMETER__CT_ANALYTIC__rBall RESTRICTED_CT_ANALYTIC_STRUCT.rBall
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__sigma
#  define CCTK_PARAMETER__CT_ANALYTIC__sigma RESTRICTED_CT_ANALYTIC_STRUCT.sigma
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__sigmax
#  define CCTK_PARAMETER__CT_ANALYTIC__sigmax RESTRICTED_CT_ANALYTIC_STRUCT.sigmax
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__sigmay
#  define CCTK_PARAMETER__CT_ANALYTIC__sigmay RESTRICTED_CT_ANALYTIC_STRUCT.sigmay
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__sigmaz
#  define CCTK_PARAMETER__CT_ANALYTIC__sigmaz RESTRICTED_CT_ANALYTIC_STRUCT.sigmaz
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__vecA
#  define CCTK_PARAMETER__CT_ANALYTIC__vecA RESTRICTED_CT_ANALYTIC_STRUCT.vecA
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__x0
#  define CCTK_PARAMETER__CT_ANALYTIC__x0 RESTRICTED_CT_ANALYTIC_STRUCT.x0
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__xa
#  define CCTK_PARAMETER__CT_ANALYTIC__xa RESTRICTED_CT_ANALYTIC_STRUCT.xa
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__xb
#  define CCTK_PARAMETER__CT_ANALYTIC__xb RESTRICTED_CT_ANALYTIC_STRUCT.xb
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__y0
#  define CCTK_PARAMETER__CT_ANALYTIC__y0 RESTRICTED_CT_ANALYTIC_STRUCT.y0
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__ya
#  define CCTK_PARAMETER__CT_ANALYTIC__ya RESTRICTED_CT_ANALYTIC_STRUCT.ya
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__yb
#  define CCTK_PARAMETER__CT_ANALYTIC__yb RESTRICTED_CT_ANALYTIC_STRUCT.yb
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__z0
#  define CCTK_PARAMETER__CT_ANALYTIC__z0 RESTRICTED_CT_ANALYTIC_STRUCT.z0
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__za
#  define CCTK_PARAMETER__CT_ANALYTIC__za RESTRICTED_CT_ANALYTIC_STRUCT.za
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__zb
#  define CCTK_PARAMETER__CT_ANALYTIC__zb RESTRICTED_CT_ANALYTIC_STRUCT.zb
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_BY_Calc_calc_every
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_BY_Calc_calc_every RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_BY_Calc_calc_every
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_BY_Calc_calc_offset
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_BY_Calc_calc_offset RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_BY_Calc_calc_offset
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExactBoundary_calc_every
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExactBoundary_calc_every RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_ExactBoundary_calc_every
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExactBoundary_calc_offset
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExactBoundary_calc_offset RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_ExactBoundary_calc_offset
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Exact_Calc_calc_every
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Exact_Calc_calc_every RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_Exact_Calc_calc_every
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Exact_Calc_calc_offset
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Exact_Calc_calc_offset RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_Exact_Calc_calc_offset
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExpandingLattice_Calc_calc_every
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExpandingLattice_Calc_calc_every RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_ExpandingLattice_Calc_calc_every
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExpandingLattice_Calc_calc_offset
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_ExpandingLattice_Calc_calc_offset RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_ExpandingLattice_Calc_calc_offset
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_LumpBoundary_calc_every
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_LumpBoundary_calc_every RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_LumpBoundary_calc_every
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_LumpBoundary_calc_offset
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_LumpBoundary_calc_offset RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_LumpBoundary_calc_offset
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Lump_Calc_calc_every
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Lump_Calc_calc_every RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_Lump_Calc_calc_every
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Lump_Calc_calc_offset
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Lump_Calc_calc_offset RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_Lump_Calc_calc_offset
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_MaxNumArrayEvolvedVars
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_MaxNumArrayEvolvedVars RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_MaxNumArrayEvolvedVars
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_MaxNumEvolvedVars
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_MaxNumEvolvedVars RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_MaxNumEvolvedVars
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Poisson_Calc_calc_every
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Poisson_Calc_calc_every RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_Poisson_Calc_calc_every
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Poisson_Calc_calc_offset
#  define CCTK_PARAMETER__CT_ANALYTIC__CT_Analytic_Poisson_Calc_calc_offset RESTRICTED_CT_ANALYTIC_STRUCT.CT_Analytic_Poisson_Calc_calc_offset
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__imaxF
#  define CCTK_PARAMETER__CT_ANALYTIC__imaxF RESTRICTED_CT_ANALYTIC_STRUCT.imaxF
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__jmaxF
#  define CCTK_PARAMETER__CT_ANALYTIC__jmaxF RESTRICTED_CT_ANALYTIC_STRUCT.jmaxF
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__kmaxF
#  define CCTK_PARAMETER__CT_ANALYTIC__kmaxF RESTRICTED_CT_ANALYTIC_STRUCT.kmaxF
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__other_timelevels
#  define CCTK_PARAMETER__CT_ANALYTIC__other_timelevels RESTRICTED_CT_ANALYTIC_STRUCT.other_timelevels
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__rhs_timelevels
#  define CCTK_PARAMETER__CT_ANALYTIC__rhs_timelevels RESTRICTED_CT_ANALYTIC_STRUCT.rhs_timelevels
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__tile_size
#  define CCTK_PARAMETER__CT_ANALYTIC__tile_size RESTRICTED_CT_ANALYTIC_STRUCT.tile_size
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__timelevels
#  define CCTK_PARAMETER__CT_ANALYTIC__timelevels RESTRICTED_CT_ANALYTIC_STRUCT.timelevels
#endif
#ifndef CCTK_PARAMETER__CT_ANALYTIC__verbose
#  define CCTK_PARAMETER__CT_ANALYTIC__verbose RESTRICTED_CT_ANALYTIC_STRUCT.verbose
#endif

