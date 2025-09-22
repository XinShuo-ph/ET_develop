#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL Pert_Amplitude[10];
  CCTK_REAL TOV_Gamma;
  CCTK_REAL TOV_K;
  CCTK_REAL TOV_Position_x[10];
  CCTK_REAL TOV_Position_y[10];
  CCTK_REAL TOV_Position_z[10];
  CCTK_REAL TOV_Rho_Central[10];
  CCTK_REAL TOV_Velocity_x[10];
  CCTK_REAL TOV_Velocity_y[10];
  CCTK_REAL TOV_Velocity_z[10];
  CCTK_REAL TOV_dr[10];
  const char * TOV_Combine_Method;
  const char * TOV_save_to_datafile;
  CCTK_INT Perturb[10];
  CCTK_INT TOV_Clear_Initial_Data;
  CCTK_INT TOV_Conformal_Flat_Three_Metric;
  CCTK_INT TOV_Enforce_Interpolation;
  CCTK_INT TOV_Fast_Interpolation;
  CCTK_INT TOV_Momentum_Psi_Power;
  CCTK_INT TOV_Num_Radial;
  CCTK_INT TOV_Num_TOVs;
  CCTK_INT TOV_Populate_Timelevels;
  CCTK_INT TOV_ProperPosition;
  CCTK_INT TOV_Solve_for_TOVs;
  CCTK_INT TOV_Use_Old_Initial_Data;
  CCTK_INT TOV_Use_Old_Matter_Initial_Data;
  CCTK_INT TOV_fake_evolution;
} PRIVATE_TOVSOLVER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_TOVSOLVER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, Pert_Amplitude, CCTK_PARAMETER__TOVSOLVER__Pert_Amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, TOV_Gamma, CCTK_PARAMETER__TOVSOLVER__TOV_Gamma); \
  CCTK_DECLARE_INIT (CCTK_REAL const, TOV_K, CCTK_PARAMETER__TOVSOLVER__TOV_K); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, TOV_Position_x, CCTK_PARAMETER__TOVSOLVER__TOV_Position_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, TOV_Position_y, CCTK_PARAMETER__TOVSOLVER__TOV_Position_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, TOV_Position_z, CCTK_PARAMETER__TOVSOLVER__TOV_Position_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, TOV_Rho_Central, CCTK_PARAMETER__TOVSOLVER__TOV_Rho_Central); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, TOV_Velocity_x, CCTK_PARAMETER__TOVSOLVER__TOV_Velocity_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, TOV_Velocity_y, CCTK_PARAMETER__TOVSOLVER__TOV_Velocity_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, TOV_Velocity_z, CCTK_PARAMETER__TOVSOLVER__TOV_Velocity_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, TOV_dr, CCTK_PARAMETER__TOVSOLVER__TOV_dr); \
  CCTK_DECLARE_INIT (const char * const, TOV_Combine_Method, CCTK_PARAMETER__TOVSOLVER__TOV_Combine_Method); \
  CCTK_DECLARE_INIT (const char * const, TOV_save_to_datafile, CCTK_PARAMETER__TOVSOLVER__TOV_save_to_datafile); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, Perturb, CCTK_PARAMETER__TOVSOLVER__Perturb); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Clear_Initial_Data, CCTK_PARAMETER__TOVSOLVER__TOV_Clear_Initial_Data); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Conformal_Flat_Three_Metric, CCTK_PARAMETER__TOVSOLVER__TOV_Conformal_Flat_Three_Metric); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Enforce_Interpolation, CCTK_PARAMETER__TOVSOLVER__TOV_Enforce_Interpolation); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Fast_Interpolation, CCTK_PARAMETER__TOVSOLVER__TOV_Fast_Interpolation); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Momentum_Psi_Power, CCTK_PARAMETER__TOVSOLVER__TOV_Momentum_Psi_Power); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Num_Radial, CCTK_PARAMETER__TOVSOLVER__TOV_Num_Radial); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Num_TOVs, CCTK_PARAMETER__TOVSOLVER__TOV_Num_TOVs); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Populate_Timelevels, CCTK_PARAMETER__TOVSOLVER__TOV_Populate_Timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_ProperPosition, CCTK_PARAMETER__TOVSOLVER__TOV_ProperPosition); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Solve_for_TOVs, CCTK_PARAMETER__TOVSOLVER__TOV_Solve_for_TOVs); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Use_Old_Initial_Data, CCTK_PARAMETER__TOVSOLVER__TOV_Use_Old_Initial_Data); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_Use_Old_Matter_Initial_Data, CCTK_PARAMETER__TOVSOLVER__TOV_Use_Old_Matter_Initial_Data); \
  CCTK_DECLARE_INIT (CCTK_INT const, TOV_fake_evolution, CCTK_PARAMETER__TOVSOLVER__TOV_fake_evolution); \


#ifndef CCTK_PARAMETER__TOVSOLVER__Pert_Amplitude
#  define CCTK_PARAMETER__TOVSOLVER__Pert_Amplitude PRIVATE_TOVSOLVER_STRUCT.Pert_Amplitude
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Gamma
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Gamma PRIVATE_TOVSOLVER_STRUCT.TOV_Gamma
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_K
#  define CCTK_PARAMETER__TOVSOLVER__TOV_K PRIVATE_TOVSOLVER_STRUCT.TOV_K
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Position_x
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Position_x PRIVATE_TOVSOLVER_STRUCT.TOV_Position_x
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Position_y
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Position_y PRIVATE_TOVSOLVER_STRUCT.TOV_Position_y
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Position_z
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Position_z PRIVATE_TOVSOLVER_STRUCT.TOV_Position_z
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Rho_Central
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Rho_Central PRIVATE_TOVSOLVER_STRUCT.TOV_Rho_Central
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Velocity_x
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Velocity_x PRIVATE_TOVSOLVER_STRUCT.TOV_Velocity_x
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Velocity_y
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Velocity_y PRIVATE_TOVSOLVER_STRUCT.TOV_Velocity_y
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Velocity_z
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Velocity_z PRIVATE_TOVSOLVER_STRUCT.TOV_Velocity_z
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_dr
#  define CCTK_PARAMETER__TOVSOLVER__TOV_dr PRIVATE_TOVSOLVER_STRUCT.TOV_dr
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Combine_Method
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Combine_Method PRIVATE_TOVSOLVER_STRUCT.TOV_Combine_Method
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_save_to_datafile
#  define CCTK_PARAMETER__TOVSOLVER__TOV_save_to_datafile PRIVATE_TOVSOLVER_STRUCT.TOV_save_to_datafile
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__Perturb
#  define CCTK_PARAMETER__TOVSOLVER__Perturb PRIVATE_TOVSOLVER_STRUCT.Perturb
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Clear_Initial_Data
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Clear_Initial_Data PRIVATE_TOVSOLVER_STRUCT.TOV_Clear_Initial_Data
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Conformal_Flat_Three_Metric
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Conformal_Flat_Three_Metric PRIVATE_TOVSOLVER_STRUCT.TOV_Conformal_Flat_Three_Metric
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Enforce_Interpolation
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Enforce_Interpolation PRIVATE_TOVSOLVER_STRUCT.TOV_Enforce_Interpolation
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Fast_Interpolation
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Fast_Interpolation PRIVATE_TOVSOLVER_STRUCT.TOV_Fast_Interpolation
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Momentum_Psi_Power
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Momentum_Psi_Power PRIVATE_TOVSOLVER_STRUCT.TOV_Momentum_Psi_Power
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Num_Radial
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Num_Radial PRIVATE_TOVSOLVER_STRUCT.TOV_Num_Radial
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Num_TOVs
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Num_TOVs PRIVATE_TOVSOLVER_STRUCT.TOV_Num_TOVs
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Populate_Timelevels
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Populate_Timelevels PRIVATE_TOVSOLVER_STRUCT.TOV_Populate_Timelevels
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_ProperPosition
#  define CCTK_PARAMETER__TOVSOLVER__TOV_ProperPosition PRIVATE_TOVSOLVER_STRUCT.TOV_ProperPosition
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Solve_for_TOVs
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Solve_for_TOVs PRIVATE_TOVSOLVER_STRUCT.TOV_Solve_for_TOVs
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Use_Old_Initial_Data
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Use_Old_Initial_Data PRIVATE_TOVSOLVER_STRUCT.TOV_Use_Old_Initial_Data
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_Use_Old_Matter_Initial_Data
#  define CCTK_PARAMETER__TOVSOLVER__TOV_Use_Old_Matter_Initial_Data PRIVATE_TOVSOLVER_STRUCT.TOV_Use_Old_Matter_Initial_Data
#endif
#ifndef CCTK_PARAMETER__TOVSOLVER__TOV_fake_evolution
#  define CCTK_PARAMETER__TOVSOLVER__TOV_fake_evolution PRIVATE_TOVSOLVER_STRUCT.TOV_fake_evolution
#endif

