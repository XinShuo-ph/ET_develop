#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT interp_barrier;
  CCTK_INT verbose;
  CCTK_INT veryverbose;
} PRIVATE_CARPETINTERP2_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETINTERP2_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, interp_barrier, CCTK_PARAMETER__CARPETINTERP2__interp_barrier); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARPETINTERP2__verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, veryverbose, CCTK_PARAMETER__CARPETINTERP2__veryverbose); \


#ifndef CCTK_PARAMETER__CARPETINTERP2__interp_barrier
#  define CCTK_PARAMETER__CARPETINTERP2__interp_barrier PRIVATE_CARPETINTERP2_STRUCT.interp_barrier
#endif
#ifndef CCTK_PARAMETER__CARPETINTERP2__verbose
#  define CCTK_PARAMETER__CARPETINTERP2__verbose PRIVATE_CARPETINTERP2_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__CARPETINTERP2__veryverbose
#  define CCTK_PARAMETER__CARPETINTERP2__veryverbose PRIVATE_CARPETINTERP2_STRUCT.veryverbose
#endif

