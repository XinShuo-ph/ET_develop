/*@@
   @file      LinearExtrapBnd.c
   @date      6 May 2003
   @author    David Rideout
   @desc 
              Linear extrapolation boundary condition
   @enddesc 
   @version   $Header$
 @@*/

#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_Parameters.h"
#include "SampleBnd.h"

static const char *rcsid = "$Header$";

CCTK_FILEVERSION(CactusExamples_SampleBoundary_LinearExtrapBnd_c);

/********************************************************************
 ********************* External Routine Prototypes ******************
 ********************************************************************/

void CCTK_FCALL CCTK_FNAME(Linear_extrap_one_bndry)(int doBC[6], int lsh[3], CCTK_REAL *var);

/********************************************************************
 *********************     Aliased Routines   ***********************
 ********************************************************************/

 /*@@
   @routine    BndLinExtrap
   @date       6 May 2003
   @author     David Rideout
   @desc 
               Linear extrapolation boundary condition
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
   @vdesc      number of variables passed in through var_indices[]
   @vtype      const CCTK_INT
   @vio        in
   @endvar
   @var        var_indices
   @vdesc      array of variable indicies to which to apply this boundary condition
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @var        faces
   @vdesc      array of set of faces to which to apply the boundary condition
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @var        widths
   @vdesc      array of boundary widths for each variable
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @var        table_handles
   @vdesc      array of table handles which hold extra arguments
   @vtype      const CCTK_INT *
   @vio        in
   @endvar
   @returntype int
   @returndesc
               return code of @seeroutine BndLinExtrap <BR>
               -1 if invalid variable type was passed in<BR>
               -2 if operation failed
   @endreturndesc
@@*/

int BndLinExtrap (const CCTK_POINTER_TO_CONST GH, const CCTK_INT num_vars, 
                  const CCTK_INT *var_indices,  const CCTK_INT *faces, 
                  const CCTK_INT *widths, const CCTK_INT *table_handles)
{
  const cGH *cctkGH;
  int retval;
  int i;
  int var_index;
  int gdim;
  void *var_ptr;
  int var_type;
  int doBC[6];
  int lsh[3];
  
  /* avoid compiler warnings about unused parameters */
  (void) (widths + 0);
  (void) (table_handles + 0);
  
  cctkGH = (const cGH *) GH;
  retval = 0;
  
  gdim = CCTK_GroupDimI(CCTK_GroupIndexFromVarI(var_indices[0]));
  
  if (gdim != 3)
  {
    CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
               "Linear extrapolation boundary condition only implemented "
               "for 3D variables");
    return -2;
  }
  
  /* loop over variables */
  for (i = 0; i < num_vars; i++)
  {
    var_index = var_indices[i];
    var_ptr = CCTK_VarDataPtrI(cctkGH, 0, var_index);
    var_type = CCTK_VarTypeI(var_index);
    
    if (var_type != CCTK_VARIABLE_REAL)
    {
      CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
                 "Linear extrapolation boundary condition only implemented "
                 "for CCTK_REAL variables");
      retval = -1;
      continue;
    }
    
    /* set up doBC array */
    doBC[0] = (faces[i] >> 0) & 1;  /* x min face */
    doBC[1] = (faces[i] >> 1) & 1;  /* x max face */
    doBC[2] = (faces[i] >> 2) & 1;  /* y min face */
    doBC[3] = (faces[i] >> 3) & 1;  /* y max face */
    doBC[4] = (faces[i] >> 4) & 1;  /* z min face */
    doBC[5] = (faces[i] >> 5) & 1;  /* z max face */
    
    /* set up lsh array */
    lsh[0] = cctkGH->cctk_lsh[0];
    lsh[1] = cctkGH->cctk_lsh[1];
    lsh[2] = cctkGH->cctk_lsh[2];
    
    /* call the Fortran routine */
    CCTK_FNAME(Linear_extrap_one_bndry)(doBC, lsh, (CCTK_REAL *) var_ptr);
  }
  
  return retval;
}