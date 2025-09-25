/*@@
   @file      Register.c
   @date      6 May 2003
   @author    David Rideout
   @desc
              Register the linear extrapolation boundary condition
   @enddesc
 @@*/

#include "cctk.h"

#include "SampleBnd.h"

/* the rcs ID and its dummy function to use it */
static const char *rcsid = "$Header$";
CCTK_FILEVERSION(CactusExamples_SampleBoundary_Register_c);

/********************************************************************
 ********************    External Routines   ************************
 ********************************************************************/

void SampleBoundary_RegisterBCs(CCTK_ARGUMENTS);

/*@@
   @routine    SampleBoundary_RegisterBCs
   @date       6 May 2003
   @author     David Rideout
   @desc
               Register all the boundary conditions.
   @enddesc
   @calls     
   @history
   @endhistory
@@*/

void SampleBoundary_RegisterBCs(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  
  int ierr;

  /* Register the linear extrapolation boundary condition */
  ierr = Boundary_RegisterPhysicalBC(cctkGH, 
                                     (CCTK_INT (*) (CCTK_POINTER_TO_CONST,
                                                    CCTK_INT,
                                                    CCTK_INT const *,
                                                    CCTK_INT const *,
                                                    CCTK_INT const *,
                                                    CCTK_INT const *))BndLinExtrap,
                                     "LinearExtrap");
  if (ierr < 0)
  {
    CCTK_WARN(0, "Failed to register LinearExtrap boundary condition");
  }
}