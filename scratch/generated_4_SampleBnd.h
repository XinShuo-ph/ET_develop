/*@@
   @header    SampleBnd.h
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
 *********************     Constants       ***********************
 ********************************************************************/

/* Define return codes for the boundary condition function */
#define BOUNDARY_NO_ERROR                 0
#define BOUNDARY_INVALID_FACES           -1
#define BOUNDARY_UNSUPPORTED_STAGGERING  -2
#define BOUNDARY_INVALID_WIDTH           -4
#define BOUNDARY_INVALID_TABLE           -8
#define BOUNDARY_UNSUPPORTED_DIM        -16
#define BOUNDARY_GRID_SCALAR            -32

/********************************************************************
 *********************     Typedefs        ***********************
 ********************************************************************/

/* Function pointer type for physical boundary conditions */
typedef int (*phys_bc_fn_ptr) (const cGH *GH, 
                               int num_vars, 
                               int *var_indices, 
                               int *faces, 
                               int *boundary_widths, 
                               int *table_handles);

/********************************************************************
 *********************     Function Prototypes   *****************
 ********************************************************************/

/* Scheduled routines */
void SampleBoundary_RegisterBCs(CCTK_ARGUMENTS);

/* Boundary condition implementation */
int BndLinExtrap (const cGH *GH, 
                  int num_vars, 
                  int *vars, 
                  int *faces, 
                  int *widths, 
                  int *tables);

/* Fortran interface for the linear extrapolation routine */
void CCTK_FCALL CCTK_FNAME(Linear_extrap_one_bndry)(int *doBC, 
                                                    const int *lsh, 
                                                    CCTK_REAL *var_ptr);

#ifdef __cplusplus
}
#endif

#endif /* _SAMPLEBND_H_ */