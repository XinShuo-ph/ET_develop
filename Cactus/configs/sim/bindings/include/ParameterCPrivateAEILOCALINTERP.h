#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT log_interp_coords;
} PRIVATE_AEILOCALINTERP_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_AEILOCALINTERP_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, log_interp_coords, CCTK_PARAMETER__AEILOCALINTERP__log_interp_coords); \


#ifndef CCTK_PARAMETER__AEILOCALINTERP__log_interp_coords
#  define CCTK_PARAMETER__AEILOCALINTERP__log_interp_coords PRIVATE_AEILOCALINTERP_STRUCT.log_interp_coords
#endif

