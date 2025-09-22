#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,auto_res_ratio,(42))&&\
CCTK_DECLARE(CCTK_STRING,auto_res_grid,(42))&&\
CCTK_DECLARE(CCTK_STRING,name,(42))&&\
CCTK_DECLARE(CCTK_INT,auto_res,(42))&&\
CCTK_DECLARE(CCTK_INT,maxnphi,)&&\
CCTK_DECLARE(CCTK_INT,maxntheta,)&&\
CCTK_DECLARE(CCTK_INT,nghostsphi,(42))&&\
CCTK_DECLARE(CCTK_INT,nghoststheta,(42))&&\
CCTK_DECLARE(CCTK_INT,nphi,(42))&&\
CCTK_DECLARE(CCTK_INT,nsurfaces,)&&\
CCTK_DECLARE(CCTK_INT,ntheta,(42))&&\
CCTK_DECLARE(CCTK_INT,symmetric_x,(42))&&\
CCTK_DECLARE(CCTK_INT,symmetric_y,(42))&&\
CCTK_DECLARE(CCTK_INT,symmetric_z,(42))&&\
CCTK_DECLARE(CCTK_INT,verbose,)&&\
COMMON /SphericalSurfacerest/auto_res_ratio, auto_res_grid, name, auto_res, maxnphi, maxntheta, nghostsphi, nghoststheta, nphi, nsurfaces, ntheta, symmetric_x, symmetric_y, symmetric_z, verbose&&\
CCTK_DECLARE(CCTK_REAL,origin_x,(42))&&\
CCTK_DECLARE(CCTK_REAL,origin_y,(42))&&\
CCTK_DECLARE(CCTK_REAL,origin_z,(42))&&\
CCTK_DECLARE(CCTK_REAL,radius,(42))&&\
CCTK_DECLARE(CCTK_REAL,radius_x,(42))&&\
CCTK_DECLARE(CCTK_REAL,radius_y,(42))&&\
CCTK_DECLARE(CCTK_REAL,radius_z,(42))&&\
CCTK_DECLARE(CCTK_INT,set_elliptic,(42))&&\
CCTK_DECLARE(CCTK_INT,set_spherical,(42))&&\
COMMON /SphericalSurfacepriv/origin_x, origin_y, origin_z, radius, radius_x, radius_y, radius_z, set_elliptic, set_spherical&&\

