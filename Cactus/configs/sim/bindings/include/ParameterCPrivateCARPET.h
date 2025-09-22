#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL aspect_ratio_x;
  CCTK_REAL aspect_ratio_y;
  CCTK_REAL aspect_ratio_z;
  CCTK_REAL ghost_zone_cost;
  CCTK_REAL maximum_imbalance;
  CCTK_REAL timing_average_window_minutes;
  const char * base_extents;
  const char * base_outerbounds;
  const char * eno_interpolation_type;
  const char * ghost_sizes;
  const char * grid_coordinates_filename;
  const char * grid_structure_filename;
  const char * model;
  const char * processor_topology;
  const char * prolongation_orders_space;
  const char * refinement_centering;
  const char * space_refinement_factors;
  const char * time_refinement_factors;
  const char * timer_file;
  CCTK_INT adaptive_stepsize;
  CCTK_INT additional_buffer_zones;
  CCTK_INT additional_overlap_zones;
  CCTK_INT barriers;
  CCTK_INT check_for_poison;
  CCTK_INT checksum_timelevels;
  CCTK_INT constant_load_per_processor;
  CCTK_INT convergence_factor;
  CCTK_INT convergence_level;
  CCTK_INT domain_from_coordbase;
  CCTK_INT domain_from_multipatch;
  CCTK_INT enable_all_storage;
  CCTK_INT enable_no_storage;
  CCTK_INT ghost_size;
  CCTK_INT ghost_size_x;
  CCTK_INT ghost_size_y;
  CCTK_INT ghost_size_z;
  CCTK_INT global_nsize;
  CCTK_INT global_nx;
  CCTK_INT global_ny;
  CCTK_INT global_nz;
  CCTK_INT granularity;
  CCTK_INT granularity_boundary;
  CCTK_INT include_local_mode_in_mode_timer_tree;
  CCTK_INT include_maps_in_mode_timer_tree;
  CCTK_INT init_3_timelevels;
  CCTK_INT init_each_timelevel;
  CCTK_INT init_fill_timelevels;
  CCTK_INT max_poison_locations;
  CCTK_INT max_refinement_levels;
  CCTK_INT max_timelevels;
  CCTK_INT min_points_per_proc;
  CCTK_INT no_split_direction;
  CCTK_INT num_convergence_levels;
  CCTK_INT num_integrator_substeps;
  CCTK_INT num_maps;
  CCTK_INT num_threads;
  CCTK_INT output_after_regridding;
  CCTK_INT output_initialise_timer_tree;
  CCTK_INT output_internal_data;
  CCTK_INT output_timer_tree_every;
  CCTK_INT output_timers_every;
  CCTK_INT output_xml_timer_tree;
  CCTK_INT poison_new_timelevels;
  CCTK_INT poison_value;
  CCTK_INT print_grid_info;
  CCTK_INT print_timestats_every;
  CCTK_INT processor_topology_3d_x;
  CCTK_INT processor_topology_3d_y;
  CCTK_INT processor_topology_3d_z;
  CCTK_INT prolongate_initial_data;
  CCTK_INT prolongation_order_space;
  CCTK_INT prolongation_order_time;
  CCTK_INT recompose_verbose;
  CCTK_INT refine_timestep;
  CCTK_INT refinement_factor;
  CCTK_INT regrid_during_initialisation;
  CCTK_INT regrid_during_recovery;
  CCTK_INT regrid_in_level_mode;
  CCTK_INT same_number_of_components_on_each_process;
  CCTK_INT schedule_barriers;
  CCTK_INT set_cpu_affinity;
  CCTK_INT split_components;
  CCTK_INT split_direction;
  CCTK_INT storage_verbose;
  CCTK_INT suppress_restriction;
  CCTK_INT sync_barriers;
  CCTK_INT sync_during_time_integration;
  CCTK_INT time_interpolation_during_regridding;
  CCTK_INT use_buffer_zones;
  CCTK_INT use_overlap_zones;
  CCTK_INT use_tapered_grids;
  CCTK_INT use_unusedpoints_mask;
  CCTK_INT verbose;
  CCTK_INT veryverbose;
} PRIVATE_CARPET_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPET_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, aspect_ratio_x, CCTK_PARAMETER__CARPET__aspect_ratio_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, aspect_ratio_y, CCTK_PARAMETER__CARPET__aspect_ratio_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, aspect_ratio_z, CCTK_PARAMETER__CARPET__aspect_ratio_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ghost_zone_cost, CCTK_PARAMETER__CARPET__ghost_zone_cost); \
  CCTK_DECLARE_INIT (CCTK_REAL const, maximum_imbalance, CCTK_PARAMETER__CARPET__maximum_imbalance); \
  CCTK_DECLARE_INIT (CCTK_REAL const, timing_average_window_minutes, CCTK_PARAMETER__CARPET__timing_average_window_minutes); \
  CCTK_DECLARE_INIT (const char * const, base_extents, CCTK_PARAMETER__CARPET__base_extents); \
  CCTK_DECLARE_INIT (const char * const, base_outerbounds, CCTK_PARAMETER__CARPET__base_outerbounds); \
  CCTK_DECLARE_INIT (const char * const, eno_interpolation_type, CCTK_PARAMETER__CARPET__eno_interpolation_type); \
  CCTK_DECLARE_INIT (const char * const, ghost_sizes, CCTK_PARAMETER__CARPET__ghost_sizes); \
  CCTK_DECLARE_INIT (const char * const, grid_coordinates_filename, CCTK_PARAMETER__CARPET__grid_coordinates_filename); \
  CCTK_DECLARE_INIT (const char * const, grid_structure_filename, CCTK_PARAMETER__CARPET__grid_structure_filename); \
  CCTK_DECLARE_INIT (const char * const, model, CCTK_PARAMETER__CARPET__model); \
  CCTK_DECLARE_INIT (const char * const, processor_topology, CCTK_PARAMETER__CARPET__processor_topology); \
  CCTK_DECLARE_INIT (const char * const, prolongation_orders_space, CCTK_PARAMETER__CARPET__prolongation_orders_space); \
  CCTK_DECLARE_INIT (const char * const, refinement_centering, CCTK_PARAMETER__CARPET__refinement_centering); \
  CCTK_DECLARE_INIT (const char * const, space_refinement_factors, CCTK_PARAMETER__CARPET__space_refinement_factors); \
  CCTK_DECLARE_INIT (const char * const, time_refinement_factors, CCTK_PARAMETER__CARPET__time_refinement_factors); \
  CCTK_DECLARE_INIT (const char * const, timer_file, CCTK_PARAMETER__CARPET__timer_file); \
  CCTK_DECLARE_INIT (CCTK_INT const, adaptive_stepsize, CCTK_PARAMETER__CARPET__adaptive_stepsize); \
  CCTK_DECLARE_INIT (CCTK_INT const, additional_buffer_zones, CCTK_PARAMETER__CARPET__additional_buffer_zones); \
  CCTK_DECLARE_INIT (CCTK_INT const, additional_overlap_zones, CCTK_PARAMETER__CARPET__additional_overlap_zones); \
  CCTK_DECLARE_INIT (CCTK_INT const, barriers, CCTK_PARAMETER__CARPET__barriers); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_for_poison, CCTK_PARAMETER__CARPET__check_for_poison); \
  CCTK_DECLARE_INIT (CCTK_INT const, checksum_timelevels, CCTK_PARAMETER__CARPET__checksum_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, constant_load_per_processor, CCTK_PARAMETER__CARPET__constant_load_per_processor); \
  CCTK_DECLARE_INIT (CCTK_INT const, convergence_factor, CCTK_PARAMETER__CARPET__convergence_factor); \
  CCTK_DECLARE_INIT (CCTK_INT const, convergence_level, CCTK_PARAMETER__CARPET__convergence_level); \
  CCTK_DECLARE_INIT (CCTK_INT const, domain_from_coordbase, CCTK_PARAMETER__CARPET__domain_from_coordbase); \
  CCTK_DECLARE_INIT (CCTK_INT const, domain_from_multipatch, CCTK_PARAMETER__CARPET__domain_from_multipatch); \
  CCTK_DECLARE_INIT (CCTK_INT const, enable_all_storage, CCTK_PARAMETER__CARPET__enable_all_storage); \
  CCTK_DECLARE_INIT (CCTK_INT const, enable_no_storage, CCTK_PARAMETER__CARPET__enable_no_storage); \
  CCTK_DECLARE_INIT (CCTK_INT const, ghost_size, CCTK_PARAMETER__CARPET__ghost_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, ghost_size_x, CCTK_PARAMETER__CARPET__ghost_size_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, ghost_size_y, CCTK_PARAMETER__CARPET__ghost_size_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, ghost_size_z, CCTK_PARAMETER__CARPET__ghost_size_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, global_nsize, CCTK_PARAMETER__CARPET__global_nsize); \
  CCTK_DECLARE_INIT (CCTK_INT const, global_nx, CCTK_PARAMETER__CARPET__global_nx); \
  CCTK_DECLARE_INIT (CCTK_INT const, global_ny, CCTK_PARAMETER__CARPET__global_ny); \
  CCTK_DECLARE_INIT (CCTK_INT const, global_nz, CCTK_PARAMETER__CARPET__global_nz); \
  CCTK_DECLARE_INIT (CCTK_INT const, granularity, CCTK_PARAMETER__CARPET__granularity); \
  CCTK_DECLARE_INIT (CCTK_INT const, granularity_boundary, CCTK_PARAMETER__CARPET__granularity_boundary); \
  CCTK_DECLARE_INIT (CCTK_INT const, include_local_mode_in_mode_timer_tree, CCTK_PARAMETER__CARPET__include_local_mode_in_mode_timer_tree); \
  CCTK_DECLARE_INIT (CCTK_INT const, include_maps_in_mode_timer_tree, CCTK_PARAMETER__CARPET__include_maps_in_mode_timer_tree); \
  CCTK_DECLARE_INIT (CCTK_INT const, init_3_timelevels, CCTK_PARAMETER__CARPET__init_3_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, init_each_timelevel, CCTK_PARAMETER__CARPET__init_each_timelevel); \
  CCTK_DECLARE_INIT (CCTK_INT const, init_fill_timelevels, CCTK_PARAMETER__CARPET__init_fill_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_poison_locations, CCTK_PARAMETER__CARPET__max_poison_locations); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_refinement_levels, CCTK_PARAMETER__CARPET__max_refinement_levels); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_timelevels, CCTK_PARAMETER__CARPET__max_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, min_points_per_proc, CCTK_PARAMETER__CARPET__min_points_per_proc); \
  CCTK_DECLARE_INIT (CCTK_INT const, no_split_direction, CCTK_PARAMETER__CARPET__no_split_direction); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_convergence_levels, CCTK_PARAMETER__CARPET__num_convergence_levels); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_integrator_substeps, CCTK_PARAMETER__CARPET__num_integrator_substeps); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_maps, CCTK_PARAMETER__CARPET__num_maps); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_threads, CCTK_PARAMETER__CARPET__num_threads); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_after_regridding, CCTK_PARAMETER__CARPET__output_after_regridding); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_initialise_timer_tree, CCTK_PARAMETER__CARPET__output_initialise_timer_tree); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_internal_data, CCTK_PARAMETER__CARPET__output_internal_data); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_timer_tree_every, CCTK_PARAMETER__CARPET__output_timer_tree_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_timers_every, CCTK_PARAMETER__CARPET__output_timers_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_xml_timer_tree, CCTK_PARAMETER__CARPET__output_xml_timer_tree); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_new_timelevels, CCTK_PARAMETER__CARPET__poison_new_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_value, CCTK_PARAMETER__CARPET__poison_value); \
  CCTK_DECLARE_INIT (CCTK_INT const, print_grid_info, CCTK_PARAMETER__CARPET__print_grid_info); \
  CCTK_DECLARE_INIT (CCTK_INT const, print_timestats_every, CCTK_PARAMETER__CARPET__print_timestats_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, processor_topology_3d_x, CCTK_PARAMETER__CARPET__processor_topology_3d_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, processor_topology_3d_y, CCTK_PARAMETER__CARPET__processor_topology_3d_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, processor_topology_3d_z, CCTK_PARAMETER__CARPET__processor_topology_3d_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, prolongate_initial_data, CCTK_PARAMETER__CARPET__prolongate_initial_data); \
  CCTK_DECLARE_INIT (CCTK_INT const, prolongation_order_space, CCTK_PARAMETER__CARPET__prolongation_order_space); \
  CCTK_DECLARE_INIT (CCTK_INT const, prolongation_order_time, CCTK_PARAMETER__CARPET__prolongation_order_time); \
  CCTK_DECLARE_INIT (CCTK_INT const, recompose_verbose, CCTK_PARAMETER__CARPET__recompose_verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, refine_timestep, CCTK_PARAMETER__CARPET__refine_timestep); \
  CCTK_DECLARE_INIT (CCTK_INT const, refinement_factor, CCTK_PARAMETER__CARPET__refinement_factor); \
  CCTK_DECLARE_INIT (CCTK_INT const, regrid_during_initialisation, CCTK_PARAMETER__CARPET__regrid_during_initialisation); \
  CCTK_DECLARE_INIT (CCTK_INT const, regrid_during_recovery, CCTK_PARAMETER__CARPET__regrid_during_recovery); \
  CCTK_DECLARE_INIT (CCTK_INT const, regrid_in_level_mode, CCTK_PARAMETER__CARPET__regrid_in_level_mode); \
  CCTK_DECLARE_INIT (CCTK_INT const, same_number_of_components_on_each_process, CCTK_PARAMETER__CARPET__same_number_of_components_on_each_process); \
  CCTK_DECLARE_INIT (CCTK_INT const, schedule_barriers, CCTK_PARAMETER__CARPET__schedule_barriers); \
  CCTK_DECLARE_INIT (CCTK_INT const, set_cpu_affinity, CCTK_PARAMETER__CARPET__set_cpu_affinity); \
  CCTK_DECLARE_INIT (CCTK_INT const, split_components, CCTK_PARAMETER__CARPET__split_components); \
  CCTK_DECLARE_INIT (CCTK_INT const, split_direction, CCTK_PARAMETER__CARPET__split_direction); \
  CCTK_DECLARE_INIT (CCTK_INT const, storage_verbose, CCTK_PARAMETER__CARPET__storage_verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, suppress_restriction, CCTK_PARAMETER__CARPET__suppress_restriction); \
  CCTK_DECLARE_INIT (CCTK_INT const, sync_barriers, CCTK_PARAMETER__CARPET__sync_barriers); \
  CCTK_DECLARE_INIT (CCTK_INT const, sync_during_time_integration, CCTK_PARAMETER__CARPET__sync_during_time_integration); \
  CCTK_DECLARE_INIT (CCTK_INT const, time_interpolation_during_regridding, CCTK_PARAMETER__CARPET__time_interpolation_during_regridding); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_buffer_zones, CCTK_PARAMETER__CARPET__use_buffer_zones); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_overlap_zones, CCTK_PARAMETER__CARPET__use_overlap_zones); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_tapered_grids, CCTK_PARAMETER__CARPET__use_tapered_grids); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_unusedpoints_mask, CCTK_PARAMETER__CARPET__use_unusedpoints_mask); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARPET__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, veryverbose, CCTK_PARAMETER__CARPET__veryverbose); \


#ifndef CCTK_PARAMETER__CARPET__aspect_ratio_x
#  define CCTK_PARAMETER__CARPET__aspect_ratio_x PRIVATE_CARPET_STRUCT.aspect_ratio_x
#endif
#ifndef CCTK_PARAMETER__CARPET__aspect_ratio_y
#  define CCTK_PARAMETER__CARPET__aspect_ratio_y PRIVATE_CARPET_STRUCT.aspect_ratio_y
#endif
#ifndef CCTK_PARAMETER__CARPET__aspect_ratio_z
#  define CCTK_PARAMETER__CARPET__aspect_ratio_z PRIVATE_CARPET_STRUCT.aspect_ratio_z
#endif
#ifndef CCTK_PARAMETER__CARPET__ghost_zone_cost
#  define CCTK_PARAMETER__CARPET__ghost_zone_cost PRIVATE_CARPET_STRUCT.ghost_zone_cost
#endif
#ifndef CCTK_PARAMETER__CARPET__maximum_imbalance
#  define CCTK_PARAMETER__CARPET__maximum_imbalance PRIVATE_CARPET_STRUCT.maximum_imbalance
#endif
#ifndef CCTK_PARAMETER__CARPET__timing_average_window_minutes
#  define CCTK_PARAMETER__CARPET__timing_average_window_minutes PRIVATE_CARPET_STRUCT.timing_average_window_minutes
#endif
#ifndef CCTK_PARAMETER__CARPET__base_extents
#  define CCTK_PARAMETER__CARPET__base_extents PRIVATE_CARPET_STRUCT.base_extents
#endif
#ifndef CCTK_PARAMETER__CARPET__base_outerbounds
#  define CCTK_PARAMETER__CARPET__base_outerbounds PRIVATE_CARPET_STRUCT.base_outerbounds
#endif
#ifndef CCTK_PARAMETER__CARPET__eno_interpolation_type
#  define CCTK_PARAMETER__CARPET__eno_interpolation_type PRIVATE_CARPET_STRUCT.eno_interpolation_type
#endif
#ifndef CCTK_PARAMETER__CARPET__ghost_sizes
#  define CCTK_PARAMETER__CARPET__ghost_sizes PRIVATE_CARPET_STRUCT.ghost_sizes
#endif
#ifndef CCTK_PARAMETER__CARPET__grid_coordinates_filename
#  define CCTK_PARAMETER__CARPET__grid_coordinates_filename PRIVATE_CARPET_STRUCT.grid_coordinates_filename
#endif
#ifndef CCTK_PARAMETER__CARPET__grid_structure_filename
#  define CCTK_PARAMETER__CARPET__grid_structure_filename PRIVATE_CARPET_STRUCT.grid_structure_filename
#endif
#ifndef CCTK_PARAMETER__CARPET__model
#  define CCTK_PARAMETER__CARPET__model PRIVATE_CARPET_STRUCT.model
#endif
#ifndef CCTK_PARAMETER__CARPET__processor_topology
#  define CCTK_PARAMETER__CARPET__processor_topology PRIVATE_CARPET_STRUCT.processor_topology
#endif
#ifndef CCTK_PARAMETER__CARPET__prolongation_orders_space
#  define CCTK_PARAMETER__CARPET__prolongation_orders_space PRIVATE_CARPET_STRUCT.prolongation_orders_space
#endif
#ifndef CCTK_PARAMETER__CARPET__refinement_centering
#  define CCTK_PARAMETER__CARPET__refinement_centering PRIVATE_CARPET_STRUCT.refinement_centering
#endif
#ifndef CCTK_PARAMETER__CARPET__space_refinement_factors
#  define CCTK_PARAMETER__CARPET__space_refinement_factors PRIVATE_CARPET_STRUCT.space_refinement_factors
#endif
#ifndef CCTK_PARAMETER__CARPET__time_refinement_factors
#  define CCTK_PARAMETER__CARPET__time_refinement_factors PRIVATE_CARPET_STRUCT.time_refinement_factors
#endif
#ifndef CCTK_PARAMETER__CARPET__timer_file
#  define CCTK_PARAMETER__CARPET__timer_file PRIVATE_CARPET_STRUCT.timer_file
#endif
#ifndef CCTK_PARAMETER__CARPET__adaptive_stepsize
#  define CCTK_PARAMETER__CARPET__adaptive_stepsize PRIVATE_CARPET_STRUCT.adaptive_stepsize
#endif
#ifndef CCTK_PARAMETER__CARPET__additional_buffer_zones
#  define CCTK_PARAMETER__CARPET__additional_buffer_zones PRIVATE_CARPET_STRUCT.additional_buffer_zones
#endif
#ifndef CCTK_PARAMETER__CARPET__additional_overlap_zones
#  define CCTK_PARAMETER__CARPET__additional_overlap_zones PRIVATE_CARPET_STRUCT.additional_overlap_zones
#endif
#ifndef CCTK_PARAMETER__CARPET__barriers
#  define CCTK_PARAMETER__CARPET__barriers PRIVATE_CARPET_STRUCT.barriers
#endif
#ifndef CCTK_PARAMETER__CARPET__check_for_poison
#  define CCTK_PARAMETER__CARPET__check_for_poison PRIVATE_CARPET_STRUCT.check_for_poison
#endif
#ifndef CCTK_PARAMETER__CARPET__checksum_timelevels
#  define CCTK_PARAMETER__CARPET__checksum_timelevels PRIVATE_CARPET_STRUCT.checksum_timelevels
#endif
#ifndef CCTK_PARAMETER__CARPET__constant_load_per_processor
#  define CCTK_PARAMETER__CARPET__constant_load_per_processor PRIVATE_CARPET_STRUCT.constant_load_per_processor
#endif
#ifndef CCTK_PARAMETER__CARPET__convergence_factor
#  define CCTK_PARAMETER__CARPET__convergence_factor PRIVATE_CARPET_STRUCT.convergence_factor
#endif
#ifndef CCTK_PARAMETER__CARPET__convergence_level
#  define CCTK_PARAMETER__CARPET__convergence_level PRIVATE_CARPET_STRUCT.convergence_level
#endif
#ifndef CCTK_PARAMETER__CARPET__domain_from_coordbase
#  define CCTK_PARAMETER__CARPET__domain_from_coordbase PRIVATE_CARPET_STRUCT.domain_from_coordbase
#endif
#ifndef CCTK_PARAMETER__CARPET__domain_from_multipatch
#  define CCTK_PARAMETER__CARPET__domain_from_multipatch PRIVATE_CARPET_STRUCT.domain_from_multipatch
#endif
#ifndef CCTK_PARAMETER__CARPET__enable_all_storage
#  define CCTK_PARAMETER__CARPET__enable_all_storage PRIVATE_CARPET_STRUCT.enable_all_storage
#endif
#ifndef CCTK_PARAMETER__CARPET__enable_no_storage
#  define CCTK_PARAMETER__CARPET__enable_no_storage PRIVATE_CARPET_STRUCT.enable_no_storage
#endif
#ifndef CCTK_PARAMETER__CARPET__ghost_size
#  define CCTK_PARAMETER__CARPET__ghost_size PRIVATE_CARPET_STRUCT.ghost_size
#endif
#ifndef CCTK_PARAMETER__CARPET__ghost_size_x
#  define CCTK_PARAMETER__CARPET__ghost_size_x PRIVATE_CARPET_STRUCT.ghost_size_x
#endif
#ifndef CCTK_PARAMETER__CARPET__ghost_size_y
#  define CCTK_PARAMETER__CARPET__ghost_size_y PRIVATE_CARPET_STRUCT.ghost_size_y
#endif
#ifndef CCTK_PARAMETER__CARPET__ghost_size_z
#  define CCTK_PARAMETER__CARPET__ghost_size_z PRIVATE_CARPET_STRUCT.ghost_size_z
#endif
#ifndef CCTK_PARAMETER__CARPET__global_nsize
#  define CCTK_PARAMETER__CARPET__global_nsize PRIVATE_CARPET_STRUCT.global_nsize
#endif
#ifndef CCTK_PARAMETER__CARPET__global_nx
#  define CCTK_PARAMETER__CARPET__global_nx PRIVATE_CARPET_STRUCT.global_nx
#endif
#ifndef CCTK_PARAMETER__CARPET__global_ny
#  define CCTK_PARAMETER__CARPET__global_ny PRIVATE_CARPET_STRUCT.global_ny
#endif
#ifndef CCTK_PARAMETER__CARPET__global_nz
#  define CCTK_PARAMETER__CARPET__global_nz PRIVATE_CARPET_STRUCT.global_nz
#endif
#ifndef CCTK_PARAMETER__CARPET__granularity
#  define CCTK_PARAMETER__CARPET__granularity PRIVATE_CARPET_STRUCT.granularity
#endif
#ifndef CCTK_PARAMETER__CARPET__granularity_boundary
#  define CCTK_PARAMETER__CARPET__granularity_boundary PRIVATE_CARPET_STRUCT.granularity_boundary
#endif
#ifndef CCTK_PARAMETER__CARPET__include_local_mode_in_mode_timer_tree
#  define CCTK_PARAMETER__CARPET__include_local_mode_in_mode_timer_tree PRIVATE_CARPET_STRUCT.include_local_mode_in_mode_timer_tree
#endif
#ifndef CCTK_PARAMETER__CARPET__include_maps_in_mode_timer_tree
#  define CCTK_PARAMETER__CARPET__include_maps_in_mode_timer_tree PRIVATE_CARPET_STRUCT.include_maps_in_mode_timer_tree
#endif
#ifndef CCTK_PARAMETER__CARPET__init_3_timelevels
#  define CCTK_PARAMETER__CARPET__init_3_timelevels PRIVATE_CARPET_STRUCT.init_3_timelevels
#endif
#ifndef CCTK_PARAMETER__CARPET__init_each_timelevel
#  define CCTK_PARAMETER__CARPET__init_each_timelevel PRIVATE_CARPET_STRUCT.init_each_timelevel
#endif
#ifndef CCTK_PARAMETER__CARPET__init_fill_timelevels
#  define CCTK_PARAMETER__CARPET__init_fill_timelevels PRIVATE_CARPET_STRUCT.init_fill_timelevels
#endif
#ifndef CCTK_PARAMETER__CARPET__max_poison_locations
#  define CCTK_PARAMETER__CARPET__max_poison_locations PRIVATE_CARPET_STRUCT.max_poison_locations
#endif
#ifndef CCTK_PARAMETER__CARPET__max_refinement_levels
#  define CCTK_PARAMETER__CARPET__max_refinement_levels PRIVATE_CARPET_STRUCT.max_refinement_levels
#endif
#ifndef CCTK_PARAMETER__CARPET__max_timelevels
#  define CCTK_PARAMETER__CARPET__max_timelevels PRIVATE_CARPET_STRUCT.max_timelevels
#endif
#ifndef CCTK_PARAMETER__CARPET__min_points_per_proc
#  define CCTK_PARAMETER__CARPET__min_points_per_proc PRIVATE_CARPET_STRUCT.min_points_per_proc
#endif
#ifndef CCTK_PARAMETER__CARPET__no_split_direction
#  define CCTK_PARAMETER__CARPET__no_split_direction PRIVATE_CARPET_STRUCT.no_split_direction
#endif
#ifndef CCTK_PARAMETER__CARPET__num_convergence_levels
#  define CCTK_PARAMETER__CARPET__num_convergence_levels PRIVATE_CARPET_STRUCT.num_convergence_levels
#endif
#ifndef CCTK_PARAMETER__CARPET__num_integrator_substeps
#  define CCTK_PARAMETER__CARPET__num_integrator_substeps PRIVATE_CARPET_STRUCT.num_integrator_substeps
#endif
#ifndef CCTK_PARAMETER__CARPET__num_maps
#  define CCTK_PARAMETER__CARPET__num_maps PRIVATE_CARPET_STRUCT.num_maps
#endif
#ifndef CCTK_PARAMETER__CARPET__num_threads
#  define CCTK_PARAMETER__CARPET__num_threads PRIVATE_CARPET_STRUCT.num_threads
#endif
#ifndef CCTK_PARAMETER__CARPET__output_after_regridding
#  define CCTK_PARAMETER__CARPET__output_after_regridding PRIVATE_CARPET_STRUCT.output_after_regridding
#endif
#ifndef CCTK_PARAMETER__CARPET__output_initialise_timer_tree
#  define CCTK_PARAMETER__CARPET__output_initialise_timer_tree PRIVATE_CARPET_STRUCT.output_initialise_timer_tree
#endif
#ifndef CCTK_PARAMETER__CARPET__output_internal_data
#  define CCTK_PARAMETER__CARPET__output_internal_data PRIVATE_CARPET_STRUCT.output_internal_data
#endif
#ifndef CCTK_PARAMETER__CARPET__output_timer_tree_every
#  define CCTK_PARAMETER__CARPET__output_timer_tree_every PRIVATE_CARPET_STRUCT.output_timer_tree_every
#endif
#ifndef CCTK_PARAMETER__CARPET__output_timers_every
#  define CCTK_PARAMETER__CARPET__output_timers_every PRIVATE_CARPET_STRUCT.output_timers_every
#endif
#ifndef CCTK_PARAMETER__CARPET__output_xml_timer_tree
#  define CCTK_PARAMETER__CARPET__output_xml_timer_tree PRIVATE_CARPET_STRUCT.output_xml_timer_tree
#endif
#ifndef CCTK_PARAMETER__CARPET__poison_new_timelevels
#  define CCTK_PARAMETER__CARPET__poison_new_timelevels PRIVATE_CARPET_STRUCT.poison_new_timelevels
#endif
#ifndef CCTK_PARAMETER__CARPET__poison_value
#  define CCTK_PARAMETER__CARPET__poison_value PRIVATE_CARPET_STRUCT.poison_value
#endif
#ifndef CCTK_PARAMETER__CARPET__print_grid_info
#  define CCTK_PARAMETER__CARPET__print_grid_info PRIVATE_CARPET_STRUCT.print_grid_info
#endif
#ifndef CCTK_PARAMETER__CARPET__print_timestats_every
#  define CCTK_PARAMETER__CARPET__print_timestats_every PRIVATE_CARPET_STRUCT.print_timestats_every
#endif
#ifndef CCTK_PARAMETER__CARPET__processor_topology_3d_x
#  define CCTK_PARAMETER__CARPET__processor_topology_3d_x PRIVATE_CARPET_STRUCT.processor_topology_3d_x
#endif
#ifndef CCTK_PARAMETER__CARPET__processor_topology_3d_y
#  define CCTK_PARAMETER__CARPET__processor_topology_3d_y PRIVATE_CARPET_STRUCT.processor_topology_3d_y
#endif
#ifndef CCTK_PARAMETER__CARPET__processor_topology_3d_z
#  define CCTK_PARAMETER__CARPET__processor_topology_3d_z PRIVATE_CARPET_STRUCT.processor_topology_3d_z
#endif
#ifndef CCTK_PARAMETER__CARPET__prolongate_initial_data
#  define CCTK_PARAMETER__CARPET__prolongate_initial_data PRIVATE_CARPET_STRUCT.prolongate_initial_data
#endif
#ifndef CCTK_PARAMETER__CARPET__prolongation_order_space
#  define CCTK_PARAMETER__CARPET__prolongation_order_space PRIVATE_CARPET_STRUCT.prolongation_order_space
#endif
#ifndef CCTK_PARAMETER__CARPET__prolongation_order_time
#  define CCTK_PARAMETER__CARPET__prolongation_order_time PRIVATE_CARPET_STRUCT.prolongation_order_time
#endif
#ifndef CCTK_PARAMETER__CARPET__recompose_verbose
#  define CCTK_PARAMETER__CARPET__recompose_verbose PRIVATE_CARPET_STRUCT.recompose_verbose
#endif
#ifndef CCTK_PARAMETER__CARPET__refine_timestep
#  define CCTK_PARAMETER__CARPET__refine_timestep PRIVATE_CARPET_STRUCT.refine_timestep
#endif
#ifndef CCTK_PARAMETER__CARPET__refinement_factor
#  define CCTK_PARAMETER__CARPET__refinement_factor PRIVATE_CARPET_STRUCT.refinement_factor
#endif
#ifndef CCTK_PARAMETER__CARPET__regrid_during_initialisation
#  define CCTK_PARAMETER__CARPET__regrid_during_initialisation PRIVATE_CARPET_STRUCT.regrid_during_initialisation
#endif
#ifndef CCTK_PARAMETER__CARPET__regrid_during_recovery
#  define CCTK_PARAMETER__CARPET__regrid_during_recovery PRIVATE_CARPET_STRUCT.regrid_during_recovery
#endif
#ifndef CCTK_PARAMETER__CARPET__regrid_in_level_mode
#  define CCTK_PARAMETER__CARPET__regrid_in_level_mode PRIVATE_CARPET_STRUCT.regrid_in_level_mode
#endif
#ifndef CCTK_PARAMETER__CARPET__same_number_of_components_on_each_process
#  define CCTK_PARAMETER__CARPET__same_number_of_components_on_each_process PRIVATE_CARPET_STRUCT.same_number_of_components_on_each_process
#endif
#ifndef CCTK_PARAMETER__CARPET__schedule_barriers
#  define CCTK_PARAMETER__CARPET__schedule_barriers PRIVATE_CARPET_STRUCT.schedule_barriers
#endif
#ifndef CCTK_PARAMETER__CARPET__set_cpu_affinity
#  define CCTK_PARAMETER__CARPET__set_cpu_affinity PRIVATE_CARPET_STRUCT.set_cpu_affinity
#endif
#ifndef CCTK_PARAMETER__CARPET__split_components
#  define CCTK_PARAMETER__CARPET__split_components PRIVATE_CARPET_STRUCT.split_components
#endif
#ifndef CCTK_PARAMETER__CARPET__split_direction
#  define CCTK_PARAMETER__CARPET__split_direction PRIVATE_CARPET_STRUCT.split_direction
#endif
#ifndef CCTK_PARAMETER__CARPET__storage_verbose
#  define CCTK_PARAMETER__CARPET__storage_verbose PRIVATE_CARPET_STRUCT.storage_verbose
#endif
#ifndef CCTK_PARAMETER__CARPET__suppress_restriction
#  define CCTK_PARAMETER__CARPET__suppress_restriction PRIVATE_CARPET_STRUCT.suppress_restriction
#endif
#ifndef CCTK_PARAMETER__CARPET__sync_barriers
#  define CCTK_PARAMETER__CARPET__sync_barriers PRIVATE_CARPET_STRUCT.sync_barriers
#endif
#ifndef CCTK_PARAMETER__CARPET__sync_during_time_integration
#  define CCTK_PARAMETER__CARPET__sync_during_time_integration PRIVATE_CARPET_STRUCT.sync_during_time_integration
#endif
#ifndef CCTK_PARAMETER__CARPET__time_interpolation_during_regridding
#  define CCTK_PARAMETER__CARPET__time_interpolation_during_regridding PRIVATE_CARPET_STRUCT.time_interpolation_during_regridding
#endif
#ifndef CCTK_PARAMETER__CARPET__use_buffer_zones
#  define CCTK_PARAMETER__CARPET__use_buffer_zones PRIVATE_CARPET_STRUCT.use_buffer_zones
#endif
#ifndef CCTK_PARAMETER__CARPET__use_overlap_zones
#  define CCTK_PARAMETER__CARPET__use_overlap_zones PRIVATE_CARPET_STRUCT.use_overlap_zones
#endif
#ifndef CCTK_PARAMETER__CARPET__use_tapered_grids
#  define CCTK_PARAMETER__CARPET__use_tapered_grids PRIVATE_CARPET_STRUCT.use_tapered_grids
#endif
#ifndef CCTK_PARAMETER__CARPET__use_unusedpoints_mask
#  define CCTK_PARAMETER__CARPET__use_unusedpoints_mask PRIVATE_CARPET_STRUCT.use_unusedpoints_mask
#endif
#ifndef CCTK_PARAMETER__CARPET__verbose
#  define CCTK_PARAMETER__CARPET__verbose PRIVATE_CARPET_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__CARPET__veryverbose
#  define CCTK_PARAMETER__CARPET__veryverbose PRIVATE_CARPET_STRUCT.veryverbose
#endif

