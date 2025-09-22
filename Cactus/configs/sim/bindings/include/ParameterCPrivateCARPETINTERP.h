#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL ipoison;
  CCTK_REAL poison;
  CCTK_INT barriers;
  CCTK_INT check_tree_search;
  CCTK_INT tree_search;
} PRIVATE_CARPETINTERP_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARPETINTERP_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, ipoison, CCTK_PARAMETER__CARPETINTERP__ipoison); \
  CCTK_DECLARE_INIT (CCTK_REAL const, poison, CCTK_PARAMETER__CARPETINTERP__poison); \
  CCTK_DECLARE_INIT (CCTK_INT const, barriers, CCTK_PARAMETER__CARPETINTERP__barriers); \
  CCTK_DECLARE_INIT (CCTK_INT const, check_tree_search, CCTK_PARAMETER__CARPETINTERP__check_tree_search); \
  CCTK_DECLARE_INIT (CCTK_INT const, tree_search, CCTK_PARAMETER__CARPETINTERP__tree_search); \


#ifndef CCTK_PARAMETER__CARPETINTERP__ipoison
#  define CCTK_PARAMETER__CARPETINTERP__ipoison PRIVATE_CARPETINTERP_STRUCT.ipoison
#endif
#ifndef CCTK_PARAMETER__CARPETINTERP__poison
#  define CCTK_PARAMETER__CARPETINTERP__poison PRIVATE_CARPETINTERP_STRUCT.poison
#endif
#ifndef CCTK_PARAMETER__CARPETINTERP__barriers
#  define CCTK_PARAMETER__CARPETINTERP__barriers PRIVATE_CARPETINTERP_STRUCT.barriers
#endif
#ifndef CCTK_PARAMETER__CARPETINTERP__check_tree_search
#  define CCTK_PARAMETER__CARPETINTERP__check_tree_search PRIVATE_CARPETINTERP_STRUCT.check_tree_search
#endif
#ifndef CCTK_PARAMETER__CARPETINTERP__tree_search
#  define CCTK_PARAMETER__CARPETINTERP__tree_search PRIVATE_CARPETINTERP_STRUCT.tree_search
#endif

