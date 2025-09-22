#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * bitant_plane;
  const char * domain;
} RESTRICTED_TESTGRID_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_TESTGRID_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, bitant_plane, CCTK_PARAMETER__TESTGRID__bitant_plane); \
  CCTK_DECLARE_INIT (const char * const, domain, CCTK_PARAMETER__TESTGRID__domain); \


#ifndef CCTK_PARAMETER__TESTGRID__bitant_plane
#  define CCTK_PARAMETER__TESTGRID__bitant_plane RESTRICTED_TESTGRID_STRUCT.bitant_plane
#endif
#ifndef CCTK_PARAMETER__TESTGRID__domain
#  define CCTK_PARAMETER__TESTGRID__domain RESTRICTED_TESTGRID_STRUCT.domain
#endif

