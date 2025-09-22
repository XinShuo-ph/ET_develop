#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL l1xmax;
  CCTK_REAL l1xmin;
  CCTK_REAL l1ymax;
  CCTK_REAL l1ymin;
  CCTK_REAL l1zmax;
  CCTK_REAL l1zmin;
  CCTK_REAL l2xmax;
  CCTK_REAL l2xmin;
  CCTK_REAL l2ymax;
  CCTK_REAL l2ymin;
  CCTK_REAL l2zmax;
  CCTK_REAL l2zmin;
  CCTK_REAL l3xmax;
  CCTK_REAL l3xmin;
  CCTK_REAL l3ymax;
  CCTK_REAL l3ymin;
  CCTK_REAL l3zmax;
  CCTK_REAL l3zmin;
  CCTK_REAL maxerror;
  CCTK_REAL minfraction;
  CCTK_REAL moving_centre_x;
  CCTK_REAL moving_centre_y;
  CCTK_REAL moving_centre_z;
  CCTK_REAL moving_circle_frequency;
  CCTK_REAL moving_circle_radius;
  CCTK_REAL moving_region_radius;
  const char * activate_levels_on_regrid;
  const char * coordinates;
  const char * errorvar;
  const char * gridpoints;
  const char * moving_trajectory;
  const char * outerbounds;
  const char * refined_regions;
  CCTK_INT activate_next;
  CCTK_INT keep_same_grid_structure;
  CCTK_INT l1ixmax;
  CCTK_INT l1ixmin;
  CCTK_INT l1iymax;
  CCTK_INT l1iymin;
  CCTK_INT l1izmax;
  CCTK_INT l1izmin;
  CCTK_INT l2ixmax;
  CCTK_INT l2ixmin;
  CCTK_INT l2iymax;
  CCTK_INT l2iymin;
  CCTK_INT l2izmax;
  CCTK_INT l2izmin;
  CCTK_INT l3ixmax;
  CCTK_INT l3ixmin;
  CCTK_INT l3iymax;
  CCTK_INT l3iymin;
  CCTK_INT l3izmax;
  CCTK_INT l3izmin;
  CCTK_INT merge_overlapping_components;
  CCTK_INT minwidth;
  CCTK_INT num_new_levels;
  CCTK_INT refinement_levels;
  CCTK_INT regrid_every;
  CCTK_INT smart_outer_boundaries;
  CCTK_INT symmetry_x;
  CCTK_INT symmetry_y;
  CCTK_INT symmetry_z;
  CCTK_INT tracking;
  CCTK_INT verbose;
  CCTK_INT veryverbose;
} PRIVATE_CARPETREGRID_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETREGRID_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, l1xmax, CCTK_PARAMETER__CARPETREGRID__l1xmax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l1xmin, CCTK_PARAMETER__CARPETREGRID__l1xmin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l1ymax, CCTK_PARAMETER__CARPETREGRID__l1ymax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l1ymin, CCTK_PARAMETER__CARPETREGRID__l1ymin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l1zmax, CCTK_PARAMETER__CARPETREGRID__l1zmax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l1zmin, CCTK_PARAMETER__CARPETREGRID__l1zmin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l2xmax, CCTK_PARAMETER__CARPETREGRID__l2xmax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l2xmin, CCTK_PARAMETER__CARPETREGRID__l2xmin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l2ymax, CCTK_PARAMETER__CARPETREGRID__l2ymax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l2ymin, CCTK_PARAMETER__CARPETREGRID__l2ymin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l2zmax, CCTK_PARAMETER__CARPETREGRID__l2zmax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l2zmin, CCTK_PARAMETER__CARPETREGRID__l2zmin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l3xmax, CCTK_PARAMETER__CARPETREGRID__l3xmax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l3xmin, CCTK_PARAMETER__CARPETREGRID__l3xmin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l3ymax, CCTK_PARAMETER__CARPETREGRID__l3ymax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l3ymin, CCTK_PARAMETER__CARPETREGRID__l3ymin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l3zmax, CCTK_PARAMETER__CARPETREGRID__l3zmax); \
  CCTK_DECLARE_INIT (CCTK_REAL const, l3zmin, CCTK_PARAMETER__CARPETREGRID__l3zmin); \
  CCTK_DECLARE_INIT (CCTK_REAL const, maxerror, CCTK_PARAMETER__CARPETREGRID__maxerror); \
  CCTK_DECLARE_INIT (CCTK_REAL const, minfraction, CCTK_PARAMETER__CARPETREGRID__minfraction); \
  CCTK_DECLARE_INIT (CCTK_REAL const, moving_centre_x, CCTK_PARAMETER__CARPETREGRID__moving_centre_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, moving_centre_y, CCTK_PARAMETER__CARPETREGRID__moving_centre_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, moving_centre_z, CCTK_PARAMETER__CARPETREGRID__moving_centre_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, moving_circle_frequency, CCTK_PARAMETER__CARPETREGRID__moving_circle_frequency); \
  CCTK_DECLARE_INIT (CCTK_REAL const, moving_circle_radius, CCTK_PARAMETER__CARPETREGRID__moving_circle_radius); \
  CCTK_DECLARE_INIT (CCTK_REAL const, moving_region_radius, CCTK_PARAMETER__CARPETREGRID__moving_region_radius); \
  CCTK_DECLARE_INIT (const char * const, activate_levels_on_regrid, CCTK_PARAMETER__CARPETREGRID__activate_levels_on_regrid); \
  CCTK_DECLARE_INIT (const char * const, coordinates, CCTK_PARAMETER__CARPETREGRID__coordinates); \
  CCTK_DECLARE_INIT (const char * const, errorvar, CCTK_PARAMETER__CARPETREGRID__errorvar); \
  CCTK_DECLARE_INIT (const char * const, gridpoints, CCTK_PARAMETER__CARPETREGRID__gridpoints); \
  CCTK_DECLARE_INIT (const char * const, moving_trajectory, CCTK_PARAMETER__CARPETREGRID__moving_trajectory); \
  CCTK_DECLARE_INIT (const char * const, outerbounds, CCTK_PARAMETER__CARPETREGRID__outerbounds); \
  CCTK_DECLARE_INIT (const char * const, refined_regions, CCTK_PARAMETER__CARPETREGRID__refined_regions); \
  CCTK_DECLARE_INIT (CCTK_INT const, activate_next, CCTK_PARAMETER__CARPETREGRID__activate_next); \
  CCTK_DECLARE_INIT (CCTK_INT const, keep_same_grid_structure, CCTK_PARAMETER__CARPETREGRID__keep_same_grid_structure); \
  CCTK_DECLARE_INIT (CCTK_INT const, l1ixmax, CCTK_PARAMETER__CARPETREGRID__l1ixmax); \
  CCTK_DECLARE_INIT (CCTK_INT const, l1ixmin, CCTK_PARAMETER__CARPETREGRID__l1ixmin); \
  CCTK_DECLARE_INIT (CCTK_INT const, l1iymax, CCTK_PARAMETER__CARPETREGRID__l1iymax); \
  CCTK_DECLARE_INIT (CCTK_INT const, l1iymin, CCTK_PARAMETER__CARPETREGRID__l1iymin); \
  CCTK_DECLARE_INIT (CCTK_INT const, l1izmax, CCTK_PARAMETER__CARPETREGRID__l1izmax); \
  CCTK_DECLARE_INIT (CCTK_INT const, l1izmin, CCTK_PARAMETER__CARPETREGRID__l1izmin); \
  CCTK_DECLARE_INIT (CCTK_INT const, l2ixmax, CCTK_PARAMETER__CARPETREGRID__l2ixmax); \
  CCTK_DECLARE_INIT (CCTK_INT const, l2ixmin, CCTK_PARAMETER__CARPETREGRID__l2ixmin); \
  CCTK_DECLARE_INIT (CCTK_INT const, l2iymax, CCTK_PARAMETER__CARPETREGRID__l2iymax); \
  CCTK_DECLARE_INIT (CCTK_INT const, l2iymin, CCTK_PARAMETER__CARPETREGRID__l2iymin); \
  CCTK_DECLARE_INIT (CCTK_INT const, l2izmax, CCTK_PARAMETER__CARPETREGRID__l2izmax); \
  CCTK_DECLARE_INIT (CCTK_INT const, l2izmin, CCTK_PARAMETER__CARPETREGRID__l2izmin); \
  CCTK_DECLARE_INIT (CCTK_INT const, l3ixmax, CCTK_PARAMETER__CARPETREGRID__l3ixmax); \
  CCTK_DECLARE_INIT (CCTK_INT const, l3ixmin, CCTK_PARAMETER__CARPETREGRID__l3ixmin); \
  CCTK_DECLARE_INIT (CCTK_INT const, l3iymax, CCTK_PARAMETER__CARPETREGRID__l3iymax); \
  CCTK_DECLARE_INIT (CCTK_INT const, l3iymin, CCTK_PARAMETER__CARPETREGRID__l3iymin); \
  CCTK_DECLARE_INIT (CCTK_INT const, l3izmax, CCTK_PARAMETER__CARPETREGRID__l3izmax); \
  CCTK_DECLARE_INIT (CCTK_INT const, l3izmin, CCTK_PARAMETER__CARPETREGRID__l3izmin); \
  CCTK_DECLARE_INIT (CCTK_INT const, merge_overlapping_components, CCTK_PARAMETER__CARPETREGRID__merge_overlapping_components); \
  CCTK_DECLARE_INIT (CCTK_INT const, minwidth, CCTK_PARAMETER__CARPETREGRID__minwidth); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_new_levels, CCTK_PARAMETER__CARPETREGRID__num_new_levels); \
  CCTK_DECLARE_INIT (CCTK_INT const, refinement_levels, CCTK_PARAMETER__CARPETREGRID__refinement_levels); \
  CCTK_DECLARE_INIT (CCTK_INT const, regrid_every, CCTK_PARAMETER__CARPETREGRID__regrid_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, smart_outer_boundaries, CCTK_PARAMETER__CARPETREGRID__smart_outer_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, symmetry_x, CCTK_PARAMETER__CARPETREGRID__symmetry_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, symmetry_y, CCTK_PARAMETER__CARPETREGRID__symmetry_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, symmetry_z, CCTK_PARAMETER__CARPETREGRID__symmetry_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, tracking, CCTK_PARAMETER__CARPETREGRID__tracking); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARPETREGRID__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, veryverbose, CCTK_PARAMETER__CARPETREGRID__veryverbose); \


#ifndef CCTK_PARAMETER__CARPETREGRID__l1xmax
#  define CCTK_PARAMETER__CARPETREGRID__l1xmax PRIVATE_CARPETREGRID_STRUCT.l1xmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1xmin
#  define CCTK_PARAMETER__CARPETREGRID__l1xmin PRIVATE_CARPETREGRID_STRUCT.l1xmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1ymax
#  define CCTK_PARAMETER__CARPETREGRID__l1ymax PRIVATE_CARPETREGRID_STRUCT.l1ymax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1ymin
#  define CCTK_PARAMETER__CARPETREGRID__l1ymin PRIVATE_CARPETREGRID_STRUCT.l1ymin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1zmax
#  define CCTK_PARAMETER__CARPETREGRID__l1zmax PRIVATE_CARPETREGRID_STRUCT.l1zmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1zmin
#  define CCTK_PARAMETER__CARPETREGRID__l1zmin PRIVATE_CARPETREGRID_STRUCT.l1zmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2xmax
#  define CCTK_PARAMETER__CARPETREGRID__l2xmax PRIVATE_CARPETREGRID_STRUCT.l2xmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2xmin
#  define CCTK_PARAMETER__CARPETREGRID__l2xmin PRIVATE_CARPETREGRID_STRUCT.l2xmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2ymax
#  define CCTK_PARAMETER__CARPETREGRID__l2ymax PRIVATE_CARPETREGRID_STRUCT.l2ymax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2ymin
#  define CCTK_PARAMETER__CARPETREGRID__l2ymin PRIVATE_CARPETREGRID_STRUCT.l2ymin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2zmax
#  define CCTK_PARAMETER__CARPETREGRID__l2zmax PRIVATE_CARPETREGRID_STRUCT.l2zmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2zmin
#  define CCTK_PARAMETER__CARPETREGRID__l2zmin PRIVATE_CARPETREGRID_STRUCT.l2zmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3xmax
#  define CCTK_PARAMETER__CARPETREGRID__l3xmax PRIVATE_CARPETREGRID_STRUCT.l3xmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3xmin
#  define CCTK_PARAMETER__CARPETREGRID__l3xmin PRIVATE_CARPETREGRID_STRUCT.l3xmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3ymax
#  define CCTK_PARAMETER__CARPETREGRID__l3ymax PRIVATE_CARPETREGRID_STRUCT.l3ymax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3ymin
#  define CCTK_PARAMETER__CARPETREGRID__l3ymin PRIVATE_CARPETREGRID_STRUCT.l3ymin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3zmax
#  define CCTK_PARAMETER__CARPETREGRID__l3zmax PRIVATE_CARPETREGRID_STRUCT.l3zmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3zmin
#  define CCTK_PARAMETER__CARPETREGRID__l3zmin PRIVATE_CARPETREGRID_STRUCT.l3zmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__maxerror
#  define CCTK_PARAMETER__CARPETREGRID__maxerror PRIVATE_CARPETREGRID_STRUCT.maxerror
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__minfraction
#  define CCTK_PARAMETER__CARPETREGRID__minfraction PRIVATE_CARPETREGRID_STRUCT.minfraction
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__moving_centre_x
#  define CCTK_PARAMETER__CARPETREGRID__moving_centre_x PRIVATE_CARPETREGRID_STRUCT.moving_centre_x
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__moving_centre_y
#  define CCTK_PARAMETER__CARPETREGRID__moving_centre_y PRIVATE_CARPETREGRID_STRUCT.moving_centre_y
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__moving_centre_z
#  define CCTK_PARAMETER__CARPETREGRID__moving_centre_z PRIVATE_CARPETREGRID_STRUCT.moving_centre_z
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__moving_circle_frequency
#  define CCTK_PARAMETER__CARPETREGRID__moving_circle_frequency PRIVATE_CARPETREGRID_STRUCT.moving_circle_frequency
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__moving_circle_radius
#  define CCTK_PARAMETER__CARPETREGRID__moving_circle_radius PRIVATE_CARPETREGRID_STRUCT.moving_circle_radius
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__moving_region_radius
#  define CCTK_PARAMETER__CARPETREGRID__moving_region_radius PRIVATE_CARPETREGRID_STRUCT.moving_region_radius
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__activate_levels_on_regrid
#  define CCTK_PARAMETER__CARPETREGRID__activate_levels_on_regrid PRIVATE_CARPETREGRID_STRUCT.activate_levels_on_regrid
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__coordinates
#  define CCTK_PARAMETER__CARPETREGRID__coordinates PRIVATE_CARPETREGRID_STRUCT.coordinates
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__errorvar
#  define CCTK_PARAMETER__CARPETREGRID__errorvar PRIVATE_CARPETREGRID_STRUCT.errorvar
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__gridpoints
#  define CCTK_PARAMETER__CARPETREGRID__gridpoints PRIVATE_CARPETREGRID_STRUCT.gridpoints
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__moving_trajectory
#  define CCTK_PARAMETER__CARPETREGRID__moving_trajectory PRIVATE_CARPETREGRID_STRUCT.moving_trajectory
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__outerbounds
#  define CCTK_PARAMETER__CARPETREGRID__outerbounds PRIVATE_CARPETREGRID_STRUCT.outerbounds
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__refined_regions
#  define CCTK_PARAMETER__CARPETREGRID__refined_regions PRIVATE_CARPETREGRID_STRUCT.refined_regions
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__activate_next
#  define CCTK_PARAMETER__CARPETREGRID__activate_next PRIVATE_CARPETREGRID_STRUCT.activate_next
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__keep_same_grid_structure
#  define CCTK_PARAMETER__CARPETREGRID__keep_same_grid_structure PRIVATE_CARPETREGRID_STRUCT.keep_same_grid_structure
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1ixmax
#  define CCTK_PARAMETER__CARPETREGRID__l1ixmax PRIVATE_CARPETREGRID_STRUCT.l1ixmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1ixmin
#  define CCTK_PARAMETER__CARPETREGRID__l1ixmin PRIVATE_CARPETREGRID_STRUCT.l1ixmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1iymax
#  define CCTK_PARAMETER__CARPETREGRID__l1iymax PRIVATE_CARPETREGRID_STRUCT.l1iymax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1iymin
#  define CCTK_PARAMETER__CARPETREGRID__l1iymin PRIVATE_CARPETREGRID_STRUCT.l1iymin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1izmax
#  define CCTK_PARAMETER__CARPETREGRID__l1izmax PRIVATE_CARPETREGRID_STRUCT.l1izmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l1izmin
#  define CCTK_PARAMETER__CARPETREGRID__l1izmin PRIVATE_CARPETREGRID_STRUCT.l1izmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2ixmax
#  define CCTK_PARAMETER__CARPETREGRID__l2ixmax PRIVATE_CARPETREGRID_STRUCT.l2ixmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2ixmin
#  define CCTK_PARAMETER__CARPETREGRID__l2ixmin PRIVATE_CARPETREGRID_STRUCT.l2ixmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2iymax
#  define CCTK_PARAMETER__CARPETREGRID__l2iymax PRIVATE_CARPETREGRID_STRUCT.l2iymax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2iymin
#  define CCTK_PARAMETER__CARPETREGRID__l2iymin PRIVATE_CARPETREGRID_STRUCT.l2iymin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2izmax
#  define CCTK_PARAMETER__CARPETREGRID__l2izmax PRIVATE_CARPETREGRID_STRUCT.l2izmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l2izmin
#  define CCTK_PARAMETER__CARPETREGRID__l2izmin PRIVATE_CARPETREGRID_STRUCT.l2izmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3ixmax
#  define CCTK_PARAMETER__CARPETREGRID__l3ixmax PRIVATE_CARPETREGRID_STRUCT.l3ixmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3ixmin
#  define CCTK_PARAMETER__CARPETREGRID__l3ixmin PRIVATE_CARPETREGRID_STRUCT.l3ixmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3iymax
#  define CCTK_PARAMETER__CARPETREGRID__l3iymax PRIVATE_CARPETREGRID_STRUCT.l3iymax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3iymin
#  define CCTK_PARAMETER__CARPETREGRID__l3iymin PRIVATE_CARPETREGRID_STRUCT.l3iymin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3izmax
#  define CCTK_PARAMETER__CARPETREGRID__l3izmax PRIVATE_CARPETREGRID_STRUCT.l3izmax
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__l3izmin
#  define CCTK_PARAMETER__CARPETREGRID__l3izmin PRIVATE_CARPETREGRID_STRUCT.l3izmin
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__merge_overlapping_components
#  define CCTK_PARAMETER__CARPETREGRID__merge_overlapping_components PRIVATE_CARPETREGRID_STRUCT.merge_overlapping_components
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__minwidth
#  define CCTK_PARAMETER__CARPETREGRID__minwidth PRIVATE_CARPETREGRID_STRUCT.minwidth
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__num_new_levels
#  define CCTK_PARAMETER__CARPETREGRID__num_new_levels PRIVATE_CARPETREGRID_STRUCT.num_new_levels
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__refinement_levels
#  define CCTK_PARAMETER__CARPETREGRID__refinement_levels PRIVATE_CARPETREGRID_STRUCT.refinement_levels
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__regrid_every
#  define CCTK_PARAMETER__CARPETREGRID__regrid_every PRIVATE_CARPETREGRID_STRUCT.regrid_every
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__smart_outer_boundaries
#  define CCTK_PARAMETER__CARPETREGRID__smart_outer_boundaries PRIVATE_CARPETREGRID_STRUCT.smart_outer_boundaries
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__symmetry_x
#  define CCTK_PARAMETER__CARPETREGRID__symmetry_x PRIVATE_CARPETREGRID_STRUCT.symmetry_x
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__symmetry_y
#  define CCTK_PARAMETER__CARPETREGRID__symmetry_y PRIVATE_CARPETREGRID_STRUCT.symmetry_y
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__symmetry_z
#  define CCTK_PARAMETER__CARPETREGRID__symmetry_z PRIVATE_CARPETREGRID_STRUCT.symmetry_z
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__tracking
#  define CCTK_PARAMETER__CARPETREGRID__tracking PRIVATE_CARPETREGRID_STRUCT.tracking
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__verbose
#  define CCTK_PARAMETER__CARPETREGRID__verbose PRIVATE_CARPETREGRID_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__veryverbose
#  define CCTK_PARAMETER__CARPETREGRID__veryverbose PRIVATE_CARPETREGRID_STRUCT.veryverbose
#endif

