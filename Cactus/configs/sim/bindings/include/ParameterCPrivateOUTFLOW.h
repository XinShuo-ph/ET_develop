#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL rad_rescale[100];
  CCTK_REAL radius[100];
  CCTK_REAL threshold[20];
  const char * coord_system;
  const char * extra_variables;
  const char * interpolator_name;
  const char * interpolator_pars;
  const char * out_format;
  const char * surface_name[100];
  const char * threshold_on_var;
  CCTK_INT compute_every;
  CCTK_INT compute_every_det[100];
  CCTK_INT num_detectors;
  CCTK_INT num_thresholds;
  CCTK_INT output_2d_data;
  CCTK_INT output_relative_coordinates;
  CCTK_INT override_radius[100];
  CCTK_INT surface_index[100];
  CCTK_INT verbose;
} PRIVATE_OUTFLOW_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_OUTFLOW_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, rad_rescale, CCTK_PARAMETER__OUTFLOW__rad_rescale); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius, CCTK_PARAMETER__OUTFLOW__radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, threshold, CCTK_PARAMETER__OUTFLOW__threshold); \
  CCTK_DECLARE_INIT (const char * const, coord_system, CCTK_PARAMETER__OUTFLOW__coord_system); \
  CCTK_DECLARE_INIT (const char * const, extra_variables, CCTK_PARAMETER__OUTFLOW__extra_variables); \
  CCTK_DECLARE_INIT (const char * const, interpolator_name, CCTK_PARAMETER__OUTFLOW__interpolator_name); \
  CCTK_DECLARE_INIT (const char * const, interpolator_pars, CCTK_PARAMETER__OUTFLOW__interpolator_pars); \
  CCTK_DECLARE_INIT (const char * const, out_format, CCTK_PARAMETER__OUTFLOW__out_format); \
  CCTK_DECLARE_INIT (const char * const * const, surface_name, CCTK_PARAMETER__OUTFLOW__surface_name); \
  CCTK_DECLARE_INIT (const char * const, threshold_on_var, CCTK_PARAMETER__OUTFLOW__threshold_on_var); \
  CCTK_DECLARE_INIT (CCTK_INT const, compute_every, CCTK_PARAMETER__OUTFLOW__compute_every); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, compute_every_det, CCTK_PARAMETER__OUTFLOW__compute_every_det); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_detectors, CCTK_PARAMETER__OUTFLOW__num_detectors); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_thresholds, CCTK_PARAMETER__OUTFLOW__num_thresholds); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_2d_data, CCTK_PARAMETER__OUTFLOW__output_2d_data); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_relative_coordinates, CCTK_PARAMETER__OUTFLOW__output_relative_coordinates); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, override_radius, CCTK_PARAMETER__OUTFLOW__override_radius); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, surface_index, CCTK_PARAMETER__OUTFLOW__surface_index); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__OUTFLOW__verbose); \


#ifndef CCTK_PARAMETER__OUTFLOW__rad_rescale
#  define CCTK_PARAMETER__OUTFLOW__rad_rescale PRIVATE_OUTFLOW_STRUCT.rad_rescale
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__radius
#  define CCTK_PARAMETER__OUTFLOW__radius PRIVATE_OUTFLOW_STRUCT.radius
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__threshold
#  define CCTK_PARAMETER__OUTFLOW__threshold PRIVATE_OUTFLOW_STRUCT.threshold
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__coord_system
#  define CCTK_PARAMETER__OUTFLOW__coord_system PRIVATE_OUTFLOW_STRUCT.coord_system
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__extra_variables
#  define CCTK_PARAMETER__OUTFLOW__extra_variables PRIVATE_OUTFLOW_STRUCT.extra_variables
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__interpolator_name
#  define CCTK_PARAMETER__OUTFLOW__interpolator_name PRIVATE_OUTFLOW_STRUCT.interpolator_name
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__interpolator_pars
#  define CCTK_PARAMETER__OUTFLOW__interpolator_pars PRIVATE_OUTFLOW_STRUCT.interpolator_pars
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__out_format
#  define CCTK_PARAMETER__OUTFLOW__out_format PRIVATE_OUTFLOW_STRUCT.out_format
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__surface_name
#  define CCTK_PARAMETER__OUTFLOW__surface_name PRIVATE_OUTFLOW_STRUCT.surface_name
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__threshold_on_var
#  define CCTK_PARAMETER__OUTFLOW__threshold_on_var PRIVATE_OUTFLOW_STRUCT.threshold_on_var
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__compute_every
#  define CCTK_PARAMETER__OUTFLOW__compute_every PRIVATE_OUTFLOW_STRUCT.compute_every
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__compute_every_det
#  define CCTK_PARAMETER__OUTFLOW__compute_every_det PRIVATE_OUTFLOW_STRUCT.compute_every_det
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__num_detectors
#  define CCTK_PARAMETER__OUTFLOW__num_detectors PRIVATE_OUTFLOW_STRUCT.num_detectors
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__num_thresholds
#  define CCTK_PARAMETER__OUTFLOW__num_thresholds PRIVATE_OUTFLOW_STRUCT.num_thresholds
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__output_2d_data
#  define CCTK_PARAMETER__OUTFLOW__output_2d_data PRIVATE_OUTFLOW_STRUCT.output_2d_data
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__output_relative_coordinates
#  define CCTK_PARAMETER__OUTFLOW__output_relative_coordinates PRIVATE_OUTFLOW_STRUCT.output_relative_coordinates
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__override_radius
#  define CCTK_PARAMETER__OUTFLOW__override_radius PRIVATE_OUTFLOW_STRUCT.override_radius
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__surface_index
#  define CCTK_PARAMETER__OUTFLOW__surface_index PRIVATE_OUTFLOW_STRUCT.surface_index
#endif
#ifndef CCTK_PARAMETER__OUTFLOW__verbose
#  define CCTK_PARAMETER__OUTFLOW__verbose PRIVATE_OUTFLOW_STRUCT.verbose
#endif

