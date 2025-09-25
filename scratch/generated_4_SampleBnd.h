/*@@
   @header    SampleBnd.h
   @date      6 May 2003
   @author    David Rideout
   @desc 
              Function prototypes for SampleBoundary thorn
   @enddesc 
   @version   $Header$
 @@*/

#ifndef _SAMPLEBND_H_
#define _SAMPLEBND_H_ 1

#include "cctk.h"

#ifdef __cplusplus
extern "C" 
{
#endif

/* Function pointer type for physical boundary conditions */
typedef int (*phys_bc_fn_ptr) (const cGH *GH, 
                               int num_vars, 
                               int *var_indices, 
                               int *faces, 
                               int *boundary_widths, 
                               int *table_handles);

/* Scheduled function prototypes */
void SampleBoundary_RegisterBCs(CCTK_ARGUMENTS);

/* Boundary condition implementation function */
int BndLinExtrap(const cGH *GH, 
                 int num_vars, 
                 int *vars, 
                 int *faces, 
                 int *widths, 
                 int *tables);

/* Fortran function prototype */
void CCTK_FCALL CCTK_FNAME(Linear_extrap_one_bndry)(int *doBC, 
                                                    const int *lsh, 
                                                    CCTK_REAL *var_ptr);

#ifdef __cplusplus
}
#endif

#endif /* _SAMPLEBND_H_ */