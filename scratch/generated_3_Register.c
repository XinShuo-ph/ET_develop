/*@@
   @file      Register.c
   @date      6 May 2003
   @author    David Rideout
   @desc
              Register the boundary conditions that this thorn provides
   @enddesc
   @version   $Id$
 @@*/

#include "cctk.h"
#include "SampleBnd.h"

/* the rcs ID and its dummy function to use it */
static const char *rcsid = "$Header$";
CCTK_FILEVERSION(CactusExamples_SampleBoundary_Register_c);

/********************************************************************
 ********************    External Routines   ************************
 ********************************************************************/

/*@@
   @routine    SampleBoundary_RegisterBCs
   @date       6 May 2003
   @author     David Rideout
   @desc
               Register the boundary conditions that this thorn provides
   @enddesc
   @calls      Boundary_RegisterPhysicalBC

   @returntype int
   @returndesc
      return code of @seeroutine Boundary_RegisterPhysicalBC <BR>
      0 for success
   @endreturndesc
@@*/
int SampleBoundary_RegisterBCs(void)
{
  int err;

  /* Register the linear extrapolation boundary condition with the boundary thorn */
  err = Boundary_RegisterPhysicalBC((CCTK_POINTER_TO_CONST) NULL,
                                   (CCTK_INT) BndLinExtrap,
                                   "LinearExtrap");
  if (err)
  {
    CCTK_WARN(0, "Failed to register boundary condition LinearExtrap");
  }

  return err;
}