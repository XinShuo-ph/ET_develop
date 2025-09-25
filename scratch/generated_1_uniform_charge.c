#include <cctk.h>
#include <cctk_Arguments.h>
#include <cctk_Parameters.h>
#include <cctk_Functions.h>
#include <util_Table.h>
#include <math.h>

void Poisson_prepare(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int i, j, k;
  int index;
  CCTK_REAL x, y, z, r;
  
  for (k = 0; k < cctk_lsh[2]; k++)
  {
    for (j = 0; j < cctk_lsh[1]; j++)
    {
      for (i = 0; i < cctk_lsh[0]; i++)
      {
        index = CCTK_GFINDEX3D(cctkGH, i, j, k);
        
        x = CCTK_ORIGIN_SPACE(0) + (cctk_lbnd[0] + i) * CCTK_DELTA_SPACE(0);
        y = CCTK_ORIGIN_SPACE(1) + (cctk_lbnd[1] + j) * CCTK_DELTA_SPACE(1);
        z = CCTK_ORIGIN_SPACE(2) + (cctk_lbnd[2] + k) * CCTK_DELTA_SPACE(2);
        
        r = sqrt(x*x + y*y + z*z);
        
        /* Initial guess for potential */
        if (r <= radius)
        {
          phi[index] = charge * (3.0/(2.0*radius) - r*r/(2.0*radius*radius*radius));
        }
        else
        {
          phi[index] = charge / r;
        }
      }
    }
  }
}

void Poisson_solve(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int i, j, k;
  int index;
  CCTK_REAL x, y, z, r;
  CCTK_REAL volume;
  CCTK_REAL charge_density;
  int ierr;
  
  /* Calculate charge density */
  volume = 4.0 * M_PI * radius * radius * radius / 3.0;
  charge_density = charge / volume;
  
  /* Set up residual (source term) for Poisson equation */
  for (k = 0; k < cctk_lsh[2]; k++)
  {
    for (j = 0; j < cctk_lsh[1]; j++)
    {
      for (i = 0; i < cctk_lsh[0]; i++)
      {
        index = CCTK_GFINDEX3D(cctkGH, i, j, k);
        
        x = CCTK_ORIGIN_SPACE(0) + (cctk_lbnd[0] + i) * CCTK_DELTA_SPACE(0);
        y = CCTK_ORIGIN_SPACE(1) + (cctk_lbnd[1] + j) * CCTK_DELTA_SPACE(1);
        z = CCTK_ORIGIN_SPACE(2) + (cctk_lbnd[2] + k) * CCTK_DELTA_SPACE(2);
        
        r = sqrt(x*x + y*y + z*z);
        
        if (r <= radius)
        {
          res[index] = -charge_density;
        }
        else
        {
          res[index] = 0.0;
        }
      }
    }
  }
  
  /* Call TATelliptic solver */
  ierr = TATelliptic_Solve(cctkGH, 1, "potential", "residual", solver, options);
  
  if (ierr != 0)
  {
    CCTK_WARN(0, "Error calling TATelliptic solver");
  }
}

void Poisson_boundaries_select(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  
  int ierr;
  int table_handle;
  
  /* Create table for boundary condition options */
  table_handle = Util_TableCreate(UTIL_TABLE_FLAGS_DEFAULT);
  if (table_handle < 0)
  {
    CCTK_WARN(0, "Could not create table for boundary conditions");
  }
  
  /* Set Dirichlet boundary condition with value 0 */
  ierr = Util_TableSetReal(table_handle, 0.0, "BOUNDARY_VALUE");
  if (ierr < 0)
  {
    CCTK_WARN(0, "Could not set boundary value in table");
  }
  
  /* Select boundary conditions for potential */
  ierr = Boundary_SelectGroupForBC(cctkGH, CCTK_ALL_FACES, 1, table_handle,
                                   "Poisson::potential", "Scalar");
  if (ierr < 0)
  {
    CCTK_WARN(0, "Could not select boundary conditions for potential");
  }
  
  /* Destroy table */
  ierr = Util_TableDestroy(table_handle);
  if (ierr < 0)
  {
    CCTK_WARN(0, "Could not destroy table");
  }
}