#include "NullNews/cctk_Arguments.h"




#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void NullNews_InterpInit (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void NullNews_InterpCycleTimelevels (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void NullNews_Interp_to_constant_uBondi (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */



