/*@@
   @file      SampleBnd.h
   @date      6 May 2003
   @author    David Rideout
   @desc 
              Header file for SampleBoundary thorn
   @enddesc 
   @version   $Header$
 @@*/

#ifndef _SAMPLEBND_H_
#define _SAMPLEBND_H_

#include "cctk.h"

#ifdef __cplusplus
extern "C" 
{
#endif

/********************************************************************
 *********************     Function Prototypes   *******************
 ********************************************************************/

/* Aliased function prototypes */
CCTK_INT CCTK_FCALL CCTK_FNAME(Boundary_RegisterPhysicalBC)
     (CCTK_POINTER_TO_CONST GH,
      CCTK_INT CCTK_FPOINTER function_pointer(CCTK_POINTER_TO_CONST GH,
                                              CCTK_INT num_vars,
                                              CCTK_INT *var_indices,
                                              CCTK_INT *faces,
                                              CCTK_INT *boundary_widths,
                                              CCTK_INT *table_handles),
      CCTK_STRING bc_name);

CCTK_INT CCTK_FCALL CCTK_FNAME(SymmetryTableHandleForGrid)
     (CCTK_POINTER_TO_CONST cctkGH);

/* Function pointer type for boundary condition functions */
typedef int (*phys_bc_fn_ptr) (const cGH *GH,
                               int num_vars,
                               int *vars,
                               int *faces,
                               int *widths,
                               int *tables);

/* Scheduled function prototypes */
void SampleBoundary_RegisterBCs(CCTK_ARGUMENTS);

/* Boundary condition implementation prototypes */
int BndLinExtrap(const cGH *GH,
                 int num_vars,
                 int *vars,
                 int *faces,
                 int *widths,
                 int *tables);

/* Fortran routine prototype */
void CCTK_FCALL CCTK_FNAME(Linear_extrap_one_bndry)(int *doBC,
                                                    const int *lsh,
                                                    CCTK_REAL *var_ptr);

#ifdef __cplusplus
}
#endif

#endif /* _SAMPLEBND_H_ */