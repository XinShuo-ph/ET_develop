#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL damp_lorenz;
} PRIVATE_ILLINOISGRMHD_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_ILLINOISGRMHD_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, damp_lorenz, CCTK_PARAMETER__ILLINOISGRMHD__damp_lorenz); \


#ifndef CCTK_PARAMETER__ILLINOISGRMHD__damp_lorenz
#  define CCTK_PARAMETER__ILLINOISGRMHD__damp_lorenz PRIVATE_ILLINOISGRMHD_STRUCT.damp_lorenz
#endif

