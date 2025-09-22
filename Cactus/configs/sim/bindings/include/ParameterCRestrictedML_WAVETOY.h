#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL amplitude;
  CCTK_REAL width;
  CCTK_INT ML_WaveToy_MaxNumArrayEvolvedVars;
  CCTK_INT ML_WaveToy_MaxNumEvolvedVars;
  CCTK_INT WT_Dirichlet_calc_every;
  CCTK_INT WT_Dirichlet_calc_offset;
  CCTK_INT WT_EnergyBoundary_calc_every;
  CCTK_INT WT_EnergyBoundary_calc_offset;
  CCTK_INT WT_Energy_calc_every;
  CCTK_INT WT_Energy_calc_offset;
  CCTK_INT WT_Gaussian_calc_every;
  CCTK_INT WT_Gaussian_calc_offset;
  CCTK_INT WT_RHS_calc_every;
  CCTK_INT WT_RHS_calc_offset;
  CCTK_INT WT_Standing_calc_every;
  CCTK_INT WT_Standing_calc_offset;
  CCTK_INT other_timelevels;
  CCTK_INT rhs_timelevels;
  CCTK_INT tile_size;
  CCTK_INT timelevels;
  CCTK_INT verbose;
} RESTRICTED_ML_WAVETOY_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_ML_WAVETOY_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, amplitude, CCTK_PARAMETER__ML_WAVETOY__amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, width, CCTK_PARAMETER__ML_WAVETOY__width); \
  CCTK_DECLARE_INIT (CCTK_INT const, ML_WaveToy_MaxNumArrayEvolvedVars, CCTK_PARAMETER__ML_WAVETOY__ML_WaveToy_MaxNumArrayEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, ML_WaveToy_MaxNumEvolvedVars, CCTK_PARAMETER__ML_WAVETOY__ML_WaveToy_MaxNumEvolvedVars); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_Dirichlet_calc_every, CCTK_PARAMETER__ML_WAVETOY__WT_Dirichlet_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_Dirichlet_calc_offset, CCTK_PARAMETER__ML_WAVETOY__WT_Dirichlet_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_EnergyBoundary_calc_every, CCTK_PARAMETER__ML_WAVETOY__WT_EnergyBoundary_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_EnergyBoundary_calc_offset, CCTK_PARAMETER__ML_WAVETOY__WT_EnergyBoundary_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_Energy_calc_every, CCTK_PARAMETER__ML_WAVETOY__WT_Energy_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_Energy_calc_offset, CCTK_PARAMETER__ML_WAVETOY__WT_Energy_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_Gaussian_calc_every, CCTK_PARAMETER__ML_WAVETOY__WT_Gaussian_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_Gaussian_calc_offset, CCTK_PARAMETER__ML_WAVETOY__WT_Gaussian_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_RHS_calc_every, CCTK_PARAMETER__ML_WAVETOY__WT_RHS_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_RHS_calc_offset, CCTK_PARAMETER__ML_WAVETOY__WT_RHS_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_Standing_calc_every, CCTK_PARAMETER__ML_WAVETOY__WT_Standing_calc_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, WT_Standing_calc_offset, CCTK_PARAMETER__ML_WAVETOY__WT_Standing_calc_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, other_timelevels, CCTK_PARAMETER__ML_WAVETOY__other_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, rhs_timelevels, CCTK_PARAMETER__ML_WAVETOY__rhs_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, tile_size, CCTK_PARAMETER__ML_WAVETOY__tile_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, timelevels, CCTK_PARAMETER__ML_WAVETOY__timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__ML_WAVETOY__verbose); \


#ifndef CCTK_PARAMETER__ML_WAVETOY__amplitude
#  define CCTK_PARAMETER__ML_WAVETOY__amplitude RESTRICTED_ML_WAVETOY_STRUCT.amplitude
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__width
#  define CCTK_PARAMETER__ML_WAVETOY__width RESTRICTED_ML_WAVETOY_STRUCT.width
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__ML_WaveToy_MaxNumArrayEvolvedVars
#  define CCTK_PARAMETER__ML_WAVETOY__ML_WaveToy_MaxNumArrayEvolvedVars RESTRICTED_ML_WAVETOY_STRUCT.ML_WaveToy_MaxNumArrayEvolvedVars
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__ML_WaveToy_MaxNumEvolvedVars
#  define CCTK_PARAMETER__ML_WAVETOY__ML_WaveToy_MaxNumEvolvedVars RESTRICTED_ML_WAVETOY_STRUCT.ML_WaveToy_MaxNumEvolvedVars
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_Dirichlet_calc_every
#  define CCTK_PARAMETER__ML_WAVETOY__WT_Dirichlet_calc_every RESTRICTED_ML_WAVETOY_STRUCT.WT_Dirichlet_calc_every
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_Dirichlet_calc_offset
#  define CCTK_PARAMETER__ML_WAVETOY__WT_Dirichlet_calc_offset RESTRICTED_ML_WAVETOY_STRUCT.WT_Dirichlet_calc_offset
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_EnergyBoundary_calc_every
#  define CCTK_PARAMETER__ML_WAVETOY__WT_EnergyBoundary_calc_every RESTRICTED_ML_WAVETOY_STRUCT.WT_EnergyBoundary_calc_every
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_EnergyBoundary_calc_offset
#  define CCTK_PARAMETER__ML_WAVETOY__WT_EnergyBoundary_calc_offset RESTRICTED_ML_WAVETOY_STRUCT.WT_EnergyBoundary_calc_offset
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_Energy_calc_every
#  define CCTK_PARAMETER__ML_WAVETOY__WT_Energy_calc_every RESTRICTED_ML_WAVETOY_STRUCT.WT_Energy_calc_every
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_Energy_calc_offset
#  define CCTK_PARAMETER__ML_WAVETOY__WT_Energy_calc_offset RESTRICTED_ML_WAVETOY_STRUCT.WT_Energy_calc_offset
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_Gaussian_calc_every
#  define CCTK_PARAMETER__ML_WAVETOY__WT_Gaussian_calc_every RESTRICTED_ML_WAVETOY_STRUCT.WT_Gaussian_calc_every
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_Gaussian_calc_offset
#  define CCTK_PARAMETER__ML_WAVETOY__WT_Gaussian_calc_offset RESTRICTED_ML_WAVETOY_STRUCT.WT_Gaussian_calc_offset
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_RHS_calc_every
#  define CCTK_PARAMETER__ML_WAVETOY__WT_RHS_calc_every RESTRICTED_ML_WAVETOY_STRUCT.WT_RHS_calc_every
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_RHS_calc_offset
#  define CCTK_PARAMETER__ML_WAVETOY__WT_RHS_calc_offset RESTRICTED_ML_WAVETOY_STRUCT.WT_RHS_calc_offset
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_Standing_calc_every
#  define CCTK_PARAMETER__ML_WAVETOY__WT_Standing_calc_every RESTRICTED_ML_WAVETOY_STRUCT.WT_Standing_calc_every
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__WT_Standing_calc_offset
#  define CCTK_PARAMETER__ML_WAVETOY__WT_Standing_calc_offset RESTRICTED_ML_WAVETOY_STRUCT.WT_Standing_calc_offset
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__other_timelevels
#  define CCTK_PARAMETER__ML_WAVETOY__other_timelevels RESTRICTED_ML_WAVETOY_STRUCT.other_timelevels
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__rhs_timelevels
#  define CCTK_PARAMETER__ML_WAVETOY__rhs_timelevels RESTRICTED_ML_WAVETOY_STRUCT.rhs_timelevels
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__tile_size
#  define CCTK_PARAMETER__ML_WAVETOY__tile_size RESTRICTED_ML_WAVETOY_STRUCT.tile_size
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__timelevels
#  define CCTK_PARAMETER__ML_WAVETOY__timelevels RESTRICTED_ML_WAVETOY_STRUCT.timelevels
#endif
#ifndef CCTK_PARAMETER__ML_WAVETOY__verbose
#  define CCTK_PARAMETER__ML_WAVETOY__verbose RESTRICTED_ML_WAVETOY_STRUCT.verbose
#endif

