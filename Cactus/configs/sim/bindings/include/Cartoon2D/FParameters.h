#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,new_mask_excised_name,)&&\
CCTK_DECLARE(CCTK_STRING,new_mask_field_name,)&&\
CCTK_DECLARE(CCTK_STRING,new_style_excision_var,)&&\
CCTK_DECLARE(CCTK_STRING,old_style_excision_var,)&&\
CCTK_DECLARE(CCTK_INT,allow_grid_resize,)&&\
CCTK_DECLARE(CCTK_INT,cartoon_active,)&&\
CCTK_DECLARE(CCTK_INT,eno_order,)&&\
CCTK_DECLARE(CCTK_INT,new_excision,)&&\
CCTK_DECLARE(CCTK_INT,old_excision,)&&\
CCTK_DECLARE(CCTK_INT,order,)&&\
CCTK_DECLARE(CCTK_INT,stencil,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /Cartoon2Dpriv/new_mask_excised_name, new_mask_field_name, new_style_excision_var, old_style_excision_var, allow_grid_resize, cartoon_active, eno_order, new_excision, old_excision, order, stencil, verbose&&\

