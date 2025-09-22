#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL eps_omega;
  CCTK_INT DEBUG_skip_BondiNews;
  CCTK_INT Jl_deriv_order;
  CCTK_INT NewsSpinWeight;
  CCTK_INT Ylm_at_Scri;
  CCTK_INT compute_lin_strain;
  CCTK_INT debug_output;
  CCTK_INT filter_news;
  CCTK_INT filter_omega;
  CCTK_INT filter_scri_fields;
  CCTK_INT first_order_scheme;
  CCTK_INT interp_to_constant_uBondi;
  CCTK_INT l_YlmScri;
  CCTK_INT linearized_inertial_frame;
  CCTK_INT m_YlmScri;
  CCTK_INT mask_NewsB;
  CCTK_INT mask_Psi4;
  CCTK_INT max_timelevels;
  CCTK_INT news_interp_order;
  CCTK_INT use_linearized_omega;
  CCTK_INT write_spherical_harmonics;
} PRIVATE_NULLNEWS_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_NULLNEWS_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, eps_omega, CCTK_PARAMETER__NULLNEWS__eps_omega); \
  CCTK_DECLARE_INIT (CCTK_INT const, DEBUG_skip_BondiNews, CCTK_PARAMETER__NULLNEWS__DEBUG_skip_BondiNews); \
  CCTK_DECLARE_INIT (CCTK_INT const, Jl_deriv_order, CCTK_PARAMETER__NULLNEWS__Jl_deriv_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, NewsSpinWeight, CCTK_PARAMETER__NULLNEWS__NewsSpinWeight); \
  CCTK_DECLARE_INIT (CCTK_INT const, Ylm_at_Scri, CCTK_PARAMETER__NULLNEWS__Ylm_at_Scri); \
  CCTK_DECLARE_INIT (CCTK_INT const, compute_lin_strain, CCTK_PARAMETER__NULLNEWS__compute_lin_strain); \
  CCTK_DECLARE_INIT (CCTK_INT const, debug_output, CCTK_PARAMETER__NULLNEWS__debug_output); \
  CCTK_DECLARE_INIT (CCTK_INT const, filter_news, CCTK_PARAMETER__NULLNEWS__filter_news); \
  CCTK_DECLARE_INIT (CCTK_INT const, filter_omega, CCTK_PARAMETER__NULLNEWS__filter_omega); \
  CCTK_DECLARE_INIT (CCTK_INT const, filter_scri_fields, CCTK_PARAMETER__NULLNEWS__filter_scri_fields); \
  CCTK_DECLARE_INIT (CCTK_INT const, first_order_scheme, CCTK_PARAMETER__NULLNEWS__first_order_scheme); \
  CCTK_DECLARE_INIT (CCTK_INT const, interp_to_constant_uBondi, CCTK_PARAMETER__NULLNEWS__interp_to_constant_uBondi); \
  CCTK_DECLARE_INIT (CCTK_INT const, l_YlmScri, CCTK_PARAMETER__NULLNEWS__l_YlmScri); \
  CCTK_DECLARE_INIT (CCTK_INT const, linearized_inertial_frame, CCTK_PARAMETER__NULLNEWS__linearized_inertial_frame); \
  CCTK_DECLARE_INIT (CCTK_INT const, m_YlmScri, CCTK_PARAMETER__NULLNEWS__m_YlmScri); \
  CCTK_DECLARE_INIT (CCTK_INT const, mask_NewsB, CCTK_PARAMETER__NULLNEWS__mask_NewsB); \
  CCTK_DECLARE_INIT (CCTK_INT const, mask_Psi4, CCTK_PARAMETER__NULLNEWS__mask_Psi4); \
  CCTK_DECLARE_INIT (CCTK_INT const, max_timelevels, CCTK_PARAMETER__NULLNEWS__max_timelevels); \
  CCTK_DECLARE_INIT (CCTK_INT const, news_interp_order, CCTK_PARAMETER__NULLNEWS__news_interp_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, use_linearized_omega, CCTK_PARAMETER__NULLNEWS__use_linearized_omega); \
  CCTK_DECLARE_INIT (CCTK_INT const, write_spherical_harmonics, CCTK_PARAMETER__NULLNEWS__write_spherical_harmonics); \


#ifndef CCTK_PARAMETER__NULLNEWS__eps_omega
#  define CCTK_PARAMETER__NULLNEWS__eps_omega PRIVATE_NULLNEWS_STRUCT.eps_omega
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__DEBUG_skip_BondiNews
#  define CCTK_PARAMETER__NULLNEWS__DEBUG_skip_BondiNews PRIVATE_NULLNEWS_STRUCT.DEBUG_skip_BondiNews
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__Jl_deriv_order
#  define CCTK_PARAMETER__NULLNEWS__Jl_deriv_order PRIVATE_NULLNEWS_STRUCT.Jl_deriv_order
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__NewsSpinWeight
#  define CCTK_PARAMETER__NULLNEWS__NewsSpinWeight PRIVATE_NULLNEWS_STRUCT.NewsSpinWeight
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__Ylm_at_Scri
#  define CCTK_PARAMETER__NULLNEWS__Ylm_at_Scri PRIVATE_NULLNEWS_STRUCT.Ylm_at_Scri
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__compute_lin_strain
#  define CCTK_PARAMETER__NULLNEWS__compute_lin_strain PRIVATE_NULLNEWS_STRUCT.compute_lin_strain
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__debug_output
#  define CCTK_PARAMETER__NULLNEWS__debug_output PRIVATE_NULLNEWS_STRUCT.debug_output
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__filter_news
#  define CCTK_PARAMETER__NULLNEWS__filter_news PRIVATE_NULLNEWS_STRUCT.filter_news
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__filter_omega
#  define CCTK_PARAMETER__NULLNEWS__filter_omega PRIVATE_NULLNEWS_STRUCT.filter_omega
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__filter_scri_fields
#  define CCTK_PARAMETER__NULLNEWS__filter_scri_fields PRIVATE_NULLNEWS_STRUCT.filter_scri_fields
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__first_order_scheme
#  define CCTK_PARAMETER__NULLNEWS__first_order_scheme PRIVATE_NULLNEWS_STRUCT.first_order_scheme
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__interp_to_constant_uBondi
#  define CCTK_PARAMETER__NULLNEWS__interp_to_constant_uBondi PRIVATE_NULLNEWS_STRUCT.interp_to_constant_uBondi
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__l_YlmScri
#  define CCTK_PARAMETER__NULLNEWS__l_YlmScri PRIVATE_NULLNEWS_STRUCT.l_YlmScri
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__linearized_inertial_frame
#  define CCTK_PARAMETER__NULLNEWS__linearized_inertial_frame PRIVATE_NULLNEWS_STRUCT.linearized_inertial_frame
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__m_YlmScri
#  define CCTK_PARAMETER__NULLNEWS__m_YlmScri PRIVATE_NULLNEWS_STRUCT.m_YlmScri
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__mask_NewsB
#  define CCTK_PARAMETER__NULLNEWS__mask_NewsB PRIVATE_NULLNEWS_STRUCT.mask_NewsB
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__mask_Psi4
#  define CCTK_PARAMETER__NULLNEWS__mask_Psi4 PRIVATE_NULLNEWS_STRUCT.mask_Psi4
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__max_timelevels
#  define CCTK_PARAMETER__NULLNEWS__max_timelevels PRIVATE_NULLNEWS_STRUCT.max_timelevels
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__news_interp_order
#  define CCTK_PARAMETER__NULLNEWS__news_interp_order PRIVATE_NULLNEWS_STRUCT.news_interp_order
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__use_linearized_omega
#  define CCTK_PARAMETER__NULLNEWS__use_linearized_omega PRIVATE_NULLNEWS_STRUCT.use_linearized_omega
#endif
#ifndef CCTK_PARAMETER__NULLNEWS__write_spherical_harmonics
#  define CCTK_PARAMETER__NULLNEWS__write_spherical_harmonics PRIVATE_NULLNEWS_STRUCT.write_spherical_harmonics
#endif

