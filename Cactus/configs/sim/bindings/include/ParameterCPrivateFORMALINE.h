#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL update_interval;
  const char * out_reductions;
  const char * out_vars;
  const char * output_source_subdirectory;
  const char * portal_hostname[5];
  const char * portal_username;
  const char * rdf_hostname[5];
  const char * relay_host;
  const char * steered_parameters_log_exclusion_list;
  const char * storage_filename;
  const char * storage_json_filename;
  CCTK_INT announce_to_portal;
  CCTK_INT collect_metadata;
  CCTK_INT create_id_files;
  CCTK_INT max_warn_level;
  CCTK_INT metadata_lifetime;
  CCTK_INT nr_of_parameter_changes_to_be_logged;
  CCTK_INT output_info;
  CCTK_INT output_source;
  CCTK_INT portal_port[5];
  CCTK_INT publish_level;
  CCTK_INT rdf_port[5];
  CCTK_INT send_as_rdf;
  CCTK_INT store_into_file;
  CCTK_INT store_into_json_file;
  CCTK_INT timeout;
  CCTK_INT use_relay_host;
  CCTK_INT verbose;
} PRIVATE_FORMALINE_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_FORMALINE_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, update_interval, CCTK_PARAMETER__FORMALINE__update_interval); \
  CCTK_DECLARE_INIT (const char * const, out_reductions, CCTK_PARAMETER__FORMALINE__out_reductions); \
  CCTK_DECLARE_INIT (const char * const, out_vars, CCTK_PARAMETER__FORMALINE__out_vars); \
  CCTK_DECLARE_INIT (const char * const, output_source_subdirectory, CCTK_PARAMETER__FORMALINE__output_source_subdirectory); \
  CCTK_DECLARE_INIT (const char * const * const, portal_hostname, CCTK_PARAMETER__FORMALINE__portal_hostname); \
  CCTK_DECLARE_INIT (const char * const, portal_username, CCTK_PARAMETER__FORMALINE__portal_username); \
  CCTK_DECLARE_INIT (const char * const * const, rdf_hostname, CCTK_PARAMETER__FORMALINE__rdf_hostname); \
  CCTK_DECLARE_INIT (const char * const, relay_host, CCTK_PARAMETER__FORMALINE__relay_host); \
  CCTK_DECLARE_INIT (const char * const, steered_parameters_log_exclusion_list, CCTK_PARAMETER__FORMALINE__steered_parameters_log_exclusion_list); \
  CCTK_DECLARE_INIT (const char * const, storage_filename, CCTK_PARAMETER__FORMALINE__storage_filename); \
  CCTK_DECLARE_INIT (const char * const, storage_json_filename, CCTK_PARAMETER__FORMALINE__storage_json_filename); \
  CCTK_DECLARE_INIT (CCTK_INT const, announce_to_portal, CCTK_PARAMETER__FORMALINE__announce_to_portal); \
  CCTK_DECLARE_INIT (CCTK_INT const, collect_metadata, CCTK_PARAMETER__FORMALINE__collect_metadata); \
  CCTK_DECLARE_INIT (CCTK_INT const, create_id_files, CCTK_PARAMETER__FORMALINE__create_id_files); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_warn_level, CCTK_PARAMETER__FORMALINE__max_warn_level); \
  CCTK_DECLARE_INIT (CCTK_INT const, metadata_lifetime, CCTK_PARAMETER__FORMALINE__metadata_lifetime); \
  CCTK_DECLARE_INIT (CCTK_INT const, nr_of_parameter_changes_to_be_logged, CCTK_PARAMETER__FORMALINE__nr_of_parameter_changes_to_be_logged); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_info, CCTK_PARAMETER__FORMALINE__output_info); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_source, CCTK_PARAMETER__FORMALINE__output_source); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, portal_port, CCTK_PARAMETER__FORMALINE__portal_port); \
  CCTK_DECLARE_INIT (CCTK_INT const, publish_level, CCTK_PARAMETER__FORMALINE__publish_level); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, rdf_port, CCTK_PARAMETER__FORMALINE__rdf_port); \
  CCTK_DECLARE_INIT (CCTK_INT const, send_as_rdf, CCTK_PARAMETER__FORMALINE__send_as_rdf); \
  CCTK_DECLARE_INIT (CCTK_INT const, store_into_file, CCTK_PARAMETER__FORMALINE__store_into_file); \
  CCTK_DECLARE_INIT (CCTK_INT const, store_into_json_file, CCTK_PARAMETER__FORMALINE__store_into_json_file); \
  CCTK_DECLARE_INIT (CCTK_INT const, timeout, CCTK_PARAMETER__FORMALINE__timeout); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_relay_host, CCTK_PARAMETER__FORMALINE__use_relay_host); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__FORMALINE__verbose); \


#ifndef CCTK_PARAMETER__FORMALINE__update_interval
#  define CCTK_PARAMETER__FORMALINE__update_interval PRIVATE_FORMALINE_STRUCT.update_interval
#endif
#ifndef CCTK_PARAMETER__FORMALINE__out_reductions
#  define CCTK_PARAMETER__FORMALINE__out_reductions PRIVATE_FORMALINE_STRUCT.out_reductions
#endif
#ifndef CCTK_PARAMETER__FORMALINE__out_vars
#  define CCTK_PARAMETER__FORMALINE__out_vars PRIVATE_FORMALINE_STRUCT.out_vars
#endif
#ifndef CCTK_PARAMETER__FORMALINE__output_source_subdirectory
#  define CCTK_PARAMETER__FORMALINE__output_source_subdirectory PRIVATE_FORMALINE_STRUCT.output_source_subdirectory
#endif
#ifndef CCTK_PARAMETER__FORMALINE__portal_hostname
#  define CCTK_PARAMETER__FORMALINE__portal_hostname PRIVATE_FORMALINE_STRUCT.portal_hostname
#endif
#ifndef CCTK_PARAMETER__FORMALINE__portal_username
#  define CCTK_PARAMETER__FORMALINE__portal_username PRIVATE_FORMALINE_STRUCT.portal_username
#endif
#ifndef CCTK_PARAMETER__FORMALINE__rdf_hostname
#  define CCTK_PARAMETER__FORMALINE__rdf_hostname PRIVATE_FORMALINE_STRUCT.rdf_hostname
#endif
#ifndef CCTK_PARAMETER__FORMALINE__relay_host
#  define CCTK_PARAMETER__FORMALINE__relay_host PRIVATE_FORMALINE_STRUCT.relay_host
#endif
#ifndef CCTK_PARAMETER__FORMALINE__steered_parameters_log_exclusion_list
#  define CCTK_PARAMETER__FORMALINE__steered_parameters_log_exclusion_list PRIVATE_FORMALINE_STRUCT.steered_parameters_log_exclusion_list
#endif
#ifndef CCTK_PARAMETER__FORMALINE__storage_filename
#  define CCTK_PARAMETER__FORMALINE__storage_filename PRIVATE_FORMALINE_STRUCT.storage_filename
#endif
#ifndef CCTK_PARAMETER__FORMALINE__storage_json_filename
#  define CCTK_PARAMETER__FORMALINE__storage_json_filename PRIVATE_FORMALINE_STRUCT.storage_json_filename
#endif
#ifndef CCTK_PARAMETER__FORMALINE__announce_to_portal
#  define CCTK_PARAMETER__FORMALINE__announce_to_portal PRIVATE_FORMALINE_STRUCT.announce_to_portal
#endif
#ifndef CCTK_PARAMETER__FORMALINE__collect_metadata
#  define CCTK_PARAMETER__FORMALINE__collect_metadata PRIVATE_FORMALINE_STRUCT.collect_metadata
#endif
#ifndef CCTK_PARAMETER__FORMALINE__create_id_files
#  define CCTK_PARAMETER__FORMALINE__create_id_files PRIVATE_FORMALINE_STRUCT.create_id_files
#endif
#ifndef CCTK_PARAMETER__FORMALINE__max_warn_level
#  define CCTK_PARAMETER__FORMALINE__max_warn_level PRIVATE_FORMALINE_STRUCT.max_warn_level
#endif
#ifndef CCTK_PARAMETER__FORMALINE__metadata_lifetime
#  define CCTK_PARAMETER__FORMALINE__metadata_lifetime PRIVATE_FORMALINE_STRUCT.metadata_lifetime
#endif
#ifndef CCTK_PARAMETER__FORMALINE__nr_of_parameter_changes_to_be_logged
#  define CCTK_PARAMETER__FORMALINE__nr_of_parameter_changes_to_be_logged PRIVATE_FORMALINE_STRUCT.nr_of_parameter_changes_to_be_logged
#endif
#ifndef CCTK_PARAMETER__FORMALINE__output_info
#  define CCTK_PARAMETER__FORMALINE__output_info PRIVATE_FORMALINE_STRUCT.output_info
#endif
#ifndef CCTK_PARAMETER__FORMALINE__output_source
#  define CCTK_PARAMETER__FORMALINE__output_source PRIVATE_FORMALINE_STRUCT.output_source
#endif
#ifndef CCTK_PARAMETER__FORMALINE__portal_port
#  define CCTK_PARAMETER__FORMALINE__portal_port PRIVATE_FORMALINE_STRUCT.portal_port
#endif
#ifndef CCTK_PARAMETER__FORMALINE__publish_level
#  define CCTK_PARAMETER__FORMALINE__publish_level PRIVATE_FORMALINE_STRUCT.publish_level
#endif
#ifndef CCTK_PARAMETER__FORMALINE__rdf_port
#  define CCTK_PARAMETER__FORMALINE__rdf_port PRIVATE_FORMALINE_STRUCT.rdf_port
#endif
#ifndef CCTK_PARAMETER__FORMALINE__send_as_rdf
#  define CCTK_PARAMETER__FORMALINE__send_as_rdf PRIVATE_FORMALINE_STRUCT.send_as_rdf
#endif
#ifndef CCTK_PARAMETER__FORMALINE__store_into_file
#  define CCTK_PARAMETER__FORMALINE__store_into_file PRIVATE_FORMALINE_STRUCT.store_into_file
#endif
#ifndef CCTK_PARAMETER__FORMALINE__store_into_json_file
#  define CCTK_PARAMETER__FORMALINE__store_into_json_file PRIVATE_FORMALINE_STRUCT.store_into_json_file
#endif
#ifndef CCTK_PARAMETER__FORMALINE__timeout
#  define CCTK_PARAMETER__FORMALINE__timeout PRIVATE_FORMALINE_STRUCT.timeout
#endif
#ifndef CCTK_PARAMETER__FORMALINE__use_relay_host
#  define CCTK_PARAMETER__FORMALINE__use_relay_host PRIVATE_FORMALINE_STRUCT.use_relay_host
#endif
#ifndef CCTK_PARAMETER__FORMALINE__verbose
#  define CCTK_PARAMETER__FORMALINE__verbose PRIVATE_FORMALINE_STRUCT.verbose
#endif

