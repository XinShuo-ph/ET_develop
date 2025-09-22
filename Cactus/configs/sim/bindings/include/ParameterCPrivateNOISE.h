#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL amplitude;
  const char * bc_vars;
  const char * id_vars;
  CCTK_INT apply_bc_noise;
  CCTK_INT apply_id_noise;
  CCTK_INT noise_boundaries[6];
  CCTK_INT noise_stencil[3];
} PRIVATE_NOISE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NOISE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, amplitude, CCTK_PARAMETER__NOISE__amplitude); \
  CCTK_DECLARE_INIT (const char * const, bc_vars, CCTK_PARAMETER__NOISE__bc_vars); \
  CCTK_DECLARE_INIT (const char * const, id_vars, CCTK_PARAMETER__NOISE__id_vars); \
  CCTK_DECLARE_INIT (CCTK_INT const, apply_bc_noise, CCTK_PARAMETER__NOISE__apply_bc_noise); \
  CCTK_DECLARE_INIT (CCTK_INT const, apply_id_noise, CCTK_PARAMETER__NOISE__apply_id_noise); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, noise_boundaries, CCTK_PARAMETER__NOISE__noise_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, noise_stencil, CCTK_PARAMETER__NOISE__noise_stencil); \


#ifndef CCTK_PARAMETER__NOISE__amplitude
#  define CCTK_PARAMETER__NOISE__amplitude PRIVATE_NOISE_STRUCT.amplitude
#endif
#ifndef CCTK_PARAMETER__NOISE__bc_vars
#  define CCTK_PARAMETER__NOISE__bc_vars PRIVATE_NOISE_STRUCT.bc_vars
#endif
#ifndef CCTK_PARAMETER__NOISE__id_vars
#  define CCTK_PARAMETER__NOISE__id_vars PRIVATE_NOISE_STRUCT.id_vars
#endif
#ifndef CCTK_PARAMETER__NOISE__apply_bc_noise
#  define CCTK_PARAMETER__NOISE__apply_bc_noise PRIVATE_NOISE_STRUCT.apply_bc_noise
#endif
#ifndef CCTK_PARAMETER__NOISE__apply_id_noise
#  define CCTK_PARAMETER__NOISE__apply_id_noise PRIVATE_NOISE_STRUCT.apply_id_noise
#endif
#ifndef CCTK_PARAMETER__NOISE__noise_boundaries
#  define CCTK_PARAMETER__NOISE__noise_boundaries PRIVATE_NOISE_STRUCT.noise_boundaries
#endif
#ifndef CCTK_PARAMETER__NOISE__noise_stencil
#  define CCTK_PARAMETER__NOISE__noise_stencil PRIVATE_NOISE_STRUCT.noise_stencil
#endif

