#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL symmetry_boundary_x;
  CCTK_REAL symmetry_boundary_y;
  const char * hyperslabber;
  CCTK_INT check_boundaries;
  CCTK_INT poison_boundaries;
  CCTK_INT poison_value;
  CCTK_INT use_coordbase;
  CCTK_INT verbose;
} PRIVATE_ROTATINGSYMMETRY180_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_ROTATINGSYMMETRY180_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, symmetry_boundary_x, CCTK_PARAMETER__ROTATINGSYMMETRY180__symmetry_boundary_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, symmetry_boundary_y, CCTK_PARAMETER__ROTATINGSYMMETRY180__symmetry_boundary_y); \
  CCTK_DECLARE_INIT (const char * const, hyperslabber, CCTK_PARAMETER__ROTATINGSYMMETRY180__hyperslabber); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_boundaries, CCTK_PARAMETER__ROTATINGSYMMETRY180__check_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_boundaries, CCTK_PARAMETER__ROTATINGSYMMETRY180__poison_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_value, CCTK_PARAMETER__ROTATINGSYMMETRY180__poison_value); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_coordbase, CCTK_PARAMETER__ROTATINGSYMMETRY180__use_coordbase); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__ROTATINGSYMMETRY180__verbose); \


#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY180__symmetry_boundary_x
#  define CCTK_PARAMETER__ROTATINGSYMMETRY180__symmetry_boundary_x PRIVATE_ROTATINGSYMMETRY180_STRUCT.symmetry_boundary_x
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY180__symmetry_boundary_y
#  define CCTK_PARAMETER__ROTATINGSYMMETRY180__symmetry_boundary_y PRIVATE_ROTATINGSYMMETRY180_STRUCT.symmetry_boundary_y
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY180__hyperslabber
#  define CCTK_PARAMETER__ROTATINGSYMMETRY180__hyperslabber PRIVATE_ROTATINGSYMMETRY180_STRUCT.hyperslabber
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY180__check_boundaries
#  define CCTK_PARAMETER__ROTATINGSYMMETRY180__check_boundaries PRIVATE_ROTATINGSYMMETRY180_STRUCT.check_boundaries
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY180__poison_boundaries
#  define CCTK_PARAMETER__ROTATINGSYMMETRY180__poison_boundaries PRIVATE_ROTATINGSYMMETRY180_STRUCT.poison_boundaries
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY180__poison_value
#  define CCTK_PARAMETER__ROTATINGSYMMETRY180__poison_value PRIVATE_ROTATINGSYMMETRY180_STRUCT.poison_value
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY180__use_coordbase
#  define CCTK_PARAMETER__ROTATINGSYMMETRY180__use_coordbase PRIVATE_ROTATINGSYMMETRY180_STRUCT.use_coordbase
#endif
#ifndef CCTK_PARAMETER__ROTATINGSYMMETRY180__verbose
#  define CCTK_PARAMETER__ROTATINGSYMMETRY180__verbose PRIVATE_ROTATINGSYMMETRY180_STRUCT.verbose
#endif

