#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL until_time;
  const char * encryption_scheme;
  const char * password;
  const char * until_expression;
  const char * user;
  CCTK_INT hunt;
  CCTK_INT pause;
  CCTK_INT port;
  CCTK_INT provide_pages;
  CCTK_INT queue_length;
  CCTK_INT refresh_seconds;
  CCTK_INT single_step;
  CCTK_INT steering_frequency;
  CCTK_INT terminate;
  CCTK_INT timeout_seconds;
  CCTK_INT timeout_useconds;
  CCTK_INT until_expression_active;
  CCTK_INT until_it;
  CCTK_INT until_it_active;
  CCTK_INT until_time_active;
  CCTK_INT use_pthreads;
  CCTK_INT verbose;
} PRIVATE_HTTPD_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_HTTPD_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, until_time, CCTK_PARAMETER__HTTPD__until_time); \
  CCTK_DECLARE_INIT (const char * const, encryption_scheme, CCTK_PARAMETER__HTTPD__encryption_scheme); \
  CCTK_DECLARE_INIT (const char * const, password, CCTK_PARAMETER__HTTPD__password); \
  CCTK_DECLARE_INIT (const char * const, until_expression, CCTK_PARAMETER__HTTPD__until_expression); \
  CCTK_DECLARE_INIT (const char * const, user, CCTK_PARAMETER__HTTPD__user); \
  CCTK_DECLARE_INIT (CCTK_INT const, hunt, CCTK_PARAMETER__HTTPD__hunt); \
  CCTK_DECLARE_INIT (CCTK_INT const, pause, CCTK_PARAMETER__HTTPD__pause); \
  CCTK_DECLARE_INIT (CCTK_INT const, port, CCTK_PARAMETER__HTTPD__port); \
  CCTK_DECLARE_INIT (CCTK_INT const, provide_pages, CCTK_PARAMETER__HTTPD__provide_pages); \
  CCTK_DECLARE_INIT (CCTK_INT const, queue_length, CCTK_PARAMETER__HTTPD__queue_length); \
  CCTK_DECLARE_INIT (CCTK_INT const, refresh_seconds, CCTK_PARAMETER__HTTPD__refresh_seconds); \
  CCTK_DECLARE_INIT (CCTK_INT const, single_step, CCTK_PARAMETER__HTTPD__single_step); \
  CCTK_DECLARE_INIT (CCTK_INT const, steering_frequency, CCTK_PARAMETER__HTTPD__steering_frequency); \
  CCTK_DECLARE_INIT (CCTK_INT const, terminate, CCTK_PARAMETER__HTTPD__terminate); \
  CCTK_DECLARE_INIT (CCTK_INT const, timeout_seconds, CCTK_PARAMETER__HTTPD__timeout_seconds); \
  CCTK_DECLARE_INIT (CCTK_INT const, timeout_useconds, CCTK_PARAMETER__HTTPD__timeout_useconds); \
  CCTK_DECLARE_INIT (CCTK_INT const, until_expression_active, CCTK_PARAMETER__HTTPD__until_expression_active); \
  CCTK_DECLARE_INIT (CCTK_INT const, until_it, CCTK_PARAMETER__HTTPD__until_it); \
  CCTK_DECLARE_INIT (CCTK_INT const, until_it_active, CCTK_PARAMETER__HTTPD__until_it_active); \
  CCTK_DECLARE_INIT (CCTK_INT const, until_time_active, CCTK_PARAMETER__HTTPD__until_time_active); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_pthreads, CCTK_PARAMETER__HTTPD__use_pthreads); \
  CCTK_DECLARE_INIT (CCTK_INT const, verbose, CCTK_PARAMETER__HTTPD__verbose); \


#ifndef CCTK_PARAMETER__HTTPD__until_time
#  define CCTK_PARAMETER__HTTPD__until_time PRIVATE_HTTPD_STRUCT.until_time
#endif
#ifndef CCTK_PARAMETER__HTTPD__encryption_scheme
#  define CCTK_PARAMETER__HTTPD__encryption_scheme PRIVATE_HTTPD_STRUCT.encryption_scheme
#endif
#ifndef CCTK_PARAMETER__HTTPD__password
#  define CCTK_PARAMETER__HTTPD__password PRIVATE_HTTPD_STRUCT.password
#endif
#ifndef CCTK_PARAMETER__HTTPD__until_expression
#  define CCTK_PARAMETER__HTTPD__until_expression PRIVATE_HTTPD_STRUCT.until_expression
#endif
#ifndef CCTK_PARAMETER__HTTPD__user
#  define CCTK_PARAMETER__HTTPD__user PRIVATE_HTTPD_STRUCT.user
#endif
#ifndef CCTK_PARAMETER__HTTPD__hunt
#  define CCTK_PARAMETER__HTTPD__hunt PRIVATE_HTTPD_STRUCT.hunt
#endif
#ifndef CCTK_PARAMETER__HTTPD__pause
#  define CCTK_PARAMETER__HTTPD__pause PRIVATE_HTTPD_STRUCT.pause
#endif
#ifndef CCTK_PARAMETER__HTTPD__port
#  define CCTK_PARAMETER__HTTPD__port PRIVATE_HTTPD_STRUCT.port
#endif
#ifndef CCTK_PARAMETER__HTTPD__provide_pages
#  define CCTK_PARAMETER__HTTPD__provide_pages PRIVATE_HTTPD_STRUCT.provide_pages
#endif
#ifndef CCTK_PARAMETER__HTTPD__queue_length
#  define CCTK_PARAMETER__HTTPD__queue_length PRIVATE_HTTPD_STRUCT.queue_length
#endif
#ifndef CCTK_PARAMETER__HTTPD__refresh_seconds
#  define CCTK_PARAMETER__HTTPD__refresh_seconds PRIVATE_HTTPD_STRUCT.refresh_seconds
#endif
#ifndef CCTK_PARAMETER__HTTPD__single_step
#  define CCTK_PARAMETER__HTTPD__single_step PRIVATE_HTTPD_STRUCT.single_step
#endif
#ifndef CCTK_PARAMETER__HTTPD__steering_frequency
#  define CCTK_PARAMETER__HTTPD__steering_frequency PRIVATE_HTTPD_STRUCT.steering_frequency
#endif
#ifndef CCTK_PARAMETER__HTTPD__terminate
#  define CCTK_PARAMETER__HTTPD__terminate PRIVATE_HTTPD_STRUCT.terminate
#endif
#ifndef CCTK_PARAMETER__HTTPD__timeout_seconds
#  define CCTK_PARAMETER__HTTPD__timeout_seconds PRIVATE_HTTPD_STRUCT.timeout_seconds
#endif
#ifndef CCTK_PARAMETER__HTTPD__timeout_useconds
#  define CCTK_PARAMETER__HTTPD__timeout_useconds PRIVATE_HTTPD_STRUCT.timeout_useconds
#endif
#ifndef CCTK_PARAMETER__HTTPD__until_expression_active
#  define CCTK_PARAMETER__HTTPD__until_expression_active PRIVATE_HTTPD_STRUCT.until_expression_active
#endif
#ifndef CCTK_PARAMETER__HTTPD__until_it
#  define CCTK_PARAMETER__HTTPD__until_it PRIVATE_HTTPD_STRUCT.until_it
#endif
#ifndef CCTK_PARAMETER__HTTPD__until_it_active
#  define CCTK_PARAMETER__HTTPD__until_it_active PRIVATE_HTTPD_STRUCT.until_it_active
#endif
#ifndef CCTK_PARAMETER__HTTPD__until_time_active
#  define CCTK_PARAMETER__HTTPD__until_time_active PRIVATE_HTTPD_STRUCT.until_time_active
#endif
#ifndef CCTK_PARAMETER__HTTPD__use_pthreads
#  define CCTK_PARAMETER__HTTPD__use_pthreads PRIVATE_HTTPD_STRUCT.use_pthreads
#endif
#ifndef CCTK_PARAMETER__HTTPD__verbose
#  define CCTK_PARAMETER__HTTPD__verbose PRIVATE_HTTPD_STRUCT.verbose
#endif

