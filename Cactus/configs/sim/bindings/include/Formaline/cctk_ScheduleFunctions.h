#include "Formaline/cctk_Arguments.h"

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Formaline_OutputSource (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
int Formaline_PrintIDs (void);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Formaline_RegisterPublishRDF_Callbacks (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Formaline_RegisterWarnings (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Formaline_AnnounceInitial (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Formaline_AnnounceUpdate (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Formaline_AnnounceFinal (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void Formaline_UnregisterPublishRDF_Callbacks (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

