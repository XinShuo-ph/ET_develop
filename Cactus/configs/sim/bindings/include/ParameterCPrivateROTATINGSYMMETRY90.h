#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT check_boundaries;
  CCTK_INT poison_boundaries;
  CCTK_INT poison_value;
  CCTK_INT verbose;
} PRIVATE_ROTATINGSYMMETRY90_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_ROTATINGSYMMETRY90_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, check_boundaries, CCTK_PARAMETER__ROTATINGSYMMETRY90__check_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_boundaries, CCTK_PARAMETER__ROTATINGSYMMETRY90__poison_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_value, CCTK_PARAMETER__ROTATINGSYMMETRY90__poison_value); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__ROTATINGSYMMETRY90__verbose); \


#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY90__check_boundaries
#  define CCTK_PARAMETER__ROTATINGSYMMETRY90__check_boundaries PRIVATE_ROTATINGSYMMETRY90_STRUCT.check_boundaries
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY90__poison_boundaries
#  define CCTK_PARAMETER__ROTATINGSYMMETRY90__poison_boundaries PRIVATE_ROTATINGSYMMETRY90_STRUCT.poison_boundaries
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY90__poison_value
#  define CCTK_PARAMETER__ROTATINGSYMMETRY90__poison_value PRIVATE_ROTATINGSYMMETRY90_STRUCT.poison_value
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY90__verbose
#  define CCTK_PARAMETER__ROTATINGSYMMETRY90__verbose PRIVATE_ROTATINGSYMMETRY90_STRUCT.verbose
#endif

