#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * surface_name[10];
  CCTK_INT surface[10];
  CCTK_INT verbose;
} PRIVATE_CARPETTRACKER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETTRACKER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const * const, surface_name, CCTK_PARAMETER__CARPETTRACKER__surface_name); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, surface, CCTK_PARAMETER__CARPETTRACKER__surface); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARPETTRACKER__verbose); \


#ifndef CCTK_PARAMETER__CARPETTRACKER__surface_name
#  define CCTK_PARAMETER__CARPETTRACKER__surface_name PRIVATE_CARPETTRACKER_STRUCT.surface_name
#endif
#ifndef CCTK_PARAMETER__CARPETTRACKER__surface
#  define CCTK_PARAMETER__CARPETTRACKER__surface PRIVATE_CARPETTRACKER_STRUCT.surface
#endif
#ifndef CCTK_PARAMETER__CARPETTRACKER__verbose
#  define CCTK_PARAMETER__CARPETTRACKER__verbose PRIVATE_CARPETTRACKER_STRUCT.verbose
#endif

