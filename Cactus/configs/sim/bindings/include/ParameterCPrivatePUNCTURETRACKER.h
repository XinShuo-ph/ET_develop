#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL initial_x[10];
  CCTK_REAL initial_y[10];
  CCTK_REAL initial_z[10];
  CCTK_REAL modify_distance;
  CCTK_REAL shift_limit;
  CCTK_INT modify_puncture[2];
  CCTK_INT new_reflevel_number[2];
  CCTK_INT track[10];
  CCTK_INT verbose;
  CCTK_INT which_surface_to_store_info[10];
} PRIVATE_PUNCTURETRACKER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_PUNCTURETRACKER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_x, CCTK_PARAMETER__PUNCTURETRACKER__initial_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_y, CCTK_PARAMETER__PUNCTURETRACKER__initial_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, initial_z, CCTK_PARAMETER__PUNCTURETRACKER__initial_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, modify_distance, CCTK_PARAMETER__PUNCTURETRACKER__modify_distance); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shift_limit, CCTK_PARAMETER__PUNCTURETRACKER__shift_limit); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, modify_puncture, CCTK_PARAMETER__PUNCTURETRACKER__modify_puncture); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, new_reflevel_number, CCTK_PARAMETER__PUNCTURETRACKER__new_reflevel_number); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, track, CCTK_PARAMETER__PUNCTURETRACKER__track); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__PUNCTURETRACKER__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, which_surface_to_store_info, CCTK_PARAMETER__PUNCTURETRACKER__which_surface_to_store_info); \


#ifndef CCTK_PARAMETER__PUNCTURETRACKER__initial_x
#  define CCTK_PARAMETER__PUNCTURETRACKER__initial_x PRIVATE_PUNCTURETRACKER_STRUCT.initial_x
#endif
#ifndef CCTK_PARAMETER__PUNCTURETRACKER__initial_y
#  define CCTK_PARAMETER__PUNCTURETRACKER__initial_y PRIVATE_PUNCTURETRACKER_STRUCT.initial_y
#endif
#ifndef CCTK_PARAMETER__PUNCTURETRACKER__initial_z
#  define CCTK_PARAMETER__PUNCTURETRACKER__initial_z PRIVATE_PUNCTURETRACKER_STRUCT.initial_z
#endif
#ifndef CCTK_PARAMETER__PUNCTURETRACKER__modify_distance
#  define CCTK_PARAMETER__PUNCTURETRACKER__modify_distance PRIVATE_PUNCTURETRACKER_STRUCT.modify_distance
#endif
#ifndef CCTK_PARAMETER__PUNCTURETRACKER__shift_limit
#  define CCTK_PARAMETER__PUNCTURETRACKER__shift_limit PRIVATE_PUNCTURETRACKER_STRUCT.shift_limit
#endif
#ifndef CCTK_PARAMETER__PUNCTURETRACKER__modify_puncture
#  define CCTK_PARAMETER__PUNCTURETRACKER__modify_puncture PRIVATE_PUNCTURETRACKER_STRUCT.modify_puncture
#endif
#ifndef CCTK_PARAMETER__PUNCTURETRACKER__new_reflevel_number
#  define CCTK_PARAMETER__PUNCTURETRACKER__new_reflevel_number PRIVATE_PUNCTURETRACKER_STRUCT.new_reflevel_number
#endif
#ifndef CCTK_PARAMETER__PUNCTURETRACKER__track
#  define CCTK_PARAMETER__PUNCTURETRACKER__track PRIVATE_PUNCTURETRACKER_STRUCT.track
#endif
#ifndef CCTK_PARAMETER__PUNCTURETRACKER__verbose
#  define CCTK_PARAMETER__PUNCTURETRACKER__verbose PRIVATE_PUNCTURETRACKER_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__PUNCTURETRACKER__which_surface_to_store_info
#  define CCTK_PARAMETER__PUNCTURETRACKER__which_surface_to_store_info PRIVATE_PUNCTURETRACKER_STRUCT.which_surface_to_store_info
#endif

