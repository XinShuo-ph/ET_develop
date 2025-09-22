#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL boost_vx;
  CCTK_REAL boost_vy;
  CCTK_REAL boost_vz;
  CCTK_REAL exact_eps;
  CCTK_REAL exblend_rout;
  CCTK_REAL exblend_width;
  CCTK_REAL rotation_euler_phi;
  CCTK_REAL rotation_euler_psi;
  CCTK_REAL rotation_euler_theta;
  CCTK_REAL shift_add_x;
  CCTK_REAL shift_add_y;
  CCTK_REAL shift_add_z;
  CCTK_REAL slice_Gauss_ampl;
  CCTK_REAL slice_Gauss_width;
  const char * overwrite_boundary;
  CCTK_INT exact_order;
  CCTK_INT exblend_Ks;
  CCTK_INT exblend_gauge;
  CCTK_INT exblend_gs;
} PRIVATE_EXACT_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_EXACT_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, boost_vx, CCTK_PARAMETER__EXACT__boost_vx); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boost_vy, CCTK_PARAMETER__EXACT__boost_vy); \
  CCTK_DECLARE_INIT (CCTK_REAL const, boost_vz, CCTK_PARAMETER__EXACT__boost_vz); \
  CCTK_DECLARE_INIT (CCTK_REAL const, exact_eps, CCTK_PARAMETER__EXACT__exact_eps); \
  CCTK_DECLARE_INIT (CCTK_REAL const, exblend_rout, CCTK_PARAMETER__EXACT__exblend_rout); \
  CCTK_DECLARE_INIT (CCTK_REAL const, exblend_width, CCTK_PARAMETER__EXACT__exblend_width); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotation_euler_phi, CCTK_PARAMETER__EXACT__rotation_euler_phi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotation_euler_psi, CCTK_PARAMETER__EXACT__rotation_euler_psi); \
  CCTK_DECLARE_INIT (CCTK_REAL const, rotation_euler_theta, CCTK_PARAMETER__EXACT__rotation_euler_theta); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shift_add_x, CCTK_PARAMETER__EXACT__shift_add_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shift_add_y, CCTK_PARAMETER__EXACT__shift_add_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, shift_add_z, CCTK_PARAMETER__EXACT__shift_add_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, slice_Gauss_ampl, CCTK_PARAMETER__EXACT__slice_Gauss_ampl); \
  CCTK_DECLARE_INIT (CCTK_REAL const, slice_Gauss_width, CCTK_PARAMETER__EXACT__slice_Gauss_width); \
  CCTK_DECLARE_INIT (const char * const, overwrite_boundary, CCTK_PARAMETER__EXACT__overwrite_boundary); \
  CCTK_DECLARE_INIT (CCTK_INT const, exact_order, CCTK_PARAMETER__EXACT__exact_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, exblend_Ks, CCTK_PARAMETER__EXACT__exblend_Ks); \
  CCTK_DECLARE_INIT (CCTK_INT const, exblend_gauge, CCTK_PARAMETER__EXACT__exblend_gauge); \
  CCTK_DECLARE_INIT (CCTK_INT const, exblend_gs, CCTK_PARAMETER__EXACT__exblend_gs); \


#ifndef CCTK_PARAMETER__EXACT__boost_vx
#  define CCTK_PARAMETER__EXACT__boost_vx PRIVATE_EXACT_STRUCT.boost_vx
#endif
#ifndef CCTK_PARAMETER__EXACT__boost_vy
#  define CCTK_PARAMETER__EXACT__boost_vy PRIVATE_EXACT_STRUCT.boost_vy
#endif
#ifndef CCTK_PARAMETER__EXACT__boost_vz
#  define CCTK_PARAMETER__EXACT__boost_vz PRIVATE_EXACT_STRUCT.boost_vz
#endif
#ifndef CCTK_PARAMETER__EXACT__exact_eps
#  define CCTK_PARAMETER__EXACT__exact_eps PRIVATE_EXACT_STRUCT.exact_eps
#endif
#ifndef CCTK_PARAMETER__EXACT__exblend_rout
#  define CCTK_PARAMETER__EXACT__exblend_rout PRIVATE_EXACT_STRUCT.exblend_rout
#endif
#ifndef CCTK_PARAMETER__EXACT__exblend_width
#  define CCTK_PARAMETER__EXACT__exblend_width PRIVATE_EXACT_STRUCT.exblend_width
#endif
#ifndef CCTK_PARAMETER__EXACT__rotation_euler_phi
#  define CCTK_PARAMETER__EXACT__rotation_euler_phi PRIVATE_EXACT_STRUCT.rotation_euler_phi
#endif
#ifndef CCTK_PARAMETER__EXACT__rotation_euler_psi
#  define CCTK_PARAMETER__EXACT__rotation_euler_psi PRIVATE_EXACT_STRUCT.rotation_euler_psi
#endif
#ifndef CCTK_PARAMETER__EXACT__rotation_euler_theta
#  define CCTK_PARAMETER__EXACT__rotation_euler_theta PRIVATE_EXACT_STRUCT.rotation_euler_theta
#endif
#ifndef CCTK_PARAMETER__EXACT__shift_add_x
#  define CCTK_PARAMETER__EXACT__shift_add_x PRIVATE_EXACT_STRUCT.shift_add_x
#endif
#ifndef CCTK_PARAMETER__EXACT__shift_add_y
#  define CCTK_PARAMETER__EXACT__shift_add_y PRIVATE_EXACT_STRUCT.shift_add_y
#endif
#ifndef CCTK_PARAMETER__EXACT__shift_add_z
#  define CCTK_PARAMETER__EXACT__shift_add_z PRIVATE_EXACT_STRUCT.shift_add_z
#endif
#ifndef CCTK_PARAMETER__EXACT__slice_Gauss_ampl
#  define CCTK_PARAMETER__EXACT__slice_Gauss_ampl PRIVATE_EXACT_STRUCT.slice_Gauss_ampl
#endif
#ifndef CCTK_PARAMETER__EXACT__slice_Gauss_width
#  define CCTK_PARAMETER__EXACT__slice_Gauss_width PRIVATE_EXACT_STRUCT.slice_Gauss_width
#endif
#ifndef CCTK_PARAMETER__EXACT__overwrite_boundary
#  define CCTK_PARAMETER__EXACT__overwrite_boundary PRIVATE_EXACT_STRUCT.overwrite_boundary
#endif
#ifndef CCTK_PARAMETER__EXACT__exact_order
#  define CCTK_PARAMETER__EXACT__exact_order PRIVATE_EXACT_STRUCT.exact_order
#endif
#ifndef CCTK_PARAMETER__EXACT__exblend_Ks
#  define CCTK_PARAMETER__EXACT__exblend_Ks PRIVATE_EXACT_STRUCT.exblend_Ks
#endif
#ifndef CCTK_PARAMETER__EXACT__exblend_gauge
#  define CCTK_PARAMETER__EXACT__exblend_gauge PRIVATE_EXACT_STRUCT.exblend_gauge
#endif
#ifndef CCTK_PARAMETER__EXACT__exblend_gs
#  define CCTK_PARAMETER__EXACT__exblend_gs PRIVATE_EXACT_STRUCT.exblend_gs
#endif

