#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_STRING,set_thread_bindings,)&&\
CCTK_DECLARE(CCTK_STRING,thread_layout,)&&\
COMMON /SystemTopologypriv/set_thread_bindings, thread_layout&&\

