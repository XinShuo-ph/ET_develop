#include "IOJpeg/cctk_Arguments.h"

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
int IOJpeg_Startup (void);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void IOJpeg_ChooseOutput (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

