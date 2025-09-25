#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_Parameters.h"
#include "cctk_Functions.h"
#include "util_Table.h"
#include <math.h>

static const char *rcsid = "$Header$";

CCTK_FILEVERSION(CactusExamples_Poisson_uniform_charge_c)

void Poisson_prepare(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int i, j, k, index;
  
  for (k = 0; k < cctk_lsh[2]; k++)
  {
    for (j = 0; j < cctk_lsh[1]; j++)
    {
      for (i = 0; i < cctk_lsh[0]; i++)
      {
        index = CCTK_GFINDEX3D(cctkGH, i, j, k);
        phi[index] = 0.0;
        res[index] = 0.0;
      }
    }
  }
}

void Poisson_solve(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int i, j, k, index;
  CCTK_REAL x_coord, y_coord, z_coord, r;
  CCTK_REAL rho;
  CCTK_REAL charge_density;
  CCTK_REAL sphere_volume;
  int ierr;
  int options_table;
  
  /* Calculate charge density assuming uniform distribution in sphere */
  sphere_volume = (4.0/3.0) * M_PI * radius * radius * radius;
  charge_density = charge / sphere_volume;
  
  /* Set up source term (charge density) */
  for (k = 0; k < cctk_lsh[2]; k++)
  {
    for (j = 0; j < cctk_lsh[1]; j++)
    {
      for (i = 0; i < cctk_lsh[0]; i++)
      {
        index = CCTK_GFINDEX3D(cctkGH, i, j, k);
        
        x_coord = x[index];
        y_coord = y[index];
        z_coord = z[index];
        
        r = sqrt(x_coord*x_coord + y_coord*y_coord + z_coord*z_coord);
        
        if (r <= radius)
        {
          rho = charge_density;
        }
        else
        {
          rho = 0.0;
        }
        
        /* Store source term in residual grid function */
        res[index] = -4.0 * M_PI * rho;
      }
    }
  }
  
  /* Create options table for solver */
  options_table = Util_TableCreateFromString(options);
  if (options_table < 0)
  {
    CCTK_VWarn(0, __LINE__, __FILE__, CCTK_THORNSTRING,
               "Could not create options table from string '%s'", options);
  }
  
  /* Call elliptic solver */
  ierr = TATelliptic_Solve(cctkGH, options_table, "phi", "res", solver);
  
  if (ierr != 0)
  {
    CCTK_VWarn(0, __LINE__, __FILE__, CCTK_THORNSTRING,
               "TATelliptic_Solve failed with error code %d", ierr);
  }
  
  /* Clean up */
  ierr = Util_TableDestroy(options_table);
  if (ierr != 0)
  {
    CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
               "Could not destroy options table");
  }
}

void Poisson_boundaries_select(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;
  
  int ierr;
  int table_handle;
  CCTK_REAL falloff_power = 1.0;
  
  /* Create table for boundary condition options */
  table_handle = Util_TableCreate(UTIL_TABLE_FLAGS_DEFAULT);
  if (table_handle < 0)
  {
    CCTK_WARN(0, "Could not create table for boundary conditions");
  }
  
  /* Set falloff power for Robin boundary condition */
  ierr = Util_TableSetReal(table_handle, falloff_power, "FALLOFF_POWER");
  if (ierr < 0)
  {
    CCTK_WARN(0, "Could not set falloff power in boundary table");
  }
  
  /* Apply Robin boundary condition (1/r falloff) to all faces */
  ierr = Boundary_SelectGroupForBC(cctkGH, CCTK_ALL_FACES, 1, table_handle,
                                   "Poisson::potential", "Robin");
  if (ierr < 0)
  {
    CCTK_WARN(0, "Could not select boundary conditions for potential");
  }
  
  /* Clean up */
  ierr = Util_TableDestroy(table_handle);
  if (ierr != 0)
  {
    CCTK_VWarn(1, __LINE__, __FILE__, CCTK_THORNSTRING,
               "Could not destroy boundary table");
  }
}