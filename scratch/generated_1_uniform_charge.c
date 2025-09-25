#include <cctk.h>
#include <cctk_Arguments.h>
#include <cctk_Parameters.h>
#include <util_Table.h>
#include <carpet.h>
#include <TATelliptic.h>
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
                
                x = x[index];
                y = y[index];
                z = z[index];
                r = sqrt(x*x + y*y + z*z);
                
                /* Initial guess for potential */
                phi[index] = 0.0;
                
                /* Set up source term (charge density) */
                if (r <= radius)
                {
                    CCTK_REAL volume = 4.0 * M_PI * radius * radius * radius / 3.0;
                    res[index] = -charge / volume;
                }
                else
                {
                    res[index] = 0.0;
                }
            }
        }
    }
}

void Poisson_solve(CCTK_ARGUMENTS)
{
    DECLARE_CCTK_ARGUMENTS;
    DECLARE_CCTK_PARAMETERS;
    
    int ierr;
    int options_table;
    
    options_table = Util_TableCreateFromString(options);
    if (options_table < 0)
    {
        CCTK_VWarn(0, __LINE__, __FILE__, CCTK_THORNSTRING,
                   "Error creating options table: %d", options_table);
    }
    
    ierr = TATelliptic_Solve(cctkGH, 3, 1,
                            cctk_nghostzones,
                            cctk_nghostzones,
                            cctk_nghostzones,
                            solver,
                            options_table,
                            "Poisson::phi",
                            "Poisson::res");
    
    if (ierr != 0)
    {
        CCTK_VWarn(0, __LINE__, __FILE__, CCTK_THORNSTRING,
                   "Error in TATelliptic_Solve: %d", ierr);
    }
    
    if (options_table >= 0)
    {
        Util_TableDestroy(options_table);
    }
}

void Poisson_boundaries_select(CCTK_ARGUMENTS)
{
    DECLARE_CCTK_ARGUMENTS;
    
    int ierr;
    int faces = CCTK_ALL_FACES;
    int boundary_width = 1;
    int table_handle;
    
    table_handle = Util_TableCreateFromString("DIRICHLET");
    if (table_handle < 0)
    {
        CCTK_VWarn(0, __LINE__, __FILE__, CCTK_THORNSTRING,
                   "Error creating boundary condition table");
    }
    
    Util_TableSetReal(table_handle, 0.0, "DIRICHLET_VALUE");
    
    ierr = Boundary_SelectGroupForBC(cctkGH, faces, boundary_width,
                                    table_handle, "Poisson::potential",
                                    "Dirichlet");
    
    if (ierr != 0)
    {
        CCTK_VWarn(0, __LINE__, __FILE__, CCTK_THORNSTRING,
                   "Error selecting boundary conditions: %d", ierr);
    }
    
    if (table_handle >= 0)
    {
        Util_TableDestroy(table_handle);
    }
}