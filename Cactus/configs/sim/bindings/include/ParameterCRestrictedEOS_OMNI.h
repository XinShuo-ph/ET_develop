#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL barotropiceos_gammath;
  CCTK_REAL gl_gamma;
  CCTK_REAL gl_k;
  CCTK_REAL hybrid_gamma1;
  CCTK_REAL hybrid_gamma2;
  CCTK_REAL hybrid_gamma_th;
  CCTK_REAL hybrid_k1;
  CCTK_REAL hybrid_rho_nuc;
  CCTK_REAL poly_gamma;
  CCTK_REAL poly_gamma_initial;
  CCTK_REAL poly_k;
  const char * barotropiceos_table_name;
  const char * coldeos_table_name;
  const char * dump_nuceos_table_name;
  const char * nuceos_table_name;
  CCTK_INT barotropiceos_read_table;
  CCTK_INT barotropiceos_use_thermal_gamma_law;
  CCTK_INT coldeos_read_table;
  CCTK_INT coldeos_use_thermal_gamma_law;
  CCTK_INT do_energy_shift;
  CCTK_INT dump_nuceos_table;
  CCTK_INT nuceos_read_table;
  CCTK_INT read_table_on_single_process;
  CCTK_INT reader_process;
} RESTRICTED_EOS_OMNI_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_EOS_OMNI_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, barotropiceos_gammath, CCTK_PARAMETER__EOS_OMNI__barotropiceos_gammath); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gl_gamma, CCTK_PARAMETER__EOS_OMNI__gl_gamma); \
  CCTK_DECLARE_INIT (CCTK_REAL const, gl_k, CCTK_PARAMETER__EOS_OMNI__gl_k); \
  CCTK_DECLARE_INIT (CCTK_REAL const, hybrid_gamma1, CCTK_PARAMETER__EOS_OMNI__hybrid_gamma1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, hybrid_gamma2, CCTK_PARAMETER__EOS_OMNI__hybrid_gamma2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, hybrid_gamma_th, CCTK_PARAMETER__EOS_OMNI__hybrid_gamma_th); \
  CCTK_DECLARE_INIT (CCTK_REAL const, hybrid_k1, CCTK_PARAMETER__EOS_OMNI__hybrid_k1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, hybrid_rho_nuc, CCTK_PARAMETER__EOS_OMNI__hybrid_rho_nuc); \
  CCTK_DECLARE_INIT (CCTK_REAL const, poly_gamma, CCTK_PARAMETER__EOS_OMNI__poly_gamma); \
  CCTK_DECLARE_INIT (CCTK_REAL const, poly_gamma_initial, CCTK_PARAMETER__EOS_OMNI__poly_gamma_initial); \
  CCTK_DECLARE_INIT (CCTK_REAL const, poly_k, CCTK_PARAMETER__EOS_OMNI__poly_k); \
  CCTK_DECLARE_INIT (const char * const, barotropiceos_table_name, CCTK_PARAMETER__EOS_OMNI__barotropiceos_table_name); \
  CCTK_DECLARE_INIT (const char * const, coldeos_table_name, CCTK_PARAMETER__EOS_OMNI__coldeos_table_name); \
  CCTK_DECLARE_INIT (const char * const, dump_nuceos_table_name, CCTK_PARAMETER__EOS_OMNI__dump_nuceos_table_name); \
  CCTK_DECLARE_INIT (const char * const, nuceos_table_name, CCTK_PARAMETER__EOS_OMNI__nuceos_table_name); \
  CCTK_DECLARE_INIT (CCTK_INT const, barotropiceos_read_table, CCTK_PARAMETER__EOS_OMNI__barotropiceos_read_table); \
  CCTK_DECLARE_INIT (CCTK_INT const, barotropiceos_use_thermal_gamma_law, CCTK_PARAMETER__EOS_OMNI__barotropiceos_use_thermal_gamma_law); \
  CCTK_DECLARE_INIT (CCTK_INT const, coldeos_read_table, CCTK_PARAMETER__EOS_OMNI__coldeos_read_table); \
  CCTK_DECLARE_INIT (CCTK_INT const, coldeos_use_thermal_gamma_law, CCTK_PARAMETER__EOS_OMNI__coldeos_use_thermal_gamma_law); \
  CCTK_DECLARE_INIT (CCTK_INT const, do_energy_shift, CCTK_PARAMETER__EOS_OMNI__do_energy_shift); \
  CCTK_DECLARE_INIT (CCTK_INT const, dump_nuceos_table, CCTK_PARAMETER__EOS_OMNI__dump_nuceos_table); \
  CCTK_DECLARE_INIT (CCTK_INT const, nuceos_read_table, CCTK_PARAMETER__EOS_OMNI__nuceos_read_table); \
  CCTK_DECLARE_INIT (CCTK_INT const, read_table_on_single_process, CCTK_PARAMETER__EOS_OMNI__read_table_on_single_process); \
  CCTK_DECLARE_INIT (CCTK_INT const, reader_process, CCTK_PARAMETER__EOS_OMNI__reader_process); \


#ifndef CCTK_PARAMETER__EOS_OMNI__barotropiceos_gammath
#  define CCTK_PARAMETER__EOS_OMNI__barotropiceos_gammath RESTRICTED_EOS_OMNI_STRUCT.barotropiceos_gammath
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__gl_gamma
#  define CCTK_PARAMETER__EOS_OMNI__gl_gamma RESTRICTED_EOS_OMNI_STRUCT.gl_gamma
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__gl_k
#  define CCTK_PARAMETER__EOS_OMNI__gl_k RESTRICTED_EOS_OMNI_STRUCT.gl_k
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__hybrid_gamma1
#  define CCTK_PARAMETER__EOS_OMNI__hybrid_gamma1 RESTRICTED_EOS_OMNI_STRUCT.hybrid_gamma1
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__hybrid_gamma2
#  define CCTK_PARAMETER__EOS_OMNI__hybrid_gamma2 RESTRICTED_EOS_OMNI_STRUCT.hybrid_gamma2
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__hybrid_gamma_th
#  define CCTK_PARAMETER__EOS_OMNI__hybrid_gamma_th RESTRICTED_EOS_OMNI_STRUCT.hybrid_gamma_th
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__hybrid_k1
#  define CCTK_PARAMETER__EOS_OMNI__hybrid_k1 RESTRICTED_EOS_OMNI_STRUCT.hybrid_k1
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__hybrid_rho_nuc
#  define CCTK_PARAMETER__EOS_OMNI__hybrid_rho_nuc RESTRICTED_EOS_OMNI_STRUCT.hybrid_rho_nuc
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__poly_gamma
#  define CCTK_PARAMETER__EOS_OMNI__poly_gamma RESTRICTED_EOS_OMNI_STRUCT.poly_gamma
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__poly_gamma_initial
#  define CCTK_PARAMETER__EOS_OMNI__poly_gamma_initial RESTRICTED_EOS_OMNI_STRUCT.poly_gamma_initial
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__poly_k
#  define CCTK_PARAMETER__EOS_OMNI__poly_k RESTRICTED_EOS_OMNI_STRUCT.poly_k
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__barotropiceos_table_name
#  define CCTK_PARAMETER__EOS_OMNI__barotropiceos_table_name RESTRICTED_EOS_OMNI_STRUCT.barotropiceos_table_name
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__coldeos_table_name
#  define CCTK_PARAMETER__EOS_OMNI__coldeos_table_name RESTRICTED_EOS_OMNI_STRUCT.coldeos_table_name
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__dump_nuceos_table_name
#  define CCTK_PARAMETER__EOS_OMNI__dump_nuceos_table_name RESTRICTED_EOS_OMNI_STRUCT.dump_nuceos_table_name
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__nuceos_table_name
#  define CCTK_PARAMETER__EOS_OMNI__nuceos_table_name RESTRICTED_EOS_OMNI_STRUCT.nuceos_table_name
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__barotropiceos_read_table
#  define CCTK_PARAMETER__EOS_OMNI__barotropiceos_read_table RESTRICTED_EOS_OMNI_STRUCT.barotropiceos_read_table
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__barotropiceos_use_thermal_gamma_law
#  define CCTK_PARAMETER__EOS_OMNI__barotropiceos_use_thermal_gamma_law RESTRICTED_EOS_OMNI_STRUCT.barotropiceos_use_thermal_gamma_law
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__coldeos_read_table
#  define CCTK_PARAMETER__EOS_OMNI__coldeos_read_table RESTRICTED_EOS_OMNI_STRUCT.coldeos_read_table
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__coldeos_use_thermal_gamma_law
#  define CCTK_PARAMETER__EOS_OMNI__coldeos_use_thermal_gamma_law RESTRICTED_EOS_OMNI_STRUCT.coldeos_use_thermal_gamma_law
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__do_energy_shift
#  define CCTK_PARAMETER__EOS_OMNI__do_energy_shift RESTRICTED_EOS_OMNI_STRUCT.do_energy_shift
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__dump_nuceos_table
#  define CCTK_PARAMETER__EOS_OMNI__dump_nuceos_table RESTRICTED_EOS_OMNI_STRUCT.dump_nuceos_table
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__nuceos_read_table
#  define CCTK_PARAMETER__EOS_OMNI__nuceos_read_table RESTRICTED_EOS_OMNI_STRUCT.nuceos_read_table
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__read_table_on_single_process
#  define CCTK_PARAMETER__EOS_OMNI__read_table_on_single_process RESTRICTED_EOS_OMNI_STRUCT.read_table_on_single_process
#endif
#ifndef CCTK_PARAMETER__EOS_OMNI__reader_process
#  define CCTK_PARAMETER__EOS_OMNI__reader_process RESTRICTED_EOS_OMNI_STRUCT.reader_process
#endif

