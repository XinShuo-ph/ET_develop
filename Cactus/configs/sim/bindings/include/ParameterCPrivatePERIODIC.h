#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT check_boundaries;
  CCTK_INT periodic;
  CCTK_INT periodic_x;
  CCTK_INT periodic_y;
  CCTK_INT periodic_z;
  CCTK_INT poison_boundaries;
  CCTK_INT poison_value;
  CCTK_INT verbose;
} PRIVATE_PERIODIC_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_PERIODIC_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, check_boundaries, CCTK_PARAMETER__PERIODIC__check_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, periodic, CCTK_PARAMETER__PERIODIC__periodic); \
  CCTK_DECLARE_INIT (CCTK_INT const, periodic_x, CCTK_PARAMETER__PERIODIC__periodic_x); \
  CCTK_DECLARE_INIT (CCTK_INT const, periodic_y, CCTK_PARAMETER__PERIODIC__periodic_y); \
  CCTK_DECLARE_INIT (CCTK_INT const, periodic_z, CCTK_PARAMETER__PERIODIC__periodic_z); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_boundaries, CCTK_PARAMETER__PERIODIC__poison_boundaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, poison_value, CCTK_PARAMETER__PERIODIC__poison_value); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__PERIODIC__verbose); \


#ifndef CCTK_PARAMETER__PERIODIC__check_boundaries
#  define CCTK_PARAMETER__PERIODIC__check_boundaries PRIVATE_PERIODIC_STRUCT.check_boundaries
#endif
#ifndef CCTK_PARAMETER__PERIODIC__periodic
#  define CCTK_PARAMETER__PERIODIC__periodic PRIVATE_PERIODIC_STRUCT.periodic
#endif
#ifndef CCTK_PARAMETER__PERIODIC__periodic_x
#  define CCTK_PARAMETER__PERIODIC__periodic_x PRIVATE_PERIODIC_STRUCT.periodic_x
#endif
#ifndef CCTK_PARAMETER__PERIODIC__periodic_y
#  define CCTK_PARAMETER__PERIODIC__periodic_y PRIVATE_PERIODIC_STRUCT.periodic_y
#endif
#ifndef CCTK_PARAMETER__PERIODIC__periodic_z
#  define CCTK_PARAMETER__PERIODIC__periodic_z PRIVATE_PERIODIC_STRUCT.periodic_z
#endif
#ifndef CCTK_PARAMETER__PERIODIC__poison_boundaries
#  define CCTK_PARAMETER__PERIODIC__poison_boundaries PRIVATE_PERIODIC_STRUCT.poison_boundaries
#endif
#ifndef CCTK_PARAMETER__PERIODIC__poison_value
#  define CCTK_PARAMETER__PERIODIC__poison_value PRIVATE_PERIODIC_STRUCT.poison_value
#endif
#ifndef CCTK_PARAMETER__PERIODIC__verbose
#  define CCTK_PARAMETER__PERIODIC__verbose PRIVATE_PERIODIC_STRUCT.verbose
#endif

