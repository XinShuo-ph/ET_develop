#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * new_mask_excised_name;
  const char * new_mask_field_name;
  const char * new_style_excision_var;
  const char * old_style_excision_var;
  CCTK_INT allow_grid_resize;
  CCTK_INT cartoon_active;
  CCTK_INT eno_order;
  CCTK_INT new_excision;
  CCTK_INT old_excision;
  CCTK_INT order;
  CCTK_INT stencil;
  CCTK_INT verbose;
} PRIVATE_CARTOON2D_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CARTOON2D_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, new_mask_excised_name, CCTK_PARAMETER__CARTOON2D__new_mask_excised_name); \
  CCTK_DECLARE_INIT (const char * const, new_mask_field_name, CCTK_PARAMETER__CARTOON2D__new_mask_field_name); \
  CCTK_DECLARE_INIT (const char * const, new_style_excision_var, CCTK_PARAMETER__CARTOON2D__new_style_excision_var); \
  CCTK_DECLARE_INIT (const char * const, old_style_excision_var, CCTK_PARAMETER__CARTOON2D__old_style_excision_var); \
  CCTK_DECLARE_INIT (CCTK_INT const, allow_grid_resize, CCTK_PARAMETER__CARTOON2D__allow_grid_resize); \
  CCTK_DECLARE_INIT (CCTK_INT const, cartoon_active, CCTK_PARAMETER__CARTOON2D__cartoon_active); \
  CCTK_DECLARE_INIT (CCTK_INT const, eno_order, CCTK_PARAMETER__CARTOON2D__eno_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, new_excision, CCTK_PARAMETER__CARTOON2D__new_excision); \
  CCTK_DECLARE_INIT (CCTK_INT const, old_excision, CCTK_PARAMETER__CARTOON2D__old_excision); \
  CCTK_DECLARE_INIT (CCTK_INT const, order, CCTK_PARAMETER__CARTOON2D__order); \
  CCTK_DECLARE_INIT (CCTK_INT const, stencil, CCTK_PARAMETER__CARTOON2D__stencil); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__CARTOON2D__verbose); \


#ifndef CCTK_PARAMETER__CARTOON2D__new_mask_excised_name
#  define CCTK_PARAMETER__CARTOON2D__new_mask_excised_name PRIVATE_CARTOON2D_STRUCT.new_mask_excised_name
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__new_mask_field_name
#  define CCTK_PARAMETER__CARTOON2D__new_mask_field_name PRIVATE_CARTOON2D_STRUCT.new_mask_field_name
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__new_style_excision_var
#  define CCTK_PARAMETER__CARTOON2D__new_style_excision_var PRIVATE_CARTOON2D_STRUCT.new_style_excision_var
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__old_style_excision_var
#  define CCTK_PARAMETER__CARTOON2D__old_style_excision_var PRIVATE_CARTOON2D_STRUCT.old_style_excision_var
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__allow_grid_resize
#  define CCTK_PARAMETER__CARTOON2D__allow_grid_resize PRIVATE_CARTOON2D_STRUCT.allow_grid_resize
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__cartoon_active
#  define CCTK_PARAMETER__CARTOON2D__cartoon_active PRIVATE_CARTOON2D_STRUCT.cartoon_active
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__eno_order
#  define CCTK_PARAMETER__CARTOON2D__eno_order PRIVATE_CARTOON2D_STRUCT.eno_order
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__new_excision
#  define CCTK_PARAMETER__CARTOON2D__new_excision PRIVATE_CARTOON2D_STRUCT.new_excision
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__old_excision
#  define CCTK_PARAMETER__CARTOON2D__old_excision PRIVATE_CARTOON2D_STRUCT.old_excision
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__order
#  define CCTK_PARAMETER__CARTOON2D__order PRIVATE_CARTOON2D_STRUCT.order
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__stencil
#  define CCTK_PARAMETER__CARTOON2D__stencil PRIVATE_CARTOON2D_STRUCT.stencil
#endif
#ifndef CCTK_PARAMETER__CARTOON2D__verbose
#  define CCTK_PARAMETER__CARTOON2D__verbose PRIVATE_CARTOON2D_STRUCT.verbose
#endif

