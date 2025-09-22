#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT viewport_refresh_seconds;
} PRIVATE_HTTPDEXTRA_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_HTTPDEXTRA_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, viewport_refresh_seconds, CCTK_PARAMETER__HTTPDEXTRA__viewport_refresh_seconds); \


#ifndef CCTK_PARAMETER__HTTPDEXTRA__viewport_refresh_seconds
#  define CCTK_PARAMETER__HTTPDEXTRA__viewport_refresh_seconds PRIVATE_HTTPDEXTRA_STRUCT.viewport_refresh_seconds
#endif

