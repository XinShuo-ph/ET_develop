#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * Abar_evolution_method;
  const char * Bvec_evolution_method;
  const char * Y_e_evolution_method;
  const char * entropy_evolution_method;
  const char * evolution_method;
  const char * initial_Abar;
  const char * initial_Aphi;
  const char * initial_Avec;
  const char * initial_Bvec;
  const char * initial_Y_e;
  const char * initial_entropy;
  const char * initial_hydro;
  const char * initial_temperature;
  const char * prolongation_type;
  const char * temperature_evolution_method;
  CCTK_INT hydro_excision;
  CCTK_INT timelevels;
} RESTRICTED_HYDROBASE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_HYDROBASE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, Abar_evolution_method, CCTK_PARAMETER__HYDROBASE__Abar_evolution_method); \
  CCTK_DECLARE_INIT (const char * const, Bvec_evolution_method, CCTK_PARAMETER__HYDROBASE__Bvec_evolution_method); \
  CCTK_DECLARE_INIT (const char * const, Y_e_evolution_method, CCTK_PARAMETER__HYDROBASE__Y_e_evolution_method); \
  CCTK_DECLARE_INIT (const char * const, entropy_evolution_method, CCTK_PARAMETER__HYDROBASE__entropy_evolution_method); \
  CCTK_DECLARE_INIT (const char * const, evolution_method, CCTK_PARAMETER__HYDROBASE__evolution_method); \
  CCTK_DECLARE_INIT (const char * const, initial_Abar, CCTK_PARAMETER__HYDROBASE__initial_Abar); \
  CCTK_DECLARE_INIT (const char * const, initial_Aphi, CCTK_PARAMETER__HYDROBASE__initial_Aphi); \
  CCTK_DECLARE_INIT (const char * const, initial_Avec, CCTK_PARAMETER__HYDROBASE__initial_Avec); \
  CCTK_DECLARE_INIT (const char * const, initial_Bvec, CCTK_PARAMETER__HYDROBASE__initial_Bvec); \
  CCTK_DECLARE_INIT (const char * const, initial_Y_e, CCTK_PARAMETER__HYDROBASE__initial_Y_e); \
  CCTK_DECLARE_INIT (const char * const, initial_entropy, CCTK_PARAMETER__HYDROBASE__initial_entropy); \
  CCTK_DECLARE_INIT (const char * const, initial_hydro, CCTK_PARAMETER__HYDROBASE__initial_hydro); \
  CCTK_DECLARE_INIT (const char * const, initial_temperature, CCTK_PARAMETER__HYDROBASE__initial_temperature); \
  CCTK_DECLARE_INIT (const char * const, prolongation_type, CCTK_PARAMETER__HYDROBASE__prolongation_type); \
  CCTK_DECLARE_INIT (const char * const, temperature_evolution_method, CCTK_PARAMETER__HYDROBASE__temperature_evolution_method); \
  CCTK_DECLARE_INIT (CCTK_INT const, hydro_excision, CCTK_PARAMETER__HYDROBASE__hydro_excision); \
  CCTK_DECLARE_INIT (CCTK_INT const, timelevels, CCTK_PARAMETER__HYDROBASE__timelevels); \


#ifndef CCTK_PARAMETER__HYDROBASE__Abar_evolution_method
#  define CCTK_PARAMETER__HYDROBASE__Abar_evolution_method RESTRICTED_HYDROBASE_STRUCT.Abar_evolution_method
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__Bvec_evolution_method
#  define CCTK_PARAMETER__HYDROBASE__Bvec_evolution_method RESTRICTED_HYDROBASE_STRUCT.Bvec_evolution_method
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__Y_e_evolution_method
#  define CCTK_PARAMETER__HYDROBASE__Y_e_evolution_method RESTRICTED_HYDROBASE_STRUCT.Y_e_evolution_method
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__entropy_evolution_method
#  define CCTK_PARAMETER__HYDROBASE__entropy_evolution_method RESTRICTED_HYDROBASE_STRUCT.entropy_evolution_method
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__evolution_method
#  define CCTK_PARAMETER__HYDROBASE__evolution_method RESTRICTED_HYDROBASE_STRUCT.evolution_method
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__initial_Abar
#  define CCTK_PARAMETER__HYDROBASE__initial_Abar RESTRICTED_HYDROBASE_STRUCT.initial_Abar
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__initial_Aphi
#  define CCTK_PARAMETER__HYDROBASE__initial_Aphi RESTRICTED_HYDROBASE_STRUCT.initial_Aphi
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__initial_Avec
#  define CCTK_PARAMETER__HYDROBASE__initial_Avec RESTRICTED_HYDROBASE_STRUCT.initial_Avec
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__initial_Bvec
#  define CCTK_PARAMETER__HYDROBASE__initial_Bvec RESTRICTED_HYDROBASE_STRUCT.initial_Bvec
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__initial_Y_e
#  define CCTK_PARAMETER__HYDROBASE__initial_Y_e RESTRICTED_HYDROBASE_STRUCT.initial_Y_e
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__initial_entropy
#  define CCTK_PARAMETER__HYDROBASE__initial_entropy RESTRICTED_HYDROBASE_STRUCT.initial_entropy
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__initial_hydro
#  define CCTK_PARAMETER__HYDROBASE__initial_hydro RESTRICTED_HYDROBASE_STRUCT.initial_hydro
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__initial_temperature
#  define CCTK_PARAMETER__HYDROBASE__initial_temperature RESTRICTED_HYDROBASE_STRUCT.initial_temperature
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__prolongation_type
#  define CCTK_PARAMETER__HYDROBASE__prolongation_type RESTRICTED_HYDROBASE_STRUCT.prolongation_type
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__temperature_evolution_method
#  define CCTK_PARAMETER__HYDROBASE__temperature_evolution_method RESTRICTED_HYDROBASE_STRUCT.temperature_evolution_method
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__hydro_excision
#  define CCTK_PARAMETER__HYDROBASE__hydro_excision RESTRICTED_HYDROBASE_STRUCT.hydro_excision
#endif
#ifndef CCTK_PARAMETER__HYDROBASE__timelevels
#  define CCTK_PARAMETER__HYDROBASE__timelevels RESTRICTED_HYDROBASE_STRUCT.timelevels
#endif

