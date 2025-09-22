#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL min_fraction;
  CCTK_REAL movement_threshold_1;
  CCTK_REAL movement_threshold_10;
  CCTK_REAL movement_threshold_2;
  CCTK_REAL movement_threshold_3;
  CCTK_REAL movement_threshold_4;
  CCTK_REAL movement_threshold_5;
  CCTK_REAL movement_threshold_6;
  CCTK_REAL movement_threshold_7;
  CCTK_REAL movement_threshold_8;
  CCTK_REAL movement_threshold_9;
  CCTK_REAL position_x_1;
  CCTK_REAL position_x_10;
  CCTK_REAL position_x_2;
  CCTK_REAL position_x_3;
  CCTK_REAL position_x_4;
  CCTK_REAL position_x_5;
  CCTK_REAL position_x_6;
  CCTK_REAL position_x_7;
  CCTK_REAL position_x_8;
  CCTK_REAL position_x_9;
  CCTK_REAL position_y_1;
  CCTK_REAL position_y_10;
  CCTK_REAL position_y_2;
  CCTK_REAL position_y_3;
  CCTK_REAL position_y_4;
  CCTK_REAL position_y_5;
  CCTK_REAL position_y_6;
  CCTK_REAL position_y_7;
  CCTK_REAL position_y_8;
  CCTK_REAL position_y_9;
  CCTK_REAL position_z_1;
  CCTK_REAL position_z_10;
  CCTK_REAL position_z_2;
  CCTK_REAL position_z_3;
  CCTK_REAL position_z_4;
  CCTK_REAL position_z_5;
  CCTK_REAL position_z_6;
  CCTK_REAL position_z_7;
  CCTK_REAL position_z_8;
  CCTK_REAL position_z_9;
  CCTK_REAL radius_1[30];
  CCTK_REAL radius_10[30];
  CCTK_REAL radius_2[30];
  CCTK_REAL radius_3[30];
  CCTK_REAL radius_4[30];
  CCTK_REAL radius_5[30];
  CCTK_REAL radius_6[30];
  CCTK_REAL radius_7[30];
  CCTK_REAL radius_8[30];
  CCTK_REAL radius_9[30];
  CCTK_REAL radius_rel_change_threshold_1;
  CCTK_REAL radius_rel_change_threshold_10;
  CCTK_REAL radius_rel_change_threshold_2;
  CCTK_REAL radius_rel_change_threshold_3;
  CCTK_REAL radius_rel_change_threshold_4;
  CCTK_REAL radius_rel_change_threshold_5;
  CCTK_REAL radius_rel_change_threshold_6;
  CCTK_REAL radius_rel_change_threshold_7;
  CCTK_REAL radius_rel_change_threshold_8;
  CCTK_REAL radius_rel_change_threshold_9;
  CCTK_REAL radius_x_1[30];
  CCTK_REAL radius_x_10[30];
  CCTK_REAL radius_x_2[30];
  CCTK_REAL radius_x_3[30];
  CCTK_REAL radius_x_4[30];
  CCTK_REAL radius_x_5[30];
  CCTK_REAL radius_x_6[30];
  CCTK_REAL radius_x_7[30];
  CCTK_REAL radius_x_8[30];
  CCTK_REAL radius_x_9[30];
  CCTK_REAL radius_y_1[30];
  CCTK_REAL radius_y_10[30];
  CCTK_REAL radius_y_2[30];
  CCTK_REAL radius_y_3[30];
  CCTK_REAL radius_y_4[30];
  CCTK_REAL radius_y_5[30];
  CCTK_REAL radius_y_6[30];
  CCTK_REAL radius_y_7[30];
  CCTK_REAL radius_y_8[30];
  CCTK_REAL radius_y_9[30];
  CCTK_REAL radius_z_1[30];
  CCTK_REAL radius_z_10[30];
  CCTK_REAL radius_z_2[30];
  CCTK_REAL radius_z_3[30];
  CCTK_REAL radius_z_4[30];
  CCTK_REAL radius_z_5[30];
  CCTK_REAL radius_z_6[30];
  CCTK_REAL radius_z_7[30];
  CCTK_REAL radius_z_8[30];
  CCTK_REAL radius_z_9[30];
  CCTK_INT active_1;
  CCTK_INT active_10;
  CCTK_INT active_2;
  CCTK_INT active_3;
  CCTK_INT active_4;
  CCTK_INT active_5;
  CCTK_INT active_6;
  CCTK_INT active_7;
  CCTK_INT active_8;
  CCTK_INT active_9;
  CCTK_INT adaptive_block_size;
  CCTK_INT adaptive_block_size_x;
  CCTK_INT adaptive_block_size_y;
  CCTK_INT adaptive_block_size_z;
  CCTK_INT adaptive_refinement;
  CCTK_INT add_levels_automatically;
  CCTK_INT boundary_shiftout;
  CCTK_INT ensure_proper_nesting;
  CCTK_INT expect_symmetric_grids;
  CCTK_INT freeze_unaligned_levels;
  CCTK_INT freeze_unaligned_parent_levels;
  CCTK_INT min_distance;
  CCTK_INT num_centres;
  CCTK_INT num_levels_1;
  CCTK_INT num_levels_10;
  CCTK_INT num_levels_2;
  CCTK_INT num_levels_3;
  CCTK_INT num_levels_4;
  CCTK_INT num_levels_5;
  CCTK_INT num_levels_6;
  CCTK_INT num_levels_7;
  CCTK_INT num_levels_8;
  CCTK_INT num_levels_9;
  CCTK_INT regrid_every;
  CCTK_INT snap_to_coarse;
  CCTK_INT symmetry_parity;
  CCTK_INT symmetry_periodic_x;
  CCTK_INT symmetry_periodic_y;
  CCTK_INT symmetry_periodic_z;
  CCTK_INT symmetry_rotating180;
  CCTK_INT symmetry_rotating90;
  CCTK_INT verbose;
  CCTK_INT veryverbose;
} PRIVATE_CARPETREGRID2_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETREGRID2_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, min_fraction, CCTK_PARAMETER__CARPETREGRID2__min_fraction); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_1, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_10, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_10); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_2, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_3, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_4, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_4); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_5, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_5); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_6, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_6); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_7, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_7); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_8, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_8); \
  CCTK_DECLARE_INIT (CCTK_REAL const, movement_threshold_9, CCTK_PARAMETER__CARPETREGRID2__movement_threshold_9); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_1, CCTK_PARAMETER__CARPETREGRID2__position_x_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_10, CCTK_PARAMETER__CARPETREGRID2__position_x_10); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_2, CCTK_PARAMETER__CARPETREGRID2__position_x_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_3, CCTK_PARAMETER__CARPETREGRID2__position_x_3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_4, CCTK_PARAMETER__CARPETREGRID2__position_x_4); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_5, CCTK_PARAMETER__CARPETREGRID2__position_x_5); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_6, CCTK_PARAMETER__CARPETREGRID2__position_x_6); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_7, CCTK_PARAMETER__CARPETREGRID2__position_x_7); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_8, CCTK_PARAMETER__CARPETREGRID2__position_x_8); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_x_9, CCTK_PARAMETER__CARPETREGRID2__position_x_9); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_1, CCTK_PARAMETER__CARPETREGRID2__position_y_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_10, CCTK_PARAMETER__CARPETREGRID2__position_y_10); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_2, CCTK_PARAMETER__CARPETREGRID2__position_y_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_3, CCTK_PARAMETER__CARPETREGRID2__position_y_3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_4, CCTK_PARAMETER__CARPETREGRID2__position_y_4); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_5, CCTK_PARAMETER__CARPETREGRID2__position_y_5); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_6, CCTK_PARAMETER__CARPETREGRID2__position_y_6); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_7, CCTK_PARAMETER__CARPETREGRID2__position_y_7); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_8, CCTK_PARAMETER__CARPETREGRID2__position_y_8); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_y_9, CCTK_PARAMETER__CARPETREGRID2__position_y_9); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_1, CCTK_PARAMETER__CARPETREGRID2__position_z_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_10, CCTK_PARAMETER__CARPETREGRID2__position_z_10); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_2, CCTK_PARAMETER__CARPETREGRID2__position_z_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_3, CCTK_PARAMETER__CARPETREGRID2__position_z_3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_4, CCTK_PARAMETER__CARPETREGRID2__position_z_4); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_5, CCTK_PARAMETER__CARPETREGRID2__position_z_5); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_6, CCTK_PARAMETER__CARPETREGRID2__position_z_6); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_7, CCTK_PARAMETER__CARPETREGRID2__position_z_7); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_8, CCTK_PARAMETER__CARPETREGRID2__position_z_8); \
  CCTK_DECLARE_INIT (CCTK_REAL const, position_z_9, CCTK_PARAMETER__CARPETREGRID2__position_z_9); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_1, CCTK_PARAMETER__CARPETREGRID2__radius_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_10, CCTK_PARAMETER__CARPETREGRID2__radius_10); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_2, CCTK_PARAMETER__CARPETREGRID2__radius_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_3, CCTK_PARAMETER__CARPETREGRID2__radius_3); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_4, CCTK_PARAMETER__CARPETREGRID2__radius_4); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_5, CCTK_PARAMETER__CARPETREGRID2__radius_5); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_6, CCTK_PARAMETER__CARPETREGRID2__radius_6); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_7, CCTK_PARAMETER__CARPETREGRID2__radius_7); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_8, CCTK_PARAMETER__CARPETREGRID2__radius_8); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_9, CCTK_PARAMETER__CARPETREGRID2__radius_9); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_1, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_10, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_10); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_2, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_3, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_3); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_4, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_4); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_5, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_5); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_6, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_6); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_7, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_7); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_8, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_8); \
  CCTK_DECLARE_INIT (CCTK_REAL const, radius_rel_change_threshold_9, CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_9); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_1, CCTK_PARAMETER__CARPETREGRID2__radius_x_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_10, CCTK_PARAMETER__CARPETREGRID2__radius_x_10); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_2, CCTK_PARAMETER__CARPETREGRID2__radius_x_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_3, CCTK_PARAMETER__CARPETREGRID2__radius_x_3); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_4, CCTK_PARAMETER__CARPETREGRID2__radius_x_4); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_5, CCTK_PARAMETER__CARPETREGRID2__radius_x_5); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_6, CCTK_PARAMETER__CARPETREGRID2__radius_x_6); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_7, CCTK_PARAMETER__CARPETREGRID2__radius_x_7); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_8, CCTK_PARAMETER__CARPETREGRID2__radius_x_8); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_x_9, CCTK_PARAMETER__CARPETREGRID2__radius_x_9); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_1, CCTK_PARAMETER__CARPETREGRID2__radius_y_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_10, CCTK_PARAMETER__CARPETREGRID2__radius_y_10); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_2, CCTK_PARAMETER__CARPETREGRID2__radius_y_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_3, CCTK_PARAMETER__CARPETREGRID2__radius_y_3); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_4, CCTK_PARAMETER__CARPETREGRID2__radius_y_4); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_5, CCTK_PARAMETER__CARPETREGRID2__radius_y_5); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_6, CCTK_PARAMETER__CARPETREGRID2__radius_y_6); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_7, CCTK_PARAMETER__CARPETREGRID2__radius_y_7); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_8, CCTK_PARAMETER__CARPETREGRID2__radius_y_8); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_y_9, CCTK_PARAMETER__CARPETREGRID2__radius_y_9); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_1, CCTK_PARAMETER__CARPETREGRID2__radius_z_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_10, CCTK_PARAMETER__CARPETREGRID2__radius_z_10); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_2, CCTK_PARAMETER__CARPETREGRID2__radius_z_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_3, CCTK_PARAMETER__CARPETREGRID2__radius_z_3); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_4, CCTK_PARAMETER__CARPETREGRID2__radius_z_4); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_5, CCTK_PARAMETER__CARPETREGRID2__radius_z_5); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_6, CCTK_PARAMETER__CARPETREGRID2__radius_z_6); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_7, CCTK_PARAMETER__CARPETREGRID2__radius_z_7); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_8, CCTK_PARAMETER__CARPETREGRID2__radius_z_8); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, radius_z_9, CCTK_PARAMETER__CARPETREGRID2__radius_z_9); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_1, CCTK_PARAMETER__CARPETREGRID2__active_1); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_10, CCTK_PARAMETER__CARPETREGRID2__active_10); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_2, CCTK_PARAMETER__CARPETREGRID2__active_2); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_3, CCTK_PARAMETER__CARPETREGRID2__active_3); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_4, CCTK_PARAMETER__CARPETREGRID2__active_4); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_5, CCTK_PARAMETER__CARPETREGRID2__active_5); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_6, CCTK_PARAMETER__CARPETREGRID2__active_6); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_7, CCTK_PARAMETER__CARPETREGRID2__active_7); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_8, CCTK_PARAMETER__CARPETREGRID2__active_8); \
  CCTK_DECLARE_INIT (CCTK_INT const, active_9, CCTK_PARAMETER__CARPETREGRID2__active_9); \
  CCTK_DECLARE_INIT (CCTK_INT const, adaptive_block_size, CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size); \
  CCTK_DECLARE_INIT (CCTK_INT const, adaptive_block_size_x, CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, adaptive_block_size_y, CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, adaptive_block_size_z, CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, adaptive_refinement, CCTK_PARAMETER__CARPETREGRID2__adaptive_refinement); \
  CCTK_DECLARE_INIT (CCTK_INT const, add_levels_automatically, CCTK_PARAMETER__CARPETREGRID2__add_levels_automatically); \
  CCTK_DECLARE_INIT (CCTK_INT const, boundary_shiftout, CCTK_PARAMETER__CARPETREGRID2__boundary_shiftout); \
  CCTK_DECLARE_INIT (CCTK_INT const, ensure_proper_nesting, CCTK_PARAMETER__CARPETREGRID2__ensure_proper_nesting); \
  CCTK_DECLARE_INIT (CCTK_INT const, expect_symmetric_grids, CCTK_PARAMETER__CARPETREGRID2__expect_symmetric_grids); \
  CCTK_DECLARE_INIT (CCTK_INT const, freeze_unaligned_levels, CCTK_PARAMETER__CARPETREGRID2__freeze_unaligned_levels); \
  CCTK_DECLARE_INIT (CCTK_INT const, freeze_unaligned_parent_levels, CCTK_PARAMETER__CARPETREGRID2__freeze_unaligned_parent_levels); \
  CCTK_DECLARE_INIT (CCTK_INT const, min_distance, CCTK_PARAMETER__CARPETREGRID2__min_distance); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_centres, CCTK_PARAMETER__CARPETREGRID2__num_centres); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_1, CCTK_PARAMETER__CARPETREGRID2__num_levels_1); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_10, CCTK_PARAMETER__CARPETREGRID2__num_levels_10); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_2, CCTK_PARAMETER__CARPETREGRID2__num_levels_2); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_3, CCTK_PARAMETER__CARPETREGRID2__num_levels_3); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_4, CCTK_PARAMETER__CARPETREGRID2__num_levels_4); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_5, CCTK_PARAMETER__CARPETREGRID2__num_levels_5); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_6, CCTK_PARAMETER__CARPETREGRID2__num_levels_6); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_7, CCTK_PARAMETER__CARPETREGRID2__num_levels_7); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_8, CCTK_PARAMETER__CARPETREGRID2__num_levels_8); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_levels_9, CCTK_PARAMETER__CARPETREGRID2__num_levels_9); \
  CCTK_DECLARE_INIT (CCTK_INT const, regrid_every, CCTK_PARAMETER__CARPETREGRID2__regrid_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, snap_to_coarse, CCTK_PARAMETER__CARPETREGRID2__snap_to_coarse); \
  CCTK_DECLARE_INIT (CCTK_INT const, symmetry_parity, CCTK_PARAMETER__CARPETREGRID2__symmetry_parity); \
  CCTK_DECLARE_INIT (CCTK_INT const, symmetry_periodic_x, CCTK_PARAMETER__CARPETREGRID2__symmetry_periodic_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, symmetry_periodic_y, CCTK_PARAMETER__CARPETREGRID2__symmetry_periodic_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, symmetry_periodic_z, CCTK_PARAMETER__CARPETREGRID2__symmetry_periodic_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, symmetry_rotating180, CCTK_PARAMETER__CARPETREGRID2__symmetry_rotating180); \
  CCTK_DECLARE_INIT (CCTK_INT const, symmetry_rotating90, CCTK_PARAMETER__CARPETREGRID2__symmetry_rotating90); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARPETREGRID2__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, veryverbose, CCTK_PARAMETER__CARPETREGRID2__veryverbose); \


#ifndef CCTK_PARAMETER__CARPETREGRID2__min_fraction
#  define CCTK_PARAMETER__CARPETREGRID2__min_fraction PRIVATE_CARPETREGRID2_STRUCT.min_fraction
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_1
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_1 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_10
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_10 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_2
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_2 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_3
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_3 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_4
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_4 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_5
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_5 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_6
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_6 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_7
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_7 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_8
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_8 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__movement_threshold_9
#  define CCTK_PARAMETER__CARPETREGRID2__movement_threshold_9 PRIVATE_CARPETREGRID2_STRUCT.movement_threshold_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_1
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_1 PRIVATE_CARPETREGRID2_STRUCT.position_x_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_10
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_10 PRIVATE_CARPETREGRID2_STRUCT.position_x_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_2
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_2 PRIVATE_CARPETREGRID2_STRUCT.position_x_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_3
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_3 PRIVATE_CARPETREGRID2_STRUCT.position_x_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_4
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_4 PRIVATE_CARPETREGRID2_STRUCT.position_x_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_5
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_5 PRIVATE_CARPETREGRID2_STRUCT.position_x_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_6
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_6 PRIVATE_CARPETREGRID2_STRUCT.position_x_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_7
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_7 PRIVATE_CARPETREGRID2_STRUCT.position_x_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_8
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_8 PRIVATE_CARPETREGRID2_STRUCT.position_x_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_x_9
#  define CCTK_PARAMETER__CARPETREGRID2__position_x_9 PRIVATE_CARPETREGRID2_STRUCT.position_x_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_1
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_1 PRIVATE_CARPETREGRID2_STRUCT.position_y_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_10
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_10 PRIVATE_CARPETREGRID2_STRUCT.position_y_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_2
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_2 PRIVATE_CARPETREGRID2_STRUCT.position_y_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_3
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_3 PRIVATE_CARPETREGRID2_STRUCT.position_y_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_4
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_4 PRIVATE_CARPETREGRID2_STRUCT.position_y_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_5
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_5 PRIVATE_CARPETREGRID2_STRUCT.position_y_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_6
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_6 PRIVATE_CARPETREGRID2_STRUCT.position_y_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_7
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_7 PRIVATE_CARPETREGRID2_STRUCT.position_y_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_8
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_8 PRIVATE_CARPETREGRID2_STRUCT.position_y_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_y_9
#  define CCTK_PARAMETER__CARPETREGRID2__position_y_9 PRIVATE_CARPETREGRID2_STRUCT.position_y_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_1
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_1 PRIVATE_CARPETREGRID2_STRUCT.position_z_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_10
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_10 PRIVATE_CARPETREGRID2_STRUCT.position_z_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_2
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_2 PRIVATE_CARPETREGRID2_STRUCT.position_z_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_3
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_3 PRIVATE_CARPETREGRID2_STRUCT.position_z_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_4
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_4 PRIVATE_CARPETREGRID2_STRUCT.position_z_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_5
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_5 PRIVATE_CARPETREGRID2_STRUCT.position_z_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_6
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_6 PRIVATE_CARPETREGRID2_STRUCT.position_z_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_7
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_7 PRIVATE_CARPETREGRID2_STRUCT.position_z_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_8
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_8 PRIVATE_CARPETREGRID2_STRUCT.position_z_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__position_z_9
#  define CCTK_PARAMETER__CARPETREGRID2__position_z_9 PRIVATE_CARPETREGRID2_STRUCT.position_z_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_1
#  define CCTK_PARAMETER__CARPETREGRID2__radius_1 PRIVATE_CARPETREGRID2_STRUCT.radius_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_10
#  define CCTK_PARAMETER__CARPETREGRID2__radius_10 PRIVATE_CARPETREGRID2_STRUCT.radius_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_2
#  define CCTK_PARAMETER__CARPETREGRID2__radius_2 PRIVATE_CARPETREGRID2_STRUCT.radius_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_3
#  define CCTK_PARAMETER__CARPETREGRID2__radius_3 PRIVATE_CARPETREGRID2_STRUCT.radius_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_4
#  define CCTK_PARAMETER__CARPETREGRID2__radius_4 PRIVATE_CARPETREGRID2_STRUCT.radius_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_5
#  define CCTK_PARAMETER__CARPETREGRID2__radius_5 PRIVATE_CARPETREGRID2_STRUCT.radius_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_6
#  define CCTK_PARAMETER__CARPETREGRID2__radius_6 PRIVATE_CARPETREGRID2_STRUCT.radius_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_7
#  define CCTK_PARAMETER__CARPETREGRID2__radius_7 PRIVATE_CARPETREGRID2_STRUCT.radius_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_8
#  define CCTK_PARAMETER__CARPETREGRID2__radius_8 PRIVATE_CARPETREGRID2_STRUCT.radius_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_9
#  define CCTK_PARAMETER__CARPETREGRID2__radius_9 PRIVATE_CARPETREGRID2_STRUCT.radius_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_1
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_1 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_10
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_10 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_2
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_2 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_3
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_3 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_4
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_4 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_5
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_5 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_6
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_6 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_7
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_7 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_8
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_8 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_9
#  define CCTK_PARAMETER__CARPETREGRID2__radius_rel_change_threshold_9 PRIVATE_CARPETREGRID2_STRUCT.radius_rel_change_threshold_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_1
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_1 PRIVATE_CARPETREGRID2_STRUCT.radius_x_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_10
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_10 PRIVATE_CARPETREGRID2_STRUCT.radius_x_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_2
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_2 PRIVATE_CARPETREGRID2_STRUCT.radius_x_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_3
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_3 PRIVATE_CARPETREGRID2_STRUCT.radius_x_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_4
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_4 PRIVATE_CARPETREGRID2_STRUCT.radius_x_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_5
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_5 PRIVATE_CARPETREGRID2_STRUCT.radius_x_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_6
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_6 PRIVATE_CARPETREGRID2_STRUCT.radius_x_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_7
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_7 PRIVATE_CARPETREGRID2_STRUCT.radius_x_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_8
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_8 PRIVATE_CARPETREGRID2_STRUCT.radius_x_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_x_9
#  define CCTK_PARAMETER__CARPETREGRID2__radius_x_9 PRIVATE_CARPETREGRID2_STRUCT.radius_x_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_1
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_1 PRIVATE_CARPETREGRID2_STRUCT.radius_y_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_10
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_10 PRIVATE_CARPETREGRID2_STRUCT.radius_y_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_2
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_2 PRIVATE_CARPETREGRID2_STRUCT.radius_y_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_3
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_3 PRIVATE_CARPETREGRID2_STRUCT.radius_y_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_4
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_4 PRIVATE_CARPETREGRID2_STRUCT.radius_y_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_5
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_5 PRIVATE_CARPETREGRID2_STRUCT.radius_y_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_6
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_6 PRIVATE_CARPETREGRID2_STRUCT.radius_y_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_7
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_7 PRIVATE_CARPETREGRID2_STRUCT.radius_y_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_8
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_8 PRIVATE_CARPETREGRID2_STRUCT.radius_y_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_y_9
#  define CCTK_PARAMETER__CARPETREGRID2__radius_y_9 PRIVATE_CARPETREGRID2_STRUCT.radius_y_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_1
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_1 PRIVATE_CARPETREGRID2_STRUCT.radius_z_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_10
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_10 PRIVATE_CARPETREGRID2_STRUCT.radius_z_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_2
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_2 PRIVATE_CARPETREGRID2_STRUCT.radius_z_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_3
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_3 PRIVATE_CARPETREGRID2_STRUCT.radius_z_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_4
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_4 PRIVATE_CARPETREGRID2_STRUCT.radius_z_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_5
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_5 PRIVATE_CARPETREGRID2_STRUCT.radius_z_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_6
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_6 PRIVATE_CARPETREGRID2_STRUCT.radius_z_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_7
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_7 PRIVATE_CARPETREGRID2_STRUCT.radius_z_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_8
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_8 PRIVATE_CARPETREGRID2_STRUCT.radius_z_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__radius_z_9
#  define CCTK_PARAMETER__CARPETREGRID2__radius_z_9 PRIVATE_CARPETREGRID2_STRUCT.radius_z_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_1
#  define CCTK_PARAMETER__CARPETREGRID2__active_1 PRIVATE_CARPETREGRID2_STRUCT.active_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_10
#  define CCTK_PARAMETER__CARPETREGRID2__active_10 PRIVATE_CARPETREGRID2_STRUCT.active_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_2
#  define CCTK_PARAMETER__CARPETREGRID2__active_2 PRIVATE_CARPETREGRID2_STRUCT.active_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_3
#  define CCTK_PARAMETER__CARPETREGRID2__active_3 PRIVATE_CARPETREGRID2_STRUCT.active_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_4
#  define CCTK_PARAMETER__CARPETREGRID2__active_4 PRIVATE_CARPETREGRID2_STRUCT.active_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_5
#  define CCTK_PARAMETER__CARPETREGRID2__active_5 PRIVATE_CARPETREGRID2_STRUCT.active_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_6
#  define CCTK_PARAMETER__CARPETREGRID2__active_6 PRIVATE_CARPETREGRID2_STRUCT.active_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_7
#  define CCTK_PARAMETER__CARPETREGRID2__active_7 PRIVATE_CARPETREGRID2_STRUCT.active_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_8
#  define CCTK_PARAMETER__CARPETREGRID2__active_8 PRIVATE_CARPETREGRID2_STRUCT.active_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__active_9
#  define CCTK_PARAMETER__CARPETREGRID2__active_9 PRIVATE_CARPETREGRID2_STRUCT.active_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size
#  define CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size PRIVATE_CARPETREGRID2_STRUCT.adaptive_block_size
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size_x
#  define CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size_x PRIVATE_CARPETREGRID2_STRUCT.adaptive_block_size_x
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size_y
#  define CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size_y PRIVATE_CARPETREGRID2_STRUCT.adaptive_block_size_y
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size_z
#  define CCTK_PARAMETER__CARPETREGRID2__adaptive_block_size_z PRIVATE_CARPETREGRID2_STRUCT.adaptive_block_size_z
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__adaptive_refinement
#  define CCTK_PARAMETER__CARPETREGRID2__adaptive_refinement PRIVATE_CARPETREGRID2_STRUCT.adaptive_refinement
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__add_levels_automatically
#  define CCTK_PARAMETER__CARPETREGRID2__add_levels_automatically PRIVATE_CARPETREGRID2_STRUCT.add_levels_automatically
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__boundary_shiftout
#  define CCTK_PARAMETER__CARPETREGRID2__boundary_shiftout PRIVATE_CARPETREGRID2_STRUCT.boundary_shiftout
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__ensure_proper_nesting
#  define CCTK_PARAMETER__CARPETREGRID2__ensure_proper_nesting PRIVATE_CARPETREGRID2_STRUCT.ensure_proper_nesting
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__expect_symmetric_grids
#  define CCTK_PARAMETER__CARPETREGRID2__expect_symmetric_grids PRIVATE_CARPETREGRID2_STRUCT.expect_symmetric_grids
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__freeze_unaligned_levels
#  define CCTK_PARAMETER__CARPETREGRID2__freeze_unaligned_levels PRIVATE_CARPETREGRID2_STRUCT.freeze_unaligned_levels
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__freeze_unaligned_parent_levels
#  define CCTK_PARAMETER__CARPETREGRID2__freeze_unaligned_parent_levels PRIVATE_CARPETREGRID2_STRUCT.freeze_unaligned_parent_levels
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__min_distance
#  define CCTK_PARAMETER__CARPETREGRID2__min_distance PRIVATE_CARPETREGRID2_STRUCT.min_distance
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_centres
#  define CCTK_PARAMETER__CARPETREGRID2__num_centres PRIVATE_CARPETREGRID2_STRUCT.num_centres
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_1
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_1 PRIVATE_CARPETREGRID2_STRUCT.num_levels_1
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_10
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_10 PRIVATE_CARPETREGRID2_STRUCT.num_levels_10
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_2
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_2 PRIVATE_CARPETREGRID2_STRUCT.num_levels_2
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_3
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_3 PRIVATE_CARPETREGRID2_STRUCT.num_levels_3
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_4
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_4 PRIVATE_CARPETREGRID2_STRUCT.num_levels_4
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_5
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_5 PRIVATE_CARPETREGRID2_STRUCT.num_levels_5
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_6
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_6 PRIVATE_CARPETREGRID2_STRUCT.num_levels_6
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_7
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_7 PRIVATE_CARPETREGRID2_STRUCT.num_levels_7
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_8
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_8 PRIVATE_CARPETREGRID2_STRUCT.num_levels_8
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__num_levels_9
#  define CCTK_PARAMETER__CARPETREGRID2__num_levels_9 PRIVATE_CARPETREGRID2_STRUCT.num_levels_9
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__regrid_every
#  define CCTK_PARAMETER__CARPETREGRID2__regrid_every PRIVATE_CARPETREGRID2_STRUCT.regrid_every
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__snap_to_coarse
#  define CCTK_PARAMETER__CARPETREGRID2__snap_to_coarse PRIVATE_CARPETREGRID2_STRUCT.snap_to_coarse
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__symmetry_parity
#  define CCTK_PARAMETER__CARPETREGRID2__symmetry_parity PRIVATE_CARPETREGRID2_STRUCT.symmetry_parity
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__symmetry_periodic_x
#  define CCTK_PARAMETER__CARPETREGRID2__symmetry_periodic_x PRIVATE_CARPETREGRID2_STRUCT.symmetry_periodic_x
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__symmetry_periodic_y
#  define CCTK_PARAMETER__CARPETREGRID2__symmetry_periodic_y PRIVATE_CARPETREGRID2_STRUCT.symmetry_periodic_y
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__symmetry_periodic_z
#  define CCTK_PARAMETER__CARPETREGRID2__symmetry_periodic_z PRIVATE_CARPETREGRID2_STRUCT.symmetry_periodic_z
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__symmetry_rotating180
#  define CCTK_PARAMETER__CARPETREGRID2__symmetry_rotating180 PRIVATE_CARPETREGRID2_STRUCT.symmetry_rotating180
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__symmetry_rotating90
#  define CCTK_PARAMETER__CARPETREGRID2__symmetry_rotating90 PRIVATE_CARPETREGRID2_STRUCT.symmetry_rotating90
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__verbose
#  define CCTK_PARAMETER__CARPETREGRID2__verbose PRIVATE_CARPETREGRID2_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID2__veryverbose
#  define CCTK_PARAMETER__CARPETREGRID2__veryverbose PRIVATE_CARPETREGRID2_STRUCT.veryverbose
#endif

