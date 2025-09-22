#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT check_every;
} PRIVATE_WATCHDOG_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_WATCHDOG_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, check_every, CCTK_PARAMETER__WATCHDOG__check_every); \


#ifndef CCTK_PARAMETER__WATCHDOG__check_every
#  define CCTK_PARAMETER__WATCHDOG__check_every PRIVATE_WATCHDOG_STRUCT.check_every
#endif

