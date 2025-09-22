#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,until_time,)&&\
CCTK_DECLARE(CCTK_STRING,encryption_scheme,)&&\
CCTK_DECLARE(CCTK_STRING,password,)&&\
CCTK_DECLARE(CCTK_STRING,until_expression,)&&\
CCTK_DECLARE(CCTK_STRING,user,)&&\
CCTK_DECLARE(CCTK_INT,hunt,)&&\
CCTK_DECLARE(CCTK_INT,pause,)&&\
CCTK_DECLARE(CCTK_INT,port,)&&\
CCTK_DECLARE(CCTK_INT,provide_pages,)&&\
CCTK_DECLARE(CCTK_INT,queue_length,)&&\
CCTK_DECLARE(CCTK_INT,refresh_seconds,)&&\
CCTK_DECLARE(CCTK_INT,single_step,)&&\
CCTK_DECLARE(CCTK_INT,steering_frequency,)&&\
CCTK_DECLARE(CCTK_INT,terminate,)&&\
CCTK_DECLARE(CCTK_INT,timeout_seconds,)&&\
CCTK_DECLARE(CCTK_INT,timeout_useconds,)&&\
CCTK_DECLARE(CCTK_INT,until_expression_active,)&&\
CCTK_DECLARE(CCTK_INT,until_it,)&&\
CCTK_DECLARE(CCTK_INT,until_it_active,)&&\
CCTK_DECLARE(CCTK_INT,until_time_active,)&&\
CCTK_DECLARE(CCTK_INT,use_pthreads,)&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /HTTPDpriv/until_time, encryption_scheme, password, until_expression, user, hunt, pause, port, provide_pages, queue_length, refresh_seconds, single_step, steering_frequency, terminate, timeout_seconds, timeout_useconds, until_expression_active, until_it, until_it_active, until_time_active, use_pthreads, verbose&&\
CCTK_DECLARE(CCTK_REAL,cctk_final_time,)&&\
CCTK_DECLARE(CCTK_REAL,cctk_initial_time,)&&\
CCTK_DECLARE(CCTK_REAL,CCTKH0,)&&\
CCTK_DECLARE(CCTK_STRING,CCTKH1,)&&\
CCTK_DECLARE(CCTK_INT,cctk_itlast,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH2,)&&\
COMMON /CACTUSrest/cctk_final_time, cctk_initial_time, CCTKH0, CCTKH1, cctk_itlast, CCTKH2&&\

