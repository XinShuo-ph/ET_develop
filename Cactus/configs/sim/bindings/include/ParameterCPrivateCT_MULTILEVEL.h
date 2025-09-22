#ifdef __cplusplus
extern "C"
{
#endif

extern struct
{
  CCTK_REAL eps;
  CCTK_REAL exact_offset;
  CCTK_REAL omega;
  CCTK_REAL reset_value[10];
  CCTK_REAL reset_x;
  CCTK_REAL reset_y;
  CCTK_REAL reset_z;
  CCTK_REAL tol;
  const char * a0_gfname[10];
  const char * a1_gfname[10];
  const char * a2_gfname[10];
  const char * a3_gfname[10];
  const char * a4_gfname[10];
  const char * boundary_conditions;
  const char * c0_gfname[10];
  const char * c1_gfname[10];
  const char * c2_gfname[10];
  const char * c3_gfname[10];
  const char * c4_gfname[10];
  const char * compare_to_exact;
  const char * cx_gfname[10];
  const char * cxx_gfname[10];
  const char * cxy_gfname[10];
  const char * cxz_gfname[10];
  const char * cy_gfname[10];
  const char * cycle_type;
  const char * cyy_gfname[10];
  const char * cyz_gfname[10];
  const char * cz_gfname[10];
  const char * czz_gfname[10];
  const char * disable[10];
  const char * exact_laplacian_gfname[10];
  const char * exact_solution_gfname[10];
  const char * fill_ADM;
  const char * fill_Aij;
  const char * inipsi_gfname[10];
  const char * mode;
  const char * model;
  const char * other_gfname[10];
  const char * output_norms;
  const char * output_walk;
  const char * reset_psi;
  const char * verbose;
  const char * veryverbose;
  CCTK_INT enforce_int;
  CCTK_INT fd_order;
  CCTK_INT integral_refinement;
  CCTK_INT n0[10];
  CCTK_INT n1[10];
  CCTK_INT n2[10];
  CCTK_INT n3[10];
  CCTK_INT n4[10];
  CCTK_INT nrelsteps_bottom;
  CCTK_INT nrelsteps_down;
  CCTK_INT nrelsteps_top;
  CCTK_INT nrelsteps_up;
  CCTK_INT number_of_auxiliaries;
  CCTK_INT number_of_equations;
  CCTK_INT reset_every;
  CCTK_INT topMGlevel;
} PRIVATE_CT_MULTILEVEL_STRUCT;

#ifdef __cplusplus
}
#endif

#define DECLARE_PRIVATE_CT_MULTILEVEL_STRUCT_PARAMS \
  CCTK_DECLARE_INIT (CCTK_REAL const, eps, CCTK_PARAMETER__CT_MULTILEVEL__eps); \
  CCTK_DECLARE_INIT (CCTK_REAL const, exact_offset, CCTK_PARAMETER__CT_MULTILEVEL__exact_offset); \
  CCTK_DECLARE_INIT (CCTK_REAL const, omega, CCTK_PARAMETER__CT_MULTILEVEL__omega); \
  CCTK_DECLARE_INIT (CCTK_REAL const * const, reset_value, CCTK_PARAMETER__CT_MULTILEVEL__reset_value); \
  CCTK_DECLARE_INIT (CCTK_REAL const, reset_x, CCTK_PARAMETER__CT_MULTILEVEL__reset_x); \
  CCTK_DECLARE_INIT (CCTK_REAL const, reset_y, CCTK_PARAMETER__CT_MULTILEVEL__reset_y); \
  CCTK_DECLARE_INIT (CCTK_REAL const, reset_z, CCTK_PARAMETER__CT_MULTILEVEL__reset_z); \
  CCTK_DECLARE_INIT (CCTK_REAL const, tol, CCTK_PARAMETER__CT_MULTILEVEL__tol); \
  CCTK_DECLARE_INIT (const char * const * const, a0_gfname, CCTK_PARAMETER__CT_MULTILEVEL__a0_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, a1_gfname, CCTK_PARAMETER__CT_MULTILEVEL__a1_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, a2_gfname, CCTK_PARAMETER__CT_MULTILEVEL__a2_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, a3_gfname, CCTK_PARAMETER__CT_MULTILEVEL__a3_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, a4_gfname, CCTK_PARAMETER__CT_MULTILEVEL__a4_gfname); \
  CCTK_DECLARE_INIT (const char * const, boundary_conditions, CCTK_PARAMETER__CT_MULTILEVEL__boundary_conditions); \
  CCTK_DECLARE_INIT (const char * const * const, c0_gfname, CCTK_PARAMETER__CT_MULTILEVEL__c0_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, c1_gfname, CCTK_PARAMETER__CT_MULTILEVEL__c1_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, c2_gfname, CCTK_PARAMETER__CT_MULTILEVEL__c2_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, c3_gfname, CCTK_PARAMETER__CT_MULTILEVEL__c3_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, c4_gfname, CCTK_PARAMETER__CT_MULTILEVEL__c4_gfname); \
  CCTK_DECLARE_INIT (const char * const, compare_to_exact, CCTK_PARAMETER__CT_MULTILEVEL__compare_to_exact); \
  CCTK_DECLARE_INIT (const char * const * const, cx_gfname, CCTK_PARAMETER__CT_MULTILEVEL__cx_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, cxx_gfname, CCTK_PARAMETER__CT_MULTILEVEL__cxx_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, cxy_gfname, CCTK_PARAMETER__CT_MULTILEVEL__cxy_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, cxz_gfname, CCTK_PARAMETER__CT_MULTILEVEL__cxz_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, cy_gfname, CCTK_PARAMETER__CT_MULTILEVEL__cy_gfname); \
  CCTK_DECLARE_INIT (const char * const, cycle_type, CCTK_PARAMETER__CT_MULTILEVEL__cycle_type); \
  CCTK_DECLARE_INIT (const char * const * const, cyy_gfname, CCTK_PARAMETER__CT_MULTILEVEL__cyy_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, cyz_gfname, CCTK_PARAMETER__CT_MULTILEVEL__cyz_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, cz_gfname, CCTK_PARAMETER__CT_MULTILEVEL__cz_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, czz_gfname, CCTK_PARAMETER__CT_MULTILEVEL__czz_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, disable, CCTK_PARAMETER__CT_MULTILEVEL__disable); \
  CCTK_DECLARE_INIT (const char * const * const, exact_laplacian_gfname, CCTK_PARAMETER__CT_MULTILEVEL__exact_laplacian_gfname); \
  CCTK_DECLARE_INIT (const char * const * const, exact_solution_gfname, CCTK_PARAMETER__CT_MULTILEVEL__exact_solution_gfname); \
  CCTK_DECLARE_INIT (const char * const, fill_ADM, CCTK_PARAMETER__CT_MULTILEVEL__fill_ADM); \
  CCTK_DECLARE_INIT (const char * const, fill_Aij, CCTK_PARAMETER__CT_MULTILEVEL__fill_Aij); \
  CCTK_DECLARE_INIT (const char * const * const, inipsi_gfname, CCTK_PARAMETER__CT_MULTILEVEL__inipsi_gfname); \
  CCTK_DECLARE_INIT (const char * const, mode, CCTK_PARAMETER__CT_MULTILEVEL__mode); \
  CCTK_DECLARE_INIT (const char * const, model, CCTK_PARAMETER__CT_MULTILEVEL__model); \
  CCTK_DECLARE_INIT (const char * const * const, other_gfname, CCTK_PARAMETER__CT_MULTILEVEL__other_gfname); \
  CCTK_DECLARE_INIT (const char * const, output_norms, CCTK_PARAMETER__CT_MULTILEVEL__output_norms); \
  CCTK_DECLARE_INIT (const char * const, output_walk, CCTK_PARAMETER__CT_MULTILEVEL__output_walk); \
  CCTK_DECLARE_INIT (const char * const, reset_psi, CCTK_PARAMETER__CT_MULTILEVEL__reset_psi); \
  CCTK_DECLARE_INIT (const char * const, verbose, CCTK_PARAMETER__CT_MULTILEVEL__verbose); \
  CCTK_DECLARE_INIT (const char * const, veryverbose, CCTK_PARAMETER__CT_MULTILEVEL__veryverbose); \
  CCTK_DECLARE_INIT (CCTK_INT const, enforce_int, CCTK_PARAMETER__CT_MULTILEVEL__enforce_int); \
  CCTK_DECLARE_INIT (CCTK_INT const, fd_order, CCTK_PARAMETER__CT_MULTILEVEL__fd_order); \
  CCTK_DECLARE_INIT (CCTK_INT const, integral_refinement, CCTK_PARAMETER__CT_MULTILEVEL__integral_refinement); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, n0, CCTK_PARAMETER__CT_MULTILEVEL__n0); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, n1, CCTK_PARAMETER__CT_MULTILEVEL__n1); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, n2, CCTK_PARAMETER__CT_MULTILEVEL__n2); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, n3, CCTK_PARAMETER__CT_MULTILEVEL__n3); \
  CCTK_DECLARE_INIT (CCTK_INT const * const, n4, CCTK_PARAMETER__CT_MULTILEVEL__n4); \
  CCTK_DECLARE_INIT (CCTK_INT const, nrelsteps_bottom, CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_bottom); \
  CCTK_DECLARE_INIT (CCTK_INT const, nrelsteps_down, CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_down); \
  CCTK_DECLARE_INIT (CCTK_INT const, nrelsteps_top, CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_top); \
  CCTK_DECLARE_INIT (CCTK_INT const, nrelsteps_up, CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_up); \
  CCTK_DECLARE_INIT (CCTK_INT const, number_of_auxiliaries, CCTK_PARAMETER__CT_MULTILEVEL__number_of_auxiliaries); \
  CCTK_DECLARE_INIT (CCTK_INT const, number_of_equations, CCTK_PARAMETER__CT_MULTILEVEL__number_of_equations); \
  CCTK_DECLARE_INIT (CCTK_INT const, reset_every, CCTK_PARAMETER__CT_MULTILEVEL__reset_every); \
  CCTK_DECLARE_INIT (CCTK_INT const, topMGlevel, CCTK_PARAMETER__CT_MULTILEVEL__topMGlevel); \


#ifndef CCTK_PARAMETER__CT_MULTILEVEL__eps
#  define CCTK_PARAMETER__CT_MULTILEVEL__eps PRIVATE_CT_MULTILEVEL_STRUCT.eps
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__exact_offset
#  define CCTK_PARAMETER__CT_MULTILEVEL__exact_offset PRIVATE_CT_MULTILEVEL_STRUCT.exact_offset
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__omega
#  define CCTK_PARAMETER__CT_MULTILEVEL__omega PRIVATE_CT_MULTILEVEL_STRUCT.omega
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__reset_value
#  define CCTK_PARAMETER__CT_MULTILEVEL__reset_value PRIVATE_CT_MULTILEVEL_STRUCT.reset_value
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__reset_x
#  define CCTK_PARAMETER__CT_MULTILEVEL__reset_x PRIVATE_CT_MULTILEVEL_STRUCT.reset_x
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__reset_y
#  define CCTK_PARAMETER__CT_MULTILEVEL__reset_y PRIVATE_CT_MULTILEVEL_STRUCT.reset_y
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__reset_z
#  define CCTK_PARAMETER__CT_MULTILEVEL__reset_z PRIVATE_CT_MULTILEVEL_STRUCT.reset_z
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__tol
#  define CCTK_PARAMETER__CT_MULTILEVEL__tol PRIVATE_CT_MULTILEVEL_STRUCT.tol
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__a0_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__a0_gfname PRIVATE_CT_MULTILEVEL_STRUCT.a0_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__a1_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__a1_gfname PRIVATE_CT_MULTILEVEL_STRUCT.a1_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__a2_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__a2_gfname PRIVATE_CT_MULTILEVEL_STRUCT.a2_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__a3_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__a3_gfname PRIVATE_CT_MULTILEVEL_STRUCT.a3_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__a4_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__a4_gfname PRIVATE_CT_MULTILEVEL_STRUCT.a4_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__boundary_conditions
#  define CCTK_PARAMETER__CT_MULTILEVEL__boundary_conditions PRIVATE_CT_MULTILEVEL_STRUCT.boundary_conditions
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__c0_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__c0_gfname PRIVATE_CT_MULTILEVEL_STRUCT.c0_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__c1_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__c1_gfname PRIVATE_CT_MULTILEVEL_STRUCT.c1_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__c2_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__c2_gfname PRIVATE_CT_MULTILEVEL_STRUCT.c2_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__c3_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__c3_gfname PRIVATE_CT_MULTILEVEL_STRUCT.c3_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__c4_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__c4_gfname PRIVATE_CT_MULTILEVEL_STRUCT.c4_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__compare_to_exact
#  define CCTK_PARAMETER__CT_MULTILEVEL__compare_to_exact PRIVATE_CT_MULTILEVEL_STRUCT.compare_to_exact
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__cx_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__cx_gfname PRIVATE_CT_MULTILEVEL_STRUCT.cx_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__cxx_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__cxx_gfname PRIVATE_CT_MULTILEVEL_STRUCT.cxx_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__cxy_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__cxy_gfname PRIVATE_CT_MULTILEVEL_STRUCT.cxy_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__cxz_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__cxz_gfname PRIVATE_CT_MULTILEVEL_STRUCT.cxz_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__cy_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__cy_gfname PRIVATE_CT_MULTILEVEL_STRUCT.cy_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__cycle_type
#  define CCTK_PARAMETER__CT_MULTILEVEL__cycle_type PRIVATE_CT_MULTILEVEL_STRUCT.cycle_type
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__cyy_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__cyy_gfname PRIVATE_CT_MULTILEVEL_STRUCT.cyy_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__cyz_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__cyz_gfname PRIVATE_CT_MULTILEVEL_STRUCT.cyz_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__cz_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__cz_gfname PRIVATE_CT_MULTILEVEL_STRUCT.cz_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__czz_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__czz_gfname PRIVATE_CT_MULTILEVEL_STRUCT.czz_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__disable
#  define CCTK_PARAMETER__CT_MULTILEVEL__disable PRIVATE_CT_MULTILEVEL_STRUCT.disable
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__exact_laplacian_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__exact_laplacian_gfname PRIVATE_CT_MULTILEVEL_STRUCT.exact_laplacian_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__exact_solution_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__exact_solution_gfname PRIVATE_CT_MULTILEVEL_STRUCT.exact_solution_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__fill_ADM
#  define CCTK_PARAMETER__CT_MULTILEVEL__fill_ADM PRIVATE_CT_MULTILEVEL_STRUCT.fill_ADM
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__fill_Aij
#  define CCTK_PARAMETER__CT_MULTILEVEL__fill_Aij PRIVATE_CT_MULTILEVEL_STRUCT.fill_Aij
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__inipsi_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__inipsi_gfname PRIVATE_CT_MULTILEVEL_STRUCT.inipsi_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__mode
#  define CCTK_PARAMETER__CT_MULTILEVEL__mode PRIVATE_CT_MULTILEVEL_STRUCT.mode
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__model
#  define CCTK_PARAMETER__CT_MULTILEVEL__model PRIVATE_CT_MULTILEVEL_STRUCT.model
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__other_gfname
#  define CCTK_PARAMETER__CT_MULTILEVEL__other_gfname PRIVATE_CT_MULTILEVEL_STRUCT.other_gfname
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__output_norms
#  define CCTK_PARAMETER__CT_MULTILEVEL__output_norms PRIVATE_CT_MULTILEVEL_STRUCT.output_norms
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__output_walk
#  define CCTK_PARAMETER__CT_MULTILEVEL__output_walk PRIVATE_CT_MULTILEVEL_STRUCT.output_walk
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__reset_psi
#  define CCTK_PARAMETER__CT_MULTILEVEL__reset_psi PRIVATE_CT_MULTILEVEL_STRUCT.reset_psi
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__verbose
#  define CCTK_PARAMETER__CT_MULTILEVEL__verbose PRIVATE_CT_MULTILEVEL_STRUCT.verbose
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__veryverbose
#  define CCTK_PARAMETER__CT_MULTILEVEL__veryverbose PRIVATE_CT_MULTILEVEL_STRUCT.veryverbose
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__enforce_int
#  define CCTK_PARAMETER__CT_MULTILEVEL__enforce_int PRIVATE_CT_MULTILEVEL_STRUCT.enforce_int
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__fd_order
#  define CCTK_PARAMETER__CT_MULTILEVEL__fd_order PRIVATE_CT_MULTILEVEL_STRUCT.fd_order
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__integral_refinement
#  define CCTK_PARAMETER__CT_MULTILEVEL__integral_refinement PRIVATE_CT_MULTILEVEL_STRUCT.integral_refinement
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__n0
#  define CCTK_PARAMETER__CT_MULTILEVEL__n0 PRIVATE_CT_MULTILEVEL_STRUCT.n0
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__n1
#  define CCTK_PARAMETER__CT_MULTILEVEL__n1 PRIVATE_CT_MULTILEVEL_STRUCT.n1
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__n2
#  define CCTK_PARAMETER__CT_MULTILEVEL__n2 PRIVATE_CT_MULTILEVEL_STRUCT.n2
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__n3
#  define CCTK_PARAMETER__CT_MULTILEVEL__n3 PRIVATE_CT_MULTILEVEL_STRUCT.n3
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__n4
#  define CCTK_PARAMETER__CT_MULTILEVEL__n4 PRIVATE_CT_MULTILEVEL_STRUCT.n4
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_bottom
#  define CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_bottom PRIVATE_CT_MULTILEVEL_STRUCT.nrelsteps_bottom
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_down
#  define CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_down PRIVATE_CT_MULTILEVEL_STRUCT.nrelsteps_down
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_top
#  define CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_top PRIVATE_CT_MULTILEVEL_STRUCT.nrelsteps_top
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_up
#  define CCTK_PARAMETER__CT_MULTILEVEL__nrelsteps_up PRIVATE_CT_MULTILEVEL_STRUCT.nrelsteps_up
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__number_of_auxiliaries
#  define CCTK_PARAMETER__CT_MULTILEVEL__number_of_auxiliaries PRIVATE_CT_MULTILEVEL_STRUCT.number_of_auxiliaries
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__number_of_equations
#  define CCTK_PARAMETER__CT_MULTILEVEL__number_of_equations PRIVATE_CT_MULTILEVEL_STRUCT.number_of_equations
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__reset_every
#  define CCTK_PARAMETER__CT_MULTILEVEL__reset_every PRIVATE_CT_MULTILEVEL_STRUCT.reset_every
#endif
#ifndef CCTK_PARAMETER__CT_MULTILEVEL__topMGlevel
#  define CCTK_PARAMETER__CT_MULTILEVEL__topMGlevel PRIVATE_CT_MULTILEVEL_STRUCT.topMGlevel
#endif

