#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT linearized_news;
} RESTRICTED_NULLNEWS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_RESTRICTED_NULLNEWS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, linearized_news, CCTK_PARAMETER__NULLNEWS__linearized_news); \


#ifndef CCTK_PARAMETER__NULLNEWS__linearized_news
#  define CCTK_PARAMETER__NULLNEWS__linearized_news RESTRICTED_NULLNEWS_STRUCT.linearized_news
#endif

