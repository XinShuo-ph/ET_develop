#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL amplitude;
  CCTK_REAL wavecenter;
  CCTK_REAL wavelength;
  CCTK_REAL wavephi;
  CCTK_REAL wavepulse;
  CCTK_REAL wavetheta;
  const char * packet;
  const char * parity;
  const char * teuk_no_vee;
  const char * wavesgoing;
  CCTK_INT mvalue;
} PRIVATE_IDLINEARWAVES_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_IDLINEARWAVES_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, amplitude, CCTK_PARAMETER__IDLINEARWAVES__amplitude); \
  CCTK_DECLARE_INIT (CCTK_REAL const, wavecenter, CCTK_PARAMETER__IDLINEARWAVES__wavecenter); \
  CCTK_DECLARE_INIT (CCTK_REAL const, wavelength, CCTK_PARAMETER__IDLINEARWAVES__wavelength); \
  CCTK_DECLARE_INIT (CCTK_REAL const, wavephi, CCTK_PARAMETER__IDLINEARWAVES__wavephi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, wavepulse, CCTK_PARAMETER__IDLINEARWAVES__wavepulse); \
  CCTK_DECLARE_INIT (CCTK_REAL const, wavetheta, CCTK_PARAMETER__IDLINEARWAVES__wavetheta); \
  CCTK_DECLARE_INIT (const char * const, packet, CCTK_PARAMETER__IDLINEARWAVES__packet); \
  CCTK_DECLARE_INIT (const char * const, parity, CCTK_PARAMETER__IDLINEARWAVES__parity); \
  CCTK_DECLARE_INIT (const char * const, teuk_no_vee, CCTK_PARAMETER__IDLINEARWAVES__teuk_no_vee); \
  CCTK_DECLARE_INIT (const char * const, wavesgoing, CCTK_PARAMETER__IDLINEARWAVES__wavesgoing); \
  CCTK_DECLARE_INIT (CCTK_INT const, mvalue, CCTK_PARAMETER__IDLINEARWAVES__mvalue); \


#ifndef CCTK_PARAMETER__IDLINEARWAVES__amplitude
#  define CCTK_PARAMETER__IDLINEARWAVES__amplitude PRIVATE_IDLINEARWAVES_STRUCT.amplitude
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__wavecenter
#  define CCTK_PARAMETER__IDLINEARWAVES__wavecenter PRIVATE_IDLINEARWAVES_STRUCT.wavecenter
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__wavelength
#  define CCTK_PARAMETER__IDLINEARWAVES__wavelength PRIVATE_IDLINEARWAVES_STRUCT.wavelength
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__wavephi
#  define CCTK_PARAMETER__IDLINEARWAVES__wavephi PRIVATE_IDLINEARWAVES_STRUCT.wavephi
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__wavepulse
#  define CCTK_PARAMETER__IDLINEARWAVES__wavepulse PRIVATE_IDLINEARWAVES_STRUCT.wavepulse
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__wavetheta
#  define CCTK_PARAMETER__IDLINEARWAVES__wavetheta PRIVATE_IDLINEARWAVES_STRUCT.wavetheta
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__packet
#  define CCTK_PARAMETER__IDLINEARWAVES__packet PRIVATE_IDLINEARWAVES_STRUCT.packet
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__parity
#  define CCTK_PARAMETER__IDLINEARWAVES__parity PRIVATE_IDLINEARWAVES_STRUCT.parity
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__teuk_no_vee
#  define CCTK_PARAMETER__IDLINEARWAVES__teuk_no_vee PRIVATE_IDLINEARWAVES_STRUCT.teuk_no_vee
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__wavesgoing
#  define CCTK_PARAMETER__IDLINEARWAVES__wavesgoing PRIVATE_IDLINEARWAVES_STRUCT.wavesgoing
#endif
#ifndef CCTK_PARAMETER__IDLINEARWAVES__mvalue
#  define CCTK_PARAMETER__IDLINEARWAVES__mvalue PRIVATE_IDLINEARWAVES_STRUCT.mvalue
#endif

