#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL begin_qlm_calculations_after[100];
  const char * coordsystem;
  const char * interpolator;
  const char * interpolator_options;
  const char * killing_vector_method;
  const char * killing_vector_normalisation;
  const char * surface_name[100];
  CCTK_INT num_surfaces;
  CCTK_INT output_vtk_every;
  CCTK_INT spatial_order;
  CCTK_INT surface_index[100];
  CCTK_INT verbose;
  CCTK_INT veryverbose;
} PRIVATE_QUASILOCALMEASURES_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_QUASILOCALMEASURES_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, begin_qlm_calculations_after, CCTK_PARAMETER__QUASILOCALMEASURES__begin_qlm_calculations_after); \
  CCTK_DECLARE_INIT (const char * const, coordsystem, CCTK_PARAMETER__QUASILOCALMEASURES__coordsystem); \
  CCTK_DECLARE_INIT (const char * const, interpolator, CCTK_PARAMETER__QUASILOCALMEASURES__interpolator); \
  CCTK_DECLARE_INIT (const char * const, interpolator_options, CCTK_PARAMETER__QUASILOCALMEASURES__interpolator_options); \
  CCTK_DECLARE_INIT (const char * const, killing_vector_method, CCTK_PARAMETER__QUASILOCALMEASURES__killing_vector_method); \
  CCTK_DECLARE_INIT (const char * const, killing_vector_normalisation, CCTK_PARAMETER__QUASILOCALMEASURES__killing_vector_normalisation); \
  CCTK_DECLARE_INIT (const char * const * const, surface_name, CCTK_PARAMETER__QUASILOCALMEASURES__surface_name); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_surfaces, CCTK_PARAMETER__QUASILOCALMEASURES__num_surfaces); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_vtk_every, CCTK_PARAMETER__QUASILOCALMEASURES__output_vtk_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, spatial_order, CCTK_PARAMETER__QUASILOCALMEASURES__spatial_order); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, surface_index, CCTK_PARAMETER__QUASILOCALMEASURES__surface_index); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__QUASILOCALMEASURES__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, veryverbose, CCTK_PARAMETER__QUASILOCALMEASURES__veryverbose); \


#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__begin_qlm_calculations_after
#  define CCTK_PARAMETER__QUASILOCALMEASURES__begin_qlm_calculations_after PRIVATE_QUASILOCALMEASURES_STRUCT.begin_qlm_calculations_after
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__coordsystem
#  define CCTK_PARAMETER__QUASILOCALMEASURES__coordsystem PRIVATE_QUASILOCALMEASURES_STRUCT.coordsystem
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__interpolator
#  define CCTK_PARAMETER__QUASILOCALMEASURES__interpolator PRIVATE_QUASILOCALMEASURES_STRUCT.interpolator
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__interpolator_options
#  define CCTK_PARAMETER__QUASILOCALMEASURES__interpolator_options PRIVATE_QUASILOCALMEASURES_STRUCT.interpolator_options
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__killing_vector_method
#  define CCTK_PARAMETER__QUASILOCALMEASURES__killing_vector_method PRIVATE_QUASILOCALMEASURES_STRUCT.killing_vector_method
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__killing_vector_normalisation
#  define CCTK_PARAMETER__QUASILOCALMEASURES__killing_vector_normalisation PRIVATE_QUASILOCALMEASURES_STRUCT.killing_vector_normalisation
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__surface_name
#  define CCTK_PARAMETER__QUASILOCALMEASURES__surface_name PRIVATE_QUASILOCALMEASURES_STRUCT.surface_name
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__num_surfaces
#  define CCTK_PARAMETER__QUASILOCALMEASURES__num_surfaces PRIVATE_QUASILOCALMEASURES_STRUCT.num_surfaces
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__output_vtk_every
#  define CCTK_PARAMETER__QUASILOCALMEASURES__output_vtk_every PRIVATE_QUASILOCALMEASURES_STRUCT.output_vtk_every
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__spatial_order
#  define CCTK_PARAMETER__QUASILOCALMEASURES__spatial_order PRIVATE_QUASILOCALMEASURES_STRUCT.spatial_order
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__surface_index
#  define CCTK_PARAMETER__QUASILOCALMEASURES__surface_index PRIVATE_QUASILOCALMEASURES_STRUCT.surface_index
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__verbose
#  define CCTK_PARAMETER__QUASILOCALMEASURES__verbose PRIVATE_QUASILOCALMEASURES_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__QUASILOCALMEASURES__veryverbose
#  define CCTK_PARAMETER__QUASILOCALMEASURES__veryverbose PRIVATE_QUASILOCALMEASURES_STRUCT.veryverbose
#endif

