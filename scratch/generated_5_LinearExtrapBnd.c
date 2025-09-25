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

/* Prototype for the Fortran routine */
void CCTK_FCALL Linear_extrap_one_bndry(CCTK_INT *doBC, CCTK_INT *lsh, CCTK_REAL *var);

/*@@
   @routine    BndLinExtrap
   @date       6 May 2003
   @author     David Rideout
   @desc 
               Linear extrapolation boundary condition.
               This is the function which is registered as a boundary condition.
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
   @vdesc      number of variables passed in through var_indices[]
   @vtype      const CCTK_INT
   @vio        in
   @endvar
   @var        var_indices
   @vdesc      array of variable indicies to which to apply this boundary
               condition
   @vtype      const CCTK_INT*
   @vio        in
   @endvar
   @var        faces
   @vdesc      array of set of faces to which to apply the bc
   @vtype      const CCTK_INT*
   @vio        in
   @endvar
   @var        widths
   @vdesc      array of boundary widths for each variable
   @vtype      const CCTK_INT*
   @vio        in
   @endvar
   @var        table_handles
   @vdesc      array of table handles which hold extra arguments
   @vtype      const CCTK_INT*
   @vio        in
   @endvar
   @returntype CCTK_INT
   @returndesc
               return code of @seeroutine Linear_extrap_one_bndry
               0  success
              -1  failure
   @endreturndesc
@@*/

int BndLinExtrap(const CCTK_POINTER_TO_CONST GH, const CCTK_INT num_vars,
                 const CCTK_INT *var_indices, const CCTK_INT *faces,
                 const CCTK_INT *widths, const CCTK_INT *table_handles)
{
  const cGH *cctkGH = (const cGH *)GH;
  int i, var, gdim;
  CCTK_INT doBC[6];
  CCTK_INT lsh[3];
  CCTK_REAL *var_ptr;
  int retval = 0;

  /* Check input arguments */
  if (!GH)
  {
    CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
               "BndLinExtrap: NULL pointer passed for GH argument");
    return -1;
  }

  if (num_vars < 0)
  {
    CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
               "BndLinExtrap: num_vars=%d is negative", (int)num_vars);
    return -1;
  }

  /* Get grid dimensions */
  gdim = CCTK_GroupDimFromVarI(var_indices[0]);
  if (gdim != 3)
  {
    CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
               "BndLinExtrap: Linear extrapolation boundary condition "
               "only implemented for 3D grids (variable has %dD)", gdim);
    return -1;
  }

  /* Loop over variables */
  for (var = 0; var < num_vars; var++)
  {
    /* Check variable type */
    if (CCTK_VarTypeI(var_indices[var]) != CCTK_VARIABLE_REAL)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "BndLinExtrap: Variable index %d is not of type CCTK_REAL",
                 var_indices[var]);
      retval = -1;
      continue;
    }

    /* Get variable data pointer */
    var_ptr = (CCTK_REAL *) CCTK_VarDataPtrI(cctkGH, 0, var_indices[var]);
    if (!var_ptr)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "BndLinExtrap: Cannot get data pointer for variable index %d",
                 var_indices[var]);
      retval = -1;
      continue;
    }

    /* Get local grid size */
    for (i = 0; i < 3; i++)
    {
      lsh[i] = cctkGH->cctk_lsh[i];
    }

    /* Set up doBC array based on faces */
    for (i = 0; i < 6; i++)
    {
      doBC[i] = (faces[var] == CCTK_ALL_FACES || (faces[var] & (1 << i))) ? 1 : 0;
    }

    /* Check that we have enough grid points */
    if ((doBC[0] || doBC[1]) && lsh[0] < 3)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "BndLinExtrap: Not enough grid points in x-direction "
                 "(need at least 3, have %d)", (int)lsh[0]);
      retval = -1;
      continue;
    }
    if ((doBC[2] || doBC[3]) && lsh[1] < 3)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "BndLinExtrap: Not enough grid points in y-direction "
                 "(need at least 3, have %d)", (int)lsh[1]);
      retval = -1;
      continue;
    }
    if ((doBC[4] || doBC[5]) && lsh[2] < 3)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "BndLinExtrap: Not enough grid points in z-direction "
                 "(need at least 3, have %d)", (int)lsh[2]);
      retval = -1;
      continue;
    }

    /* Call the Fortran routine */
    Linear_extrap_one_bndry(doBC, lsh, var_ptr);
  }

  return retval;
}