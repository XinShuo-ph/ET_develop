#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  const char * set_thread_bindings;
  const char * thread_layout;
} PRIVATE_SYSTEMTOPOLOGY_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_SYSTEMTOPOLOGY_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (const char * const, set_thread_bindings, CCTK_PARAMETER__SYSTEMTOPOLOGY__set_thread_bindings); \
  CCTK_DECLARE_INIT (const char * const, thread_layout, CCTK_PARAMETER__SYSTEMTOPOLOGY__thread_layout); \


#ifndef CCTK_PARAMETER__SYSTEMTOPOLOGY__set_thread_bindings
#  define CCTK_PARAMETER__SYSTEMTOPOLOGY__set_thread_bindings PRIVATE_SYSTEMTOPOLOGY_STRUCT.set_thread_bindings
#endif
#ifndef CCTK_PARAMETER__SYSTEMTOPOLOGY__thread_layout
#  define CCTK_PARAMETER__SYSTEMTOPOLOGY__thread_layout PRIVATE_SYSTEMTOPOLOGY_STRUCT.thread_layout
#endif

