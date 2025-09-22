#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,excluded_centre_x,(10))&&\
CCTK_DECLARE(CCTK_REAL,excluded_centre_y,(10))&&\
CCTK_DECLARE(CCTK_REAL,excluded_centre_z,(10))&&\
CCTK_DECLARE(CCTK_REAL,excluded_radius,(10))&&\
CCTK_DECLARE(CCTK_REAL,excluded_surface_factor,(10))&&\
CCTK_DECLARE(CCTK_INT,exclude_exterior,(10))&&\
CCTK_DECLARE(CCTK_INT,excluded_surface,(10))&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /CarpetMaskpriv/excluded_centre_x, excluded_centre_y, excluded_centre_z, excluded_radius, excluded_surface_factor, exclude_exterior, excluded_surface, verbose&&\
CCTK_DECLARE(CCTK_REAL,CCTKH2,(42))&&\
CCTK_DECLARE(CCTK_STRING,CCTKH1,(42))&&\
CCTK_DECLARE(CCTK_STRING,CCTKH3,(42))&&\
CCTK_DECLARE(CCTK_INT,CCTKH0,(42))&&\
CCTK_DECLARE(CCTK_INT,maxnphi,)&&\
CCTK_DECLARE(CCTK_INT,maxntheta,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH4,(42))&&\
CCTK_DECLARE(CCTK_INT,CCTKH5,(42))&&\
CCTK_DECLARE(CCTK_INT,CCTKH6,(42))&&\
CCTK_DECLARE(CCTK_INT,nsurfaces,)&&\
CCTK_DECLARE(CCTK_INT,CCTKH7,(42))&&\
CCTK_DECLARE(CCTK_INT,symmetric_x,(42))&&\
CCTK_DECLARE(CCTK_INT,symmetric_y,(42))&&\
CCTK_DECLARE(CCTK_INT,symmetric_z,(42))&&\
CCTK_DECLARE(CCTK_INT,CCTKH8,)&&\
COMMON /SPHERICALSURFACErest/CCTKH2, CCTKH1, CCTKH3, CCTKH0, maxnphi, maxntheta, CCTKH4, CCTKH5, CCTKH6, nsurfaces, CCTKH7, symmetric_x, symmetric_y, symmetric_z, CCTKH8&&\

