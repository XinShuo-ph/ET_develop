#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL ahf_findaftertime;
  CCTK_REAL ahf_flowa;
  CCTK_REAL ahf_flowb;
  CCTK_REAL ahf_flowc;
  CCTK_REAL ahf_flowh;
  CCTK_REAL ahf_flown;
  CCTK_REAL ahf_flowtol;
  CCTK_REAL ahf_l0_guess;
  CCTK_REAL ahf_l10_guess;
  CCTK_REAL ahf_l12_guess;
  CCTK_REAL ahf_l14_guess;
  CCTK_REAL ahf_l16_guess;
  CCTK_REAL ahf_l18_guess;
  CCTK_REAL ahf_l2_guess;
  CCTK_REAL ahf_l4_guess;
  CCTK_REAL ahf_l6_guess;
  CCTK_REAL ahf_l8_guess;
  CCTK_REAL ahf_mask_time;
  CCTK_REAL ahf_maskshrink;
  CCTK_REAL ahf_maxchange;
  CCTK_REAL ahf_minchange;
  CCTK_REAL ahf_r0;
  CCTK_REAL ahf_r0_0;
  CCTK_REAL ahf_r0_1;
  CCTK_REAL ahf_r0_2;
  CCTK_REAL ahf_shiftcoeff;
  CCTK_REAL ahf_tol;
  CCTK_REAL ahf_xc;
  CCTK_REAL ahf_xc_0;
  CCTK_REAL ahf_xc_1;
  CCTK_REAL ahf_xc_2;
  CCTK_REAL ahf_yc;
  CCTK_REAL ahf_yc_0;
  CCTK_REAL ahf_yc_1;
  CCTK_REAL ahf_yc_2;
  CCTK_REAL ahf_zc;
  CCTK_REAL ahf_zc_0;
  CCTK_REAL ahf_zc_1;
  CCTK_REAL ahf_zc_2;
  CCTK_REAL trapped_surface_delta;
  const char * ahf_mask;
  const char * ahf_masktype;
  const char * ahf_octant;
  const char * interpolation_operator;
  CCTK_INT ahf_1Doutput;
  CCTK_INT ahf_2Doutput;
  CCTK_INT ahf_3Doutput;
  CCTK_INT ahf_HDF5output;
  CCTK_INT ahf_ReportAlways;
  CCTK_INT ahf_areamap;
  CCTK_INT ahf_cartoon;
  CCTK_INT ahf_find3;
  CCTK_INT ahf_findafter;
  CCTK_INT ahf_findevery;
  CCTK_INT ahf_flow;
  CCTK_INT ahf_flowiter;
  CCTK_INT ahf_gaussout;
  CCTK_INT ahf_guess_absmin;
  CCTK_INT ahf_guessold;
  CCTK_INT ahf_guessverbose;
  CCTK_INT ahf_inner;
  CCTK_INT ahf_lmax;
  CCTK_INT ahf_logfile;
  CCTK_INT ahf_manual_guess;
  CCTK_INT ahf_mask_0;
  CCTK_INT ahf_mask_1;
  CCTK_INT ahf_mask_2;
  CCTK_INT ahf_maskbuffer;
  CCTK_INT ahf_maxiter;
  CCTK_INT ahf_minarea;
  CCTK_INT ahf_nn0;
  CCTK_INT ahf_nn2;
  CCTK_INT ahf_nphi;
  CCTK_INT ahf_ntheta;
  CCTK_INT ahf_offset;
  CCTK_INT ahf_phi;
  CCTK_INT ahf_refx;
  CCTK_INT ahf_refy;
  CCTK_INT ahf_refz;
  CCTK_INT ahf_sloppyguess;
  CCTK_INT ahf_trapped_surface;
  CCTK_INT ahf_verbose;
  CCTK_INT ahf_veryverbose;
  CCTK_INT ahf_wander;
  CCTK_INT horizon_to_announce_centroid;
  CCTK_INT horizon_to_output_centroid;
  CCTK_INT interpolation_order;
} PRIVATE_AHFINDER_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_AHFINDER_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_findaftertime, CCTK_PARAMETER__AHFINDER__ahf_findaftertime); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_flowa, CCTK_PARAMETER__AHFINDER__ahf_flowa); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_flowb, CCTK_PARAMETER__AHFINDER__ahf_flowb); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_flowc, CCTK_PARAMETER__AHFINDER__ahf_flowc); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_flowh, CCTK_PARAMETER__AHFINDER__ahf_flowh); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_flown, CCTK_PARAMETER__AHFINDER__ahf_flown); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_flowtol, CCTK_PARAMETER__AHFINDER__ahf_flowtol); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l0_guess, CCTK_PARAMETER__AHFINDER__ahf_l0_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l10_guess, CCTK_PARAMETER__AHFINDER__ahf_l10_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l12_guess, CCTK_PARAMETER__AHFINDER__ahf_l12_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l14_guess, CCTK_PARAMETER__AHFINDER__ahf_l14_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l16_guess, CCTK_PARAMETER__AHFINDER__ahf_l16_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l18_guess, CCTK_PARAMETER__AHFINDER__ahf_l18_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l2_guess, CCTK_PARAMETER__AHFINDER__ahf_l2_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l4_guess, CCTK_PARAMETER__AHFINDER__ahf_l4_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l6_guess, CCTK_PARAMETER__AHFINDER__ahf_l6_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_l8_guess, CCTK_PARAMETER__AHFINDER__ahf_l8_guess); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_mask_time, CCTK_PARAMETER__AHFINDER__ahf_mask_time); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_maskshrink, CCTK_PARAMETER__AHFINDER__ahf_maskshrink); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_maxchange, CCTK_PARAMETER__AHFINDER__ahf_maxchange); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_minchange, CCTK_PARAMETER__AHFINDER__ahf_minchange); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_r0, CCTK_PARAMETER__AHFINDER__ahf_r0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_r0_0, CCTK_PARAMETER__AHFINDER__ahf_r0_0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_r0_1, CCTK_PARAMETER__AHFINDER__ahf_r0_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_r0_2, CCTK_PARAMETER__AHFINDER__ahf_r0_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_shiftcoeff, CCTK_PARAMETER__AHFINDER__ahf_shiftcoeff); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_tol, CCTK_PARAMETER__AHFINDER__ahf_tol); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_xc, CCTK_PARAMETER__AHFINDER__ahf_xc); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_xc_0, CCTK_PARAMETER__AHFINDER__ahf_xc_0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_xc_1, CCTK_PARAMETER__AHFINDER__ahf_xc_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_xc_2, CCTK_PARAMETER__AHFINDER__ahf_xc_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_yc, CCTK_PARAMETER__AHFINDER__ahf_yc); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_yc_0, CCTK_PARAMETER__AHFINDER__ahf_yc_0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_yc_1, CCTK_PARAMETER__AHFINDER__ahf_yc_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_yc_2, CCTK_PARAMETER__AHFINDER__ahf_yc_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_zc, CCTK_PARAMETER__AHFINDER__ahf_zc); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_zc_0, CCTK_PARAMETER__AHFINDER__ahf_zc_0); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_zc_1, CCTK_PARAMETER__AHFINDER__ahf_zc_1); \
  CCTK_DECLARE_INIT (CCTK_REAL const, ahf_zc_2, CCTK_PARAMETER__AHFINDER__ahf_zc_2); \
  CCTK_DECLARE_INIT (CCTK_REAL const, trapped_surface_delta, CCTK_PARAMETER__AHFINDER__trapped_surface_delta); \
  CCTK_DECLARE_INIT (const char * const, ahf_mask, CCTK_PARAMETER__AHFINDER__ahf_mask); \
  CCTK_DECLARE_INIT (const char * const, ahf_masktype, CCTK_PARAMETER__AHFINDER__ahf_masktype); \
  CCTK_DECLARE_INIT (const char * const, ahf_octant, CCTK_PARAMETER__AHFINDER__ahf_octant); \
  CCTK_DECLARE_INIT (const char * const, interpolation_operator, CCTK_PARAMETER__AHFINDER__interpolation_operator); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_1Doutput, CCTK_PARAMETER__AHFINDER__ahf_1Doutput); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_2Doutput, CCTK_PARAMETER__AHFINDER__ahf_2Doutput); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_3Doutput, CCTK_PARAMETER__AHFINDER__ahf_3Doutput); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_HDF5output, CCTK_PARAMETER__AHFINDER__ahf_HDF5output); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_ReportAlways, CCTK_PARAMETER__AHFINDER__ahf_ReportAlways); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_areamap, CCTK_PARAMETER__AHFINDER__ahf_areamap); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_cartoon, CCTK_PARAMETER__AHFINDER__ahf_cartoon); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_find3, CCTK_PARAMETER__AHFINDER__ahf_find3); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_findafter, CCTK_PARAMETER__AHFINDER__ahf_findafter); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_findevery, CCTK_PARAMETER__AHFINDER__ahf_findevery); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_flow, CCTK_PARAMETER__AHFINDER__ahf_flow); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_flowiter, CCTK_PARAMETER__AHFINDER__ahf_flowiter); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_gaussout, CCTK_PARAMETER__AHFINDER__ahf_gaussout); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_guess_absmin, CCTK_PARAMETER__AHFINDER__ahf_guess_absmin); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_guessold, CCTK_PARAMETER__AHFINDER__ahf_guessold); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_guessverbose, CCTK_PARAMETER__AHFINDER__ahf_guessverbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_inner, CCTK_PARAMETER__AHFINDER__ahf_inner); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_lmax, CCTK_PARAMETER__AHFINDER__ahf_lmax); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_logfile, CCTK_PARAMETER__AHFINDER__ahf_logfile); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_manual_guess, CCTK_PARAMETER__AHFINDER__ahf_manual_guess); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_mask_0, CCTK_PARAMETER__AHFINDER__ahf_mask_0); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_mask_1, CCTK_PARAMETER__AHFINDER__ahf_mask_1); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_mask_2, CCTK_PARAMETER__AHFINDER__ahf_mask_2); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_maskbuffer, CCTK_PARAMETER__AHFINDER__ahf_maskbuffer); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_maxiter, CCTK_PARAMETER__AHFINDER__ahf_maxiter); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_minarea, CCTK_PARAMETER__AHFINDER__ahf_minarea); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_nn0, CCTK_PARAMETER__AHFINDER__ahf_nn0); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_nn2, CCTK_PARAMETER__AHFINDER__ahf_nn2); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_nphi, CCTK_PARAMETER__AHFINDER__ahf_nphi); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_ntheta, CCTK_PARAMETER__AHFINDER__ahf_ntheta); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_offset, CCTK_PARAMETER__AHFINDER__ahf_offset); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_phi, CCTK_PARAMETER__AHFINDER__ahf_phi); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_refx, CCTK_PARAMETER__AHFINDER__ahf_refx); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_refy, CCTK_PARAMETER__AHFINDER__ahf_refy); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_refz, CCTK_PARAMETER__AHFINDER__ahf_refz); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_sloppyguess, CCTK_PARAMETER__AHFINDER__ahf_sloppyguess); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_trapped_surface, CCTK_PARAMETER__AHFINDER__ahf_trapped_surface); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_verbose, CCTK_PARAMETER__AHFINDER__ahf_verbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_veryverbose, CCTK_PARAMETER__AHFINDER__ahf_veryverbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, ahf_wander, CCTK_PARAMETER__AHFINDER__ahf_wander); \
  CCTK_DECLARE_INIT (CCTK_INT const, horizon_to_announce_centroid, CCTK_PARAMETER__AHFINDER__horizon_to_announce_centroid); \
  CCTK_DECLARE_INIT (CCTK_INT const, horizon_to_output_centroid, CCTK_PARAMETER__AHFINDER__horizon_to_output_centroid); \
  CCTK_DECLARE_INIT (CCTK_INT const, interpolation_order, CCTK_PARAMETER__AHFINDER__interpolation_order); \


#ifndef CCTK_PARAMETER__AHFINDER__ahf_findaftertime
#  define CCTK_PARAMETER__AHFINDER__ahf_findaftertime PRIVATE_AHFINDER_STRUCT.ahf_findaftertime
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_flowa
#  define CCTK_PARAMETER__AHFINDER__ahf_flowa PRIVATE_AHFINDER_STRUCT.ahf_flowa
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_flowb
#  define CCTK_PARAMETER__AHFINDER__ahf_flowb PRIVATE_AHFINDER_STRUCT.ahf_flowb
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_flowc
#  define CCTK_PARAMETER__AHFINDER__ahf_flowc PRIVATE_AHFINDER_STRUCT.ahf_flowc
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_flowh
#  define CCTK_PARAMETER__AHFINDER__ahf_flowh PRIVATE_AHFINDER_STRUCT.ahf_flowh
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_flown
#  define CCTK_PARAMETER__AHFINDER__ahf_flown PRIVATE_AHFINDER_STRUCT.ahf_flown
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_flowtol
#  define CCTK_PARAMETER__AHFINDER__ahf_flowtol PRIVATE_AHFINDER_STRUCT.ahf_flowtol
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l0_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l0_guess PRIVATE_AHFINDER_STRUCT.ahf_l0_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l10_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l10_guess PRIVATE_AHFINDER_STRUCT.ahf_l10_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l12_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l12_guess PRIVATE_AHFINDER_STRUCT.ahf_l12_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l14_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l14_guess PRIVATE_AHFINDER_STRUCT.ahf_l14_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l16_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l16_guess PRIVATE_AHFINDER_STRUCT.ahf_l16_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l18_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l18_guess PRIVATE_AHFINDER_STRUCT.ahf_l18_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l2_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l2_guess PRIVATE_AHFINDER_STRUCT.ahf_l2_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l4_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l4_guess PRIVATE_AHFINDER_STRUCT.ahf_l4_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l6_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l6_guess PRIVATE_AHFINDER_STRUCT.ahf_l6_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_l8_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_l8_guess PRIVATE_AHFINDER_STRUCT.ahf_l8_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_mask_time
#  define CCTK_PARAMETER__AHFINDER__ahf_mask_time PRIVATE_AHFINDER_STRUCT.ahf_mask_time
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_maskshrink
#  define CCTK_PARAMETER__AHFINDER__ahf_maskshrink PRIVATE_AHFINDER_STRUCT.ahf_maskshrink
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_maxchange
#  define CCTK_PARAMETER__AHFINDER__ahf_maxchange PRIVATE_AHFINDER_STRUCT.ahf_maxchange
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_minchange
#  define CCTK_PARAMETER__AHFINDER__ahf_minchange PRIVATE_AHFINDER_STRUCT.ahf_minchange
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_r0
#  define CCTK_PARAMETER__AHFINDER__ahf_r0 PRIVATE_AHFINDER_STRUCT.ahf_r0
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_r0_0
#  define CCTK_PARAMETER__AHFINDER__ahf_r0_0 PRIVATE_AHFINDER_STRUCT.ahf_r0_0
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_r0_1
#  define CCTK_PARAMETER__AHFINDER__ahf_r0_1 PRIVATE_AHFINDER_STRUCT.ahf_r0_1
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_r0_2
#  define CCTK_PARAMETER__AHFINDER__ahf_r0_2 PRIVATE_AHFINDER_STRUCT.ahf_r0_2
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_shiftcoeff
#  define CCTK_PARAMETER__AHFINDER__ahf_shiftcoeff PRIVATE_AHFINDER_STRUCT.ahf_shiftcoeff
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_tol
#  define CCTK_PARAMETER__AHFINDER__ahf_tol PRIVATE_AHFINDER_STRUCT.ahf_tol
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_xc
#  define CCTK_PARAMETER__AHFINDER__ahf_xc PRIVATE_AHFINDER_STRUCT.ahf_xc
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_xc_0
#  define CCTK_PARAMETER__AHFINDER__ahf_xc_0 PRIVATE_AHFINDER_STRUCT.ahf_xc_0
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_xc_1
#  define CCTK_PARAMETER__AHFINDER__ahf_xc_1 PRIVATE_AHFINDER_STRUCT.ahf_xc_1
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_xc_2
#  define CCTK_PARAMETER__AHFINDER__ahf_xc_2 PRIVATE_AHFINDER_STRUCT.ahf_xc_2
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_yc
#  define CCTK_PARAMETER__AHFINDER__ahf_yc PRIVATE_AHFINDER_STRUCT.ahf_yc
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_yc_0
#  define CCTK_PARAMETER__AHFINDER__ahf_yc_0 PRIVATE_AHFINDER_STRUCT.ahf_yc_0
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_yc_1
#  define CCTK_PARAMETER__AHFINDER__ahf_yc_1 PRIVATE_AHFINDER_STRUCT.ahf_yc_1
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_yc_2
#  define CCTK_PARAMETER__AHFINDER__ahf_yc_2 PRIVATE_AHFINDER_STRUCT.ahf_yc_2
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_zc
#  define CCTK_PARAMETER__AHFINDER__ahf_zc PRIVATE_AHFINDER_STRUCT.ahf_zc
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_zc_0
#  define CCTK_PARAMETER__AHFINDER__ahf_zc_0 PRIVATE_AHFINDER_STRUCT.ahf_zc_0
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_zc_1
#  define CCTK_PARAMETER__AHFINDER__ahf_zc_1 PRIVATE_AHFINDER_STRUCT.ahf_zc_1
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_zc_2
#  define CCTK_PARAMETER__AHFINDER__ahf_zc_2 PRIVATE_AHFINDER_STRUCT.ahf_zc_2
#endif
#ifndef CCTK_PARAMETER__AHFINDER__trapped_surface_delta
#  define CCTK_PARAMETER__AHFINDER__trapped_surface_delta PRIVATE_AHFINDER_STRUCT.trapped_surface_delta
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_mask
#  define CCTK_PARAMETER__AHFINDER__ahf_mask PRIVATE_AHFINDER_STRUCT.ahf_mask
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_masktype
#  define CCTK_PARAMETER__AHFINDER__ahf_masktype PRIVATE_AHFINDER_STRUCT.ahf_masktype
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_octant
#  define CCTK_PARAMETER__AHFINDER__ahf_octant PRIVATE_AHFINDER_STRUCT.ahf_octant
#endif
#ifndef CCTK_PARAMETER__AHFINDER__interpolation_operator
#  define CCTK_PARAMETER__AHFINDER__interpolation_operator PRIVATE_AHFINDER_STRUCT.interpolation_operator
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_1Doutput
#  define CCTK_PARAMETER__AHFINDER__ahf_1Doutput PRIVATE_AHFINDER_STRUCT.ahf_1Doutput
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_2Doutput
#  define CCTK_PARAMETER__AHFINDER__ahf_2Doutput PRIVATE_AHFINDER_STRUCT.ahf_2Doutput
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_3Doutput
#  define CCTK_PARAMETER__AHFINDER__ahf_3Doutput PRIVATE_AHFINDER_STRUCT.ahf_3Doutput
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_HDF5output
#  define CCTK_PARAMETER__AHFINDER__ahf_HDF5output PRIVATE_AHFINDER_STRUCT.ahf_HDF5output
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_ReportAlways
#  define CCTK_PARAMETER__AHFINDER__ahf_ReportAlways PRIVATE_AHFINDER_STRUCT.ahf_ReportAlways
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_areamap
#  define CCTK_PARAMETER__AHFINDER__ahf_areamap PRIVATE_AHFINDER_STRUCT.ahf_areamap
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_cartoon
#  define CCTK_PARAMETER__AHFINDER__ahf_cartoon PRIVATE_AHFINDER_STRUCT.ahf_cartoon
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_find3
#  define CCTK_PARAMETER__AHFINDER__ahf_find3 PRIVATE_AHFINDER_STRUCT.ahf_find3
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_findafter
#  define CCTK_PARAMETER__AHFINDER__ahf_findafter PRIVATE_AHFINDER_STRUCT.ahf_findafter
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_findevery
#  define CCTK_PARAMETER__AHFINDER__ahf_findevery PRIVATE_AHFINDER_STRUCT.ahf_findevery
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_flow
#  define CCTK_PARAMETER__AHFINDER__ahf_flow PRIVATE_AHFINDER_STRUCT.ahf_flow
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_flowiter
#  define CCTK_PARAMETER__AHFINDER__ahf_flowiter PRIVATE_AHFINDER_STRUCT.ahf_flowiter
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_gaussout
#  define CCTK_PARAMETER__AHFINDER__ahf_gaussout PRIVATE_AHFINDER_STRUCT.ahf_gaussout
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_guess_absmin
#  define CCTK_PARAMETER__AHFINDER__ahf_guess_absmin PRIVATE_AHFINDER_STRUCT.ahf_guess_absmin
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_guessold
#  define CCTK_PARAMETER__AHFINDER__ahf_guessold PRIVATE_AHFINDER_STRUCT.ahf_guessold
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_guessverbose
#  define CCTK_PARAMETER__AHFINDER__ahf_guessverbose PRIVATE_AHFINDER_STRUCT.ahf_guessverbose
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_inner
#  define CCTK_PARAMETER__AHFINDER__ahf_inner PRIVATE_AHFINDER_STRUCT.ahf_inner
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_lmax
#  define CCTK_PARAMETER__AHFINDER__ahf_lmax PRIVATE_AHFINDER_STRUCT.ahf_lmax
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_logfile
#  define CCTK_PARAMETER__AHFINDER__ahf_logfile PRIVATE_AHFINDER_STRUCT.ahf_logfile
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_manual_guess
#  define CCTK_PARAMETER__AHFINDER__ahf_manual_guess PRIVATE_AHFINDER_STRUCT.ahf_manual_guess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_mask_0
#  define CCTK_PARAMETER__AHFINDER__ahf_mask_0 PRIVATE_AHFINDER_STRUCT.ahf_mask_0
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_mask_1
#  define CCTK_PARAMETER__AHFINDER__ahf_mask_1 PRIVATE_AHFINDER_STRUCT.ahf_mask_1
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_mask_2
#  define CCTK_PARAMETER__AHFINDER__ahf_mask_2 PRIVATE_AHFINDER_STRUCT.ahf_mask_2
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_maskbuffer
#  define CCTK_PARAMETER__AHFINDER__ahf_maskbuffer PRIVATE_AHFINDER_STRUCT.ahf_maskbuffer
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_maxiter
#  define CCTK_PARAMETER__AHFINDER__ahf_maxiter PRIVATE_AHFINDER_STRUCT.ahf_maxiter
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_minarea
#  define CCTK_PARAMETER__AHFINDER__ahf_minarea PRIVATE_AHFINDER_STRUCT.ahf_minarea
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_nn0
#  define CCTK_PARAMETER__AHFINDER__ahf_nn0 PRIVATE_AHFINDER_STRUCT.ahf_nn0
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_nn2
#  define CCTK_PARAMETER__AHFINDER__ahf_nn2 PRIVATE_AHFINDER_STRUCT.ahf_nn2
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_nphi
#  define CCTK_PARAMETER__AHFINDER__ahf_nphi PRIVATE_AHFINDER_STRUCT.ahf_nphi
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_ntheta
#  define CCTK_PARAMETER__AHFINDER__ahf_ntheta PRIVATE_AHFINDER_STRUCT.ahf_ntheta
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_offset
#  define CCTK_PARAMETER__AHFINDER__ahf_offset PRIVATE_AHFINDER_STRUCT.ahf_offset
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_phi
#  define CCTK_PARAMETER__AHFINDER__ahf_phi PRIVATE_AHFINDER_STRUCT.ahf_phi
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_refx
#  define CCTK_PARAMETER__AHFINDER__ahf_refx PRIVATE_AHFINDER_STRUCT.ahf_refx
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_refy
#  define CCTK_PARAMETER__AHFINDER__ahf_refy PRIVATE_AHFINDER_STRUCT.ahf_refy
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_refz
#  define CCTK_PARAMETER__AHFINDER__ahf_refz PRIVATE_AHFINDER_STRUCT.ahf_refz
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_sloppyguess
#  define CCTK_PARAMETER__AHFINDER__ahf_sloppyguess PRIVATE_AHFINDER_STRUCT.ahf_sloppyguess
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_trapped_surface
#  define CCTK_PARAMETER__AHFINDER__ahf_trapped_surface PRIVATE_AHFINDER_STRUCT.ahf_trapped_surface
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_verbose
#  define CCTK_PARAMETER__AHFINDER__ahf_verbose PRIVATE_AHFINDER_STRUCT.ahf_verbose
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_veryverbose
#  define CCTK_PARAMETER__AHFINDER__ahf_veryverbose PRIVATE_AHFINDER_STRUCT.ahf_veryverbose
#endif
#ifndef CCTK_PARAMETER__AHFINDER__ahf_wander
#  define CCTK_PARAMETER__AHFINDER__ahf_wander PRIVATE_AHFINDER_STRUCT.ahf_wander
#endif
#ifndef CCTK_PARAMETER__AHFINDER__horizon_to_announce_centroid
#  define CCTK_PARAMETER__AHFINDER__horizon_to_announce_centroid PRIVATE_AHFINDER_STRUCT.horizon_to_announce_centroid
#endif
#ifndef CCTK_PARAMETER__AHFINDER__horizon_to_output_centroid
#  define CCTK_PARAMETER__AHFINDER__horizon_to_output_centroid PRIVATE_AHFINDER_STRUCT.horizon_to_output_centroid
#endif
#ifndef CCTK_PARAMETER__AHFINDER__interpolation_order
#  define CCTK_PARAMETER__AHFINDER__interpolation_order PRIVATE_AHFINDER_STRUCT.interpolation_order
#endif

