/*@@
   @file      Register.c
   @date      6 May 2003
   @author    David Rideout
   @desc
              Registration of physical boundary conditions
   @enddesc
   @version   $Id$
 @@*/

#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_FortranString.h"

#include "SampleBnd.h"

/* the rcs ID and its dummy function to use it */
static const char *rcsid = "$Header$";
CCTK_FILEVERSION(CactusExamples_SampleBoundary_Register_c);

/********************************************************************
 *********************     Local Data Types   ***********************
 ********************************************************************/

/********************************************************************
 ********************* Local Routine Prototypes *********************
 ********************************************************************/

void SampleBoundary_RegisterBCs(CCTK_ARGUMENTS);

/********************************************************************
 ********************* Other Routine Prototypes *********************
 ********************************************************************/

/********************************************************************
 *********************     Local Data   *****************************
 ********************************************************************/

/********************************************************************
 *********************     External Routines   **********************
 ********************************************************************/

/*@@
   @routine    SampleBoundary_RegisterBCs
   @date       6 May 2003
   @author     David Rideout
   @desc
               Register all the boundary conditions that this thorn
               provides.
   @enddesc
   @calls      Boundary_RegisterPhysicalBC

   @var        CCTK_ARGUMENTS
   @vdesc      arguments as passed by the flesh
   @vtype      CCTK_ARGUMENTS
   @vio        in
   @endvar

   @returntype void
   @returndesc
   @endreturndesc
@@*/

void SampleBoundary_RegisterBCs(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  int err;

  /* Register the linear extrapolation boundary condition under the 
     name "LinearExtrap" */
  err = Boundary_RegisterPhysicalBC(cctkGH, (CCTK_FPOINTER) BndLinExtrap, 
                                   "LinearExtrap");
  if (err < 0)
  {
    CCTK_WARN(0, "Failed to register LinearExtrap boundary condition");
  }
}