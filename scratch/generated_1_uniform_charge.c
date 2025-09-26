#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_Parameters.h"

#include "carpet.h"
#include "TATelliptic.h"

void Poisson_prepare(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int const npoints = cctk_lsh[0] * cctk_lsh[1] * cctk_lsh[2];
  
  /* Initialize potential to zero as initial guess */
  for (int n = 0; n < npoints; ++n) {
    phi[n] = 0.0;
  }
}

void Poisson_solve(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int const npoints = cctk_lsh[0] * cctk_lsh[1] * cctk_lsh[2];
  
  /* Set up source term (charge density) */
  CCTK_REAL *source = malloc(npoints * sizeof(CCTK_REAL));
  
  for (int k = 0; k < cctk_lsh[2]; ++k) {
    for (int j = 0; j < cctk_lsh[1]; ++j) {
      for (int i = 0; i < cctk_lsh[0]; ++i) {
        int const ind3d = CCTK_GFINDEX3D(cctkGH, i, j, k);
        
        CCTK_REAL const xx = x[ind3d];
        CCTK_REAL const yy = y[ind3d];
        CCTK_REAL const zz = z[ind3d];
        
        CCTK_REAL const rr = sqrt(xx*xx + yy*yy + zz*zz);
        
        /* Set charge density inside sphere */
        if (rr <= radius) {
          CCTK_REAL const volume = 4.0/3.0 * M_PI * pow(radius, 3);
          source[ind3d] = charge / volume;
        } else {
          source[ind3d] = 0.0;
        }
      }
    }
  }
  
  /* Call TATelliptic solver */
  int const ierr = TATelliptic_Solve(cctkGH, "potential", "TATelliptic::Poisson3D",
                                     1, options, phi, source, res);
  
  if (ierr != 0) {
    CCTK_WARN(0, "Error calling TATelliptic solver");
  }
  
  free(source);
}

void Poisson_boundaries_select(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int const faces = CCTK_ALL_FACES;
  int const boundary_width = 1;
  int const table_handle = Util_TableCreate(UTIL_TABLE_FLAGS_DEFAULT);
  
  /* Set Dirichlet boundary conditions (phi = 0) */
  Util_TableSetReal(table_handle, 0.0, "DIRICHLET_VALUE");
  
  int const ierr = Boundary_SelectGroupForBC(cctkGH, faces, boundary_width,
                                             table_handle, "Poisson::potential",
                                             "Dirichlet");
  
  if (ierr != 0) {
    CCTK_WARN(0, "Error selecting boundary conditions");
  }
  
  Util_TableDestroy(table_handle);
}