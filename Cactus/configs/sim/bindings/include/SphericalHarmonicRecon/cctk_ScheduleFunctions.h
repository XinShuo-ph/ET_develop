#include "SphericalHarmonicRecon/cctk_Arguments.h"

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void SphericalHarmonicRecon_ReadData (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void SphericalHarmonicRecon_PostStep (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void SphericalHarmonicRecon_Startup (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

