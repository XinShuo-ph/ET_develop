#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL offsetx[10];
  CCTK_REAL offsety[10];
  CCTK_REAL offsetz[10];
  CCTK_INT num_offsets;
  CCTK_INT offset_firstlevel;
} RESTRICTED_CARPETREGRID_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_CARPETREGRID_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, offsetx, CCTK_PARAMETER__CARPETREGRID__offsetx); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, offsety, CCTK_PARAMETER__CARPETREGRID__offsety); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, offsetz, CCTK_PARAMETER__CARPETREGRID__offsetz); \
  CCTK_DECLARE_INIT (CCTK_INT const, num_offsets, CCTK_PARAMETER__CARPETREGRID__num_offsets); \
  CCTK_DECLARE_INIT (CCTK_INT const, offset_firstlevel, CCTK_PARAMETER__CARPETREGRID__offset_firstlevel); \


#ifndef CCTK_PARAMETER__CARPETREGRID__offsetx
#  define CCTK_PARAMETER__CARPETREGRID__offsetx RESTRICTED_CARPETREGRID_STRUCT.offsetx
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__offsety
#  define CCTK_PARAMETER__CARPETREGRID__offsety RESTRICTED_CARPETREGRID_STRUCT.offsety
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__offsetz
#  define CCTK_PARAMETER__CARPETREGRID__offsetz RESTRICTED_CARPETREGRID_STRUCT.offsetz
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__num_offsets
#  define CCTK_PARAMETER__CARPETREGRID__num_offsets RESTRICTED_CARPETREGRID_STRUCT.num_offsets
#endif
#ifndef CCTK_PARAMETER__CARPETREGRID__offset_firstlevel
#  define CCTK_PARAMETER__CARPETREGRID__offset_firstlevel RESTRICTED_CARPETREGRID_STRUCT.offset_firstlevel
#endif

