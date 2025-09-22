#define DECLARE_CCTK_PARAMETERS \
CCTK_DECLARE(CCTK_REAL,override_Rin,)&&\
CCTK_DECLARE(CCTK_REAL,override_Rout,)&&\
CCTK_DECLARE(CCTK_REAL,r_extract,)&&\
CCTK_DECLARE(CCTK_STRING,metric_data_filename,)&&\
CCTK_DECLARE(CCTK_INT,order,)&&\
CCTK_DECLARE(CCTK_INT,override_extraction_parameters,)&&\
CCTK_DECLARE(CCTK_INT,override_na,)&&\
CCTK_DECLARE(CCTK_INT,override_nn,)&&\
CCTK_DECLARE(CCTK_INT,override_spin,)&&\
CCTK_DECLARE(CCTK_INT,time_derivative_in_file,)&&\
COMMON /SphericalHarmonicReconpriv/override_Rin, override_Rout, r_extract, metric_data_filename, order, override_extraction_parameters, override_na, override_nn, override_spin, time_derivative_in_file&&\

