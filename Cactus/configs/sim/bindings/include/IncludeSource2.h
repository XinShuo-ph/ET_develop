/* Include source file IncludeSource2.h */

/* Including source file IncludeSource1In2.h from TestInclude1 */
#ifdef FCODE
      if (CCTK_IsThornActive("TestInclude1").eq.1) then
#else
if (CCTK_IsThornActive("TestInclude1")){
#endif
#include "CactusTest/TestInclude1/src/IncludeSource1In2.h"

#ifdef FCODE
      end if
#else

}
#endif
/* End of include source file IncludeSource1In2.h from TestInclude1 */
/* Including source file IncludeSource2In2.h from TestInclude2 */
#ifdef FCODE
      if (CCTK_IsThornActive("TestInclude2").eq.1) then
#else
if (CCTK_IsThornActive("TestInclude2")){
#endif
#include "CactusTest/TestInclude2/src/IncludeSource2In2.h"

#ifdef FCODE
      end if
#else

}
#endif
/* End of include source file IncludeSource2In2.h from TestInclude2 */
