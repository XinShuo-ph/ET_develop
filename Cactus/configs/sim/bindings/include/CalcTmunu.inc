/* Include header file CalcTmunu.inc */

/* Including source file Scalar_CalcTmunu.inc from Exact */
#ifdef FCODE
      if (CCTK_IsThornActive("Exact").eq.1) then
#else
if (CCTK_IsThornActive("Exact")){
#endif
#include "EinsteinInitialData/Exact/src/include/Scalar_CalcTmunu.inc"

#ifdef FCODE
      end if
#else

}
#endif
/* End of include source file Scalar_CalcTmunu.inc from Exact */
/* Including source file TmunuBase_CalcTmunu.inc from TmunuBase */
#ifdef FCODE
      if (CCTK_IsThornActive("TmunuBase").eq.1) then
#else
if (CCTK_IsThornActive("TmunuBase")){
#endif
#include "EinsteinBase/TmunuBase/src/TmunuBase_CalcTmunu.inc"

#ifdef FCODE
      end if
#else

}
#endif
/* End of include source file TmunuBase_CalcTmunu.inc from TmunuBase */
