#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_Parameters.h"

#include "TATelliptic.h"

void Poisson_prepare(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int i, j, k;
  int index;
  
  /* Initialize potential to zero */
  for (k = 0; k < cctk_lsh[2]; k++) {
    for (j = 0; j < cctk_lsh[1]; j++) {
      for (i = 0; i < cctk_lsh[0]; i++) {
        index = CCTK_GFINDEX3D(cctkGH, i, j, k);
        phi[index] = 0.0;
        res[index] = 0.0;
      }
    }
  }
}

static int residual_func(cGH const *restrict const cctkGH,
                        CCTK_REAL const *restrict const phi_ptr,
                        CCTK_REAL *restrict const res_ptr,
                        void *restrict const user_data)
{
  DECLARE_CCTK_PARAMETERS;
  
  int i, j, k;
  int index;
  CCTK_REAL x, y, z, r;
  CCTK_REAL rho;
  CCTK_REAL dx, dy, dz;
  CCTK_REAL laplacian;
  CCTK_REAL volume;
  
  dx = CCTK_DELTA_SPACE(0);
  dy = CCTK_DELTA_SPACE(1);
  dz = CCTK_DELTA_SPACE(2);
  
  volume = 4.0 * M_PI * radius * radius * radius / 3.0;
  
  for (k = 1; k < cctk_lsh[2] - 1; k++) {
    for (j = 1; j < cctk_lsh[1] - 1; j++) {
      for (i = 1; i < cctk_lsh[0] - 1; i++) {
        index = CCTK_GFINDEX3D(cctkGH, i, j, k);
        
        x = CCTK_ORIGIN_SPACE(0) + (cctk_lbnd[0] + i) * dx;
        y = CCTK_ORIGIN_SPACE(1) + (cctk_lbnd[1] + j) * dy;
        z = CCTK_ORIGIN_SPACE(2) + (cctk_lbnd[2] + k) * dz;
        
        r = sqrt(x*x + y*y + z*z);
        
        /* Set charge density */
        if (r <= radius) {
          rho = charge / volume;
        } else {
          rho = 0.0;
        }
        
        /* Calculate Laplacian using finite differences */
        laplacian = (phi_ptr[CCTK_GFINDEX3D(cctkGH, i+1, j, k)] 
                   - 2.0 * phi_ptr[index] 
                   + phi_ptr[CCTK_GFINDEX3D(cctkGH, i-1, j, k)]) / (dx * dx)
                  + (phi_ptr[CCTK_GFINDEX3D(cctkGH, i, j+1, k)] 
                   - 2.0 * phi_ptr[index] 
                   + phi_ptr[CCTK_GFINDEX3D(cctkGH, i, j-1, k)]) / (dy * dy)
                  + (phi_ptr[CCTK_GFINDEX3D(cctkGH, i, j, k+1)] 
                   - 2.0 * phi_ptr[index] 
                   + phi_ptr[CCTK_GFINDEX3D(cctkGH, i, j, k-1)]) / (dz * dz);
        
        /* Residual = Laplacian(phi) - rho */
        res_ptr[index] = laplacian - rho;
      }
    }
  }
  
  return 0;
}

void Poisson_solve(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int ierr;
  
  CCTK_INFO("Solving Poisson equation for uniform charge distribution");
  
  /* Call TATelliptic solver */
  ierr = TATelliptic_Solve(cctkGH, 1, &cctkGH->cctk_lsh[0],
                          (CCTK_REAL const *const *) &phi,
                          (CCTK_REAL *const *) &phi,
                          residual_func, NULL,
                          solver, options);
  
  if (ierr) {
    CCTK_WARN(0, "Error in TATelliptic_Solve");
  }
  
  /* Calculate final residual */
  residual_func(cctkGH, phi, res, NULL);
  
  CCTK_INFO("Poisson equation solved successfully");
}

void Poisson_boundaries_select(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  
  int ierr;
  CCTK_INT faces = CCTK_ALL_FACES;
  CCTK_INT width = 1;
  CCTK_INT table;
  
  table = Util_TableCreate(UTIL_TABLE_FLAGS_DEFAULT);
  if (table < 0) {
    CCTK_WARN(0, "Could not create table");
  }
  
  ierr = Util_TableSetReal(table, 0.0, "SCALAR");
  if (ierr < 0) {
    CCTK_WARN(0, "Could not set table entry");
  }
  
  ierr = Boundary_SelectGroupForBC(cctkGH, faces, width, table,
                                  "Poisson::potential", "scalar");
  if (ierr < 0) {
    CCTK_WARN(0, "Could not select boundary condition");
  }
  
  ierr = Util_TableDestroy(table);
  if (ierr < 0) {
    CCTK_WARN(0, "Could not destroy table");
  }
}