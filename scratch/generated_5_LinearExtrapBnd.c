/*@@
   @file      LinearExtrapBnd.c
   @date      6 May 2003
   @author    David Rideout
   @desc 
              C wrapper for linear extrapolation boundary condition
   @enddesc 
   @version   $Header$
 @@*/

#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_Parameters.h"
#include "SampleBnd.h"

static const char *rcsid = "$Header$";

CCTK_FILEVERSION(CactusExamples_SampleBoundary_LinearExtrapBnd_c);

/* Fortran routine prototype */
void CCTK_FCALL CCTK_FNAME(Linear_extrap_one_bndry)(
  int *doBC,
  int *lsh,
  CCTK_REAL *var);

/*@@
   @routine    BndLinExtrap
   @date       6 May 2003
   @author     David Rideout
   @desc 
               C wrapper to apply linear extrapolation boundary condition
   @enddesc 
   @calls      
   @history 
   @endhistory
   @var        GH
   @vdesc      Pointer to CCTK grid hierarchy
   @vtype      const CCTK_POINTER_TO_CONST
   @vio        in
   @endvar
   @var        num_vars
   @vdesc      Number of variables to apply BC to
   @vtype      const CCTK_INT
   @vio        in  
   @endvar
   @var        var_indices
   @vdesc      Variable indices to apply BC to
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @var        faces
   @vdesc      Faces on which to apply BC
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @var        widths
   @vdesc      Boundary widths
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @var        table_handles
   @vdesc      Table handles for options
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @returntype int
   @returndesc
               0 for success
   @endreturndesc
@@*/

int BndLinExtrap (const CCTK_POINTER_TO_CONST GH, const CCTK_INT num_vars, 
                  const CCTK_INT *var_indices, const CCTK_INT *faces, 
                  const CCTK_INT *widths, const CCTK_INT *table_handles)
{
  const cGH *cctkGH = (const cGH *) GH;
  int i, ierr;
  int doBC[6];
  int lsh[3];
  CCTK_REAL *var_ptr;
  int var_index;
  
  ierr = 0;
  
  /* Check that we are in 3D */
  if (cctkGH->cctk_dim != 3)
  {
    CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
               "Linear extrapolation boundary condition only implemented "
               "for 3D");
    return -1;
  }
  
  /* Set up local grid size */
  lsh[0] = cctkGH->cctk_lsh[0];
  lsh[1] = cctkGH->cctk_lsh[1]; 
  lsh[2] = cctkGH->cctk_lsh[2];
  
  /* Loop over variables */
  for (i = 0; i < num_vars; i++)
  {
    var_index = var_indices[i];
    
    /* Get pointer to variable data */
    var_ptr = (CCTK_REAL *) CCTK_VarDataPtrI(cctkGH, 0, var_index);
    
    if (!var_ptr)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "Cannot get data pointer for variable index %d", var_index);
      ierr = -2;
      continue;
    }
    
    /* Set up faces array for this variable */
    if (faces)
    {
      doBC[0] = faces[6*i + 0];  /* x-min */
      doBC[1] = faces[6*i + 1];  /* x-max */
      doBC[2] = faces[6*i + 2];  /* y-min */
      doBC[3] = faces[6*i + 3];  /* y-max */
      doBC[4] = faces[6*i + 4];  /* z-min */
      doBC[5] = faces[6*i + 5];  /* z-max */
    }
    else
    {
      /* Default: apply to all faces */
      doBC[0] = 1;
      doBC[1] = 1;
      doBC[2] = 1;
      doBC[3] = 1;
      doBC[4] = 1;
      doBC[5] = 1;
    }
    
    /* Call Fortran routine */
    CCTK_FNAME(Linear_extrap_one_bndry)(doBC, lsh, var_ptr);
  }
  
  return ierr;
}