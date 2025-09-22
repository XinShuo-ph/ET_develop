#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT ahf_active;
  CCTK_INT ahf_persists;
} RESTRICTED_AHFINDER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_AHFINDER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_active, CCTK_PARAMETER__AHFINDER__ahf_active); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_persists, CCTK_PARAMETER__AHFINDER__ahf_persists); \


#ifndef CCTK_PARAMETER__AHFINDER__ahf_active
#  define CCTK_PARAMETER__AHFINDER__ahf_active RESTRICTED_AHFINDER_STRUCT.ahf_active
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_persists
#  define CCTK_PARAMETER__AHFINDER__ahf_persists RESTRICTED_AHFINDER_STRUCT.ahf_persists
#endif

