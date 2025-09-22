#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL out0D_dt;
  CCTK_REAL out0D_point_x;
  CCTK_REAL out0D_point_y;
  CCTK_REAL out0D_point_z;
  CCTK_REAL out1D_dt;
  CCTK_REAL out1D_xline_y;
  CCTK_REAL out1D_xline_z;
  CCTK_REAL out1D_yline_x;
  CCTK_REAL out1D_yline_z;
  CCTK_REAL out1D_zline_x;
  CCTK_REAL out1D_zline_y;
  CCTK_REAL out2D_dt;
  CCTK_REAL out2D_xyplane_z;
  CCTK_REAL out2D_xzplane_y;
  CCTK_REAL out2D_yzplane_x;
  CCTK_REAL out3D_dt;
  CCTK_REAL out_dt;
  const char * out0D_criterion;
  const char * out0D_dir;
  const char * out0D_vars;
  const char * out1D_criterion;
  const char * out1D_dir;
  const char * out1D_vars;
  const char * out2D_criterion;
  const char * out2D_dir;
  const char * out2D_vars;
  const char * out3D_criterion;
  const char * out3D_dir;
  const char * out3D_vars;
  const char * out_criterion;
  const char * out_dir;
  const char * out_extension;
  const char * out_vars;
  const char * skip_recover_variables;
  CCTK_INT checkpoint;
  CCTK_INT checkpoint_every_divisor;
  CCTK_INT checkpoint_next;
  CCTK_INT compression_level;
  CCTK_INT minimum_size_for_compression;
  CCTK_INT one_file_per_group;
  CCTK_INT open_one_input_file_at_a_time;
  CCTK_INT out0D_every;
  CCTK_INT out0D_point_xi;
  CCTK_INT out0D_point_yi;
  CCTK_INT out0D_point_zi;
  CCTK_INT out1D_d;
  CCTK_INT out1D_every;
  CCTK_INT out1D_x;
  CCTK_INT out1D_xline_yi;
  CCTK_INT out1D_xline_zi;
  CCTK_INT out1D_y;
  CCTK_INT out1D_yline_xi;
  CCTK_INT out1D_yline_zi;
  CCTK_INT out1D_z;
  CCTK_INT out1D_zline_xi;
  CCTK_INT out1D_zline_yi;
  CCTK_INT out2D_every;
  CCTK_INT out2D_xy;
  CCTK_INT out2D_xyplane_zi;
  CCTK_INT out2D_xz;
  CCTK_INT out2D_xzplane_yi;
  CCTK_INT out2D_yz;
  CCTK_INT out2D_yzplane_xi;
  CCTK_INT out3D_every;
  CCTK_INT out3D_ghosts;
  CCTK_INT out3D_outer_ghosts;
  CCTK_INT out_every;
  CCTK_INT output_all_timelevels;
  CCTK_INT output_boundary_points;
  CCTK_INT output_buffer_points;
  CCTK_INT output_ghost_points;
  CCTK_INT output_index;
  CCTK_INT output_symmetry_points;
  CCTK_INT use_checksums;
  CCTK_INT use_grid_structure_from_checkpoint;
  CCTK_INT use_reflevels_from_checkpoint;
} PRIVATE_CARPETIOHDF5_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETIOHDF5_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, out0D_dt, CCTK_PARAMETER__CARPETIOHDF5__out0D_dt); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out0D_point_x, CCTK_PARAMETER__CARPETIOHDF5__out0D_point_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out0D_point_y, CCTK_PARAMETER__CARPETIOHDF5__out0D_point_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out0D_point_z, CCTK_PARAMETER__CARPETIOHDF5__out0D_point_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out1D_dt, CCTK_PARAMETER__CARPETIOHDF5__out1D_dt); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out1D_xline_y, CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out1D_xline_z, CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out1D_yline_x, CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out1D_yline_z, CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out1D_zline_x, CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out1D_zline_y, CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out2D_dt, CCTK_PARAMETER__CARPETIOHDF5__out2D_dt); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out2D_xyplane_z, CCTK_PARAMETER__CARPETIOHDF5__out2D_xyplane_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out2D_xzplane_y, CCTK_PARAMETER__CARPETIOHDF5__out2D_xzplane_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out2D_yzplane_x, CCTK_PARAMETER__CARPETIOHDF5__out2D_yzplane_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out3D_dt, CCTK_PARAMETER__CARPETIOHDF5__out3D_dt); \
  CCTK_DECLARE_INIT (CCTK_REAL const, out_dt, CCTK_PARAMETER__CARPETIOHDF5__out_dt); \
  CCTK_DECLARE_INIT (const char * const, out0D_criterion, CCTK_PARAMETER__CARPETIOHDF5__out0D_criterion); \
  CCTK_DECLARE_INIT (const char * const, out0D_dir, CCTK_PARAMETER__CARPETIOHDF5__out0D_dir); \
  CCTK_DECLARE_INIT (const char * const, out0D_vars, CCTK_PARAMETER__CARPETIOHDF5__out0D_vars); \
  CCTK_DECLARE_INIT (const char * const, out1D_criterion, CCTK_PARAMETER__CARPETIOHDF5__out1D_criterion); \
  CCTK_DECLARE_INIT (const char * const, out1D_dir, CCTK_PARAMETER__CARPETIOHDF5__out1D_dir); \
  CCTK_DECLARE_INIT (const char * const, out1D_vars, CCTK_PARAMETER__CARPETIOHDF5__out1D_vars); \
  CCTK_DECLARE_INIT (const char * const, out2D_criterion, CCTK_PARAMETER__CARPETIOHDF5__out2D_criterion); \
  CCTK_DECLARE_INIT (const char * const, out2D_dir, CCTK_PARAMETER__CARPETIOHDF5__out2D_dir); \
  CCTK_DECLARE_INIT (const char * const, out2D_vars, CCTK_PARAMETER__CARPETIOHDF5__out2D_vars); \
  CCTK_DECLARE_INIT (const char * const, out3D_criterion, CCTK_PARAMETER__CARPETIOHDF5__out3D_criterion); \
  CCTK_DECLARE_INIT (const char * const, out3D_dir, CCTK_PARAMETER__CARPETIOHDF5__out3D_dir); \
  CCTK_DECLARE_INIT (const char * const, out3D_vars, CCTK_PARAMETER__CARPETIOHDF5__out3D_vars); \
  CCTK_DECLARE_INIT (const char * const, out_criterion, CCTK_PARAMETER__CARPETIOHDF5__out_criterion); \
  CCTK_DECLARE_INIT (const char * const, out_dir, CCTK_PARAMETER__CARPETIOHDF5__out_dir); \
  CCTK_DECLARE_INIT (const char * const, out_extension, CCTK_PARAMETER__CARPETIOHDF5__out_extension); \
  CCTK_DECLARE_INIT (const char * const, out_vars, CCTK_PARAMETER__CARPETIOHDF5__out_vars); \
  CCTK_DECLARE_INIT (const char * const, skip_recover_variables, CCTK_PARAMETER__CARPETIOHDF5__skip_recover_variables); \
  CCTK_DECLARE_INIT (CCTK_INT const, checkpoint, CCTK_PARAMETER__CARPETIOHDF5__checkpoint); \
  CCTK_DECLARE_INIT (CCTK_INT const, checkpoint_every_divisor, CCTK_PARAMETER__CARPETIOHDF5__checkpoint_every_divisor); \
  CCTK_DECLARE_INIT (CCTK_INT const, checkpoint_next, CCTK_PARAMETER__CARPETIOHDF5__checkpoint_next); \
  CCTK_DECLARE_INIT (CCTK_INT const, compression_level, CCTK_PARAMETER__CARPETIOHDF5__compression_level); \
  CCTK_DECLARE_INIT (CCTK_INT const, minimum_size_for_compression, CCTK_PARAMETER__CARPETIOHDF5__minimum_size_for_compression); \
  CCTK_DECLARE_INIT (CCTK_INT const, one_file_per_group, CCTK_PARAMETER__CARPETIOHDF5__one_file_per_group); \
  CCTK_DECLARE_INIT (CCTK_INT const, open_one_input_file_at_a_time, CCTK_PARAMETER__CARPETIOHDF5__open_one_input_file_at_a_time); \
  CCTK_DECLARE_INIT (CCTK_INT const, out0D_every, CCTK_PARAMETER__CARPETIOHDF5__out0D_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, out0D_point_xi, CCTK_PARAMETER__CARPETIOHDF5__out0D_point_xi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out0D_point_yi, CCTK_PARAMETER__CARPETIOHDF5__out0D_point_yi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out0D_point_zi, CCTK_PARAMETER__CARPETIOHDF5__out0D_point_zi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_d, CCTK_PARAMETER__CARPETIOHDF5__out1D_d); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_every, CCTK_PARAMETER__CARPETIOHDF5__out1D_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_x, CCTK_PARAMETER__CARPETIOHDF5__out1D_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_xline_yi, CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_yi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_xline_zi, CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_zi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_y, CCTK_PARAMETER__CARPETIOHDF5__out1D_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_yline_xi, CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_xi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_yline_zi, CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_zi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_z, CCTK_PARAMETER__CARPETIOHDF5__out1D_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_zline_xi, CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_xi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out1D_zline_yi, CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_yi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_every, CCTK_PARAMETER__CARPETIOHDF5__out2D_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_xy, CCTK_PARAMETER__CARPETIOHDF5__out2D_xy); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_xyplane_zi, CCTK_PARAMETER__CARPETIOHDF5__out2D_xyplane_zi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_xz, CCTK_PARAMETER__CARPETIOHDF5__out2D_xz); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_xzplane_yi, CCTK_PARAMETER__CARPETIOHDF5__out2D_xzplane_yi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_yz, CCTK_PARAMETER__CARPETIOHDF5__out2D_yz); \
  CCTK_DECLARE_INIT (CCTK_INT const, out2D_yzplane_xi, CCTK_PARAMETER__CARPETIOHDF5__out2D_yzplane_xi); \
  CCTK_DECLARE_INIT (CCTK_INT const, out3D_every, CCTK_PARAMETER__CARPETIOHDF5__out3D_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, out3D_ghosts, CCTK_PARAMETER__CARPETIOHDF5__out3D_ghosts); \
  CCTK_DECLARE_INIT (CCTK_INT const, out3D_outer_ghosts, CCTK_PARAMETER__CARPETIOHDF5__out3D_outer_ghosts); \
  CCTK_DECLARE_INIT (CCTK_INT const, out_every, CCTK_PARAMETER__CARPETIOHDF5__out_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_all_timelevels, CCTK_PARAMETER__CARPETIOHDF5__output_all_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_boundary_points, CCTK_PARAMETER__CARPETIOHDF5__output_boundary_points); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_buffer_points, CCTK_PARAMETER__CARPETIOHDF5__output_buffer_points); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_ghost_points, CCTK_PARAMETER__CARPETIOHDF5__output_ghost_points); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_index, CCTK_PARAMETER__CARPETIOHDF5__output_index); \
  CCTK_DECLARE_INIT (CCTK_INT const, output_symmetry_points, CCTK_PARAMETER__CARPETIOHDF5__output_symmetry_points); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_checksums, CCTK_PARAMETER__CARPETIOHDF5__use_checksums); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_grid_structure_from_checkpoint, CCTK_PARAMETER__CARPETIOHDF5__use_grid_structure_from_checkpoint); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_reflevels_from_checkpoint, CCTK_PARAMETER__CARPETIOHDF5__use_reflevels_from_checkpoint); \


#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_dt
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_dt PRIVATE_CARPETIOHDF5_STRUCT.out0D_dt
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_point_x
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_point_x PRIVATE_CARPETIOHDF5_STRUCT.out0D_point_x
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_point_y
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_point_y PRIVATE_CARPETIOHDF5_STRUCT.out0D_point_y
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_point_z
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_point_z PRIVATE_CARPETIOHDF5_STRUCT.out0D_point_z
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_dt
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_dt PRIVATE_CARPETIOHDF5_STRUCT.out1D_dt
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_y
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_y PRIVATE_CARPETIOHDF5_STRUCT.out1D_xline_y
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_z
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_z PRIVATE_CARPETIOHDF5_STRUCT.out1D_xline_z
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_x
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_x PRIVATE_CARPETIOHDF5_STRUCT.out1D_yline_x
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_z
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_z PRIVATE_CARPETIOHDF5_STRUCT.out1D_yline_z
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_x
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_x PRIVATE_CARPETIOHDF5_STRUCT.out1D_zline_x
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_y
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_y PRIVATE_CARPETIOHDF5_STRUCT.out1D_zline_y
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_dt
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_dt PRIVATE_CARPETIOHDF5_STRUCT.out2D_dt
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_xyplane_z
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_xyplane_z PRIVATE_CARPETIOHDF5_STRUCT.out2D_xyplane_z
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_xzplane_y
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_xzplane_y PRIVATE_CARPETIOHDF5_STRUCT.out2D_xzplane_y
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_yzplane_x
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_yzplane_x PRIVATE_CARPETIOHDF5_STRUCT.out2D_yzplane_x
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out3D_dt
#  define CCTK_PARAMETER__CARPETIOHDF5__out3D_dt PRIVATE_CARPETIOHDF5_STRUCT.out3D_dt
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out_dt
#  define CCTK_PARAMETER__CARPETIOHDF5__out_dt PRIVATE_CARPETIOHDF5_STRUCT.out_dt
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_criterion
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_criterion PRIVATE_CARPETIOHDF5_STRUCT.out0D_criterion
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_dir
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_dir PRIVATE_CARPETIOHDF5_STRUCT.out0D_dir
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_vars
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_vars PRIVATE_CARPETIOHDF5_STRUCT.out0D_vars
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_criterion
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_criterion PRIVATE_CARPETIOHDF5_STRUCT.out1D_criterion
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_dir
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_dir PRIVATE_CARPETIOHDF5_STRUCT.out1D_dir
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_vars
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_vars PRIVATE_CARPETIOHDF5_STRUCT.out1D_vars
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_criterion
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_criterion PRIVATE_CARPETIOHDF5_STRUCT.out2D_criterion
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_dir
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_dir PRIVATE_CARPETIOHDF5_STRUCT.out2D_dir
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_vars
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_vars PRIVATE_CARPETIOHDF5_STRUCT.out2D_vars
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out3D_criterion
#  define CCTK_PARAMETER__CARPETIOHDF5__out3D_criterion PRIVATE_CARPETIOHDF5_STRUCT.out3D_criterion
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out3D_dir
#  define CCTK_PARAMETER__CARPETIOHDF5__out3D_dir PRIVATE_CARPETIOHDF5_STRUCT.out3D_dir
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out3D_vars
#  define CCTK_PARAMETER__CARPETIOHDF5__out3D_vars PRIVATE_CARPETIOHDF5_STRUCT.out3D_vars
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out_criterion
#  define CCTK_PARAMETER__CARPETIOHDF5__out_criterion PRIVATE_CARPETIOHDF5_STRUCT.out_criterion
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out_dir
#  define CCTK_PARAMETER__CARPETIOHDF5__out_dir PRIVATE_CARPETIOHDF5_STRUCT.out_dir
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out_extension
#  define CCTK_PARAMETER__CARPETIOHDF5__out_extension PRIVATE_CARPETIOHDF5_STRUCT.out_extension
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out_vars
#  define CCTK_PARAMETER__CARPETIOHDF5__out_vars PRIVATE_CARPETIOHDF5_STRUCT.out_vars
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__skip_recover_variables
#  define CCTK_PARAMETER__CARPETIOHDF5__skip_recover_variables PRIVATE_CARPETIOHDF5_STRUCT.skip_recover_variables
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__checkpoint
#  define CCTK_PARAMETER__CARPETIOHDF5__checkpoint PRIVATE_CARPETIOHDF5_STRUCT.checkpoint
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__checkpoint_every_divisor
#  define CCTK_PARAMETER__CARPETIOHDF5__checkpoint_every_divisor PRIVATE_CARPETIOHDF5_STRUCT.checkpoint_every_divisor
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__checkpoint_next
#  define CCTK_PARAMETER__CARPETIOHDF5__checkpoint_next PRIVATE_CARPETIOHDF5_STRUCT.checkpoint_next
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__compression_level
#  define CCTK_PARAMETER__CARPETIOHDF5__compression_level PRIVATE_CARPETIOHDF5_STRUCT.compression_level
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__minimum_size_for_compression
#  define CCTK_PARAMETER__CARPETIOHDF5__minimum_size_for_compression PRIVATE_CARPETIOHDF5_STRUCT.minimum_size_for_compression
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__one_file_per_group
#  define CCTK_PARAMETER__CARPETIOHDF5__one_file_per_group PRIVATE_CARPETIOHDF5_STRUCT.one_file_per_group
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__open_one_input_file_at_a_time
#  define CCTK_PARAMETER__CARPETIOHDF5__open_one_input_file_at_a_time PRIVATE_CARPETIOHDF5_STRUCT.open_one_input_file_at_a_time
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_every
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_every PRIVATE_CARPETIOHDF5_STRUCT.out0D_every
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_point_xi
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_point_xi PRIVATE_CARPETIOHDF5_STRUCT.out0D_point_xi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_point_yi
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_point_yi PRIVATE_CARPETIOHDF5_STRUCT.out0D_point_yi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out0D_point_zi
#  define CCTK_PARAMETER__CARPETIOHDF5__out0D_point_zi PRIVATE_CARPETIOHDF5_STRUCT.out0D_point_zi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_d
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_d PRIVATE_CARPETIOHDF5_STRUCT.out1D_d
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_every
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_every PRIVATE_CARPETIOHDF5_STRUCT.out1D_every
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_x
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_x PRIVATE_CARPETIOHDF5_STRUCT.out1D_x
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_yi
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_yi PRIVATE_CARPETIOHDF5_STRUCT.out1D_xline_yi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_zi
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_xline_zi PRIVATE_CARPETIOHDF5_STRUCT.out1D_xline_zi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_y
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_y PRIVATE_CARPETIOHDF5_STRUCT.out1D_y
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_xi
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_xi PRIVATE_CARPETIOHDF5_STRUCT.out1D_yline_xi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_zi
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_yline_zi PRIVATE_CARPETIOHDF5_STRUCT.out1D_yline_zi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_z
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_z PRIVATE_CARPETIOHDF5_STRUCT.out1D_z
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_xi
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_xi PRIVATE_CARPETIOHDF5_STRUCT.out1D_zline_xi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_yi
#  define CCTK_PARAMETER__CARPETIOHDF5__out1D_zline_yi PRIVATE_CARPETIOHDF5_STRUCT.out1D_zline_yi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_every
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_every PRIVATE_CARPETIOHDF5_STRUCT.out2D_every
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_xy
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_xy PRIVATE_CARPETIOHDF5_STRUCT.out2D_xy
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_xyplane_zi
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_xyplane_zi PRIVATE_CARPETIOHDF5_STRUCT.out2D_xyplane_zi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_xz
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_xz PRIVATE_CARPETIOHDF5_STRUCT.out2D_xz
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_xzplane_yi
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_xzplane_yi PRIVATE_CARPETIOHDF5_STRUCT.out2D_xzplane_yi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_yz
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_yz PRIVATE_CARPETIOHDF5_STRUCT.out2D_yz
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out2D_yzplane_xi
#  define CCTK_PARAMETER__CARPETIOHDF5__out2D_yzplane_xi PRIVATE_CARPETIOHDF5_STRUCT.out2D_yzplane_xi
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out3D_every
#  define CCTK_PARAMETER__CARPETIOHDF5__out3D_every PRIVATE_CARPETIOHDF5_STRUCT.out3D_every
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out3D_ghosts
#  define CCTK_PARAMETER__CARPETIOHDF5__out3D_ghosts PRIVATE_CARPETIOHDF5_STRUCT.out3D_ghosts
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out3D_outer_ghosts
#  define CCTK_PARAMETER__CARPETIOHDF5__out3D_outer_ghosts PRIVATE_CARPETIOHDF5_STRUCT.out3D_outer_ghosts
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__out_every
#  define CCTK_PARAMETER__CARPETIOHDF5__out_every PRIVATE_CARPETIOHDF5_STRUCT.out_every
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__output_all_timelevels
#  define CCTK_PARAMETER__CARPETIOHDF5__output_all_timelevels PRIVATE_CARPETIOHDF5_STRUCT.output_all_timelevels
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__output_boundary_points
#  define CCTK_PARAMETER__CARPETIOHDF5__output_boundary_points PRIVATE_CARPETIOHDF5_STRUCT.output_boundary_points
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__output_buffer_points
#  define CCTK_PARAMETER__CARPETIOHDF5__output_buffer_points PRIVATE_CARPETIOHDF5_STRUCT.output_buffer_points
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__output_ghost_points
#  define CCTK_PARAMETER__CARPETIOHDF5__output_ghost_points PRIVATE_CARPETIOHDF5_STRUCT.output_ghost_points
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__output_index
#  define CCTK_PARAMETER__CARPETIOHDF5__output_index PRIVATE_CARPETIOHDF5_STRUCT.output_index
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__output_symmetry_points
#  define CCTK_PARAMETER__CARPETIOHDF5__output_symmetry_points PRIVATE_CARPETIOHDF5_STRUCT.output_symmetry_points
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__use_checksums
#  define CCTK_PARAMETER__CARPETIOHDF5__use_checksums PRIVATE_CARPETIOHDF5_STRUCT.use_checksums
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__use_grid_structure_from_checkpoint
#  define CCTK_PARAMETER__CARPETIOHDF5__use_grid_structure_from_checkpoint PRIVATE_CARPETIOHDF5_STRUCT.use_grid_structure_from_checkpoint
#endif
#ifndef CCTK_PARAMETER__CARPETIOHDF5__use_reflevels_from_checkpoint
#  define CCTK_PARAMETER__CARPETIOHDF5__use_reflevels_from_checkpoint PRIVATE_CARPETIOHDF5_STRUCT.use_reflevels_from_checkpoint
#endif

