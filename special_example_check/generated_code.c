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
void CCTK_FCALL CCTK_FNAME(Linear_extrap_one_bndry)(int *doBC, int *lsh, CCTK_REAL *var);

/*@@
   @routine    BndLinExtrap
   @date       6 May 2003
   @author     David Rideout
   @desc 
               Apply linear extrapolation boundary condition to a set of variables
   @enddesc 
   @calls      Linear_extrap_one_bndry
   @history 
   @endhistory
   @var        GH
   @vdesc      Pointer to CCTK grid hierarchy
   @vtype      const CCTK_POINTER_TO_CONST
   @vio        in
   @endvar
   @var        num_vars
   @vdesc      Number of variables to apply boundary condition to
   @vtype      const CCTK_INT
   @vio        in
   @endvar
   @var        var_indices
   @vdesc      Array of variable indices
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @var        faces
   @vdesc      Array of face flags
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @var        widths
   @vdesc      Array of boundary widths
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @var        table_handles
   @vdesc      Array of table handles
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @returntype int
   @returndesc
               0 for success, negative for error
   @endreturndesc
@@*/

int BndLinExtrap(const CCTK_POINTER_TO_CONST GH, const CCTK_INT num_vars, 
                 const CCTK_INT *var_indices, const CCTK_INT *faces, 
                 const CCTK_INT *widths, const CCTK_INT *table_handles)
{
  const cGH *cctkGH = (const cGH *) GH;
  int i, j;
  int var_index;
  int doBC[6];
  int lsh[3];
  CCTK_REAL *var_ptr;
  int retval = 0;

  /* Check that we have a 3D grid */
  if (cctkGH->cctk_dim != 3)
  {
    CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
               "LinearExtrap boundary condition only works in 3D");
    return -1;
  }

  /* Check that the grid has at least 3 points in each direction */
  if (cctkGH->cctk_lsh[0] < 3 || cctkGH->cctk_lsh[1] < 3 || cctkGH->cctk_lsh[2] < 3)
  {
    CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
               "LinearExtrap boundary condition requires at least 3 grid points "
               "in each direction");
    return -2;
  }

  /* Set up local grid size */
  for (i = 0; i < 3; i++)
  {
    lsh[i] = cctkGH->cctk_lsh[i];
  }

  /* Loop over all variables */
  for (i = 0; i < num_vars; i++)
  {
    var_index = var_indices[i];
    
    /* Check for valid variable index */
    if (var_index < 0)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "Invalid variable index %d", var_index);
      retval = -3;
      continue;
    }

    /* Get pointer to variable data */
    var_ptr = (CCTK_REAL *) CCTK_VarDataPtrI(cctkGH, 0, var_index);
    if (!var_ptr)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "Cannot get data pointer for variable index %d", var_index);
      retval = -4;
      continue;
    }

    /* Check that variable is CCTK_REAL */
    if (CCTK_VarTypeI(var_index) != CCTK_VARIABLE_REAL)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "LinearExtrap boundary condition only supports CCTK_REAL variables");
      retval = -5;
      continue;
    }

    /* Set up face flags - determine which faces to apply BC to */
    for (j = 0; j < 6; j++)
    {
      doBC[j] = 0;
    }

    /* If faces array is provided, use it to determine which faces to apply BC to */
    if (faces)
    {
      /* faces array contains flags for each face */
      for (j = 0; j < 6; j++)
      {
        if (j < 6 && faces[6*i + j])
        {
          doBC[j] = 1;
        }
      }
    }
    else
    {
      /* Apply to all faces if no face specification is given */
      for (j = 0; j < 6; j++)
      {
        doBC[j] = 1;
      }
    }

    /* Call the Fortran routine to do the actual work */
    CCTK_FNAME(Linear_extrap_one_bndry)(doBC, lsh, var_ptr);
  }

  return retval;
}