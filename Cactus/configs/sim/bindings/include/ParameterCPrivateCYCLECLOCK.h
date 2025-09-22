#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_INT register_clock;
} PRIVATE_CYCLECLOCK_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CYCLECLOCK_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_INT const, register_clock, CCTK_PARAMETER__CYCLECLOCK__register_clock); \


#ifndef CCTK_PARAMETER__CYCLECLOCK__register_clock
#  define CCTK_PARAMETER__CYCLECLOCK__register_clock PRIVATE_CYCLECLOCK_STRUCT.register_clock
#endif

