#include "TestReduce/cctk_Arguments.h"

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void TestReduce_Initial (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */

#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void TestReduceC_Maximum (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */


#ifdef CCODE
#ifdef __cplusplus
extern "C"
#endif
void TestReduceC_Sum (CCTK_ARGUMENTS) CCTK_ATTRIBUTE_NONNULL(1);
#endif /* CCODE */


