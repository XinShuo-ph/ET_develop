#include "RotatingSymmetry180/cctk_Arguments.h"

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Rot180_CheckTensorTypes (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Rot180_RegisterSymmetry (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Rot180_ComputeLevelExtent (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Rot180_ApplyBC (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

