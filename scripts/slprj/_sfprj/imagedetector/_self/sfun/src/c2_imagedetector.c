/* Include files */

#include "imagedetector_sfun.h"
#include "c2_imagedetector.h"
#include <math.h>
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c2_emlrtMCI = { 88, /* lineNo */
  9,                                   /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c2_b_emlrtMCI = { 121,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c2_c_emlrtMCI = { 85,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_d_emlrtMCI = { 184,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_e_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

static emlrtMCInfo c2_f_emlrtMCI = { 41,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtMCInfo c2_g_emlrtMCI = { 31,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtMCInfo c2_h_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c2_i_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnan.m"/* pName */
};

static emlrtMCInfo c2_j_emlrtMCI = { 1271,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtMCInfo c2_k_emlrtMCI = { 47,/* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtMCInfo c2_l_emlrtMCI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c2_m_emlrtMCI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c2_n_emlrtMCI = { 38,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtMCInfo c2_o_emlrtMCI = { 271,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtMCInfo c2_p_emlrtMCI = { 46,/* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pName */
};

static emlrtMCInfo c2_q_emlrtMCI = { 81,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_r_emlrtMCI = { 297,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtMCInfo c2_s_emlrtMCI = { 81,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtMCInfo c2_t_emlrtMCI = { 392,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtMCInfo c2_u_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/+valattr/validatepositive.m"/* pName */
};

static emlrtMCInfo c2_v_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validatenonempty",                  /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/+valattr/validatenonempty.m"/* pName */
};

static emlrtMCInfo c2_w_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "validatencols",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/+valattr/validatencols.m"/* pName */
};

static emlrtMCInfo c2_x_emlrtMCI = { 72,/* lineNo */
  1,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtMCInfo c2_y_emlrtMCI = { 83,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRSInfo c2_emlrtRSI = { 2,  /* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#imagedetector:16"                  /* pathName */
};

static emlrtRSInfo c2_b_emlrtRSI = { 5,/* lineNo */
  "MATLAB Function",                   /* fcnName */
  "#imagedetector:16"                  /* pathName */
};

static emlrtRSInfo c2_c_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/shared/coder/coder/lib/+coder/+internal/warning.m"/* pathName */
};

static emlrtRSInfo c2_d_emlrtRSI = { 204,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_e_emlrtRSI = { 48,/* lineNo */
  "rgb2gray",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/images/rgb2gray.m"/* pathName */
};

static emlrtRSInfo c2_f_emlrtRSI = { 16,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c2_g_emlrtRSI = { 28,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c2_h_emlrtRSI = { 38,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c2_i_emlrtRSI = { 46,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c2_j_emlrtRSI = { 64,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c2_k_emlrtRSI = { 24,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_l_emlrtRSI = { 28,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_m_emlrtRSI = { 31,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_n_emlrtRSI = { 32,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_o_emlrtRSI = { 76,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_p_emlrtRSI = { 136,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_q_emlrtRSI = { 174,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_r_emlrtRSI = { 175,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_s_emlrtRSI = { 106,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c2_t_emlrtRSI = { 110,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c2_u_emlrtRSI = { 849,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c2_v_emlrtRSI = { 923,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c2_w_emlrtRSI = { 997,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c2_x_emlrtRSI = { 1025,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c2_y_emlrtRSI = { 1037,/* lineNo */
  "imfilter",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo c2_ab_emlrtRSI = { 190,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_bb_emlrtRSI = { 195,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_cb_emlrtRSI = { 35,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_db_emlrtRSI = { 40,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_eb_emlrtRSI = { 101,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_fb_emlrtRSI = { 103,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_gb_emlrtRSI = { 105,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_hb_emlrtRSI = { 107,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_ib_emlrtRSI = { 149,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_jb_emlrtRSI = { 151,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_kb_emlrtRSI = { 152,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_lb_emlrtRSI = { 155,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_mb_emlrtRSI = { 754,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_nb_emlrtRSI = { 755,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_ob_emlrtRSI = { 757,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_pb_emlrtRSI = { 39,/* lineNo */
  "im2uint8",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

static emlrtRSInfo c2_qb_emlrtRSI = { 138,/* lineNo */
  "im2uint8",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/im2uint8.m"/* pathName */
};

static emlrtRSInfo c2_rb_emlrtRSI = { 19,/* lineNo */
  "grayto8",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/grayto8.m"/* pathName */
};

static emlrtRSInfo c2_sb_emlrtRSI = { 133,/* lineNo */
  "imhist",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c2_tb_emlrtRSI = { 456,/* lineNo */
  "imhist",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c2_ub_emlrtRSI = { 452,/* lineNo */
  "imhist",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c2_vb_emlrtRSI = { 207,/* lineNo */
  "imhist",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c2_wb_emlrtRSI = { 196,/* lineNo */
  "imhist",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c2_xb_emlrtRSI = { 170,/* lineNo */
  "imhist",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m"/* pathName */
};

static emlrtRSInfo c2_yb_emlrtRSI = { 20,/* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo c2_ac_emlrtRSI = { 99,/* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRSInfo c2_bc_emlrtRSI = { 74,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c2_cc_emlrtRSI = { 107,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/blockedSummation.m"/* pathName */
};

static emlrtRSInfo c2_dc_emlrtRSI = { 22,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c2_ec_emlrtRSI = { 42,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c2_fc_emlrtRSI = { 178,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c2_gc_emlrtRSI = { 210,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c2_hc_emlrtRSI = { 21,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c2_ic_emlrtRSI = { 145,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_jc_emlrtRSI = { 113,/* lineNo */
  "mergesort",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/mergesort.m"/* pathName */
};

static emlrtRSInfo c2_kc_emlrtRSI = { 40,/* lineNo */
  "safeEq",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/safeEq.m"/* pathName */
};

static emlrtRSInfo c2_lc_emlrtRSI = { 46,/* lineNo */
  "eps",                               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/eps.m"/* pathName */
};

static emlrtRSInfo c2_mc_emlrtRSI = { 912,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_nc_emlrtRSI = { 917,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_oc_emlrtRSI = { 44,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_pc_emlrtRSI = { 243,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_qc_emlrtRSI = { 237,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_rc_emlrtRSI = { 229,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_sc_emlrtRSI = { 218,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_tc_emlrtRSI = { 205,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_uc_emlrtRSI = { 198,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_vc_emlrtRSI = { 180,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_wc_emlrtRSI = { 161,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_xc_emlrtRSI = { 43,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c2_yc_emlrtRSI = { 13,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_ad_emlrtRSI = { 17,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_bd_emlrtRSI = { 169,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_cd_emlrtRSI = { 172,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_dd_emlrtRSI = { 132,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_ed_emlrtRSI = { 1027,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_fd_emlrtRSI = { 1028,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_gd_emlrtRSI = { 1037,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_hd_emlrtRSI = { 18,/* lineNo */
  "abs",                               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRSInfo c2_id_emlrtRSI = { 74,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo c2_jd_emlrtRSI = { 13,/* lineNo */
  "any",                               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/any.m"/* pathName */
};

static emlrtRSInfo c2_kd_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pathName */
};

static emlrtRSInfo c2_ld_emlrtRSI = { 32,/* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo c2_md_emlrtRSI = { 72,/* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo c2_nd_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_od_emlrtRSI = { 308,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_pd_emlrtRSI = { 316,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_qd_emlrtRSI = { 317,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_rd_emlrtRSI = { 325,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_sd_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_td_emlrtRSI = { 392,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_ud_emlrtRSI = { 420,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_vd_emlrtRSI = { 427,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_wd_emlrtRSI = { 587,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_xd_emlrtRSI = { 589,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_yd_emlrtRSI = { 617,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_ae_emlrtRSI = { 499,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_be_emlrtRSI = { 506,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_ce_emlrtRSI = { 507,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_de_emlrtRSI = { 514,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_ee_emlrtRSI = { 561,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_fe_emlrtRSI = { 530,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_ge_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c2_he_emlrtRSI = { 138,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c2_ie_emlrtRSI = { 255,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c2_je_emlrtRSI = { 254,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c2_ke_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c2_le_emlrtRSI = { 16,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c2_me_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c2_ne_emlrtRSI = { 117,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c2_oe_emlrtRSI = { 320,/* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

static emlrtRSInfo c2_pe_emlrtRSI = { 161,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_qe_emlrtRSI = { 37,/* lineNo */
  "medfilt2",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/medfilt2.m"/* pathName */
};

static emlrtRSInfo c2_re_emlrtRSI = { 25,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/ordfilt2.m"/* pathName */
};

static emlrtRSInfo c2_se_emlrtRSI = { 155,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/ordfilt2.m"/* pathName */
};

static emlrtRSInfo c2_te_emlrtRSI = { 179,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/ordfilt2.m"/* pathName */
};

static emlrtRSInfo c2_ue_emlrtRSI = { 29,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_ve_emlrtRSI = { 34,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_we_emlrtRSI = { 35,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_xe_emlrtRSI = { 36,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_ye_emlrtRSI = { 48,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_af_emlrtRSI = { 53,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_bf_emlrtRSI = { 55,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_cf_emlrtRSI = { 66,/* lineNo */
  "imhmax",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/imhmax.m"/* pathName */
};

static emlrtRSInfo c2_df_emlrtRSI = { 10,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imreconstruct.m"/* pathName */
};

static emlrtRSInfo c2_ef_emlrtRSI = { 14,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imreconstruct.m"/* pathName */
};

static emlrtRSInfo c2_ff_emlrtRSI = { 76,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imreconstruct.m"/* pathName */
};

static emlrtRSInfo c2_gf_emlrtRSI = { 76,/* lineNo */
  "validateattributes",                /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/lang/validateattributes.m"/* pathName */
};

static emlrtRSInfo c2_hf_emlrtRSI = { 14,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imregionalmax.m"/* pathName */
};

static emlrtRSInfo c2_if_emlrtRSI = { 35,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imregionalmax.m"/* pathName */
};

static emlrtRSInfo c2_jf_emlrtRSI = { 37,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imregionalmax.m"/* pathName */
};

static emlrtRSInfo c2_kf_emlrtRSI = { 32,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_lf_emlrtRSI = { 73,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_mf_emlrtRSI = { 75,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_nf_emlrtRSI = { 78,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_of_emlrtRSI = { 168,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_pf_emlrtRSI = { 197,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_qf_emlrtRSI = { 79,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_rf_emlrtRSI = { 71,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_sf_emlrtRSI = { 70,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_tf_emlrtRSI = { 69,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_uf_emlrtRSI = { 57,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_vf_emlrtRSI = { 44,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_wf_emlrtRSI = { 23,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_xf_emlrtRSI = { 51,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c2_yf_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c2_ag_emlrtRSI = { 149,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c2_bg_emlrtRSI = { 150,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c2_cg_emlrtRSI = { 153,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c2_dg_emlrtRSI = { 57,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c2_eg_emlrtRSI = { 182,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c2_fg_emlrtRSI = { 184,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c2_gg_emlrtRSI = { 189,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c2_hg_emlrtRSI = { 14,/* lineNo */
  "cumsum",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/cumsum.m"/* pathName */
};

static emlrtRSInfo c2_ig_emlrtRSI = { 16,/* lineNo */
  "cumop",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c2_jg_emlrtRSI = { 32,/* lineNo */
  "useConstantDim",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/useConstantDim.m"/* pathName */
};

static emlrtRSInfo c2_kg_emlrtRSI = { 99,/* lineNo */
  "cumop",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c2_lg_emlrtRSI = { 125,/* lineNo */
  "cumop",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c2_mg_emlrtRSI = { 290,/* lineNo */
  "cumop",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo c2_ng_emlrtRSI = { 1283,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_og_emlrtRSI = { 1468,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_pg_emlrtRSI = { 28,/* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo c2_qg_emlrtRSI = { 1840,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_rg_emlrtRSI = { 295,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_sg_emlrtRSI = { 1152,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_tg_emlrtRSI = { 1143,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_ug_emlrtRSI = { 1138,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_vg_emlrtRSI = { 1135,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_wg_emlrtRSI = { 772,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_xg_emlrtRSI = { 770,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_yg_emlrtRSI = { 19,/* lineNo */
  "ind2sub",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pathName */
};

static emlrtRSInfo c2_ah_emlrtRSI = { 22,/* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo c2_bh_emlrtRSI = { 96,/* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo c2_ch_emlrtRSI = { 1121,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_dh_emlrtRSI = { 22,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_eh_emlrtRSI = { 26,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_fh_emlrtRSI = { 274,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_gh_emlrtRSI = { 275,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_hh_emlrtRSI = { 10,/* lineNo */
  "round",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elfun/round.m"/* pathName */
};

static emlrtRSInfo c2_ih_emlrtRSI = { 33,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c2_jh_emlrtRSI = { 27,/* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo c2_kh_emlrtRSI = { 104,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_lh_emlrtRSI = { 340,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_mh_emlrtRSI = { 354,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_nh_emlrtRSI = { 363,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo c2_oh_emlrtRSI = { 39,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c2_ph_emlrtRSI = { 144,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c2_qh_emlrtRSI = { 382,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c2_rh_emlrtRSI = { 402,/* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo c2_sh_emlrtRSI = { 6,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_th_emlrtRSI = { 14,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_uh_emlrtRSI = { 16,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_vh_emlrtRSI = { 32,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_wh_emlrtRSI = { 35,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_xh_emlrtRSI = { 44,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_yh_emlrtRSI = { 72,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_ai_emlrtRSI = { 73,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_bi_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/all.m"/* pathName */
};

static emlrtRSInfo c2_ci_emlrtRSI = { 9,/* lineNo */
  "angle",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elfun/angle.m"/* pathName */
};

static emlrtRSInfo c2_di_emlrtRSI = { 10,/* lineNo */
  "exp",                               /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elfun/exp.m"/* pathName */
};

static emlrtRSInfo c2_ei_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

static emlrtRSInfo c2_fi_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRTEInfo c2_emlrtRTEI = { 2,/* lineNo */
  2,                                   /* colNo */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16"                  /* pName */
};

static emlrtRTEInfo c2_b_emlrtRTEI = { 2,/* lineNo */
  14,                                  /* colNo */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16"                  /* pName */
};

static emlrtRTEInfo c2_c_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

static emlrtRTEInfo c2_d_emlrtRTEI = { 38,/* lineNo */
  2,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_e_emlrtRTEI = { 46,/* lineNo */
  17,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_f_emlrtRTEI = { 369,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_g_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_h_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_i_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_j_emlrtRTEI = { 64,/* lineNo */
  45,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_k_emlrtRTEI = { 64,/* lineNo */
  17,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_l_emlrtRTEI = { 1,/* lineNo */
  43,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_m_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_n_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_o_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_p_emlrtRTEI = { 32,/* lineNo */
  35,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_q_emlrtRTEI = { 32,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_r_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_s_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_t_emlrtRTEI = { 76,/* lineNo */
  23,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_u_emlrtRTEI = { 77,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_v_emlrtRTEI = { 78,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_w_emlrtRTEI = { 79,/* lineNo */
  33,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_x_emlrtRTEI = { 91,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_y_emlrtRTEI = { 92,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_ab_emlrtRTEI = { 94,/* lineNo */
  24,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_bb_emlrtRTEI = { 95,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_cb_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_db_emlrtRTEI = { 120,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_eb_emlrtRTEI = { 121,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_fb_emlrtRTEI = { 122,/* lineNo */
  28,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_gb_emlrtRTEI = { 312,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c2_hb_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_ib_emlrtRTEI = { 78,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_jb_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_kb_emlrtRTEI = { 91,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_lb_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_mb_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_nb_emlrtRTEI = { 95,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_ob_emlrtRTEI = { 120,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_pb_emlrtRTEI = { 121,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_qb_emlrtRTEI = { 122,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_rb_emlrtRTEI = { 1,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_sb_emlrtRTEI = { 32,/* lineNo */
  8,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtRTEInfo c2_tb_emlrtRTEI = { 175,/* lineNo */
  38,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c2_ub_emlrtRTEI = { 35,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_vb_emlrtRTEI = { 585,/* lineNo */
  15,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_wb_emlrtRTEI = { 12,/* lineNo */
  20,                                  /* colNo */
  "grayto8",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/grayto8.m"/* pName */
};

static emlrtRTEInfo c2_xb_emlrtRTEI = { 94,/* lineNo */
  13,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_yb_emlrtRTEI = { 912,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ac_emlrtRTEI = { 917,/* lineNo */
  16,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_bc_emlrtRTEI = { 903,/* lineNo */
  28,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_cc_emlrtRTEI = { 917,/* lineNo */
  36,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_dc_emlrtRTEI = { 77,/* lineNo */
  9,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c2_ec_emlrtRTEI = { 903,/* lineNo */
  1,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_fc_emlrtRTEI = { 141,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_gc_emlrtRTEI = { 995,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_hc_emlrtRTEI = { 1044,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ic_emlrtRTEI = { 1011,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_jc_emlrtRTEI = { 107,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_kc_emlrtRTEI = { 152,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_lc_emlrtRTEI = { 1039,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_mc_emlrtRTEI = { 1020,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_nc_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo c2_oc_emlrtRTEI = { 1021,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_pc_emlrtRTEI = { 1008,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_qc_emlrtRTEI = { 157,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_rc_emlrtRTEI = { 1027,/* lineNo */
  24,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_sc_emlrtRTEI = { 1027,/* lineNo */
  20,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_tc_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_uc_emlrtRTEI = { 917,/* lineNo */
  22,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_vc_emlrtRTEI = { 754,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_wc_emlrtRTEI = { 585,/* lineNo */
  17,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_xc_emlrtRTEI = { 1,/* lineNo */
  29,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtRTEInfo c2_yc_emlrtRTEI = { 185,/* lineNo */
  38,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo c2_ad_emlrtRTEI = { 162,/* lineNo */
  20,                                  /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c2_bd_emlrtRTEI = { 173,/* lineNo */
  50,                                  /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c2_cd_emlrtRTEI = { 237,/* lineNo */
  1,                                   /* colNo */
  "unique",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pName */
};

static emlrtRTEInfo c2_dd_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_ed_emlrtRTEI = { 30,/* lineNo */
  21,                                  /* colNo */
  "applyScalarFunction",               /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pName */
};

static emlrtRTEInfo c2_fd_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo c2_gd_emlrtRTEI = { 572,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_hd_emlrtRTEI = { 482,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_id_emlrtRTEI = { 520,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_jd_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_kd_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_ld_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_md_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo c2_nd_emlrtRTEI = { 41,/* lineNo */
  30,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_od_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_pd_emlrtRTEI = { 48,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_qd_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_rd_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_sd_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_td_emlrtRTEI = { 42,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_ud_emlrtRTEI = { 53,/* lineNo */
  38,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_vd_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_wd_emlrtRTEI = { 53,/* lineNo */
  58,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_xd_emlrtRTEI = { 53,/* lineNo */
  18,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_yd_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_ae_emlrtRTEI = { 55,/* lineNo */
  33,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_be_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_ce_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/sort.m"/* pName */
};

static emlrtRTEInfo c2_de_emlrtRTEI = { 55,/* lineNo */
  10,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_ee_emlrtRTEI = { 56,/* lineNo */
  19,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_fe_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_ge_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_he_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_ie_emlrtRTEI = { 53,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_je_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_ke_emlrtRTEI = { 291,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_le_emlrtRTEI = { 292,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_me_emlrtRTEI = { 17,/* lineNo */
  25,                                  /* colNo */
  "cumop",                             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pName */
};

static emlrtRTEInfo c2_ne_emlrtRTEI = { 295,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_oe_emlrtRTEI = { 298,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_pe_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_qe_emlrtRTEI = { 75,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_re_emlrtRTEI = { 220,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_se_emlrtRTEI = { 233,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_te_emlrtRTEI = { 234,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_ue_emlrtRTEI = { 48,/* lineNo */
  27,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_ve_emlrtRTEI = { 49,/* lineNo */
  25,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_we_emlrtRTEI = { 50,/* lineNo */
  28,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_xe_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_ye_emlrtRTEI = { 39,/* lineNo */
  35,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_af_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_bf_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_cf_emlrtRTEI = { 42,/* lineNo */
  42,                                  /* colNo */
  "sumMatrixIncludeNaN",               /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pName */
};

static emlrtRTEInfo c2_df_emlrtRTEI = { 69,/* lineNo */
  31,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_ef_emlrtRTEI = { 51,/* lineNo */
  36,                                  /* colNo */
  "sumMatrixIncludeNaN",               /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pName */
};

static emlrtRTEInfo c2_ff_emlrtRTEI = { 70,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_gf_emlrtRTEI = { 54,/* lineNo */
  44,                                  /* colNo */
  "sumMatrixIncludeNaN",               /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pName */
};

static emlrtRTEInfo c2_hf_emlrtRTEI = { 57,/* lineNo */
  43,                                  /* colNo */
  "sumMatrixIncludeNaN",               /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/datafun/private/sumMatrixIncludeNaN.m"/* pName */
};

static emlrtRTEInfo c2_if_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_jf_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_kf_emlrtRTEI = { 90,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_lf_emlrtRTEI = { 11,/* lineNo */
  6,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_mf_emlrtRTEI = { 11,/* lineNo */
  19,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_nf_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_of_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_pf_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_qf_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_rf_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "useConstantDim",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/useConstantDim.m"/* pName */
};

static emlrtRTEInfo c2_sf_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo c2_tf_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "repmat",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo c2_uf_emlrtRTEI = { 1840,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_vf_emlrtRTEI = { 1719,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_wf_emlrtRTEI = { 1130,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_xf_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "round",                             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elfun/round.m"/* pName */
};

static emlrtRTEInfo c2_yf_emlrtRTEI = { 72,/* lineNo */
  30,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_ag_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_bg_emlrtRTEI = { 14,/* lineNo */
  56,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_cg_emlrtRTEI = { 14,/* lineNo */
  76,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_dg_emlrtRTEI = { 14,/* lineNo */
  18,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_eg_emlrtRTEI = { 16,/* lineNo */
  20,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_fg_emlrtRTEI = { 16,/* lineNo */
  19,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_gg_emlrtRTEI = { 14,/* lineNo */
  30,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_hg_emlrtRTEI = { 13,/* lineNo */
  21,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_ig_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_jg_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_kg_emlrtRTEI = { 267,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_lg_emlrtRTEI = { 385,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_mg_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_ng_emlrtRTEI = { 274,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_og_emlrtRTEI = { 387,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_pg_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_qg_emlrtRTEI = { 105,/* lineNo */
  40,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_rg_emlrtRTEI = { 769,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_sg_emlrtRTEI = { 770,/* lineNo */
  41,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_tg_emlrtRTEI = { 1120,/* lineNo */
  57,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_ug_emlrtRTEI = { 774,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_vg_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_wg_emlrtRTEI = { 1142,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_xg_emlrtRTEI = { 1120,/* lineNo */
  47,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_yg_emlrtRTEI = { 40,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_ah_emlrtRTEI = { 1143,/* lineNo */
  28,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_bh_emlrtRTEI = { 1121,/* lineNo */
  33,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_ch_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_dh_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_eh_emlrtRTEI = { 44,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_fh_emlrtRTEI = { 1152,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_gh_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_hh_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_ih_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_jh_emlrtRTEI = { 1122,/* lineNo */
  27,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_kh_emlrtRTEI = { 104,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c2_lh_emlrtRTEI = { 111,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c2_mh_emlrtRTEI = { 772,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_nh_emlrtRTEI = { 99,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo c2_oh_emlrtRTEI = { 770,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo c2_ph_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtBCInfo c2_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  44,                                  /* colNo */
  "radiiDark",                         /* aName */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16",                 /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  25,                                  /* colNo */
  "centersDark",                       /* aName */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16",                 /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  42,                                  /* colNo */
  "radiiDark",                         /* aName */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16",                 /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  25,                                  /* colNo */
  "centersDark",                       /* aName */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16",                 /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  21,                                  /* colNo */
  "radiiDark",                         /* aName */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16",                 /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  48,                                  /* colNo */
  "radiiDark",                         /* aName */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16",                 /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  73,                                  /* colNo */
  "radiiDark",                         /* aName */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16",                 /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  96,                                  /* colNo */
  "radiiDark",                         /* aName */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16",                 /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  119,                                 /* colNo */
  "radiiDark",                         /* aName */
  "MATLAB Function",                   /* fName */
  "#imagedetector:16",                 /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c2_qh_emlrtRTEI = { 75,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pName */
};

static emlrtBCInfo c2_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_gb_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  162,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ib_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  162,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_kb_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  162,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c2_lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_mb_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  162,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c2_nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ob_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_qb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_rb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_sb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  81,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_tb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  104,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ub_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_vb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_wb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_xb_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_yb_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  100,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ac_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1022,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_bc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1008,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_cc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1005,                                /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c2_emlrtECI = { 2,  /* nDims */
  917,                                 /* lineNo */
  16,                                  /* colNo */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pName */
};

static emlrtBCInfo c2_dc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ec_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1032,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_fc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1049,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_gc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1050,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_hc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1064,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ic_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1051,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_jc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1052,                                /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_kc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c2_b_emlrtECI = { -1,/* nDims */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtRTEInfo c2_rh_emlrtRTEI = { 46,/* lineNo */
  15,                                  /* colNo */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pName */
};

static emlrtBCInfo c2_lc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_mc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_nc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_oc_emlrtBCI = { 1,/* iFirst */
  307200,                              /* iLast */
  53,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_pc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_qc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_rc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_sc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1896,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_tc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1898,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_uc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_vc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1899,                                /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_wc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_emlrtDCI = { 48, /* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c2_xc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  233,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_yc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ad_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  234,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_bd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_b_emlrtDCI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_cd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_dd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ed_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_fd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_gd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_hd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_id_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_jd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_kd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ld_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_md_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_nd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_od_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_pd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_qd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_rd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_sd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_td_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ud_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_vd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_wd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_xd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_yd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ae_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_be_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ce_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_de_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_c_emlrtDCI = { 69,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c2_d_emlrtDCI = { 69,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c2_ee_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_fe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ge_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_he_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ie_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_je_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ke_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_le_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_me_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ne_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_oe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_pe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  72,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_qe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  92,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_re_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_se_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_te_emlrtBCI = { 1,/* iFirst */
  307200,                              /* iLast */
  14,                                  /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c2_c_emlrtECI = { -1,/* nDims */
  1152,                                /* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtBCInfo c2_ue_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1144,                                /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ve_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1123,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_we_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1120,                                /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_xe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  774,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ye_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1152,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_af_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1156,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_bf_emlrtBCI = { 1,/* iFirst */
  480,                                 /* iLast */
  1123,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_cf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1123,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_df_emlrtBCI = { 1,/* iFirst */
  640,                                 /* iLast */
  1123,                                /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ef_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1123,                                /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_ff_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  772,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_gf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  769,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_hf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  770,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_if_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1120,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_jf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1142,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_kf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1142,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_lf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1121,                                /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_mf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1152,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_nf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1122,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c2_gi_emlrtRSI = { 14,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_hi_emlrtRSI = { 122,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_ii_emlrtRSI = { 1152,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_ji_emlrtRSI = { 56,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_ki_emlrtRSI = { 55,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_li_emlrtRSI = { 48,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_mi_emlrtRSI = { 53,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_ni_emlrtRSI = { 40,/* lineNo */
  "chcenters",                         /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chcenters.m"/* pathName */
};

static emlrtRSInfo c2_oi_emlrtRSI = { 107,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_pi_emlrtRSI = { 94,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_qi_emlrtRSI = { 64,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c2_ri_emlrtRSI = { 47,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c2_si_emlrtRSI = { 38,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c2_ti_emlrtRSI = { 95,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_ui_emlrtRSI = { 46,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/imfindcircles.m"/* pathName */
};

static emlrtRSInfo c2_vi_emlrtRSI = { 70,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_wi_emlrtRSI = { 55,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_xi_emlrtRSI = { 39,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_yi_emlrtRSI = { 48,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c2_aj_emlrtRSI = { 46,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c2_bj_emlrtRSI = { 35,/* lineNo */
  "multithresh",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/multithresh.m"/* pathName */
};

static emlrtRSInfo c2_cj_emlrtRSI = { 121,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_dj_emlrtRSI = { 120,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_ej_emlrtRSI = { 1143,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_fj_emlrtRSI = { 1142,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo c2_gj_emlrtRSI = { 16,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c2_hj_emlrtRSI = { 69,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo c2_ij_emlrtRSI = { 41,/* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo c2_jj_emlrtRSI = { 79,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_kj_emlrtRSI = { 78,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_lj_emlrtRSI = { 77,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_mj_emlrtRSI = { 32,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_nj_emlrtRSI = { 31,/* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo c2_oj_emlrtRSI = { 98,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_pj_emlrtRSI = { 13,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo c2_qj_emlrtRSI = { 92,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_rj_emlrtRSI = { 91,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_sj_emlrtRSI = { 94,/* lineNo */
  "chaccum",                           /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/images/images/eml/private/chaccum.m"/* pathName */
};

static emlrtRSInfo c2_tj_emlrtRSI = { 237,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_uj_emlrtRSI = { 173,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_vj_emlrtRSI = { 162,/* lineNo */
  "unique",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/ops/unique.m"/* pathName */
};

static emlrtRSInfo c2_wj_emlrtRSI = { 53,/* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo c2_xj_emlrtRSI = { 46,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo c2_yj_emlrtRSI = { 44,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2021a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static const char_T c2_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i',
  'l', 't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
  'a', 'i', 'l', 'e', 'd' };

static const char_T c2_cv1[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
  'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm',
  'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

static const char_T c2_cv2[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c', 'h'
};

static const char_T c2_cv3[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N',
  'o', 'n', 'N', 'a', 'N' };

static const char_T c2_cv4[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
  'a', 'x', 's', 'i', 'z', 'e' };

/* Function Declarations */
static void initialize_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance);
static void initialize_params_c2_imagedetector(SFc2_imagedetectorInstanceStruct *
  chartInstance);
static void enable_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance);
static void disable_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance);
static void c2_update_jit_animation_state_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance);
static void c2_do_animation_call_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance);
static void ext_mode_exec_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance);
static void set_sim_state_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void sf_gateway_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance);
static void mdl_start_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance);
static void mdl_terminate_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance);
static void initSimStructsc2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance);
static void c2_warning(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_varargin_6);
static void c2_imfindcircles(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, uint8_T c2_f_varargin_1[921600], c2_emxArray_real_T
  *c2_centers, c2_emxArray_real_T *c2_r_estimated);
static void c2_chaccum(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, uint8_T c2_f_varargin_1[921600], creal_T c2_c_accumMatrix
  [307200], real32_T c2_b_gradientImg[307200]);
static void c2_imfilter(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real32_T c2_f_varargin_1[307200], real32_T c2_b[307200]);
static void c2_padImage(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real32_T c2_a_tmp[307200], real32_T c2_d_a[309444]);
static void c2_b_imfilter(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real32_T c2_f_varargin_1[307200], real32_T c2_b[307200]);
static real32_T c2_maximum(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real32_T c2_e_x[307200]);
static real32_T c2_multithresh(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real32_T c2_f_varargin_1[307200]);
static void c2_check_forloop_overflow_error(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp);
static real32_T c2_minimum(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real32_T c2_e_x[307200]);
static void c2_imhist(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, c2_emxArray_uint8_T *c2_f_varargin_1,
                      real_T c2_yout[256]);
static real_T c2_sum(SFc2_imagedetectorInstanceStruct *chartInstance, real_T
                     c2_e_x[256]);
static real_T c2_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  real_T c2_e_x[256]);
static void c2_b_warning(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp);
static real_T c2_b_maximum(SFc2_imagedetectorInstanceStruct *chartInstance,
  real_T c2_e_x[256]);
static void c2_mergesort(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, int32_T c2_b_idx[307200], real32_T c2_e_x[307200], int32_T
  c2_c_idx[307200]);
static void c2_unique_vector(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real32_T c2_d_a[307200], c2_emxArray_real32_T *c2_b);
static void c2_indexShapeCheck(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_matrixSize, int32_T c2_indexSize[2]);
static void c2_nullAssignment(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real32_T *c2_e_x, c2_emxArray_boolean_T
  *c2_b_idx, c2_emxArray_real32_T *c2_f_x);
static void c2_c_warning(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp);
static void c2_abs(SFc2_imagedetectorInstanceStruct *chartInstance, const
                   emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x,
                   c2_emxArray_real_T *c2_b_y);
static real_T c2_eps(SFc2_imagedetectorInstanceStruct *chartInstance, real_T
                     c2_e_x);
static boolean_T c2_any(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_e_x);
static void c2_sort(SFc2_imagedetectorInstanceStruct *chartInstance, const
                    emlrtStack *c2_sp, c2_emxArray_real32_T *c2_e_x,
                    c2_emxArray_real32_T *c2_f_x);
static void c2_merge_pow2_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T
  *c2_e_x, int32_T c2_offset, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real32_T *c2_f_x);
static void c2_merge_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T
  *c2_e_x, int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel,
  c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real32_T *c2_xwork,
  c2_emxArray_int32_T *c2_c_idx, c2_emxArray_real32_T *c2_f_x,
  c2_emxArray_int32_T *c2_c_iwork, c2_emxArray_real32_T *c2_b_xwork);
static void c2_merge(SFc2_imagedetectorInstanceStruct *chartInstance, const
                     emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx,
                     c2_emxArray_real32_T *c2_e_x, int32_T c2_offset, int32_T
                     c2_np, int32_T c2_nq, c2_emxArray_int32_T *c2_b_iwork,
                     c2_emxArray_real32_T *c2_xwork, c2_emxArray_int32_T
                     *c2_c_idx, c2_emxArray_real32_T *c2_f_x,
                     c2_emxArray_int32_T *c2_c_iwork, c2_emxArray_real32_T
                     *c2_b_xwork);
static void c2_eml_find(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, boolean_T c2_e_x[307200], c2_emxArray_int32_T *c2_i,
  c2_emxArray_int32_T *c2_j);
static boolean_T c2_allinrange(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_e_x, int32_T c2_hi);
static void c2_eml_sub2ind(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T *c2_f_varargin_1,
  c2_emxArray_real_T *c2_b_varargin_2, c2_emxArray_int32_T *c2_b_idx);
static void c2_medfilt2(SFc2_imagedetectorInstanceStruct *chartInstance, real_T
  c2_f_varargin_1[307200], real_T c2_b[307200]);
static void c2_chcenters(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, creal_T c2_f_varargin_1[307200], c2_emxArray_real_T
  *c2_centers, c2_emxArray_real_T *c2_metric);
static void c2_imhmax(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, real_T c2_c_I[307200], real_T c2_b_J
                      [307200]);
static void c2_validateattributes(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_d_a[307200]);
static void c2_imregionalmax(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_f_varargin_1[307200], boolean_T c2_BW
  [307200]);
static void c2_regionprops(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, boolean_T c2_f_varargin_1[307200], real_T
  c2_b_varargin_2[307200], c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_outstats);
static void c2_bwconncomp(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, boolean_T c2_f_varargin_1[307200],
  c2_s_vX9LV7M75v5ZNol5H5URkE *c2_CC);
static real_T c2_b_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_e_x, int32_T c2_vlen);
static real_T c2_sumColumnB4(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_e_x, int32_T c2_vstart);
static real_T c2_c_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_e_x, int32_T c2_vlen, int32_T
  c2_vstart);
static void c2_useConstantDim(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_varargin_2, int32_T
  c2_varargin_3, c2_emxArray_int32_T *c2_varargout_1);
static void c2_repmat(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, real_T c2_f_varargin_1,
                      c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_b);
static void c2_assertValidSizeArg(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_f_varargin_1);
static void c2_initializeStatsStruct(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_numObjs,
  c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_stats, c2_sHtk0WM4OMtyqkehwQYcq2
  *c2_statsAlreadyComputed);
static void c2_ComputeWeightedCentroid(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_c_I[307200],
  c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_stats, c2_sHtk0WM4OMtyqkehwQYcq2
  c2_statsAlreadyComputed, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_b_stats,
  c2_sHtk0WM4OMtyqkehwQYcq2 *c2_b_statsAlreadyComputed);
static real_T c2_b_sum(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x);
static real_T c2_d_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x, int32_T c2_vlen);
static real_T c2_b_sumColumnB4(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_e_x, int32_T c2_vstart);
static real_T c2_e_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x, int32_T c2_vlen, int32_T
  c2_vstart);
static void c2_round(SFc2_imagedetectorInstanceStruct *chartInstance, const
                     emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x,
                     c2_emxArray_real_T *c2_f_x);
static void c2_b_sort(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x,
                      c2_emxArray_real_T *c2_f_x, c2_emxArray_int32_T *c2_b_idx);
static void c2_b_merge_pow2_block(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx,
  c2_emxArray_real_T *c2_e_x, int32_T c2_offset, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real_T *c2_f_x);
static void c2_b_merge_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T
  *c2_e_x, int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel,
  c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real_T *c2_xwork,
  c2_emxArray_int32_T *c2_c_idx, c2_emxArray_real_T *c2_f_x, c2_emxArray_int32_T
  *c2_c_iwork, c2_emxArray_real_T *c2_b_xwork);
static void c2_b_merge(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_e_x,
  int32_T c2_offset, int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T
  *c2_b_iwork, c2_emxArray_real_T *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real_T *c2_f_x, c2_emxArray_int32_T *c2_c_iwork,
  c2_emxArray_real_T *c2_b_xwork);
static void c2_chradiiphcode(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T *c2_f_varargin_1, creal_T
  c2_b_varargin_2[307200], c2_emxArray_real_T *c2_r_estimated);
static boolean_T c2_all(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_e_x);
static void c2_angle(SFc2_imagedetectorInstanceStruct *chartInstance, const
                     emlrtStack *c2_sp, c2_emxArray_creal_T *c2_e_x,
                     c2_emxArray_real_T *c2_b_y);
static real_T c2_emlrt_marshallIn(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_b_y, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static uint8_T c2_c_emlrt_marshallIn(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_imagedetector, const char_T
  *c2_identifier);
static uint8_T c2_d_emlrt_marshallIn(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_chart_data_browse_helper(SFc2_imagedetectorInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig);
static const mxArray *c2_feval(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1,
  const mxArray *c2_input2, const mxArray *c2_input3, const mxArray *c2_input4,
  const mxArray *c2_input5, const mxArray *c2_input6, const mxArray *c2_input7);
static void c2_b_feval(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1);
static const mxArray *c2_sprintf(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0);
static const mxArray *c2_c_feval(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1,
  const mxArray *c2_input2);
static void c2_d_feval(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1);
static const mxArray *c2_e_feval(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1);
static void c2_f_feval(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1);
static void c2_b_mergesort(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_b_idx[307200], real32_T c2_e_x[307200]);
static void c2_b_nullAssignment(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real32_T *c2_e_x, c2_emxArray_boolean_T
  *c2_b_idx);
static void c2_c_sort(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, c2_emxArray_real32_T *c2_e_x);
static void c2_c_merge_pow2_block(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx,
  c2_emxArray_real32_T *c2_e_x, int32_T c2_offset);
static void c2_c_merge_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T
  *c2_e_x, int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel,
  c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real32_T *c2_xwork);
static void c2_c_merge(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_e_x,
  int32_T c2_offset, int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T
  *c2_b_iwork, c2_emxArray_real32_T *c2_xwork);
static void c2_b_ComputeWeightedCentroid(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_c_I[307200],
  c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_stats, c2_sHtk0WM4OMtyqkehwQYcq2
  *c2_statsAlreadyComputed);
static void c2_b_round(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x);
static void c2_d_sort(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x,
                      c2_emxArray_int32_T *c2_b_idx);
static void c2_d_merge_pow2_block(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx,
  c2_emxArray_real_T *c2_e_x, int32_T c2_offset);
static void c2_d_merge_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T
  *c2_e_x, int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel,
  c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real_T *c2_xwork);
static void c2_d_merge(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_e_x,
  int32_T c2_offset, int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T
  *c2_b_iwork, c2_emxArray_real_T *c2_xwork);
static void c2_emxInit_real_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_real_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_real_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_creal_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_creal_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_real_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_boolean_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_int32_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_real_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_boolean_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_boolean_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_int32_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_creal_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_creal_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_boolean_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_boolean_T **c2_pEmxArray);
static void c2_emxFree_int32_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_int32_T **c2_pEmxArray);
static void c2_emxFree_creal_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_creal_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_boolean_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_real32_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real32_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_creal_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_creal_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real32_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real32_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_creal_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_creal_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_boolean_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_real32_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_real32_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_real32_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real32_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real32_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real32_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_uint8_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_uint8_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_uint8_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_uint8_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_uint8_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_uint8_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_int32_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_sBO2RC5RVZVTbundPSRqHnH(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_sBO2RC5RVZVTbundPSRqHn
  **c2_pEmxArray, int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_int32_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_sBO2RC5RVZVTbundPSRqHnH(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_emxArray_sBO2RC5RVZVTbundPSRqHn **c2_pEmxArray);
static void c2_emxInitStruct_s_vX9LV7M75v5ZNol(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_s_vX9LV7M75v5ZNol5H5URkE
  *c2_pStruct, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_s_R6Og1x0kmqQXSF9Pwa49F(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49
  **c2_pEmxArray, int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFreeStruct_s_vX9LV7M75v5ZNol(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_s_vX9LV7M75v5ZNol5H5URkE *c2_pStruct);
static void c2_emxFree_s_R6Og1x0kmqQXSF9Pwa49F(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 **c2_pEmxArray);
static void c2_emxFreeStruct_s_R6Og1x0kmqQXSF9(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_s_R6Og1x0kmqQXSF9Pwa49FD *c2_pStruct);
static void c2_emxEnsureCapacity_sBO2RC5RVZVTb(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_sBO2RC5RVZVTbundPSRqHn
  *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxTrim_s_R6Og1x0kmqQXSF9Pwa49F(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_emxArray, int32_T
  c2_fromIndex, int32_T c2_toIndex);
static void c2_emxInitStruct_s_R6Og1x0kmqQXSF9(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_s_R6Og1x0kmqQXSF9Pwa49FD
  *c2_pStruct, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxExpand_s_R6Og1x0kmqQXSF9Pwa4(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49
  *c2_emxArray, int32_T c2_fromIndex, int32_T c2_toIndex, const emlrtRTEInfo
  *c2_srcLocation);
static void c2_emxEnsureCapacity_s_R6Og1x0kmqQ(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49
  *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopyStruct_s_R6Og1x0kmqQXSF9(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_s_R6Og1x0kmqQXSF9Pwa49FD *c2_dst,
  const c2_s_R6Og1x0kmqQXSF9Pwa49FD *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopyMatrix_real_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, real_T c2_dst[2], const real_T c2_src[2]);
static void c2_emxCopyMatrix_real_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, real_T c2_dst[4], const real_T c2_src[4]);
static void c2_emxCopy_boolean_T_0x0(SFc2_imagedetectorInstanceStruct
  *chartInstance, c2_emxArray_boolean_T_0x0 *c2_dst, const
  c2_emxArray_boolean_T_0x0 *c2_src);
static void c2_emxCopyMatrix_real_T2(SFc2_imagedetectorInstanceStruct
  *chartInstance, real_T c2_dst[16], const real_T c2_src[16]);
static void c2_emxCopy_real_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T **c2_dst, c2_emxArray_real_T *
  const *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopy_real_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T **c2_dst, c2_emxArray_real_T *
  const *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopy_real_T_1x0(SFc2_imagedetectorInstanceStruct
  *chartInstance, c2_emxArray_real_T_1x0 *c2_dst, const c2_emxArray_real_T_1x0
  *c2_src);
static void c2_emxInitMatrix_cell_wrap_46(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_cell_wrap_46 c2_pMatrix[2], const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxInitStruct_cell_wrap_46(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_cell_wrap_46 *c2_pStruct, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxFreeMatrix_cell_wrap_46(SFc2_imagedetectorInstanceStruct
  *chartInstance, c2_cell_wrap_46 c2_pMatrix[2]);
static void c2_emxFreeStruct_cell_wrap_46(SFc2_imagedetectorInstanceStruct
  *chartInstance, c2_cell_wrap_46 *c2_pStruct);
static int32_T c2_div_nzp_s32(SFc2_imagedetectorInstanceStruct *chartInstance,
  int32_T c2_numerator, int32_T c2_denominator, int32_T c2_EMLOvCount_src_loc,
  uint32_T c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T c2_length_src_loc);
static int32_T c2__s32_s64_(SFc2_imagedetectorInstanceStruct *chartInstance,
  int64_T c2_b, int32_T c2_EMLOvCount_src_loc, uint32_T c2_ssid_src_loc, int32_T
  c2_offset_src_loc, int32_T c2_length_src_loc);
static void init_dsm_address_info(SFc2_imagedetectorInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_imagedetectorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  emlrtLicenseCheckR2012b(&c2_st, (const char_T *)"image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_imagedetector = 0U;
}

static void initialize_params_c2_imagedetector(SFc2_imagedetectorInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_jit_animation_state_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_do_animation_call_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_st;
  c2_st = NULL;
  c2_st = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createcellmatrix(2, 1), false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", chartInstance->c2_y, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_b_y, 0, c2_c_y);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y",
    &chartInstance->c2_is_active_c2_imagedetector, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_b_y, 1, c2_d_y);
  sf_mex_assign(&c2_st, c2_b_y, false);
  return c2_st;
}

static void set_sim_state_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "y");
  chartInstance->c2_is_active_c2_imagedetector = c2_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_imagedetector");
  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static void sf_gateway_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  c2_emxArray_real_T *c2_centersDark;
  c2_emxArray_real_T *c2_radiiDark;
  emlrtStack c2_b_st;
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c2_b_y = NULL;
  real_T c2_b_c;
  real_T c2_c;
  real_T c2_c_c;
  real_T c2_c_y;
  real_T c2_d_a;
  real_T c2_d_c;
  real_T c2_e_a;
  real_T c2_f_a;
  real_T c2_g_a;
  real_T c2_h_a;
  real_T c2_i_a;
  real_T c2_j_a;
  real_T c2_k_a;
  real_T c2_l_a;
  real_T c2_m_a;
  real_T c2_n_a;
  real_T c2_o_a;
  real_T c2_p_a;
  real_T c2_q_a;
  real_T c2_r_a;
  real_T c2_s_a;
  real_T c2_t_a;
  real_T c2_u_a;
  real_T c2_v_a;
  real_T c2_w_a;
  real_T c2_xPos;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  boolean_T c2_b;
  boolean_T c2_b1;
  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  chartInstance->c2_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c2_i = 0; c2_i < 921600; c2_i++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U, (real_T)
                      (*chartInstance->c2_b_data)[c2_i]);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  for (c2_i1 = 0; c2_i1 < 921600; c2_i1++) {
    chartInstance->c2_data[c2_i1] = (*chartInstance->c2_b_data)[c2_i1];
  }

  c2_emxInit_real_T(chartInstance, &c2_st, &c2_centersDark, 2, &c2_emlrtRTEI);
  c2_emxInit_real_T(chartInstance, &c2_st, &c2_radiiDark, 2, &c2_b_emlrtRTEI);
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  c2_b_st.site = &c2_emlrtRSI;
  c2_imfindcircles(chartInstance, &c2_b_st, chartInstance->c2_data,
                   c2_centersDark, c2_radiiDark);
  c2_xPos = 0.0;
  sf_mex_printf("%s =\\n", "xPos");
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_xPos, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call(&c2_st, NULL, "disp", 0U, 1U, 14, c2_b_y);
  c2_b = (c2_centersDark->size[0] == 0);
  c2_b1 = (c2_centersDark->size[1] == 0);
  if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 0, covrtEmlMcdcEval
                     (chartInstance->c2_covrtInstance, 4U, 0, 0,
                      !covrtEmlCondEval(chartInstance->c2_covrtInstance, 4U, 0,
         0, c2_b || c2_b1)))) {
    c2_b_st.site = &c2_b_emlrtRSI;
    c2_b_st.site = &c2_b_emlrtRSI;
    c2_i2 = c2__s32_s64_(chartInstance, (int64_T)c2_radiiDark->size[0] *
                         (int64_T)c2_radiiDark->size[1], 0, 1U, 177, 12);
    c2_i3 = 1;
    if ((c2_i3 < 1) || (c2_i3 > c2_i2)) {
      emlrtDynamicBoundsCheckR2012b(c2_i3, 1, c2_i2, &c2_e_emlrtBCI, &c2_b_st);
    }

    c2_d_a = c2_radiiDark->data[c2_i3 - 1];
    c2_e_a = c2_d_a;
    c2_f_a = c2_e_a;
    c2_g_a = c2_f_a;
    c2_h_a = c2_g_a;
    c2_c = muDoubleScalarPower(c2_h_a, 5.0);
    c2_b_st.site = &c2_b_emlrtRSI;
    c2_i4 = c2__s32_s64_(chartInstance, (int64_T)c2_radiiDark->size[0] *
                         (int64_T)c2_radiiDark->size[1], 0, 1U, 204, 12);
    c2_i5 = 1;
    if ((c2_i5 < 1) || (c2_i5 > c2_i4)) {
      emlrtDynamicBoundsCheckR2012b(c2_i5, 1, c2_i4, &c2_f_emlrtBCI, &c2_b_st);
    }

    c2_i_a = c2_radiiDark->data[c2_i5 - 1];
    c2_j_a = c2_i_a;
    c2_k_a = c2_j_a;
    c2_l_a = c2_k_a;
    c2_m_a = c2_l_a;
    c2_b_c = muDoubleScalarPower(c2_m_a, 4.0);
    c2_b_st.site = &c2_b_emlrtRSI;
    c2_i6 = c2__s32_s64_(chartInstance, (int64_T)c2_radiiDark->size[0] *
                         (int64_T)c2_radiiDark->size[1], 0, 1U, 229, 12);
    c2_i7 = 1;
    if ((c2_i7 < 1) || (c2_i7 > c2_i6)) {
      emlrtDynamicBoundsCheckR2012b(c2_i7, 1, c2_i6, &c2_g_emlrtBCI, &c2_b_st);
    }

    c2_n_a = c2_radiiDark->data[c2_i7 - 1];
    c2_o_a = c2_n_a;
    c2_p_a = c2_o_a;
    c2_q_a = c2_p_a;
    c2_r_a = c2_q_a;
    c2_c_c = muDoubleScalarPower(c2_r_a, 3.0);
    c2_b_st.site = &c2_b_emlrtRSI;
    c2_i8 = c2__s32_s64_(chartInstance, (int64_T)c2_radiiDark->size[0] *
                         (int64_T)c2_radiiDark->size[1], 0, 1U, 252, 12);
    c2_i9 = 1;
    if ((c2_i9 < 1) || (c2_i9 > c2_i8)) {
      emlrtDynamicBoundsCheckR2012b(c2_i9, 1, c2_i8, &c2_h_emlrtBCI, &c2_b_st);
    }

    c2_s_a = c2_radiiDark->data[c2_i9 - 1];
    c2_t_a = c2_s_a;
    c2_u_a = c2_t_a;
    c2_v_a = c2_u_a;
    c2_w_a = c2_v_a;
    c2_d_c = c2_w_a * c2_w_a;
    c2_i10 = c2__s32_s64_(chartInstance, (int64_T)c2_radiiDark->size[0] *
                          (int64_T)c2_radiiDark->size[1], 0, 1U, 275, 12);
    c2_i11 = 1;
    if ((c2_i11 < 1) || (c2_i11 > c2_i10)) {
      emlrtDynamicBoundsCheckR2012b(c2_i11, 1, c2_i10, &c2_i_emlrtBCI, &c2_st);
    }

    c2_xPos = ((((-5.983E-7 * c2_c + 0.0001086 * c2_b_c) - 0.00788 * c2_c_c) +
                0.292 * c2_d_c) - 5.812 * c2_radiiDark->data[c2_i11 - 1]) + 59.0;
    c2_i12 = c2__s32_s64_(chartInstance, (int64_T)c2_centersDark->size[0] *
                          (int64_T)c2_centersDark->size[1], 0, 1U, 306, 14);
    c2_i13 = 1;
    if ((c2_i13 < 1) || (c2_i13 > c2_i12)) {
      emlrtDynamicBoundsCheckR2012b(c2_i13, 1, c2_i12, &c2_d_emlrtBCI, &c2_st);
    }

    c2_i14 = c2__s32_s64_(chartInstance, (int64_T)c2_radiiDark->size[0] *
                          (int64_T)c2_radiiDark->size[1], 0, 1U, 325, 12);
    c2_i15 = 1;
    if ((c2_i15 < 1) || (c2_i15 > c2_i14)) {
      emlrtDynamicBoundsCheckR2012b(c2_i15, 1, c2_i14, &c2_c_emlrtBCI, &c2_st);
    }

    c2_i16 = c2__s32_s64_(chartInstance, (int64_T)c2_centersDark->size[0] *
                          (int64_T)c2_centersDark->size[1], 0, 1U, 352, 14);
    c2_i17 = 2;
    if ((c2_i17 < 1) || (c2_i17 > c2_i16)) {
      emlrtDynamicBoundsCheckR2012b(c2_i17, 1, c2_i16, &c2_b_emlrtBCI, &c2_st);
    }

    c2_i18 = c2__s32_s64_(chartInstance, (int64_T)c2_radiiDark->size[0] *
                          (int64_T)c2_radiiDark->size[1], 0, 1U, 373, 12);
    c2_i19 = 1;
    if ((c2_i19 < 1) || (c2_i19 > c2_i18)) {
      emlrtDynamicBoundsCheckR2012b(c2_i19, 1, c2_i18, &c2_emlrtBCI, &c2_st);
    }
  }

  c2_emxFree_real_T(chartInstance, &c2_radiiDark);
  c2_emxFree_real_T(chartInstance, &c2_centersDark);
  c2_c_y = c2_xPos;
  *chartInstance->c2_y = c2_c_y;
  c2_do_animation_call_c2_imagedetector(chartInstance);
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U, *chartInstance->c2_y);
}

static void mdl_start_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance)
{
  static const int32_T c2_postfixPredicateTree[2] = { 0, -1 };

  static const int32_T c2_condTxtEndIdx[1] = { 156 };

  static const int32_T c2_condTxtStartIdx[1] = { 136 };

  static const uint32_T c2_decisionTxtEndIdx = 0U;
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c2_chart_data_browse_helper);
  chartInstance->c2_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c2_RuntimeVar,
    &chartInstance->c2_IsDebuggerActive,
    &chartInstance->c2_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c2_mlFcnLineNumber, &chartInstance->c2_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    4U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 1U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 401);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 132, 156, -1,
                    391);
  covrtEmlMCDCInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 135, 156, 1U,
                      0U, c2_condTxtStartIdx, c2_condTxtEndIdx, 2U,
                      c2_postfixPredicateTree);
}

static void mdl_cleanup_runtime_resources_c2_imagedetector
  (SFc2_imagedetectorInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c2_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void initSimStructsc2_imagedetector(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c2_imagedetector_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_warning(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_varargin_6)
{
  static char_T c2_msgID[44] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'f', 'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'w', 'a', 'r',
    'n', 'F', 'o', 'r', 'L', 'a', 'r', 'g', 'e', 'R', 'a', 'd', 'i', 'u', 's',
    'R', 'a', 'n', 'g', 'e' };

  static char_T c2_varargin_3[19] = { '(', 'R', 'm', 'a', 'x', ' ', '-', ' ',
    'R', 'm', 'i', 'n', ')', ' ', '<', ' ', '1', '0', '0' };

  static char_T c2_b_varargin_2[13] = { 'R', 'm', 'a', 'x', ' ', '<', ' ', '3',
    '*', 'R', 'm', 'i', 'n' };

  static char_T c2_f_varargin_1[13] = { 'I', 'M', 'F', 'I', 'N', 'D', 'C', 'I',
    'R', 'C', 'L', 'E', 'S' };

  static char_T c2_varargin_4[8] = { '[', '2', '0', ' ', '1', '0', '0', ']' };

  static char_T c2_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c2_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 44),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_f_varargin_1, 10, 0U, 1U, 0U, 2,
    1, 13), false);
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_varargin_2, 10, 0U, 1U, 0U, 2,
    1, 13), false);
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_varargin_3, 10, 0U, 1U, 0U, 2, 1,
    19), false);
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_varargin_4, 10, 0U, 1U, 0U, 2, 1,
    8), false);
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_f_varargin_1, 10, 0U, 1U, 0U, 2,
    1, 13), false);
  c2_st.site = &c2_c_emlrtRSI;
  c2_b_feval(chartInstance, &c2_st, c2_b_y, c2_feval(chartInstance, &c2_st,
              c2_c_y, c2_d_y, c2_e_y, c2_f_y, c2_g_y, c2_h_y, c2_i_y, sf_mex_dup
              (c2_varargin_6)));
  sf_mex_destroy(&c2_varargin_6);
}

static void c2_imfindcircles(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, uint8_T c2_f_varargin_1[921600], c2_emxArray_real_T
  *c2_centers, c2_emxArray_real_T *c2_r_estimated)
{
  static creal_T c2_dc = { 0.0,        /* re */
    0.0                                /* im */
  };

  static char_T c2_b_cv[119] = { '\\', 't', '[', 'C', 'E', 'N', 'T', 'E', 'R',
    'S', '1', ',', ' ', 'R', 'A', 'D', 'I', 'I', '1', ',', ' ', 'M', 'E', 'T',
    'R', 'I', 'C', '1', ']', ' ', '=', ' ', 'I', 'M', 'F', 'I', 'N', 'D', 'C',
    'I', 'R', 'C', 'L', 'E', 'S', '(', 'A', ',', ' ', '[', '2', '0', ' ', '6',
    '0', ']', ')', ';', '\\', 'n', '\\', 't', '[', 'C', 'E', 'N', 'T', 'E', 'R',
    'S', '2', ',', ' ', 'R', 'A', 'D', 'I', 'I', '2', ',', ' ', 'M', 'E', 'T',
    'R', 'I', 'C', '2', ']', ' ', '=', ' ', 'I', 'M', 'F', 'I', 'N', 'D', 'C',
    'I', 'R', 'C', 'L', 'E', 'S', '(', 'A', ',', ' ', '[', '6', '1', ' ', '1',
    '0', '0', ']', ')', ';' };

  c2_emxArray_boolean_T *c2_h_x;
  c2_emxArray_creal_T *c2_e_x;
  c2_emxArray_int32_T *c2_ii;
  c2_emxArray_real_T *c2_b_centers;
  c2_emxArray_real_T *c2_c_centers;
  c2_emxArray_real_T *c2_idx2Keep;
  c2_emxArray_real_T *c2_metric;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  creal_T c2_g_x;
  real_T c2_b_k;
  int32_T c2_iv[2];
  int32_T c2_b_idx;
  int32_T c2_b_ii;
  int32_T c2_b_loop_ub;
  int32_T c2_b_metric;
  int32_T c2_b_nx;
  int32_T c2_c_b;
  int32_T c2_c_ii;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_d_b;
  int32_T c2_d_centers;
  int32_T c2_d_loop_ub;
  int32_T c2_e_loop_ub;
  int32_T c2_f_loop_ub;
  int32_T c2_g_loop_ub;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_k;
  int32_T c2_loop_ub;
  int32_T c2_nx;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b3;
  boolean_T c2_b4;
  boolean_T c2_b5;
  boolean_T c2_b6;
  boolean_T c2_b7;
  boolean_T c2_b_b;
  boolean_T c2_c_y;
  boolean_T c2_exitg1;
  boolean_T c2_f_x;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_centers->size[0] = 0;
  c2_centers->size[1] = 0;
  c2_r_estimated->size[0] = 0;
  c2_r_estimated->size[1] = 0;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  c2_st.site = &c2_f_emlrtRSI;
  c2_warning(chartInstance, &c2_st, c2_sprintf(chartInstance, &c2_st, c2_b_y));
  c2_st.site = &c2_g_emlrtRSI;
  for (c2_i = 0; c2_i < 921600; c2_i++) {
    chartInstance->c2_b_varargin_1[c2_i] = c2_f_varargin_1[c2_i];
  }

  c2_chaccum(chartInstance, &c2_st, chartInstance->c2_b_varargin_1,
             chartInstance->c2_accumMatrix, chartInstance->c2_gradientImg);
  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    chartInstance->c2_x[c2_i1] = chartInstance->c2_accumMatrix[c2_i1];
  }

  c2_emxInit_creal_T(chartInstance, c2_sp, &c2_e_x, 1, &c2_c_emlrtRTEI);
  c2_i2 = c2_e_x->size[0];
  c2_e_x->size[0] = 307200;
  c2_emxEnsureCapacity_creal_T(chartInstance, c2_sp, c2_e_x, c2_i2,
    &c2_c_emlrtRTEI);
  for (c2_i3 = 0; c2_i3 < 307200; c2_i3++) {
    c2_e_x->data[c2_i3] = chartInstance->c2_x[c2_i3];
  }

  c2_c_y = false;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 307200)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_f_x = ((c2_e_x->data[(int32_T)c2_b_k - 1].re == c2_dc.re) &&
              (c2_e_x->data[(int32_T)c2_b_k - 1].im == c2_dc.im));
    if (c2_f_x) {
      c2_b = true;
    } else {
      c2_g_x = c2_e_x->data[(int32_T)c2_b_k - 1];
      c2_b1 = muDoubleScalarIsNaN(c2_g_x.re);
      c2_b2 = muDoubleScalarIsNaN(c2_g_x.im);
      c2_b_b = (c2_b1 || c2_b2);
      if (c2_b_b) {
        c2_b = true;
      } else {
        c2_b = false;
      }
    }

    if (!c2_b) {
      c2_c_y = true;
      c2_exitg1 = true;
    } else {
      c2_k++;
    }
  }

  c2_emxFree_creal_T(chartInstance, &c2_e_x);
  c2_emxInit_real_T1(chartInstance, c2_sp, &c2_idx2Keep, 1, &c2_g_emlrtRTEI);
  c2_emxInit_real_T(chartInstance, c2_sp, &c2_b_centers, 2, &c2_l_emlrtRTEI);
  c2_emxInit_real_T(chartInstance, c2_sp, &c2_metric, 2, &c2_l_emlrtRTEI);
  c2_emxInit_boolean_T(chartInstance, c2_sp, &c2_h_x, 2, &c2_e_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, c2_sp, &c2_ii, 1, &c2_m_emlrtRTEI);
  c2_emxInit_real_T(chartInstance, c2_sp, &c2_c_centers, 2, &c2_j_emlrtRTEI);
  if (!c2_c_y) {
  } else {
    c2_st.site = &c2_h_emlrtRSI;
    for (c2_i4 = 0; c2_i4 < 307200; c2_i4++) {
      chartInstance->c2_b_accumMatrix[c2_i4] = chartInstance->
        c2_accumMatrix[c2_i4];
    }

    c2_chcenters(chartInstance, &c2_st, chartInstance->c2_b_accumMatrix,
                 c2_b_centers, c2_metric);
    c2_i5 = c2_centers->size[0] * c2_centers->size[1];
    c2_centers->size[0] = c2_b_centers->size[0];
    c2_centers->size[1] = c2_b_centers->size[1];
    c2_st.site = &c2_si_emlrtRSI;
    c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_centers, c2_i5,
      &c2_d_emlrtRTEI);
    c2_loop_ub = c2_b_centers->size[0] * c2_b_centers->size[1] - 1;
    for (c2_i6 = 0; c2_i6 <= c2_loop_ub; c2_i6++) {
      c2_centers->data[c2_i6] = c2_b_centers->data[c2_i6];
    }

    c2_b3 = (c2_b_centers->size[0] == 0);
    c2_b4 = (c2_b_centers->size[1] == 0);
    if (c2_b3 || c2_b4) {
    } else {
      c2_st.site = &c2_i_emlrtRSI;
      c2_i7 = c2_h_x->size[0] * c2_h_x->size[1];
      c2_h_x->size[0] = c2_metric->size[0];
      c2_h_x->size[1] = c2_metric->size[1];
      c2_b_st.site = &c2_ui_emlrtRSI;
      c2_emxEnsureCapacity_boolean_T(chartInstance, &c2_b_st, c2_h_x, c2_i7,
        &c2_e_emlrtRTEI);
      c2_b_loop_ub = c2_metric->size[0] * c2_metric->size[1] - 1;
      for (c2_i8 = 0; c2_i8 <= c2_b_loop_ub; c2_i8++) {
        c2_h_x->data[c2_i8] = (c2_metric->data[c2_i8] >= 0.07999999999999996);
      }

      c2_b_st.site = &c2_oh_emlrtRSI;
      c2_nx = c2_h_x->size[0] * c2_h_x->size[1];
      c2_c_st.site = &c2_ph_emlrtRSI;
      c2_c_k = c2_nx;
      c2_b_nx = c2_nx;
      c2_b_idx = 0;
      c2_i9 = c2_ii->size[0];
      c2_ii->size[0] = c2_c_k;
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_ii, c2_i9,
        &c2_f_emlrtRTEI);
      c2_d_st.site = &c2_qh_emlrtRSI;
      c2_c_b = c2_b_nx;
      c2_d_b = c2_c_b;
      if (1 > c2_d_b) {
        c2_overflow = false;
      } else {
        c2_overflow = (c2_d_b > 2147483646);
      }

      if (c2_overflow) {
        c2_e_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
      }

      c2_b_ii = 1;
      c2_exitg1 = false;
      while ((!c2_exitg1) && (c2_b_ii - 1 <= c2_b_nx - 1)) {
        c2_c_ii = c2_b_ii;
        if (c2_h_x->data[c2_c_ii - 1]) {
          c2_b_idx++;
          c2_ii->data[c2_b_idx - 1] = c2_c_ii;
          if (c2_b_idx >= c2_c_k) {
            c2_exitg1 = true;
          } else {
            c2_b_ii++;
          }
        } else {
          c2_b_ii++;
        }
      }

      if (!(c2_b_idx <= c2_c_k)) {
        c2_d_y = NULL;
        sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        c2_e_y = NULL;
        sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call(&c2_c_st, &c2_t_emlrtMCI, "error", 0U, 2U, 14, c2_d_y, 14,
                    sf_mex_call(&c2_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c2_c_st, NULL, "message", 1U, 1U, 14, c2_e_y)));
      }

      if (c2_c_k == 1) {
        if (c2_b_idx == 0) {
          c2_ii->size[0] = 0;
        }
      } else {
        c2_b5 = (1 > c2_b_idx);
        if (c2_b5) {
          c2_i10 = 0;
        } else {
          c2_i10 = c2_b_idx;
        }

        c2_iv[0] = 1;
        c2_iv[1] = c2_i10;
        c2_d_st.site = &c2_rh_emlrtRSI;
        c2_indexShapeCheck(chartInstance, &c2_d_st, c2_ii->size[0], c2_iv);
        c2_i13 = c2_ii->size[0];
        c2_ii->size[0] = c2_i10;
        c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_ii, c2_i13,
          &c2_h_emlrtRTEI);
      }

      c2_i11 = c2_idx2Keep->size[0];
      c2_idx2Keep->size[0] = c2_ii->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_idx2Keep, c2_i11,
        &c2_g_emlrtRTEI);
      c2_c_loop_ub = c2_ii->size[0] - 1;
      for (c2_i12 = 0; c2_i12 <= c2_c_loop_ub; c2_i12++) {
        c2_idx2Keep->data[c2_i12] = (real_T)c2_ii->data[c2_i12];
      }

      c2_d_centers = c2_b_centers->size[0];
      c2_i14 = c2_b_centers->size[1] - 1;
      c2_i15 = c2_centers->size[0] * c2_centers->size[1];
      c2_centers->size[0] = c2_idx2Keep->size[0];
      c2_centers->size[1] = c2_i14 + 1;
      c2_st.site = &c2_ri_emlrtRSI;
      c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_centers, c2_i15,
        &c2_i_emlrtRTEI);
      c2_d_loop_ub = c2_i14;
      for (c2_i16 = 0; c2_i16 <= c2_d_loop_ub; c2_i16++) {
        c2_e_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i17 = 0; c2_i17 <= c2_e_loop_ub; c2_i17++) {
          c2_i19 = (int32_T)c2_idx2Keep->data[c2_i17];
          if ((c2_i19 < 1) || (c2_i19 > c2_d_centers)) {
            emlrtDynamicBoundsCheckR2012b(c2_i19, 1, c2_d_centers,
              &c2_j_emlrtBCI, (void *)c2_sp);
          }

          c2_centers->data[c2_i17 + c2_centers->size[0] * c2_i16] =
            c2_b_centers->data[(c2_i19 + c2_b_centers->size[0] * c2_i16) - 1];
        }
      }

      c2_b_metric = c2_metric->size[0];
      c2_f_loop_ub = c2_idx2Keep->size[0] - 1;
      for (c2_i18 = 0; c2_i18 <= c2_f_loop_ub; c2_i18++) {
        c2_i20 = (int32_T)c2_idx2Keep->data[c2_i18];
        if ((c2_i20 < 1) || (c2_i20 > c2_b_metric)) {
          emlrtDynamicBoundsCheckR2012b(c2_i20, 1, c2_b_metric, &c2_k_emlrtBCI,
            (void *)c2_sp);
        }
      }

      c2_b6 = (c2_centers->size[0] == 0);
      c2_b7 = (c2_centers->size[1] == 0);
      if (c2_b6 || c2_b7) {
        c2_centers->size[0] = 0;
        c2_centers->size[1] = 0;
      } else {
        c2_i21 = c2_c_centers->size[0] * c2_c_centers->size[1];
        c2_c_centers->size[0] = c2_centers->size[0];
        c2_c_centers->size[1] = c2_centers->size[1];
        c2_st.site = &c2_qi_emlrtRSI;
        c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_c_centers, c2_i21,
          &c2_j_emlrtRTEI);
        c2_g_loop_ub = c2_centers->size[0] * c2_centers->size[1] - 1;
        for (c2_i22 = 0; c2_i22 <= c2_g_loop_ub; c2_i22++) {
          c2_c_centers->data[c2_i22] = c2_centers->data[c2_i22];
        }

        c2_st.site = &c2_j_emlrtRSI;
        c2_chradiiphcode(chartInstance, &c2_st, c2_c_centers,
                         chartInstance->c2_accumMatrix, c2_idx2Keep);
        c2_i23 = c2_r_estimated->size[0] * c2_r_estimated->size[1];
        c2_r_estimated->size[0] = c2_idx2Keep->size[0];
        c2_r_estimated->size[1] = 1;
        c2_st.site = &c2_qi_emlrtRSI;
        c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_r_estimated,
          c2_i23, &c2_k_emlrtRTEI);
        c2_h_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i24 = 0; c2_i24 <= c2_h_loop_ub; c2_i24++) {
          c2_r_estimated->data[c2_i24] = c2_idx2Keep->data[c2_i24];
        }
      }
    }
  }

  c2_emxFree_real_T(chartInstance, &c2_c_centers);
  c2_emxFree_int32_T(chartInstance, &c2_ii);
  c2_emxFree_boolean_T(chartInstance, &c2_h_x);
  c2_emxFree_real_T(chartInstance, &c2_metric);
  c2_emxFree_real_T(chartInstance, &c2_b_centers);
  c2_emxFree_real_T(chartInstance, &c2_idx2Keep);
}

static void c2_chaccum(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, uint8_T c2_f_varargin_1[921600], creal_T c2_c_accumMatrix
  [307200], real32_T c2_b_gradientImg[307200])
{
  static creal_T c2_Opca[581] = { { -1.0,/* re */
      -1.2246467991473532E-16          /* im */
    }, { -0.99594083601332251,         /* re */
      -0.09001028364072719             /* im */
    }, { -0.98453954055960058,         /* re */
      -0.17516247621762657             /* im */
    }, { -0.96685408372126735,         /* re */
      -0.25532955330613127             /* im */
    }, { -0.9438134151391725,          /* re */
      -0.33047880023283188             /* im */
    }, { -0.91623239065062168,         /* re */
      -0.40064723426306909             /* im */
    }, { -0.88482533095707427,         /* re */
      -0.46592288385172076             /* im */
    }, { -0.85021816548376461,         /* re */
      -0.52643049976366485             /* im */
    }, { -0.81295920958593748,         /* re */
      -0.58232063637604992             /* im */
    }, { -0.77352867128965785,         /* re */
      -0.63376130734911262             /* im */
    }, { -0.73234700438523037,         /* re */
      -0.680931615632568               /* im */
    }, { -0.68978222964392444,         /* re */
      -0.72401690288794807             /* im */
    }, { -0.64615634223689045,         /* re */
      -0.76320507164656759             /* im */
    }, { -0.60175091529856484,         /* re */
      -0.798683814746073               /* im */
    }, { -0.55681199947654147,         /* re */
      -0.83063854788887326             /* im */
    }, { -0.51155440768198834,         /* re */
      -0.8592508876813163              /* im */
    }, { -0.466165463900912,           /* re */
      -0.88469755298974773             /* im */
    }, { -0.42080828526553465,         /* re */
      -0.90714959463799594             /* im */
    }, { -0.37562465780675647,         /* re */
      -0.926771879400512               /* im */
    }, { -0.33073755846924613,         /* re */
      -0.94372277042455743             /* im */
    }, { -0.28625336905102278,         /* re */
      -0.958153958770165               /* im */
    }, { -0.24226382167007832,         /* re */
      -0.97021041053464707             /* im */
    }, { -0.19884771008391683,         /* re */
      -0.98003040166842914             /* im */
    }, { -0.15607239660998098,         /* re */
      -0.987745618576168               /* im */
    }, { -0.11399514043322742,         /* re */
      -0.993481307301556               /* im */
    }, { -0.072664269664041575,        /* re */
      -0.99735645779941262             /* im */
    }, { -0.0321202165546643,          /* re */
      -0.99948401272280563             /* im */
    }, { 0.0076035672676942924,        /* re */
      -0.99997109246458                /* im */
    }, { 0.046479800893563239,         /* re */
      -0.99891923002257532             /* im */
    }, { 0.08448665679191901,          /* re */
      -0.99642461070776678             /* im */
    }, { 0.12160712492206371,          /* re */
      -0.99257831286412335             /* im */
    }, { 0.15782844859826503,          /* re */
      -0.98746654668047606             /* im */
    }, { 0.19314162363599002,          /* re */
      -0.98117088889716531             /* im */
    }, { 0.22754095337146821,          /* re */
      -0.97376851178234514             /* im */
    }, { 0.261023653067805,            /* re */
      -0.96533240520513874             /* im */
    }, { 0.29358949802073719,          /* re */
      -0.95593159098961233             /* im */
    }, { 0.32524051037224333,          /* re */
      -0.94563132901400992             /* im */
    }, { 0.35598068024501733,          /* re */
      -0.93449331473921993             /* im */
    }, { 0.38581571733768233,          /* re */
      -0.92257586802127534             /* im */
    }, { 0.41475282958021786,          /* re */
      -0.90993411319457784             /* im */
    }, { 0.44280052585041374,          /* re */
      -0.89662015051335819             /* im */
    }, { 0.46996844010314076,          /* re */
      -0.88268321911488756             /* im */
    }, { 0.49626717457150255,          /* re */
      -0.86816985172419914             /* im */
    }, { 0.52170815996829867,          /* re */
      -0.85312402136060617             /* im */
    }, { 0.54630353085263117,          /* re */
      -0.8375872803343829              /* im */
    }, { 0.57006601453423167,          /* re */
      -0.82159889184020762             /* im */
    }, { 0.59300883207085664,          /* re */
      -0.805195954464476               /* im */
    }, { 0.61514561007506074,          /* re */
      -0.78841351992807762             /* im */
    }, { 0.63649030218862945,          /* re */
      -0.771284704386018               /* im */
    }, { 0.65705711920824938,          /* re */
      -0.75384079360151135             /* im */
    }, { 0.67686046695676194,          /* re */
      -0.73611134230568287             /* im */
    }, { 0.695914891092319,            /* re */
      -0.71812426804555618             /* im */
    }, { 0.7142350281345361,           /* re */
      -0.69990593981309968             /* im */
    }, { 0.73183556206369538,          /* re */
      -0.68148126173719192             /* im */
    }, { 0.74873118591730359,          /* re */
      -0.66287375210885235             /* im */
    }, { 0.76493656786899034,          /* re */
      -0.6441056179981739              /* im */
    }, { 0.78046632132864535,          /* re */
      -0.62519782570937632             /* im */
    }, { 0.7953349786507119,           /* re */
      -0.6061701673083818              /* im */
    }, { 0.80955696808030631,          /* re */
      -0.5870413234454811              /* im */
    }, { 0.82314659360497155,          /* re */
      -0.56782892268405261             /* im */
    }, { 0.83611801741387837,          /* re */
      -0.54854959753506827             /* im */
    }, { 0.84848524469670428,          /* re */
      -0.5292190373861978              /* im */
    }, { 0.86026211054156321,          /* re */
      -0.509852038503893               /* im */
    }, { 0.87146226871566024,          /* re */
      -0.49046255127680682             /* im */
    }, { 0.88209918213411842,          /* re */
      -0.4710637248593012              /* im */
    }, { 0.89218611484189148,          /* re */
      -0.45166794936471993             /* im */
    }, { 0.90173612535116665,          /* re */
      -0.43228689574941442             /* im */
    }, { 0.91076206119233616,          /* re */
      -0.4129315535202987              /* im */
    }, { 0.91927655455068891,          /* re */
      -0.39361226639094254             /* im */
    }, { 0.92729201887362089,          /* re */
      -0.3743387660038488              /* im */
    }, { 0.93482064634453255,          /* re */
      -0.3551202038296194              /* im */
    }, { 0.94187440612980189,          /* re */
      -0.33596518134716435             /* im */
    }, { 0.94846504331442538,          /* re */
      -0.31688177860294403             /* im */
    }, { 0.95460407845020823,          /* re */
      -0.29787758124140318             /* im */
    }, { 0.96030280764784781,          /* re */
      -0.27895970609330056             /* im */
    }, { 0.96557230315098685,          /* re */
      -0.26013482540347965             /* im */
    }, { 0.9704234143363788,           /* re */
      -0.24140918977479897             /* im */
    }, { 0.97486676908979153,          /* re */
      -0.22278864990037336             /* im */
    }, { 0.97891277551221145,          /* re */
      -0.20427867715201872             /* im */
    }, { 0.98257162391537922,          /* re */
      -0.18588438308877525             /* im */
    }, { 0.9858532890697207,           /* re */
      -0.16761053794560113             /* im */
    }, { 0.98876753267137851,          /* re */
      -0.14946158815881216             /* im */
    }, { 0.99132390599835163,          /* re */
      -0.1314416729814834              /* im */
    }, { 0.99353175272872207,          /* re */
      -0.11355464023893311             /* im */
    }, { 0.99540021189664751,          /* re */
      -0.095804061271478461            /* im */
    }, { 0.99693822096423979,          /* re */
      -0.078193245108874584            /* im */
    }, { 0.99815451898965057,          /* re */
      -0.060725251918286767            /* im */
    }, { 0.9990576498736875,           /* re */
      -0.043402905765219636            /* im */
    }, { 0.9996559656690932,           /* re */
      -0.02622880672452978             /* im */
    }, { 0.99995762993825432,          /* re */
      -0.00920534237653137             /* im */
    }, { 0.99997062114659385,          /* re */
      0.0076653012788345624            /* im */
    }, { 0.99970273608024152,          /* re */
      0.024381129458641869             /* im */
    }, { 0.99916159327779464,          /* re */
      0.040940328755138755             /* im */
    }, { 0.99835463646708311,          /* re */
      0.057341257787724906             /* im */
    }, { 0.99728913799884833,          /* re */
      0.0735824383227011               /* im */
    }, { 0.99597220227015315,          /* re */
      0.089662546836129522             /* im */
    }, { 0.99441076913115489,          /* re */
      0.10558040649658915              /* im */
    }, { 0.99261161726961411,          /* re */
      0.12133497954588829              /* im */
    }, { 0.990581367568186,            /* re */
      0.1369253600570117               /* im */
    }, { 0.98832648643014165,          /* re */
      0.15235076704976258              /* im */
    }, { 0.9858532890697207,           /* re */
      0.16761053794560071              /* im */
    }, { 0.98316794276381114,          /* re */
      0.18270412234423011              /* im */
    }, { 0.98027647006210028,          /* re */
      0.19763107610542507              /* im */
    }, { 0.97718475195324361,          /* re */
      0.21239105572052153              /* im */
    }, { 0.97389853098497292,          /* re */
      0.22698381295879155              /* im */
    }, { 0.9704234143363788,           /* re */
      0.24140918977479897              /* im */
    }, { 0.96676487684092283,          /* re */
      0.25566711346349441              /* im */
    }, { 0.96292826395897813,          /* re */
      0.2697575920506195               /* im */
    }, { 0.95891879469896,             /* re */
      0.28368070990656685              /* im */
    }, { 0.95474156448630787,          /* re */
      0.29743662357254719              /* im */
    }, { 0.95040154797978849,          /* re */
      0.31102555778845842              /* im */
    }, { 0.94590360183475408,          /* re */
      0.32444780171244647              /* im */
    }, { 0.94125246741315416,          /* re */
      0.337703705322653                /* im */
    }, { 0.93645277344022593,          /* re */
      0.35079367599218331              /* im */
    }, { 0.93150903860794088,          /* re */
      0.36371817522871974              /* im */
    }, { 0.92642567412535259,          /* re */
      0.37647771557077059              /* im */
    }, { 0.921206986216138,            /* re */
      0.38907285763283483              /* im */
    }, { 0.91585717856366777,          /* re */
      0.40150420729227487              /* im */
    }, { 0.91038035470405143,          /* re */
      0.41377241301097573              /* im */
    }, { 0.90478052036765322,          /* re */
      0.42587816328527417              /* im */
    }, { 0.89906158576963091,          /* re */
      0.43782218421797303              /* im */
    }, { 0.89322736785012458,          /* re */
      0.44960523720652795              /* im */
    }, { 0.88728159246472826,          /* re */
      0.46122811674187414              /* im */
    }, { 0.88122789652595934,          /* re */
      0.47269164831254745              /* im */
    }, { 0.87506983009643713,          /* re */
      0.48399668640910409              /* im */
    }, { 0.86881085843453232,          /* re */
      0.49514411262404312              /* im */
    }, { 0.86245436399325937,          /* re */
      0.506134833842705                /* im */
    }, { 0.85600364837320753,          /* re */
      0.51696978052083287              /* im */
    }, { 0.849461934230326,            /* re */
      0.52764990504469289              /* im */
    }, { 0.84283236713937371,          /* re */
      0.53817618016987712              /* im */
    }, { 0.83611801741387859,          /* re */
      0.54854959753506793              /* im */
    }, { 0.82932188188342448,          /* re */
      0.558771166247271                /* im */
    }, { 0.82244688562912094,          /* re */
      0.56884191153514663              /* im */
    }, { 0.81549588367808756,          /* re */
      0.5787628734672734               /* im */
    }, { 0.80847166265778836,          /* re */
      0.58853510573231849              /* im */
    }, { 0.80137694241106483,          /* re */
      0.59815967447822238              /* im */
    }, { 0.79421437757268276,          /* re */
      0.60763765720767837              /* im */
    }, { 0.78698655910823778,          /* re */
      0.61697014172727693              /* im */
    }, { 0.77969601581621861,          /* re */
      0.62615822514785746              /* im */
    }, { 0.77234521579406457,          /* re */
      0.635203012933676                /* im */
    }, { 0.76493656786899089,          /* re */
      0.64410561799817323              /* im */
    }, { 0.75747242299439665,          /* re */
      0.65286715984417365              /* im */
    }, { 0.7499550756126333,           /* re */
      0.66148876374648224              /* im */
    }, { 0.7423867649848972,           /* re */
      0.66997155997494329              /* im */
    }, { 0.73476967648900893,          /* re */
      0.67831668305610548              /* im */
    }, { 0.7271059428858393,           /* re */
      0.68652527107171712              /* im */
    }, { 0.71939764555509245,          /* re */
      0.69459846499239375              /* im */
    }, { 0.7116468157011997,           /* re */
      0.70253740804482623              /* im */
    }, { 0.7038554355300024,           /* re */
      0.7103432451110312               /* im */
    }, { 0.696025439396943,            /* re */
      0.71801712215816449              /* im */
    }, { 0.68815871492744241,          /* re */
      0.725560185697514                /* im */
    }, { 0.680257104110124,            /* re */
      0.73297358227135856              /* im */
    }, { 0.67232240436355428,          /* re */
      0.74025845796641154              /* im */
    }, { 0.664356369577126,            /* re */
      0.74741595795266591              /* im */
    }, { 0.65636071112674788,          /* re */
      0.75444722604645442              /* im */
    }, { 0.64833709886590141,          /* re */
      0.76135340429668164              /* im */
    }, { 0.6402871620927284,           /* re */
      0.7681356325931249               /* im */
    }, { 0.63221249049369488,          /* re */
      0.77479504829584434              /* im */
    }, { 0.62411463506442444,          /* re */
      0.78133278588473443              /* im */
    }, { 0.615995109008277,            /* re */
      0.78774997662829593              /* im */
    }, { 0.60785538861319421,          /* re */
      0.79404774827078417              /* im */
    }, { 0.5996969141073768,           /* re */
      0.80022722473688024              /* im */
    }, { 0.59152109049430912,          /* re */
      0.80628952585310409              /* im */
    }, { 0.583329288367636,            /* re */
      0.81223576708521483              /* im */
    }, { 0.57512284470642006,          /* re */
      0.81806705929085977              /* im */
    }, { 0.56690306365122456,          /* re */
      0.8237845084868104               /* im */
    }, { 0.55867121726155056,          /* re */
      0.82938921563009083              /* im */
    }, { 0.55042854625505222,          /* re */
      0.8348822764123992               /* im */
    }, { 0.54217626072900971,          /* re */
      0.8402647810671996               /* im */
    }, { 0.533915540864493,            /* re */
      0.8455378141889196               /* im */
    }, { 0.52564753761365413,          /* re */
      0.85070245456369886              /* im */
    }, { 0.517373373370563,            /* re */
      0.85575977501116751              /* im */
    }, { 0.50909414262600639,          /* re */
      0.86071084223674765              /* im */
    }, { 0.50081091260664812,          /* re */
      0.86555671669399936              /* im */
    }, { 0.49252472389894064,          /* re */
      0.87029845245655368              /* im */
    }, { 0.48423659105816758,          /* re */
      0.87493709709919432              /* im */
    }, { 0.47594750320299617,          /* re */
      0.8794736915876642               /* im */
    }, { 0.46765842459589552,          /* re */
      0.8839092701768011               /* im */
    }, { 0.459370295209771,            /* re */
      0.88824486031661776              /* im */
    }, { 0.45108403128117708,          /* re */
      0.89248148256595339              /* im */
    }, { 0.44280052585041335,          /* re */
      0.8966201505133583               /* im */
    }, { 0.43452064928886913,          /* re */
      0.90066187070486092              /* im */
    }, { 0.42624524981389095,          /* re */
      0.9046076425783135               /* im */
    }, { 0.41797515399153,             /* re */
      0.90845845840399153              /* im */
    }, { 0.409711167227429,            /* re */
      0.91221530323117128              /* im */
    }, { 0.40145407424618079,          /* re */
      0.91587915484038718              /* im */
    }, { 0.3932046395594197,           /* re */
      0.91945098370111433              /* im */
    }, { 0.38496360792292655,          /* re */
      0.92293175293461616              /* im */
    }, { 0.37673170478304435,          /* re */
      0.92632241828170236              /* im */
    }, { 0.36850963671264247,          /* re */
      0.929623928075174                /* im */
    }, { 0.36029809183690076,          /* re */
      0.932837223216724                /* im */
    }, { 0.35209774024916379,          /* re */
      0.93596323715808                 /* im */
    }, { 0.34390923441711224,          /* re */
      0.93900289588618191              /* im */
    }, { 0.33573320957948832,          /* re */
      0.94195711791219849              /* im */
    }, { 0.32757028413361389,          /* re */
      0.94482681426419279              /* im */
    }, { 0.31942106001390458,          /* re */
      0.9476128884832633               /* im */
    }, { 0.31128612306165693,          /* re */
      0.950316236622969                /* im */
    }, { 0.30316604338624459,          /* re */
      0.952937747251902                /* im */
    }, { 0.29506137571800956,          /* re */
      0.95547830145921975              /* im */
    }, { 0.28697265975299696,          /* re */
      0.95793877286301066              /* im */
    }, { 0.27890042048977431,          /* re */
      0.9603200276213274               /* im */
    }, { 0.27084516855849305,          /* re */
      0.96262292444576736              /* im */
    }, { 0.26280740054240825,          /* re */
      0.96484831461745435              /* im */
    }, { 0.25478759929202521,          /* re */
      0.96699704200530334              /* im */
    }, { 0.2467862342320688,           /* re */
      0.96906994308643923              /* im */
    }, { 0.23880376166142234,          /* re */
      0.971067846968663                /* im */
    }, { 0.2308406250462417,           /* re */
      0.97299157541484416              /* im */
    }, { 0.22289725530638047,          /* re */
      0.97484194286914139              /* im */
    }, { 0.21497407109530284,          /* re */
      0.97661975648494415              /* im */
    }, { 0.20707147907363999,          /* re */
      0.978325816154442                /* im */
    }, { 0.19918987417654446,          /* re */
      0.97996091453972412              /* im */
    }, { 0.1913296398749865,           /* re */
      0.98152583710532448              /* im */
    }, { 0.18349114843114053,          /* re */
      0.983021362152126                /* im */
    }, { 0.17567476114801009,          /* re */
      0.98444826085253945              /* im */
    }, { 0.16788082861342124,          /* re */
      0.9858072972868841               /* im */
    }, { 0.16010969093851868,          /* re */
      0.98709922848089193              /* im */
    }, { 0.15236167799090605,          /* re */
      0.9883248044442654               /* im */
    }, { 0.14463710962255469,          /* re */
      0.98948476821022013              /* im */
    }, { 0.136936295892586,            /* re */
      0.9905798558759501               /* im */
    }, { 0.12925953728509212,          /* re */
      0.99161079664394736              /* im */
    }, { 0.12160712492206481,          /* re */
      0.99257831286412324              /* im */
    }, { 0.11397934077158089,          /* re */
      0.99348312007667039              /* im */
    }, { 0.10637645785135111,          /* re */
      0.99432592705561074              /* im */
    }, { 0.098798740427729653,         /* re */
      0.99510743585298067              /* im */
    }, { 0.0912464442102987,           /* re */
      0.99582834184360147              /* im */
    }, { 0.083719816542146649,         /* re */
      0.99648933377038673              /* im */
    }, { 0.07621909658591304,          /* re */
      0.99709109379014471              /* im */
    }, { 0.068744515505716308,         /* re */
      0.99763429751982979              /* im */
    }, { 0.061296296645076825,         /* re */
      0.99811961408320138              /* im */
    }, { 0.05387465570088782,          /* re */
      0.99854770615785338              /* im */
    }, { 0.046479800893563017,         /* re */
      0.99891923002257532              /* im */
    }, { 0.039111933133441426,         /* re */
      0.99923483560500692              /* im */
    }, { 0.031771246183522825,         /* re */
      0.9994951665295565               /* im */
    }, { 0.024457926818632288,         /* re */
      0.99970086016554693              /* im */
    }, { 0.017172154981101438,         /* re */
      0.99985254767555853              /* im */
    }, { 0.0099141039330275134,        /* re */
      0.999950854063941                /* im */
    }, { 0.0026839404052147841,        /* re */
      0.99999639822546427              /* im */
    }, { -0.0045181752571572436,       /* re */
      0.99998979299408131              /* im */
    }, { -0.011692088952017846,        /* re */
      0.99993164519177913              /* im */
    }, { -0.018837652681025739,        /* re */
      0.99982255567749068              /* im */
    }, { -0.025954724413188766,        /* re */
      0.999663119396047                /* im */
    }, { -0.033043167951488435,        /* re */
      0.99945392542714528              /* im */
    }, { -0.040102852802361054,        /* re */
      0.99919555703431351              /* im */
    }, { -0.047133654048042907,        /* re */
      0.99888859171385047              /* im */
    }, { -0.05413545222165058,         /* re */
      0.99853360124372248              /* im */
    }, { -0.061108133184995438,        /* re */
      0.99813115173239875              /* im */
    }, { -0.068051588009010955,        /* re */
      0.99768180366760817              /* im */
    }, { -0.074965712856775349,        /* re */
      0.997186111965001                /* im */
    }, { -0.081850408869056368,        /* re */
      0.99664462601670023              /* im */
    }, { -0.088705582052318932,        /* re */
      0.99605788973972753              /* im */
    }, { -0.095531143169135246,        /* re */
      0.99542644162429106              /* im */
    }, { -0.10232700763096164,         /* re */
      0.99475081478191973              /* im */
    }, { -0.10909309539321364,         /* re */
      0.99403153699343316              /* im */
    }, { -0.11582933085258058,         /* re */
      0.99326913075673673              /* im */
    }, { -0.12253564274655639,         /* re */
      0.992464113334426                /* im */
    }, { -0.12921196405510926,         /* re */
      0.991616996801195                /* im */
    }, { -0.13585823190445143,         /* re */
      0.99072828809103675              /* im */
    }, { -0.14247438747287119,         /* re */
      0.98979848904422463              /* im */
    }, { -0.14906037589857424,         /* re */
      0.98882809645406811              /* im */
    }, { -0.1556161461894788,          /* re */
      0.98781760211343406              /* im */
    }, { -0.16214165113493884,         /* re */
      0.98676749286102639              /* im */
    }, { -0.1686368472193443,          /* re */
      0.98567825062741421              /* im */
    }, { -0.17510169453755875,         /* re */
      0.984550352480804                /* im */
    }, { -0.18153615671214318,         /* re */
      0.98338427067255052              /* im */
    }, { -0.18794020081235019,         /* re */
      0.98218047268239528              /* im */
    }, { -0.19431379727481879,         /* re */
      0.98093942126343392              /* im */
    }, { -0.20065691982596073,         /* re */
      0.979661574486801                /* im */
    }, { -0.20696954540598347,         /* re */
      0.97834738578607161              /* im */
    }, { -0.21325165409451513,         /* re */
      0.97699730400137408              /* im */
    }, { -0.2195032290378077,          /* re */
      0.97561177342320737              /* im */
    }, { -0.22572425637747198,         /* re */
      0.97419123383596373              /* im */
    }, { -0.23191472518071413,         /* re */
      0.97273612056114878              /* im */
    }, { -0.23807462737204141,         /* re */
      0.97124686450029973              /* im */
    }, { -0.2442039576664122,          /* re */
      0.96972389217759358              /* im */
    }, { -0.25030271350378241,         /* re */
      0.9681676257821491               /* im */
    }, { -0.25637089498503451,         /* re */
      0.96657848321001461              /* im */
    }, { -0.26240850480924527,         /* re */
      0.96495687810584385              /* im */
    }, { -0.26841554821228569,         /* re */
      0.96330321990425116              /* im */
    }, { -0.27439203290667985,         /* re */
      0.96161791387085727              /* im */
    }, { -0.28033796902275926,         /* re */
      0.95990136114300539              /* im */
    }, { -0.28625336905102189,         /* re */
      0.95815395877016518              /* im */
    }, { -0.29213824778571351,         /* re */
      0.9563760997540105               /* im */
    }, { -0.29799262226958162,         /* re */
      0.95456817308817632              /* im */
    }, { -0.30381651173978275,         /* re */
      0.95273056379769328              /* im */
    }, { -0.30960993757493238,         /* re */
      0.95086365297809472              /* im */
    }, { -0.31537292324324639,         /* re */
      0.94896781783420314              /* im */
    }, { -0.32110549425177087,         /* re */
      0.94704343171859118              /* im */
    }, { -0.32680767809667344,         /* re */
      0.94509086416971622              /* im */
    }, { -0.3324795042145654,          /* re */
      0.943110480949733                /* im */
    }, { -0.33812100393483963,         /* re */
      0.94110264408198119              /* im */
    }, { -0.34373221043300795,         /* re */
      0.93906771188814619              /* im */
    }, { -0.34931315868500085,         /* re */
      0.9370060390251                  /* im */
    }, { -0.3548638854224247,          /* re */
      0.93491797652141673              /* im */
    }, { -0.36038442908874158,         /* re */
      0.93280387181356716              /* im */
    }, { -0.36587482979637592,         /* re */
      0.9306640687817882               /* im */
    }, { -0.37133512928469381,         /* re */
      0.92849890778563637              /* im */
    }, { -0.37676537087886852,         /* re */
      0.92630872569921774              /* im */
    }, { -0.382165599449595,           /* re */
      0.92409385594610016              /* im */
    }, { -0.38753586137364809,         /* re */
      0.92185462853390532              /* im */
    }, { -0.39287620449524552,         /* re */
      0.91959137008858993              /* im */
    }, { -0.39818667808822905,         /* re */
      0.91730440388840451              /* im */
    }, { -0.40346733281901853,         /* re */
      0.914994049897543                /* im */
    }, { -0.40871822071034192,         /* re */
      0.91266062479947729              /* im */
    }, { -0.41393939510571082,         /* re */
      0.91030444202998273              /* im */
    }, { -0.41913091063464303,         /* re */
      0.90792581180984988              /* im */
    }, { -0.42429282317859235,         /* re */
      0.90552504117729393              /* im */
    }, { -0.42942518983759853,         /* re */
      0.90310243402005208              /* im */
    }, { -0.43452806889762019,         /* re */
      0.90065829110717954              /* im */
    }, { -0.43960151979854617,         /* re */
      0.89819291012054225              /* im */
    }, { -0.44464560310287465,         /* re */
      0.89570658568600514              /* im */
    }, { -0.449660380465035,           /* re */
      0.89319960940432563              /* im */
    }, { -0.454645914601351,           /* re */
      0.89067226988174564              /* im */
    }, { -0.45960226926062381,         /* re */
      0.888124852760289                /* im */
    }, { -0.46452950919532177,         /* re */
      0.88555764074776833              /* im */
    }, { -0.46942770013338064,         /* re */
      0.88297091364749092              /* im */
    }, { -0.474296908750568,           /* re */
      0.88036494838768731              /* im */
    }, { -0.47913720264344273,         /* re */
      0.87774001905063925              /* im */
    }, { -0.48394865030285511,         /* re */
      0.87509639690153274              /* im */
    }, { -0.48873132108801376,         /* re */
      0.87243435041701833              /* im */
    }, { -0.493485285201077,           /* re */
      0.869754145313497                /* im */
    }, { -0.498210613662287,           /* re */
      0.86705604457511709              /* im */
    }, { -0.50290737828559751,         /* re */
      0.86434030848150711              /* im */
    }, { -0.50757565165483665,         /* re */
      0.86160719463521651              /* im */
    }, { -0.512215507100335,           /* re */
      0.85885695798889972              /* im */
    }, { -0.51682701867606484,         /* re */
      0.85608985087221456              /* im */
    }, { -0.52141026113724021,         /* re */
      0.85330612301845987              /* im */
    }, { -0.52596530991838353,         /* re */
      0.850506021590946                /* im */
    }, { -0.53049224111185456,         /* re */
      0.84768979120909671              /* im */
    }, { -0.53499113144682375,         /* re */
      0.84485767397428979              /* im */
    }, { -0.53946205826868066,         /* re */
      0.84200990949543975              /* im */
    }, { -0.54390509951887778,         /* re */
      0.83914673491431746              /* im */
    }, { -0.548320333715185,           /* re */
      0.83626838493062028              /* im */
    }, { -0.55270783993236494,         /* re */
      0.83337509182678315              /* im */
    }, { -0.55706769778325549,         /* re */
      0.83046708549253379              /* im */
    }, { -0.56139998740022712,         /* re */
      0.82754459344921394              /* im */
    }, { -0.565704789417053,           /* re */
      0.82460784087383487              /* im */
    }, { -0.5699821849511395,          /* re */
      0.82165705062290129              /* im */
    }, { -0.57423225558614255,         /* re */
      0.81869244325598312              /* im */
    }, { -0.57845508335493523,         /* re */
      0.81571423705905421              /* im */
    }, { -0.58265075072294836,         /* re */
      0.81272264806758321              /* im */
    }, { -0.58681934057184237,         /* re */
      0.809717890089399                /* im */
    }, { -0.59096093618353618,         /* re */
      0.8067001747273137               /* im */
    }, { -0.59507562122456648,         /* re */
      0.80366971140151622              /* im */
    }, { -0.59916347973077888,         /* re */
      0.80062670737173425              /* im */
    }, { -0.60322459609234069,         /* re */
      0.79757136775916959              /* im */
    }, { -0.60725905503906352,         /* re */
      0.79450389556821155              /* im */
    }, { -0.61126694162604878,         /* re */
      0.79142449170791818              /* im */
    }, { -0.61524834121962368,         /* re */
      0.78833335501328472              /* im */
    }, { -0.61920333948358419,         /* re */
      0.78523068226628612              /* im */
    }, { -0.623132022365726,           /* re */
      0.78211666821670556              /* im */
    }, { -0.62703447608466378,         /* re */
      0.77899150560274488              /* im */
    }, { -0.63091078711691606,         /* re */
      0.77585538517143349              /* im */
    }, { -0.63476104218429941,         /* re */
      0.77270849569879985              /* im */
    }, { -0.63858532824154557,         /* re */
      0.76955102400986874              /* im */
    }, { -0.64238373246422265,         /* re */
      0.76638315499842113              /* im */
    }, { -0.64615634223688978,         /* re */
      0.76320507164656826              /* im */
    }, { -0.64990324514151909,         /* re */
      0.76001695504411115              /* im */
    }, { -0.65362452894615464,         /* re */
      0.75681898440770989              /* im */
    }, { -0.65732028159382583,         /* re */
      0.75361133709984318              /* im */
    }, { -0.6609905911916909,          /* re */
      0.75039418864757934              /* im */
    }, { -0.66463554600042229,         /* re */
      0.7471677127611448               /* im */
    }, { -0.66825523442380974,         /* re */
      0.74393208135230948              /* im */
    }, { -0.67184974499860006,         /* re */
      0.740687464552571                /* im */
    }, { -0.67541916638455346,         /* re */
      0.73743403073115277              /* im */
    }, { -0.678963587354707,           /* re */
      0.7341719465128228               /* im */
    }, { -0.682483096785868,           /* re */
      0.73090137679550948              /* im */
    }, { -0.68597778364929185,         /* re */
      0.72762248476775748              /* im */
    }, { -0.68944773700158679,         /* re */
      0.72433543192597649              /* im */
    }, { -0.69289304597579915,         /* re */
      0.72104037809153176              /* im */
    }, { -0.6963137997727048,          /* re */
      0.71773748142764393              /* im */
    }, { -0.69971008765228693,         /* re */
      0.7144268984561184               /* im */
    }, { -0.70308199892540613,         /* re */
      0.71110878407389622              /* im */
    }, { -0.706429622945652,           /* re */
      0.707783291569435                /* im */
    }, { -0.70975304910137016,         /* re */
      0.70445057263892408              /* im */
    }, { -0.713052366807881,           /* re */
      0.70111077740231542              /* im */
    }, { -0.71632766549985327,         /* re */
      0.69776405441920719              /* im */
    }, { -0.71957903462386019,         /* re */
      0.69441055070454782              /* im */
    }, { -0.72280656363110163,         /* re */
      0.69105041174417814              /* im */
    }, { -0.72601034197028147,         /* re */
      0.68768378151021936              /* im */
    }, { -0.72919045908065616,         /* re */
      0.68431080247628839              /* im */
    }, { -0.73234700438523,            /* re */
      0.68093161563256832              /* im */
    }, { -0.73548006728411452,         /* re */
      0.67754636050070727              /* im */
    }, { -0.73858973714802811,         /* re */
      0.67415517514857559              /* im */
    }, { -0.741676103311955,           /* re */
      0.67075819620485755              /* im */
    }, { -0.7447392550689369,          /* re */
      0.66735555887350262              /* im */
    }, { -0.74777928166401963,         /* re */
      0.6639473969480133               /* im */
    }, { -0.75079627228833068,         /* re */
      0.66053384282559424              /* im */
    }, { -0.75379031607329761,         /* re */
      0.65711502752114714              /* im */
    }, { -0.75676150208499515,         /* re */
      0.65369108068112869              /* im */
    }, { -0.75970991931863285,         /* re */
      0.650262130597251                /* im */
    }, { -0.76263565669316169,         /* re */
      0.64682830422005344              /* im */
    }, { -0.765538803046015,           /* re */
      0.6433897271723219               /* im */
    }, { -0.76841944712796861,         /* re */
      0.63994652376237415              /* im */
    }, { -0.77127767759812627,         /* re */
      0.63649881699720445              /* im */
    }, { -0.774113583019016,           /* re */
      0.63304672859549715              /* im */
    }, { -0.77692725185181732,         /* re */
      0.62959037900049175              /* im */
    }, { -0.77971877245168442,         /* re */
      0.62612988739273445              /* im */
    }, { -0.78248823306320336,         /* re */
      0.62266537170267133              /* im */
    }, { -0.78523572181593715,         /* re */
      0.61919694862313734              /* im */
    }, { -0.78796132672009633,         /* re */
      0.61572473362169367              /* im */
    }, { -0.790665135662305,           /* re */
      0.61224884095285048              /* im */
    }, { -0.79334723640147442,         /* re */
      0.6087693836701572               /* im */
    }, { -0.79600771656477909,         /* re */
      0.605286473638166                /* im */
    }, { -0.79864666364372772,         /* re */
      0.60180022154427826              /* im */
    }, { -0.80126416499033837,         /* re */
      0.59831073691045844              /* im */
    }, { -0.80386030781340745,         /* re */
      0.59481812810482992              /* im */
    }, { -0.80643517917486629,         /* re */
      0.59132250235315864              /* im */
    }, { -0.8089888659862412,          /* re */
      0.58782396575020279              /* im */
    }, { -0.81152145500519235,         /* re */
      0.58432262327095941              /* im */
    }, { -0.81403303283215267,         /* re */
      0.58081857878178056              /* im */
    }, { -0.81652368590703983,         /* re */
      0.57731193505139122              /* im */
    }, { -0.818993500506069,           /* re */
      0.57380279376177279              /* im */
    }, { -0.82144256273863259,         /* re */
      0.57029125551895654              /* im */
    }, { -0.82387095854427739,         /* re */
      0.566777419863683                /* im */
    }, { -0.82627877368975156,         /* re */
      0.56326138528196679              /* im */
    }, { -0.8286660937661332,          /* re */
      0.55974324921554719              /* im */
    }, { -0.831033004186035,           /* re */
      0.55622310807223163              /* im */
    }, { -0.83337959018088914,         /* re */
      0.55270105723612772              /* im */
    }, { -0.83570593679829919,         /* re */
      0.549177191077777                /* im */
    }, { -0.83801212889946985,         /* re */
      0.54565160296417925              /* im */
    }, { -0.84029825115670465,         /* re */
      0.54212438526871642              /* im */
    }, { -0.84256438805097611,         /* re */
      0.53859562938097094              /* im */
    }, { -0.84481062386956451,         /* re */
      0.53506542571644189              /* im */
    }, { -0.847037042703759,           /* re */
      0.53153386372616962              /* im */
    }, { -0.84924372844663,            /* re */
      0.52800103190625169              /* im */
    }, { -0.85143076479086321,         /* re */
      0.52446701780726468              /* im */
    }, { -0.85359823522665712,         /* re */
      0.52093190804359124              /* im */
    }, { -0.85574622303968317,         /* re */
      0.51739578830264621              /* im */
    }, { -0.85787481130910559,         /* re */
      0.51385874335401416              /* im */
    }, { -0.85998408290566419,         /* re */
      0.51032085705848218              /* im */
    }, { -0.86207412048980592,         /* re */
      0.50678221237700083              /* im */
    }, { -0.86414500650988724,         /* re */
      0.50324289137952749              /* im */
    }, { -0.86619682320042179,         /* re */
      0.49970297525379731              /* im */
    }, { -0.868229652580388,           /* re */
      0.49616254431399665              /* im */
    }, { -0.87024357645158934,         /* re */
      0.49262167800934908              /* im */
    }, { -0.87223867639706532,         /* re */
      0.489080454932617                /* im */
    }, { -0.87421503377955956,         /* re */
      0.48553895282850734              /* im */
    }, { -0.87617272974003124,         /* re */
      0.4819972486020041               /* im */
    }, { -0.87811184519622376,         /* re */
      0.47845541832660138              /* im */
    }, { -0.88003246084127529,         /* re */
      0.47491353725246582              /* im */
    }, { -0.88193465714238306,         /* re */
      0.47137167981450384              /* im */
    }, { -0.88381851433950809,         /* re */
      0.467829919640359                /* im */
    }, { -0.88568411244413292,         /* re */
      0.4642883295583129               /* im */
    }, { -0.88753153123805817,         /* re */
      0.46074698160511895              /* im */
    }, { -0.8893608502722441,          /* re */
      0.45720594703375295              /* im */
    }, { -0.8911721488657014,          /* re */
      0.45366529632107422              /* im */
    }, { -0.89296550610441261,         /* re */
      0.45012509917542942              /* im */
    }, { -0.8947410008403095,          /* re */
      0.44658542454415279              /* im */
    }, { -0.89649871169027606,         /* re */
      0.44304634062101822              /* im */
    }, { -0.89823871703520208,         /* re */
      0.43950791485359419              /* im */
    }, { -0.89996109501907351,         /* re */
      0.43597021395052915              /* im */
    }, { -0.90166592354809449,         /* re */
      0.43243330388877516              /* im */
    }, { -0.9033532802898584,          /* re */
      0.42889724992071526              /* im */
    }, { -0.90502324267253964,         /* re */
      0.4253621165812505               /* im */
    }, { -0.90667588788414344,         /* re */
      0.42182796769477027              /* im */
    }, { -0.908311292871764,           /* re */
      0.41829486638210678              /* im */
    }, { -0.90992953434090051,         /* re */
      0.41476287506737136              /* im */
    }, { -0.91153068875479426,         /* re */
      0.41123205548474751              /* im */
    }, { -0.91311483233380153,         /* re */
      0.4077024686852086               /* im */
    }, { -0.91468204105479833,         /* re */
      0.40417417504317155              /* im */
    }, { -0.91623239065062168,         /* re */
      0.40064723426306909              /* im */
    }, { -0.91776595660953242,         /* re */
      0.39712170538588021              /* im */
    }, { -0.91928281417471758,         /* re */
      0.39359764679557185              /* im */
    }, { -0.92078303834381781,         /* re */
      0.39007511622548707              /* im */
    }, { -0.92226670386848464,         /* re */
      0.386554170764669                /* im */
    }, { -0.92373388525396738,         /* re */
      0.383034866864115                /* im */
    }, { -0.92518465675872663,         /* re */
      0.37951726034297467              /* im */
    }, { -0.92661909239407647,         /* re */
      0.37600140639468083              /* im */
    }, { -0.92803726592385194,         /* re */
      0.37248735959302248              /* im */
    }, { -0.92943925086410328,         /* re */
      0.36897517389815593              /* im */
    }, { -0.93082512048281751,         /* re */
      0.36546490266255138              /* im */
    }, { -0.93219494779966239,         /* re */
      0.36195659863688717              /* im */
    }, { -0.93354880558575837,         /* re */
      0.35845031397587568              /* im */
    }, { -0.93488676636347023,         /* re */
      0.35494610024404288              /* im */
    }, { -0.93620890240622623,         /* re */
      0.35144400842144                 /* im */
    }, { -0.93751528573835763,         /* re */
      0.34794408890930389              /* im */
    }, { -0.93880598813496474,         /* re */
      0.34444639153565304              /* im */
    }, { -0.94008108112179889,         /* re */
      0.340950965560841                /* im */
    }, { -0.94134063597517192,         /* re */
      0.33745785968304082              /* im */
    }, { -0.94258472372188429,         /* re */
      0.33396712204368134              /* im */
    }, { -0.94381341513917238,         /* re */
      0.33047880023283233              /* im */
    }, { -0.94502678075468,            /* re */
      0.32699294129452688              /* im */
    }, { -0.94622489084644612,         /* re */
      0.32350959173203997              /* im */
    }, { -0.947407815442914,           /* re */
      0.32002879751310737              /* im */
    }, { -0.94857562432295728,         /* re */
      0.31655060407510177              /* im */
    }, { -0.94972838701592877,         /* re */
      0.31307505633014321              /* im */
    }, { -0.95086617280172125,         /* re */
      0.30960219867017597              /* im */
    }, { -0.95198905071085349,         /* re */
      0.30613207497197686              /* im */
    }, { -0.95309708952456518,         /* re */
      0.30266472860213339              /* im */
    }, { -0.9541903577749371,          /* re */
      0.29920020242195289              /* im */
    }, { -0.95526892374502148,         /* re */
      0.29573853879234                 /* im */
    }, { -0.95633285546899227,         /* re */
      0.29227977957861456              /* im */
    }, { -0.95738222073231027,         /* re */
      0.28882396615528633              /* im */
    }, { -0.95841708707190287,         /* re */
      0.28537113941078285              /* im */
    }, { -0.95943752177636121,         /* re */
      0.28192133975212724              /* im */
    }, { -0.96044359188614836,         /* re */
      0.27847460710957783              /* im */
    }, { -0.961435364193827,           /* re */
      0.27503098094120831              /* im */
    }, { -0.96241290524429668,         /* re */
      0.27159050023745768              /* im */
    }, { -0.96337628133504782,         /* re */
      0.26815320352562427              /* im */
    }, { -0.964325558516428,           /* re */
      0.26471912887432064              /* im */
    }, { -0.96526080259192082,         /* re */
      0.26128831389788709              /* im */
    }, { -0.96618207911844,            /* re */
      0.25786079576075244              /* im */
    }, { -0.967089453406633,           /* re */
      0.25443661118176319              /* im */
    }, { -0.96798299052119974,         /* re */
      0.25101579643846111              /* im */
    }, { -0.968862755281221,           /* re */
      0.24759838737132542              /* im */
    }, { -0.969728812260501,           /* re */
      0.24418441938796578              /* im */
    }, { -0.97058122578791861,         /* re */
      0.24077392746728477              /* im */
    }, { -0.971420059947791,           /* re */
      0.23736694616359319              /* im */
    }, { -0.97224537858025017,         /* re */
      0.23396350961067858              /* im */
    }, { -0.973057245281627,           /* re */
      0.23056365152584571              /* im */
    }, { -0.97385572340484583,         /* re */
      0.22716740521391812              /* im */
    }, { -0.97464087605983241,         /* re */
      0.22377480357118482              /* im */
    }, { -0.9754127661139288,          /* re */
      0.22038587908932386              /* im */
    }, { -0.9761714561923176,          /* re */
      0.21700066385928457              /* im */
    }, { -0.97691700867845832,         /* re */
      0.21361918957512444              /* im */
    }, { -0.97764948571452948,         /* re */
      0.21024148753782182              /* im */
    }, { -0.97836894920188333,         /* re */
      0.20686758865903246              /* im */
    }, { -0.9790754608015052,          /* re */
      0.20349752346483294              /* im */
    }, { -0.97976908193448464,         /* re */
      0.2001313220994082               /* im */
    }, { -0.98044987378249437,         /* re */
      0.19676901432870711              /* im */
    }, { -0.9811178972882737,          /* re */
      0.19341062954407748              /* im */
    }, { -0.98177321315612565,         /* re */
      0.19005619676584251              /* im */
    }, { -0.98241588185241613,         /* re */
      0.18670574464686293              /* im */
    }, { -0.98304596360608509,         /* re */
      0.18335930147604626              /* im */
    }, { -0.98366351840916189,         /* re */
      0.18001689518183697              /* im */
    }, { -0.98426860601728672,         /* re */
      0.17667855333567561              /* im */
    }, { -0.98486128595024469,         /* re */
      0.17334430315539759              /* im */
    }, { -0.985441617492499,           /* re */
      0.17001417150863418              /* im */
    }, { -0.98600965969373633,         /* re */
      0.16668818491615511              /* im */
    }, { -0.98656547136941486,         /* re */
      0.16336636955519399              /* im */
    }, { -0.98710911110132182,         /* re */
      0.16004875126272736              /* im */
    }, { -0.98764063723813234,         /* re */
      0.15673535553874224              /* im */
    }, { -0.98816010789597941,         /* re */
      0.15342620754944816              /* im */
    }, { -0.988667580959026,           /* re */
      0.15012133213047316              /* im */
    }, { -0.989163114080042,           /* re */
      0.14682075379003448              /* im */
    }, { -0.98964676468098933,         /* re */
      0.14352449671206111              /* im */
    }, { -0.99011858995361068,         /* re */
      0.14023258475929812              /* im */
    }, { -0.99057864686002262,         /* re */
      0.13694504147637704              /* im */
    }, { -0.99102699213331347,         /* re */
      0.13366189009286661              /* im */
    }, { -0.99146368227814818,         /* re */
      0.13038315352627119              /* im */
    }, { -0.99188877357137473,         /* re */
      0.12710885438502734              /* im */
    }, { -0.99230232206263658,         /* re */
      0.12383901497145179              /* im */
    }, { -0.99270438357498769,         /* re */
      0.12057365728468072              /* im */
    }, { -0.99309501370551567,         /* re */
      0.11731280302354709              /* im */
    }, { -0.993474267825963,           /* re */
      0.11405647358947529              /* im */
    }, { -0.99384220108335708,         /* re */
      0.11080469008930965              /* im */
    }, { -0.9941988684006412,          /* re */
      0.10755747333813868              /* im */
    }, { -0.99454432447731056,         /* re */
      0.10431484386207941              /* im */
    }, { -0.99487862379005,            /* re */
      0.10107682190104782              /* im */
    }, { -0.99520182059337725,         /* re */
      0.097843427411488937             /* im */
    }, { -0.99551396892028809,         /* re */
      0.094614680069086757             /* im */
    }, { -0.99581512258290383,         /* re */
      0.091390599271458359             /* im */
    }, { -0.9961053351731235,          /* re */
      0.08817120414080365              /* im */
    }, { -0.99638466006327842,         /* re */
      0.0849565135265401               /* im */
    }, { -0.99665315040678781,         /* re */
      0.081746546007918475             /* im */
    }, { -0.99691085913881994,         /* re */
      0.0785413198965985               /* im */
    }, { -0.99715783897695309,         /* re */
      0.0753408532392142               /* im */
    }, { -0.99739414242184088,         /* re */
      0.072145163819903241             /* im */
    }, { -0.99761982175787811,         /* re */
      0.068954269162825738             /* im */
    }, { -0.99783492905387128,         /* re */
      0.065768186534644266             /* im */
    }, { -0.99803951616370823,         /* re */
      0.062586932946991011             /* im */
    }, { -0.99823363472703286,         /* re */
      0.059410525158904021             /* im */
    }, { -0.99841733616991868,         /* re */
      0.05623897967925473              /* im */
    }, { -0.99859067170554716,         /* re */
      0.053072312769127307             /* im */
    }, { -0.998753692334886,           /* re */
      0.049910540444198882             /* im */
    }, { -0.99890644884736868,         /* re */
      0.0467536784770916               /* im */
    }, { -0.9990489918215778,          /* re */
      0.043601742399691515             /* im */
    }, { -0.99918137162592746,         /* re */
      0.040454747505457675             /* im */
    }, { -0.99930363841934844,         /* re */
      0.037312708851705678             /* im */
    }, { -0.99941584215197432,         /* re */
      0.034175641261867756             /* im */
    }, { -0.999518032565829,           /* re */
      0.031043559327731417             /* im */
    }, { -0.99961025919551461,         /* re */
      0.027916477411667633             /* im */
    }, { -0.99969257136890177,         /* re */
      0.024794409648815012             /* im */
    }, { -0.99976501820782,            /* re */
      0.021677369949265547             /* im */
    }, { -0.99982764862874907,         /* re */
      0.018565372000224668             /* im */
    }, { -0.99988051134351141,         /* re */
      0.015458429268138767             /* im */
    }, { -0.9999236548599657,          /* re */
      0.012356555000819716             /* im */
    }, { -0.99995712748269983,         /* re */
      0.0092597622295391251            /* im */
    }, { -0.99998097731372648,         /* re */
      0.0061680637711041325            /* im */
    }, { -0.99999525225317754,         /* re */
      0.0030814722299123114            /* im */
    }, { -1.0,                         /* re */
      1.2246467991473532E-16           /* im */
    } };

  static real_T c2_dv[581] = { 62.831853071795862, 65.973445725385659,
    69.115038378975441, 72.256631032565238, 75.398223686155035,
    78.539816339744831, 81.681408993334628, 84.823001646924411,
    87.964594300514207, 91.106186954104, 94.247779607693786, 97.389372261283583,
    100.53096491487338, 103.67255756846318, 106.81415022205297,
    109.95574287564276, 113.09733552923255, 116.23892818282235,
    119.38052083641213, 122.52211349000193, 125.66370614359172,
    128.80529879718151, 131.94689145077132, 135.0884841043611,
    138.23007675795088, 141.37166941154069, 144.51326206513048,
    147.65485471872029, 150.79644737231007, 153.93804002589985,
    157.07963267948966, 160.22122533307945, 163.36281798666926,
    166.50441064025904, 169.64600329384882, 172.78759594743863,
    175.92918860102841, 179.0707812546182, 182.212373908208, 185.35396656179779,
    188.49555921538757, 191.63715186897738, 194.77874452256717,
    197.92033717615698, 201.06192982974676, 204.20352248333654,
    207.34511513692635, 210.48670779051614, 213.62830044410595,
    216.76989309769573, 219.91148575128551, 223.05307840487532,
    226.1946710584651, 229.33626371205489, 232.4778563656447, 235.61944901923448,
    238.76104167282426, 241.90263432641407, 245.04422698000386,
    248.18581963359367, 251.32741228718345, 254.46900494077323, 257.610597594363,
    260.75219024795285, 263.89378290154264, 267.03537555513242,
    270.1769682087222, 273.318560862312, 276.46015351590177, 279.60174616949161,
    282.74333882308139, 285.88493147667117, 289.02652413026095,
    292.16811678385073, 295.30970943744057, 298.45130209103036,
    301.59289474462014, 304.73448739820992, 307.8760800517997,
    311.01767270538954, 314.15926535897933, 317.30085801256911,
    320.44245066615889, 323.58404331974867, 326.72563597333851,
    329.86722862692829, 333.00882128051808, 336.15041393410786,
    339.29200658769764, 342.43359924128742, 345.57519189487726,
    348.71678454846705, 351.85837720205683, 354.99996985564661,
    358.14156250923639, 361.28315516282623, 364.424747816416, 367.5663404700058,
    370.70793312359558, 373.84952577718536, 376.99111843077515, 380.132711084365,
    383.27430373795477, 386.41589639154455, 389.55748904513433,
    392.69908169872411, 395.84067435231395, 398.98226700590374,
    402.12385965949352, 405.2654523130833, 408.40704496667308,
    411.54863762026292, 414.69023027385271, 417.83182292744249,
    420.97341558103227, 424.11500823462205, 427.25660088821189,
    430.39819354180167, 433.53978619539146, 436.68137884898124, 439.822971502571,
    442.9645641561608, 446.10615680975064, 449.24774946334043,
    452.38934211693021, 455.53093477052, 458.67252742410977, 461.81412007769961,
    464.9557127312894, 468.09730538487918, 471.23889803846896,
    474.38049069205874, 477.52208334564853, 480.66367599923836,
    483.80526865282815, 486.94686130641793, 490.08845396000771,
    493.23004661359749, 496.37163926718733, 499.51323192077712,
    502.6548245743669, 505.79641722795668, 508.93800988154646,
    512.07960253513625, 515.221195188726, 518.36278784231581, 521.50438049590571,
    524.64597314949549, 527.78756580308527, 530.929158456675, 534.07075111026484,
    537.21234376385462, 540.3539364174444, 543.49552907103418, 546.637121724624,
    549.77871437821375, 552.92030703180353, 556.06189968539343,
    559.20349233898321, 562.345084992573, 565.48667764616278, 568.62827029975256,
    571.76986295334234, 574.91145560693212, 578.0530482605219,
    581.19464091411169, 584.33623356770147, 587.47782622129137,
    590.61941887488115, 593.76101152847093, 596.90260418206071,
    600.0441968356505, 603.18578948924028, 606.32738214283006,
    609.46897479641984, 612.61056745000963, 615.75216010359941,
    618.89375275718919, 622.03534541077909, 625.17693806436887,
    628.31853071795865, 631.46012337154843, 634.60171602513822, 637.743308678728,
    640.88490133231778, 644.02649398590756, 647.16808663949735,
    650.30967929308713, 653.451271946677, 656.59286460026681, 659.73445725385659,
    662.87604990744637, 666.01764256103615, 669.15923521462594,
    672.30082786821572, 675.4424205218055, 678.58401317539528,
    681.72560582898507, 684.86719848257485, 688.00879113616475,
    691.15038378975453, 694.29197644334431, 697.43356909693409,
    700.57516175052388, 703.71675440411366, 706.85834705770344,
    709.99993971129322, 713.141532364883, 716.28312501847279, 719.42471767206257,
    722.56631032565247, 725.70790297924225, 728.849495632832, 731.99108828642181,
    735.1326809400116, 738.27427359360138, 741.41586624719116, 744.557458900781,
    747.69905155437073, 750.84064420796051, 753.98223686155029,
    757.12382951514019, 760.26542216873, 763.40701482231975, 766.54860747590953,
    769.69020012949932, 772.8317927830891, 775.97338543667888,
    779.11497809026866, 782.25657074385845, 785.39816339744823,
    788.53975605103813, 791.68134870462791, 794.82294135821769,
    797.96453401180747, 801.10612666539726, 804.247719318987, 807.38931197257682,
    810.5309046261666, 813.67249727975639, 816.81408993334617, 819.955682586936,
    823.09727524052585, 826.23886789411563, 829.38046054770541,
    832.52205320129519, 835.663645854885, 838.80523850847476, 841.94683116206454,
    845.08842381565432, 848.23001646924411, 851.37160912283389,
    854.51320177642378, 857.65479443001357, 860.79638708360335,
    863.93797973719313, 867.07957239078291, 870.2211650443727,
    873.36275769796248, 876.50435035155226, 879.645943005142, 882.78753565873183,
    885.92912831232161, 889.07072096591151, 892.21231361950129,
    895.35390627309107, 898.49549892668085, 901.63709158027063,
    904.77868423386042, 907.9202768874502, 911.06186954104, 914.20346219462976,
    917.34505484821955, 920.48664750180933, 923.62824015539923, 926.769832808989,
    929.91142546257879, 933.05301811616857, 936.19461076975836,
    939.33620342334814, 942.47779607693792, 945.6193887305277,
    948.76098138411749, 951.90257403770727, 955.044166691297, 958.185759344887,
    961.32735199847673, 964.46894465206651, 967.61053730565629,
    970.75212995924608, 973.89372261283586, 977.03531526642564,
    980.17690792001542, 983.31850057360521, 986.460093227195, 989.60168588078488,
    992.74327853437467, 995.88487118796445, 999.02646384155423,
    1002.168056495144, 1005.3096491487338, 1008.4512418023236,
    1011.5928344559134, 1014.7344271095031, 1017.8760197630929,
    1021.0176124166827, 1024.1592050702725, 1027.3007977238624,
    1030.4423903774521, 1033.583983031042, 1036.7255756846316,
    1039.8671683382215, 1043.0087609918114, 1046.1503536454011,
    1049.291946298991, 1052.4335389525806, 1055.5751316061705,
    1058.7167242597602, 1061.85831691335, 1064.9999095669398, 1068.1415022205297,
    1071.2830948741193, 1074.4246875277092, 1077.5662801812991,
    1080.7078728348888, 1083.8494654884787, 1086.9910581420684,
    1090.1326507956583, 1093.2742434492479, 1096.4158361028378,
    1099.5574287564275, 1102.6990214100174, 1105.8406140636071,
    1108.982206717197, 1112.1237993707869, 1115.2653920243765,
    1118.4069846779664, 1121.5485773315561, 1124.690169985146,
    1127.8317626387357, 1130.9733552923256, 1134.1149479459152,
    1137.2565405995051, 1140.398133253095, 1143.5397259066847,
    1146.6813185602746, 1149.8229112138642, 1152.9645038674541,
    1156.1060965210438, 1159.2476891746337, 1162.3892818282234,
    1165.5308744818133, 1168.6724671354029, 1171.8140597889928,
    1174.9556524425827, 1178.0972450961724, 1181.2388377497623,
    1184.380430403352, 1187.5220230569419, 1190.6636157105315,
    1193.8052083641214, 1196.9468010177111, 1200.088393671301,
    1203.2299863248907, 1206.3715789784806, 1209.5131716320705,
    1212.6547642856601, 1215.79635693925, 1218.9379495928397, 1222.0795422464296,
    1225.2211349000193, 1228.3627275536091, 1231.5043202071988,
    1234.6459128607887, 1237.7875055143784, 1240.9290981679683,
    1244.0706908215582, 1247.2122834751478, 1250.3538761287377,
    1253.4954687823274, 1256.6370614359173, 1259.778654089507,
    1262.9202467430969, 1266.0618393966865, 1269.2034320502764,
    1272.3450247038661, 1275.486617357456, 1278.6282100110459,
    1281.7698026646356, 1284.9113953182255, 1288.0529879718151,
    1291.194580625405, 1294.3361732789947, 1297.4777659325846,
    1300.6193585861743, 1303.7609512397642, 1306.902543893354,
    1310.0441365469437, 1313.1857292005336, 1316.3273218541233,
    1319.4689145077132, 1322.6105071613028, 1325.7520998148927,
    1328.8936924684824, 1332.0352851220723, 1335.176877775662,
    1338.3184704292519, 1341.4600630828418, 1344.6016557364314,
    1347.7432483900213, 1350.884841043611, 1354.0264336972009,
    1357.1680263507906, 1360.3096190043805, 1363.4512116579701, 1366.59280431156,
    1369.7343969651497, 1372.8759896187396, 1376.0175822723295,
    1379.1591749259192, 1382.3007675795091, 1385.4423602330987,
    1388.5839528866886, 1391.7255455402783, 1394.8671381938682,
    1398.0087308474579, 1401.1503235010478, 1404.2919161546374,
    1407.4335088082273, 1410.5751014618172, 1413.7166941154069,
    1416.8582867689968, 1419.9998794225864, 1423.1414720761763,
    1426.283064729766, 1429.4246573833559, 1432.5662500369456,
    1435.7078426905355, 1438.8494353441251, 1441.991027997715,
    1445.1326206513049, 1448.2742133048946, 1451.4158059584845,
    1454.5573986120742, 1457.6989912656641, 1460.8405839192537,
    1463.9821765728436, 1467.1237692264333, 1470.2653618800232,
    1473.4069545336129, 1476.5485471872028, 1479.6901398407927,
    1482.8317324943823, 1485.9733251479722, 1489.1149178015619,
    1492.2565104551518, 1495.3981031087415, 1498.5396957623313,
    1501.681288415921, 1504.8228810695109, 1507.9644737231006,
    1511.1060663766905, 1514.2476590302804, 1517.38925168387, 1520.53084433746,
    1523.6724369910496, 1526.8140296446395, 1529.9556222982292,
    1533.0972149518191, 1536.2388076054087, 1539.3804002589986,
    1542.5219929125885, 1545.6635855661782, 1548.8051782197681,
    1551.9467708733578, 1555.0883635269477, 1558.2299561805373,
    1561.3715488341272, 1564.5131414877169, 1567.6547341413068,
    1570.7963267948965, 1573.9379194484864, 1577.0795121020763,
    1580.2211047556659, 1583.3626974092558, 1586.5042900628455,
    1589.6458827164354, 1592.787475370025, 1595.9290680236149,
    1599.0706606772046, 1602.2122533307945, 1605.3538459843842,
    1608.4954386379741, 1611.637031291564, 1614.7786239451536,
    1617.9202165987435, 1621.0618092523332, 1624.2034019059231,
    1627.3449945595128, 1630.4865872131027, 1633.6281798666923,
    1636.7697725202822, 1639.9113651738719, 1643.0529578274618,
    1646.1945504810517, 1649.3361431346414, 1652.4777357882313,
    1655.6193284418209, 1658.7609210954108, 1661.9025137490005,
    1665.0441064025904, 1668.18569905618, 1671.32729170977, 1674.4688843633596,
    1677.6104770169495, 1680.7520696705394, 1683.8936623241291,
    1687.035254977719, 1690.1768476313086, 1693.3184402848985,
    1696.4600329384882, 1699.6016255920781, 1702.7432182456678,
    1705.8848108992577, 1709.0264035528476, 1712.1679962064372,
    1715.3095888600271, 1718.4511815136168, 1721.5927741672067,
    1724.7343668207964, 1727.8759594743863, 1731.0175521279759,
    1734.1591447815658, 1737.3007374351555, 1740.4423300887454,
    1743.5839227423353, 1746.725515395925, 1749.8671080495149,
    1753.0087007031045, 1756.1502933566944, 1759.2918860102841,
    1762.433478663874, 1765.5750713174637, 1768.7166639710535,
    1771.8582566246432, 1774.9998492782331, 1778.141441931823,
    1781.2830345854127, 1784.4246272390026, 1787.5662198925922,
    1790.7078125461821, 1793.8494051997718, 1796.9909978533617,
    1800.1325905069514, 1803.2741831605413, 1806.4157758141309,
    1809.5573684677208, 1812.6989611213107, 1815.8405537749004,
    1818.9821464284903, 1822.12373908208, 1825.2653317356699, 1828.4069243892595,
    1831.5485170428494, 1834.6901096964391, 1837.831702350029,
    1840.9732950036187, 1844.1148876572086, 1847.2564803107985,
    1850.3980729643881, 1853.539665617978, 1856.6812582715677,
    1859.8228509251576, 1862.9644435787473, 1866.1060362323371,
    1869.2476288859268, 1872.3892215395167, 1875.5308141931064,
    1878.6724068466963, 1881.8139995002862, 1884.9555921538758 };

  c2_emxArray_boolean_T *c2_e_x;
  c2_emxArray_boolean_T *c2_inside;
  c2_emxArray_boolean_T *c2_rows_to_keep;
  c2_emxArray_creal_T *c2_w;
  c2_emxArray_creal_T *c2_wkeep;
  c2_emxArray_int32_T *c2_ii;
  c2_emxArray_int32_T *c2_jj;
  c2_emxArray_int32_T *c2_xckeep;
  c2_emxArray_int32_T *c2_yckeep;
  c2_emxArray_real32_T *c2_xc;
  c2_emxArray_real32_T *c2_yc;
  c2_emxArray_real_T *c2_Ex;
  c2_emxArray_real_T *c2_Ex_chunk;
  c2_emxArray_real_T *c2_Ey;
  c2_emxArray_real_T *c2_Ey_chunk;
  c2_emxArray_real_T *c2_b_varargin_2;
  c2_emxArray_real_T *c2_idxE;
  c2_emxArray_real_T *c2_idxE_chunk;
  c2_emxArray_real_T *c2_ndx;
  c2_emxArray_real_T *c2_r;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  creal_T c2_w0[581];
  real_T c2_a1;
  real_T c2_ab_x;
  real_T c2_absa;
  real_T c2_absb;
  real_T c2_ai;
  real_T c2_apnd;
  real_T c2_ar;
  real_T c2_b1;
  real_T c2_b_b;
  real_T c2_b_d;
  real_T c2_b_idx1;
  real_T c2_b_idx2;
  real_T c2_b_k;
  real_T c2_bb_x;
  real_T c2_bi;
  real_T c2_bim;
  real_T c2_br;
  real_T c2_brm;
  real_T c2_c;
  real_T c2_c_b;
  real_T c2_c_d;
  real_T c2_c_i;
  real_T c2_c_idx;
  real_T c2_c_varargin_2;
  real_T c2_cdiff;
  real_T c2_d;
  real_T c2_dim1;
  real_T c2_e_a;
  real_T c2_e_y;
  real_T c2_f_a;
  real_T c2_f_y;
  real_T c2_g_a;
  real_T c2_g_x;
  real_T c2_g_y;
  real_T c2_h_a;
  real_T c2_h_b;
  real_T c2_h_varargin_1;
  real_T c2_h_x;
  real_T c2_h_y;
  real_T c2_i_a;
  real_T c2_i_b;
  real_T c2_i_x;
  real_T c2_i_y;
  real_T c2_j_a;
  real_T c2_j_b;
  real_T c2_j_x;
  real_T c2_j_y;
  real_T c2_k_x;
  real_T c2_kd;
  real_T c2_l_a;
  real_T c2_l_x;
  real_T c2_lenE;
  real_T c2_m_a;
  real_T c2_m_x;
  real_T c2_minval;
  real_T c2_n_x;
  real_T c2_ndbl;
  real_T c2_ni;
  real_T c2_nr;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s;
  real_T c2_s_x;
  real_T c2_sgnbi;
  real_T c2_sgnbr;
  real_T c2_sizeChunk;
  real_T c2_t_x;
  real_T c2_thresh;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  int32_T c2_b_i;
  int32_T c2_b_idx;
  int32_T c2_b_loop_ub;
  int32_T c2_c_idx1;
  int32_T c2_c_idx2;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_d_idx;
  int32_T c2_d_k;
  int32_T c2_d_loop_ub;
  int32_T c2_e_idx;
  int32_T c2_e_k;
  int32_T c2_e_loop_ub;
  int32_T c2_f_k;
  int32_T c2_f_loop_ub;
  int32_T c2_g_loop_ub;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  int32_T c2_i103;
  int32_T c2_i104;
  int32_T c2_i105;
  int32_T c2_i106;
  int32_T c2_i107;
  int32_T c2_i108;
  int32_T c2_i109;
  int32_T c2_i11;
  int32_T c2_i110;
  int32_T c2_i111;
  int32_T c2_i112;
  int32_T c2_i113;
  int32_T c2_i114;
  int32_T c2_i115;
  int32_T c2_i116;
  int32_T c2_i117;
  int32_T c2_i118;
  int32_T c2_i119;
  int32_T c2_i12;
  int32_T c2_i120;
  int32_T c2_i121;
  int32_T c2_i122;
  int32_T c2_i123;
  int32_T c2_i124;
  int32_T c2_i125;
  int32_T c2_i126;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i5;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i6;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i7;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i8;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  int32_T c2_i9;
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_idx1;
  int32_T c2_idx2;
  int32_T c2_idxEdge;
  int32_T c2_idxkeep;
  int32_T c2_k;
  int32_T c2_k_a;
  int32_T c2_k_b;
  int32_T c2_l_b;
  int32_T c2_l_y;
  int32_T c2_loop_ub;
  int32_T c2_m_b;
  int32_T c2_n;
  int32_T c2_n_b;
  int32_T c2_nm1;
  int32_T c2_nm1d2;
  int32_T c2_p_b;
  int32_T c2_szxc;
  real32_T c2_Gmax;
  real32_T c2_b;
  real32_T c2_b_y;
  real32_T c2_b_z;
  real32_T c2_c_y;
  real32_T c2_c_z;
  real32_T c2_cb_x;
  real32_T c2_d_a;
  real32_T c2_d_y;
  real32_T c2_db_x;
  real32_T c2_eb_x;
  real32_T c2_edgeThresh;
  real32_T c2_f_x;
  real32_T c2_fb_x;
  real32_T c2_gb_x;
  real32_T c2_hb_x;
  real32_T c2_k_y;
  real32_T c2_m_y;
  real32_T c2_n_y;
  real32_T c2_o_b;
  real32_T c2_o_y;
  real32_T c2_p_y;
  real32_T c2_q_b;
  real32_T c2_q_y;
  real32_T c2_r_y;
  real32_T c2_s_y;
  real32_T c2_t;
  real32_T c2_x1;
  real32_T c2_x2;
  real32_T c2_z;
  uint8_T c2_g_varargin_1;
  boolean_T c2_b2;
  boolean_T c2_b3;
  boolean_T c2_b4;
  boolean_T c2_b5;
  boolean_T c2_b_b1;
  boolean_T c2_b_overflow;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  boolean_T c2_exitg1;
  boolean_T c2_f_b;
  boolean_T c2_flat;
  boolean_T c2_g_b;
  boolean_T c2_guard1 = false;
  boolean_T c2_guard2 = false;
  boolean_T c2_guard3 = false;
  boolean_T c2_overflow;
  boolean_T c2_r_b;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_g_varargin_1 = c2_f_varargin_1[0];
  for (c2_i = 0; c2_i < 921600; c2_i++) {
    chartInstance->c2_b_x[c2_i] = (c2_f_varargin_1[c2_i] == c2_g_varargin_1);
  }

  c2_emxInit_boolean_T1(chartInstance, c2_sp, &c2_e_x, 1, &c2_c_emlrtRTEI);
  c2_i1 = c2_e_x->size[0];
  c2_e_x->size[0] = 921600;
  c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_sp, c2_e_x, c2_i1,
    &c2_c_emlrtRTEI);
  for (c2_i2 = 0; c2_i2 < 921600; c2_i2++) {
    c2_e_x->data[c2_i2] = chartInstance->c2_b_x[c2_i2];
  }

  c2_flat = true;
  c2_d = (real_T)c2_e_x->size[0];
  c2_i3 = (int32_T)c2_d - 1;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k <= c2_i3)) {
    c2_b_k = (real_T)c2_k + 1.0;
    if (!c2_e_x->data[(int32_T)c2_b_k - 1]) {
      c2_flat = false;
      c2_exitg1 = true;
    } else {
      c2_k++;
    }
  }

  c2_emxFree_boolean_T(chartInstance, &c2_e_x);
  if (c2_flat) {
    for (c2_i4 = 0; c2_i4 < 307200; c2_i4++) {
      c2_c_accumMatrix[c2_i4].re = 0.0;
      c2_c_accumMatrix[c2_i4].im = 0.0;
    }

    for (c2_i5 = 0; c2_i5 < 307200; c2_i5++) {
      c2_b_gradientImg[c2_i5] = 0.0F;
    }
  } else {
    c2_st.site = &c2_k_emlrtRSI;
    c2_b_st.site = &c2_d_emlrtRSI;
    c2_c_st.site = &c2_e_emlrtRSI;
    rgb2gray_tbb_uint8(&c2_f_varargin_1[0], 307200.0, &chartInstance->c2_d_A[0],
                       true);
    for (c2_i6 = 0; c2_i6 < 307200; c2_i6++) {
      chartInstance->c2_A[c2_i6] = (real32_T)chartInstance->c2_d_A[c2_i6];
    }

    for (c2_i7 = 0; c2_i7 < 307200; c2_i7++) {
      chartInstance->c2_A[c2_i7] /= 255.0F;
    }

    c2_st.site = &c2_l_emlrtRSI;
    c2_b_st.site = &c2_q_emlrtRSI;
    for (c2_i8 = 0; c2_i8 < 307200; c2_i8++) {
      chartInstance->c2_b_A[c2_i8] = chartInstance->c2_A[c2_i8];
    }

    c2_imfilter(chartInstance, &c2_b_st, chartInstance->c2_b_A,
                chartInstance->c2_Gx);
    c2_b_st.site = &c2_r_emlrtRSI;
    c2_b_imfilter(chartInstance, &c2_b_st, chartInstance->c2_A,
                  chartInstance->c2_Gy);
    for (c2_c_k = 0; c2_c_k < 307200; c2_c_k++) {
      c2_d_k = c2_c_k;
      c2_f_x = chartInstance->c2_Gx[c2_d_k];
      c2_b_y = chartInstance->c2_Gy[c2_d_k];
      c2_x1 = c2_f_x;
      c2_x2 = c2_b_y;
      c2_d_a = c2_x1;
      c2_b = c2_x2;
      c2_z = muSingleScalarHypot(c2_d_a, c2_b);
      c2_b_gradientImg[c2_d_k] = c2_z;
    }

    c2_st.site = &c2_m_emlrtRSI;
    for (c2_i9 = 0; c2_i9 < 307200; c2_i9++) {
      chartInstance->c2_A[c2_i9] = c2_b_gradientImg[c2_i9];
    }

    c2_b_st.site = &c2_yj_emlrtRSI;
    c2_Gmax = c2_maximum(chartInstance, &c2_b_st, chartInstance->c2_A);
    c2_c_y = c2_Gmax;
    c2_d_y = c2_c_y;
    for (c2_i10 = 0; c2_i10 < 307200; c2_i10++) {
      chartInstance->c2_A[c2_i10] = c2_b_gradientImg[c2_i10] / c2_d_y;
    }

    c2_b_st.site = &c2_ab_emlrtRSI;
    c2_edgeThresh = c2_multithresh(chartInstance, &c2_b_st, chartInstance->c2_A);
    c2_t = c2_Gmax * c2_edgeThresh;
    c2_b_st.site = &c2_bb_emlrtRSI;
    for (c2_i11 = 0; c2_i11 < 307200; c2_i11++) {
      chartInstance->c2_c_x[c2_i11] = (c2_b_gradientImg[c2_i11] > c2_t);
    }

    c2_emxInit_real_T1(chartInstance, &c2_b_st, &c2_Ey, 1, &c2_rb_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_b_st, &c2_ii, 1, &c2_rb_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_b_st, &c2_jj, 1, &c2_rb_emlrtRTEI);
    c2_c_st.site = &c2_ge_emlrtRSI;
    c2_eml_find(chartInstance, &c2_c_st, chartInstance->c2_c_x, c2_ii, c2_jj);
    c2_i12 = c2_Ey->size[0];
    c2_Ey->size[0] = c2_ii->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_Ey, c2_i12,
      &c2_n_emlrtRTEI);
    c2_loop_ub = c2_ii->size[0] - 1;
    for (c2_i13 = 0; c2_i13 <= c2_loop_ub; c2_i13++) {
      c2_Ey->data[c2_i13] = (real_T)c2_ii->data[c2_i13];
    }

    c2_emxFree_int32_T(chartInstance, &c2_ii);
    c2_emxInit_real_T1(chartInstance, &c2_b_st, &c2_Ex, 1, &c2_rb_emlrtRTEI);
    c2_i14 = c2_Ex->size[0];
    c2_Ex->size[0] = c2_jj->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_Ex, c2_i14,
      &c2_o_emlrtRTEI);
    c2_b_loop_ub = c2_jj->size[0] - 1;
    for (c2_i15 = 0; c2_i15 <= c2_b_loop_ub; c2_i15++) {
      c2_Ex->data[c2_i15] = (real_T)c2_jj->data[c2_i15];
    }

    c2_emxFree_int32_T(chartInstance, &c2_jj);
    c2_emxInit_real_T1(chartInstance, &c2_b_st, &c2_ndx, 1, &c2_sb_emlrtRTEI);
    c2_st.site = &c2_n_emlrtRSI;
    c2_i16 = c2_ndx->size[0];
    c2_ndx->size[0] = c2_Ey->size[0];
    c2_b_st.site = &c2_mj_emlrtRSI;
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_ndx, c2_i16,
      &c2_p_emlrtRTEI);
    c2_c_loop_ub = c2_Ey->size[0] - 1;
    for (c2_i17 = 0; c2_i17 <= c2_c_loop_ub; c2_i17++) {
      c2_ndx->data[c2_i17] = c2_Ey->data[c2_i17];
    }

    c2_emxInit_real_T1(chartInstance, &c2_st, &c2_b_varargin_2, 1,
                       &c2_q_emlrtRTEI);
    c2_i18 = c2_b_varargin_2->size[0];
    c2_b_varargin_2->size[0] = c2_Ex->size[0];
    c2_b_st.site = &c2_mj_emlrtRSI;
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_b_varargin_2,
      c2_i18, &c2_q_emlrtRTEI);
    c2_d_loop_ub = c2_Ex->size[0] - 1;
    for (c2_i19 = 0; c2_i19 <= c2_d_loop_ub; c2_i19++) {
      c2_b_varargin_2->data[c2_i19] = c2_Ex->data[c2_i19];
    }

    c2_emxInit_int32_T(chartInstance, &c2_st, &c2_xckeep, 1, &c2_ob_emlrtRTEI);
    c2_b_st.site = &c2_le_emlrtRSI;
    c2_eml_sub2ind(chartInstance, &c2_b_st, c2_ndx, c2_b_varargin_2, c2_xckeep);
    c2_i20 = c2_ndx->size[0];
    c2_ndx->size[0] = c2_xckeep->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_ndx, c2_i20,
      &c2_r_emlrtRTEI);
    c2_e_loop_ub = c2_xckeep->size[0] - 1;
    c2_emxFree_real_T(chartInstance, &c2_b_varargin_2);
    for (c2_i21 = 0; c2_i21 <= c2_e_loop_ub; c2_i21++) {
      c2_ndx->data[c2_i21] = (real_T)c2_xckeep->data[c2_i21];
    }

    c2_emxInit_real_T1(chartInstance, &c2_st, &c2_idxE, 1, &c2_s_emlrtRTEI);
    c2_i22 = c2_idxE->size[0];
    c2_idxE->size[0] = c2_ndx->size[0];
    c2_st.site = &c2_mj_emlrtRSI;
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_idxE, c2_i22,
      &c2_s_emlrtRTEI);
    c2_f_loop_ub = c2_ndx->size[0] - 1;
    for (c2_i23 = 0; c2_i23 <= c2_f_loop_ub; c2_i23++) {
      c2_idxE->data[c2_i23] = c2_ndx->data[c2_i23];
    }

    c2_emxFree_real_T(chartInstance, &c2_ndx);
    for (c2_i24 = 0; c2_i24 < 581; c2_i24++) {
      c2_ar = c2_Opca[c2_i24].re;
      c2_ai = c2_Opca[c2_i24].im;
      c2_br = c2_dv[c2_i24];
      c2_bi = 0.0;
      if (c2_bi == 0.0) {
        if (c2_ai == 0.0) {
          c2_w0[c2_i24].re = c2_ar / c2_br;
          c2_w0[c2_i24].im = 0.0;
        } else if (c2_ar == 0.0) {
          c2_w0[c2_i24].re = 0.0;
          c2_w0[c2_i24].im = c2_ai / c2_br;
        } else {
          c2_w0[c2_i24].re = c2_ar / c2_br;
          c2_w0[c2_i24].im = c2_ai / c2_br;
        }
      } else if (c2_br == 0.0) {
        if (c2_ar == 0.0) {
          c2_w0[c2_i24].re = c2_ai / c2_bi;
          c2_w0[c2_i24].im = 0.0;
        } else if (c2_ai == 0.0) {
          c2_w0[c2_i24].re = 0.0;
          c2_w0[c2_i24].im = -(c2_ar / c2_bi);
        } else {
          c2_w0[c2_i24].re = c2_ai / c2_bi;
          c2_w0[c2_i24].im = -(c2_ar / c2_bi);
        }
      } else {
        c2_brm = muDoubleScalarAbs(c2_br);
        c2_bim = muDoubleScalarAbs(c2_bi);
        if (c2_brm > c2_bim) {
          c2_s = c2_bi / c2_br;
          c2_b_d = c2_br + c2_s * c2_bi;
          c2_nr = c2_ar + c2_s * c2_ai;
          c2_ni = c2_ai - c2_s * c2_ar;
          c2_w0[c2_i24].re = c2_nr / c2_b_d;
          c2_w0[c2_i24].im = c2_ni / c2_b_d;
        } else if (c2_bim == c2_brm) {
          if (c2_br > 0.0) {
            c2_sgnbr = 0.5;
          } else {
            c2_sgnbr = -0.5;
          }

          if (c2_bi > 0.0) {
            c2_sgnbi = 0.5;
          } else {
            c2_sgnbi = -0.5;
          }

          c2_nr = c2_ar * c2_sgnbr + c2_ai * c2_sgnbi;
          c2_ni = c2_ai * c2_sgnbr - c2_ar * c2_sgnbi;
          c2_w0[c2_i24].re = c2_nr / c2_brm;
          c2_w0[c2_i24].im = c2_ni / c2_brm;
        } else {
          c2_s = c2_br / c2_bi;
          c2_b_d = c2_bi + c2_s * c2_br;
          c2_nr = c2_s * c2_ar + c2_ai;
          c2_ni = c2_s * c2_ai - c2_ar;
          c2_w0[c2_i24].re = c2_nr / c2_b_d;
          c2_w0[c2_i24].im = c2_ni / c2_b_d;
        }
      }
    }

    c2_lenE = (real_T)c2_Ex->size[0];
    for (c2_i25 = 0; c2_i25 < 307200; c2_i25++) {
      c2_c_accumMatrix[c2_i25].re = 0.0;
      c2_c_accumMatrix[c2_i25].im = 0.0;
    }

    c2_i26 = (int32_T)((c2_lenE + 1720.0) / 1721.0);
    emlrtForLoopVectorCheckR2021a(1.0, 1721.0, c2_lenE, mxDOUBLE_CLASS, c2_i26,
      &c2_qh_emlrtRTEI, (void *)c2_sp);
    c2_b_i = 0;
    c2_emxInit_real_T1(chartInstance, c2_sp, &c2_Ex_chunk, 1, &c2_hb_emlrtRTEI);
    c2_emxInit_real_T1(chartInstance, c2_sp, &c2_Ey_chunk, 1, &c2_ib_emlrtRTEI);
    c2_emxInit_real_T1(chartInstance, c2_sp, &c2_idxE_chunk, 1, &c2_jb_emlrtRTEI);
    c2_emxInit_real32_T(chartInstance, c2_sp, &c2_xc, 2, &c2_kb_emlrtRTEI);
    c2_emxInit_real32_T(chartInstance, c2_sp, &c2_yc, 2, &c2_lb_emlrtRTEI);
    c2_emxInit_creal_T1(chartInstance, c2_sp, &c2_w, 2, &c2_mb_emlrtRTEI);
    c2_emxInit_boolean_T(chartInstance, c2_sp, &c2_inside, 2, &c2_nb_emlrtRTEI);
    c2_emxInit_boolean_T1(chartInstance, c2_sp, &c2_rows_to_keep, 1,
                          &c2_cb_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, c2_sp, &c2_yckeep, 1, &c2_pb_emlrtRTEI);
    c2_emxInit_creal_T(chartInstance, c2_sp, &c2_wkeep, 1, &c2_qb_emlrtRTEI);
    c2_emxInit_real_T(chartInstance, c2_sp, &c2_r, 2, &c2_rb_emlrtRTEI);
    while (c2_b_i <= c2_i26 - 1) {
      c2_c_i = (real_T)c2_b_i * 1721.0 + 1.0;
      c2_h_varargin_1 = (c2_c_i + 1721.0) - 1.0;
      c2_c_varargin_2 = c2_lenE;
      c2_g_x = c2_h_varargin_1;
      c2_e_y = c2_c_varargin_2;
      c2_h_x = c2_g_x;
      c2_f_y = c2_e_y;
      c2_i_x = c2_h_x;
      c2_g_y = c2_f_y;
      c2_e_a = c2_i_x;
      c2_b_b = c2_g_y;
      c2_j_x = c2_e_a;
      c2_h_y = c2_b_b;
      c2_k_x = c2_j_x;
      c2_i_y = c2_h_y;
      c2_minval = muDoubleScalarMin(c2_k_x, c2_i_y);
      c2_st.site = &c2_o_emlrtRSI;
      c2_f_a = c2_c_i;
      c2_c_d = c2_minval;
      c2_b_st.site = &c2_me_emlrtRSI;
      c2_g_a = c2_f_a;
      c2_c_b = c2_c_d;
      c2_l_x = c2_g_a;
      c2_d_b = muDoubleScalarIsNaN(c2_l_x);
      c2_guard1 = false;
      c2_guard2 = false;
      c2_guard3 = false;
      if (c2_d_b) {
        c2_guard2 = true;
      } else {
        c2_m_x = c2_c_b;
        c2_e_b = muDoubleScalarIsNaN(c2_m_x);
        if (c2_e_b) {
          c2_guard2 = true;
        } else if (c2_c_b < c2_g_a) {
          c2_r->size[0] = 1;
          c2_r->size[1] = 0;
        } else {
          c2_n_x = c2_g_a;
          c2_f_b = muDoubleScalarIsInf(c2_n_x);
          if (c2_f_b) {
            c2_guard3 = true;
          } else {
            c2_o_x = c2_c_b;
            c2_g_b = muDoubleScalarIsInf(c2_o_x);
            if (c2_g_b) {
              c2_guard3 = true;
            } else {
              c2_guard1 = true;
            }
          }
        }
      }

      if (c2_guard3) {
        if (c2_g_a == c2_c_b) {
          c2_i27 = c2_r->size[0] * c2_r->size[1];
          c2_r->size[0] = 1;
          c2_r->size[1] = 1;
          c2_emxEnsureCapacity_real_T(chartInstance, &c2_b_st, c2_r, c2_i27,
            &c2_t_emlrtRTEI);
          c2_r->data[0] = rtNaN;
        } else {
          c2_guard1 = true;
        }
      }

      if (c2_guard2) {
        c2_i28 = c2_r->size[0] * c2_r->size[1];
        c2_r->size[0] = 1;
        c2_r->size[1] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, &c2_b_st, c2_r, c2_i28,
          &c2_t_emlrtRTEI);
        c2_r->data[0] = rtNaN;
      }

      if (c2_guard1) {
        c2_p_x = c2_g_a;
        c2_q_x = c2_p_x;
        c2_q_x = muDoubleScalarFloor(c2_q_x);
        if (c2_q_x == c2_g_a) {
          c2_i30 = c2_r->size[0] * c2_r->size[1];
          c2_r->size[0] = 1;
          c2_r->size[1] = (int32_T)muDoubleScalarFloor(c2_c_b - c2_g_a) + 1;
          c2_emxEnsureCapacity_real_T(chartInstance, &c2_b_st, c2_r, c2_i30,
            &c2_t_emlrtRTEI);
          c2_g_loop_ub = (int32_T)muDoubleScalarFloor(c2_c_b - c2_g_a);
          for (c2_i32 = 0; c2_i32 <= c2_g_loop_ub; c2_i32++) {
            c2_r->data[c2_i32] = c2_g_a + (real_T)c2_i32;
          }
        } else {
          c2_c_st.site = &c2_ne_emlrtRSI;
          c2_h_a = c2_g_a;
          c2_h_b = c2_c_b;
          c2_i_a = c2_h_a;
          c2_i_b = c2_h_b;
          c2_a1 = c2_i_a;
          c2_r_x = (c2_i_b - c2_i_a) + 0.5;
          c2_ndbl = c2_r_x;
          c2_ndbl = muDoubleScalarFloor(c2_ndbl);
          c2_apnd = c2_i_a + c2_ndbl;
          c2_cdiff = c2_apnd - c2_i_b;
          c2_j_a = c2_i_a;
          c2_j_b = c2_i_b;
          c2_s_x = c2_j_a;
          c2_t_x = c2_s_x;
          c2_u_x = c2_t_x;
          c2_absa = muDoubleScalarAbs(c2_u_x);
          c2_v_x = c2_j_b;
          c2_w_x = c2_v_x;
          c2_x_x = c2_w_x;
          c2_absb = muDoubleScalarAbs(c2_x_x);
          if (c2_absa > c2_absb) {
            c2_c = c2_absa;
          } else {
            c2_c = c2_absb;
          }

          c2_thresh = 4.4408920985006262E-16 * c2_c;
          c2_y_x = c2_cdiff;
          c2_ab_x = c2_y_x;
          c2_bb_x = c2_ab_x;
          c2_j_y = muDoubleScalarAbs(c2_bb_x);
          if (c2_j_y < c2_thresh) {
            c2_ndbl++;
            c2_b1 = c2_i_b;
          } else if (c2_cdiff > 0.0) {
            c2_b1 = c2_i_a + (c2_ndbl - 1.0);
          } else {
            c2_ndbl++;
            c2_b1 = c2_apnd;
          }

          if (c2_ndbl >= 0.0) {
            c2_n = (int32_T)muDoubleScalarFloor(c2_ndbl);
          } else {
            c2_n = 0;
          }

          c2_i49 = c2_r->size[0] * c2_r->size[1];
          c2_r->size[0] = 1;
          c2_r->size[1] = c2_n;
          c2_emxEnsureCapacity_real_T(chartInstance, &c2_c_st, c2_r, c2_i49,
            &c2_gb_emlrtRTEI);
          if (c2_n > 0) {
            c2_r->data[0] = c2_a1;
            if (c2_n > 1) {
              c2_r->data[c2_n - 1] = c2_b1;
              c2_nm1 = c2_n - 1;
              c2_k_a = c2_nm1;
              c2_nm1d2 = c2_div_nzp_s32(chartInstance, c2_k_a, 2, 0, 1U, 0, 0);
              c2_i53 = c2_nm1d2 - 2;
              c2_d_st.site = &c2_oe_emlrtRSI;
              c2_k_b = c2_i53 + 1;
              c2_l_b = c2_k_b;
              if (1 > c2_l_b) {
                c2_overflow = false;
              } else {
                c2_overflow = (c2_l_b > 2147483646);
              }

              if (c2_overflow) {
                c2_e_st.site = &c2_hc_emlrtRSI;
                c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
              }

              for (c2_e_k = 1; c2_e_k - 1 <= c2_i53; c2_e_k++) {
                c2_f_k = c2_e_k;
                c2_kd = (real_T)c2_f_k;
                c2_r->data[c2_f_k] = c2_a1 + c2_kd;
                c2_r->data[(c2_n - c2_f_k) - 1] = c2_b1 - c2_kd;
              }

              c2_m_b = c2_nm1d2;
              c2_l_y = c2_m_b << 1;
              if (c2_l_y == c2_nm1) {
                c2_r->data[c2_nm1d2] = (c2_a1 + c2_b1) / 2.0;
              } else {
                c2_kd = (real_T)c2_nm1d2;
                c2_r->data[c2_nm1d2] = c2_a1 + c2_kd;
                c2_r->data[c2_nm1d2 + 1] = c2_b1 - c2_kd;
              }
            }
          }
        }
      }

      c2_sizeChunk = (real_T)c2_r->size[1];
      c2_i29 = c2_Ex_chunk->size[0];
      c2_Ex_chunk->size[0] = (int32_T)c2_sizeChunk;
      c2_st.site = &c2_lj_emlrtRSI;
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_Ex_chunk, c2_i29,
        &c2_u_emlrtRTEI);
      c2_i31 = c2_Ey_chunk->size[0];
      c2_Ey_chunk->size[0] = (int32_T)c2_sizeChunk;
      c2_st.site = &c2_kj_emlrtRSI;
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_Ey_chunk, c2_i31,
        &c2_v_emlrtRTEI);
      c2_i33 = c2_idxE_chunk->size[0];
      c2_idxE_chunk->size[0] = (int32_T)c2_sizeChunk;
      c2_st.site = &c2_jj_emlrtRSI;
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_idxE_chunk, c2_i33,
        &c2_w_emlrtRTEI);
      c2_idxEdge = (int32_T)c2_c_i;
      c2_i34 = (int32_T)c2_sizeChunk - 1;
      for (c2_b_idx = 0; c2_b_idx <= c2_i34; c2_b_idx++) {
        c2_c_idx = (real_T)c2_b_idx + 1.0;
        c2_i36 = c2_Ex->size[0];
        if ((c2_idxEdge < 1) || (c2_idxEdge > c2_i36)) {
          emlrtDynamicBoundsCheckR2012b(c2_idxEdge, 1, c2_i36, &c2_l_emlrtBCI,
            (void *)c2_sp);
        }

        c2_i37 = c2_Ex_chunk->size[0];
        c2_i38 = (int32_T)c2_c_idx;
        if ((c2_i38 < 1) || (c2_i38 > c2_i37)) {
          emlrtDynamicBoundsCheckR2012b(c2_i38, 1, c2_i37, &c2_m_emlrtBCI, (void
            *)c2_sp);
        }

        c2_Ex_chunk->data[c2_i38 - 1] = c2_Ex->data[c2_idxEdge - 1];
        c2_i40 = c2_Ey->size[0];
        if ((c2_idxEdge < 1) || (c2_idxEdge > c2_i40)) {
          emlrtDynamicBoundsCheckR2012b(c2_idxEdge, 1, c2_i40, &c2_n_emlrtBCI,
            (void *)c2_sp);
        }

        c2_i42 = c2_Ey_chunk->size[0];
        c2_i43 = (int32_T)c2_c_idx;
        if ((c2_i43 < 1) || (c2_i43 > c2_i42)) {
          emlrtDynamicBoundsCheckR2012b(c2_i43, 1, c2_i42, &c2_o_emlrtBCI, (void
            *)c2_sp);
        }

        c2_Ey_chunk->data[c2_i43 - 1] = c2_Ey->data[c2_idxEdge - 1];
        c2_i45 = c2_idxE->size[0];
        if ((c2_idxEdge < 1) || (c2_idxEdge > c2_i45)) {
          emlrtDynamicBoundsCheckR2012b(c2_idxEdge, 1, c2_i45, &c2_p_emlrtBCI,
            (void *)c2_sp);
        }

        c2_i46 = c2_idxE_chunk->size[0];
        c2_i48 = (int32_T)c2_c_idx;
        if ((c2_i48 < 1) || (c2_i48 > c2_i46)) {
          emlrtDynamicBoundsCheckR2012b(c2_i48, 1, c2_i46, &c2_q_emlrtBCI, (void
            *)c2_sp);
        }

        c2_idxE_chunk->data[c2_i48 - 1] = c2_idxE->data[c2_idxEdge - 1];
        c2_idxEdge++;
      }

      c2_dim1 = (real_T)c2_idxE_chunk->size[0];
      c2_i35 = c2_xc->size[0] * c2_xc->size[1];
      c2_xc->size[0] = (int32_T)c2_dim1;
      c2_xc->size[1] = 581;
      c2_st.site = &c2_rj_emlrtRSI;
      c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_xc, c2_i35,
        &c2_x_emlrtRTEI);
      c2_i39 = c2_yc->size[0] * c2_yc->size[1];
      c2_yc->size[0] = (int32_T)c2_dim1;
      c2_yc->size[1] = 581;
      c2_st.site = &c2_qj_emlrtRSI;
      c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_yc, c2_i39,
        &c2_y_emlrtRTEI);
      c2_i41 = c2_w->size[0] * c2_w->size[1];
      c2_w->size[0] = (int32_T)c2_dim1;
      c2_w->size[1] = 581;
      c2_st.site = &c2_sj_emlrtRSI;
      c2_emxEnsureCapacity_creal_T1(chartInstance, &c2_st, c2_w, c2_i41,
        &c2_ab_emlrtRTEI);
      c2_i44 = c2_inside->size[0] * c2_inside->size[1];
      c2_inside->size[0] = (int32_T)c2_dim1;
      c2_inside->size[1] = 581;
      c2_st.site = &c2_ti_emlrtRSI;
      c2_emxEnsureCapacity_boolean_T(chartInstance, &c2_st, c2_inside, c2_i44,
        &c2_bb_emlrtRTEI);
      c2_i47 = c2_rows_to_keep->size[0];
      c2_rows_to_keep->size[0] = (int32_T)c2_dim1;
      c2_st.site = &c2_oj_emlrtRSI;
      c2_emxEnsureCapacity_boolean_T1(chartInstance, &c2_st, c2_rows_to_keep,
        c2_i47, &c2_cb_emlrtRTEI);
      c2_h_loop_ub = (int32_T)c2_dim1 - 1;
      for (c2_i50 = 0; c2_i50 <= c2_h_loop_ub; c2_i50++) {
        c2_rows_to_keep->data[c2_i50] = false;
      }

      for (c2_idx2 = 0; c2_idx2 < 581; c2_idx2++) {
        c2_b_idx2 = (real_T)c2_idx2 + 1.0;
        c2_i52 = (int32_T)c2_dim1 - 1;
        for (c2_idx1 = 0; c2_idx1 <= c2_i52; c2_idx1++) {
          c2_b_idx1 = (real_T)c2_idx1 + 1.0;
          c2_i55 = c2_idxE_chunk->size[0];
          c2_i56 = (int32_T)c2_b_idx1;
          if ((c2_i56 < 1) || (c2_i56 > c2_i55)) {
            emlrtDynamicBoundsCheckR2012b(c2_i56, 1, c2_i55, &c2_r_emlrtBCI,
              (void *)c2_sp);
          }

          c2_cb_x = chartInstance->c2_Gx[(int32_T)c2_idxE_chunk->data[c2_i56 - 1]
            - 1];
          c2_i58 = c2_idxE_chunk->size[0];
          c2_i59 = (int32_T)c2_b_idx1;
          if ((c2_i59 < 1) || (c2_i59 > c2_i58)) {
            emlrtDynamicBoundsCheckR2012b(c2_i59, 1, c2_i58, &c2_s_emlrtBCI,
              (void *)c2_sp);
          }

          c2_k_y = c2_b_gradientImg[(int32_T)c2_idxE_chunk->data[c2_i59 - 1] - 1];
          c2_db_x = c2_cb_x;
          c2_m_y = c2_k_y;
          c2_b_z = c2_db_x / c2_m_y;
          c2_l_a = -(-10.0 + -0.5 * (real_T)((int32_T)c2_b_idx2 - 1));
          c2_o_b = c2_b_z;
          c2_n_y = (real32_T)c2_l_a * c2_o_b;
          c2_i64 = c2_Ex_chunk->size[0];
          c2_i65 = (int32_T)c2_b_idx1;
          if ((c2_i65 < 1) || (c2_i65 > c2_i64)) {
            emlrtDynamicBoundsCheckR2012b(c2_i65, 1, c2_i64, &c2_t_emlrtBCI,
              (void *)c2_sp);
          }

          c2_eb_x = (real32_T)c2_Ex_chunk->data[c2_i65 - 1] + c2_n_y;
          if (c2_eb_x > 0.0F) {
            c2_o_y = c2_eb_x + 0.5F;
          } else if (c2_eb_x < 0.0F) {
            c2_o_y = c2_eb_x - 0.5F;
          } else {
            c2_o_y = 0.0F;
          }

          c2_i69 = c2_xc->size[0];
          c2_i71 = (int32_T)c2_b_idx1;
          if ((c2_i71 < 1) || (c2_i71 > c2_i69)) {
            emlrtDynamicBoundsCheckR2012b(c2_i71, 1, c2_i69, &c2_w_emlrtBCI,
              (void *)c2_sp);
          }

          c2_xc->data[(c2_i71 + c2_xc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1] =
            c2_o_y;
          c2_i75 = c2_idxE_chunk->size[0];
          c2_i77 = (int32_T)c2_b_idx1;
          if ((c2_i77 < 1) || (c2_i77 > c2_i75)) {
            emlrtDynamicBoundsCheckR2012b(c2_i77, 1, c2_i75, &c2_ab_emlrtBCI,
              (void *)c2_sp);
          }

          c2_fb_x = chartInstance->c2_Gy[(int32_T)c2_idxE_chunk->data[c2_i77 - 1]
            - 1];
          c2_i81 = c2_idxE_chunk->size[0];
          c2_i83 = (int32_T)c2_b_idx1;
          if ((c2_i83 < 1) || (c2_i83 > c2_i81)) {
            emlrtDynamicBoundsCheckR2012b(c2_i83, 1, c2_i81, &c2_bb_emlrtBCI,
              (void *)c2_sp);
          }

          c2_p_y = c2_b_gradientImg[(int32_T)c2_idxE_chunk->data[c2_i83 - 1] - 1];
          c2_gb_x = c2_fb_x;
          c2_q_y = c2_p_y;
          c2_c_z = c2_gb_x / c2_q_y;
          c2_m_a = -(-10.0 + -0.5 * (real_T)((int32_T)c2_b_idx2 - 1));
          c2_q_b = c2_c_z;
          c2_r_y = (real32_T)c2_m_a * c2_q_b;
          c2_i90 = c2_Ey_chunk->size[0];
          c2_i93 = (int32_T)c2_b_idx1;
          if ((c2_i93 < 1) || (c2_i93 > c2_i90)) {
            emlrtDynamicBoundsCheckR2012b(c2_i93, 1, c2_i90, &c2_nb_emlrtBCI,
              (void *)c2_sp);
          }

          c2_hb_x = (real32_T)c2_Ey_chunk->data[c2_i93 - 1] + c2_r_y;
          if (c2_hb_x > 0.0F) {
            c2_s_y = c2_hb_x + 0.5F;
          } else if (c2_hb_x < 0.0F) {
            c2_s_y = c2_hb_x - 0.5F;
          } else {
            c2_s_y = 0.0F;
          }

          c2_i98 = c2_yc->size[0];
          c2_i100 = (int32_T)c2_b_idx1;
          if ((c2_i100 < 1) || (c2_i100 > c2_i98)) {
            emlrtDynamicBoundsCheckR2012b(c2_i100, 1, c2_i98, &c2_ob_emlrtBCI,
              (void *)c2_sp);
          }

          c2_yc->data[(c2_i100 + c2_yc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1]
            = c2_s_y;
          c2_i102 = c2_w->size[0];
          c2_i104 = (int32_T)c2_b_idx1;
          if ((c2_i104 < 1) || (c2_i104 > c2_i102)) {
            emlrtDynamicBoundsCheckR2012b(c2_i104, 1, c2_i102, &c2_pb_emlrtBCI,
              (void *)c2_sp);
          }

          c2_w->data[(c2_i104 + c2_w->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1].
            re = c2_w0[(int32_T)c2_b_idx2 - 1].re;
          c2_i106 = c2_w->size[0];
          c2_i107 = (int32_T)c2_b_idx1;
          if ((c2_i107 < 1) || (c2_i107 > c2_i106)) {
            emlrtDynamicBoundsCheckR2012b(c2_i107, 1, c2_i106, &c2_pb_emlrtBCI,
              (void *)c2_sp);
          }

          c2_w->data[(c2_i107 + c2_w->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1].
            im = c2_w0[(int32_T)c2_b_idx2 - 1].im;
          c2_i110 = c2_xc->size[0];
          c2_i111 = (int32_T)c2_b_idx1;
          if ((c2_i111 < 1) || (c2_i111 > c2_i110)) {
            emlrtDynamicBoundsCheckR2012b(c2_i111, 1, c2_i110, &c2_qb_emlrtBCI,
              (void *)c2_sp);
          }

          c2_r_b = (c2_xc->data[(c2_i111 + c2_xc->size[0] * ((int32_T)c2_b_idx2
                      - 1)) - 1] >= 1.0F);
          c2_i113 = c2_xc->size[0];
          c2_i115 = (int32_T)c2_b_idx1;
          if ((c2_i115 < 1) || (c2_i115 > c2_i113)) {
            emlrtDynamicBoundsCheckR2012b(c2_i115, 1, c2_i113, &c2_rb_emlrtBCI,
              (void *)c2_sp);
          }

          c2_b_b1 = (c2_xc->data[(c2_i115 + c2_xc->size[0] * ((int32_T)c2_b_idx2
            - 1)) - 1] <= 640.0F);
          c2_b2 = (c2_r_b && c2_b_b1);
          c2_i117 = c2_yc->size[0];
          c2_i118 = (int32_T)c2_b_idx1;
          if ((c2_i118 < 1) || (c2_i118 > c2_i117)) {
            emlrtDynamicBoundsCheckR2012b(c2_i118, 1, c2_i117, &c2_sb_emlrtBCI,
              (void *)c2_sp);
          }

          c2_b3 = (c2_yc->data[(c2_i118 + c2_yc->size[0] * ((int32_T)c2_b_idx2 -
                     1)) - 1] >= 1.0F);
          c2_b4 = (c2_b2 && c2_b3);
          c2_i119 = c2_yc->size[0];
          c2_i120 = (int32_T)c2_b_idx1;
          if ((c2_i120 < 1) || (c2_i120 > c2_i119)) {
            emlrtDynamicBoundsCheckR2012b(c2_i120, 1, c2_i119, &c2_tb_emlrtBCI,
              (void *)c2_sp);
          }

          c2_b5 = (c2_yc->data[(c2_i120 + c2_yc->size[0] * ((int32_T)c2_b_idx2 -
                     1)) - 1] < 480.0F);
          c2_i121 = c2_inside->size[0];
          c2_i122 = (int32_T)c2_b_idx1;
          if ((c2_i122 < 1) || (c2_i122 > c2_i121)) {
            emlrtDynamicBoundsCheckR2012b(c2_i122, 1, c2_i121, &c2_ub_emlrtBCI,
              (void *)c2_sp);
          }

          c2_inside->data[(c2_i122 + c2_inside->size[0] * ((int32_T)c2_b_idx2 -
            1)) - 1] = (c2_b4 && c2_b5);
          c2_i123 = c2_inside->size[0];
          c2_i124 = (int32_T)c2_b_idx1;
          if ((c2_i124 < 1) || (c2_i124 > c2_i123)) {
            emlrtDynamicBoundsCheckR2012b(c2_i124, 1, c2_i123, &c2_vb_emlrtBCI,
              (void *)c2_sp);
          }

          if (c2_inside->data[(c2_i124 + c2_inside->size[0] * ((int32_T)
                c2_b_idx2 - 1)) - 1]) {
            c2_i125 = c2_rows_to_keep->size[0];
            c2_i126 = (int32_T)c2_b_idx1;
            if ((c2_i126 < 1) || (c2_i126 > c2_i125)) {
              emlrtDynamicBoundsCheckR2012b(c2_i126, 1, c2_i125, &c2_wb_emlrtBCI,
                (void *)c2_sp);
            }

            c2_rows_to_keep->data[c2_i126 - 1] = true;
          }
        }
      }

      c2_i51 = c2_xckeep->size[0];
      c2_xckeep->size[0] = c2_xc->size[0] * 581;
      c2_st.site = &c2_dj_emlrtRSI;
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_xckeep, c2_i51,
        &c2_db_emlrtRTEI);
      c2_i54 = c2_yckeep->size[0];
      c2_yckeep->size[0] = c2_yc->size[0] * 581;
      c2_st.site = &c2_cj_emlrtRSI;
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_yckeep, c2_i54,
        &c2_eb_emlrtRTEI);
      c2_i57 = c2_wkeep->size[0];
      c2_wkeep->size[0] = c2_w->size[0] * 581;
      c2_st.site = &c2_hi_emlrtRSI;
      c2_emxEnsureCapacity_creal_T(chartInstance, &c2_st, c2_wkeep, c2_i57,
        &c2_fb_emlrtRTEI);
      c2_idxkeep = 0;
      for (c2_c_idx2 = 0; c2_c_idx2 < 581; c2_c_idx2++) {
        c2_b_idx2 = (real_T)c2_c_idx2 + 1.0;
        c2_i60 = (int32_T)c2_dim1 - 1;
        for (c2_c_idx1 = 0; c2_c_idx1 <= c2_i60; c2_c_idx1++) {
          c2_b_idx1 = (real_T)c2_c_idx1 + 1.0;
          c2_i62 = c2_rows_to_keep->size[0];
          c2_i63 = (int32_T)c2_b_idx1;
          if ((c2_i63 < 1) || (c2_i63 > c2_i62)) {
            emlrtDynamicBoundsCheckR2012b(c2_i63, 1, c2_i62, &c2_u_emlrtBCI,
              (void *)c2_sp);
          }

          if (c2_rows_to_keep->data[c2_i63 - 1]) {
            c2_i66 = c2_inside->size[0];
            c2_i67 = (int32_T)c2_b_idx1;
            if ((c2_i67 < 1) || (c2_i67 > c2_i66)) {
              emlrtDynamicBoundsCheckR2012b(c2_i67, 1, c2_i66, &c2_v_emlrtBCI,
                (void *)c2_sp);
            }

            if (c2_inside->data[(c2_i67 + c2_inside->size[0] * ((int32_T)
                  c2_b_idx2 - 1)) - 1]) {
              c2_idxkeep++;
              c2_i72 = c2_xc->size[0];
              c2_i73 = (int32_T)c2_b_idx1;
              if ((c2_i73 < 1) || (c2_i73 > c2_i72)) {
                emlrtDynamicBoundsCheckR2012b(c2_i73, 1, c2_i72, &c2_x_emlrtBCI,
                  (void *)c2_sp);
              }

              c2_i76 = c2_xckeep->size[0];
              if ((c2_idxkeep < 1) || (c2_idxkeep > c2_i76)) {
                emlrtDynamicBoundsCheckR2012b(c2_idxkeep, 1, c2_i76,
                  &c2_y_emlrtBCI, (void *)c2_sp);
              }

              c2_xckeep->data[c2_idxkeep - 1] = (int32_T)c2_xc->data[(c2_i73 +
                c2_xc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1];
              c2_i80 = c2_yc->size[0];
              c2_i82 = (int32_T)c2_b_idx1;
              if ((c2_i82 < 1) || (c2_i82 > c2_i80)) {
                emlrtDynamicBoundsCheckR2012b(c2_i82, 1, c2_i80, &c2_cb_emlrtBCI,
                  (void *)c2_sp);
              }

              c2_i85 = c2_yckeep->size[0];
              if ((c2_idxkeep < 1) || (c2_idxkeep > c2_i85)) {
                emlrtDynamicBoundsCheckR2012b(c2_idxkeep, 1, c2_i85,
                  &c2_db_emlrtBCI, (void *)c2_sp);
              }

              c2_yckeep->data[c2_idxkeep - 1] = (int32_T)c2_yc->data[(c2_i82 +
                c2_yc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1];
              c2_i87 = c2_wkeep->size[0];
              if ((c2_idxkeep < 1) || (c2_idxkeep > c2_i87)) {
                emlrtDynamicBoundsCheckR2012b(c2_idxkeep, 1, c2_i87,
                  &c2_fb_emlrtBCI, (void *)c2_sp);
              }

              c2_i89 = c2_w->size[0];
              c2_i92 = (int32_T)c2_b_idx1;
              if ((c2_i92 < 1) || (c2_i92 > c2_i89)) {
                emlrtDynamicBoundsCheckR2012b(c2_i92, 1, c2_i89, &c2_eb_emlrtBCI,
                  (void *)c2_sp);
              }

              c2_wkeep->data[c2_idxkeep - 1].re = c2_w->data[(c2_i92 +
                c2_w->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1].re;
              c2_i95 = c2_w->size[0];
              c2_i96 = (int32_T)c2_b_idx1;
              if ((c2_i96 < 1) || (c2_i96 > c2_i95)) {
                emlrtDynamicBoundsCheckR2012b(c2_i96, 1, c2_i95, &c2_eb_emlrtBCI,
                  (void *)c2_sp);
              }

              c2_i99 = c2_wkeep->size[0];
              if ((c2_idxkeep < 1) || (c2_idxkeep > c2_i99)) {
                emlrtDynamicBoundsCheckR2012b(c2_idxkeep, 1, c2_i99,
                  &c2_fb_emlrtBCI, (void *)c2_sp);
              }

              c2_wkeep->data[c2_idxkeep - 1].im = c2_w->data[(c2_i96 +
                c2_w->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1].im;
            }
          }
        }
      }

      c2_st.site = &c2_p_emlrtRSI;
      c2_szxc = c2_idxkeep;
      for (c2_i61 = 0; c2_i61 < 307200; c2_i61++) {
        chartInstance->c2_out[c2_i61].re = 0.0;
        chartInstance->c2_out[c2_i61].im = 0.0;
      }

      c2_b_st.site = &c2_pe_emlrtRSI;
      c2_n_b = c2_szxc;
      c2_p_b = c2_n_b;
      if (1 > c2_p_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_p_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_c_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
      }

      for (c2_d_idx = 1; c2_d_idx - 1 < c2_szxc; c2_d_idx++) {
        c2_e_idx = c2_d_idx;
        c2_i70 = c2_yckeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i70)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i70, &c2_lb_emlrtBCI,
            &c2_st);
        }

        c2_i74 = c2_yckeep->data[c2_e_idx - 1];
        if ((c2_i74 < 1) || (c2_i74 > 480)) {
          emlrtDynamicBoundsCheckR2012b(c2_i74, 1, 480, &c2_kb_emlrtBCI, &c2_st);
        }

        c2_i78 = c2_xckeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i78)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i78, &c2_lb_emlrtBCI,
            &c2_st);
        }

        c2_i79 = c2_xckeep->data[c2_e_idx - 1];
        if ((c2_i79 < 1) || (c2_i79 > 640)) {
          emlrtDynamicBoundsCheckR2012b(c2_i79, 1, 640, &c2_mb_emlrtBCI, &c2_st);
        }

        c2_i84 = c2_yckeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i84)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i84, &c2_hb_emlrtBCI,
            &c2_st);
        }

        c2_i86 = c2_yckeep->data[c2_e_idx - 1];
        if ((c2_i86 < 1) || (c2_i86 > 480)) {
          emlrtDynamicBoundsCheckR2012b(c2_i86, 1, 480, &c2_gb_emlrtBCI, &c2_st);
        }

        c2_i88 = c2_xckeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i88)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i88, &c2_hb_emlrtBCI,
            &c2_st);
        }

        c2_i91 = c2_xckeep->data[c2_e_idx - 1];
        if ((c2_i91 < 1) || (c2_i91 > 640)) {
          emlrtDynamicBoundsCheckR2012b(c2_i91, 1, 640, &c2_ib_emlrtBCI, &c2_st);
        }

        c2_i94 = c2_wkeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i94)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i94, &c2_jb_emlrtBCI,
            &c2_st);
        }

        chartInstance->c2_out[(c2_i74 + 480 * (c2_i79 - 1)) - 1].re =
          chartInstance->c2_out[(c2_i86 + 480 * (c2_i91 - 1)) - 1].re +
          c2_wkeep->data[c2_e_idx - 1].re;
        c2_i97 = c2_yckeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i97)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i97, &c2_hb_emlrtBCI,
            &c2_st);
        }

        c2_i101 = c2_yckeep->data[c2_e_idx - 1];
        if ((c2_i101 < 1) || (c2_i101 > 480)) {
          emlrtDynamicBoundsCheckR2012b(c2_i101, 1, 480, &c2_gb_emlrtBCI, &c2_st);
        }

        c2_i103 = c2_xckeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i103)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i103, &c2_hb_emlrtBCI,
            &c2_st);
        }

        c2_i105 = c2_xckeep->data[c2_e_idx - 1];
        if ((c2_i105 < 1) || (c2_i105 > 640)) {
          emlrtDynamicBoundsCheckR2012b(c2_i105, 1, 640, &c2_ib_emlrtBCI, &c2_st);
        }

        c2_i108 = c2_wkeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i108)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i108, &c2_jb_emlrtBCI,
            &c2_st);
        }

        c2_i109 = c2_yckeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i109)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i109, &c2_lb_emlrtBCI,
            &c2_st);
        }

        c2_i112 = c2_yckeep->data[c2_e_idx - 1];
        if ((c2_i112 < 1) || (c2_i112 > 480)) {
          emlrtDynamicBoundsCheckR2012b(c2_i112, 1, 480, &c2_kb_emlrtBCI, &c2_st);
        }

        c2_i114 = c2_xckeep->size[0];
        if ((c2_e_idx < 1) || (c2_e_idx > c2_i114)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_idx, 1, c2_i114, &c2_lb_emlrtBCI,
            &c2_st);
        }

        c2_i116 = c2_xckeep->data[c2_e_idx - 1];
        if ((c2_i116 < 1) || (c2_i116 > 640)) {
          emlrtDynamicBoundsCheckR2012b(c2_i116, 1, 640, &c2_mb_emlrtBCI, &c2_st);
        }

        chartInstance->c2_out[(c2_i112 + 480 * (c2_i116 - 1)) - 1].im =
          chartInstance->c2_out[(c2_i101 + 480 * (c2_i105 - 1)) - 1].im +
          c2_wkeep->data[c2_e_idx - 1].im;
      }

      for (c2_i68 = 0; c2_i68 < 307200; c2_i68++) {
        c2_c_accumMatrix[c2_i68].re += chartInstance->c2_out[c2_i68].re;
        c2_c_accumMatrix[c2_i68].im += chartInstance->c2_out[c2_i68].im;
      }

      c2_b_i++;
    }

    c2_emxFree_real_T(chartInstance, &c2_Ex);
    c2_emxFree_real_T(chartInstance, &c2_Ey);
    c2_emxFree_real_T(chartInstance, &c2_r);
    c2_emxFree_creal_T(chartInstance, &c2_wkeep);
    c2_emxFree_int32_T(chartInstance, &c2_yckeep);
    c2_emxFree_int32_T(chartInstance, &c2_xckeep);
    c2_emxFree_boolean_T(chartInstance, &c2_rows_to_keep);
    c2_emxFree_boolean_T(chartInstance, &c2_inside);
    c2_emxFree_creal_T(chartInstance, &c2_w);
    c2_emxFree_real32_T(chartInstance, &c2_yc);
    c2_emxFree_real32_T(chartInstance, &c2_xc);
    c2_emxFree_real_T(chartInstance, &c2_idxE_chunk);
    c2_emxFree_real_T(chartInstance, &c2_Ey_chunk);
    c2_emxFree_real_T(chartInstance, &c2_Ex_chunk);
    c2_emxFree_real_T(chartInstance, &c2_idxE);
  }
}

static void c2_imfilter(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real32_T c2_f_varargin_1[307200], real32_T c2_b[307200])
{
  static real_T c2_kernel[9] = { -1.0, -2.0, -1.0, -0.0, -0.0, -0.0, 1.0, 2.0,
    1.0 };

  static real_T c2_nonZeroKernel[6] = { -1.0, -2.0, -1.0, 1.0, 2.0, 1.0 };

  static boolean_T c2_conn[9] = { true, true, true, false, false, false, true,
    true, true };

  emlrtStack c2_st;
  real_T c2_connDimsT[2];
  real_T c2_outSizeT[2];
  real_T c2_padSizeT[2];
  real_T c2_startT[2];
  int32_T c2_b_i;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  boolean_T c2_modeFlag;
  boolean_T c2_tooBig;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_s_emlrtRSI;
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    chartInstance->c2_e_varargin_1[c2_i] = c2_f_varargin_1[c2_i];
  }

  c2_padImage(chartInstance, &c2_st, chartInstance->c2_e_varargin_1,
              chartInstance->c2_c_a);
  c2_tooBig = true;
  for (c2_b_i = 0; c2_b_i < 2; c2_b_i++) {
    c2_tooBig = false;
  }

  if (!c2_tooBig) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
      c2_padSizeT[c2_i2] = 482.0 + 160.0 * (real_T)c2_i2;
    }

    for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
      c2_outSizeT[c2_i4] = 480.0 + 160.0 * (real_T)c2_i4;
    }

    for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
      c2_connDimsT[c2_i6] = 3.0;
    }

    ippfilter_real32(&chartInstance->c2_c_a[0], &c2_b[0], &c2_outSizeT[0], 2.0,
                     &c2_padSizeT[0], &c2_kernel[0], &c2_connDimsT[0], true);
  } else {
    for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
      c2_padSizeT[c2_i1] = 482.0 + 160.0 * (real_T)c2_i1;
    }

    for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
      c2_outSizeT[c2_i3] = 480.0 + 160.0 * (real_T)c2_i3;
    }

    for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
      c2_connDimsT[c2_i5] = 3.0;
    }

    for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
      c2_startT[c2_i7] = 1.0;
    }

    imfilter_real32(&chartInstance->c2_c_a[0], &c2_b[0], 2.0, &c2_outSizeT[0],
                    2.0, &c2_padSizeT[0], &c2_nonZeroKernel[0], 6.0, &c2_conn[0],
                    2.0, &c2_connDimsT[0], &c2_startT[0], 2.0, true, true);
  }
}

static void c2_padImage(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real32_T c2_a_tmp[307200], real32_T c2_d_a[309444])
{
  static int32_T c2_idxA[1284] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
    90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
    122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136,
    137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151,
    152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166,
    167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181,
    182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196,
    197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211,
    212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226,
    227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241,
    242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256,
    257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271,
    272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286,
    287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301,
    302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316,
    317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331,
    332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346,
    347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361,
    362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376,
    377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391,
    392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406,
    407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421,
    422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436,
    437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451,
    452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466,
    467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 480, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
    19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
    38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
    57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,
    76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94,
    95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
    111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125,
    126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
    141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155,
    156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
    171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185,
    186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200,
    201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215,
    216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230,
    231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245,
    246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260,
    261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275,
    276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290,
    291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305,
    306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320,
    321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335,
    336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350,
    351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365,
    366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380,
    381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395,
    396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410,
    411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425,
    426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440,
    441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455,
    456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470,
    471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485,
    486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500,
    501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515,
    516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530,
    531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545,
    546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560,
    561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575,
    576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590,
    591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605,
    606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620,
    621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635,
    636, 637, 638, 639, 640, 640 };

  emlrtStack c2_st;
  real_T c2_b_i;
  real_T c2_b_j;
  int32_T c2_c_i;
  int32_T c2_i;
  int32_T c2_j;
  (void)chartInstance;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_u_emlrtRSI;
  for (c2_j = 0; c2_j < 642; c2_j++) {
    c2_b_j = (real_T)c2_j + 1.0;
    for (c2_i = 0; c2_i < 482; c2_i++) {
      c2_b_i = (real_T)c2_i + 1.0;
      if ((c2_idxA[(int32_T)c2_b_i - 1] < 1) || (c2_idxA[(int32_T)c2_b_i - 1] >
           480)) {
        emlrtDynamicBoundsCheckR2012b(c2_idxA[(int32_T)c2_b_i - 1], 1, 480,
          &c2_xb_emlrtBCI, &c2_st);
      }

      c2_c_i = c2_idxA[(int32_T)c2_b_j + 641];
      if ((c2_c_i < 1) || (c2_c_i > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_c_i, 1, 640, &c2_yb_emlrtBCI, &c2_st);
      }

      c2_d_a[((int32_T)c2_b_i + 482 * ((int32_T)c2_b_j - 1)) - 1] = c2_a_tmp
        [(c2_idxA[(int32_T)c2_b_i - 1] + 480 * (c2_c_i - 1)) - 1];
    }
  }
}

static void c2_b_imfilter(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, real32_T c2_f_varargin_1[307200], real32_T c2_b[307200])
{
  static real_T c2_kernel[9] = { -1.0, -0.0, 1.0, -2.0, -0.0, 2.0, -1.0, -0.0,
    1.0 };

  static real_T c2_nonZeroKernel[6] = { -1.0, 1.0, -2.0, 2.0, -1.0, 1.0 };

  static boolean_T c2_conn[9] = { true, false, true, true, false, true, true,
    false, true };

  emlrtStack c2_st;
  real_T c2_connDimsT[2];
  real_T c2_outSizeT[2];
  real_T c2_padSizeT[2];
  real_T c2_startT[2];
  int32_T c2_b_i;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  boolean_T c2_modeFlag;
  boolean_T c2_tooBig;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_s_emlrtRSI;
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    chartInstance->c2_d_varargin_1[c2_i] = c2_f_varargin_1[c2_i];
  }

  c2_padImage(chartInstance, &c2_st, chartInstance->c2_d_varargin_1,
              chartInstance->c2_b_a);
  c2_tooBig = true;
  for (c2_b_i = 0; c2_b_i < 2; c2_b_i++) {
    c2_tooBig = false;
  }

  if (!c2_tooBig) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
      c2_padSizeT[c2_i2] = 482.0 + 160.0 * (real_T)c2_i2;
    }

    for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
      c2_outSizeT[c2_i4] = 480.0 + 160.0 * (real_T)c2_i4;
    }

    for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
      c2_connDimsT[c2_i6] = 3.0;
    }

    ippfilter_real32(&chartInstance->c2_b_a[0], &c2_b[0], &c2_outSizeT[0], 2.0,
                     &c2_padSizeT[0], &c2_kernel[0], &c2_connDimsT[0], true);
  } else {
    for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
      c2_padSizeT[c2_i1] = 482.0 + 160.0 * (real_T)c2_i1;
    }

    for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
      c2_outSizeT[c2_i3] = 480.0 + 160.0 * (real_T)c2_i3;
    }

    for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
      c2_connDimsT[c2_i5] = 3.0;
    }

    for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
      c2_startT[c2_i7] = 1.0;
    }

    imfilter_real32(&chartInstance->c2_b_a[0], &c2_b[0], 2.0, &c2_outSizeT[0],
                    2.0, &c2_padSizeT[0], &c2_nonZeroKernel[0], 6.0, &c2_conn[0],
                    2.0, &c2_connDimsT[0], &c2_startT[0], 2.0, true, true);
  }
}

static real32_T c2_maximum(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real32_T c2_e_x[307200])
{
  c2_emxArray_real32_T *c2_f_x;
  int32_T c2_b_idx;
  int32_T c2_b_k;
  int32_T c2_first;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_k;
  real32_T c2_b_ex;
  real32_T c2_ex;
  real32_T c2_g_x;
  real32_T c2_h_x;
  real32_T c2_i_x;
  real32_T c2_j_x;
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  c2_emxInit_real32_T1(chartInstance, c2_sp, &c2_f_x, 1, &c2_tb_emlrtRTEI);
  c2_i = c2_f_x->size[0];
  c2_f_x->size[0] = 307200;
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_sp, c2_f_x, c2_i,
    &c2_tb_emlrtRTEI);
  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    c2_f_x->data[c2_i1] = c2_e_x[c2_i1];
  }

  c2_g_x = c2_f_x->data[0];
  c2_h_x = c2_g_x;
  c2_b = muSingleScalarIsNaN(c2_h_x);
  c2_p = !c2_b;
  if (c2_p) {
    c2_b_idx = 1;
  } else {
    c2_b_idx = 0;
    c2_k = 2;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_k < 307201)) {
      c2_i_x = c2_f_x->data[c2_k - 1];
      c2_j_x = c2_i_x;
      c2_b_b = muSingleScalarIsNaN(c2_j_x);
      c2_b_p = !c2_b_b;
      if (c2_b_p) {
        c2_b_idx = c2_k;
        c2_exitg1 = true;
      } else {
        c2_k++;
      }
    }
  }

  if (c2_b_idx == 0) {
    c2_ex = c2_f_x->data[0];
  } else {
    c2_first = c2_b_idx - 1;
    c2_b_ex = c2_f_x->data[c2_first];
    c2_i2 = c2_first;
    for (c2_b_k = c2_i2 + 1; c2_b_k + 1 < 307201; c2_b_k++) {
      if (c2_b_ex < c2_f_x->data[c2_b_k]) {
        c2_b_ex = c2_f_x->data[c2_b_k];
      }
    }

    c2_ex = c2_b_ex;
  }

  c2_emxFree_real32_T(chartInstance, &c2_f_x);
  return c2_ex;
}

static real32_T c2_multithresh(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real32_T c2_f_varargin_1[307200])
{
  c2_emxArray_boolean_T *c2_r1;
  c2_emxArray_boolean_T *c2_r2;
  c2_emxArray_boolean_T *c2_r4;
  c2_emxArray_boolean_T *c2_r5;
  c2_emxArray_boolean_T *c2_r6;
  c2_emxArray_boolean_T *c2_r7;
  c2_emxArray_int32_T *c2_r;
  c2_emxArray_real32_T *c2_b_threshout;
  c2_emxArray_real32_T *c2_img;
  c2_emxArray_real32_T *c2_threshL;
  c2_emxArray_real32_T *c2_uniqueVals;
  c2_emxArray_real_T *c2_b_uniqueVals_d;
  c2_emxArray_real_T *c2_d_uniqueVals_d;
  c2_emxArray_real_T *c2_r3;
  c2_emxArray_real_T *c2_threshRaw;
  c2_emxArray_real_T *c2_uniqueVals_d;
  c2_emxArray_uint8_T *c2_Auint8;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_st;
  real_T c2_b_counts[256];
  real_T c2_c_counts[256];
  real_T c2_counts[256];
  real_T c2_d_y[256];
  real_T c2_mu[256];
  real_T c2_omega[256];
  real_T c2_b_ind;
  real_T c2_b_lenThreshOrig;
  real_T c2_b_mu_t;
  real_T c2_b_numElems;
  real_T c2_b_q;
  real_T c2_b_thNeeded1;
  real_T c2_b_thNeeded2;
  real_T c2_b_threshCandidate_d;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_e_a;
  real_T c2_e_y;
  real_T c2_f_a;
  real_T c2_idxNum;
  real_T c2_idxSum;
  real_T c2_lenThreshOrig;
  real_T c2_maxval;
  real_T c2_mu_t;
  real_T c2_n_b;
  real_T c2_numElems;
  real_T c2_o_x;
  real_T c2_p_b;
  real_T c2_p_x;
  real_T c2_q;
  real_T c2_q_x;
  real_T c2_thNeeded1;
  real_T c2_thNeeded2;
  real_T c2_threshCandidate_d;
  int32_T c2_iv[2];
  int32_T c2_iv1[2];
  int32_T c2_iv2[2];
  int32_T c2_iv3[2];
  int32_T c2_y_size[2];
  int32_T c2_c_uniqueVals_d[1];
  int32_T c2_e_uniqueVals_d[1];
  int32_T c2_ab_loop_ub;
  int32_T c2_b_i;
  int32_T c2_b_idx;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_b_trueCount;
  int32_T c2_bb_loop_ub;
  int32_T c2_c_i;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_cb_loop_ub;
  int32_T c2_d_i;
  int32_T c2_d_k;
  int32_T c2_d_loop_ub;
  int32_T c2_db_loop_ub;
  int32_T c2_e_k;
  int32_T c2_e_loop_ub;
  int32_T c2_eb_loop_ub;
  int32_T c2_f_k;
  int32_T c2_f_loop_ub;
  int32_T c2_fb_loop_ub;
  int32_T c2_g_k;
  int32_T c2_g_loop_ub;
  int32_T c2_gb_loop_ub;
  int32_T c2_h_loop_ub;
  int32_T c2_hb_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  int32_T c2_i103;
  int32_T c2_i104;
  int32_T c2_i105;
  int32_T c2_i106;
  int32_T c2_i107;
  int32_T c2_i108;
  int32_T c2_i109;
  int32_T c2_i11;
  int32_T c2_i110;
  int32_T c2_i111;
  int32_T c2_i112;
  int32_T c2_i113;
  int32_T c2_i114;
  int32_T c2_i115;
  int32_T c2_i116;
  int32_T c2_i117;
  int32_T c2_i118;
  int32_T c2_i119;
  int32_T c2_i12;
  int32_T c2_i120;
  int32_T c2_i121;
  int32_T c2_i122;
  int32_T c2_i123;
  int32_T c2_i124;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i5;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i6;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i7;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i8;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  int32_T c2_i9;
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_i_loop_ub;
  int32_T c2_ib_loop_ub;
  int32_T c2_ind;
  int32_T c2_j_loop_ub;
  int32_T c2_jb_loop_ub;
  int32_T c2_k;
  int32_T c2_k_loop_ub;
  int32_T c2_kb_loop_ub;
  int32_T c2_l_loop_ub;
  int32_T c2_loop_ub;
  int32_T c2_m_loop_ub;
  int32_T c2_n_loop_ub;
  int32_T c2_o_loop_ub;
  int32_T c2_p_loop_ub;
  int32_T c2_partialTrueCount;
  int32_T c2_q_loop_ub;
  int32_T c2_r_loop_ub;
  int32_T c2_s_loop_ub;
  int32_T c2_t_loop_ub;
  int32_T c2_trueCount;
  int32_T c2_u_loop_ub;
  int32_T c2_v_loop_ub;
  int32_T c2_w_loop_ub;
  int32_T c2_x_loop_ub;
  int32_T c2_y_loop_ub;
  real32_T c2_y_data[1];
  real32_T c2_ab_x;
  real32_T c2_b_d;
  real32_T c2_b_maxA;
  real32_T c2_b_minA;
  real32_T c2_b_minval;
  real32_T c2_b_threshCandidate;
  real32_T c2_b_varargin_2;
  real32_T c2_b_y;
  real32_T c2_bb_x;
  real32_T c2_c_d;
  real32_T c2_c_maxA;
  real32_T c2_c_minA;
  real32_T c2_c_varargin_2;
  real32_T c2_c_y;
  real32_T c2_cb_x;
  real32_T c2_d_a;
  real32_T c2_d_minA;
  real32_T c2_db_x;
  real32_T c2_e_x;
  real32_T c2_eb_x;
  real32_T c2_f_x;
  real32_T c2_f_y;
  real32_T c2_fb_x;
  real32_T c2_g_a;
  real32_T c2_g_varargin_1;
  real32_T c2_g_x;
  real32_T c2_g_y;
  real32_T c2_gb_x;
  real32_T c2_h_a;
  real32_T c2_h_varargin_1;
  real32_T c2_h_x;
  real32_T c2_h_y;
  real32_T c2_hb_x;
  real32_T c2_i_x;
  real32_T c2_i_y;
  real32_T c2_ib_x;
  real32_T c2_j_x;
  real32_T c2_j_y;
  real32_T c2_jb_x;
  real32_T c2_k_x;
  real32_T c2_k_y;
  real32_T c2_l_x;
  real32_T c2_l_y;
  real32_T c2_m_x;
  real32_T c2_m_y;
  real32_T c2_maxA;
  real32_T c2_minA;
  real32_T c2_minval;
  real32_T c2_n_x;
  real32_T c2_n_y;
  real32_T c2_o_b;
  real32_T c2_o_y;
  real32_T c2_q_b;
  real32_T c2_r_x;
  real32_T c2_s_b;
  real32_T c2_s_x;
  real32_T c2_t_b;
  real32_T c2_t_x;
  real32_T c2_thresh;
  real32_T c2_threshCandidate;
  real32_T c2_threshout;
  real32_T c2_u_x;
  real32_T c2_v_x;
  real32_T c2_w_x;
  real32_T c2_x_x;
  real32_T c2_y_x;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b3;
  boolean_T c2_b4;
  boolean_T c2_b5;
  boolean_T c2_b6;
  boolean_T c2_b7;
  boolean_T c2_b8;
  boolean_T c2_b9;
  boolean_T c2_b_b;
  boolean_T c2_b_isDegenerate;
  boolean_T c2_c_b;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  boolean_T c2_emptyp;
  boolean_T c2_exitg1;
  boolean_T c2_f_b;
  boolean_T c2_g_b;
  boolean_T c2_guard1 = false;
  boolean_T c2_h_b;
  boolean_T c2_i_b;
  boolean_T c2_isDegenerate;
  boolean_T c2_isvalid_maxval;
  boolean_T c2_j_b;
  boolean_T c2_k_b;
  boolean_T c2_l_b;
  boolean_T c2_m_b;
  boolean_T c2_r_b;
  boolean_T c2_u_b;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_st.site = &c2_cb_emlrtRSI;
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    chartInstance->c2_c_A[c2_i] = c2_f_varargin_1[c2_i];
  }

  c2_emptyp = true;
  c2_b_idx = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_b_idx + 1 <= 307200)) {
    c2_e_x = chartInstance->c2_c_A[c2_b_idx];
    c2_f_x = c2_e_x;
    c2_b = muSingleScalarIsInf(c2_f_x);
    c2_b_b = !c2_b;
    c2_g_x = c2_e_x;
    c2_c_b = muSingleScalarIsNaN(c2_g_x);
    c2_b1 = !c2_c_b;
    c2_d_b = (c2_b_b && c2_b1);
    if (!c2_d_b) {
      c2_b_idx++;
    } else {
      c2_exitg1 = true;
    }
  }

  c2_emxInit_real32_T1(chartInstance, &c2_st, &c2_img, 1, &c2_vb_emlrtRTEI);
  if (c2_b_idx + 1 <= 307200) {
    c2_minA = chartInstance->c2_c_A[c2_b_idx];
    c2_maxA = chartInstance->c2_c_A[c2_b_idx];
    c2_i2 = c2_b_idx;
    for (c2_k = c2_i2 + 2; c2_k < 307201; c2_k++) {
      c2_d_a = chartInstance->c2_c_A[c2_k - 1];
      c2_guard1 = false;
      if (c2_d_a < c2_minA) {
        c2_h_x = c2_d_a;
        c2_i_x = c2_h_x;
        c2_e_b = muSingleScalarIsInf(c2_i_x);
        c2_b2 = !c2_e_b;
        c2_l_x = c2_h_x;
        c2_g_b = muSingleScalarIsNaN(c2_l_x);
        c2_b3 = !c2_g_b;
        c2_i_b = (c2_b2 && c2_b3);
        if (c2_i_b) {
          c2_minA = c2_d_a;
        } else {
          c2_guard1 = true;
        }
      } else {
        c2_guard1 = true;
      }

      if (c2_guard1 && (c2_d_a > c2_maxA)) {
        c2_k_x = c2_d_a;
        c2_m_x = c2_k_x;
        c2_h_b = muSingleScalarIsInf(c2_m_x);
        c2_b4 = !c2_h_b;
        c2_n_x = c2_k_x;
        c2_j_b = muSingleScalarIsNaN(c2_n_x);
        c2_b5 = !c2_j_b;
        c2_k_b = (c2_b4 && c2_b5);
        if (c2_k_b) {
          c2_maxA = c2_d_a;
        }
      }
    }

    if (!(c2_minA == c2_maxA)) {
      for (c2_i3 = 0; c2_i3 < 307200; c2_i3++) {
        chartInstance->c2_c_A[c2_i3] -= c2_minA;
      }

      c2_b_y = c2_maxA - c2_minA;
      c2_c_y = c2_b_y;
      for (c2_i5 = 0; c2_i5 < 307200; c2_i5++) {
        chartInstance->c2_c_A[c2_i5] /= c2_c_y;
      }

      for (c2_i7 = 0; c2_i7 < 307200; c2_i7++) {
        chartInstance->c2_nans[c2_i7] = muSingleScalarIsNaN
          (chartInstance->c2_c_A[c2_i7]);
      }

      c2_trueCount = 0;
      for (c2_b_i = 0; c2_b_i < 307200; c2_b_i++) {
        if (!chartInstance->c2_nans[c2_b_i]) {
          c2_trueCount++;
        }
      }

      if (c2_trueCount != 0) {
        c2_b_trueCount = 0;
        for (c2_c_i = 0; c2_c_i < 307200; c2_c_i++) {
          if (!chartInstance->c2_nans[c2_c_i]) {
            c2_b_trueCount++;
          }
        }

        c2_emxInit_int32_T(chartInstance, &c2_st, &c2_r, 1, &c2_wc_emlrtRTEI);
        c2_i11 = c2_r->size[0];
        c2_r->size[0] = c2_b_trueCount;
        c2_b_st.site = &c2_bj_emlrtRSI;
        c2_emxEnsureCapacity_int32_T(chartInstance, &c2_b_st, c2_r, c2_i11,
          &c2_ub_emlrtRTEI);
        c2_partialTrueCount = 0;
        for (c2_d_i = 0; c2_d_i < 307200; c2_d_i++) {
          if (!chartInstance->c2_nans[c2_d_i]) {
            c2_r->data[c2_partialTrueCount] = c2_d_i + 1;
            c2_partialTrueCount++;
          }
        }

        c2_b_st.site = &c2_mb_emlrtRSI;
        c2_i13 = c2_img->size[0];
        c2_img->size[0] = c2_r->size[0];
        c2_emxEnsureCapacity_real32_T1(chartInstance, &c2_b_st, c2_img, c2_i13,
          &c2_vb_emlrtRTEI);
        c2_loop_ub = c2_r->size[0] - 1;
        for (c2_i14 = 0; c2_i14 <= c2_loop_ub; c2_i14++) {
          c2_img->data[c2_i14] = chartInstance->c2_c_A[c2_r->data[c2_i14] - 1];
        }

        c2_emxFree_int32_T(chartInstance, &c2_r);
        c2_emxInit_uint8_T(chartInstance, &c2_b_st, &c2_Auint8, 1,
                           &c2_vc_emlrtRTEI);
        c2_c_st.site = &c2_pb_emlrtRSI;
        c2_d_st.site = &c2_qb_emlrtRSI;
        c2_i15 = c2_Auint8->size[0];
        c2_Auint8->size[0] = c2_img->size[0];
        c2_emxEnsureCapacity_uint8_T(chartInstance, &c2_d_st, c2_Auint8, c2_i15,
          &c2_wb_emlrtRTEI);
        c2_numElems = (real_T)c2_img->size[0];
        c2_b_numElems = c2_numElems;
        grayto8_real32(&c2_img->data[0], &c2_Auint8->data[0], c2_b_numElems);
        c2_b_st.site = &c2_nb_emlrtRSI;
        c2_imhist(chartInstance, &c2_b_st, c2_Auint8, c2_counts);
        c2_b_st.site = &c2_ob_emlrtRSI;
        for (c2_i19 = 0; c2_i19 < 256; c2_i19++) {
          c2_c_counts[c2_i19] = c2_counts[c2_i19];
        }

        c2_d = c2_sum(chartInstance, c2_c_counts);
        c2_emxFree_uint8_T(chartInstance, &c2_Auint8);
        for (c2_i20 = 0; c2_i20 < 256; c2_i20++) {
          c2_mu[c2_i20] = c2_counts[c2_i20] / c2_d;
        }

        c2_emptyp = false;
      }
    }
  } else {
    for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
      chartInstance->c2_varargin_1[c2_i1] = chartInstance->c2_c_A[c2_i1];
    }

    c2_b_st.site = &c2_xj_emlrtRSI;
    c2_minA = c2_minimum(chartInstance, &c2_b_st, chartInstance->c2_varargin_1);
    c2_b_st.site = &c2_yj_emlrtRSI;
    c2_maxA = c2_maximum(chartInstance, &c2_b_st, chartInstance->c2_c_A);
  }

  if (c2_emptyp) {
    c2_st.site = &c2_db_emlrtRSI;
    c2_b_warning(chartInstance, &c2_st);
    c2_b_minA = c2_minA;
    c2_j_x = c2_b_minA;
    c2_f_b = muSingleScalarIsNaN(c2_j_x);
    if (c2_f_b) {
      c2_b_minA = 1.0F;
    }

    c2_threshout = c2_b_minA;
    c2_thresh = c2_threshout;
  } else {
    for (c2_i4 = 0; c2_i4 < 256; c2_i4++) {
      c2_omega[c2_i4] = c2_mu[c2_i4];
    }

    for (c2_b_k = 0; c2_b_k < 255; c2_b_k++) {
      c2_c_k = c2_b_k;
      c2_omega[c2_c_k + 1] += c2_omega[c2_c_k];
    }

    for (c2_i6 = 0; c2_i6 < 256; c2_i6++) {
      c2_mu[c2_i6] *= 1.0 + (real_T)c2_i6;
    }

    for (c2_d_k = 0; c2_d_k < 255; c2_d_k++) {
      c2_e_k = c2_d_k;
      c2_mu[c2_e_k + 1] += c2_mu[c2_e_k];
    }

    c2_mu_t = c2_mu[255];
    c2_b_mu_t = c2_mu_t;
    c2_e_a = c2_b_mu_t;
    for (c2_i8 = 0; c2_i8 < 256; c2_i8++) {
      c2_d_y[c2_i8] = c2_e_a * c2_omega[c2_i8];
    }

    for (c2_i9 = 0; c2_i9 < 256; c2_i9++) {
      c2_d_y[c2_i9] -= c2_mu[c2_i9];
    }

    for (c2_f_k = 0; c2_f_k < 256; c2_f_k++) {
      c2_g_k = c2_f_k;
      c2_f_a = c2_d_y[c2_g_k];
      c2_e_y = c2_f_a * c2_f_a;
      c2_counts[c2_g_k] = c2_e_y;
    }

    for (c2_i10 = 0; c2_i10 < 256; c2_i10++) {
      c2_counts[c2_i10] /= c2_omega[c2_i10] * (1.0 - c2_omega[c2_i10]);
    }

    for (c2_i12 = 0; c2_i12 < 256; c2_i12++) {
      c2_b_counts[c2_i12] = c2_counts[c2_i12];
    }

    c2_maxval = c2_b_maximum(chartInstance, c2_b_counts);
    c2_o_x = c2_maxval;
    c2_p_x = c2_o_x;
    c2_l_b = muDoubleScalarIsInf(c2_p_x);
    c2_b6 = !c2_l_b;
    c2_q_x = c2_o_x;
    c2_m_b = muDoubleScalarIsNaN(c2_q_x);
    c2_b7 = !c2_m_b;
    c2_isvalid_maxval = (c2_b6 && c2_b7);
    c2_emxInit_real32_T(chartInstance, c2_sp, &c2_b_threshout, 2,
                        &c2_tc_emlrtRTEI);
    c2_emxInit_real_T(chartInstance, c2_sp, &c2_threshRaw, 2, &c2_xb_emlrtRTEI);
    c2_emxInit_real32_T(chartInstance, c2_sp, &c2_uniqueVals, 2,
                        &c2_uc_emlrtRTEI);
    c2_emxInit_boolean_T(chartInstance, c2_sp, &c2_r1, 2, &c2_xc_emlrtRTEI);
    c2_emxInit_boolean_T(chartInstance, c2_sp, &c2_r2, 2, &c2_xc_emlrtRTEI);
    c2_emxInit_real32_T(chartInstance, c2_sp, &c2_threshL, 2, &c2_pc_emlrtRTEI);
    c2_emxInit_real_T(chartInstance, c2_sp, &c2_uniqueVals_d, 2,
                      &c2_oc_emlrtRTEI);
    c2_emxInit_real_T1(chartInstance, c2_sp, &c2_r3, 1, &c2_sc_emlrtRTEI);
    if (c2_isvalid_maxval) {
      c2_idxSum = 0.0;
      c2_idxNum = 0.0;
      for (c2_ind = 0; c2_ind < 256; c2_ind++) {
        c2_b_ind = (real_T)c2_ind + 1.0;
        if (c2_counts[(int32_T)c2_b_ind - 1] == c2_maxval) {
          c2_idxSum += c2_b_ind;
          c2_idxNum++;
        }
      }

      c2_i17 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_threshRaw->size[1] = 1;
      c2_st.site = &c2_pi_emlrtRSI;
      c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_threshRaw, c2_i17,
        &c2_xb_emlrtRTEI);
      c2_threshRaw->data[0] = c2_idxSum / c2_idxNum - 1.0;
    } else {
      c2_st.site = &c2_eb_emlrtRSI;
      c2_b_st.site = &c2_mc_emlrtRSI;
      for (c2_i16 = 0; c2_i16 < 307200; c2_i16++) {
        chartInstance->c2_varargin_1[c2_i16] = c2_f_varargin_1[c2_i16];
      }

      c2_c_st.site = &c2_oc_emlrtRSI;
      c2_unique_vector(chartInstance, &c2_c_st, chartInstance->c2_varargin_1,
                       c2_img);
      c2_i18 = c2_uniqueVals->size[0] * c2_uniqueVals->size[1];
      c2_uniqueVals->size[0] = 1;
      c2_uniqueVals->size[1] = c2_img->size[0];
      c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_uniqueVals, c2_i18,
        &c2_yb_emlrtRTEI);
      c2_b_loop_ub = c2_img->size[0] - 1;
      for (c2_i21 = 0; c2_i21 <= c2_b_loop_ub; c2_i21++) {
        c2_uniqueVals->data[c2_i21] = c2_img->data[c2_i21];
      }

      c2_i22 = c2_r1->size[0] * c2_r1->size[1];
      c2_r1->size[0] = 1;
      c2_r1->size[1] = c2_uniqueVals->size[1];
      c2_emxEnsureCapacity_boolean_T(chartInstance, &c2_st, c2_r1, c2_i22,
        &c2_ac_emlrtRTEI);
      c2_c_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
      for (c2_i26 = 0; c2_i26 <= c2_c_loop_ub; c2_i26++) {
        c2_r1->data[c2_i26] = muSingleScalarIsInf(c2_uniqueVals->data[c2_i26]);
      }

      c2_i29 = c2_r2->size[0] * c2_r2->size[1];
      c2_r2->size[0] = 1;
      c2_r2->size[1] = c2_uniqueVals->size[1];
      c2_emxEnsureCapacity_boolean_T(chartInstance, &c2_st, c2_r2, c2_i29,
        &c2_cc_emlrtRTEI);
      c2_f_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
      for (c2_i34 = 0; c2_i34 <= c2_f_loop_ub; c2_i34++) {
        c2_r2->data[c2_i34] = muSingleScalarIsNaN(c2_uniqueVals->data[c2_i34]);
      }

      c2_emxInit_boolean_T(chartInstance, &c2_st, &c2_r4, 2, &c2_ac_emlrtRTEI);
      for (c2_i37 = 0; c2_i37 < 2; c2_i37++) {
        c2_iv[c2_i37] = (*(int32_T (*)[2])c2_r1->size)[c2_i37];
      }

      for (c2_i39 = 0; c2_i39 < 2; c2_i39++) {
        c2_iv1[c2_i39] = (*(int32_T (*)[2])c2_r2->size)[c2_i39];
      }

      emlrtSizeEqCheckNDR2012b(&c2_iv[0], &c2_iv1[0], &c2_emlrtECI, &c2_st);
      c2_i44 = c2_r4->size[0] * c2_r4->size[1];
      c2_r4->size[0] = 1;
      c2_r4->size[1] = c2_r1->size[1];
      c2_emxEnsureCapacity_boolean_T(chartInstance, &c2_st, c2_r4, c2_i44,
        &c2_ac_emlrtRTEI);
      c2_k_loop_ub = c2_r1->size[0] * c2_r1->size[1] - 1;
      for (c2_i48 = 0; c2_i48 <= c2_k_loop_ub; c2_i48++) {
        c2_r4->data[c2_i48] = (c2_r1->data[c2_i48] || c2_r2->data[c2_i48]);
      }

      c2_b_st.site = &c2_nc_emlrtRSI;
      c2_b_nullAssignment(chartInstance, &c2_b_st, c2_uniqueVals, c2_r4);
      c2_isDegenerate = ((real_T)c2_uniqueVals->size[1] <= 1.0);
      c2_emxFree_boolean_T(chartInstance, &c2_r4);
      if (c2_isDegenerate) {
        c2_st.site = &c2_fb_emlrtRSI;
        c2_b_warning(chartInstance, &c2_st);
      } else {
        c2_st.site = &c2_gb_emlrtRSI;
        c2_c_warning(chartInstance, &c2_st);
      }

      c2_st.site = &c2_hb_emlrtRSI;
      c2_b8 = (c2_uniqueVals->size[1] == 0);
      if (c2_b8) {
        c2_i55 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
        c2_b_threshout->size[0] = 1;
        c2_b_threshout->size[1] = 1;
        c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_b_threshout,
          c2_i55, &c2_gc_emlrtRTEI);
        c2_b_threshout->data[0] = 1.0F;
      } else {
        c2_thNeeded1 = 1.0 - (real_T)c2_uniqueVals->size[1];
        if (c2_thNeeded1 > 0.0) {
          c2_i57 = c2_uniqueVals->size[1];
          c2_i58 = 1;
          if ((c2_i58 < 1) || (c2_i58 > c2_i57)) {
            emlrtDynamicBoundsCheckR2012b(c2_i58, 1, c2_i57, &c2_cc_emlrtBCI,
              &c2_st);
          }

          if (c2_uniqueVals->data[0] > 1.0F) {
            c2_i64 = c2_uniqueVals->size[1];
            c2_i65 = 1;
            if ((c2_i65 < 1) || (c2_i65 > c2_i64)) {
              emlrtDynamicBoundsCheckR2012b(c2_i65, 1, c2_i64, &c2_bc_emlrtBCI,
                &c2_st);
            }

            c2_r_x = c2_uniqueVals->data[0];
            c2_s_x = c2_r_x;
            c2_s_x = muSingleScalarCeil(c2_s_x);
            c2_b_varargin_2 = c2_s_x - 1.0F;
            c2_f_y = c2_b_varargin_2;
            c2_g_y = c2_f_y;
            c2_h_y = c2_g_y;
            c2_o_b = c2_h_y;
            c2_i_y = c2_o_b;
            c2_j_y = c2_i_y;
            c2_minval = muSingleScalarMin(1.0F, c2_j_y);
            c2_b_d = c2_minval;
            c2_q_b = c2_b_d;
            c2_v_x = c2_q_b;
            c2_r_b = muSingleScalarIsNaN(c2_v_x);
            if (c2_r_b) {
              c2_y_size[1] = 1;
              c2_y_data[0] = rtNaNF;
            } else if (c2_q_b < 1.0F) {
              c2_y_size[1] = 0;
            } else {
              c2_y_size[1] = 1;
              c2_y_data[0] = 1.0F;
            }

            c2_i94 = c2_threshL->size[0] * c2_threshL->size[1];
            c2_threshL->size[0] = 1;
            c2_threshL->size[1] = c2_y_size[1] + c2_uniqueVals->size[1];
            c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_threshL,
              c2_i94, &c2_pc_emlrtRTEI);
            c2_bb_loop_ub = c2_y_size[1] - 1;
            for (c2_i102 = 0; c2_i102 <= c2_bb_loop_ub; c2_i102++) {
              c2_threshL->data[c2_i102] = c2_y_data[c2_i102];
            }

            c2_cb_loop_ub = c2_uniqueVals->size[1] - 1;
            for (c2_i105 = 0; c2_i105 <= c2_cb_loop_ub; c2_i105++) {
              c2_threshL->data[c2_i105 + c2_y_size[1]] = c2_uniqueVals->
                data[c2_i105];
            }
          } else {
            c2_i63 = c2_threshL->size[0] * c2_threshL->size[1];
            c2_threshL->size[0] = 1;
            c2_threshL->size[1] = c2_uniqueVals->size[1];
            c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_threshL,
              c2_i63, &c2_ic_emlrtRTEI);
            c2_o_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
            for (c2_i69 = 0; c2_i69 <= c2_o_loop_ub; c2_i69++) {
              c2_threshL->data[c2_i69] = c2_uniqueVals->data[c2_i69];
            }
          }

          c2_thNeeded2 = 1.0 - (real_T)c2_threshL->size[1];
          if (c2_thNeeded2 > 0.0) {
            c2_lenThreshOrig = (real_T)c2_threshL->size[1];
            c2_i77 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
            c2_b_threshout->size[0] = 1;
            c2_b_threshout->size[1] = c2_threshL->size[1] + 1;
            c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_b_threshout,
              c2_i77, &c2_mc_emlrtRTEI);
            c2_t_loop_ub = c2_threshL->size[1] - 1;
            for (c2_i85 = 0; c2_i85 <= c2_t_loop_ub; c2_i85++) {
              c2_b_threshout->data[c2_i85] = c2_threshL->data[c2_i85];
            }

            c2_b_threshout->data[c2_threshL->size[1]] = 0.0F;
            c2_i89 = c2_uniqueVals_d->size[0] * c2_uniqueVals_d->size[1];
            c2_uniqueVals_d->size[0] = 1;
            c2_uniqueVals_d->size[1] = c2_uniqueVals->size[1];
            c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_uniqueVals_d,
              c2_i89, &c2_oc_emlrtRTEI);
            c2_w_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
            for (c2_i95 = 0; c2_i95 <= c2_w_loop_ub; c2_i95++) {
              c2_uniqueVals_d->data[c2_i95] = c2_uniqueVals->data[c2_i95];
            }

            c2_i97 = c2_uniqueVals->size[1];
            c2_i100 = 1;
            if ((c2_i100 < 1) || (c2_i100 > c2_i97)) {
              emlrtDynamicBoundsCheckR2012b(c2_i100, 1, c2_i97, &c2_ac_emlrtBCI,
                &c2_st);
            }

            c2_x_x = c2_uniqueVals->data[0];
            c2_g_varargin_1 = c2_x_x;
            c2_g_varargin_1 = muSingleScalarFloor(c2_g_varargin_1);
            c2_y_x = c2_g_varargin_1;
            c2_ab_x = c2_y_x;
            c2_bb_x = c2_ab_x;
            c2_g_a = c2_bb_x;
            c2_cb_x = c2_g_a;
            c2_db_x = c2_cb_x;
            c2_threshCandidate = muSingleScalarMax(c2_db_x, 0.0F);
            c2_q = 1.0;
            c2_emxInit_real_T1(chartInstance, &c2_st, &c2_b_uniqueVals_d, 1,
                               &c2_rc_emlrtRTEI);
            c2_emxInit_boolean_T1(chartInstance, &c2_st, &c2_r6, 1,
                                  &c2_sc_emlrtRTEI);
            while (c2_q <= 1.0) {
              c2_threshCandidate++;
              c2_threshCandidate_d = c2_threshCandidate;
              c2_c_uniqueVals_d[0] = c2_uniqueVals_d->size[1];
              c2_i113 = c2_b_uniqueVals_d->size[0];
              c2_b_uniqueVals_d->size[0] = c2_c_uniqueVals_d[0];
              c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st,
                c2_b_uniqueVals_d, c2_i113, &c2_rc_emlrtRTEI);
              c2_hb_loop_ub = c2_c_uniqueVals_d[0] - 1;
              for (c2_i114 = 0; c2_i114 <= c2_hb_loop_ub; c2_i114++) {
                c2_b_uniqueVals_d->data[c2_i114] = c2_uniqueVals_d->data[c2_i114]
                  - c2_threshCandidate_d;
              }

              c2_b_st.site = &c2_ed_emlrtRSI;
              c2_abs(chartInstance, &c2_b_st, c2_b_uniqueVals_d, c2_r3);
              c2_b_st.site = &c2_fd_emlrtRSI;
              c2_d1 = c2_eps(chartInstance, c2_threshCandidate_d);
              c2_i115 = c2_r6->size[0];
              c2_r6->size[0] = c2_r3->size[0];
              c2_emxEnsureCapacity_boolean_T1(chartInstance, &c2_st, c2_r6,
                c2_i115, &c2_sc_emlrtRTEI);
              c2_ib_loop_ub = c2_r3->size[0] - 1;
              for (c2_i117 = 0; c2_i117 <= c2_ib_loop_ub; c2_i117++) {
                c2_r6->data[c2_i117] = (c2_r3->data[c2_i117] < c2_d1);
              }

              c2_b_st.site = &c2_ed_emlrtRSI;
              if (!c2_any(chartInstance, &c2_b_st, c2_r6)) {
                c2_i119 = c2_b_threshout->size[1];
                c2_i120 = (int32_T)(c2_lenThreshOrig + 1.0);
                if ((c2_i120 < 1) || (c2_i120 > c2_i119)) {
                  emlrtDynamicBoundsCheckR2012b(c2_i120, 1, c2_i119,
                    &c2_ec_emlrtBCI, &c2_st);
                }

                c2_b_threshout->data[c2_i120 - 1] = c2_threshCandidate;
                c2_q = 2.0;
              }
            }

            c2_emxFree_boolean_T(chartInstance, &c2_r6);
            c2_emxFree_real_T(chartInstance, &c2_b_uniqueVals_d);
            c2_b_st.site = &c2_gd_emlrtRSI;
            c2_c_st.site = &c2_ld_emlrtRSI;
            c2_c_sort(chartInstance, &c2_c_st, c2_b_threshout);
          } else {
            c2_i76 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
            c2_b_threshout->size[0] = 1;
            c2_b_threshout->size[1] = c2_threshL->size[1];
            c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_b_threshout,
              c2_i76, &c2_lc_emlrtRTEI);
            c2_s_loop_ub = c2_threshL->size[0] * c2_threshL->size[1] - 1;
            for (c2_i84 = 0; c2_i84 <= c2_s_loop_ub; c2_i84++) {
              c2_b_threshout->data[c2_i84] = c2_threshL->data[c2_i84];
            }
          }
        } else {
          c2_i56 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
          c2_b_threshout->size[0] = 1;
          c2_b_threshout->size[1] = c2_uniqueVals->size[1];
          c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_b_threshout,
            c2_i56, &c2_hc_emlrtRTEI);
          c2_n_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
          for (c2_i62 = 0; c2_i62 <= c2_n_loop_ub; c2_i62++) {
            c2_b_threshout->data[c2_i62] = c2_uniqueVals->data[c2_i62];
          }
        }
      }

      c2_i61 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_threshRaw->size[1] = c2_b_threshout->size[1];
      c2_st.site = &c2_oi_emlrtRSI;
      c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_threshRaw, c2_i61,
        &c2_jc_emlrtRTEI);
      c2_p_loop_ub = c2_b_threshout->size[0] * c2_b_threshout->size[1] - 1;
      for (c2_i70 = 0; c2_i70 <= c2_p_loop_ub; c2_i70++) {
        c2_threshRaw->data[c2_i70] = c2_b_threshout->data[c2_i70];
      }
    }

    if (c2_isvalid_maxval) {
      c2_c_minA = c2_minA;
      c2_b_maxA = c2_maxA;
      c2_i24 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_i25 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_threshRaw, c2_i25,
        &c2_bc_emlrtRTEI);
      c2_i28 = c2_i24;
      c2_d_loop_ub = c2_i28 - 1;
      for (c2_i30 = 0; c2_i30 <= c2_d_loop_ub; c2_i30++) {
        c2_threshRaw->data[c2_i30] /= 255.0;
      }

      c2_n_b = (real_T)c2_b_maxA - (real_T)c2_c_minA;
      c2_i32 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_i33 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_threshRaw, c2_i33,
        &c2_dc_emlrtRTEI);
      c2_i36 = c2_i32;
      c2_g_loop_ub = c2_i36 - 1;
      for (c2_i38 = 0; c2_i38 <= c2_g_loop_ub; c2_i38++) {
        c2_threshRaw->data[c2_i38] *= c2_n_b;
      }

      c2_i41 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_i43 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_threshRaw, c2_i43,
        &c2_ec_emlrtRTEI);
      c2_i45 = c2_i41;
      c2_j_loop_ub = c2_i45 - 1;
      for (c2_i47 = 0; c2_i47 <= c2_j_loop_ub; c2_i47++) {
        c2_threshRaw->data[c2_i47] += (real_T)c2_c_minA;
      }

      c2_i49 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
      c2_b_threshout->size[0] = 1;
      c2_b_threshout->size[1] = c2_threshRaw->size[1];
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_sp, c2_b_threshout, c2_i49,
        &c2_fc_emlrtRTEI);
      c2_l_loop_ub = c2_threshRaw->size[0] * c2_threshRaw->size[1] - 1;
      for (c2_i52 = 0; c2_i52 <= c2_l_loop_ub; c2_i52++) {
        c2_b_threshout->data[c2_i52] = (real32_T)c2_threshRaw->data[c2_i52];
      }
    } else {
      c2_st.site = &c2_ib_emlrtRSI;
      c2_b_st.site = &c2_mc_emlrtRSI;
      for (c2_i23 = 0; c2_i23 < 307200; c2_i23++) {
        chartInstance->c2_varargin_1[c2_i23] = c2_f_varargin_1[c2_i23];
      }

      c2_c_st.site = &c2_oc_emlrtRSI;
      c2_unique_vector(chartInstance, &c2_c_st, chartInstance->c2_varargin_1,
                       c2_img);
      c2_i27 = c2_uniqueVals->size[0] * c2_uniqueVals->size[1];
      c2_uniqueVals->size[0] = 1;
      c2_uniqueVals->size[1] = c2_img->size[0];
      c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_uniqueVals, c2_i27,
        &c2_yb_emlrtRTEI);
      c2_e_loop_ub = c2_img->size[0] - 1;
      for (c2_i31 = 0; c2_i31 <= c2_e_loop_ub; c2_i31++) {
        c2_uniqueVals->data[c2_i31] = c2_img->data[c2_i31];
      }

      c2_i35 = c2_r1->size[0] * c2_r1->size[1];
      c2_r1->size[0] = 1;
      c2_r1->size[1] = c2_uniqueVals->size[1];
      c2_emxEnsureCapacity_boolean_T(chartInstance, &c2_st, c2_r1, c2_i35,
        &c2_ac_emlrtRTEI);
      c2_h_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
      for (c2_i40 = 0; c2_i40 <= c2_h_loop_ub; c2_i40++) {
        c2_r1->data[c2_i40] = muSingleScalarIsInf(c2_uniqueVals->data[c2_i40]);
      }

      c2_i42 = c2_r2->size[0] * c2_r2->size[1];
      c2_r2->size[0] = 1;
      c2_r2->size[1] = c2_uniqueVals->size[1];
      c2_emxEnsureCapacity_boolean_T(chartInstance, &c2_st, c2_r2, c2_i42,
        &c2_cc_emlrtRTEI);
      c2_i_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
      for (c2_i46 = 0; c2_i46 <= c2_i_loop_ub; c2_i46++) {
        c2_r2->data[c2_i46] = muSingleScalarIsNaN(c2_uniqueVals->data[c2_i46]);
      }

      c2_emxInit_boolean_T(chartInstance, &c2_st, &c2_r5, 2, &c2_ac_emlrtRTEI);
      for (c2_i50 = 0; c2_i50 < 2; c2_i50++) {
        c2_iv2[c2_i50] = (*(int32_T (*)[2])c2_r1->size)[c2_i50];
      }

      for (c2_i51 = 0; c2_i51 < 2; c2_i51++) {
        c2_iv3[c2_i51] = (*(int32_T (*)[2])c2_r2->size)[c2_i51];
      }

      emlrtSizeEqCheckNDR2012b(&c2_iv2[0], &c2_iv3[0], &c2_emlrtECI, &c2_st);
      c2_i53 = c2_r5->size[0] * c2_r5->size[1];
      c2_r5->size[0] = 1;
      c2_r5->size[1] = c2_r1->size[1];
      c2_emxEnsureCapacity_boolean_T(chartInstance, &c2_st, c2_r5, c2_i53,
        &c2_ac_emlrtRTEI);
      c2_m_loop_ub = c2_r1->size[0] * c2_r1->size[1] - 1;
      for (c2_i54 = 0; c2_i54 <= c2_m_loop_ub; c2_i54++) {
        c2_r5->data[c2_i54] = (c2_r1->data[c2_i54] || c2_r2->data[c2_i54]);
      }

      c2_b_st.site = &c2_nc_emlrtRSI;
      c2_b_nullAssignment(chartInstance, &c2_b_st, c2_uniqueVals, c2_r5);
      c2_b_isDegenerate = ((real_T)c2_uniqueVals->size[1] <= 1.0);
      c2_emxFree_boolean_T(chartInstance, &c2_r5);
      if (c2_b_isDegenerate) {
        c2_st.site = &c2_jb_emlrtRSI;
        c2_b_warning(chartInstance, &c2_st);
        c2_st.site = &c2_kb_emlrtRSI;
        c2_b9 = (c2_uniqueVals->size[1] == 0);
        if (c2_b9) {
          c2_i68 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
          c2_b_threshout->size[0] = 1;
          c2_b_threshout->size[1] = 1;
          c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_b_threshout,
            c2_i68, &c2_kc_emlrtRTEI);
          c2_b_threshout->data[0] = 1.0F;
        } else {
          c2_b_thNeeded1 = 1.0 - (real_T)c2_uniqueVals->size[1];
          if (c2_b_thNeeded1 > 0.0) {
            c2_i72 = c2_uniqueVals->size[1];
            c2_i74 = 1;
            if ((c2_i74 < 1) || (c2_i74 > c2_i72)) {
              emlrtDynamicBoundsCheckR2012b(c2_i74, 1, c2_i72, &c2_cc_emlrtBCI,
                &c2_st);
            }

            if (c2_uniqueVals->data[0] > 1.0F) {
              c2_i80 = c2_uniqueVals->size[1];
              c2_i82 = 1;
              if ((c2_i82 < 1) || (c2_i82 > c2_i80)) {
                emlrtDynamicBoundsCheckR2012b(c2_i82, 1, c2_i80, &c2_bc_emlrtBCI,
                  &c2_st);
              }

              c2_t_x = c2_uniqueVals->data[0];
              c2_u_x = c2_t_x;
              c2_u_x = muSingleScalarCeil(c2_u_x);
              c2_c_varargin_2 = c2_u_x - 1.0F;
              c2_k_y = c2_c_varargin_2;
              c2_l_y = c2_k_y;
              c2_m_y = c2_l_y;
              c2_s_b = c2_m_y;
              c2_n_y = c2_s_b;
              c2_o_y = c2_n_y;
              c2_b_minval = muSingleScalarMin(1.0F, c2_o_y);
              c2_c_d = c2_b_minval;
              c2_t_b = c2_c_d;
              c2_w_x = c2_t_b;
              c2_u_b = muSingleScalarIsNaN(c2_w_x);
              if (c2_u_b) {
                c2_y_size[1] = 1;
                c2_y_data[0] = rtNaNF;
              } else if (c2_t_b < 1.0F) {
                c2_y_size[1] = 0;
              } else {
                c2_y_size[1] = 1;
                c2_y_data[0] = 1.0F;
              }

              c2_i107 = c2_threshL->size[0] * c2_threshL->size[1];
              c2_threshL->size[0] = 1;
              c2_threshL->size[1] = c2_y_size[1] + c2_uniqueVals->size[1];
              c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_threshL,
                c2_i107, &c2_pc_emlrtRTEI);
              c2_fb_loop_ub = c2_y_size[1] - 1;
              for (c2_i111 = 0; c2_i111 <= c2_fb_loop_ub; c2_i111++) {
                c2_threshL->data[c2_i111] = c2_y_data[c2_i111];
              }

              c2_gb_loop_ub = c2_uniqueVals->size[1] - 1;
              for (c2_i112 = 0; c2_i112 <= c2_gb_loop_ub; c2_i112++) {
                c2_threshL->data[c2_i112 + c2_y_size[1]] = c2_uniqueVals->
                  data[c2_i112];
              }
            } else {
              c2_i79 = c2_threshL->size[0] * c2_threshL->size[1];
              c2_threshL->size[0] = 1;
              c2_threshL->size[1] = c2_uniqueVals->size[1];
              c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_threshL,
                c2_i79, &c2_ic_emlrtRTEI);
              c2_u_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
              for (c2_i87 = 0; c2_i87 <= c2_u_loop_ub; c2_i87++) {
                c2_threshL->data[c2_i87] = c2_uniqueVals->data[c2_i87];
              }
            }

            c2_b_thNeeded2 = 1.0 - (real_T)c2_threshL->size[1];
            if (c2_b_thNeeded2 > 0.0) {
              c2_b_lenThreshOrig = (real_T)c2_threshL->size[1];
              c2_i93 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
              c2_b_threshout->size[0] = 1;
              c2_b_threshout->size[1] = c2_threshL->size[1] + 1;
              c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st,
                c2_b_threshout, c2_i93, &c2_kc_emlrtRTEI);
              c2_ab_loop_ub = c2_threshL->size[1] - 1;
              for (c2_i101 = 0; c2_i101 <= c2_ab_loop_ub; c2_i101++) {
                c2_b_threshout->data[c2_i101] = c2_threshL->data[c2_i101];
              }

              c2_b_threshout->data[c2_threshL->size[1]] = 0.0F;
              c2_i104 = c2_uniqueVals_d->size[0] * c2_uniqueVals_d->size[1];
              c2_uniqueVals_d->size[0] = 1;
              c2_uniqueVals_d->size[1] = c2_uniqueVals->size[1];
              c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_uniqueVals_d,
                c2_i104, &c2_oc_emlrtRTEI);
              c2_eb_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] -
                1;
              for (c2_i108 = 0; c2_i108 <= c2_eb_loop_ub; c2_i108++) {
                c2_uniqueVals_d->data[c2_i108] = c2_uniqueVals->data[c2_i108];
              }

              c2_i109 = c2_uniqueVals->size[1];
              c2_i110 = 1;
              if ((c2_i110 < 1) || (c2_i110 > c2_i109)) {
                emlrtDynamicBoundsCheckR2012b(c2_i110, 1, c2_i109,
                  &c2_ac_emlrtBCI, &c2_st);
              }

              c2_eb_x = c2_uniqueVals->data[0];
              c2_h_varargin_1 = c2_eb_x;
              c2_h_varargin_1 = muSingleScalarFloor(c2_h_varargin_1);
              c2_fb_x = c2_h_varargin_1;
              c2_gb_x = c2_fb_x;
              c2_hb_x = c2_gb_x;
              c2_h_a = c2_hb_x;
              c2_ib_x = c2_h_a;
              c2_jb_x = c2_ib_x;
              c2_b_threshCandidate = muSingleScalarMax(c2_jb_x, 0.0F);
              c2_b_q = 1.0;
              c2_emxInit_real_T1(chartInstance, &c2_st, &c2_d_uniqueVals_d, 1,
                                 &c2_rc_emlrtRTEI);
              c2_emxInit_boolean_T1(chartInstance, &c2_st, &c2_r7, 1,
                                    &c2_sc_emlrtRTEI);
              while (c2_b_q <= 1.0) {
                c2_b_threshCandidate++;
                c2_b_threshCandidate_d = c2_b_threshCandidate;
                c2_e_uniqueVals_d[0] = c2_uniqueVals_d->size[1];
                c2_i116 = c2_d_uniqueVals_d->size[0];
                c2_d_uniqueVals_d->size[0] = c2_e_uniqueVals_d[0];
                c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st,
                  c2_d_uniqueVals_d, c2_i116, &c2_rc_emlrtRTEI);
                c2_jb_loop_ub = c2_e_uniqueVals_d[0] - 1;
                for (c2_i118 = 0; c2_i118 <= c2_jb_loop_ub; c2_i118++) {
                  c2_d_uniqueVals_d->data[c2_i118] = c2_uniqueVals_d->
                    data[c2_i118] - c2_b_threshCandidate_d;
                }

                c2_b_st.site = &c2_ed_emlrtRSI;
                c2_abs(chartInstance, &c2_b_st, c2_d_uniqueVals_d, c2_r3);
                c2_b_st.site = &c2_fd_emlrtRSI;
                c2_d2 = c2_eps(chartInstance, c2_b_threshCandidate_d);
                c2_i121 = c2_r7->size[0];
                c2_r7->size[0] = c2_r3->size[0];
                c2_emxEnsureCapacity_boolean_T1(chartInstance, &c2_st, c2_r7,
                  c2_i121, &c2_sc_emlrtRTEI);
                c2_kb_loop_ub = c2_r3->size[0] - 1;
                for (c2_i122 = 0; c2_i122 <= c2_kb_loop_ub; c2_i122++) {
                  c2_r7->data[c2_i122] = (c2_r3->data[c2_i122] < c2_d2);
                }

                c2_b_st.site = &c2_ed_emlrtRSI;
                if (!c2_any(chartInstance, &c2_b_st, c2_r7)) {
                  c2_i123 = c2_b_threshout->size[1];
                  c2_i124 = (int32_T)(c2_b_lenThreshOrig + 1.0);
                  if ((c2_i124 < 1) || (c2_i124 > c2_i123)) {
                    emlrtDynamicBoundsCheckR2012b(c2_i124, 1, c2_i123,
                      &c2_ec_emlrtBCI, &c2_st);
                  }

                  c2_b_threshout->data[c2_i124 - 1] = c2_b_threshCandidate;
                  c2_b_q = 2.0;
                }
              }

              c2_emxFree_boolean_T(chartInstance, &c2_r7);
              c2_emxFree_real_T(chartInstance, &c2_d_uniqueVals_d);
              c2_b_st.site = &c2_gd_emlrtRSI;
              c2_c_st.site = &c2_ld_emlrtRSI;
              c2_c_sort(chartInstance, &c2_c_st, c2_b_threshout);
            } else {
              c2_i92 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
              c2_b_threshout->size[0] = 1;
              c2_b_threshout->size[1] = c2_threshL->size[1];
              c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st,
                c2_b_threshout, c2_i92, &c2_kc_emlrtRTEI);
              c2_y_loop_ub = c2_threshL->size[0] * c2_threshL->size[1] - 1;
              for (c2_i99 = 0; c2_i99 <= c2_y_loop_ub; c2_i99++) {
                c2_b_threshout->data[c2_i99] = c2_threshL->data[c2_i99];
              }
            }
          } else {
            c2_i71 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
            c2_b_threshout->size[0] = 1;
            c2_b_threshout->size[1] = c2_uniqueVals->size[1];
            c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_b_threshout,
              c2_i71, &c2_kc_emlrtRTEI);
            c2_r_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
            for (c2_i78 = 0; c2_i78 <= c2_r_loop_ub; c2_i78++) {
              c2_b_threshout->data[c2_i78] = c2_uniqueVals->data[c2_i78];
            }
          }
        }
      } else {
        c2_st.site = &c2_lb_emlrtRSI;
        c2_c_warning(chartInstance, &c2_st);
        c2_d_minA = c2_minA;
        c2_c_maxA = c2_maxA;
        c2_i66 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_i67 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_threshRaw->size[0] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_threshRaw, c2_i67,
          &c2_bc_emlrtRTEI);
        c2_i73 = c2_i66;
        c2_q_loop_ub = c2_i73 - 1;
        for (c2_i75 = 0; c2_i75 <= c2_q_loop_ub; c2_i75++) {
          c2_threshRaw->data[c2_i75] /= 255.0;
        }

        c2_p_b = (real_T)c2_c_maxA - (real_T)c2_d_minA;
        c2_i81 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_i83 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_threshRaw->size[0] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_threshRaw, c2_i83,
          &c2_dc_emlrtRTEI);
        c2_i86 = c2_i81;
        c2_v_loop_ub = c2_i86 - 1;
        for (c2_i88 = 0; c2_i88 <= c2_v_loop_ub; c2_i88++) {
          c2_threshRaw->data[c2_i88] *= c2_p_b;
        }

        c2_i90 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_i91 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_threshRaw->size[0] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_threshRaw, c2_i91,
          &c2_ec_emlrtRTEI);
        c2_i96 = c2_i90;
        c2_x_loop_ub = c2_i96 - 1;
        for (c2_i98 = 0; c2_i98 <= c2_x_loop_ub; c2_i98++) {
          c2_threshRaw->data[c2_i98] += (real_T)c2_d_minA;
        }

        c2_i103 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
        c2_b_threshout->size[0] = 1;
        c2_b_threshout->size[1] = c2_threshRaw->size[1];
        c2_emxEnsureCapacity_real32_T(chartInstance, c2_sp, c2_b_threshout,
          c2_i103, &c2_qc_emlrtRTEI);
        c2_db_loop_ub = c2_threshRaw->size[0] * c2_threshRaw->size[1] - 1;
        for (c2_i106 = 0; c2_i106 <= c2_db_loop_ub; c2_i106++) {
          c2_b_threshout->data[c2_i106] = (real32_T)c2_threshRaw->data[c2_i106];
        }
      }
    }

    c2_emxFree_real_T(chartInstance, &c2_r3);
    c2_emxFree_real_T(chartInstance, &c2_uniqueVals_d);
    c2_emxFree_real32_T(chartInstance, &c2_threshL);
    c2_emxFree_boolean_T(chartInstance, &c2_r2);
    c2_emxFree_boolean_T(chartInstance, &c2_r1);
    c2_emxFree_real32_T(chartInstance, &c2_uniqueVals);
    c2_emxFree_real_T(chartInstance, &c2_threshRaw);
    c2_i59 = c2_b_threshout->size[1];
    c2_i60 = 1;
    if ((c2_i60 < 1) || (c2_i60 > c2_i59)) {
      emlrtDynamicBoundsCheckR2012b(c2_i60, 1, c2_i59, &c2_dc_emlrtBCI, (void *)
        c2_sp);
    }

    c2_thresh = c2_b_threshout->data[0];
    c2_emxFree_real32_T(chartInstance, &c2_b_threshout);
  }

  c2_emxFree_real32_T(chartInstance, &c2_img);
  return c2_thresh;
}

static void c2_check_forloop_overflow_error(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp)
{
  static char_T c2_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c2_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  (void)chartInstance;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call(c2_sp, &c2_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14, sf_mex_call
              (c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c2_sp, NULL,
    "message", 1U, 2U, 14, c2_c_y, 14, c2_d_y)));
}

static real32_T c2_minimum(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real32_T c2_e_x[307200])
{
  c2_emxArray_real32_T *c2_f_x;
  int32_T c2_b_idx;
  int32_T c2_b_k;
  int32_T c2_first;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_k;
  real32_T c2_b_ex;
  real32_T c2_ex;
  real32_T c2_g_x;
  real32_T c2_h_x;
  real32_T c2_i_x;
  real32_T c2_j_x;
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  c2_emxInit_real32_T1(chartInstance, c2_sp, &c2_f_x, 1, &c2_yc_emlrtRTEI);
  c2_i = c2_f_x->size[0];
  c2_f_x->size[0] = 307200;
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_sp, c2_f_x, c2_i,
    &c2_yc_emlrtRTEI);
  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    c2_f_x->data[c2_i1] = c2_e_x[c2_i1];
  }

  c2_g_x = c2_f_x->data[0];
  c2_h_x = c2_g_x;
  c2_b = muSingleScalarIsNaN(c2_h_x);
  c2_p = !c2_b;
  if (c2_p) {
    c2_b_idx = 1;
  } else {
    c2_b_idx = 0;
    c2_k = 2;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_k < 307201)) {
      c2_i_x = c2_f_x->data[c2_k - 1];
      c2_j_x = c2_i_x;
      c2_b_b = muSingleScalarIsNaN(c2_j_x);
      c2_b_p = !c2_b_b;
      if (c2_b_p) {
        c2_b_idx = c2_k;
        c2_exitg1 = true;
      } else {
        c2_k++;
      }
    }
  }

  if (c2_b_idx == 0) {
    c2_ex = c2_f_x->data[0];
  } else {
    c2_first = c2_b_idx - 1;
    c2_b_ex = c2_f_x->data[c2_first];
    c2_i2 = c2_first;
    for (c2_b_k = c2_i2 + 1; c2_b_k + 1 < 307201; c2_b_k++) {
      if (c2_b_ex > c2_f_x->data[c2_b_k]) {
        c2_b_ex = c2_f_x->data[c2_b_k];
      }
    }

    c2_ex = c2_b_ex;
  }

  c2_emxFree_real32_T(chartInstance, &c2_f_x);
  return c2_ex;
}

static void c2_imhist(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, c2_emxArray_uint8_T *c2_f_varargin_1,
                      real_T c2_yout[256])
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  real_T c2_localBins1[256];
  real_T c2_localBins2[256];
  real_T c2_localBins3[256];
  real_T c2_b_out;
  real_T c2_d_i;
  int32_T c2_b_c;
  int32_T c2_b_i;
  int32_T c2_b_idx;
  int32_T c2_c;
  int32_T c2_c_c;
  int32_T c2_c_i;
  int32_T c2_d_a;
  int32_T c2_d_c;
  int32_T c2_e_a;
  int32_T c2_e_c;
  int32_T c2_f_a;
  int32_T c2_f_c;
  int32_T c2_g_a;
  int32_T c2_g_c;
  int32_T c2_h_a;
  int32_T c2_h_c;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_a;
  int32_T c2_i_c;
  int32_T c2_idx1;
  int32_T c2_idx2;
  int32_T c2_idx3;
  int32_T c2_idx4;
  int32_T c2_j_a;
  int32_T c2_j_c;
  int32_T c2_k_a;
  int32_T c2_l_a;
  int32_T c2_m_a;
  (void)chartInstance;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_st.site = &c2_sb_emlrtRSI;
  c2_b_st.site = &c2_xb_emlrtRSI;
  c2_b_out = 1.0;
  getnumcores(&c2_b_out);
  c2_b_st.site = &c2_vb_emlrtRSI;
  for (c2_i = 0; c2_i < 256; c2_i++) {
    c2_yout[c2_i] = 0.0;
  }

  for (c2_i1 = 0; c2_i1 < 256; c2_i1++) {
    c2_localBins1[c2_i1] = 0.0;
  }

  for (c2_i2 = 0; c2_i2 < 256; c2_i2++) {
    c2_localBins2[c2_i2] = 0.0;
  }

  for (c2_i3 = 0; c2_i3 < 256; c2_i3++) {
    c2_localBins3[c2_i3] = 0.0;
  }

  for (c2_b_i = 1; c2_b_i + 3 <= c2_f_varargin_1->size[0]; c2_b_i += 4) {
    c2_i4 = c2_f_varargin_1->size[0];
    if ((c2_b_i < 1) || (c2_b_i > c2_i4)) {
      emlrtDynamicBoundsCheckR2012b(c2_b_i, 1, c2_i4, &c2_fc_emlrtBCI, &c2_b_st);
    }

    c2_idx1 = c2_f_varargin_1->data[c2_b_i - 1];
    c2_i6 = c2_f_varargin_1->size[0];
    c2_i7 = c2_b_i + 1;
    if ((c2_i7 < 1) || (c2_i7 > c2_i6)) {
      emlrtDynamicBoundsCheckR2012b(c2_i7, 1, c2_i6, &c2_gc_emlrtBCI, &c2_b_st);
    }

    c2_idx2 = c2_f_varargin_1->data[c2_i7 - 1];
    c2_i8 = c2_f_varargin_1->size[0];
    c2_i9 = c2_b_i + 2;
    if ((c2_i9 < 1) || (c2_i9 > c2_i8)) {
      emlrtDynamicBoundsCheckR2012b(c2_i9, 1, c2_i8, &c2_ic_emlrtBCI, &c2_b_st);
    }

    c2_idx3 = c2_f_varargin_1->data[c2_i9 - 1];
    c2_i10 = c2_f_varargin_1->size[0];
    c2_i11 = c2_b_i + 3;
    if ((c2_i11 < 1) || (c2_i11 > c2_i10)) {
      emlrtDynamicBoundsCheckR2012b(c2_i11, 1, c2_i10, &c2_jc_emlrtBCI, &c2_b_st);
    }

    c2_idx4 = c2_f_varargin_1->data[c2_i11 - 1];
    c2_f_a = c2_idx1 + 1;
    c2_c_c = c2_f_a - 1;
    c2_g_a = c2_idx1 + 1;
    c2_d_c = c2_g_a - 1;
    c2_localBins1[c2_c_c] = c2_localBins1[c2_d_c] + 1.0;
    c2_h_a = c2_idx2 + 1;
    c2_e_c = c2_h_a - 1;
    c2_i_a = c2_idx2 + 1;
    c2_f_c = c2_i_a - 1;
    c2_localBins2[c2_e_c] = c2_localBins2[c2_f_c] + 1.0;
    c2_j_a = c2_idx3 + 1;
    c2_g_c = c2_j_a - 1;
    c2_k_a = c2_idx3 + 1;
    c2_h_c = c2_k_a - 1;
    c2_localBins3[c2_g_c] = c2_localBins3[c2_h_c] + 1.0;
    c2_l_a = c2_idx4 + 1;
    c2_i_c = c2_l_a - 1;
    c2_m_a = c2_idx4 + 1;
    c2_j_c = c2_m_a - 1;
    c2_yout[c2_i_c] = c2_yout[c2_j_c] + 1.0;
  }

  while (c2_b_i <= c2_f_varargin_1->size[0]) {
    c2_i5 = c2_f_varargin_1->size[0];
    if ((c2_b_i < 1) || (c2_b_i > c2_i5)) {
      emlrtDynamicBoundsCheckR2012b(c2_b_i, 1, c2_i5, &c2_hc_emlrtBCI, &c2_b_st);
    }

    c2_b_idx = c2_f_varargin_1->data[c2_b_i - 1];
    c2_d_a = c2_b_idx + 1;
    c2_c = c2_d_a - 1;
    c2_e_a = c2_b_idx + 1;
    c2_b_c = c2_e_a - 1;
    c2_yout[c2_c] = c2_yout[c2_b_c] + 1.0;
    c2_b_i++;
  }

  for (c2_c_i = 0; c2_c_i < 256; c2_c_i++) {
    c2_d_i = (real_T)c2_c_i + 1.0;
    c2_yout[(int32_T)c2_d_i - 1] = ((c2_yout[(int32_T)c2_d_i - 1] +
      c2_localBins1[(int32_T)c2_d_i - 1]) + c2_localBins2[(int32_T)c2_d_i - 1])
      + c2_localBins3[(int32_T)c2_d_i - 1];
  }
}

static real_T c2_sum(SFc2_imagedetectorInstanceStruct *chartInstance, real_T
                     c2_e_x[256])
{
  real_T c2_f_x[256];
  int32_T c2_i;
  for (c2_i = 0; c2_i < 256; c2_i++) {
    c2_f_x[c2_i] = c2_e_x[c2_i];
  }

  return c2_sumColumnB(chartInstance, c2_f_x);
}

static real_T c2_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  real_T c2_e_x[256])
{
  real_T c2_b_y;
  int32_T c2_b_k;
  int32_T c2_k;
  (void)chartInstance;
  c2_b_y = c2_e_x[0];
  for (c2_k = 0; c2_k < 255; c2_k++) {
    c2_b_k = c2_k;
    c2_b_y += c2_e_x[c2_b_k + 1];
  }

  return c2_b_y;
}

static void c2_b_warning(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp)
{
  static char_T c2_msgID[34] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'm', 'u',
    'l', 't', 'i', 't', 'h', 'r', 'e', 's', 'h', ':', 'd', 'e', 'g', 'e', 'n',
    'e', 'r', 'a', 't', 'e', 'I', 'n', 'p', 'u', 't' };

  static char_T c2_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c2_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  real_T c2_u;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_u = 1.0;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  c2_st.site = &c2_c_emlrtRSI;
  c2_d_feval(chartInstance, &c2_st, c2_b_y, c2_c_feval(chartInstance, &c2_st,
              c2_c_y, c2_d_y, c2_e_y));
}

static real_T c2_b_maximum(SFc2_imagedetectorInstanceStruct *chartInstance,
  real_T c2_e_x[256])
{
  real_T c2_x_data[256];
  real_T c2_b_ex;
  real_T c2_ex;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  int32_T c2_b_idx;
  int32_T c2_b_k;
  int32_T c2_first;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_k;
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  (void)chartInstance;
  for (c2_i = 0; c2_i < 256; c2_i++) {
    c2_x_data[c2_i] = c2_e_x[c2_i];
  }

  c2_f_x = c2_x_data[0];
  c2_g_x = c2_f_x;
  c2_b = muDoubleScalarIsNaN(c2_g_x);
  c2_p = !c2_b;
  if (c2_p) {
    c2_b_idx = 1;
  } else {
    c2_b_idx = 0;
    c2_k = 2;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_k < 257)) {
      c2_h_x = c2_x_data[c2_k - 1];
      c2_i_x = c2_h_x;
      c2_b_b = muDoubleScalarIsNaN(c2_i_x);
      c2_b_p = !c2_b_b;
      if (c2_b_p) {
        c2_b_idx = c2_k;
        c2_exitg1 = true;
      } else {
        c2_k++;
      }
    }
  }

  if (c2_b_idx == 0) {
    c2_ex = c2_x_data[0];
  } else {
    c2_first = c2_b_idx - 1;
    c2_b_ex = c2_x_data[c2_first];
    c2_i1 = c2_first;
    for (c2_b_k = c2_i1 + 1; c2_b_k + 1 < 257; c2_b_k++) {
      if (c2_b_ex < c2_x_data[c2_b_k]) {
        c2_b_ex = c2_x_data[c2_b_k];
      }
    }

    c2_ex = c2_b_ex;
  }

  return c2_ex;
}

static void c2_mergesort(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, int32_T c2_b_idx[307200], real32_T c2_e_x[307200], int32_T
  c2_c_idx[307200])
{
  int32_T c2_i;
  int32_T c2_i1;
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    c2_c_idx[c2_i] = c2_b_idx[c2_i];
  }

  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    chartInstance->c2_d_x[c2_i1] = c2_e_x[c2_i1];
  }

  c2_b_mergesort(chartInstance, c2_sp, c2_c_idx, chartInstance->c2_d_x);
}

static void c2_unique_vector(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real32_T c2_d_a[307200], c2_emxArray_real32_T *c2_b)
{
  c2_emxArray_real32_T *c2_b_b;
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_iv[2];
  int32_T c2_b_c;
  int32_T c2_b_exponent;
  int32_T c2_b_j;
  int32_T c2_b_k;
  int32_T c2_c;
  int32_T c2_c_b;
  int32_T c2_c_c;
  int32_T c2_c_k;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_exitg2;
  int32_T c2_exponent;
  int32_T c2_f_a;
  int32_T c2_g_a;
  int32_T c2_g_b;
  int32_T c2_h_a;
  int32_T c2_h_b;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i_a;
  int32_T c2_i_b;
  int32_T c2_j;
  int32_T c2_j_a;
  int32_T c2_j_b;
  int32_T c2_k;
  int32_T c2_k0;
  int32_T c2_k_a;
  int32_T c2_k_b;
  int32_T c2_khi;
  int32_T c2_l_a;
  int32_T c2_l_b;
  int32_T c2_loop_ub;
  int32_T c2_m_b;
  int32_T c2_nFinite;
  int32_T c2_nInf;
  int32_T c2_nNaN;
  int32_T c2_n_a;
  int32_T c2_nb;
  int32_T c2_o_a;
  int32_T c2_p_a;
  int32_T c2_p_b;
  int32_T c2_q_a;
  int32_T c2_q_b;
  int32_T c2_r_a;
  int32_T c2_r_b;
  int32_T c2_s_a;
  int32_T c2_t_b;
  int32_T c2_v_b;
  real32_T c2_absx;
  real32_T c2_b_y;
  real32_T c2_e_x;
  real32_T c2_f_x;
  real32_T c2_g_x;
  real32_T c2_h_x;
  real32_T c2_i_x;
  real32_T c2_j_x;
  real32_T c2_k_x;
  real32_T c2_l_x;
  real32_T c2_m_a;
  real32_T c2_m_x;
  real32_T c2_n_b;
  real32_T c2_n_x;
  real32_T c2_o_x;
  real32_T c2_p_x;
  real32_T c2_q_x;
  real32_T c2_r;
  real32_T c2_r_x;
  real32_T c2_s_x;
  real32_T c2_t_x;
  real32_T c2_u_x;
  real32_T c2_v_x;
  real32_T c2_z;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b_overflow;
  boolean_T c2_b_p;
  boolean_T c2_c_overflow;
  boolean_T c2_d_b;
  boolean_T c2_d_overflow;
  boolean_T c2_exitg1;
  boolean_T c2_f_b;
  boolean_T c2_o_b;
  boolean_T c2_overflow;
  boolean_T c2_p;
  boolean_T c2_s_b;
  boolean_T c2_u_b;
  boolean_T c2_w_b;
  boolean_T c2_x_b;
  boolean_T c2_y_b;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_wc_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    chartInstance->c2_idx[c2_i] = 0;
  }

  c2_b_st.site = &c2_ic_emlrtRSI;
  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    chartInstance->c2_a[c2_i1] = c2_d_a[c2_i1];
  }

  c2_b_mergesort(chartInstance, &c2_b_st, chartInstance->c2_idx,
                 chartInstance->c2_a);
  c2_i2 = c2_b->size[0];
  c2_b->size[0] = 307200;
  c2_st.site = &c2_vj_emlrtRSI;
  c2_emxEnsureCapacity_real32_T1(chartInstance, &c2_st, c2_b, c2_i2,
    &c2_ad_emlrtRTEI);
  for (c2_k = 0; c2_k < 307200; c2_k++) {
    c2_b_k = c2_k;
    c2_b->data[c2_b_k] = c2_d_a[chartInstance->c2_idx[c2_b_k] - 1];
  }

  c2_emxInit_real32_T1(chartInstance, c2_sp, &c2_b_b, 1, &c2_bd_emlrtRTEI);
  c2_i3 = c2_b_b->size[0];
  c2_b_b->size[0] = c2_b->size[0];
  c2_st.site = &c2_uj_emlrtRSI;
  c2_emxEnsureCapacity_real32_T1(chartInstance, &c2_st, c2_b_b, c2_i3,
    &c2_bd_emlrtRTEI);
  c2_loop_ub = c2_b->size[0] - 1;
  for (c2_i4 = 0; c2_i4 <= c2_loop_ub; c2_i4++) {
    c2_b_b->data[c2_i4] = c2_b->data[c2_i4];
  }

  c2_c_k = 307200;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_c_k >= 1)) {
    c2_e_x = c2_b_b->data[c2_c_k - 1];
    c2_d_b = muSingleScalarIsNaN(c2_e_x);
    if (c2_d_b) {
      c2_e_a = c2_c_k - 1;
      c2_c_k = c2_e_a;
    } else {
      c2_exitg1 = true;
    }
  }

  c2_c_b = c2_c_k;
  c2_nNaN = 307200 - c2_c_b;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_c_k >= 1)) {
    c2_f_x = c2_b_b->data[c2_c_k - 1];
    c2_f_b = muSingleScalarIsInf(c2_f_x);
    if (c2_f_b && (c2_b_b->data[c2_c_k - 1] > 0.0F)) {
      c2_g_a = c2_c_k - 1;
      c2_c_k = c2_g_a;
    } else {
      c2_exitg1 = true;
    }
  }

  c2_emxFree_real32_T(chartInstance, &c2_b_b);
  c2_e_b = c2_c_k;
  c2_c = 307200 - c2_e_b;
  c2_f_a = c2_c;
  c2_g_b = c2_nNaN;
  c2_nInf = c2_f_a - c2_g_b;
  c2_h_a = c2_c_k;
  c2_nFinite = c2_h_a;
  c2_nb = -1;
  c2_h_b = c2_nFinite;
  c2_khi = c2_h_b;
  c2_b_k = 1;
  while (c2_b_k <= c2_khi) {
    c2_g_x = c2_b->data[c2_b_k - 1];
    c2_k0 = c2_b_k;
    do {
      c2_exitg2 = 0;
      c2_l_a = c2_b_k + 1;
      c2_b_k = c2_l_a;
      if (c2_b_k > c2_khi) {
        c2_exitg2 = 1;
      } else {
        c2_st.site = &c2_uc_emlrtRSI;
        c2_m_a = c2_b->data[c2_b_k - 1];
        c2_n_b = c2_g_x;
        c2_h_x = c2_n_b;
        c2_i_x = c2_h_x;
        c2_z = c2_i_x / 2.0F;
        c2_j_x = c2_n_b - c2_m_a;
        c2_k_x = c2_j_x;
        c2_l_x = c2_k_x;
        c2_b_y = muSingleScalarAbs(c2_l_x);
        c2_b_st.site = &c2_kc_emlrtRSI;
        c2_m_x = c2_z;
        c2_n_x = c2_m_x;
        c2_o_x = c2_n_x;
        c2_p_x = c2_o_x;
        c2_q_x = c2_p_x;
        c2_absx = muSingleScalarAbs(c2_q_x);
        c2_r_x = c2_absx;
        c2_s_x = c2_r_x;
        c2_s_b = muSingleScalarIsInf(c2_s_x);
        c2_b1 = !c2_s_b;
        c2_t_x = c2_r_x;
        c2_u_b = muSingleScalarIsNaN(c2_t_x);
        c2_b2 = !c2_u_b;
        c2_w_b = (c2_b1 && c2_b2);
        if (c2_w_b) {
          if (c2_absx <= 1.17549435E-38F) {
            c2_r = 1.4013E-45F;
          } else {
            frexpf(c2_absx, &c2_exponent);
            c2_b_exponent = c2_exponent;
            c2_r = ldexpf(1.0F, c2_b_exponent - 24);
          }
        } else {
          c2_r = rtNaNF;
        }

        if (c2_b_y < c2_r) {
          c2_p = true;
        } else {
          c2_u_x = c2_m_a;
          c2_x_b = muSingleScalarIsInf(c2_u_x);
          if (c2_x_b) {
            c2_v_x = c2_n_b;
            c2_y_b = muSingleScalarIsInf(c2_v_x);
            if (c2_y_b && ((c2_m_a > 0.0F) == (c2_n_b > 0.0F))) {
              c2_p = true;
            } else {
              c2_p = false;
            }
          } else {
            c2_p = false;
          }
        }

        c2_b_p = c2_p;
        if (!c2_b_p) {
          c2_exitg2 = 1;
        }
      }
    } while (c2_exitg2 == 0);

    c2_n_a = c2_nb + 1;
    c2_nb = c2_n_a;
    c2_b->data[c2_nb] = c2_g_x;
    c2_o_a = c2_b_k - 1;
    c2_i5 = c2_o_a;
    c2_st.site = &c2_tc_emlrtRSI;
    c2_p_a = c2_k0;
    c2_p_b = c2_i5;
    c2_r_a = c2_p_a;
    c2_q_b = c2_p_b;
    if (c2_r_a > c2_q_b) {
      c2_c_overflow = false;
    } else {
      c2_c_overflow = (c2_q_b > 2147483646);
    }

    if (c2_c_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }
  }

  if (c2_nInf > 0) {
    c2_i_a = c2_nb + 1;
    c2_nb = c2_i_a;
    c2_k_a = c2_khi + 1;
    c2_b_c = c2_k_a - 1;
    c2_b->data[c2_nb] = c2_b->data[c2_b_c];
    c2_st.site = &c2_sc_emlrtRSI;
    c2_l_b = c2_nInf;
    c2_m_b = c2_l_b;
    if (1 > c2_m_b) {
      c2_b_overflow = false;
    } else {
      c2_b_overflow = (c2_m_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }
  }

  c2_j_a = c2_khi;
  c2_i_b = c2_nInf;
  c2_b_k = c2_j_a + c2_i_b;
  c2_st.site = &c2_rc_emlrtRSI;
  c2_j_b = c2_nNaN;
  c2_k_b = c2_j_b;
  if (1 > c2_k_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_k_b > 2147483646);
  }

  if (c2_overflow) {
    c2_b_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
  }

  for (c2_j = 1; c2_j - 1 < c2_nNaN; c2_j++) {
    c2_b_j = c2_j;
    c2_q_a = c2_nb + 1;
    c2_nb = c2_q_a;
    c2_s_a = c2_b_k;
    c2_r_b = c2_b_j;
    c2_c_c = (c2_s_a + c2_r_b) - 1;
    c2_b->data[c2_nb] = c2_b->data[c2_c_c];
  }

  c2_o_b = (1 > c2_nb + 1);
  if (c2_o_b) {
    c2_i6 = 0;
  } else {
    c2_i6 = c2_nb + 1;
  }

  c2_iv[0] = 1;
  c2_iv[1] = c2_i6;
  c2_st.site = &c2_qc_emlrtRSI;
  c2_indexShapeCheck(chartInstance, &c2_st, 307200, c2_iv);
  c2_i7 = c2_b->size[0];
  c2_b->size[0] = c2_i6;
  c2_st.site = &c2_tj_emlrtRSI;
  c2_emxEnsureCapacity_real32_T1(chartInstance, &c2_st, c2_b, c2_i7,
    &c2_cd_emlrtRTEI);
  c2_st.site = &c2_pc_emlrtRSI;
  c2_t_b = c2_nb + 1;
  c2_v_b = c2_t_b;
  if (1 > c2_v_b) {
    c2_d_overflow = false;
  } else {
    c2_d_overflow = (c2_v_b > 2147483646);
  }

  if (c2_d_overflow) {
    c2_b_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
  }
}

static void c2_indexShapeCheck(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_matrixSize, int32_T c2_indexSize[2])
{
  static char_T c2_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  int32_T c2_size1;
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_b_c;
  boolean_T c2_c;
  boolean_T c2_nonSingletonDimFound;
  (void)chartInstance;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_size1 = c2_matrixSize;
  if (c2_size1 != 1) {
    c2_b = false;
  } else {
    c2_b = true;
  }

  if (c2_b) {
    c2_nonSingletonDimFound = false;
    if (c2_indexSize[1] != 1) {
      c2_nonSingletonDimFound = true;
    }

    c2_b_b = c2_nonSingletonDimFound;
    if (c2_b_b) {
      c2_c = true;
    } else {
      c2_c = false;
    }
  } else {
    c2_c = false;
  }

  c2_st.site = &c2_xc_emlrtRSI;
  c2_b_c = c2_c;
  if (c2_b_c) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c2_st, &c2_b_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_c_y)));
  }
}

static void c2_nullAssignment(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real32_T *c2_e_x, c2_emxArray_boolean_T
  *c2_b_idx, c2_emxArray_real32_T *c2_f_x)
{
  c2_emxArray_boolean_T *c2_c_idx;
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_loop_ub;
  c2_i = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = 1;
  c2_f_x->size[1] = c2_e_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_sp, c2_f_x, c2_i,
    &c2_dd_emlrtRTEI);
  c2_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_f_x->data[c2_i1] = c2_e_x->data[c2_i1];
  }

  c2_emxInit_boolean_T(chartInstance, c2_sp, &c2_c_idx, 2, &c2_dd_emlrtRTEI);
  c2_i2 = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = 1;
  c2_c_idx->size[1] = c2_b_idx->size[1];
  c2_emxEnsureCapacity_boolean_T(chartInstance, c2_sp, c2_c_idx, c2_i2,
    &c2_dd_emlrtRTEI);
  c2_b_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_c_idx->data[c2_i3] = c2_b_idx->data[c2_i3];
  }

  c2_b_nullAssignment(chartInstance, c2_sp, c2_f_x, c2_c_idx);
  c2_emxFree_boolean_T(chartInstance, &c2_c_idx);
}

static void c2_c_warning(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp)
{
  static char_T c2_msgID[32] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'm', 'u',
    'l', 't', 'i', 't', 'h', 'r', 'e', 's', 'h', ':', 'n', 'o', 'C', 'o', 'n',
    'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  static char_T c2_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c2_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 32),
                false);
  c2_st.site = &c2_c_emlrtRSI;
  c2_f_feval(chartInstance, &c2_st, c2_b_y, c2_e_feval(chartInstance, &c2_st,
              c2_c_y, c2_d_y));
}

static void c2_abs(SFc2_imagedetectorInstanceStruct *chartInstance, const
                   emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x,
                   c2_emxArray_real_T *c2_b_y)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_dv[2];
  real_T c2_c_y;
  real_T c2_f_x;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_i;
  int32_T c2_k;
  int32_T c2_nx;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_hd_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_nx = c2_e_x->size[0];
  c2_dv[0] = (real_T)c2_e_x->size[0];
  c2_i = c2_b_y->size[0];
  c2_b_y->size[0] = (int32_T)c2_dv[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_b_y, c2_i,
    &c2_ed_emlrtRTEI);
  c2_b_st.site = &c2_id_emlrtRSI;
  c2_b = c2_nx;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = 1; c2_k - 1 < c2_nx; c2_k++) {
    c2_b_k = c2_k - 1;
    c2_f_x = c2_e_x->data[c2_b_k];
    c2_c_y = muDoubleScalarAbs(c2_f_x);
    c2_b_y->data[c2_b_k] = c2_c_y;
  }
}

static real_T c2_eps(SFc2_imagedetectorInstanceStruct *chartInstance, real_T
                     c2_e_x)
{
  real_T c2_absx;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_r;
  int32_T c2_b_exponent;
  int32_T c2_exponent;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b_b;
  boolean_T c2_c_b;
  boolean_T c2_d_b;
  (void)chartInstance;
  c2_f_x = c2_e_x;
  c2_g_x = c2_f_x;
  c2_h_x = c2_g_x;
  c2_i_x = c2_h_x;
  c2_absx = muDoubleScalarAbs(c2_i_x);
  c2_j_x = c2_absx;
  c2_k_x = c2_j_x;
  c2_b = muDoubleScalarIsInf(c2_k_x);
  c2_b_b = !c2_b;
  c2_l_x = c2_j_x;
  c2_c_b = muDoubleScalarIsNaN(c2_l_x);
  c2_b1 = !c2_c_b;
  c2_d_b = (c2_b_b && c2_b1);
  if (c2_d_b) {
    if (c2_absx <= 2.2250738585072014E-308) {
      c2_r = 4.94065645841247E-324;
    } else {
      frexp(c2_absx, &c2_exponent);
      c2_b_exponent = c2_exponent;
      c2_r = ldexp(1.0, c2_b_exponent - 53);
    }
  } else {
    c2_r = rtNaN;
  }

  return c2_r;
}

static boolean_T c2_any(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_e_x)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_a;
  real_T c2_vlen;
  int32_T c2_b_b;
  int32_T c2_c;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_i2;
  int32_T c2_ix;
  int32_T c2_vspread;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b_y;
  boolean_T c2_exitg1;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_st.site = &c2_jd_emlrtRSI;
  if ((c2_e_x->size[0] == 1) || ((real_T)c2_e_x->size[0] != 1.0)) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c2_st, &c2_e_emlrtMCI, "error", 0U, 2U, 14, c2_c_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_d_y)));
  }

  c2_b_y = false;
  c2_vlen = (real_T)c2_e_x->size[0];
  c2_d_a = c2_vlen;
  c2_c = (int32_T)c2_d_a;
  c2_e_a = c2_c - 1;
  c2_vspread = c2_e_a;
  c2_b_b = c2_vspread;
  c2_i2 = c2_b_b;
  c2_f_a = c2_i2 + 1;
  c2_i2 = c2_f_a;
  c2_b_st.site = &c2_kd_emlrtRSI;
  c2_c_b = c2_i2;
  c2_d_b = c2_c_b;
  if (1 > c2_d_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_d_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  c2_ix = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_ix + 1 <= c2_i2)) {
    if (!c2_e_x->data[c2_ix]) {
      c2_b1 = true;
    } else {
      c2_b1 = false;
    }

    if (!c2_b1) {
      c2_b_y = true;
      c2_exitg1 = true;
    } else {
      c2_ix++;
    }
  }

  return c2_b_y;
}

static void c2_sort(SFc2_imagedetectorInstanceStruct *chartInstance, const
                    emlrtStack *c2_sp, c2_emxArray_real32_T *c2_e_x,
                    c2_emxArray_real32_T *c2_f_x)
{
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_loop_ub;
  c2_i = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = 1;
  c2_f_x->size[1] = c2_e_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_sp, c2_f_x, c2_i,
    &c2_fd_emlrtRTEI);
  c2_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_f_x->data[c2_i1] = c2_e_x->data[c2_i1];
  }

  c2_c_sort(chartInstance, c2_sp, c2_f_x);
}

static void c2_merge_pow2_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T
  *c2_e_x, int32_T c2_offset, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real32_T *c2_f_x)
{
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_loop_ub;
  c2_i = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = 1;
  c2_c_idx->size[1] = c2_b_idx->size[1];
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_sp, c2_c_idx, c2_i,
    &c2_gd_emlrtRTEI);
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_c_idx->data[c2_i1] = c2_b_idx->data[c2_i1];
  }

  c2_i2 = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = 1;
  c2_f_x->size[1] = c2_e_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_sp, c2_f_x, c2_i2,
    &c2_gd_emlrtRTEI);
  c2_b_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_f_x->data[c2_i3] = c2_e_x->data[c2_i3];
  }

  c2_c_merge_pow2_block(chartInstance, c2_sp, c2_c_idx, c2_f_x, c2_offset);
}

static void c2_merge_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T
  *c2_e_x, int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel,
  c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real32_T *c2_xwork,
  c2_emxArray_int32_T *c2_c_idx, c2_emxArray_real32_T *c2_f_x,
  c2_emxArray_int32_T *c2_c_iwork, c2_emxArray_real32_T *c2_b_xwork)
{
  int32_T c2_b_loop_ub;
  int32_T c2_c_loop_ub;
  int32_T c2_d_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_loop_ub;
  c2_i = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = 1;
  c2_c_idx->size[1] = c2_b_idx->size[1];
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_sp, c2_c_idx, c2_i,
    &c2_hd_emlrtRTEI);
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_c_idx->data[c2_i1] = c2_b_idx->data[c2_i1];
  }

  c2_i2 = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = 1;
  c2_f_x->size[1] = c2_e_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_sp, c2_f_x, c2_i2,
    &c2_hd_emlrtRTEI);
  c2_b_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_f_x->data[c2_i3] = c2_e_x->data[c2_i3];
  }

  c2_i4 = c2_c_iwork->size[0];
  c2_c_iwork->size[0] = c2_b_iwork->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_c_iwork, c2_i4,
    &c2_hd_emlrtRTEI);
  c2_c_loop_ub = c2_b_iwork->size[0] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_c_loop_ub; c2_i5++) {
    c2_c_iwork->data[c2_i5] = c2_b_iwork->data[c2_i5];
  }

  c2_i6 = c2_b_xwork->size[0];
  c2_b_xwork->size[0] = c2_xwork->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_sp, c2_b_xwork, c2_i6,
    &c2_hd_emlrtRTEI);
  c2_d_loop_ub = c2_xwork->size[0] - 1;
  for (c2_i7 = 0; c2_i7 <= c2_d_loop_ub; c2_i7++) {
    c2_b_xwork->data[c2_i7] = c2_xwork->data[c2_i7];
  }

  c2_c_merge_block(chartInstance, c2_sp, c2_c_idx, c2_f_x, c2_offset, c2_n,
                   c2_preSortLevel, c2_c_iwork, c2_b_xwork);
}

static void c2_merge(SFc2_imagedetectorInstanceStruct *chartInstance, const
                     emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx,
                     c2_emxArray_real32_T *c2_e_x, int32_T c2_offset, int32_T
                     c2_np, int32_T c2_nq, c2_emxArray_int32_T *c2_b_iwork,
                     c2_emxArray_real32_T *c2_xwork, c2_emxArray_int32_T
                     *c2_c_idx, c2_emxArray_real32_T *c2_f_x,
                     c2_emxArray_int32_T *c2_c_iwork, c2_emxArray_real32_T
                     *c2_b_xwork)
{
  int32_T c2_b_loop_ub;
  int32_T c2_c_loop_ub;
  int32_T c2_d_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_loop_ub;
  c2_i = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = 1;
  c2_c_idx->size[1] = c2_b_idx->size[1];
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_sp, c2_c_idx, c2_i,
    &c2_id_emlrtRTEI);
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_c_idx->data[c2_i1] = c2_b_idx->data[c2_i1];
  }

  c2_i2 = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = 1;
  c2_f_x->size[1] = c2_e_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_sp, c2_f_x, c2_i2,
    &c2_id_emlrtRTEI);
  c2_b_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_f_x->data[c2_i3] = c2_e_x->data[c2_i3];
  }

  c2_i4 = c2_c_iwork->size[0];
  c2_c_iwork->size[0] = c2_b_iwork->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_c_iwork, c2_i4,
    &c2_id_emlrtRTEI);
  c2_c_loop_ub = c2_b_iwork->size[0] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_c_loop_ub; c2_i5++) {
    c2_c_iwork->data[c2_i5] = c2_b_iwork->data[c2_i5];
  }

  c2_i6 = c2_b_xwork->size[0];
  c2_b_xwork->size[0] = c2_xwork->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_sp, c2_b_xwork, c2_i6,
    &c2_id_emlrtRTEI);
  c2_d_loop_ub = c2_xwork->size[0] - 1;
  for (c2_i7 = 0; c2_i7 <= c2_d_loop_ub; c2_i7++) {
    c2_b_xwork->data[c2_i7] = c2_xwork->data[c2_i7];
  }

  c2_c_merge(chartInstance, c2_sp, c2_c_idx, c2_f_x, c2_offset, c2_np, c2_nq,
             c2_c_iwork, c2_b_xwork);
}

static void c2_eml_find(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, boolean_T c2_e_x[307200], c2_emxArray_int32_T *c2_i,
  c2_emxArray_int32_T *c2_j)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_iv[2];
  int32_T c2_iv1[2];
  int32_T c2_iv2[2];
  int32_T c2_b_i;
  int32_T c2_b_idx;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_ii;
  int32_T c2_jj;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_exitg1;
  boolean_T c2_guard1 = false;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_he_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_b_idx = 0;
  c2_b_i = c2_i->size[0];
  c2_i->size[0] = 307200;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_i, c2_b_i,
    &c2_jd_emlrtRTEI);
  c2_i1 = c2_j->size[0];
  c2_j->size[0] = 307200;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_j, c2_i1,
    &c2_kd_emlrtRTEI);
  c2_ii = 1;
  c2_jj = 1;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_jj <= 640)) {
    c2_guard1 = false;
    if (c2_e_x[(c2_ii + 480 * (c2_jj - 1)) - 1]) {
      c2_b_idx++;
      c2_i->data[c2_b_idx - 1] = c2_ii;
      c2_j->data[c2_b_idx - 1] = c2_jj;
      if (c2_b_idx >= 307200) {
        c2_exitg1 = true;
      } else {
        c2_guard1 = true;
      }
    } else {
      c2_guard1 = true;
    }

    if (c2_guard1) {
      c2_ii++;
      if (c2_ii > 480) {
        c2_ii = 1;
        c2_jj++;
      }
    }
  }

  c2_b = (1 > c2_b_idx);
  if (c2_b) {
    c2_i2 = 0;
  } else {
    c2_i2 = c2_b_idx;
  }

  c2_iv[0] = 1;
  c2_iv[1] = c2_i2;
  c2_b_st.site = &c2_ke_emlrtRSI;
  c2_indexShapeCheck(chartInstance, &c2_b_st, 307200, c2_iv);
  c2_i3 = c2_i->size[0];
  c2_i->size[0] = c2_i2;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_i, c2_i3,
    &c2_ld_emlrtRTEI);
  c2_b1 = (1 > c2_b_idx);
  if (c2_b1) {
    c2_i4 = 0;
  } else {
    c2_i4 = c2_b_idx;
  }

  c2_iv1[0] = 1;
  c2_iv1[1] = c2_i4;
  c2_b_st.site = &c2_je_emlrtRSI;
  c2_indexShapeCheck(chartInstance, &c2_b_st, 307200, c2_iv1);
  c2_i5 = c2_j->size[0];
  c2_j->size[0] = c2_i4;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_j, c2_i5,
    &c2_md_emlrtRTEI);
  c2_b2 = (1 > c2_b_idx);
  if (c2_b2) {
    c2_i6 = 0;
  } else {
    c2_i6 = c2_b_idx;
  }

  c2_iv2[0] = 1;
  c2_iv2[1] = c2_i6;
  c2_b_st.site = &c2_ie_emlrtRSI;
  c2_indexShapeCheck(chartInstance, &c2_b_st, 307200, c2_iv2);
}

static boolean_T c2_allinrange(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_e_x, int32_T c2_hi)
{
  real_T c2_b_k;
  real_T c2_d;
  int32_T c2_exitg1;
  int32_T c2_i;
  int32_T c2_k;
  boolean_T c2_b;
  boolean_T c2_p;
  (void)chartInstance;
  c2_d = (real_T)c2_e_x->size[0];
  c2_i = (int32_T)c2_d - 1;
  c2_k = 0;
  do {
    c2_exitg1 = 0;
    if (c2_k <= c2_i) {
      c2_b_k = (real_T)c2_k + 1.0;
      if ((c2_e_x->data[(int32_T)c2_b_k - 1] >= 1.0) && (c2_e_x->data[(int32_T)
           c2_b_k - 1] <= (real_T)c2_hi)) {
        c2_b = true;
      } else {
        c2_b = false;
      }

      if (!c2_b) {
        c2_p = false;
        c2_exitg1 = 1;
      } else {
        c2_k++;
      }
    } else {
      c2_p = true;
      c2_exitg1 = 1;
    }
  } while (c2_exitg1 == 0);

  return c2_p;
}

static void c2_eml_sub2ind(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T *c2_f_varargin_1,
  c2_emxArray_real_T *c2_b_varargin_2, c2_emxArray_int32_T *c2_b_idx)
{
  static char_T c2_b_cv1[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't',
    'V', 'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  static char_T c2_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  c2_emxArray_int32_T *c2_b;
  c2_emxArray_real_T *c2_d_varargin_2;
  c2_emxArray_real_T *c2_g_varargin_1;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  real_T c2_c_varargin_2[2];
  real_T c2_h_varargin_1[2];
  real_T c2_b_k;
  real_T c2_x1;
  real_T c2_x2;
  int32_T c2_b_loop_ub;
  int32_T c2_c_loop_ub;
  int32_T c2_d_loop_ub;
  int32_T c2_e_loop_ub;
  int32_T c2_f_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_k;
  int32_T c2_loop_ub;
  boolean_T c2_b_p;
  boolean_T c2_c_p;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_emxInit_real_T1(chartInstance, c2_sp, &c2_g_varargin_1, 1, &c2_nd_emlrtRTEI);
  c2_i = c2_g_varargin_1->size[0];
  c2_g_varargin_1->size[0] = c2_f_varargin_1->size[0];
  c2_st.site = &c2_ij_emlrtRSI;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_g_varargin_1, c2_i,
    &c2_nd_emlrtRTEI);
  c2_loop_ub = c2_f_varargin_1->size[0] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_g_varargin_1->data[c2_i1] = c2_f_varargin_1->data[c2_i1];
  }

  if (!c2_allinrange(chartInstance, c2_g_varargin_1, 480)) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c2_sp, &c2_f_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_c_y)));
  }

  c2_emxFree_real_T(chartInstance, &c2_g_varargin_1);
  c2_h_varargin_1[0] = (real_T)c2_f_varargin_1->size[0];
  c2_h_varargin_1[1] = 1.0;
  c2_c_varargin_2[0] = (real_T)c2_b_varargin_2->size[0];
  c2_c_varargin_2[1] = 1.0;
  c2_p = false;
  c2_b_p = true;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 2)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_x1 = c2_h_varargin_1[(int32_T)c2_b_k - 1];
    c2_x2 = c2_c_varargin_2[(int32_T)c2_b_k - 1];
    c2_c_p = (c2_x1 == c2_x2);
    if (!c2_c_p) {
      c2_b_p = false;
      c2_exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (c2_b_p) {
    c2_p = true;
  }

  if (!c2_p) {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    sf_mex_call(c2_sp, &c2_g_emlrtMCI, "error", 0U, 2U, 14, c2_d_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_e_y)));
  }

  c2_emxInit_real_T1(chartInstance, c2_sp, &c2_d_varargin_2, 1, &c2_nd_emlrtRTEI);
  c2_i2 = c2_d_varargin_2->size[0];
  c2_d_varargin_2->size[0] = c2_b_varargin_2->size[0];
  c2_st.site = &c2_ij_emlrtRSI;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_d_varargin_2, c2_i2,
    &c2_nd_emlrtRTEI);
  c2_b_loop_ub = c2_b_varargin_2->size[0] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_d_varargin_2->data[c2_i3] = c2_b_varargin_2->data[c2_i3];
  }

  if (!c2_allinrange(chartInstance, c2_d_varargin_2, 640)) {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c2_sp, &c2_f_emlrtMCI, "error", 0U, 2U, 14, c2_f_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_g_y)));
  }

  c2_emxFree_real_T(chartInstance, &c2_d_varargin_2);
  c2_i4 = c2_b_idx->size[0];
  c2_b_idx->size[0] = c2_f_varargin_1->size[0];
  c2_st.site = &c2_aj_emlrtRSI;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_b_idx, c2_i4,
    &c2_od_emlrtRTEI);
  c2_c_loop_ub = c2_f_varargin_1->size[0] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_c_loop_ub; c2_i5++) {
    c2_b_idx->data[c2_i5] = (int32_T)c2_f_varargin_1->data[c2_i5];
  }

  c2_emxInit_int32_T(chartInstance, c2_sp, &c2_b, 1, &c2_pd_emlrtRTEI);
  c2_i6 = c2_b->size[0];
  c2_b->size[0] = c2_b_varargin_2->size[0];
  c2_st.site = &c2_yi_emlrtRSI;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_b, c2_i6,
    &c2_pd_emlrtRTEI);
  c2_d_loop_ub = c2_b_varargin_2->size[0] - 1;
  for (c2_i7 = 0; c2_i7 <= c2_d_loop_ub; c2_i7++) {
    c2_b->data[c2_i7] = (int32_T)c2_b_varargin_2->data[c2_i7] - 1;
  }

  c2_i8 = c2_b->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_b, c2_i8,
    &c2_qd_emlrtRTEI);
  c2_e_loop_ub = c2_b->size[0] - 1;
  for (c2_i9 = 0; c2_i9 <= c2_e_loop_ub; c2_i9++) {
    c2_b->data[c2_i9] *= 480;
  }

  c2_i10 = c2_b_idx->size[0];
  c2_st.site = &c2_yi_emlrtRSI;
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_b_idx, c2_i10,
    &c2_rd_emlrtRTEI);
  c2_f_loop_ub = c2_b_idx->size[0] - 1;
  for (c2_i11 = 0; c2_i11 <= c2_f_loop_ub; c2_i11++) {
    c2_b_idx->data[c2_i11] += c2_b->data[c2_i11];
  }

  c2_emxFree_int32_T(chartInstance, &c2_b);
}

static void c2_medfilt2(SFc2_imagedetectorInstanceStruct *chartInstance, real_T
  c2_f_varargin_1[307200], real_T c2_b[307200])
{
  static int32_T c2_offsets[25] = { -970, -969, -968, -967, -966, -486, -485,
    -484, -483, -482, -2, -1, 0, 1, 2, 482, 483, 484, 485, 486, 966, 967, 968,
    969, 970 };

  real_T c2_domainSizeT[2];
  real_T c2_sizeB[2];
  real_T c2_startIdxT[2];
  real_T c2_c_i;
  real_T c2_c_j;
  real_T c2_d_a;
  real_T c2_e_a;
  real_T c2_f_a;
  real_T c2_g_a;
  int32_T c2_b_c;
  int32_T c2_b_i;
  int32_T c2_b_j;
  int32_T c2_c;
  int32_T c2_c_c;
  int32_T c2_d_c;
  int32_T c2_d_i;
  int32_T c2_d_j;
  int32_T c2_e_i;
  int32_T c2_e_j;
  int32_T c2_f_i;
  int32_T c2_f_j;
  int32_T c2_g_i;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_j;
  for (c2_j = 0; c2_j < 2; c2_j++) {
    c2_c_j = (real_T)c2_j + 1.0;
    for (c2_i = 0; c2_i < 484; c2_i++) {
      c2_c_i = (real_T)c2_i + 1.0;
      chartInstance->c2_Apad[((int32_T)c2_c_i + 484 * ((int32_T)c2_c_j - 1)) - 1]
        = 0.0;
    }
  }

  for (c2_b_j = 0; c2_b_j < 2; c2_b_j++) {
    for (c2_b_i = 0; c2_b_i < 484; c2_b_i++) {
      c2_c_i = (real_T)c2_b_i + 1.0;
      chartInstance->c2_Apad[((int32_T)c2_c_i + 484 * (c2_b_j + 642)) - 1] = 0.0;
    }
  }

  for (c2_d_j = 0; c2_d_j < 640; c2_d_j++) {
    c2_c_j = (real_T)c2_d_j + 1.0;
    for (c2_d_i = 0; c2_d_i < 2; c2_d_i++) {
      c2_c_i = (real_T)c2_d_i + 1.0;
      c2_d_a = c2_c_j;
      c2_c = (int32_T)c2_d_a;
      chartInstance->c2_Apad[((int32_T)c2_c_i + 484 * (c2_c + 1)) - 1] = 0.0;
    }
  }

  for (c2_e_j = 0; c2_e_j < 640; c2_e_j++) {
    c2_c_j = (real_T)c2_e_j + 1.0;
    for (c2_e_i = 0; c2_e_i < 2; c2_e_i++) {
      c2_e_a = c2_c_j;
      c2_b_c = (int32_T)c2_e_a;
      chartInstance->c2_Apad[(c2_e_i + 484 * (c2_b_c + 1)) + 482] = 0.0;
    }
  }

  for (c2_f_j = 0; c2_f_j < 640; c2_f_j++) {
    c2_c_j = (real_T)c2_f_j + 1.0;
    for (c2_g_i = 0; c2_g_i < 480; c2_g_i++) {
      c2_c_i = (real_T)c2_g_i + 1.0;
      c2_f_a = c2_c_i;
      c2_c_c = (int32_T)c2_f_a;
      c2_g_a = c2_c_j;
      c2_d_c = (int32_T)c2_g_a;
      chartInstance->c2_Apad[(c2_c_c + 484 * (c2_d_c + 1)) + 1] =
        c2_f_varargin_1[((int32_T)c2_c_i + 480 * ((int32_T)c2_c_j - 1)) - 1];
    }
  }

  for (c2_f_i = 0; c2_f_i < 2; c2_f_i++) {
    c2_domainSizeT[c2_f_i] = 5.0;
  }

  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    c2_startIdxT[c2_i1] = 2.0;
  }

  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    c2_sizeB[c2_i2] = 480.0 + 160.0 * (real_T)c2_i2;
  }

  ordfilt2_real64(&chartInstance->c2_Apad[0], 484.0, &c2_startIdxT[0],
                  &c2_offsets[0], 25.0, &c2_domainSizeT[0], 12.0, &c2_b[0],
                  &c2_sizeB[0], true);
}

static void c2_chcenters(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, creal_T c2_f_varargin_1[307200], c2_emxArray_real_T
  *c2_centers, c2_emxArray_real_T *c2_metric)
{
  c2_emxArray_boolean_T *c2_f_x;
  c2_emxArray_int32_T *c2_iidx;
  c2_emxArray_int32_T *c2_r;
  c2_emxArray_real_T *c2_b_centers;
  c2_emxArray_real_T *c2_b_varargin_2;
  c2_emxArray_real_T *c2_g_x;
  c2_emxArray_real_T *c2_l_x;
  c2_emxArray_real_T *c2_ndx;
  c2_emxArray_real_T *c2_sortIdx;
  c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_s;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_st;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  creal_T c2_e_x;
  real_T c2_b;
  real_T c2_b_y;
  real_T c2_c_accumMatrixRe;
  real_T c2_c_idx;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_d3;
  real_T c2_d_a;
  real_T c2_d_k;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_x1;
  real_T c2_x2;
  int32_T c2_iv[2];
  int32_T c2_iv1[2];
  int32_T c2_tmp_data[2];
  int32_T c2_b_sortIdx[1];
  int32_T c2_b_i;
  int32_T c2_b_idx;
  int32_T c2_b_j;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_c_centers;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_d_idx;
  int32_T c2_d_loop_ub;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_e_idx;
  int32_T c2_e_loop_ub;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_idx;
  int32_T c2_f_loop_ub;
  int32_T c2_g_idx;
  int32_T c2_g_loop_ub;
  int32_T c2_h_idx;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i5;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_loop_ub;
  int32_T c2_j;
  int32_T c2_j_loop_ub;
  int32_T c2_j_x;
  int32_T c2_k;
  int32_T c2_k_loop_ub;
  int32_T c2_k_x;
  int32_T c2_l_loop_ub;
  int32_T c2_loop_ub;
  int32_T c2_m_loop_ub;
  int32_T c2_n;
  int32_T c2_nrows;
  int32_T c2_nrowx;
  boolean_T c2_b1;
  boolean_T c2_b_b;
  boolean_T c2_c_b;
  boolean_T c2_d_b;
  boolean_T c2_exitg1;
  boolean_T c2_flat;
  boolean_T c2_guard1 = false;
  boolean_T c2_overflow;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_centers->size[0] = 0;
  c2_centers->size[1] = 0;
  c2_metric->size[0] = 0;
  c2_metric->size[1] = 0;
  for (c2_k = 0; c2_k < 307200; c2_k++) {
    c2_b_k = c2_k;
    c2_e_x = c2_f_varargin_1[c2_b_k];
    c2_x1 = c2_e_x.re;
    c2_x2 = c2_e_x.im;
    c2_d_a = c2_x1;
    c2_b = c2_x2;
    c2_b_y = muDoubleScalarHypot(c2_d_a, c2_b);
    chartInstance->c2_accumMatrixRe[c2_b_k] = c2_b_y;
  }

  c2_c_accumMatrixRe = chartInstance->c2_accumMatrixRe[0];
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    chartInstance->c2_bw[c2_i] = (chartInstance->c2_accumMatrixRe[c2_i] ==
      c2_c_accumMatrixRe);
  }

  c2_emxInit_boolean_T1(chartInstance, c2_sp, &c2_f_x, 1, &c2_c_emlrtRTEI);
  c2_i1 = c2_f_x->size[0];
  c2_f_x->size[0] = 307200;
  c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_sp, c2_f_x, c2_i1,
    &c2_c_emlrtRTEI);
  for (c2_i2 = 0; c2_i2 < 307200; c2_i2++) {
    c2_f_x->data[c2_i2] = chartInstance->c2_bw[c2_i2];
  }

  c2_flat = true;
  c2_d = (real_T)c2_f_x->size[0];
  c2_i3 = (int32_T)c2_d - 1;
  c2_c_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_c_k <= c2_i3)) {
    c2_d_k = (real_T)c2_c_k + 1.0;
    if (!c2_f_x->data[(int32_T)c2_d_k - 1]) {
      c2_flat = false;
      c2_exitg1 = true;
    } else {
      c2_c_k++;
    }
  }

  c2_emxFree_boolean_T(chartInstance, &c2_f_x);
  if (!c2_flat) {
    c2_emxInit_sBO2RC5RVZVTbundPSRqHnH(chartInstance, c2_sp, &c2_s, 1,
      &c2_ge_emlrtRTEI);
    c2_st.site = &c2_ue_emlrtRSI;
    for (c2_i4 = 0; c2_i4 < 307200; c2_i4++) {
      chartInstance->c2_b_accumMatrixRe[c2_i4] = chartInstance->
        c2_accumMatrixRe[c2_i4];
    }

    c2_medfilt2(chartInstance, chartInstance->c2_b_accumMatrixRe,
                chartInstance->c2_Hd);
    c2_st.site = &c2_ve_emlrtRSI;
    for (c2_i5 = 0; c2_i5 < 307200; c2_i5++) {
      chartInstance->c2_b_Hd[c2_i5] = chartInstance->c2_Hd[c2_i5];
    }

    c2_imhmax(chartInstance, &c2_st, chartInstance->c2_b_Hd,
              chartInstance->c2_Hd);
    c2_st.site = &c2_we_emlrtRSI;
    for (c2_i6 = 0; c2_i6 < 307200; c2_i6++) {
      chartInstance->c2_c_Hd[c2_i6] = chartInstance->c2_Hd[c2_i6];
    }

    c2_imregionalmax(chartInstance, &c2_st, chartInstance->c2_c_Hd,
                     chartInstance->c2_bw);
    c2_st.site = &c2_xe_emlrtRSI;
    c2_regionprops(chartInstance, &c2_st, chartInstance->c2_bw,
                   chartInstance->c2_accumMatrixRe, c2_s);
    if (c2_s->size[0] != 0) {
      c2_i7 = c2_centers->size[0] * c2_centers->size[1];
      c2_centers->size[0] = c2_s->size[0];
      c2_centers->size[1] = 2;
      c2_st.site = &c2_ni_emlrtRSI;
      c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_centers, c2_i7,
        &c2_sd_emlrtRTEI);
      c2_d1 = (real_T)c2_s->size[0];
      c2_i8 = (int32_T)c2_d1 - 1;
      for (c2_b_idx = 0; c2_b_idx <= c2_i8; c2_b_idx++) {
        c2_c_idx = (real_T)c2_b_idx + 1.0;
        c2_i10 = c2_centers->size[0];
        c2_i11 = (int32_T)c2_c_idx;
        if ((c2_i11 < 1) || (c2_i11 > c2_i10)) {
          emlrtDynamicBoundsCheckR2012b(c2_i11, 1, c2_i10, &c2_kc_emlrtBCI,
            (void *)c2_sp);
        }

        c2_i12 = c2_i11;
        for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
          c2_tmp_data[c2_i13] = c2_i13;
        }

        for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
          c2_iv[c2_i15] = 1 + c2_i15;
        }

        for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
          c2_iv1[c2_i17] = 1 + c2_i17;
        }

        emlrtSubAssignSizeCheckR2012b(&c2_iv[0], 2, &c2_iv1[0], 2,
          &c2_b_emlrtECI, (void *)c2_sp);
        c2_i20 = c2_i12 - 1;
        for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
          c2_i23 = c2_s->size[0];
          c2_i25 = (int32_T)c2_c_idx;
          if ((c2_i25 < 1) || (c2_i25 > c2_i23)) {
            emlrtDynamicBoundsCheckR2012b(c2_i25, 1, c2_i23, &c2_mc_emlrtBCI,
              (void *)c2_sp);
          }

          c2_centers->data[c2_i20 + c2_centers->size[0] * c2_tmp_data[c2_i21]] =
            c2_s->data[c2_i25 - 1].WeightedCentroid[c2_i21];
        }
      }

      c2_d2 = (real_T)c2_centers->size[0];
      c2_i9 = (int32_T)(((-1.0 - c2_d2) + 1.0) / -1.0);
      emlrtForLoopVectorCheckR2021a(c2_d2, -1.0, 1.0, mxDOUBLE_CLASS, c2_i9,
        &c2_rh_emlrtRTEI, (void *)c2_sp);
      c2_d_idx = 0;
      c2_emxInit_real_T(chartInstance, c2_sp, &c2_g_x, 2, &c2_vd_emlrtRTEI);
      while (c2_d_idx <= c2_i9 - 1) {
        c2_c_idx = c2_d2 + -(real_T)c2_d_idx;
        c2_i14 = c2_centers->size[0];
        c2_i16 = (int32_T)c2_c_idx;
        if ((c2_i16 < 1) || (c2_i16 > c2_i14)) {
          emlrtDynamicBoundsCheckR2012b(c2_i16, 1, c2_i14, &c2_lc_emlrtBCI,
            (void *)c2_sp);
        }

        c2_h_x = c2_centers->data[c2_i16 - 1];
        c2_c_b = muDoubleScalarIsNaN(c2_h_x);
        c2_guard1 = false;
        if (c2_c_b) {
          c2_guard1 = true;
        } else {
          c2_i22 = c2_centers->size[0];
          c2_i24 = (int32_T)c2_c_idx;
          if ((c2_i24 < 1) || (c2_i24 > c2_i22)) {
            emlrtDynamicBoundsCheckR2012b(c2_i24, 1, c2_i22, &c2_nc_emlrtBCI,
              (void *)c2_sp);
          }

          c2_i_x = c2_centers->data[(c2_i24 + c2_centers->size[0]) - 1];
          c2_d_b = muDoubleScalarIsNaN(c2_i_x);
          if (c2_d_b) {
            c2_guard1 = true;
          }
        }

        if (c2_guard1) {
          c2_st.site = &c2_ye_emlrtRSI;
          c2_i27 = c2_g_x->size[0] * c2_g_x->size[1];
          c2_g_x->size[0] = c2_centers->size[0];
          c2_g_x->size[1] = c2_centers->size[1];
          c2_b_st.site = &c2_li_emlrtRSI;
          c2_emxEnsureCapacity_real_T(chartInstance, &c2_b_st, c2_g_x, c2_i27,
            &c2_vd_emlrtRTEI);
          c2_b_loop_ub = c2_centers->size[0] * c2_centers->size[1] - 1;
          for (c2_i30 = 0; c2_i30 <= c2_b_loop_ub; c2_i30++) {
            c2_g_x->data[c2_i30] = c2_centers->data[c2_i30];
          }

          c2_e_idx = (int32_T)c2_c_idx;
          c2_b_st.site = &c2_dh_emlrtRSI;
          c2_f_idx = c2_e_idx;
          c2_g_idx = c2_f_idx;
          c2_d3 = (real_T)c2_g_x->size[0];
          c2_n = (int32_T)c2_d3;
          c2_p = true;
          if (c2_g_idx > c2_n) {
            c2_p = false;
          } else {
            c2_j_x = c2_g_idx;
            c2_k_x = c2_j_x;
            if (c2_g_idx != c2_k_x) {
              c2_p = false;
            }
          }

          if (!c2_p) {
            c2_c_y = NULL;
            sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2,
              1, 25), false);
            c2_d_y = NULL;
            sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2,
              1, 25), false);
            sf_mex_call(&c2_b_st, &c2_q_emlrtMCI, "error", 0U, 2U, 14, c2_c_y,
                        14, sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c2_b_st, NULL, "message", 1U, 1U, 14, c2_d_y)));
          }

          c2_b_st.site = &c2_eh_emlrtRSI;
          c2_h_idx = c2_e_idx;
          c2_nrowx = c2_g_x->size[0];
          c2_nrows = c2_nrowx - 1;
          c2_c_st.site = &c2_fh_emlrtRSI;
          for (c2_j = 0; c2_j < 2; c2_j++) {
            c2_b_j = c2_j;
            c2_c_st.site = &c2_gh_emlrtRSI;
            c2_e_a = c2_h_idx;
            c2_e_b = c2_nrows;
            c2_f_a = c2_e_a;
            c2_f_b = c2_e_b;
            if (c2_f_a > c2_f_b) {
              c2_overflow = false;
            } else {
              c2_overflow = (c2_f_b > 2147483646);
            }

            if (c2_overflow) {
              c2_d_st.site = &c2_hc_emlrtRSI;
              c2_check_forloop_overflow_error(chartInstance, &c2_d_st);
            }

            for (c2_b_i = c2_h_idx; c2_b_i <= c2_nrows; c2_b_i++) {
              c2_g_x->data[(c2_b_i + c2_g_x->size[0] * c2_b_j) - 1] =
                c2_g_x->data[c2_b_i + c2_g_x->size[0] * c2_b_j];
            }
          }

          if (!(c2_nrows <= c2_nrowx)) {
            c2_e_y = NULL;
            sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            c2_f_y = NULL;
            sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            sf_mex_call(&c2_b_st, &c2_r_emlrtMCI, "error", 0U, 2U, 14, c2_e_y,
                        14, sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c2_b_st, NULL, "message", 1U, 1U, 14, c2_f_y)));
          }

          c2_b1 = (1 > c2_nrows);
          if (c2_b1) {
            c2_i38 = -1;
          } else {
            c2_i38 = c2_nrows - 1;
          }

          for (c2_i39 = 0; c2_i39 < 2; c2_i39++) {
            c2_f_loop_ub = c2_i38;
            for (c2_i41 = 0; c2_i41 <= c2_f_loop_ub; c2_i41++) {
              c2_g_x->data[c2_i41 + (c2_i38 + 1) * c2_i39] = c2_g_x->data[c2_i41
                + c2_g_x->size[0] * c2_i39];
            }
          }

          c2_i40 = c2_g_x->size[0] * c2_g_x->size[1];
          c2_g_x->size[0] = c2_i38 + 1;
          c2_g_x->size[1] = 2;
          c2_emxEnsureCapacity_real_T(chartInstance, &c2_b_st, c2_g_x, c2_i40,
            &c2_be_emlrtRTEI);
          c2_i43 = c2_centers->size[0] * c2_centers->size[1];
          c2_centers->size[0] = c2_g_x->size[0];
          c2_centers->size[1] = 2;
          c2_st.site = &c2_li_emlrtRSI;
          c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_centers, c2_i43,
            &c2_vd_emlrtRTEI);
          c2_h_loop_ub = c2_g_x->size[0] * c2_g_x->size[1] - 1;
          for (c2_i45 = 0; c2_i45 <= c2_h_loop_ub; c2_i45++) {
            c2_centers->data[c2_i45] = c2_g_x->data[c2_i45];
          }
        }

        c2_d_idx++;
      }

      c2_emxFree_real_T(chartInstance, &c2_g_x);
      c2_b_b = (c2_centers->size[0] == 0);
      if (!c2_b_b) {
        c2_emxInit_real_T1(chartInstance, c2_sp, &c2_ndx, 1, &c2_ie_emlrtRTEI);
        c2_st.site = &c2_af_emlrtRSI;
        c2_i18 = c2_centers->size[0] - 1;
        c2_i19 = c2_ndx->size[0];
        c2_ndx->size[0] = c2_i18 + 1;
        c2_b_st.site = &c2_mi_emlrtRSI;
        c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_ndx, c2_i19,
          &c2_ud_emlrtRTEI);
        c2_loop_ub = c2_i18;
        for (c2_i26 = 0; c2_i26 <= c2_loop_ub; c2_i26++) {
          c2_ndx->data[c2_i26] = c2_centers->data[c2_i26 + c2_centers->size[0]];
        }

        c2_emxInit_real_T1(chartInstance, &c2_st, &c2_b_varargin_2, 1,
                           &c2_wd_emlrtRTEI);
        c2_b_st.site = &c2_af_emlrtRSI;
        c2_b_round(chartInstance, &c2_b_st, c2_ndx);
        c2_i28 = c2_centers->size[0] - 1;
        c2_i29 = c2_b_varargin_2->size[0];
        c2_b_varargin_2->size[0] = c2_i28 + 1;
        c2_b_st.site = &c2_mi_emlrtRSI;
        c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_b_varargin_2,
          c2_i29, &c2_wd_emlrtRTEI);
        c2_c_loop_ub = c2_i28;
        for (c2_i31 = 0; c2_i31 <= c2_c_loop_ub; c2_i31++) {
          c2_b_varargin_2->data[c2_i31] = c2_centers->data[c2_i31];
        }

        c2_emxInit_int32_T(chartInstance, &c2_st, &c2_r, 1, &c2_je_emlrtRTEI);
        c2_b_st.site = &c2_af_emlrtRSI;
        c2_b_round(chartInstance, &c2_b_st, c2_b_varargin_2);
        c2_b_st.site = &c2_le_emlrtRSI;
        c2_eml_sub2ind(chartInstance, &c2_b_st, c2_ndx, c2_b_varargin_2, c2_r);
        c2_i32 = c2_ndx->size[0];
        c2_ndx->size[0] = c2_r->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_ndx, c2_i32,
          &c2_r_emlrtRTEI);
        c2_d_loop_ub = c2_r->size[0] - 1;
        for (c2_i33 = 0; c2_i33 <= c2_d_loop_ub; c2_i33++) {
          c2_ndx->data[c2_i33] = (real_T)c2_r->data[c2_i33];
        }

        c2_emxFree_int32_T(chartInstance, &c2_r);
        c2_i34 = c2_b_varargin_2->size[0];
        c2_b_varargin_2->size[0] = c2_ndx->size[0];
        c2_st.site = &c2_mi_emlrtRSI;
        c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_b_varargin_2,
          c2_i34, &c2_xd_emlrtRTEI);
        c2_e_loop_ub = c2_ndx->size[0] - 1;
        for (c2_i35 = 0; c2_i35 <= c2_e_loop_ub; c2_i35++) {
          c2_i36 = (int32_T)c2_ndx->data[c2_i35];
          if ((c2_i36 < 1) || (c2_i36 > 307200)) {
            emlrtDynamicBoundsCheckR2012b(c2_i36, 1, 307200, &c2_oc_emlrtBCI,
              (void *)c2_sp);
          }

          c2_b_varargin_2->data[c2_i35] = chartInstance->c2_Hd[c2_i36 - 1];
        }

        c2_emxFree_real_T(chartInstance, &c2_ndx);
        c2_i37 = c2_metric->size[0] * c2_metric->size[1];
        c2_metric->size[0] = c2_b_varargin_2->size[0];
        c2_metric->size[1] = 1;
        c2_st.site = &c2_mi_emlrtRSI;
        c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_metric, c2_i37,
          &c2_yd_emlrtRTEI);
        c2_g_loop_ub = c2_b_varargin_2->size[0] - 1;
        for (c2_i42 = 0; c2_i42 <= c2_g_loop_ub; c2_i42++) {
          c2_metric->data[c2_i42] = c2_b_varargin_2->data[c2_i42];
        }

        c2_emxFree_real_T(chartInstance, &c2_b_varargin_2);
        c2_emxInit_real_T(chartInstance, c2_sp, &c2_l_x, 2, &c2_ae_emlrtRTEI);
        c2_st.site = &c2_bf_emlrtRSI;
        c2_i44 = c2_l_x->size[0] * c2_l_x->size[1];
        c2_l_x->size[0] = c2_metric->size[0];
        c2_l_x->size[1] = c2_metric->size[1];
        c2_b_st.site = &c2_ki_emlrtRSI;
        c2_emxEnsureCapacity_real_T(chartInstance, &c2_b_st, c2_l_x, c2_i44,
          &c2_ae_emlrtRTEI);
        c2_i_loop_ub = c2_metric->size[0] * c2_metric->size[1] - 1;
        for (c2_i46 = 0; c2_i46 <= c2_i_loop_ub; c2_i46++) {
          c2_l_x->data[c2_i46] = c2_metric->data[c2_i46];
        }

        c2_emxInit_real_T(chartInstance, &c2_st, &c2_sortIdx, 2,
                          &c2_he_emlrtRTEI);
        c2_emxInit_int32_T1(chartInstance, &c2_st, &c2_iidx, 2, &c2_he_emlrtRTEI);
        c2_b_st.site = &c2_jh_emlrtRSI;
        c2_d_sort(chartInstance, &c2_b_st, c2_l_x, c2_iidx);
        c2_i47 = c2_sortIdx->size[0] * c2_sortIdx->size[1];
        c2_sortIdx->size[0] = c2_iidx->size[0];
        c2_sortIdx->size[1] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_sortIdx, c2_i47,
          &c2_ce_emlrtRTEI);
        c2_j_loop_ub = c2_iidx->size[0] * c2_iidx->size[1] - 1;
        for (c2_i48 = 0; c2_i48 <= c2_j_loop_ub; c2_i48++) {
          c2_sortIdx->data[c2_i48] = (real_T)c2_iidx->data[c2_i48];
        }

        c2_emxFree_int32_T(chartInstance, &c2_iidx);
        c2_i49 = c2_metric->size[0] * c2_metric->size[1];
        c2_metric->size[0] = c2_l_x->size[0];
        c2_metric->size[1] = 1;
        c2_st.site = &c2_ki_emlrtRSI;
        c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_metric, c2_i49,
          &c2_de_emlrtRTEI);
        c2_k_loop_ub = c2_l_x->size[0] * c2_l_x->size[1] - 1;
        for (c2_i50 = 0; c2_i50 <= c2_k_loop_ub; c2_i50++) {
          c2_metric->data[c2_i50] = c2_l_x->data[c2_i50];
        }

        c2_emxFree_real_T(chartInstance, &c2_l_x);
        c2_emxInit_real_T(chartInstance, c2_sp, &c2_b_centers, 2,
                          &c2_ee_emlrtRTEI);
        c2_c_centers = c2_centers->size[0];
        c2_b_sortIdx[0] = c2_sortIdx->size[0];
        c2_i51 = c2_b_centers->size[0] * c2_b_centers->size[1];
        c2_b_centers->size[0] = c2_b_sortIdx[0];
        c2_b_centers->size[1] = 2;
        c2_st.site = &c2_ji_emlrtRSI;
        c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_b_centers, c2_i51,
          &c2_ee_emlrtRTEI);
        for (c2_i52 = 0; c2_i52 < 2; c2_i52++) {
          c2_l_loop_ub = c2_b_sortIdx[0] - 1;
          for (c2_i54 = 0; c2_i54 <= c2_l_loop_ub; c2_i54++) {
            c2_i55 = (int32_T)c2_sortIdx->data[c2_i54];
            if ((c2_i55 < 1) || (c2_i55 > c2_c_centers)) {
              emlrtDynamicBoundsCheckR2012b(c2_i55, 1, c2_c_centers,
                &c2_pc_emlrtBCI, (void *)c2_sp);
            }

            c2_b_centers->data[c2_i54 + c2_b_centers->size[0] * c2_i52] =
              c2_centers->data[(c2_i55 + c2_centers->size[0] * c2_i52) - 1];
          }
        }

        c2_emxFree_real_T(chartInstance, &c2_sortIdx);
        c2_i53 = c2_centers->size[0] * c2_centers->size[1];
        c2_centers->size[0] = c2_b_centers->size[0];
        c2_centers->size[1] = c2_b_centers->size[1];
        c2_st.site = &c2_ji_emlrtRSI;
        c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_centers, c2_i53,
          &c2_fe_emlrtRTEI);
        c2_m_loop_ub = c2_b_centers->size[0] * c2_b_centers->size[1] - 1;
        for (c2_i56 = 0; c2_i56 <= c2_m_loop_ub; c2_i56++) {
          c2_centers->data[c2_i56] = c2_b_centers->data[c2_i56];
        }

        c2_emxFree_real_T(chartInstance, &c2_b_centers);
      }
    }

    c2_emxFree_sBO2RC5RVZVTbundPSRqHnH(chartInstance, &c2_s);
  }
}

static void c2_imhmax(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, real_T c2_c_I[307200], real_T c2_b_J
                      [307200])
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  real_T c2_imSizeT[2];
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_cf_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    c2_b_J[c2_i] = c2_c_I[c2_i] - 0.079999999999999946;
  }

  c2_b_st.site = &c2_df_emlrtRSI;
  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    chartInstance->c2_J[c2_i1] = c2_b_J[c2_i1];
  }

  c2_validateattributes(chartInstance, &c2_b_st, chartInstance->c2_J);
  c2_b_st.site = &c2_ef_emlrtRSI;
  for (c2_i2 = 0; c2_i2 < 307200; c2_i2++) {
    chartInstance->c2_I[c2_i2] = c2_c_I[c2_i2];
  }

  c2_validateattributes(chartInstance, &c2_b_st, chartInstance->c2_I);
  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    c2_imSizeT[c2_i3] = 480.0 + 160.0 * (real_T)c2_i3;
  }

  ippreconstruct_real64(&c2_b_J[0], &c2_c_I[0], &c2_imSizeT[0], 2.0);
}

static void c2_validateattributes(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_d_a[307200])
{
  static char_T c2_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'c', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c2_b_cv1[5] = { 'i', 'n', 'p', 'u', 't' };

  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_k;
  real_T c2_e_x;
  real_T c2_f_x;
  int32_T c2_k;
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  (void)chartInstance;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_gf_emlrtRSI;
  c2_p = true;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 307200)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_e_x = c2_d_a[(int32_T)c2_b_k - 1];
    c2_f_x = c2_e_x;
    c2_b_b = muDoubleScalarIsNaN(c2_f_x);
    c2_b_p = !c2_b_b;
    if (c2_b_p) {
      c2_k++;
    } else {
      c2_p = false;
      c2_exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c2_st, &c2_i_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 2U, 14, c2_c_y, 14, c2_d_y)));
  }
}

static void c2_imregionalmax(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, real_T c2_f_varargin_1[307200], boolean_T c2_BW
  [307200])
{
  static char_T c2_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'g', 'i', 'o', 'n', 'a', 'l', 'm', 'a', 'x', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c2_b_cv2[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c2_b_cv1[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'I', ',' };

  emlrtStack c2_b_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  real_T c2_connSizeT[2];
  real_T c2_imSizeT[2];
  real_T c2_b_k;
  real_T c2_d_k;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  int32_T c2_c_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_k;
  boolean_T c2_conn[9];
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_c_b;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  (void)chartInstance;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_st.site = &c2_hf_emlrtRSI;
  c2_b_st.site = &c2_gf_emlrtRSI;
  c2_p = true;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 307200)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_e_x = c2_f_varargin_1[(int32_T)c2_b_k - 1];
    c2_f_x = c2_e_x;
    c2_b_b = muDoubleScalarIsNaN(c2_f_x);
    c2_b_p = !c2_b_b;
    if (c2_b_p) {
      c2_k++;
    } else {
      c2_p = false;
      c2_exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 35),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c2_b_st, &c2_i_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_b_st, NULL, "message", 1U, 2U, 14, c2_c_y, 14, c2_d_y)));
  }

  c2_st.site = &c2_if_emlrtRSI;
  for (c2_c_k = 0; c2_c_k < 307200; c2_c_k++) {
    c2_d_k = (real_T)c2_c_k + 1.0;
    c2_g_x = c2_f_varargin_1[(int32_T)c2_d_k - 1];
    c2_c_b = muDoubleScalarIsNaN(c2_g_x);
    if (c2_c_b) {
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        19), false);
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_cv2, 10, 0U, 1U, 0U, 2, 1,
        19), false);
      sf_mex_call(&c2_st, &c2_h_emlrtMCI, "error", 0U, 2U, 14, c2_e_y, 14,
                  sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c2_st, NULL, "message", 1U, 1U, 14, c2_f_y)));
    }
  }

  c2_st.site = &c2_jf_emlrtRSI;
  for (c2_i = 0; c2_i < 9; c2_i++) {
    c2_conn[c2_i] = true;
  }

  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    c2_imSizeT[c2_i1] = 480.0 + 160.0 * (real_T)c2_i1;
  }

  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    c2_connSizeT[c2_i2] = 3.0;
  }

  imregionalmax_real64(&c2_f_varargin_1[0], &c2_BW[0], 2.0, &c2_imSizeT[0],
                       &c2_conn[0], 2.0, &c2_connSizeT[0]);
}

static void c2_regionprops(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, boolean_T c2_f_varargin_1[307200], real_T
  c2_b_varargin_2[307200], c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_outstats)
{
  static char_T c2_b_cv[31] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'r', 'e', 'g',
    'i', 'o', 'n', 'p', 'r', 'o', 'p', 's', ':', 's', 'i', 'z', 'e', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h' };

  c2_emxArray_int32_T *c2_b_regionLengths;
  c2_emxArray_int32_T *c2_idxCount;
  c2_emxArray_int32_T *c2_regionLengths;
  c2_emxArray_real_T *c2_regionIndices;
  c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_stats;
  c2_sHtk0WM4OMtyqkehwQYcq2 c2_statsAlreadyComputed;
  c2_s_vX9LV7M75v5ZNol5H5URkE c2_CC;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  real_T c2_imageSize[2];
  real_T c2_b_k;
  real_T c2_b_numObjs;
  real_T c2_b_vIdx;
  real_T c2_c_numObjs;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d_k;
  real_T c2_d_numObjs;
  real_T c2_f_k;
  real_T c2_numObjs;
  real_T c2_x1;
  real_T c2_x2;
  int32_T c2_b_loop_ub;
  int32_T c2_b_stats;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_d_loop_ub;
  int32_T c2_dim;
  int32_T c2_e_k;
  int32_T c2_e_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_k;
  int32_T c2_loop_ub;
  int32_T c2_vIdx;
  boolean_T c2_b;
  boolean_T c2_b_p;
  boolean_T c2_c_p;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_emxInitStruct_s_vX9LV7M75v5ZNol(chartInstance, c2_sp, &c2_CC,
    &c2_pe_emlrtRTEI);
  c2_st.site = &c2_kf_emlrtRSI;
  for (c2_i = 0; c2_i < 307200; c2_i++) {
    chartInstance->c2_c_varargin_1[c2_i] = c2_f_varargin_1[c2_i];
  }

  c2_bwconncomp(chartInstance, &c2_st, chartInstance->c2_c_varargin_1, &c2_CC);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    c2_imageSize[c2_i1] = c2_CC.ImageSize[c2_i1];
  }

  c2_numObjs = c2_CC.NumObjects;
  c2_st.site = &c2_lf_emlrtRSI;
  c2_b_numObjs = c2_numObjs;
  c2_p = false;
  c2_b_p = true;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k < 2)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_x1 = c2_imageSize[(int32_T)c2_b_k - 1];
    c2_x2 = 480.0 + 160.0 * (real_T)((int32_T)c2_b_k - 1);
    c2_c_p = (c2_x1 == c2_x2);
    if (!c2_c_p) {
      c2_b_p = false;
      c2_exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (c2_b_p) {
    c2_p = true;
  }

  if (!c2_p) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c2_st, &c2_j_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_c_y)));
  }

  c2_emxInit_s_R6Og1x0kmqQXSF9Pwa49F(chartInstance, &c2_st, &c2_stats, 1,
    &c2_qe_emlrtRTEI);
  c2_b_st.site = &c2_ng_emlrtRSI;
  c2_c_numObjs = c2_b_numObjs;
  c2_c_st.site = &c2_og_emlrtRSI;
  c2_repmat(chartInstance, &c2_c_st, c2_c_numObjs, c2_outstats);
  c2_st.site = &c2_mf_emlrtRSI;
  c2_initializeStatsStruct(chartInstance, &c2_st, c2_numObjs, c2_stats,
    &c2_statsAlreadyComputed);
  c2_st.site = &c2_nf_emlrtRSI;
  c2_d_numObjs = c2_numObjs;
  c2_statsAlreadyComputed.PixelIdxList = true;
  if (c2_d_numObjs != 0.0) {
    c2_emxInit_real_T1(chartInstance, &c2_st, &c2_regionIndices, 1,
                       &c2_se_emlrtRTEI);
    c2_i2 = c2_regionIndices->size[0];
    c2_regionIndices->size[0] = c2_CC.RegionIndices->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_regionIndices, c2_i2,
      &c2_ke_emlrtRTEI);
    c2_loop_ub = c2_CC.RegionIndices->size[0] - 1;
    for (c2_i4 = 0; c2_i4 <= c2_loop_ub; c2_i4++) {
      c2_regionIndices->data[c2_i4] = c2_CC.RegionIndices->data[c2_i4];
    }

    c2_emxInit_int32_T(chartInstance, &c2_st, &c2_regionLengths, 1,
                       &c2_re_emlrtRTEI);
    c2_i6 = c2_regionLengths->size[0];
    c2_regionLengths->size[0] = c2_CC.RegionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_regionLengths, c2_i6,
      &c2_le_emlrtRTEI);
    c2_b_loop_ub = c2_CC.RegionLengths->size[0] - 1;
    for (c2_i7 = 0; c2_i7 <= c2_b_loop_ub; c2_i7++) {
      c2_regionLengths->data[c2_i7] = c2_CC.RegionLengths->data[c2_i7];
    }

    c2_b_st.site = &c2_rg_emlrtRSI;
    c2_c_st.site = &c2_hg_emlrtRSI;
    c2_dim = 2;
    if ((real_T)c2_regionLengths->size[0] != 1.0) {
      c2_dim = 1;
    }

    c2_emxInit_int32_T(chartInstance, &c2_c_st, &c2_b_regionLengths, 1,
                       &c2_me_emlrtRTEI);
    c2_i12 = c2_b_regionLengths->size[0];
    c2_b_regionLengths->size[0] = c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_regionLengths,
      c2_i12, &c2_me_emlrtRTEI);
    c2_c_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i14 = 0; c2_i14 <= c2_c_loop_ub; c2_i14++) {
      c2_b_regionLengths->data[c2_i14] = c2_regionLengths->data[c2_i14];
    }

    c2_emxInit_int32_T(chartInstance, &c2_c_st, &c2_idxCount, 1,
                       &c2_te_emlrtRTEI);
    c2_d_st.site = &c2_ig_emlrtRSI;
    c2_useConstantDim(chartInstance, &c2_d_st, c2_b_regionLengths, c2_dim,
                      c2_regionLengths);
    c2_i18 = c2_idxCount->size[0];
    c2_idxCount->size[0] = 1 + c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_idxCount, c2_i18,
      &c2_ne_emlrtRTEI);
    c2_idxCount->data[0] = 0;
    c2_d_loop_ub = c2_regionLengths->size[0] - 1;
    c2_emxFree_int32_T(chartInstance, &c2_b_regionLengths);
    for (c2_i21 = 0; c2_i21 <= c2_d_loop_ub; c2_i21++) {
      c2_idxCount->data[c2_i21 + 1] = c2_regionLengths->data[c2_i21];
    }

    c2_emxFree_int32_T(chartInstance, &c2_regionLengths);
    c2_d1 = (real_T)c2_stats->size[0];
    c2_i22 = (int32_T)c2_d1 - 1;
    for (c2_e_k = 0; c2_e_k <= c2_i22; c2_e_k++) {
      c2_f_k = (real_T)c2_e_k + 1.0;
      c2_i23 = c2_idxCount->size[0];
      c2_i24 = (int32_T)c2_f_k;
      if ((c2_i24 < 1) || (c2_i24 > c2_i23)) {
        emlrtDynamicBoundsCheckR2012b(c2_i24, 1, c2_i23, &c2_qc_emlrtBCI, &c2_st);
      }

      c2_i25 = c2_idxCount->data[c2_i24 - 1] + 1;
      c2_i26 = c2_idxCount->size[0];
      c2_i27 = (int32_T)(c2_f_k + 1.0);
      if ((c2_i27 < 1) || (c2_i27 > c2_i26)) {
        emlrtDynamicBoundsCheckR2012b(c2_i27, 1, c2_i26, &c2_rc_emlrtBCI, &c2_st);
      }

      c2_i28 = c2_idxCount->data[c2_i27 - 1];
      c2_b = (c2_i25 > c2_i28);
      if (c2_b) {
        c2_i30 = 0;
        c2_i31 = -1;
      } else {
        c2_i29 = c2_regionIndices->size[0];
        if ((c2_i25 < 1) || (c2_i25 > c2_i29)) {
          emlrtDynamicBoundsCheckR2012b(c2_i25, 1, c2_i29, &c2_qc_emlrtBCI,
            &c2_st);
        }

        c2_i30 = c2_i25 - 1;
        c2_i32 = c2_regionIndices->size[0];
        if ((c2_i28 < 1) || (c2_i28 > c2_i32)) {
          emlrtDynamicBoundsCheckR2012b(c2_i28, 1, c2_i32, &c2_rc_emlrtBCI,
            &c2_st);
        }

        c2_i31 = c2_i28 - 1;
      }

      c2_b_stats = c2_stats->size[0];
      c2_i33 = (int32_T)c2_f_k;
      if ((c2_i33 < 1) || (c2_i33 > c2_b_stats)) {
        emlrtDynamicBoundsCheckR2012b(c2_i33, 1, c2_b_stats, &c2_wc_emlrtBCI,
          &c2_st);
      }

      c2_i34 = c2_i33 - 1;
      c2_i35 = c2_stats->data[c2_i34].PixelIdxList->size[0];
      c2_stats->data[c2_i34].PixelIdxList->size[0] = (c2_i31 - c2_i30) + 1;
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_stats->data[c2_i34]
        .PixelIdxList, c2_i35, &c2_oe_emlrtRTEI);
      c2_e_loop_ub = c2_i31 - c2_i30;
      for (c2_i36 = 0; c2_i36 <= c2_e_loop_ub; c2_i36++) {
        c2_i37 = (int32_T)c2_f_k;
        if ((c2_i37 < 1) || (c2_i37 > c2_b_stats)) {
          emlrtDynamicBoundsCheckR2012b(c2_i37, 1, c2_b_stats, &c2_wc_emlrtBCI,
            &c2_st);
        }

        c2_stats->data[c2_i37 - 1].PixelIdxList->data[c2_i36] =
          c2_regionIndices->data[c2_i30 + c2_i36];
      }
    }

    c2_emxFree_int32_T(chartInstance, &c2_idxCount);
    c2_emxFree_real_T(chartInstance, &c2_regionIndices);
  }

  c2_emxFreeStruct_s_vX9LV7M75v5ZNol(chartInstance, &c2_CC);
  c2_st.site = &c2_of_emlrtRSI;
  for (c2_i3 = 0; c2_i3 < 307200; c2_i3++) {
    chartInstance->c2_varargin_2[c2_i3] = c2_b_varargin_2[c2_i3];
  }

  c2_b_ComputeWeightedCentroid(chartInstance, &c2_st,
    chartInstance->c2_varargin_2, c2_stats, &c2_statsAlreadyComputed);
  c2_st.site = &c2_pf_emlrtRSI;
  c2_d = (real_T)c2_stats->size[0];
  c2_i5 = (int32_T)c2_d - 1;
  for (c2_c_k = 0; c2_c_k <= c2_i5; c2_c_k++) {
    c2_d_k = (real_T)c2_c_k + 1.0;
    c2_i8 = c2_stats->size[0];
    c2_i9 = (int32_T)c2_d_k;
    if ((c2_i9 < 1) || (c2_i9 > c2_i8)) {
      emlrtDynamicBoundsCheckR2012b(c2_i9, 1, c2_i8, &c2_sc_emlrtBCI, &c2_st);
    }

    c2_i10 = c2_outstats->size[0];
    c2_i11 = (int32_T)c2_d_k;
    if ((c2_i11 < 1) || (c2_i11 > c2_i10)) {
      emlrtDynamicBoundsCheckR2012b(c2_i11, 1, c2_i10, &c2_tc_emlrtBCI, &c2_st);
    }

    for (c2_vIdx = 0; c2_vIdx < 2; c2_vIdx++) {
      c2_b_vIdx = (real_T)c2_vIdx + 1.0;
      c2_i13 = c2_stats->size[0];
      c2_i15 = (int32_T)c2_d_k;
      if ((c2_i15 < 1) || (c2_i15 > c2_i13)) {
        emlrtDynamicBoundsCheckR2012b(c2_i15, 1, c2_i13, &c2_vc_emlrtBCI, &c2_st);
      }

      c2_i16 = c2_i15 - 1;
      c2_i17 = c2_outstats->size[0];
      c2_i19 = (int32_T)c2_d_k;
      if ((c2_i19 < 1) || (c2_i19 > c2_i17)) {
        emlrtDynamicBoundsCheckR2012b(c2_i19, 1, c2_i17, &c2_uc_emlrtBCI, &c2_st);
      }

      c2_i20 = c2_i19 - 1;
      c2_outstats->data[c2_i20].WeightedCentroid[(int32_T)c2_b_vIdx - 1] =
        c2_stats->data[c2_i16].WeightedCentroid[(int32_T)c2_b_vIdx - 1];
    }
  }

  c2_emxFree_s_R6Og1x0kmqQXSF9Pwa49F(chartInstance, &c2_stats);
}

static void c2_bwconncomp(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, boolean_T c2_f_varargin_1[307200],
  c2_s_vX9LV7M75v5ZNol5H5URkE *c2_CC)
{
  c2_emxArray_int32_T *c2_b_regionLengths;
  c2_emxArray_int32_T *c2_c_regionLengths;
  c2_emxArray_int32_T *c2_d_regionLengths;
  c2_emxArray_int32_T *c2_e_regionLengths;
  c2_emxArray_int32_T *c2_e_x;
  c2_emxArray_int32_T *c2_endRow;
  c2_emxArray_int32_T *c2_f_x;
  c2_emxArray_int32_T *c2_idxCount;
  c2_emxArray_int32_T *c2_labelsRenumbered;
  c2_emxArray_int32_T *c2_regionLengths;
  c2_emxArray_int32_T *c2_startCol;
  c2_emxArray_int32_T *c2_startRow;
  c2_emxArray_real_T *c2_pixelIdxList;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_f_st;
  emlrtStack c2_g_st;
  emlrtStack c2_st;
  real_T c2_b_col;
  real_T c2_b_k;
  real_T c2_b_y;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d_col;
  real_T c2_numComponents;
  real_T c2_s;
  int32_T c2_iv[1];
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_idx;
  int32_T c2_b_loop_ub;
  int32_T c2_b_node;
  int32_T c2_b_p;
  int32_T c2_b_root_k;
  int32_T c2_b_root_p;
  int32_T c2_b_vlen;
  int32_T c2_c;
  int32_T c2_c_b;
  int32_T c2_c_col;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_c_p;
  int32_T c2_c_vlen;
  int32_T c2_col;
  int32_T c2_column_offset;
  int32_T c2_currentColumn;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_d_loop_ub;
  int32_T c2_d_vlen;
  int32_T c2_dim;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_e_k;
  int32_T c2_e_loop_ub;
  int32_T c2_exitg1;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_k;
  int32_T c2_f_loop_ub;
  int32_T c2_firstRunOnPreviousColumn;
  int32_T c2_firstRunOnThisColumn;
  int32_T c2_g_a;
  int32_T c2_g_b;
  int32_T c2_g_k;
  int32_T c2_g_loop_ub;
  int32_T c2_h_a;
  int32_T c2_h_b;
  int32_T c2_h_k;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i5;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i6;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i7;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i8;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i9;
  int32_T c2_i_a;
  int32_T c2_i_k;
  int32_T c2_i_loop_ub;
  int32_T c2_ib;
  int32_T c2_inb;
  int32_T c2_j_loop_ub;
  int32_T c2_k;
  int32_T c2_k_loop_ub;
  int32_T c2_lastRunOnPreviousColumn;
  int32_T c2_lidx;
  int32_T c2_loop_ub;
  int32_T c2_nextLabel;
  int32_T c2_nfb;
  int32_T c2_nleft;
  int32_T c2_node;
  int32_T c2_numRuns;
  int32_T c2_p;
  int32_T c2_root_k;
  int32_T c2_root_p;
  int32_T c2_row;
  int32_T c2_rowidx;
  int32_T c2_runCounter;
  int32_T c2_vlen;
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_d_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_wf_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_f_st.prev = &c2_e_st;
  c2_f_st.tls = c2_e_st.tls;
  c2_g_st.prev = &c2_f_st;
  c2_g_st.tls = c2_f_st.tls;
  c2_numRuns = 0;
  for (c2_col = 0; c2_col < 640; c2_col++) {
    c2_b_col = (real_T)c2_col + 1.0;
    if (c2_f_varargin_1[480 * ((int32_T)c2_b_col - 1)]) {
      c2_numRuns++;
    }

    for (c2_k = 0; c2_k < 479; c2_k++) {
      c2_b_k = (real_T)c2_k + 2.0;
      if (c2_f_varargin_1[((int32_T)c2_b_k + 480 * ((int32_T)c2_b_col - 1)) - 1]
          && (!c2_f_varargin_1[((int32_T)(c2_b_k - 1.0) + 480 * ((int32_T)
             c2_b_col - 1)) - 1])) {
        c2_numRuns++;
      }
    }
  }

  c2_emxInit_int32_T(chartInstance, &c2_st, &c2_regionLengths, 1,
                     &c2_mf_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_st, &c2_startRow, 1, &c2_of_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_st, &c2_endRow, 1, &c2_pf_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_st, &c2_startCol, 1, &c2_qf_emlrtRTEI);
  if (c2_numRuns == 0) {
    c2_startRow->size[0] = 0;
    c2_endRow->size[0] = 0;
    c2_startCol->size[0] = 0;
    c2_regionLengths->size[0] = 0;
    c2_numRuns = 0;
  } else {
    c2_i = c2_startRow->size[0];
    c2_d = (real_T)c2_numRuns;
    if (!(c2_d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c2_d, &c2_emlrtDCI, &c2_st);
    }

    c2_startRow->size[0] = (int32_T)muDoubleScalarFloor(c2_d);
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_startRow, c2_i,
      &c2_ue_emlrtRTEI);
    c2_i1 = c2_endRow->size[0];
    c2_endRow->size[0] = c2_numRuns;
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_endRow, c2_i1,
      &c2_ve_emlrtRTEI);
    c2_i4 = c2_startCol->size[0];
    c2_startCol->size[0] = c2_numRuns;
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_startCol, c2_i4,
      &c2_we_emlrtRTEI);
    c2_b_st.site = &c2_xf_emlrtRSI;
    c2_runCounter = 1;
    for (c2_c_col = 0; c2_c_col < 640; c2_c_col++) {
      c2_d_col = (real_T)c2_c_col + 1.0;
      c2_row = 1;
      while (c2_row <= 480) {
        while ((c2_row <= 480) && (!c2_f_varargin_1[(c2_row + 480 * ((int32_T)
                  c2_d_col - 1)) - 1])) {
          c2_row++;
        }

        if ((c2_row <= 480) && c2_f_varargin_1[(c2_row + 480 * ((int32_T)
              c2_d_col - 1)) - 1]) {
          c2_i8 = c2_startCol->size[0];
          if ((c2_runCounter < 1) || (c2_runCounter > c2_i8)) {
            emlrtDynamicBoundsCheckR2012b(c2_runCounter, 1, c2_i8,
              &c2_xc_emlrtBCI, &c2_b_st);
          }

          c2_startCol->data[c2_runCounter - 1] = (int32_T)c2_d_col;
          c2_i11 = c2_startRow->size[0];
          if ((c2_runCounter < 1) || (c2_runCounter > c2_i11)) {
            emlrtDynamicBoundsCheckR2012b(c2_runCounter, 1, c2_i11,
              &c2_ad_emlrtBCI, &c2_b_st);
          }

          c2_startRow->data[c2_runCounter - 1] = c2_row;
          while ((c2_row <= 480) && c2_f_varargin_1[(c2_row + 480 * ((int32_T)
                   c2_d_col - 1)) - 1]) {
            c2_row++;
          }

          c2_i16 = c2_endRow->size[0];
          if ((c2_runCounter < 1) || (c2_runCounter > c2_i16)) {
            emlrtDynamicBoundsCheckR2012b(c2_runCounter, 1, c2_i16,
              &c2_dd_emlrtBCI, &c2_b_st);
          }

          c2_endRow->data[c2_runCounter - 1] = c2_row - 1;
          c2_runCounter++;
        }
      }
    }

    c2_i6 = c2_regionLengths->size[0];
    c2_regionLengths->size[0] = c2_numRuns;
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_regionLengths, c2_i6,
      &c2_xe_emlrtRTEI);
    c2_loop_ub = c2_numRuns - 1;
    for (c2_i7 = 0; c2_i7 <= c2_loop_ub; c2_i7++) {
      c2_regionLengths->data[c2_i7] = 0;
    }

    c2_d_k = 1;
    c2_currentColumn = 2;
    c2_nextLabel = 1;
    c2_firstRunOnPreviousColumn = -1;
    c2_lastRunOnPreviousColumn = 0;
    c2_firstRunOnThisColumn = 1;
    while (c2_d_k <= c2_numRuns) {
      c2_i12 = c2_startCol->size[0];
      if ((c2_d_k < 1) || (c2_d_k > c2_i12)) {
        emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i12, &c2_yc_emlrtBCI, &c2_st);
      }

      if (c2_startCol->data[c2_d_k - 1] == c2_currentColumn) {
        c2_firstRunOnPreviousColumn = c2_firstRunOnThisColumn;
        c2_firstRunOnThisColumn = c2_d_k;
        c2_lastRunOnPreviousColumn = c2_d_k;
        c2_i20 = c2_startCol->size[0];
        if ((c2_d_k < 1) || (c2_d_k > c2_i20)) {
          emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i20, &c2_cd_emlrtBCI,
            &c2_st);
        }

        c2_currentColumn = c2_startCol->data[c2_d_k - 1] + 1;
      } else {
        c2_i18 = c2_startCol->size[0];
        if ((c2_d_k < 1) || (c2_d_k > c2_i18)) {
          emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i18, &c2_bd_emlrtBCI,
            &c2_st);
        }

        if (c2_startCol->data[c2_d_k - 1] > c2_currentColumn) {
          c2_firstRunOnPreviousColumn = -1;
          c2_lastRunOnPreviousColumn = 0;
          c2_firstRunOnThisColumn = c2_d_k;
          c2_i22 = c2_startCol->size[0];
          if ((c2_d_k < 1) || (c2_d_k > c2_i22)) {
            emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i22, &c2_fd_emlrtBCI,
              &c2_st);
          }

          c2_currentColumn = c2_startCol->data[c2_d_k - 1] + 1;
        }
      }

      if (c2_firstRunOnPreviousColumn >= 0) {
        for (c2_p = c2_firstRunOnPreviousColumn; c2_p <
             c2_lastRunOnPreviousColumn; c2_p++) {
          c2_i24 = c2_endRow->size[0];
          if ((c2_d_k < 1) || (c2_d_k > c2_i24)) {
            emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i24, &c2_ld_emlrtBCI,
              &c2_st);
          }

          c2_i26 = c2_startRow->size[0];
          if ((c2_p < 1) || (c2_p > c2_i26)) {
            emlrtDynamicBoundsCheckR2012b(c2_p, 1, c2_i26, &c2_md_emlrtBCI,
              &c2_st);
          }

          if (c2_endRow->data[c2_d_k - 1] >= c2_startRow->data[c2_p - 1] - 1) {
            c2_i28 = c2_startRow->size[0];
            if ((c2_d_k < 1) || (c2_d_k > c2_i28)) {
              emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i28, &c2_nd_emlrtBCI,
                &c2_st);
            }

            c2_i30 = c2_endRow->size[0];
            if ((c2_p < 1) || (c2_p > c2_i30)) {
              emlrtDynamicBoundsCheckR2012b(c2_p, 1, c2_i30, &c2_od_emlrtBCI,
                &c2_st);
            }

            if (c2_startRow->data[c2_d_k - 1] <= c2_endRow->data[c2_p - 1] + 1)
            {
              c2_i33 = c2_regionLengths->size[0];
              if ((c2_d_k < 1) || (c2_d_k > c2_i33)) {
                emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i33, &c2_pd_emlrtBCI,
                  &c2_st);
              }

              if (c2_regionLengths->data[c2_d_k - 1] == 0) {
                c2_i36 = c2_regionLengths->size[0];
                if ((c2_p < 1) || (c2_p > c2_i36)) {
                  emlrtDynamicBoundsCheckR2012b(c2_p, 1, c2_i36, &c2_sd_emlrtBCI,
                    &c2_st);
                }

                c2_i39 = c2_regionLengths->size[0];
                if ((c2_d_k < 1) || (c2_d_k > c2_i39)) {
                  emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i39,
                    &c2_td_emlrtBCI, &c2_st);
                }

                c2_regionLengths->data[c2_d_k - 1] = c2_regionLengths->data[c2_p
                  - 1];
                c2_nextLabel++;
              } else {
                c2_i35 = c2_regionLengths->size[0];
                if ((c2_d_k < 1) || (c2_d_k > c2_i35)) {
                  emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i35,
                    &c2_qd_emlrtBCI, &c2_st);
                }

                c2_i38 = c2_regionLengths->size[0];
                if ((c2_p < 1) || (c2_p > c2_i38)) {
                  emlrtDynamicBoundsCheckR2012b(c2_p, 1, c2_i38, &c2_rd_emlrtBCI,
                    &c2_st);
                }

                if (c2_regionLengths->data[c2_d_k - 1] != c2_regionLengths->
                    data[c2_p - 1]) {
                  c2_b_st.site = &c2_yf_emlrtRSI;
                  c2_g_k = c2_d_k;
                  c2_b_p = c2_p;
                  c2_c_st.site = &c2_ag_emlrtRSI;
                  c2_node = c2_g_k;
                  c2_root_k = c2_node;
                  do {
                    c2_exitg1 = 0;
                    c2_i45 = c2_regionLengths->size[0];
                    if ((c2_root_k < 1) || (c2_root_k > c2_i45)) {
                      emlrtDynamicBoundsCheckR2012b(c2_root_k, 1, c2_i45,
                        &c2_vd_emlrtBCI, &c2_c_st);
                    }

                    if (c2_root_k != c2_regionLengths->data[c2_root_k - 1]) {
                      c2_i48 = c2_regionLengths->size[0];
                      c2_i51 = c2_regionLengths->size[0];
                      if ((c2_root_k < 1) || (c2_root_k > c2_i51)) {
                        emlrtDynamicBoundsCheckR2012b(c2_root_k, 1, c2_i51,
                          &c2_be_emlrtBCI, &c2_c_st);
                      }

                      c2_i53 = c2_regionLengths->data[c2_root_k - 1];
                      if ((c2_i53 < 1) || (c2_i53 > c2_i48)) {
                        emlrtDynamicBoundsCheckR2012b(c2_i53, 1, c2_i48,
                          &c2_be_emlrtBCI, &c2_c_st);
                      }

                      c2_i54 = c2_regionLengths->size[0];
                      if ((c2_root_k < 1) || (c2_root_k > c2_i54)) {
                        emlrtDynamicBoundsCheckR2012b(c2_root_k, 1, c2_i54,
                          &c2_ce_emlrtBCI, &c2_c_st);
                      }

                      c2_regionLengths->data[c2_root_k - 1] =
                        c2_regionLengths->data[c2_i53 - 1];
                      c2_i57 = c2_regionLengths->size[0];
                      if ((c2_root_k < 1) || (c2_root_k > c2_i57)) {
                        emlrtDynamicBoundsCheckR2012b(c2_root_k, 1, c2_i57,
                          &c2_de_emlrtBCI, &c2_c_st);
                      }

                      c2_root_k = c2_regionLengths->data[c2_root_k - 1];
                    } else {
                      c2_exitg1 = 1;
                    }
                  } while (c2_exitg1 == 0);

                  c2_c_st.site = &c2_bg_emlrtRSI;
                  c2_b_node = c2_b_p;
                  c2_root_p = c2_b_node;
                  do {
                    c2_exitg1 = 0;
                    c2_i56 = c2_regionLengths->size[0];
                    if ((c2_root_p < 1) || (c2_root_p > c2_i56)) {
                      emlrtDynamicBoundsCheckR2012b(c2_root_p, 1, c2_i56,
                        &c2_vd_emlrtBCI, &c2_c_st);
                    }

                    if (c2_root_p != c2_regionLengths->data[c2_root_p - 1]) {
                      c2_i59 = c2_regionLengths->size[0];
                      c2_i60 = c2_regionLengths->size[0];
                      if ((c2_root_p < 1) || (c2_root_p > c2_i60)) {
                        emlrtDynamicBoundsCheckR2012b(c2_root_p, 1, c2_i60,
                          &c2_be_emlrtBCI, &c2_c_st);
                      }

                      c2_i61 = c2_regionLengths->data[c2_root_p - 1];
                      if ((c2_i61 < 1) || (c2_i61 > c2_i59)) {
                        emlrtDynamicBoundsCheckR2012b(c2_i61, 1, c2_i59,
                          &c2_be_emlrtBCI, &c2_c_st);
                      }

                      c2_i63 = c2_regionLengths->size[0];
                      if ((c2_root_p < 1) || (c2_root_p > c2_i63)) {
                        emlrtDynamicBoundsCheckR2012b(c2_root_p, 1, c2_i63,
                          &c2_ce_emlrtBCI, &c2_c_st);
                      }

                      c2_regionLengths->data[c2_root_p - 1] =
                        c2_regionLengths->data[c2_i61 - 1];
                      c2_i66 = c2_regionLengths->size[0];
                      if ((c2_root_p < 1) || (c2_root_p > c2_i66)) {
                        emlrtDynamicBoundsCheckR2012b(c2_root_p, 1, c2_i66,
                          &c2_de_emlrtBCI, &c2_c_st);
                      }

                      c2_root_p = c2_regionLengths->data[c2_root_p - 1];
                    } else {
                      c2_exitg1 = 1;
                    }
                  } while (c2_exitg1 == 0);

                  if (c2_root_k != c2_root_p) {
                    c2_c_st.site = &c2_cg_emlrtRSI;
                    c2_b_root_k = c2_root_k;
                    c2_b_root_p = c2_root_p;
                    c2_h_k = c2_g_k;
                    c2_c_p = c2_b_p;
                    if (c2_b_root_p < c2_b_root_k) {
                      c2_i65 = c2_regionLengths->size[0];
                      if ((c2_b_root_k < 1) || (c2_b_root_k > c2_i65)) {
                        emlrtDynamicBoundsCheckR2012b(c2_b_root_k, 1, c2_i65,
                          &c2_fe_emlrtBCI, &c2_c_st);
                      }

                      c2_regionLengths->data[c2_b_root_k - 1] = c2_b_root_p;
                      c2_i69 = c2_regionLengths->size[0];
                      if ((c2_h_k < 1) || (c2_h_k > c2_i69)) {
                        emlrtDynamicBoundsCheckR2012b(c2_h_k, 1, c2_i69,
                          &c2_he_emlrtBCI, &c2_c_st);
                      }

                      c2_regionLengths->data[c2_h_k - 1] = c2_b_root_p;
                    } else {
                      c2_i64 = c2_regionLengths->size[0];
                      if ((c2_b_root_p < 1) || (c2_b_root_p > c2_i64)) {
                        emlrtDynamicBoundsCheckR2012b(c2_b_root_p, 1, c2_i64,
                          &c2_ee_emlrtBCI, &c2_c_st);
                      }

                      c2_regionLengths->data[c2_b_root_p - 1] = c2_b_root_k;
                      c2_i68 = c2_regionLengths->size[0];
                      if ((c2_c_p < 1) || (c2_c_p > c2_i68)) {
                        emlrtDynamicBoundsCheckR2012b(c2_c_p, 1, c2_i68,
                          &c2_ge_emlrtBCI, &c2_c_st);
                      }

                      c2_regionLengths->data[c2_c_p - 1] = c2_b_root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      c2_i23 = c2_regionLengths->size[0];
      if ((c2_d_k < 1) || (c2_d_k > c2_i23)) {
        emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i23, &c2_gd_emlrtBCI, &c2_st);
      }

      if (c2_regionLengths->data[c2_d_k - 1] == 0) {
        c2_i25 = c2_regionLengths->size[0];
        if ((c2_d_k < 1) || (c2_d_k > c2_i25)) {
          emlrtDynamicBoundsCheckR2012b(c2_d_k, 1, c2_i25, &c2_kd_emlrtBCI,
            &c2_st);
        }

        c2_regionLengths->data[c2_d_k - 1] = c2_nextLabel;
        c2_nextLabel++;
      }

      c2_d_k++;
    }
  }

  if (c2_numRuns == 0) {
    c2_CC->Connectivity = 8.0;
    for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
      c2_CC->ImageSize[c2_i3] = 480.0 + 160.0 * (real_T)c2_i3;
    }

    c2_CC->NumObjects = 0.0;
    c2_CC->RegionIndices->size[0] = 0;
    c2_i5 = c2_CC->RegionLengths->size[0];
    c2_CC->RegionLengths->size[0] = 1;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_CC->RegionLengths,
      c2_i5, &c2_af_emlrtRTEI);
    c2_CC->RegionLengths->data[0] = 0;
  } else {
    c2_emxInit_int32_T(chartInstance, c2_sp, &c2_labelsRenumbered, 1,
                       &c2_nf_emlrtRTEI);
    c2_i2 = c2_labelsRenumbered->size[0];
    c2_labelsRenumbered->size[0] = c2_regionLengths->size[0];
    c2_st.site = &c2_xi_emlrtRSI;
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_labelsRenumbered,
      c2_i2, &c2_ye_emlrtRTEI);
    c2_numComponents = 0.0;
    c2_st.site = &c2_vf_emlrtRSI;
    c2_b = c2_numRuns;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }

    for (c2_c_k = 1; c2_c_k - 1 < c2_numRuns; c2_c_k++) {
      c2_e_k = c2_c_k;
      c2_i10 = c2_regionLengths->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i10)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i10, &c2_ed_emlrtBCI, (void *)
          c2_sp);
      }

      if (c2_regionLengths->data[c2_e_k - 1] == c2_e_k) {
        c2_numComponents++;
        c2_i14 = c2_labelsRenumbered->size[0];
        if ((c2_e_k < 1) || (c2_e_k > c2_i14)) {
          emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i14, &c2_jd_emlrtBCI,
            (void *)c2_sp);
        }

        c2_labelsRenumbered->data[c2_e_k - 1] = (int32_T)c2_numComponents;
      }

      c2_i13 = c2_labelsRenumbered->size[0];
      c2_i15 = c2_regionLengths->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i15)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i15, &c2_hd_emlrtBCI, (void *)
          c2_sp);
      }

      c2_i19 = c2_regionLengths->data[c2_e_k - 1];
      if ((c2_i19 < 1) || (c2_i19 > c2_i13)) {
        emlrtDynamicBoundsCheckR2012b(c2_i19, 1, c2_i13, &c2_hd_emlrtBCI, (void *)
          c2_sp);
      }

      c2_i21 = c2_labelsRenumbered->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i21)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i21, &c2_id_emlrtBCI, (void *)
          c2_sp);
      }

      c2_labelsRenumbered->data[c2_e_k - 1] = c2_labelsRenumbered->data[c2_i19 -
        1];
    }

    c2_i9 = c2_regionLengths->size[0];
    if (c2_numComponents != (real_T)(int32_T)muDoubleScalarFloor
        (c2_numComponents)) {
      emlrtIntegerCheckR2012b(c2_numComponents, &c2_b_emlrtDCI, (void *)c2_sp);
    }

    c2_regionLengths->size[0] = (int32_T)c2_numComponents;
    c2_st.site = &c2_wi_emlrtRSI;
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_regionLengths, c2_i9,
      &c2_bf_emlrtRTEI);
    if (c2_numComponents != (real_T)(int32_T)muDoubleScalarFloor
        (c2_numComponents)) {
      emlrtIntegerCheckR2012b(c2_numComponents, &c2_b_emlrtDCI, (void *)c2_sp);
    }

    c2_b_loop_ub = (int32_T)c2_numComponents - 1;
    for (c2_i17 = 0; c2_i17 <= c2_b_loop_ub; c2_i17++) {
      c2_regionLengths->data[c2_i17] = 0;
    }

    c2_st.site = &c2_uf_emlrtRSI;
    c2_c_b = c2_numRuns;
    c2_d_b = c2_c_b;
    if (1 > c2_d_b) {
      c2_b_overflow = false;
    } else {
      c2_b_overflow = (c2_d_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }

    for (c2_f_k = 1; c2_f_k - 1 < c2_numRuns; c2_f_k++) {
      c2_e_k = c2_f_k;
      c2_i27 = c2_labelsRenumbered->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i27)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i27, &c2_ud_emlrtBCI, (void *)
          c2_sp);
      }

      c2_b_idx = c2_labelsRenumbered->data[c2_e_k - 1];
      c2_i29 = c2_regionLengths->size[0];
      if ((c2_b_idx < 1) || (c2_b_idx > c2_i29)) {
        emlrtDynamicBoundsCheckR2012b(c2_b_idx, 1, c2_i29, &c2_wd_emlrtBCI,
          (void *)c2_sp);
      }

      c2_i31 = c2_endRow->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i31)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i31, &c2_xd_emlrtBCI, (void *)
          c2_sp);
      }

      c2_i32 = c2_startRow->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i32)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i32, &c2_yd_emlrtBCI, (void *)
          c2_sp);
      }

      c2_i34 = c2_regionLengths->size[0];
      if ((c2_b_idx < 1) || (c2_b_idx > c2_i34)) {
        emlrtDynamicBoundsCheckR2012b(c2_b_idx, 1, c2_i34, &c2_ae_emlrtBCI,
          (void *)c2_sp);
      }

      c2_regionLengths->data[c2_b_idx - 1] = ((c2_regionLengths->data[c2_b_idx -
        1] + c2_endRow->data[c2_e_k - 1]) - c2_startRow->data[c2_e_k - 1]) + 1;
    }

    c2_st.site = &c2_tf_emlrtRSI;
    c2_b_st.site = &c2_yb_emlrtRSI;
    c2_c_st.site = &c2_ac_emlrtRSI;
    c2_vlen = c2_regionLengths->size[0];
    c2_d_st.site = &c2_bc_emlrtRSI;
    c2_b_vlen = c2_vlen;
    c2_emxInit_int32_T(chartInstance, &c2_d_st, &c2_b_regionLengths, 1,
                       &c2_hf_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_d_st, &c2_c_regionLengths, 1,
                       &c2_ef_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_d_st, &c2_d_regionLengths, 1,
                       &c2_gf_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_d_st, &c2_e_regionLengths, 1,
                       &c2_cf_emlrtRTEI);
    if ((c2_regionLengths->size[0] == 0) || (c2_b_vlen == 0)) {
      c2_b_y = 0.0;
    } else {
      c2_e_st.site = &c2_cc_emlrtRSI;
      c2_c_vlen = c2_b_vlen;
      c2_f_st.site = &c2_dc_emlrtRSI;
      c2_d_vlen = c2_c_vlen;
      if (c2_d_vlen < 4096) {
        c2_i37 = c2_e_regionLengths->size[0];
        c2_e_regionLengths->size[0] = c2_regionLengths->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, &c2_f_st, c2_e_regionLengths,
          c2_i37, &c2_cf_emlrtRTEI);
        c2_c_loop_ub = c2_regionLengths->size[0] - 1;
        for (c2_i40 = 0; c2_i40 <= c2_c_loop_ub; c2_i40++) {
          c2_e_regionLengths->data[c2_i40] = c2_regionLengths->data[c2_i40];
        }

        c2_g_st.site = &c2_ec_emlrtRSI;
        c2_b_y = c2_b_sumColumnB(chartInstance, &c2_g_st, c2_e_regionLengths,
          c2_d_vlen);
      } else {
        c2_d_a = c2_d_vlen;
        c2_nfb = c2_div_nzp_s32(chartInstance, c2_d_a, 4096, 0, 1U, 0, 0);
        c2_inb = c2_nfb << 12;
        c2_lidx = c2_inb;
        c2_nleft = c2_d_vlen - c2_inb;
        c2_i41 = c2_c_regionLengths->size[0];
        c2_c_regionLengths->size[0] = c2_regionLengths->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, &c2_f_st, c2_c_regionLengths,
          c2_i41, &c2_ef_emlrtRTEI);
        c2_d_loop_ub = c2_regionLengths->size[0] - 1;
        for (c2_i42 = 0; c2_i42 <= c2_d_loop_ub; c2_i42++) {
          c2_c_regionLengths->data[c2_i42] = c2_regionLengths->data[c2_i42];
        }

        c2_s = c2_sumColumnB4(chartInstance, c2_c_regionLengths, 1);
        for (c2_ib = 1; c2_ib < c2_nfb; c2_ib++) {
          c2_i46 = c2_d_regionLengths->size[0];
          c2_d_regionLengths->size[0] = c2_regionLengths->size[0];
          c2_emxEnsureCapacity_int32_T(chartInstance, &c2_f_st,
            c2_d_regionLengths, c2_i46, &c2_gf_emlrtRTEI);
          c2_e_loop_ub = c2_regionLengths->size[0] - 1;
          for (c2_i49 = 0; c2_i49 <= c2_e_loop_ub; c2_i49++) {
            c2_d_regionLengths->data[c2_i49] = c2_regionLengths->data[c2_i49];
          }

          c2_s += c2_sumColumnB4(chartInstance, c2_d_regionLengths, 1 + (c2_ib <<
            12));
        }

        if (c2_nleft > 0) {
          c2_i47 = c2_b_regionLengths->size[0];
          c2_b_regionLengths->size[0] = c2_regionLengths->size[0];
          c2_emxEnsureCapacity_int32_T(chartInstance, &c2_f_st,
            c2_b_regionLengths, c2_i47, &c2_hf_emlrtRTEI);
          c2_g_loop_ub = c2_regionLengths->size[0] - 1;
          for (c2_i52 = 0; c2_i52 <= c2_g_loop_ub; c2_i52++) {
            c2_b_regionLengths->data[c2_i52] = c2_regionLengths->data[c2_i52];
          }

          c2_g_st.site = &c2_dg_emlrtRSI;
          c2_s += c2_c_sumColumnB(chartInstance, &c2_g_st, c2_b_regionLengths,
            c2_nleft, c2_lidx + 1);
        }

        c2_b_y = c2_s;
      }
    }

    c2_emxFree_int32_T(chartInstance, &c2_e_regionLengths);
    c2_emxFree_int32_T(chartInstance, &c2_d_regionLengths);
    c2_emxFree_int32_T(chartInstance, &c2_c_regionLengths);
    c2_emxFree_int32_T(chartInstance, &c2_b_regionLengths);
    c2_emxInit_real_T1(chartInstance, &c2_d_st, &c2_pixelIdxList, 1,
                       &c2_lf_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_d_st, &c2_e_x, 1, &c2_ff_emlrtRTEI);
    if (!(c2_b_y >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c2_b_y, &c2_d_emlrtDCI, (void *)c2_sp);
    }

    c2_d1 = c2_b_y;
    if (c2_d1 != (real_T)(int32_T)muDoubleScalarFloor(c2_d1)) {
      emlrtIntegerCheckR2012b(c2_d1, &c2_c_emlrtDCI, (void *)c2_sp);
    }

    c2_iv[0] = (int32_T)c2_d1;
    c2_i43 = c2_pixelIdxList->size[0];
    c2_pixelIdxList->size[0] = c2_iv[0];
    c2_st.site = &c2_hj_emlrtRSI;
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_pixelIdxList, c2_i43,
      &c2_df_emlrtRTEI);
    c2_st.site = &c2_sf_emlrtRSI;
    c2_i44 = c2_e_x->size[0];
    c2_e_x->size[0] = c2_regionLengths->size[0];
    c2_b_st.site = &c2_vi_emlrtRSI;
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_b_st, c2_e_x, c2_i44,
      &c2_ff_emlrtRTEI);
    c2_f_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i50 = 0; c2_i50 <= c2_f_loop_ub; c2_i50++) {
      c2_e_x->data[c2_i50] = c2_regionLengths->data[c2_i50];
    }

    c2_b_st.site = &c2_hg_emlrtRSI;
    c2_dim = 2;
    if ((real_T)c2_e_x->size[0] != 1.0) {
      c2_dim = 1;
    }

    c2_emxInit_int32_T(chartInstance, &c2_b_st, &c2_f_x, 1, &c2_me_emlrtRTEI);
    c2_i55 = c2_f_x->size[0];
    c2_f_x->size[0] = c2_e_x->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_b_st, c2_f_x, c2_i55,
      &c2_me_emlrtRTEI);
    c2_h_loop_ub = c2_e_x->size[0] - 1;
    for (c2_i58 = 0; c2_i58 <= c2_h_loop_ub; c2_i58++) {
      c2_f_x->data[c2_i58] = c2_e_x->data[c2_i58];
    }

    c2_emxInit_int32_T(chartInstance, &c2_b_st, &c2_idxCount, 1,
                       &c2_if_emlrtRTEI);
    c2_c_st.site = &c2_ig_emlrtRSI;
    c2_useConstantDim(chartInstance, &c2_c_st, c2_f_x, c2_dim, c2_e_x);
    c2_i62 = c2_idxCount->size[0];
    c2_idxCount->size[0] = 1 + c2_e_x->size[0];
    c2_st.site = &c2_vi_emlrtRSI;
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_idxCount, c2_i62,
      &c2_if_emlrtRTEI);
    c2_idxCount->data[0] = 0;
    c2_i_loop_ub = c2_e_x->size[0] - 1;
    c2_emxFree_int32_T(chartInstance, &c2_f_x);
    for (c2_i67 = 0; c2_i67 <= c2_i_loop_ub; c2_i67++) {
      c2_idxCount->data[c2_i67 + 1] = c2_e_x->data[c2_i67];
    }

    c2_emxFree_int32_T(chartInstance, &c2_e_x);
    c2_st.site = &c2_rf_emlrtRSI;
    c2_e_b = c2_numRuns;
    c2_f_b = c2_e_b;
    if (1 > c2_f_b) {
      c2_c_overflow = false;
    } else {
      c2_c_overflow = (c2_f_b > 2147483646);
    }

    if (c2_c_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }

    for (c2_i_k = 1; c2_i_k - 1 < c2_numRuns; c2_i_k++) {
      c2_e_k = c2_i_k;
      c2_i70 = c2_startCol->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i70)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i70, &c2_ie_emlrtBCI, (void *)
          c2_sp);
      }

      c2_e_a = c2_startCol->data[c2_e_k - 1] - 1;
      c2_c = c2_e_a;
      c2_f_a = c2_c;
      c2_column_offset = c2_f_a * 480;
      c2_i73 = c2_labelsRenumbered->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i73)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i73, &c2_je_emlrtBCI, (void *)
          c2_sp);
      }

      c2_b_idx = c2_labelsRenumbered->data[c2_e_k - 1];
      c2_i75 = c2_startRow->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i75)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i75, &c2_ke_emlrtBCI, (void *)
          c2_sp);
      }

      c2_i77 = c2_startRow->data[c2_e_k - 1];
      c2_i78 = c2_endRow->size[0];
      if ((c2_e_k < 1) || (c2_e_k > c2_i78)) {
        emlrtDynamicBoundsCheckR2012b(c2_e_k, 1, c2_i78, &c2_le_emlrtBCI, (void *)
          c2_sp);
      }

      c2_i80 = c2_endRow->data[c2_e_k - 1];
      c2_st.site = &c2_qf_emlrtRSI;
      c2_g_a = c2_i77;
      c2_g_b = c2_i80;
      c2_h_a = c2_g_a;
      c2_h_b = c2_g_b;
      if (c2_h_a > c2_h_b) {
        c2_d_overflow = false;
      } else {
        c2_d_overflow = (c2_h_b > 2147483646);
      }

      if (c2_d_overflow) {
        c2_b_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
      }

      for (c2_rowidx = c2_i77; c2_rowidx <= c2_i80; c2_rowidx++) {
        c2_i81 = c2_idxCount->size[0];
        if ((c2_b_idx < 1) || (c2_b_idx > c2_i81)) {
          emlrtDynamicBoundsCheckR2012b(c2_b_idx, 1, c2_i81, &c2_me_emlrtBCI,
            (void *)c2_sp);
        }

        c2_i_a = c2_idxCount->data[c2_b_idx - 1] + 1;
        c2_b_c = c2_i_a;
        c2_i82 = c2_idxCount->size[0];
        if ((c2_b_idx < 1) || (c2_b_idx > c2_i82)) {
          emlrtDynamicBoundsCheckR2012b(c2_b_idx, 1, c2_i82, &c2_ne_emlrtBCI,
            (void *)c2_sp);
        }

        c2_idxCount->data[c2_b_idx - 1] = c2_b_c;
        c2_i83 = c2_pixelIdxList->size[0];
        c2_i84 = c2_idxCount->size[0];
        if ((c2_b_idx < 1) || (c2_b_idx > c2_i84)) {
          emlrtDynamicBoundsCheckR2012b(c2_b_idx, 1, c2_i84, &c2_oe_emlrtBCI,
            (void *)c2_sp);
        }

        c2_i85 = c2_idxCount->data[c2_b_idx - 1];
        if ((c2_i85 < 1) || (c2_i85 > c2_i83)) {
          emlrtDynamicBoundsCheckR2012b(c2_i85, 1, c2_i83, &c2_oe_emlrtBCI,
            (void *)c2_sp);
        }

        c2_pixelIdxList->data[c2_i85 - 1] = (real_T)(c2_rowidx +
          c2_column_offset);
      }
    }

    c2_emxFree_int32_T(chartInstance, &c2_idxCount);
    c2_emxFree_int32_T(chartInstance, &c2_labelsRenumbered);
    c2_CC->Connectivity = 8.0;
    for (c2_i71 = 0; c2_i71 < 2; c2_i71++) {
      c2_CC->ImageSize[c2_i71] = 480.0 + 160.0 * (real_T)c2_i71;
    }

    c2_CC->NumObjects = c2_numComponents;
    c2_i72 = c2_CC->RegionIndices->size[0];
    c2_CC->RegionIndices->size[0] = c2_pixelIdxList->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_sp, c2_CC->RegionIndices,
      c2_i72, &c2_jf_emlrtRTEI);
    c2_j_loop_ub = c2_pixelIdxList->size[0] - 1;
    for (c2_i74 = 0; c2_i74 <= c2_j_loop_ub; c2_i74++) {
      c2_CC->RegionIndices->data[c2_i74] = c2_pixelIdxList->data[c2_i74];
    }

    c2_emxFree_real_T(chartInstance, &c2_pixelIdxList);
    c2_i76 = c2_CC->RegionLengths->size[0];
    c2_CC->RegionLengths->size[0] = c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_CC->RegionLengths,
      c2_i76, &c2_kf_emlrtRTEI);
    c2_k_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i79 = 0; c2_i79 <= c2_k_loop_ub; c2_i79++) {
      c2_CC->RegionLengths->data[c2_i79] = c2_regionLengths->data[c2_i79];
    }
  }

  c2_emxFree_int32_T(chartInstance, &c2_startCol);
  c2_emxFree_int32_T(chartInstance, &c2_endRow);
  c2_emxFree_int32_T(chartInstance, &c2_startRow);
  c2_emxFree_int32_T(chartInstance, &c2_regionLengths);
}

static real_T c2_b_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_e_x, int32_T c2_vlen)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_d_y;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_b_vlen;
  int32_T c2_b_vstart;
  int32_T c2_c_b;
  int32_T c2_c_k;
  int32_T c2_c_vlen;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_h_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i_k;
  int32_T c2_inb;
  int32_T c2_k;
  int32_T c2_lidx;
  int32_T c2_nfb;
  int32_T c2_nleft;
  int32_T c2_vstart;
  boolean_T c2_b_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  if (c2_vlen <= 1024) {
    c2_st.site = &c2_fc_emlrtRSI;
    c2_b_vlen = c2_vlen - 1;
    c2_b_y = (real_T)c2_e_x->data[0];
    c2_i = c2_b_vlen;
    c2_b_st.site = &c2_gc_emlrtRSI;
    c2_b = c2_i;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_c_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
    }

    for (c2_d_k = 1; c2_d_k - 1 < c2_i; c2_d_k++) {
      c2_e_k = c2_d_k;
      c2_b_y += (real_T)c2_e_x->data[c2_e_k];
    }
  } else {
    c2_d_a = c2_vlen;
    c2_nfb = c2_div_nzp_s32(chartInstance, c2_d_a, 1024, 0, 1U, 0, 0);
    c2_inb = c2_nfb << 10;
    c2_st.site = &c2_eg_emlrtRSI;
    c2_b_y = (real_T)c2_e_x->data[0];
    c2_b_st.site = &c2_gc_emlrtRSI;
    for (c2_k = 1; c2_k - 1 < 1023; c2_k++) {
      c2_c_k = c2_k;
      c2_b_y += (real_T)c2_e_x->data[c2_c_k];
    }

    for (c2_b_k = 1; c2_b_k < c2_nfb; c2_b_k++) {
      c2_st.site = &c2_fg_emlrtRSI;
      c2_vstart = c2_b_k << 10;
      c2_c_y = (real_T)c2_e_x->data[c2_vstart];
      c2_b_st.site = &c2_gc_emlrtRSI;
      for (c2_f_k = 1; c2_f_k - 1 < 1023; c2_f_k++) {
        c2_g_k = c2_f_k;
        c2_c_y += (real_T)c2_e_x->data[c2_vstart + c2_g_k];
      }

      c2_b_y += c2_c_y;
    }

    if (c2_vlen > c2_inb) {
      c2_nleft = c2_vlen - c2_inb;
      c2_lidx = c2_inb;
      c2_st.site = &c2_gg_emlrtRSI;
      c2_c_vlen = c2_nleft - 1;
      c2_b_vstart = c2_lidx;
      c2_d_y = (real_T)c2_e_x->data[c2_b_vstart];
      c2_i1 = c2_c_vlen;
      c2_b_st.site = &c2_gc_emlrtRSI;
      c2_c_b = c2_i1;
      c2_d_b = c2_c_b;
      if (1 > c2_d_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_d_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_c_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
      }

      for (c2_h_k = 1; c2_h_k - 1 < c2_i1; c2_h_k++) {
        c2_i_k = c2_h_k;
        c2_d_y += (real_T)c2_e_x->data[c2_b_vstart + c2_i_k];
      }

      c2_b_y += c2_d_y;
    }
  }

  return c2_b_y;
}

static real_T c2_sumColumnB4(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_e_x, int32_T c2_vstart)
{
  real_T c2_psum1;
  real_T c2_psum2;
  real_T c2_psum3;
  real_T c2_psum4;
  int32_T c2_b_k;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_k;
  (void)chartInstance;
  c2_i2 = c2_vstart + 1023;
  c2_i3 = c2_vstart + 2047;
  c2_i4 = c2_vstart + 3071;
  c2_psum1 = (real_T)c2_e_x->data[c2_vstart - 1];
  c2_psum2 = (real_T)c2_e_x->data[c2_i2];
  c2_psum3 = (real_T)c2_e_x->data[c2_i3];
  c2_psum4 = (real_T)c2_e_x->data[c2_i4];
  for (c2_k = 0; c2_k < 1023; c2_k++) {
    c2_b_k = c2_k + 1;
    c2_psum1 += (real_T)c2_e_x->data[(c2_vstart + c2_b_k) - 1];
    c2_psum2 += (real_T)c2_e_x->data[c2_i2 + c2_b_k];
    c2_psum3 += (real_T)c2_e_x->data[c2_i3 + c2_b_k];
    c2_psum4 += (real_T)c2_e_x->data[c2_i4 + c2_b_k];
  }

  return (c2_psum1 + c2_psum2) + (c2_psum3 + c2_psum4);
}

static real_T c2_c_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_e_x, int32_T c2_vlen, int32_T
  c2_vstart)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_d_y;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_b_vlen;
  int32_T c2_b_vstart;
  int32_T c2_c_b;
  int32_T c2_c_k;
  int32_T c2_c_vlen;
  int32_T c2_c_vstart;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_d_vstart;
  int32_T c2_e_k;
  int32_T c2_e_vstart;
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_h_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i_k;
  int32_T c2_inb;
  int32_T c2_k;
  int32_T c2_lidx;
  int32_T c2_nfb;
  int32_T c2_nleft;
  boolean_T c2_b_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  if (c2_vlen <= 1024) {
    c2_st.site = &c2_fc_emlrtRSI;
    c2_b_vlen = c2_vlen - 1;
    c2_b_vstart = c2_vstart - 1;
    c2_b_y = (real_T)c2_e_x->data[c2_b_vstart];
    c2_i = c2_b_vlen;
    c2_b_st.site = &c2_gc_emlrtRSI;
    c2_b = c2_i;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_c_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
    }

    for (c2_d_k = 1; c2_d_k - 1 < c2_i; c2_d_k++) {
      c2_e_k = c2_d_k;
      c2_b_y += (real_T)c2_e_x->data[c2_b_vstart + c2_e_k];
    }
  } else {
    c2_d_a = c2_vlen;
    c2_nfb = c2_div_nzp_s32(chartInstance, c2_d_a, 1024, 0, 1U, 0, 0);
    c2_inb = c2_nfb << 10;
    c2_st.site = &c2_eg_emlrtRSI;
    c2_c_vstart = c2_vstart - 1;
    c2_b_y = (real_T)c2_e_x->data[c2_c_vstart];
    c2_b_st.site = &c2_gc_emlrtRSI;
    for (c2_k = 1; c2_k - 1 < 1023; c2_k++) {
      c2_c_k = c2_k;
      c2_b_y += (real_T)c2_e_x->data[c2_c_vstart + c2_c_k];
    }

    for (c2_b_k = 1; c2_b_k < c2_nfb; c2_b_k++) {
      c2_st.site = &c2_fg_emlrtRSI;
      c2_d_vstart = (c2_vstart + (c2_b_k << 10)) - 1;
      c2_c_y = (real_T)c2_e_x->data[c2_d_vstart];
      c2_b_st.site = &c2_gc_emlrtRSI;
      for (c2_f_k = 1; c2_f_k - 1 < 1023; c2_f_k++) {
        c2_g_k = c2_f_k;
        c2_c_y += (real_T)c2_e_x->data[c2_d_vstart + c2_g_k];
      }

      c2_b_y += c2_c_y;
    }

    if (c2_vlen > c2_inb) {
      c2_nleft = c2_vlen - c2_inb;
      c2_lidx = c2_vstart + c2_inb;
      c2_st.site = &c2_gg_emlrtRSI;
      c2_c_vlen = c2_nleft - 1;
      c2_e_vstart = c2_lidx - 1;
      c2_d_y = (real_T)c2_e_x->data[c2_e_vstart];
      c2_i1 = c2_c_vlen;
      c2_b_st.site = &c2_gc_emlrtRSI;
      c2_c_b = c2_i1;
      c2_d_b = c2_c_b;
      if (1 > c2_d_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_d_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_c_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
      }

      for (c2_h_k = 1; c2_h_k - 1 < c2_i1; c2_h_k++) {
        c2_i_k = c2_h_k;
        c2_d_y += (real_T)c2_e_x->data[c2_e_vstart + c2_i_k];
      }

      c2_b_y += c2_d_y;
    }
  }

  return c2_b_y;
}

static void c2_useConstantDim(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_varargin_2, int32_T
  c2_varargin_3, c2_emxArray_int32_T *c2_varargout_1)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_k;
  int32_T c2_loop_ub;
  int32_T c2_nx;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  if (1 == c2_varargin_3) {
    c2_st.site = &c2_jg_emlrtRSI;
    c2_i1 = c2_varargout_1->size[0];
    c2_varargout_1->size[0] = c2_b_varargin_2->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_st, c2_varargout_1, c2_i1,
      &c2_rf_emlrtRTEI);
    c2_b_loop_ub = c2_b_varargin_2->size[0] - 1;
    for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
      c2_varargout_1->data[c2_i3] = c2_b_varargin_2->data[c2_i3];
    }

    c2_b_st.site = &c2_kg_emlrtRSI;
    if (c2_varargout_1->size[0] != 0) {
      c2_c_st.site = &c2_lg_emlrtRSI;
      c2_nx = c2_varargout_1->size[0] - 1;
      if (!((real_T)c2_varargout_1->size[0] == 1.0)) {
        c2_i4 = c2_nx;
        c2_d_st.site = &c2_mg_emlrtRSI;
        c2_b = c2_i4;
        c2_b_b = c2_b;
        if (1 > c2_b_b) {
          c2_overflow = false;
        } else {
          c2_overflow = (c2_b_b > 2147483646);
        }

        if (c2_overflow) {
          c2_e_st.site = &c2_hc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
        }

        for (c2_k = 1; c2_k - 1 < c2_i4; c2_k++) {
          c2_b_k = c2_k;
          c2_varargout_1->data[c2_b_k] += c2_varargout_1->data[c2_b_k - 1];
        }
      }
    }
  } else {
    c2_i = c2_varargout_1->size[0];
    c2_varargout_1->size[0] = c2_b_varargin_2->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_varargout_1, c2_i,
      &c2_rf_emlrtRTEI);
    c2_loop_ub = c2_b_varargin_2->size[0] - 1;
    for (c2_i2 = 0; c2_i2 <= c2_loop_ub; c2_i2++) {
      c2_varargout_1->data[c2_i2] = c2_b_varargin_2->data[c2_i2];
    }
  }
}

static void c2_repmat(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, real_T c2_f_varargin_1,
                      c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_b)
{
  c2_emxArray_boolean_T *c2_tile;
  c2_sBO2RC5RVZVTbundPSRqHnH c2_s;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  int32_T c2_outsize[2];
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_loop_ub;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_emxInit_boolean_T1(chartInstance, c2_sp, &c2_tile, 1, &c2_sf_emlrtRTEI);
  c2_st.site = &c2_pg_emlrtRSI;
  c2_assertValidSizeArg(chartInstance, &c2_st, c2_f_varargin_1);
  c2_i = c2_tile->size[0];
  c2_tile->size[0] = (int32_T)c2_f_varargin_1;
  c2_st.site = &c2_nj_emlrtRSI;
  c2_emxEnsureCapacity_boolean_T1(chartInstance, &c2_st, c2_tile, c2_i,
    &c2_sf_emlrtRTEI);
  c2_loop_ub = (int32_T)c2_f_varargin_1 - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_tile->data[c2_i1] = false;
  }

  c2_outsize[0] = c2_tile->size[0];
  if (!((real_T)c2_outsize[0] == (real_T)c2_tile->size[0])) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c2_sp, &c2_k_emlrtMCI, "error", 0U, 1U, 14, c2_b_y);
  }

  c2_emxFree_boolean_T(chartInstance, &c2_tile);
  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    c2_s.WeightedCentroid[c2_i2] = 0.0;
  }

  c2_i3 = c2_b->size[0];
  c2_b->size[0] = c2_outsize[0];
  c2_st.site = &c2_wj_emlrtRSI;
  c2_emxEnsureCapacity_sBO2RC5RVZVTb(chartInstance, &c2_st, c2_b, c2_i3,
    &c2_tf_emlrtRTEI);
  c2_b_loop_ub = c2_outsize[0] - 1;
  for (c2_i4 = 0; c2_i4 <= c2_b_loop_ub; c2_i4++) {
    c2_b->data[c2_i4] = c2_s;
  }
}

static void c2_assertValidSizeArg(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_f_varargin_1)
{
  static char_T c2_b_cv[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n',
    'p', 'u', 't' };

  static char_T c2_b_cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  real_T c2_arg;
  real_T c2_b_arg;
  real_T c2_e_x;
  real_T c2_g_varargin_1;
  real_T c2_n;
  int32_T c2_b_u;
  int32_T c2_u;
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_p;
  (void)chartInstance;
  c2_arg = c2_f_varargin_1;
  if (c2_arg != c2_arg) {
    c2_p = false;
  } else {
    c2_e_x = c2_arg;
    c2_b = muDoubleScalarIsInf(c2_e_x);
    if (c2_b) {
      c2_p = false;
    } else {
      c2_p = true;
    }
  }

  if (c2_p) {
    c2_b_arg = c2_f_varargin_1;
    if (c2_b_arg > 2.147483647E+9) {
      c2_b_p = false;
    } else {
      c2_b_p = true;
    }

    if (c2_b_p) {
      c2_b_b = true;
    } else {
      c2_b_b = false;
    }
  } else {
    c2_b_b = false;
  }

  if (!c2_b_b) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c2_u = MIN_int32_T;
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
    c2_b_u = MAX_int32_T;
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_call(c2_sp, &c2_l_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 3U, 14, c2_c_y, 14, c2_d_y, 14, c2_g_y)));
  }

  c2_g_varargin_1 = c2_f_varargin_1;
  if (c2_g_varargin_1 <= 0.0) {
    c2_n = 0.0;
  } else {
    c2_n = c2_g_varargin_1;
  }

  if (!(c2_n <= 2.147483647E+9)) {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    sf_mex_call(c2_sp, &c2_m_emlrtMCI, "error", 0U, 2U, 14, c2_e_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_f_y)));
  }
}

static void c2_initializeStatsStruct(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_numObjs,
  c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_stats, c2_sHtk0WM4OMtyqkehwQYcq2
  *c2_statsAlreadyComputed)
{
  c2_emxArray_boolean_T *c2_tile;
  c2_s_R6Og1x0kmqQXSF9Pwa49FD c2_statsOneObj;
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  real_T c2_f_varargin_1;
  int32_T c2_outsize[2];
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_loop_ub;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_emxInitStruct_s_R6Og1x0kmqQXSF9(chartInstance, c2_sp, &c2_statsOneObj,
    &c2_vf_emlrtRTEI);
  c2_statsAlreadyComputed->Area = false;
  c2_statsOneObj.Area = 0.0;
  c2_statsAlreadyComputed->Centroid = false;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_statsOneObj.Centroid[c2_i] = 0.0;
  }

  c2_statsAlreadyComputed->BoundingBox = false;
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    c2_statsOneObj.BoundingBox[c2_i1] = 0.0;
  }

  c2_statsAlreadyComputed->MajorAxisLength = false;
  c2_statsOneObj.MajorAxisLength = 0.0;
  c2_statsAlreadyComputed->MinorAxisLength = false;
  c2_statsOneObj.MinorAxisLength = 0.0;
  c2_statsAlreadyComputed->Eccentricity = false;
  c2_statsOneObj.Eccentricity = 0.0;
  c2_statsAlreadyComputed->Orientation = false;
  c2_statsOneObj.Orientation = 0.0;
  c2_statsAlreadyComputed->Image = false;
  c2_statsOneObj.Image.size[0] = 0;
  c2_statsOneObj.Image.size[1] = 0;
  c2_statsAlreadyComputed->FilledImage = false;
  c2_statsOneObj.FilledImage.size[0] = 0;
  c2_statsOneObj.FilledImage.size[1] = 0;
  c2_statsAlreadyComputed->FilledArea = false;
  c2_statsOneObj.FilledArea = 0.0;
  c2_statsAlreadyComputed->EulerNumber = false;
  c2_statsOneObj.EulerNumber = 0.0;
  c2_statsAlreadyComputed->Extrema = false;
  for (c2_i2 = 0; c2_i2 < 16; c2_i2++) {
    c2_statsOneObj.Extrema[c2_i2] = 0.0;
  }

  c2_statsAlreadyComputed->EquivDiameter = false;
  c2_statsOneObj.EquivDiameter = 0.0;
  c2_statsAlreadyComputed->Extent = false;
  c2_statsOneObj.Extent = 0.0;
  c2_statsAlreadyComputed->PixelIdxList = false;
  c2_statsOneObj.PixelIdxList->size[0] = 0;
  c2_statsAlreadyComputed->PixelList = false;
  c2_statsOneObj.PixelList->size[0] = 0;
  c2_statsOneObj.PixelList->size[1] = 2;
  c2_statsAlreadyComputed->Perimeter = false;
  c2_statsOneObj.Perimeter = 0.0;
  c2_statsAlreadyComputed->Circularity = false;
  c2_statsOneObj.Circularity = 0.0;
  c2_statsAlreadyComputed->PixelValues = false;
  c2_statsOneObj.PixelValues->size[0] = 0;
  c2_statsAlreadyComputed->WeightedCentroid = false;
  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    c2_statsOneObj.WeightedCentroid[c2_i3] = 0.0;
  }

  c2_statsAlreadyComputed->MeanIntensity = false;
  c2_statsOneObj.MeanIntensity = 0.0;
  c2_statsAlreadyComputed->MinIntensity = false;
  c2_statsOneObj.MinIntensity = 0.0;
  c2_statsAlreadyComputed->MaxIntensity = false;
  c2_statsOneObj.MaxIntensity = 0.0;
  c2_statsAlreadyComputed->SubarrayIdx = false;
  c2_statsOneObj.SubarrayIdx.size[0] = 1;
  c2_statsOneObj.SubarrayIdx.size[1] = 0;
  for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
    c2_statsOneObj.SubarrayIdxLengths[c2_i4] = 0.0;
  }

  c2_emxInit_boolean_T1(chartInstance, c2_sp, &c2_tile, 1, &c2_sf_emlrtRTEI);
  c2_st.site = &c2_qg_emlrtRSI;
  c2_f_varargin_1 = c2_numObjs;
  c2_b_st.site = &c2_pg_emlrtRSI;
  c2_assertValidSizeArg(chartInstance, &c2_b_st, c2_f_varargin_1);
  c2_i5 = c2_tile->size[0];
  c2_tile->size[0] = (int32_T)c2_f_varargin_1;
  c2_emxEnsureCapacity_boolean_T1(chartInstance, &c2_st, c2_tile, c2_i5,
    &c2_sf_emlrtRTEI);
  c2_loop_ub = (int32_T)c2_f_varargin_1 - 1;
  for (c2_i6 = 0; c2_i6 <= c2_loop_ub; c2_i6++) {
    c2_tile->data[c2_i6] = false;
  }

  c2_outsize[0] = c2_tile->size[0];
  if (!((real_T)c2_outsize[0] == (real_T)c2_tile->size[0])) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c2_st, &c2_k_emlrtMCI, "error", 0U, 1U, 14, c2_b_y);
  }

  c2_emxFree_boolean_T(chartInstance, &c2_tile);
  c2_i7 = c2_stats->size[0];
  c2_stats->size[0] = c2_outsize[0];
  c2_emxEnsureCapacity_s_R6Og1x0kmqQ(chartInstance, &c2_st, c2_stats, c2_i7,
    &c2_uf_emlrtRTEI);
  c2_b_loop_ub = c2_outsize[0] - 1;
  for (c2_i8 = 0; c2_i8 <= c2_b_loop_ub; c2_i8++) {
    c2_emxCopyStruct_s_R6Og1x0kmqQXSF9(chartInstance, &c2_st, &c2_stats->
      data[c2_i8], &c2_statsOneObj, &c2_uf_emlrtRTEI);
  }

  c2_emxFreeStruct_s_R6Og1x0kmqQXSF9(chartInstance, &c2_statsOneObj);
}

static void c2_ComputeWeightedCentroid(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_c_I[307200],
  c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_stats, c2_sHtk0WM4OMtyqkehwQYcq2
  c2_statsAlreadyComputed, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_b_stats,
  c2_sHtk0WM4OMtyqkehwQYcq2 *c2_b_statsAlreadyComputed)
{
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_loop_ub;
  c2_i = c2_b_stats->size[0];
  c2_b_stats->size[0] = c2_stats->size[0];
  c2_emxEnsureCapacity_s_R6Og1x0kmqQ(chartInstance, c2_sp, c2_b_stats, c2_i,
    &c2_wf_emlrtRTEI);
  c2_loop_ub = c2_stats->size[0] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_emxCopyStruct_s_R6Og1x0kmqQXSF9(chartInstance, c2_sp, &c2_b_stats->
      data[c2_i1], &c2_stats->data[c2_i1], &c2_wf_emlrtRTEI);
  }

  *c2_b_statsAlreadyComputed = c2_statsAlreadyComputed;
  for (c2_i2 = 0; c2_i2 < 307200; c2_i2++) {
    chartInstance->c2_b_I[c2_i2] = c2_c_I[c2_i2];
  }

  c2_b_ComputeWeightedCentroid(chartInstance, c2_sp, chartInstance->c2_b_I,
    c2_b_stats, c2_b_statsAlreadyComputed);
}

static real_T c2_b_sum(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x)
{
  static char_T c2_b_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  c2_emxArray_real_T *c2_f_x;
  c2_emxArray_real_T *c2_g_x;
  c2_emxArray_real_T *c2_h_x;
  c2_emxArray_real_T *c2_i_x;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_f_st;
  emlrtStack c2_st;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_y;
  real_T c2_s;
  int32_T c2_b_loop_ub;
  int32_T c2_b_vlen;
  int32_T c2_c_loop_ub;
  int32_T c2_c_vlen;
  int32_T c2_d_a;
  int32_T c2_d_loop_ub;
  int32_T c2_d_vlen;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_ib;
  int32_T c2_inb;
  int32_T c2_lidx;
  int32_T c2_loop_ub;
  int32_T c2_nfb;
  int32_T c2_nleft;
  int32_T c2_vlen;
  boolean_T c2_b;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_f_st.prev = &c2_e_st;
  c2_f_st.tls = c2_e_st.tls;
  c2_st.site = &c2_yb_emlrtRSI;
  if ((c2_e_x->size[0] == 1) || ((real_T)c2_e_x->size[0] != 1.0)) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c2_st, &c2_p_emlrtMCI, "error", 0U, 2U, 14, c2_c_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_d_y)));
  }

  c2_b_st.site = &c2_ac_emlrtRSI;
  c2_vlen = c2_e_x->size[0];
  c2_c_st.site = &c2_bc_emlrtRSI;
  c2_b_vlen = c2_vlen;
  c2_emxInit_real_T1(chartInstance, &c2_c_st, &c2_f_x, 1, &c2_hf_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_c_st, &c2_g_x, 1, &c2_ef_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_c_st, &c2_h_x, 1, &c2_gf_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_c_st, &c2_i_x, 1, &c2_cf_emlrtRTEI);
  if ((c2_e_x->size[0] == 0) || (c2_b_vlen == 0)) {
    c2_b_y = 0.0;
  } else {
    c2_d_st.site = &c2_cc_emlrtRSI;
    c2_c_vlen = c2_b_vlen;
    c2_e_st.site = &c2_dc_emlrtRSI;
    c2_d_vlen = c2_c_vlen;
    if (c2_d_vlen < 4096) {
      c2_i = c2_i_x->size[0];
      c2_i_x->size[0] = c2_e_x->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_e_st, c2_i_x, c2_i,
        &c2_cf_emlrtRTEI);
      c2_loop_ub = c2_e_x->size[0] - 1;
      for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
        c2_i_x->data[c2_i1] = c2_e_x->data[c2_i1];
      }

      c2_f_st.site = &c2_ec_emlrtRSI;
      c2_b_y = c2_d_sumColumnB(chartInstance, &c2_f_st, c2_i_x, c2_d_vlen);
    } else {
      c2_d_a = c2_d_vlen;
      c2_nfb = c2_div_nzp_s32(chartInstance, c2_d_a, 4096, 0, 1U, 0, 0);
      c2_inb = c2_nfb << 12;
      c2_lidx = c2_inb;
      c2_nleft = c2_d_vlen - c2_inb;
      c2_i2 = c2_g_x->size[0];
      c2_g_x->size[0] = c2_e_x->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_e_st, c2_g_x, c2_i2,
        &c2_ef_emlrtRTEI);
      c2_b_loop_ub = c2_e_x->size[0] - 1;
      for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
        c2_g_x->data[c2_i3] = c2_e_x->data[c2_i3];
      }

      c2_s = c2_b_sumColumnB4(chartInstance, c2_g_x, 1);
      for (c2_ib = 1; c2_ib < c2_nfb; c2_ib++) {
        c2_i4 = c2_h_x->size[0];
        c2_h_x->size[0] = c2_e_x->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, &c2_e_st, c2_h_x, c2_i4,
          &c2_gf_emlrtRTEI);
        c2_c_loop_ub = c2_e_x->size[0] - 1;
        for (c2_i6 = 0; c2_i6 <= c2_c_loop_ub; c2_i6++) {
          c2_h_x->data[c2_i6] = c2_e_x->data[c2_i6];
        }

        c2_s += c2_b_sumColumnB4(chartInstance, c2_h_x, 1 + (c2_ib << 12));
      }

      if (c2_nleft > 0) {
        c2_i5 = c2_f_x->size[0];
        c2_f_x->size[0] = c2_e_x->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, &c2_e_st, c2_f_x, c2_i5,
          &c2_hf_emlrtRTEI);
        c2_d_loop_ub = c2_e_x->size[0] - 1;
        for (c2_i7 = 0; c2_i7 <= c2_d_loop_ub; c2_i7++) {
          c2_f_x->data[c2_i7] = c2_e_x->data[c2_i7];
        }

        c2_f_st.site = &c2_dg_emlrtRSI;
        c2_s += c2_e_sumColumnB(chartInstance, &c2_f_st, c2_f_x, c2_nleft,
          c2_lidx + 1);
      }

      c2_b_y = c2_s;
    }
  }

  c2_emxFree_real_T(chartInstance, &c2_i_x);
  c2_emxFree_real_T(chartInstance, &c2_h_x);
  c2_emxFree_real_T(chartInstance, &c2_g_x);
  c2_emxFree_real_T(chartInstance, &c2_f_x);
  return c2_b_y;
}

static real_T c2_d_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x, int32_T c2_vlen)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_d_y;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_b_vlen;
  int32_T c2_b_vstart;
  int32_T c2_c_b;
  int32_T c2_c_k;
  int32_T c2_c_vlen;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_h_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i_k;
  int32_T c2_inb;
  int32_T c2_k;
  int32_T c2_lidx;
  int32_T c2_nfb;
  int32_T c2_nleft;
  int32_T c2_vstart;
  boolean_T c2_b_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  if (c2_vlen <= 1024) {
    c2_st.site = &c2_fc_emlrtRSI;
    c2_b_vlen = c2_vlen - 1;
    c2_b_y = c2_e_x->data[0];
    c2_i = c2_b_vlen;
    c2_b_st.site = &c2_gc_emlrtRSI;
    c2_b = c2_i;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_c_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
    }

    for (c2_d_k = 1; c2_d_k - 1 < c2_i; c2_d_k++) {
      c2_e_k = c2_d_k;
      c2_b_y += c2_e_x->data[c2_e_k];
    }
  } else {
    c2_d_a = c2_vlen;
    c2_nfb = c2_div_nzp_s32(chartInstance, c2_d_a, 1024, 0, 1U, 0, 0);
    c2_inb = c2_nfb << 10;
    c2_st.site = &c2_eg_emlrtRSI;
    c2_b_y = c2_e_x->data[0];
    c2_b_st.site = &c2_gc_emlrtRSI;
    for (c2_k = 1; c2_k - 1 < 1023; c2_k++) {
      c2_c_k = c2_k;
      c2_b_y += c2_e_x->data[c2_c_k];
    }

    for (c2_b_k = 1; c2_b_k < c2_nfb; c2_b_k++) {
      c2_st.site = &c2_fg_emlrtRSI;
      c2_vstart = c2_b_k << 10;
      c2_c_y = c2_e_x->data[c2_vstart];
      c2_b_st.site = &c2_gc_emlrtRSI;
      for (c2_f_k = 1; c2_f_k - 1 < 1023; c2_f_k++) {
        c2_g_k = c2_f_k;
        c2_c_y += c2_e_x->data[c2_vstart + c2_g_k];
      }

      c2_b_y += c2_c_y;
    }

    if (c2_vlen > c2_inb) {
      c2_nleft = c2_vlen - c2_inb;
      c2_lidx = c2_inb;
      c2_st.site = &c2_gg_emlrtRSI;
      c2_c_vlen = c2_nleft - 1;
      c2_b_vstart = c2_lidx;
      c2_d_y = c2_e_x->data[c2_b_vstart];
      c2_i1 = c2_c_vlen;
      c2_b_st.site = &c2_gc_emlrtRSI;
      c2_c_b = c2_i1;
      c2_d_b = c2_c_b;
      if (1 > c2_d_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_d_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_c_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
      }

      for (c2_h_k = 1; c2_h_k - 1 < c2_i1; c2_h_k++) {
        c2_i_k = c2_h_k;
        c2_d_y += c2_e_x->data[c2_b_vstart + c2_i_k];
      }

      c2_b_y += c2_d_y;
    }
  }

  return c2_b_y;
}

static real_T c2_b_sumColumnB4(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_e_x, int32_T c2_vstart)
{
  real_T c2_psum1;
  real_T c2_psum2;
  real_T c2_psum3;
  real_T c2_psum4;
  int32_T c2_b_k;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_k;
  (void)chartInstance;
  c2_i2 = c2_vstart + 1023;
  c2_i3 = c2_vstart + 2047;
  c2_i4 = c2_vstart + 3071;
  c2_psum1 = c2_e_x->data[c2_vstart - 1];
  c2_psum2 = c2_e_x->data[c2_i2];
  c2_psum3 = c2_e_x->data[c2_i3];
  c2_psum4 = c2_e_x->data[c2_i4];
  for (c2_k = 0; c2_k < 1023; c2_k++) {
    c2_b_k = c2_k + 1;
    c2_psum1 += c2_e_x->data[(c2_vstart + c2_b_k) - 1];
    c2_psum2 += c2_e_x->data[c2_i2 + c2_b_k];
    c2_psum3 += c2_e_x->data[c2_i3 + c2_b_k];
    c2_psum4 += c2_e_x->data[c2_i4 + c2_b_k];
  }

  return (c2_psum1 + c2_psum2) + (c2_psum3 + c2_psum4);
}

static real_T c2_e_sumColumnB(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x, int32_T c2_vlen, int32_T
  c2_vstart)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_d_y;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_b_vlen;
  int32_T c2_b_vstart;
  int32_T c2_c_b;
  int32_T c2_c_k;
  int32_T c2_c_vlen;
  int32_T c2_c_vstart;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_d_vstart;
  int32_T c2_e_k;
  int32_T c2_e_vstart;
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_h_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i_k;
  int32_T c2_inb;
  int32_T c2_k;
  int32_T c2_lidx;
  int32_T c2_nfb;
  int32_T c2_nleft;
  boolean_T c2_b_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  if (c2_vlen <= 1024) {
    c2_st.site = &c2_fc_emlrtRSI;
    c2_b_vlen = c2_vlen - 1;
    c2_b_vstart = c2_vstart - 1;
    c2_b_y = c2_e_x->data[c2_b_vstart];
    c2_i = c2_b_vlen;
    c2_b_st.site = &c2_gc_emlrtRSI;
    c2_b = c2_i;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_c_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
    }

    for (c2_d_k = 1; c2_d_k - 1 < c2_i; c2_d_k++) {
      c2_e_k = c2_d_k;
      c2_b_y += c2_e_x->data[c2_b_vstart + c2_e_k];
    }
  } else {
    c2_d_a = c2_vlen;
    c2_nfb = c2_div_nzp_s32(chartInstance, c2_d_a, 1024, 0, 1U, 0, 0);
    c2_inb = c2_nfb << 10;
    c2_st.site = &c2_eg_emlrtRSI;
    c2_c_vstart = c2_vstart - 1;
    c2_b_y = c2_e_x->data[c2_c_vstart];
    c2_b_st.site = &c2_gc_emlrtRSI;
    for (c2_k = 1; c2_k - 1 < 1023; c2_k++) {
      c2_c_k = c2_k;
      c2_b_y += c2_e_x->data[c2_c_vstart + c2_c_k];
    }

    for (c2_b_k = 1; c2_b_k < c2_nfb; c2_b_k++) {
      c2_st.site = &c2_fg_emlrtRSI;
      c2_d_vstart = (c2_vstart + (c2_b_k << 10)) - 1;
      c2_c_y = c2_e_x->data[c2_d_vstart];
      c2_b_st.site = &c2_gc_emlrtRSI;
      for (c2_f_k = 1; c2_f_k - 1 < 1023; c2_f_k++) {
        c2_g_k = c2_f_k;
        c2_c_y += c2_e_x->data[c2_d_vstart + c2_g_k];
      }

      c2_b_y += c2_c_y;
    }

    if (c2_vlen > c2_inb) {
      c2_nleft = c2_vlen - c2_inb;
      c2_lidx = c2_vstart + c2_inb;
      c2_st.site = &c2_gg_emlrtRSI;
      c2_c_vlen = c2_nleft - 1;
      c2_e_vstart = c2_lidx - 1;
      c2_d_y = c2_e_x->data[c2_e_vstart];
      c2_i1 = c2_c_vlen;
      c2_b_st.site = &c2_gc_emlrtRSI;
      c2_c_b = c2_i1;
      c2_d_b = c2_c_b;
      if (1 > c2_d_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_d_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_c_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
      }

      for (c2_h_k = 1; c2_h_k - 1 < c2_i1; c2_h_k++) {
        c2_i_k = c2_h_k;
        c2_d_y += c2_e_x->data[c2_e_vstart + c2_i_k];
      }

      c2_b_y += c2_d_y;
    }
  }

  return c2_b_y;
}

static void c2_round(SFc2_imagedetectorInstanceStruct *chartInstance, const
                     emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x,
                     c2_emxArray_real_T *c2_f_x)
{
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_loop_ub;
  c2_i = c2_f_x->size[0];
  c2_f_x->size[0] = c2_e_x->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_sp, c2_f_x, c2_i,
    &c2_xf_emlrtRTEI);
  c2_loop_ub = c2_e_x->size[0] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_f_x->data[c2_i1] = c2_e_x->data[c2_i1];
  }

  c2_b_round(chartInstance, c2_sp, c2_f_x);
}

static void c2_b_sort(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x,
                      c2_emxArray_real_T *c2_f_x, c2_emxArray_int32_T *c2_b_idx)
{
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_loop_ub;
  c2_i = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = c2_e_x->size[0];
  c2_f_x->size[1] = 1;
  c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_f_x, c2_i,
    &c2_fd_emlrtRTEI);
  c2_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_f_x->data[c2_i1] = c2_e_x->data[c2_i1];
  }

  c2_d_sort(chartInstance, c2_sp, c2_f_x, c2_b_idx);
}

static void c2_b_merge_pow2_block(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx,
  c2_emxArray_real_T *c2_e_x, int32_T c2_offset, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real_T *c2_f_x)
{
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_loop_ub;
  c2_i = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = c2_b_idx->size[0];
  c2_c_idx->size[1] = 1;
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_sp, c2_c_idx, c2_i,
    &c2_gd_emlrtRTEI);
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_c_idx->data[c2_i1] = c2_b_idx->data[c2_i1];
  }

  c2_i2 = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = c2_e_x->size[0];
  c2_f_x->size[1] = 1;
  c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_f_x, c2_i2,
    &c2_gd_emlrtRTEI);
  c2_b_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_f_x->data[c2_i3] = c2_e_x->data[c2_i3];
  }

  c2_d_merge_pow2_block(chartInstance, c2_sp, c2_c_idx, c2_f_x, c2_offset);
}

static void c2_b_merge_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T
  *c2_e_x, int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel,
  c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real_T *c2_xwork,
  c2_emxArray_int32_T *c2_c_idx, c2_emxArray_real_T *c2_f_x, c2_emxArray_int32_T
  *c2_c_iwork, c2_emxArray_real_T *c2_b_xwork)
{
  int32_T c2_b_loop_ub;
  int32_T c2_c_loop_ub;
  int32_T c2_d_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_loop_ub;
  c2_i = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = c2_b_idx->size[0];
  c2_c_idx->size[1] = 1;
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_sp, c2_c_idx, c2_i,
    &c2_hd_emlrtRTEI);
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_c_idx->data[c2_i1] = c2_b_idx->data[c2_i1];
  }

  c2_i2 = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = c2_e_x->size[0];
  c2_f_x->size[1] = 1;
  c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_f_x, c2_i2,
    &c2_hd_emlrtRTEI);
  c2_b_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_f_x->data[c2_i3] = c2_e_x->data[c2_i3];
  }

  c2_i4 = c2_c_iwork->size[0];
  c2_c_iwork->size[0] = c2_b_iwork->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_c_iwork, c2_i4,
    &c2_hd_emlrtRTEI);
  c2_c_loop_ub = c2_b_iwork->size[0] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_c_loop_ub; c2_i5++) {
    c2_c_iwork->data[c2_i5] = c2_b_iwork->data[c2_i5];
  }

  c2_i6 = c2_b_xwork->size[0];
  c2_b_xwork->size[0] = c2_xwork->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_sp, c2_b_xwork, c2_i6,
    &c2_hd_emlrtRTEI);
  c2_d_loop_ub = c2_xwork->size[0] - 1;
  for (c2_i7 = 0; c2_i7 <= c2_d_loop_ub; c2_i7++) {
    c2_b_xwork->data[c2_i7] = c2_xwork->data[c2_i7];
  }

  c2_d_merge_block(chartInstance, c2_sp, c2_c_idx, c2_f_x, c2_offset, c2_n,
                   c2_preSortLevel, c2_c_iwork, c2_b_xwork);
}

static void c2_b_merge(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_e_x,
  int32_T c2_offset, int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T
  *c2_b_iwork, c2_emxArray_real_T *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real_T *c2_f_x, c2_emxArray_int32_T *c2_c_iwork,
  c2_emxArray_real_T *c2_b_xwork)
{
  int32_T c2_b_loop_ub;
  int32_T c2_c_loop_ub;
  int32_T c2_d_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_loop_ub;
  c2_i = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = c2_b_idx->size[0];
  c2_c_idx->size[1] = 1;
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_sp, c2_c_idx, c2_i,
    &c2_id_emlrtRTEI);
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_c_idx->data[c2_i1] = c2_b_idx->data[c2_i1];
  }

  c2_i2 = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = c2_e_x->size[0];
  c2_f_x->size[1] = 1;
  c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, c2_f_x, c2_i2,
    &c2_id_emlrtRTEI);
  c2_b_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_b_loop_ub; c2_i3++) {
    c2_f_x->data[c2_i3] = c2_e_x->data[c2_i3];
  }

  c2_i4 = c2_c_iwork->size[0];
  c2_c_iwork->size[0] = c2_b_iwork->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_sp, c2_c_iwork, c2_i4,
    &c2_id_emlrtRTEI);
  c2_c_loop_ub = c2_b_iwork->size[0] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_c_loop_ub; c2_i5++) {
    c2_c_iwork->data[c2_i5] = c2_b_iwork->data[c2_i5];
  }

  c2_i6 = c2_b_xwork->size[0];
  c2_b_xwork->size[0] = c2_xwork->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_sp, c2_b_xwork, c2_i6,
    &c2_id_emlrtRTEI);
  c2_d_loop_ub = c2_xwork->size[0] - 1;
  for (c2_i7 = 0; c2_i7 <= c2_d_loop_ub; c2_i7++) {
    c2_b_xwork->data[c2_i7] = c2_xwork->data[c2_i7];
  }

  c2_d_merge(chartInstance, c2_sp, c2_c_idx, c2_f_x, c2_offset, c2_np, c2_nq,
             c2_c_iwork, c2_b_xwork);
}

static void c2_chradiiphcode(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T *c2_f_varargin_1, creal_T
  c2_b_varargin_2[307200], c2_emxArray_real_T *c2_r_estimated)
{
  static char_T c2_b_cv1[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c2_b_cv4[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c2_cv7[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'i', 'n', 'c', 'o', 'r', 'r', 'e', 'c',
    't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c2_cv9[38] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'f',
    'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'o', 'u', 't', 'O',
    'f', 'B', 'o', 'u', 'n', 'd', 'C', 'e', 'n', 't', 'e', 'r', 's' };

  static char_T c2_b_cv[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c2_b_cv3[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p',
    'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c2_cv5[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'i', 'n', 'c', 'o',
    'r', 'r', 'e', 'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c2_b_cv2[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c2_cv6[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c2_cv8[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  c2_emxArray_boolean_T *c2_g_varargin_1;
  c2_emxArray_boolean_T *c2_h_varargin_1;
  c2_emxArray_creal_T *c2_d_varargin_2;
  c2_emxArray_int32_T *c2_r;
  c2_emxArray_real_T *c2_c_varargin_2;
  c2_emxArray_real_T *c2_ndx;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  const mxArray *c2_j_y = NULL;
  const mxArray *c2_k_y = NULL;
  const mxArray *c2_l_y = NULL;
  const mxArray *c2_m_y = NULL;
  real_T c2_b_k;
  real_T c2_d;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_u;
  int32_T c2_b_b;
  int32_T c2_b_loop_ub;
  int32_T c2_c_b;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_d_k;
  int32_T c2_d_loop_ub;
  int32_T c2_e_loop_ub;
  int32_T c2_f_loop_ub;
  int32_T c2_g_loop_ub;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_loop_ub;
  int32_T c2_k;
  int32_T c2_loop_ub;
  int32_T c2_nx;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b2;
  boolean_T c2_b3;
  boolean_T c2_b_p;
  boolean_T c2_exitg1;
  boolean_T c2_overflow;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_st.site = &c2_sh_emlrtRSI;
  c2_b_st.site = &c2_vh_emlrtRSI;
  c2_c_st.site = &c2_xh_emlrtRSI;
  c2_d_st.site = &c2_gf_emlrtRSI;
  c2_p = true;
  c2_d = (real_T)(c2_f_varargin_1->size[0] * c2_f_varargin_1->size[1]);
  c2_i = (int32_T)c2_d - 1;
  c2_k = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_k <= c2_i)) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_e_x = c2_f_varargin_1->data[(int32_T)c2_b_k - 1];
    c2_b_p = !(c2_e_x <= 0.0);
    if (c2_b_p) {
      c2_k++;
    } else {
      c2_p = false;
      c2_exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_cv2, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call(&c2_d_st, &c2_u_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                sf_mex_call(&c2_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_d_st, NULL, "message", 1U, 2U, 14, c2_c_y, 14, c2_d_y)));
  }

  c2_d_st.site = &c2_gf_emlrtRSI;
  c2_b1 = (c2_f_varargin_1->size[0] == 0);
  c2_b2 = (c2_f_varargin_1->size[1] == 0);
  if (!((!c2_b1) && (!c2_b2))) {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_cv3, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_b_cv4, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call(&c2_d_st, &c2_v_emlrtMCI, "error", 0U, 2U, 14, c2_e_y, 14,
                sf_mex_call(&c2_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_d_st, NULL, "message", 1U, 2U, 14, c2_f_y, 14, c2_h_y)));
  }

  c2_d_st.site = &c2_gf_emlrtRSI;
  if (!((real_T)c2_f_varargin_1->size[1] == 2.0)) {
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 37),
                  false);
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    c2_u = 2.0;
    c2_k_y = NULL;
    sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call(&c2_d_st, &c2_w_emlrtMCI, "error", 0U, 2U, 14, c2_g_y, 14,
                sf_mex_call(&c2_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_d_st, NULL, "message", 1U, 3U, 14, c2_i_y, 14, c2_j_y, 14, c2_k_y)));
  }

  c2_emxInit_boolean_T1(chartInstance, &c2_d_st, &c2_g_varargin_1, 1,
                        &c2_yf_emlrtRTEI);
  c2_b_st.site = &c2_wh_emlrtRSI;
  c2_i1 = c2_f_varargin_1->size[1];
  c2_i2 = 1;
  if ((c2_i2 < 1) || (c2_i2 > c2_i1)) {
    emlrtDynamicBoundsCheckR2012b(c2_i2, 1, c2_i1, &c2_re_emlrtBCI, &c2_b_st);
  }

  c2_i3 = c2_f_varargin_1->size[0] - 1;
  c2_i4 = c2_g_varargin_1->size[0];
  c2_g_varargin_1->size[0] = c2_i3 + 1;
  c2_emxEnsureCapacity_boolean_T1(chartInstance, &c2_b_st, c2_g_varargin_1,
    c2_i4, &c2_yf_emlrtRTEI);
  c2_loop_ub = c2_i3;
  for (c2_i5 = 0; c2_i5 <= c2_loop_ub; c2_i5++) {
    c2_g_varargin_1->data[c2_i5] = (c2_f_varargin_1->data[c2_i5] <= 640.0);
  }

  c2_emxInit_boolean_T1(chartInstance, &c2_b_st, &c2_h_varargin_1, 1,
                        &c2_ag_emlrtRTEI);
  c2_c_st.site = &c2_yh_emlrtRSI;
  if (c2_all(chartInstance, &c2_c_st, c2_g_varargin_1)) {
    c2_i6 = c2_f_varargin_1->size[1];
    c2_i7 = 2;
    if ((c2_i7 < 1) || (c2_i7 > c2_i6)) {
      emlrtDynamicBoundsCheckR2012b(c2_i7, 1, c2_i6, &c2_se_emlrtBCI, &c2_b_st);
    }

    c2_i8 = c2_f_varargin_1->size[0] - 1;
    c2_i9 = c2_h_varargin_1->size[0];
    c2_h_varargin_1->size[0] = c2_i8 + 1;
    c2_emxEnsureCapacity_boolean_T1(chartInstance, &c2_b_st, c2_h_varargin_1,
      c2_i9, &c2_ag_emlrtRTEI);
    c2_b_loop_ub = c2_i8;
    for (c2_i12 = 0; c2_i12 <= c2_b_loop_ub; c2_i12++) {
      c2_h_varargin_1->data[c2_i12] = (c2_f_varargin_1->data[c2_i12 +
        c2_f_varargin_1->size[0]] <= 480.0);
    }

    c2_c_st.site = &c2_ai_emlrtRSI;
    if (c2_all(chartInstance, &c2_c_st, c2_h_varargin_1)) {
      c2_b3 = true;
    } else {
      c2_b3 = false;
    }
  } else {
    c2_b3 = false;
  }

  c2_emxFree_boolean_T(chartInstance, &c2_h_varargin_1);
  c2_emxFree_boolean_T(chartInstance, &c2_g_varargin_1);
  if (!c2_b3) {
    c2_l_y = NULL;
    sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    c2_m_y = NULL;
    sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 38),
                  false);
    sf_mex_call(&c2_b_st, &c2_x_emlrtMCI, "error", 0U, 2U, 14, c2_l_y, 14,
                sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_b_st, NULL, "message", 1U, 1U, 14, c2_m_y)));
  }

  c2_emxInit_real_T1(chartInstance, &c2_b_st, &c2_ndx, 1, &c2_gg_emlrtRTEI);
  c2_i10 = c2_f_varargin_1->size[1];
  c2_i11 = 2;
  if ((c2_i11 < 1) || (c2_i11 > c2_i10)) {
    emlrtDynamicBoundsCheckR2012b(c2_i11, 1, c2_i10, &c2_pe_emlrtBCI, (void *)
      c2_sp);
  }

  c2_i13 = c2_f_varargin_1->size[1];
  c2_i14 = 1;
  if ((c2_i14 < 1) || (c2_i14 > c2_i13)) {
    emlrtDynamicBoundsCheckR2012b(c2_i14, 1, c2_i13, &c2_qe_emlrtBCI, (void *)
      c2_sp);
  }

  c2_st.site = &c2_th_emlrtRSI;
  c2_i15 = c2_f_varargin_1->size[0] - 1;
  c2_i16 = c2_ndx->size[0];
  c2_ndx->size[0] = c2_i15 + 1;
  c2_b_st.site = &c2_gi_emlrtRSI;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_ndx, c2_i16,
    &c2_bg_emlrtRTEI);
  c2_c_loop_ub = c2_i15;
  for (c2_i17 = 0; c2_i17 <= c2_c_loop_ub; c2_i17++) {
    c2_ndx->data[c2_i17] = c2_f_varargin_1->data[c2_i17 + c2_f_varargin_1->size
      [0]];
  }

  c2_emxInit_real_T1(chartInstance, &c2_st, &c2_c_varargin_2, 1,
                     &c2_cg_emlrtRTEI);
  c2_b_st.site = &c2_th_emlrtRSI;
  c2_b_round(chartInstance, &c2_b_st, c2_ndx);
  c2_i18 = c2_f_varargin_1->size[0] - 1;
  c2_i19 = c2_c_varargin_2->size[0];
  c2_c_varargin_2->size[0] = c2_i18 + 1;
  c2_b_st.site = &c2_gi_emlrtRSI;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_c_varargin_2, c2_i19,
    &c2_cg_emlrtRTEI);
  c2_d_loop_ub = c2_i18;
  for (c2_i20 = 0; c2_i20 <= c2_d_loop_ub; c2_i20++) {
    c2_c_varargin_2->data[c2_i20] = c2_f_varargin_1->data[c2_i20];
  }

  c2_emxInit_int32_T(chartInstance, &c2_st, &c2_r, 1, &c2_je_emlrtRTEI);
  c2_b_st.site = &c2_th_emlrtRSI;
  c2_b_round(chartInstance, &c2_b_st, c2_c_varargin_2);
  c2_b_st.site = &c2_le_emlrtRSI;
  c2_eml_sub2ind(chartInstance, &c2_b_st, c2_ndx, c2_c_varargin_2, c2_r);
  c2_i21 = c2_ndx->size[0];
  c2_ndx->size[0] = c2_r->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_ndx, c2_i21,
    &c2_r_emlrtRTEI);
  c2_e_loop_ub = c2_r->size[0] - 1;
  c2_emxFree_real_T(chartInstance, &c2_c_varargin_2);
  for (c2_i22 = 0; c2_i22 <= c2_e_loop_ub; c2_i22++) {
    c2_ndx->data[c2_i22] = (real_T)c2_r->data[c2_i22];
  }

  c2_emxFree_int32_T(chartInstance, &c2_r);
  c2_emxInit_creal_T(chartInstance, &c2_st, &c2_d_varargin_2, 1,
                     &c2_dg_emlrtRTEI);
  c2_i23 = c2_d_varargin_2->size[0];
  c2_d_varargin_2->size[0] = c2_ndx->size[0];
  c2_st.site = &c2_gi_emlrtRSI;
  c2_emxEnsureCapacity_creal_T(chartInstance, &c2_st, c2_d_varargin_2, c2_i23,
    &c2_dg_emlrtRTEI);
  c2_f_loop_ub = c2_ndx->size[0] - 1;
  for (c2_i24 = 0; c2_i24 <= c2_f_loop_ub; c2_i24++) {
    c2_i25 = (int32_T)c2_ndx->data[c2_i24];
    if ((c2_i25 < 1) || (c2_i25 > 307200)) {
      emlrtDynamicBoundsCheckR2012b(c2_i25, 1, 307200, &c2_te_emlrtBCI, (void *)
        c2_sp);
    }

    c2_d_varargin_2->data[c2_i24].re = c2_b_varargin_2[c2_i25 - 1].re;
    c2_i27 = (int32_T)c2_ndx->data[c2_i24];
    if ((c2_i27 < 1) || (c2_i27 > 307200)) {
      emlrtDynamicBoundsCheckR2012b(c2_i27, 1, 307200, &c2_te_emlrtBCI, (void *)
        c2_sp);
    }

    c2_d_varargin_2->data[c2_i24].im = c2_b_varargin_2[c2_i27 - 1].im;
  }

  c2_emxFree_real_T(chartInstance, &c2_ndx);
  c2_st.site = &c2_th_emlrtRSI;
  c2_angle(chartInstance, &c2_st, c2_d_varargin_2, c2_r_estimated);
  c2_i26 = c2_r_estimated->size[0];
  c2_st.site = &c2_gj_emlrtRSI;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_r_estimated, c2_i26,
    &c2_eg_emlrtRTEI);
  c2_g_loop_ub = c2_r_estimated->size[0] - 1;
  c2_emxFree_creal_T(chartInstance, &c2_d_varargin_2);
  for (c2_i28 = 0; c2_i28 <= c2_g_loop_ub; c2_i28++) {
    c2_r_estimated->data[c2_i28] = (c2_r_estimated->data[c2_i28] +
      3.1415926535897931) / 6.2831853071795862;
  }

  c2_i29 = c2_r_estimated->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_sp, c2_r_estimated, c2_i29,
    &c2_dc_emlrtRTEI);
  c2_h_loop_ub = c2_r_estimated->size[0] - 1;
  for (c2_i30 = 0; c2_i30 <= c2_h_loop_ub; c2_i30++) {
    c2_r_estimated->data[c2_i30] *= 3.401197381662155;
  }

  c2_st.site = &c2_uh_emlrtRSI;
  c2_i31 = c2_r_estimated->size[0];
  c2_b_st.site = &c2_gj_emlrtRSI;
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_r_estimated, c2_i31,
    &c2_fg_emlrtRTEI);
  c2_i_loop_ub = c2_r_estimated->size[0] - 1;
  for (c2_i32 = 0; c2_i32 <= c2_i_loop_ub; c2_i32++) {
    c2_r_estimated->data[c2_i32] += 2.3025850929940459;
  }

  c2_b_st.site = &c2_di_emlrtRSI;
  c2_nx = c2_r_estimated->size[0];
  c2_c_st.site = &c2_ih_emlrtRSI;
  c2_b_b = c2_nx;
  c2_c_b = c2_b_b;
  if (1 > c2_c_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_d_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_d_st);
  }

  for (c2_c_k = 1; c2_c_k - 1 < c2_nx; c2_c_k++) {
    c2_d_k = c2_c_k - 1;
    c2_f_x = c2_r_estimated->data[c2_d_k];
    c2_g_x = c2_f_x;
    c2_g_x = muDoubleScalarExp(c2_g_x);
    c2_r_estimated->data[c2_d_k] = c2_g_x;
  }
}

static boolean_T c2_all(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_e_x)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_a;
  real_T c2_vlen;
  int32_T c2_b_b;
  int32_T c2_c;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_i2;
  int32_T c2_ix;
  int32_T c2_vspread;
  boolean_T c2_b;
  boolean_T c2_b_y;
  boolean_T c2_exitg1;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_st.site = &c2_bi_emlrtRSI;
  if ((c2_e_x->size[0] == 1) || ((real_T)c2_e_x->size[0] != 1.0)) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c2_st, &c2_e_emlrtMCI, "error", 0U, 2U, 14, c2_c_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_d_y)));
  }

  c2_b_y = true;
  c2_vlen = (real_T)c2_e_x->size[0];
  c2_d_a = c2_vlen;
  c2_c = (int32_T)c2_d_a;
  c2_e_a = c2_c - 1;
  c2_vspread = c2_e_a;
  c2_b_b = c2_vspread;
  c2_i2 = c2_b_b;
  c2_f_a = c2_i2 + 1;
  c2_i2 = c2_f_a;
  c2_b_st.site = &c2_kd_emlrtRSI;
  c2_c_b = c2_i2;
  c2_d_b = c2_c_b;
  if (1 > c2_d_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_d_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  c2_ix = 0;
  c2_exitg1 = false;
  while ((!c2_exitg1) && (c2_ix + 1 <= c2_i2)) {
    if (!c2_e_x->data[c2_ix]) {
      c2_b_y = false;
      c2_exitg1 = true;
    } else {
      c2_ix++;
    }
  }

  return c2_b_y;
}

static void c2_angle(SFc2_imagedetectorInstanceStruct *chartInstance, const
                     emlrtStack *c2_sp, c2_emxArray_creal_T *c2_e_x,
                     c2_emxArray_real_T *c2_b_y)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  creal_T c2_f_x;
  real_T c2_dv[2];
  real_T c2_c_y;
  real_T c2_d_y;
  real_T c2_g_x;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_i;
  int32_T c2_k;
  int32_T c2_nx;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_ci_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_nx = c2_e_x->size[0];
  c2_dv[0] = (real_T)c2_e_x->size[0];
  c2_i = c2_b_y->size[0];
  c2_b_y->size[0] = (int32_T)c2_dv[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_b_y, c2_i,
    &c2_ed_emlrtRTEI);
  c2_b_st.site = &c2_id_emlrtRSI;
  c2_b = c2_nx;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = 1; c2_k - 1 < c2_nx; c2_k++) {
    c2_b_k = c2_k - 1;
    c2_f_x = c2_e_x->data[c2_b_k];
    c2_c_y = c2_f_x.im;
    c2_g_x = c2_f_x.re;
    c2_d_y = muDoubleScalarAtan2(c2_c_y, c2_g_x);
    c2_b_y->data[c2_b_k] = c2_d_y;
  }
}

static real_T c2_emlrt_marshallIn(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_b_y, const char_T *c2_identifier)
{
  emlrtMsgIdentifier c2_thisId;
  real_T c2_c_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId);
  sf_mex_destroy(&c2_b_y);
  return c2_c_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_b_y;
  real_T c2_d;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d;
  sf_mex_destroy(&c2_u);
  return c2_b_y;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_imagedetector, const char_T
  *c2_identifier)
{
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_b_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_imagedetector), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_imagedetector);
  return c2_b_y;
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_imagedetectorInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_u;
  uint8_T c2_b_y;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b_u, 1, 3, 0U, 0, 0U, 0);
  c2_b_y = c2_b_u;
  sf_mex_destroy(&c2_u);
  return c2_b_y;
}

static void c2_chart_data_browse_helper(SFc2_imagedetectorInstanceStruct
  *chartInstance, int32_T c2_ssIdNumber, const mxArray **c2_mxData, uint8_T
  *c2_isValueTooBig)
{
  real_T c2_d;
  *c2_mxData = NULL;
  *c2_mxData = NULL;
  *c2_isValueTooBig = 0U;
  switch (c2_ssIdNumber) {
   case 5U:
    c2_d = *chartInstance->c2_y;
    sf_mex_assign(c2_mxData, sf_mex_create("mxData", &c2_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 6U:
    *c2_isValueTooBig = 1U;
    break;
  }
}

static const mxArray *c2_feval(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1,
  const mxArray *c2_input2, const mxArray *c2_input3, const mxArray *c2_input4,
  const mxArray *c2_input5, const mxArray *c2_input6, const mxArray *c2_input7)
{
  const mxArray *c2_ = NULL;
  (void)chartInstance;
  c2_ = NULL;
  sf_mex_assign(&c2_, sf_mex_call(c2_sp, NULL, "feval", 1U, 8U, 14, sf_mex_dup
    (c2_input0), 14, sf_mex_dup(c2_input1), 14, sf_mex_dup(c2_input2), 14,
    sf_mex_dup(c2_input3), 14, sf_mex_dup(c2_input4), 14, sf_mex_dup(c2_input5),
    14, sf_mex_dup(c2_input6), 14, sf_mex_dup(c2_input7)), false);
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
  sf_mex_destroy(&c2_input2);
  sf_mex_destroy(&c2_input3);
  sf_mex_destroy(&c2_input4);
  sf_mex_destroy(&c2_input5);
  sf_mex_destroy(&c2_input6);
  sf_mex_destroy(&c2_input7);
  return c2_;
}

static void c2_b_feval(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1)
{
  (void)chartInstance;
  sf_mex_call(c2_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c2_input0), 14,
              sf_mex_dup(c2_input1));
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
}

static const mxArray *c2_sprintf(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0)
{
  const mxArray *c2_ = NULL;
  (void)chartInstance;
  c2_ = NULL;
  sf_mex_assign(&c2_, sf_mex_call(c2_sp, NULL, "sprintf", 1U, 1U, 14, sf_mex_dup
    (c2_input0)), false);
  sf_mex_destroy(&c2_input0);
  return c2_;
}

static const mxArray *c2_c_feval(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1,
  const mxArray *c2_input2)
{
  const mxArray *c2_ = NULL;
  (void)chartInstance;
  c2_ = NULL;
  sf_mex_assign(&c2_, sf_mex_call(c2_sp, NULL, "feval", 1U, 3U, 14, sf_mex_dup
    (c2_input0), 14, sf_mex_dup(c2_input1), 14, sf_mex_dup(c2_input2)), false);
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
  sf_mex_destroy(&c2_input2);
  return c2_;
}

static void c2_d_feval(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1)
{
  (void)chartInstance;
  sf_mex_call(c2_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c2_input0), 14,
              sf_mex_dup(c2_input1));
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
}

static const mxArray *c2_e_feval(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1)
{
  const mxArray *c2_ = NULL;
  (void)chartInstance;
  c2_ = NULL;
  sf_mex_assign(&c2_, sf_mex_call(c2_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c2_input0), 14, sf_mex_dup(c2_input1)), false);
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
  return c2_;
}

static void c2_f_feval(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, const mxArray *c2_input0, const mxArray *c2_input1)
{
  (void)chartInstance;
  sf_mex_call(c2_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c2_input0), 14,
              sf_mex_dup(c2_input1));
  sf_mex_destroy(&c2_input0);
  sf_mex_destroy(&c2_input1);
}

static void c2_b_mergesort(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, int32_T c2_b_idx[307200], real32_T c2_e_x[307200])
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_b_idx1;
  int32_T c2_b_idx2;
  int32_T c2_b_k;
  int32_T c2_b_p;
  int32_T c2_c_k;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_f_b;
  int32_T c2_i;
  int32_T c2_i2;
  int32_T c2_idx1;
  int32_T c2_idx2;
  int32_T c2_j;
  int32_T c2_k;
  int32_T c2_kEnd;
  int32_T c2_pEnd;
  int32_T c2_q;
  int32_T c2_qEnd;
  real32_T c2_b;
  real32_T c2_b_b;
  real32_T c2_c_b;
  real32_T c2_d_a;
  real32_T c2_f_a;
  real32_T c2_f_x;
  real32_T c2_g_a;
  real32_T c2_g_b;
  real32_T c2_g_x;
  real32_T c2_h_a;
  real32_T c2_h_b;
  real32_T c2_i_a;
  real32_T c2_i_b;
  real32_T c2_j_a;
  boolean_T c2_c_p;
  boolean_T c2_d_b;
  boolean_T c2_d_p;
  boolean_T c2_e_p;
  boolean_T c2_f_p;
  boolean_T c2_g_p;
  boolean_T c2_j_b;
  boolean_T c2_overflow;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  for (c2_k = 0; c2_k <= 307199; c2_k += 2) {
    c2_idx1 = c2_k;
    c2_idx2 = c2_k;
    c2_d_a = c2_e_x[c2_idx1];
    c2_b = c2_e_x[c2_idx2 + 1];
    c2_f_a = c2_d_a;
    c2_b_b = c2_b;
    c2_g_a = c2_f_a;
    c2_c_b = c2_b_b;
    c2_p = (c2_g_a <= c2_c_b);
    if (c2_p) {
      c2_c_p = true;
    } else {
      c2_f_x = c2_b_b;
      c2_d_b = muSingleScalarIsNaN(c2_f_x);
      if (c2_d_b) {
        c2_c_p = true;
      } else {
        c2_c_p = false;
      }
    }

    c2_d_p = c2_c_p;
    if (c2_d_p) {
      c2_b_idx[c2_k] = c2_k + 1;
      c2_b_idx[c2_k + 1] = c2_k + 2;
    } else {
      c2_b_idx[c2_k] = c2_k + 2;
      c2_b_idx[c2_k + 1] = c2_k + 1;
    }
  }

  c2_i = 2;
  while (c2_i < 307200) {
    c2_e_a = c2_i;
    c2_i2 = c2_e_a << 1;
    c2_j = 1;
    for (c2_pEnd = 1 + c2_i; c2_pEnd < 307201; c2_pEnd = c2_qEnd + c2_i) {
      c2_b_p = c2_j - 1;
      c2_q = c2_pEnd - 1;
      c2_qEnd = c2_j + c2_i2;
      if (c2_qEnd > 307201) {
        c2_qEnd = 307201;
      }

      c2_b_k = 0;
      c2_kEnd = c2_qEnd - c2_j;
      while (c2_b_k + 1 <= c2_kEnd) {
        c2_b_idx1 = c2_b_idx[c2_b_p] - 1;
        c2_b_idx2 = c2_b_idx[c2_q] - 1;
        c2_h_a = c2_e_x[c2_b_idx1];
        c2_g_b = c2_e_x[c2_b_idx2];
        c2_i_a = c2_h_a;
        c2_h_b = c2_g_b;
        c2_j_a = c2_i_a;
        c2_i_b = c2_h_b;
        c2_e_p = (c2_j_a <= c2_i_b);
        if (c2_e_p) {
          c2_f_p = true;
        } else {
          c2_g_x = c2_h_b;
          c2_j_b = muSingleScalarIsNaN(c2_g_x);
          if (c2_j_b) {
            c2_f_p = true;
          } else {
            c2_f_p = false;
          }
        }

        c2_g_p = c2_f_p;
        if (c2_g_p) {
          chartInstance->c2_iwork[c2_b_k] = c2_b_idx[c2_b_p];
          c2_b_p++;
          if (c2_b_p + 1 == c2_pEnd) {
            while (c2_q + 1 < c2_qEnd) {
              c2_b_k++;
              chartInstance->c2_iwork[c2_b_k] = c2_b_idx[c2_q];
              c2_q++;
            }
          }
        } else {
          chartInstance->c2_iwork[c2_b_k] = c2_b_idx[c2_q];
          c2_q++;
          if (c2_q + 1 == c2_qEnd) {
            while (c2_b_p + 1 < c2_pEnd) {
              c2_b_k++;
              chartInstance->c2_iwork[c2_b_k] = c2_b_idx[c2_b_p];
              c2_b_p++;
            }
          }
        }

        c2_b_k++;
      }

      c2_b_p = c2_j - 2;
      c2_st.site = &c2_jc_emlrtRSI;
      c2_e_b = c2_kEnd;
      c2_f_b = c2_e_b;
      if (1 > c2_f_b) {
        c2_overflow = false;
      } else {
        c2_overflow = (c2_f_b > 2147483646);
      }

      if (c2_overflow) {
        c2_b_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
      }

      for (c2_c_k = 1; c2_c_k - 1 < c2_kEnd; c2_c_k++) {
        c2_b_k = c2_c_k;
        c2_b_idx[c2_b_p + c2_b_k] = chartInstance->c2_iwork[c2_b_k - 1];
      }

      c2_j = c2_qEnd;
    }

    c2_i = c2_i2;
  }
}

static void c2_b_nullAssignment(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real32_T *c2_e_x, c2_emxArray_boolean_T
  *c2_b_idx)
{
  c2_emxArray_real32_T *c2_f_x;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_b_n;
  int32_T c2_c_b;
  int32_T c2_c_k;
  int32_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_k;
  int32_T c2_k0;
  int32_T c2_loop_ub;
  int32_T c2_n;
  int32_T c2_nb;
  int32_T c2_nxin;
  int32_T c2_nxout;
  boolean_T c2_b_overflow;
  boolean_T c2_e_b;
  boolean_T c2_overflow;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_emxInit_real32_T(chartInstance, c2_sp, &c2_f_x, 2, &c2_hg_emlrtRTEI);
  c2_st.site = &c2_yc_emlrtRSI;
  c2_i = c2_f_x->size[0] * c2_f_x->size[1];
  c2_f_x->size[0] = 1;
  c2_f_x->size[1] = c2_e_x->size[1];
  c2_b_st.site = &c2_pj_emlrtRSI;
  c2_emxEnsureCapacity_real32_T(chartInstance, &c2_b_st, c2_f_x, c2_i,
    &c2_hg_emlrtRTEI);
  c2_loop_ub = c2_e_x->size[0] * c2_e_x->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_f_x->data[c2_i1] = c2_e_x->data[c2_i1];
  }

  c2_n = c2_f_x->size[1];
  c2_k = c2_b_idx->size[1];
  c2_emxFree_real32_T(chartInstance, &c2_f_x);
  while ((c2_k >= 1) && (!c2_b_idx->data[c2_k - 1])) {
    c2_k--;
  }

  c2_p = (c2_k <= c2_n);
  if (!c2_p) {
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call(&c2_st, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_c_y)));
  }

  c2_st.site = &c2_ad_emlrtRSI;
  c2_nxin = c2_e_x->size[1];
  c2_b_st.site = &c2_bd_emlrtRSI;
  c2_b_n = 0;
  c2_i2 = c2_b_idx->size[1];
  c2_c_st.site = &c2_dd_emlrtRSI;
  c2_b = c2_i2;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_d_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_d_st);
  }

  for (c2_b_k = 1; c2_b_k - 1 < c2_i2; c2_b_k++) {
    c2_c_k = c2_b_k - 1;
    c2_b_n += (int32_T)c2_b_idx->data[c2_c_k];
  }

  c2_nxout = c2_nxin - c2_b_n;
  c2_nb = c2_b_idx->size[1];
  c2_k0 = -1;
  c2_b_st.site = &c2_cd_emlrtRSI;
  c2_c_b = c2_nxin;
  c2_d_b = c2_c_b;
  if (1 > c2_d_b) {
    c2_b_overflow = false;
  } else {
    c2_b_overflow = (c2_d_b > 2147483646);
  }

  if (c2_b_overflow) {
    c2_c_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_d_k = 1; c2_d_k - 1 < c2_nxin; c2_d_k++) {
    c2_e_k = c2_d_k - 1;
    if ((c2_e_k + 1 > c2_nb) || (!c2_b_idx->data[c2_e_k])) {
      c2_k0++;
      c2_e_x->data[c2_k0] = c2_e_x->data[c2_e_k];
    }
  }

  if (!(c2_nxout <= c2_nxin)) {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c2_st, &c2_d_emlrtMCI, "error", 0U, 2U, 14, c2_d_y, 14,
                sf_mex_call(&c2_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_st, NULL, "message", 1U, 1U, 14, c2_e_y)));
  }

  c2_e_b = (1 > c2_nxout);
  if (c2_e_b) {
    c2_i3 = 0;
  } else {
    c2_i3 = c2_nxout;
  }

  c2_i4 = c2_e_x->size[0] * c2_e_x->size[1];
  c2_e_x->size[1] = c2_i3;
  c2_emxEnsureCapacity_real32_T(chartInstance, &c2_st, c2_e_x, c2_i4,
    &c2_ig_emlrtRTEI);
}

static void c2_c_sort(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, c2_emxArray_real32_T *c2_e_x)
{
  c2_emxArray_int32_T *c2_b_idx;
  c2_emxArray_int32_T *c2_b_iwork;
  c2_emxArray_real32_T *c2_xwork;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  real_T c2_dv[2];
  int32_T c2_idx4[4];
  int32_T c2_perm[4];
  int32_T c2_b_xwork[1];
  int32_T c2_c_iwork[1];
  int32_T c2_iv[1];
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_i1;
  int32_T c2_b_i2;
  int32_T c2_b_i3;
  int32_T c2_b_i4;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_b_n;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_c_n;
  int32_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_e_b;
  int32_T c2_f_b;
  int32_T c2_g_b;
  int32_T c2_h_b;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_b;
  int32_T c2_ib;
  int32_T c2_itmp;
  int32_T c2_j_b;
  int32_T c2_k;
  int32_T c2_k_b;
  int32_T c2_loop_ub;
  int32_T c2_m;
  int32_T c2_n;
  int32_T c2_nBlocks;
  int32_T c2_nLastBlock;
  int32_T c2_nNaNs;
  int32_T c2_nNonNaN;
  int32_T c2_preSortLevel;
  int32_T c2_quartetOffset;
  int32_T c2_tailOffset;
  int32_T c2_wOffset;
  real32_T c2_x4[4];
  real32_T c2_f_x;
  boolean_T c2_b_overflow;
  boolean_T c2_c_b;
  boolean_T c2_c_overflow;
  boolean_T c2_d_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  c2_emxInit_int32_T1(chartInstance, c2_sp, &c2_b_idx, 2, &c2_qg_emlrtRTEI);
  c2_st.site = &c2_md_emlrtRSI;
  c2_i = c2_b_idx->size[0] * c2_b_idx->size[1];
  c2_b_idx->size[0] = 1;
  c2_b_idx->size[1] = c2_e_x->size[1];
  c2_emxEnsureCapacity_int32_T1(chartInstance, &c2_st, c2_b_idx, c2_i,
    &c2_jg_emlrtRTEI);
  c2_loop_ub = c2_e_x->size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
    c2_b_idx->data[c2_i1] = 0;
  }

  c2_b_st.site = &c2_nd_emlrtRSI;
  c2_n = c2_e_x->size[1];
  c2_c_st.site = &c2_od_emlrtRSI;
  c2_b_n = c2_e_x->size[1];
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    c2_x4[c2_i2] = 0.0F;
  }

  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    c2_idx4[c2_i3] = 0;
  }

  c2_emxInit_int32_T(chartInstance, &c2_c_st, &c2_b_iwork, 1, &c2_lg_emlrtRTEI);
  c2_i4 = c2_b_iwork->size[0];
  c2_b_iwork->size[0] = c2_b_idx->size[1];
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_iwork, c2_i4,
    &c2_kg_emlrtRTEI);
  c2_iv[0] = c2_b_iwork->size[0];
  c2_i5 = c2_b_iwork->size[0];
  c2_b_iwork->size[0] = c2_iv[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_iwork, c2_i5,
    &c2_lg_emlrtRTEI);
  c2_c_iwork[0] = c2_b_iwork->size[0];
  c2_i6 = c2_b_iwork->size[0];
  c2_b_iwork->size[0] = c2_c_iwork[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_iwork, c2_i6,
    &c2_mg_emlrtRTEI);
  c2_b_loop_ub = c2_c_iwork[0] - 1;
  for (c2_i7 = 0; c2_i7 <= c2_b_loop_ub; c2_i7++) {
    c2_b_iwork->data[c2_i7] = 0;
  }

  c2_emxInit_real32_T1(chartInstance, &c2_c_st, &c2_xwork, 1, &c2_og_emlrtRTEI);
  c2_dv[0] = (real_T)c2_e_x->size[1];
  c2_i8 = c2_xwork->size[0];
  c2_xwork->size[0] = (int32_T)c2_dv[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, &c2_c_st, c2_xwork, c2_i8,
    &c2_ng_emlrtRTEI);
  c2_iv[0] = c2_xwork->size[0];
  c2_i9 = c2_xwork->size[0];
  c2_xwork->size[0] = c2_iv[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, &c2_c_st, c2_xwork, c2_i9,
    &c2_og_emlrtRTEI);
  c2_b_xwork[0] = c2_xwork->size[0];
  c2_i10 = c2_xwork->size[0];
  c2_xwork->size[0] = c2_b_xwork[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, &c2_c_st, c2_xwork, c2_i10,
    &c2_pg_emlrtRTEI);
  c2_c_loop_ub = c2_b_xwork[0] - 1;
  for (c2_i11 = 0; c2_i11 <= c2_c_loop_ub; c2_i11++) {
    c2_xwork->data[c2_i11] = 0.0F;
  }

  c2_nNaNs = 0;
  c2_ib = 0;
  c2_d_st.site = &c2_td_emlrtRSI;
  c2_b = c2_b_n;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_e_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
  }

  for (c2_k = 1; c2_k - 1 < c2_b_n; c2_k++) {
    c2_b_k = c2_k - 1;
    c2_f_x = c2_e_x->data[c2_b_k];
    c2_c_b = muSingleScalarIsNaN(c2_f_x);
    if (c2_c_b) {
      c2_b_idx->data[(c2_b_n - c2_nNaNs) - 1] = c2_b_k + 1;
      c2_xwork->data[(c2_b_n - c2_nNaNs) - 1] = c2_e_x->data[c2_b_k];
      c2_nNaNs++;
    } else {
      c2_ib++;
      c2_idx4[c2_ib - 1] = c2_b_k + 1;
      c2_x4[c2_ib - 1] = c2_e_x->data[c2_b_k];
      if (c2_ib == 4) {
        c2_quartetOffset = c2_b_k - c2_nNaNs;
        if (c2_x4[0] <= c2_x4[1]) {
          c2_b_i1 = 1;
          c2_b_i2 = 2;
        } else {
          c2_b_i1 = 2;
          c2_b_i2 = 1;
        }

        if (c2_x4[2] <= c2_x4[3]) {
          c2_b_i3 = 3;
          c2_b_i4 = 4;
        } else {
          c2_b_i3 = 4;
          c2_b_i4 = 3;
        }

        if (c2_x4[c2_b_i1 - 1] <= c2_x4[c2_b_i3 - 1]) {
          if (c2_x4[c2_b_i2 - 1] <= c2_x4[c2_b_i3 - 1]) {
            c2_perm[0] = c2_b_i1;
            c2_perm[1] = c2_b_i2;
            c2_perm[2] = c2_b_i3;
            c2_perm[3] = c2_b_i4;
          } else if (c2_x4[c2_b_i2 - 1] <= c2_x4[c2_b_i4 - 1]) {
            c2_perm[0] = c2_b_i1;
            c2_perm[1] = c2_b_i3;
            c2_perm[2] = c2_b_i2;
            c2_perm[3] = c2_b_i4;
          } else {
            c2_perm[0] = c2_b_i1;
            c2_perm[1] = c2_b_i3;
            c2_perm[2] = c2_b_i4;
            c2_perm[3] = c2_b_i2;
          }
        } else if (c2_x4[c2_b_i1 - 1] <= c2_x4[c2_b_i4 - 1]) {
          if (c2_x4[c2_b_i2 - 1] <= c2_x4[c2_b_i4 - 1]) {
            c2_perm[0] = c2_b_i3;
            c2_perm[1] = c2_b_i1;
            c2_perm[2] = c2_b_i2;
            c2_perm[3] = c2_b_i4;
          } else {
            c2_perm[0] = c2_b_i3;
            c2_perm[1] = c2_b_i1;
            c2_perm[2] = c2_b_i4;
            c2_perm[3] = c2_b_i2;
          }
        } else {
          c2_perm[0] = c2_b_i3;
          c2_perm[1] = c2_b_i4;
          c2_perm[2] = c2_b_i1;
          c2_perm[3] = c2_b_i2;
        }

        c2_b_idx->data[c2_quartetOffset - 3] = c2_idx4[c2_perm[0] - 1];
        c2_b_idx->data[c2_quartetOffset - 2] = c2_idx4[c2_perm[1] - 1];
        c2_b_idx->data[c2_quartetOffset - 1] = c2_idx4[c2_perm[2] - 1];
        c2_b_idx->data[c2_quartetOffset] = c2_idx4[c2_perm[3] - 1];
        c2_e_x->data[c2_quartetOffset - 3] = c2_x4[c2_perm[0] - 1];
        c2_e_x->data[c2_quartetOffset - 2] = c2_x4[c2_perm[1] - 1];
        c2_e_x->data[c2_quartetOffset - 1] = c2_x4[c2_perm[2] - 1];
        c2_e_x->data[c2_quartetOffset] = c2_x4[c2_perm[3] - 1];
        c2_ib = 0;
      }
    }
  }

  c2_wOffset = (c2_b_n - c2_nNaNs) - 1;
  if (c2_ib > 0) {
    c2_c_n = c2_ib;
    for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
      c2_perm[c2_i12] = 0;
    }

    if (c2_c_n == 1) {
      c2_perm[0] = 1;
    } else if (c2_c_n == 2) {
      if (c2_x4[0] <= c2_x4[1]) {
        c2_perm[0] = 1;
        c2_perm[1] = 2;
      } else {
        c2_perm[0] = 2;
        c2_perm[1] = 1;
      }
    } else if (c2_x4[0] <= c2_x4[1]) {
      if (c2_x4[1] <= c2_x4[2]) {
        c2_perm[0] = 1;
        c2_perm[1] = 2;
        c2_perm[2] = 3;
      } else if (c2_x4[0] <= c2_x4[2]) {
        c2_perm[0] = 1;
        c2_perm[1] = 3;
        c2_perm[2] = 2;
      } else {
        c2_perm[0] = 3;
        c2_perm[1] = 1;
        c2_perm[2] = 2;
      }
    } else if (c2_x4[0] <= c2_x4[2]) {
      c2_perm[0] = 2;
      c2_perm[1] = 1;
      c2_perm[2] = 3;
    } else if (c2_x4[1] <= c2_x4[2]) {
      c2_perm[0] = 2;
      c2_perm[1] = 3;
      c2_perm[2] = 1;
    } else {
      c2_perm[0] = 3;
      c2_perm[1] = 2;
      c2_perm[2] = 1;
    }

    c2_d_st.site = &c2_ud_emlrtRSI;
    c2_f_b = c2_ib;
    c2_g_b = c2_f_b;
    if (1 > c2_g_b) {
      c2_c_overflow = false;
    } else {
      c2_c_overflow = (c2_g_b > 2147483646);
    }

    if (c2_c_overflow) {
      c2_e_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
    }

    for (c2_d_k = 1; c2_d_k - 1 < c2_ib; c2_d_k++) {
      c2_b_k = c2_d_k;
      c2_b_idx->data[(c2_wOffset - c2_ib) + c2_b_k] = c2_idx4[c2_perm[c2_b_k - 1]
        - 1];
      c2_e_x->data[(c2_wOffset - c2_ib) + c2_b_k] = c2_x4[c2_perm[c2_b_k - 1] -
        1];
    }
  }

  c2_m = c2_nNaNs >> 1;
  c2_d_st.site = &c2_vd_emlrtRSI;
  c2_d_b = c2_m;
  c2_e_b = c2_d_b;
  if (1 > c2_e_b) {
    c2_b_overflow = false;
  } else {
    c2_b_overflow = (c2_e_b > 2147483646);
  }

  if (c2_b_overflow) {
    c2_e_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
  }

  for (c2_c_k = 1; c2_c_k - 1 < c2_m; c2_c_k++) {
    c2_b_k = c2_c_k;
    c2_itmp = c2_b_idx->data[c2_wOffset + c2_b_k];
    c2_b_idx->data[c2_wOffset + c2_b_k] = c2_b_idx->data[c2_b_n - c2_b_k];
    c2_b_idx->data[c2_b_n - c2_b_k] = c2_itmp;
    c2_e_x->data[c2_wOffset + c2_b_k] = c2_xwork->data[c2_b_n - c2_b_k];
    c2_e_x->data[c2_b_n - c2_b_k] = c2_xwork->data[c2_wOffset + c2_b_k];
  }

  if ((c2_nNaNs & 1) != 0) {
    c2_e_x->data[(c2_wOffset + c2_m) + 1] = c2_xwork->data[(c2_wOffset + c2_m) +
      1];
  }

  c2_nNonNaN = c2_n - c2_nNaNs;
  c2_preSortLevel = 2;
  if (c2_nNonNaN > 1) {
    if (c2_n >= 256) {
      c2_nBlocks = c2_nNonNaN >> 8;
      if (c2_nBlocks > 0) {
        c2_c_st.site = &c2_pd_emlrtRSI;
        c2_h_b = c2_nBlocks;
        c2_i_b = c2_h_b;
        if (1 > c2_i_b) {
          c2_d_overflow = false;
        } else {
          c2_d_overflow = (c2_i_b > 2147483646);
        }

        if (c2_d_overflow) {
          c2_d_st.site = &c2_hc_emlrtRSI;
          c2_check_forloop_overflow_error(chartInstance, &c2_d_st);
        }

        for (c2_j_b = 1; c2_j_b - 1 < c2_nBlocks; c2_j_b++) {
          c2_k_b = c2_j_b - 1;
          c2_c_st.site = &c2_qd_emlrtRSI;
          c2_c_merge_pow2_block(chartInstance, &c2_c_st, c2_b_idx, c2_e_x,
                                c2_k_b << 8);
        }

        c2_tailOffset = c2_nBlocks << 8;
        c2_nLastBlock = c2_nNonNaN - c2_tailOffset;
        if (c2_nLastBlock > 0) {
          c2_c_st.site = &c2_rd_emlrtRSI;
          c2_c_merge_block(chartInstance, &c2_c_st, c2_b_idx, c2_e_x,
                           c2_tailOffset, c2_nLastBlock, 2, c2_b_iwork, c2_xwork);
        }

        c2_preSortLevel = 8;
      }
    }

    c2_c_st.site = &c2_sd_emlrtRSI;
    c2_c_merge_block(chartInstance, &c2_c_st, c2_b_idx, c2_e_x, 0, c2_nNonNaN,
                     c2_preSortLevel, c2_b_iwork, c2_xwork);
  }

  c2_emxFree_real32_T(chartInstance, &c2_xwork);
  c2_emxFree_int32_T(chartInstance, &c2_b_iwork);
  c2_emxFree_int32_T(chartInstance, &c2_b_idx);
}

static void c2_c_merge_pow2_block(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx,
  c2_emxArray_real32_T *c2_e_x, int32_T c2_offset)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_b_iwork[256];
  int32_T c2_b;
  int32_T c2_bLen;
  int32_T c2_bLen2;
  int32_T c2_b_b;
  int32_T c2_b_j;
  int32_T c2_b_k;
  int32_T c2_blockOffset;
  int32_T c2_c_b;
  int32_T c2_c_j;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_exitg1;
  int32_T c2_f_b;
  int32_T c2_g_b;
  int32_T c2_iout;
  int32_T c2_j;
  int32_T c2_k;
  int32_T c2_nPairs;
  int32_T c2_offset1;
  int32_T c2_p;
  int32_T c2_q;
  real32_T c2_xwork[256];
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  for (c2_b = 0; c2_b < 6; c2_b++) {
    c2_bLen = 1 << (c2_b + 2);
    c2_bLen2 = c2_bLen << 1;
    c2_nPairs = 256 >> (c2_b + 3);
    c2_st.site = &c2_wd_emlrtRSI;
    c2_b_b = c2_nPairs;
    c2_c_b = c2_b_b;
    if (1 > c2_c_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_c_b > 2147483646);
    }

    if (c2_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }

    for (c2_k = 1; c2_k - 1 < c2_nPairs; c2_k++) {
      c2_b_k = c2_k - 1;
      c2_blockOffset = (c2_offset + c2_b_k * c2_bLen2) - 1;
      c2_st.site = &c2_xd_emlrtRSI;
      c2_d_b = c2_bLen2;
      c2_e_b = c2_d_b;
      if (1 > c2_e_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_e_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_b_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
      }

      for (c2_j = 1; c2_j - 1 < c2_bLen2; c2_j++) {
        c2_b_j = c2_j;
        c2_b_iwork[c2_b_j - 1] = c2_b_idx->data[c2_blockOffset + c2_b_j];
        c2_xwork[c2_b_j - 1] = c2_e_x->data[c2_blockOffset + c2_b_j];
      }

      c2_p = 0;
      c2_q = c2_bLen;
      c2_iout = c2_blockOffset;
      do {
        c2_exitg1 = 0;
        c2_iout++;
        if (c2_xwork[c2_p] <= c2_xwork[c2_q]) {
          c2_b_idx->data[c2_iout] = c2_b_iwork[c2_p];
          c2_e_x->data[c2_iout] = c2_xwork[c2_p];
          if (c2_p + 1 < c2_bLen) {
            c2_p++;
          } else {
            c2_exitg1 = 1;
          }
        } else {
          c2_b_idx->data[c2_iout] = c2_b_iwork[c2_q];
          c2_e_x->data[c2_iout] = c2_xwork[c2_q];
          if (c2_q + 1 < c2_bLen2) {
            c2_q++;
          } else {
            c2_offset1 = c2_iout - c2_p;
            c2_st.site = &c2_yd_emlrtRSI;
            c2_d_a = c2_p + 1;
            c2_f_b = c2_bLen;
            c2_e_a = c2_d_a;
            c2_g_b = c2_f_b;
            if (c2_e_a > c2_g_b) {
              c2_c_overflow = false;
            } else {
              c2_c_overflow = (c2_g_b > 2147483646);
            }

            if (c2_c_overflow) {
              c2_b_st.site = &c2_hc_emlrtRSI;
              c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
            }

            for (c2_c_j = c2_p + 1; c2_c_j <= c2_bLen; c2_c_j++) {
              c2_b_idx->data[c2_offset1 + c2_c_j] = c2_b_iwork[c2_c_j - 1];
              c2_e_x->data[c2_offset1 + c2_c_j] = c2_xwork[c2_c_j - 1];
            }

            c2_exitg1 = 1;
          }
        }
      } while (c2_exitg1 == 0);
    }
  }
}

static void c2_c_merge_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T
  *c2_e_x, int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel,
  c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real32_T *c2_xwork)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_b;
  int32_T c2_bLen;
  int32_T c2_bLen2;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_k;
  int32_T c2_nBlocks;
  int32_T c2_nPairs;
  int32_T c2_nTail;
  int32_T c2_tailOffset;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_nBlocks = c2_n >> c2_preSortLevel;
  c2_bLen = 1 << c2_preSortLevel;
  while (c2_nBlocks > 1) {
    if ((c2_nBlocks & 1) != 0) {
      c2_nBlocks--;
      c2_tailOffset = c2_bLen * c2_nBlocks;
      c2_nTail = c2_n - c2_tailOffset;
      if (c2_nTail > c2_bLen) {
        c2_st.site = &c2_ae_emlrtRSI;
        c2_c_merge(chartInstance, &c2_st, c2_b_idx, c2_e_x, c2_offset +
                   c2_tailOffset, c2_bLen, c2_nTail - c2_bLen, c2_b_iwork,
                   c2_xwork);
      }
    }

    c2_bLen2 = c2_bLen << 1;
    c2_nPairs = c2_nBlocks >> 1;
    c2_st.site = &c2_be_emlrtRSI;
    c2_b = c2_nPairs;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }

    for (c2_k = 1; c2_k - 1 < c2_nPairs; c2_k++) {
      c2_b_k = c2_k - 1;
      c2_st.site = &c2_ce_emlrtRSI;
      c2_c_merge(chartInstance, &c2_st, c2_b_idx, c2_e_x, c2_offset + c2_b_k *
                 c2_bLen2, c2_bLen, c2_bLen, c2_b_iwork, c2_xwork);
    }

    c2_bLen = c2_bLen2;
    c2_nBlocks = c2_nPairs;
  }

  if (c2_n > c2_bLen) {
    c2_st.site = &c2_de_emlrtRSI;
    c2_c_merge(chartInstance, &c2_st, c2_b_idx, c2_e_x, c2_offset, c2_bLen, c2_n
               - c2_bLen, c2_b_iwork, c2_xwork);
  }
}

static void c2_c_merge(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_e_x,
  int32_T c2_offset, int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T
  *c2_b_iwork, c2_emxArray_real32_T *c2_xwork)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_j;
  int32_T c2_c_b;
  int32_T c2_c_j;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_exitg1;
  int32_T c2_iout;
  int32_T c2_j;
  int32_T c2_n;
  int32_T c2_offset1;
  int32_T c2_p;
  int32_T c2_q;
  int32_T c2_qend;
  boolean_T c2_b_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  if (c2_nq != 0) {
    c2_n = c2_np + c2_nq;
    c2_st.site = &c2_fe_emlrtRSI;
    c2_b = c2_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }

    for (c2_j = 1; c2_j - 1 < c2_n; c2_j++) {
      c2_b_j = c2_j - 1;
      c2_b_iwork->data[c2_b_j] = c2_b_idx->data[c2_offset + c2_b_j];
      c2_xwork->data[c2_b_j] = c2_e_x->data[c2_offset + c2_b_j];
    }

    c2_p = 0;
    c2_q = c2_np;
    c2_qend = c2_np + c2_nq;
    c2_iout = c2_offset - 1;
    do {
      c2_exitg1 = 0;
      c2_iout++;
      if (c2_xwork->data[c2_p] <= c2_xwork->data[c2_q]) {
        c2_b_idx->data[c2_iout] = c2_b_iwork->data[c2_p];
        c2_e_x->data[c2_iout] = c2_xwork->data[c2_p];
        if (c2_p + 1 < c2_np) {
          c2_p++;
        } else {
          c2_exitg1 = 1;
        }
      } else {
        c2_b_idx->data[c2_iout] = c2_b_iwork->data[c2_q];
        c2_e_x->data[c2_iout] = c2_xwork->data[c2_q];
        if (c2_q + 1 < c2_qend) {
          c2_q++;
        } else {
          c2_offset1 = c2_iout - c2_p;
          c2_st.site = &c2_ee_emlrtRSI;
          c2_d_a = c2_p + 1;
          c2_c_b = c2_np;
          c2_e_a = c2_d_a;
          c2_d_b = c2_c_b;
          if (c2_e_a > c2_d_b) {
            c2_b_overflow = false;
          } else {
            c2_b_overflow = (c2_d_b > 2147483646);
          }

          if (c2_b_overflow) {
            c2_b_st.site = &c2_hc_emlrtRSI;
            c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
          }

          for (c2_c_j = c2_p + 1; c2_c_j <= c2_np; c2_c_j++) {
            c2_b_idx->data[c2_offset1 + c2_c_j] = c2_b_iwork->data[c2_c_j - 1];
            c2_e_x->data[c2_offset1 + c2_c_j] = c2_xwork->data[c2_c_j - 1];
          }

          c2_exitg1 = 1;
        }
      }
    } while (c2_exitg1 == 0);
  }
}

static void c2_b_ComputeWeightedCentroid(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_c_I[307200],
  c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_stats, c2_sHtk0WM4OMtyqkehwQYcq2
  *c2_statsAlreadyComputed)
{
  static char_T c2_b_cv[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  c2_cell_wrap_46 c2_reshapes[2];
  c2_emxArray_int32_T *c2_b_idx;
  c2_emxArray_int32_T *c2_varargout_4;
  c2_emxArray_int32_T *c2_vk;
  c2_emxArray_real_T *c2_Intensity;
  c2_emxArray_real_T *c2_b_Intensity;
  c2_emxArray_real_T *c2_c;
  c2_emxArray_real_T *c2_r;
  c2_emxArray_real_T *c2_r1;
  c2_emxArray_real_T *c2_r2;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  real_T c2_wc[2];
  real_T c2_M;
  real_T c2_b_k;
  real_T c2_b_n;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_d3;
  real_T c2_d_idx;
  real_T c2_d_k;
  real_T c2_f_k;
  real_T c2_sumIntensity;
  int32_T c2_sizes[2];
  int32_T c2_ab_loop_ub;
  int32_T c2_b_loop_ub;
  int32_T c2_b_stats;
  int32_T c2_bb_loop_ub;
  int32_T c2_c_idx;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_c_n;
  int32_T c2_c_stats;
  int32_T c2_cb_loop_ub;
  int32_T c2_d_loop_ub;
  int32_T c2_d_stats;
  int32_T c2_db_loop_ub;
  int32_T c2_e_k;
  int32_T c2_e_loop_ub;
  int32_T c2_e_stats;
  int32_T c2_eb_loop_ub;
  int32_T c2_expected;
  int32_T c2_f_loop_ub;
  int32_T c2_fb_loop_ub;
  int32_T c2_g_loop_ub;
  int32_T c2_gb_loop_ub;
  int32_T c2_h_loop_ub;
  int32_T c2_hb_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  int32_T c2_i103;
  int32_T c2_i104;
  int32_T c2_i105;
  int32_T c2_i106;
  int32_T c2_i107;
  int32_T c2_i108;
  int32_T c2_i109;
  int32_T c2_i11;
  int32_T c2_i110;
  int32_T c2_i111;
  int32_T c2_i112;
  int32_T c2_i113;
  int32_T c2_i114;
  int32_T c2_i115;
  int32_T c2_i116;
  int32_T c2_i117;
  int32_T c2_i118;
  int32_T c2_i119;
  int32_T c2_i12;
  int32_T c2_i120;
  int32_T c2_i121;
  int32_T c2_i122;
  int32_T c2_i123;
  int32_T c2_i124;
  int32_T c2_i125;
  int32_T c2_i126;
  int32_T c2_i127;
  int32_T c2_i128;
  int32_T c2_i129;
  int32_T c2_i13;
  int32_T c2_i130;
  int32_T c2_i131;
  int32_T c2_i132;
  int32_T c2_i133;
  int32_T c2_i134;
  int32_T c2_i135;
  int32_T c2_i136;
  int32_T c2_i137;
  int32_T c2_i138;
  int32_T c2_i139;
  int32_T c2_i14;
  int32_T c2_i140;
  int32_T c2_i141;
  int32_T c2_i142;
  int32_T c2_i143;
  int32_T c2_i144;
  int32_T c2_i145;
  int32_T c2_i146;
  int32_T c2_i147;
  int32_T c2_i148;
  int32_T c2_i149;
  int32_T c2_i15;
  int32_T c2_i150;
  int32_T c2_i151;
  int32_T c2_i152;
  int32_T c2_i153;
  int32_T c2_i154;
  int32_T c2_i155;
  int32_T c2_i156;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i5;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i6;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i7;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i8;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  int32_T c2_i9;
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_i_loop_ub;
  int32_T c2_ib_loop_ub;
  int32_T c2_j_loop_ub;
  int32_T c2_k;
  int32_T c2_k_loop_ub;
  int32_T c2_l_loop_ub;
  int32_T c2_loop_ub;
  int32_T c2_m_loop_ub;
  int32_T c2_n;
  int32_T c2_n_loop_ub;
  int32_T c2_o_loop_ub;
  int32_T c2_p_loop_ub;
  int32_T c2_q_loop_ub;
  int32_T c2_r_loop_ub;
  int32_T c2_result;
  int32_T c2_s_loop_ub;
  int32_T c2_t_loop_ub;
  int32_T c2_u_loop_ub;
  int32_T c2_v_loop_ub;
  int32_T c2_w_loop_ub;
  int32_T c2_x_loop_ub;
  int32_T c2_y_loop_ub;
  boolean_T c2_b;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_statsAlreadyComputed->WeightedCentroid = true;
  c2_st.site = &c2_vg_emlrtRSI;
  c2_statsAlreadyComputed->PixelList = true;
  c2_d = (real_T)c2_stats->size[0];
  c2_i = (int32_T)c2_d - 1;
  c2_k = 0;
  c2_emxInit_real_T1(chartInstance, &c2_st, &c2_Intensity, 1, &c2_wg_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_st, &c2_r, 1, &c2_wf_emlrtRTEI);
  c2_emxInitMatrix_cell_wrap_46(chartInstance, &c2_st, c2_reshapes,
    &c2_nh_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_st, &c2_c, 1, &c2_oh_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_st, &c2_varargout_4, 1, &c2_wf_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_st, &c2_b_idx, 1, &c2_vg_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_st, &c2_vk, 1, &c2_ch_emlrtRTEI);
  while (c2_k <= c2_i) {
    c2_b_k = (real_T)c2_k + 1.0;
    c2_i1 = c2_r->size[0];
    c2_i2 = c2_stats->size[0];
    c2_i3 = (int32_T)c2_b_k;
    if ((c2_i3 < 1) || (c2_i3 > c2_i2)) {
      emlrtDynamicBoundsCheckR2012b(c2_i3, 1, c2_i2, &c2_gf_emlrtBCI, &c2_st);
    }

    c2_r->size[0] = c2_stats->data[c2_i3 - 1].PixelIdxList->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_r, c2_i1,
      &c2_rg_emlrtRTEI);
    c2_i5 = c2_stats->size[0];
    c2_i7 = (int32_T)c2_b_k;
    if ((c2_i7 < 1) || (c2_i7 > c2_i5)) {
      emlrtDynamicBoundsCheckR2012b(c2_i7, 1, c2_i5, &c2_gf_emlrtBCI, &c2_st);
    }

    c2_loop_ub = c2_stats->data[c2_i7 - 1].PixelIdxList->size[0] - 1;
    for (c2_i11 = 0; c2_i11 <= c2_loop_ub; c2_i11++) {
      c2_i12 = c2_stats->size[0];
      c2_i15 = (int32_T)c2_b_k;
      if ((c2_i15 < 1) || (c2_i15 > c2_i12)) {
        emlrtDynamicBoundsCheckR2012b(c2_i15, 1, c2_i12, &c2_gf_emlrtBCI, &c2_st);
      }

      c2_r->data[c2_i11] = c2_stats->data[c2_i15 - 1].PixelIdxList->data[c2_i11];
    }

    if (c2_r->size[0] != 0) {
      c2_b_st.site = &c2_xg_emlrtRSI;
      c2_i18 = c2_Intensity->size[0];
      c2_i19 = c2_stats->size[0];
      c2_i20 = (int32_T)c2_b_k;
      if ((c2_i20 < 1) || (c2_i20 > c2_i19)) {
        emlrtDynamicBoundsCheckR2012b(c2_i20, 1, c2_i19, &c2_hf_emlrtBCI,
          &c2_b_st);
      }

      c2_Intensity->size[0] = c2_stats->data[c2_i20 - 1].PixelIdxList->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_Intensity, c2_i18,
        &c2_sg_emlrtRTEI);
      c2_i31 = c2_stats->size[0];
      c2_i33 = (int32_T)c2_b_k;
      if ((c2_i33 < 1) || (c2_i33 > c2_i31)) {
        emlrtDynamicBoundsCheckR2012b(c2_i33, 1, c2_i31, &c2_hf_emlrtBCI,
          &c2_b_st);
      }

      c2_c_loop_ub = c2_stats->data[c2_i33 - 1].PixelIdxList->size[0] - 1;
      for (c2_i39 = 0; c2_i39 <= c2_c_loop_ub; c2_i39++) {
        c2_i42 = c2_stats->size[0];
        c2_i44 = (int32_T)c2_b_k;
        if ((c2_i44 < 1) || (c2_i44 > c2_i42)) {
          emlrtDynamicBoundsCheckR2012b(c2_i44, 1, c2_i42, &c2_hf_emlrtBCI,
            &c2_b_st);
        }

        c2_Intensity->data[c2_i39] = c2_stats->data[c2_i44 - 1]
          .PixelIdxList->data[c2_i39];
      }

      c2_c_st.site = &c2_yg_emlrtRSI;
      c2_i43 = c2_b_idx->size[0];
      c2_b_idx->size[0] = c2_Intensity->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_idx, c2_i43,
        &c2_vg_emlrtRTEI);
      c2_e_loop_ub = c2_Intensity->size[0] - 1;
      for (c2_i52 = 0; c2_i52 <= c2_e_loop_ub; c2_i52++) {
        c2_b_idx->data[c2_i52] = (int32_T)c2_Intensity->data[c2_i52];
      }

      c2_i54 = c2_b_idx->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_idx, c2_i54,
        &c2_yg_emlrtRTEI);
      c2_g_loop_ub = c2_b_idx->size[0] - 1;
      for (c2_i58 = 0; c2_i58 <= c2_g_loop_ub; c2_i58++) {
        c2_b_idx->data[c2_i58]--;
      }

      c2_i59 = c2_vk->size[0];
      c2_vk->size[0] = c2_b_idx->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_vk, c2_i59,
        &c2_ch_emlrtRTEI);
      c2_i_loop_ub = c2_b_idx->size[0] - 1;
      for (c2_i64 = 0; c2_i64 <= c2_i_loop_ub; c2_i64++) {
        c2_vk->data[c2_i64] = c2_div_nzp_s32(chartInstance, c2_b_idx->
          data[c2_i64], 480, 0, 1U, 0, 0);
      }

      c2_i67 = c2_varargout_4->size[0];
      c2_varargout_4->size[0] = c2_vk->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_varargout_4,
        c2_i67, &c2_dh_emlrtRTEI);
      c2_k_loop_ub = c2_vk->size[0] - 1;
      for (c2_i72 = 0; c2_i72 <= c2_k_loop_ub; c2_i72++) {
        c2_varargout_4->data[c2_i72] = c2_vk->data[c2_i72] + 1;
      }

      c2_i75 = c2_vk->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_vk, c2_i75,
        &c2_eh_emlrtRTEI);
      c2_m_loop_ub = c2_vk->size[0] - 1;
      for (c2_i79 = 0; c2_i79 <= c2_m_loop_ub; c2_i79++) {
        c2_vk->data[c2_i79] *= 480;
      }

      c2_i81 = c2_b_idx->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_idx, c2_i81,
        &c2_gh_emlrtRTEI);
      c2_o_loop_ub = c2_b_idx->size[0] - 1;
      for (c2_i85 = 0; c2_i85 <= c2_o_loop_ub; c2_i85++) {
        c2_b_idx->data[c2_i85] -= c2_vk->data[c2_i85];
      }

      c2_i87 = c2_b_idx->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_idx, c2_i87,
        &c2_hh_emlrtRTEI);
      c2_p_loop_ub = c2_b_idx->size[0] - 1;
      for (c2_i91 = 0; c2_i91 <= c2_p_loop_ub; c2_i91++) {
        c2_b_idx->data[c2_i91]++;
      }

      c2_i93 = c2_Intensity->size[0];
      c2_Intensity->size[0] = c2_b_idx->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_Intensity, c2_i93,
        &c2_ih_emlrtRTEI);
      c2_t_loop_ub = c2_b_idx->size[0] - 1;
      for (c2_i98 = 0; c2_i98 <= c2_t_loop_ub; c2_i98++) {
        c2_Intensity->data[c2_i98] = (real_T)c2_b_idx->data[c2_i98];
      }

      c2_i103 = c2_c->size[0];
      c2_c->size[0] = c2_varargout_4->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_c, c2_i103,
        &c2_ih_emlrtRTEI);
      c2_v_loop_ub = c2_varargout_4->size[0] - 1;
      for (c2_i106 = 0; c2_i106 <= c2_v_loop_ub; c2_i106++) {
        c2_c->data[c2_i106] = (real_T)c2_varargout_4->data[c2_i106];
      }

      c2_b_st.site = &c2_wg_emlrtRSI;
      c2_c_st.site = &c2_ah_emlrtRSI;
      c2_result = c2_c->size[0];
      c2_sizes[0] = c2_result;
      c2_d_st.site = &c2_bh_emlrtRSI;
      c2_expected = c2_sizes[0];
      if (c2_c->size[0] == c2_expected) {
        c2_b = true;
      } else {
        c2_b = false;
      }

      if (!c2_b) {
        c2_b_y = NULL;
        sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c2_c_y = NULL;
        sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c2_d_st, &c2_o_emlrtMCI, "error", 0U, 2U, 14, c2_b_y, 14,
                    sf_mex_call(&c2_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c2_d_st, NULL, "message", 1U, 1U, 14, c2_c_y)));
      }

      if (c2_Intensity->size[0] == c2_expected) {
        c2_b = true;
      } else {
        c2_b = false;
      }

      if (!c2_b) {
        c2_d_y = NULL;
        sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c2_e_y = NULL;
        sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call(&c2_d_st, &c2_o_emlrtMCI, "error", 0U, 2U, 14, c2_d_y, 14,
                    sf_mex_call(&c2_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c2_d_st, NULL, "message", 1U, 1U, 14, c2_e_y)));
      }

      c2_i119 = c2_reshapes[0].f1->size[0];
      c2_reshapes[0].f1->size[0] = c2_c->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_c_st, c2_reshapes[0].f1,
        c2_i119, &c2_kh_emlrtRTEI);
      c2_cb_loop_ub = c2_c->size[0] - 1;
      for (c2_i122 = 0; c2_i122 <= c2_cb_loop_ub; c2_i122++) {
        c2_reshapes[0].f1->data[c2_i122] = c2_c->data[c2_i122];
      }

      c2_i123 = c2_reshapes[1].f1->size[0];
      c2_reshapes[1].f1->size[0] = c2_Intensity->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_c_st, c2_reshapes[1].f1,
        c2_i123, &c2_kh_emlrtRTEI);
      c2_db_loop_ub = c2_Intensity->size[0] - 1;
      for (c2_i126 = 0; c2_i126 <= c2_db_loop_ub; c2_i126++) {
        c2_reshapes[1].f1->data[c2_i126] = c2_Intensity->data[c2_i126];
      }

      c2_i128 = c2_Intensity->size[0];
      c2_Intensity->size[0] = c2_reshapes[0].f1->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_c_st, c2_Intensity,
        c2_i128, &c2_lh_emlrtRTEI);
      c2_fb_loop_ub = c2_reshapes[0].f1->size[0] - 1;
      for (c2_i132 = 0; c2_i132 <= c2_fb_loop_ub; c2_i132++) {
        c2_Intensity->data[c2_i132] = c2_reshapes[0].f1->data[c2_i132];
      }

      c2_i133 = c2_c->size[0];
      c2_c->size[0] = c2_reshapes[1].f1->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_c_st, c2_c, c2_i133,
        &c2_lh_emlrtRTEI);
      c2_gb_loop_ub = c2_reshapes[1].f1->size[0] - 1;
      for (c2_i136 = 0; c2_i136 <= c2_gb_loop_ub; c2_i136++) {
        c2_c->data[c2_i136] = c2_reshapes[1].f1->data[c2_i136];
      }

      c2_e_stats = c2_stats->size[0];
      c2_i139 = (int32_T)c2_b_k;
      if ((c2_i139 < 1) || (c2_i139 > c2_e_stats)) {
        emlrtDynamicBoundsCheckR2012b(c2_i139, 1, c2_e_stats, &c2_ff_emlrtBCI,
          &c2_c_st);
      }

      c2_i141 = c2_i139 - 1;
      c2_i143 = c2_stats->data[c2_i141].PixelList->size[0] * c2_stats->
        data[c2_i141].PixelList->size[1];
      c2_stats->data[c2_i141].PixelList->size[0] = c2_Intensity->size[0];
      c2_i144 = (int32_T)c2_b_k;
      if ((c2_i144 < 1) || (c2_i144 > c2_e_stats)) {
        emlrtDynamicBoundsCheckR2012b(c2_i144, 1, c2_e_stats, &c2_ff_emlrtBCI,
          &c2_c_st);
      }

      c2_i147 = c2_i144 - 1;
      c2_stats->data[c2_i147].PixelList->size[1] = 2;
      c2_emxEnsureCapacity_real_T(chartInstance, &c2_c_st, c2_stats->
        data[c2_i147].PixelList, c2_i143, &c2_mh_emlrtRTEI);
      c2_hb_loop_ub = c2_Intensity->size[0] - 1;
      for (c2_i149 = 0; c2_i149 <= c2_hb_loop_ub; c2_i149++) {
        c2_i152 = (int32_T)c2_b_k;
        if ((c2_i152 < 1) || (c2_i152 > c2_e_stats)) {
          emlrtDynamicBoundsCheckR2012b(c2_i152, 1, c2_e_stats, &c2_ff_emlrtBCI,
            &c2_c_st);
        }

        c2_i155 = (int32_T)c2_b_k;
        if ((c2_i155 < 1) || (c2_i155 > c2_e_stats)) {
          emlrtDynamicBoundsCheckR2012b(c2_i155, 1, c2_e_stats, &c2_ff_emlrtBCI,
            &c2_c_st);
        }

        c2_stats->data[c2_i152 - 1].PixelList->data[c2_i149] =
          c2_Intensity->data[c2_i149];
      }

      c2_ib_loop_ub = c2_c->size[0] - 1;
      for (c2_i153 = 0; c2_i153 <= c2_ib_loop_ub; c2_i153++) {
        c2_i154 = (int32_T)c2_b_k;
        if ((c2_i154 < 1) || (c2_i154 > c2_e_stats)) {
          emlrtDynamicBoundsCheckR2012b(c2_i154, 1, c2_e_stats, &c2_ff_emlrtBCI,
            &c2_c_st);
        }

        c2_i156 = (int32_T)c2_b_k;
        if ((c2_i156 < 1) || (c2_i156 > c2_e_stats)) {
          emlrtDynamicBoundsCheckR2012b(c2_i156, 1, c2_e_stats, &c2_ff_emlrtBCI,
            &c2_c_st);
        }

        c2_stats->data[c2_i154 - 1].PixelList->data[c2_i153 + c2_stats->
          data[c2_i156 - 1].PixelList->size[0]] = c2_c->data[c2_i153];
      }
    } else {
      c2_i14 = c2_stats->size[0];
      c2_i17 = (int32_T)c2_b_k;
      if ((c2_i17 < 1) || (c2_i17 > c2_i14)) {
        emlrtDynamicBoundsCheckR2012b(c2_i17, 1, c2_i14, &c2_xe_emlrtBCI, &c2_st);
      }

      c2_i21 = c2_i17 - 1;
      c2_stats->data[c2_i21].PixelList->size[0] = 0;
      c2_i25 = c2_stats->size[0];
      c2_i28 = (int32_T)c2_b_k;
      if ((c2_i28 < 1) || (c2_i28 > c2_i25)) {
        emlrtDynamicBoundsCheckR2012b(c2_i28, 1, c2_i25, &c2_xe_emlrtBCI, &c2_st);
      }

      c2_i34 = c2_i28 - 1;
      c2_i35 = c2_stats->data[c2_i34].PixelList->size[0] * c2_stats->data[c2_i34]
        .PixelList->size[1];
      c2_stats->data[c2_i34].PixelList->size[1] = 2;
      c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_stats->data[c2_i34].
        PixelList, c2_i35, &c2_ug_emlrtRTEI);
      c2_b_stats = c2_stats->size[0];
      c2_i41 = (int32_T)c2_b_k;
      if ((c2_i41 < 1) || (c2_i41 > c2_b_stats)) {
        emlrtDynamicBoundsCheckR2012b(c2_i41, 1, c2_b_stats, &c2_xe_emlrtBCI,
          &c2_st);
      }

      c2_c_stats = c2_stats->size[0];
      c2_i49 = (int32_T)c2_b_k;
      if ((c2_i49 < 1) || (c2_i49 > c2_c_stats)) {
        emlrtDynamicBoundsCheckR2012b(c2_i49, 1, c2_c_stats, &c2_xe_emlrtBCI,
          &c2_st);
      }
    }

    c2_k++;
  }

  c2_emxFreeMatrix_cell_wrap_46(chartInstance, c2_reshapes);
  c2_st.site = &c2_ug_emlrtRSI;
  c2_statsAlreadyComputed->PixelValues = true;
  c2_d1 = (real_T)c2_stats->size[0];
  c2_i4 = (int32_T)c2_d1 - 1;
  for (c2_c_k = 0; c2_c_k <= c2_i4; c2_c_k++) {
    c2_d_k = (real_T)c2_c_k + 1.0;
    c2_i6 = c2_r->size[0];
    c2_i8 = c2_stats->size[0];
    c2_i9 = (int32_T)c2_d_k;
    if ((c2_i9 < 1) || (c2_i9 > c2_i8)) {
      emlrtDynamicBoundsCheckR2012b(c2_i9, 1, c2_i8, &c2_if_emlrtBCI, &c2_st);
    }

    c2_r->size[0] = c2_stats->data[c2_i9 - 1].PixelIdxList->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_r, c2_i6,
      &c2_tg_emlrtRTEI);
    c2_i13 = c2_stats->size[0];
    c2_i16 = (int32_T)c2_d_k;
    if ((c2_i16 < 1) || (c2_i16 > c2_i13)) {
      emlrtDynamicBoundsCheckR2012b(c2_i16, 1, c2_i13, &c2_if_emlrtBCI, &c2_st);
    }

    c2_b_loop_ub = c2_stats->data[c2_i16 - 1].PixelIdxList->size[0] - 1;
    for (c2_i23 = 0; c2_i23 <= c2_b_loop_ub; c2_i23++) {
      c2_i27 = c2_stats->size[0];
      c2_i30 = (int32_T)c2_d_k;
      if ((c2_i30 < 1) || (c2_i30 > c2_i27)) {
        emlrtDynamicBoundsCheckR2012b(c2_i30, 1, c2_i27, &c2_if_emlrtBCI, &c2_st);
      }

      c2_r->data[c2_i23] = c2_stats->data[c2_i30 - 1].PixelIdxList->data[c2_i23];
    }

    c2_wc[0] = (real_T)c2_r->size[0];
    c2_i29 = c2_stats->size[0];
    c2_i32 = (int32_T)c2_d_k;
    if ((c2_i32 < 1) || (c2_i32 > c2_i29)) {
      emlrtDynamicBoundsCheckR2012b(c2_i32, 1, c2_i29, &c2_we_emlrtBCI, &c2_st);
    }

    c2_i36 = c2_i32;
    c2_i38 = c2_stats->data[c2_i36 - 1].PixelValues->size[0];
    c2_stats->data[c2_i36 - 1].PixelValues->size[0] = (int32_T)c2_wc[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_stats->data[c2_i36 -
      1].PixelValues, c2_i38, &c2_xg_emlrtRTEI);
    c2_b_st.site = &c2_ch_emlrtRSI;
    c2_i45 = c2_Intensity->size[0];
    c2_i47 = c2_stats->size[0];
    c2_i48 = (int32_T)c2_d_k;
    if ((c2_i48 < 1) || (c2_i48 > c2_i47)) {
      emlrtDynamicBoundsCheckR2012b(c2_i48, 1, c2_i47, &c2_lf_emlrtBCI, &c2_b_st);
    }

    c2_Intensity->size[0] = c2_stats->data[c2_i48 - 1].PixelIdxList->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_Intensity, c2_i45,
      &c2_bh_emlrtRTEI);
    c2_i55 = c2_stats->size[0];
    c2_i57 = (int32_T)c2_d_k;
    if ((c2_i57 < 1) || (c2_i57 > c2_i55)) {
      emlrtDynamicBoundsCheckR2012b(c2_i57, 1, c2_i55, &c2_lf_emlrtBCI, &c2_b_st);
    }

    c2_h_loop_ub = c2_stats->data[c2_i57 - 1].PixelIdxList->size[0] - 1;
    for (c2_i61 = 0; c2_i61 <= c2_h_loop_ub; c2_i61++) {
      c2_i63 = c2_stats->size[0];
      c2_i66 = (int32_T)c2_d_k;
      if ((c2_i66 < 1) || (c2_i66 > c2_i63)) {
        emlrtDynamicBoundsCheckR2012b(c2_i66, 1, c2_i63, &c2_lf_emlrtBCI,
          &c2_b_st);
      }

      c2_Intensity->data[c2_i61] = c2_stats->data[c2_i66 - 1].PixelIdxList->
        data[c2_i61];
    }

    c2_c_st.site = &c2_yg_emlrtRSI;
    c2_i65 = c2_b_idx->size[0];
    c2_b_idx->size[0] = c2_Intensity->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_idx, c2_i65,
      &c2_vg_emlrtRTEI);
    c2_j_loop_ub = c2_Intensity->size[0] - 1;
    for (c2_i70 = 0; c2_i70 <= c2_j_loop_ub; c2_i70++) {
      c2_b_idx->data[c2_i70] = (int32_T)c2_Intensity->data[c2_i70];
    }

    c2_i74 = c2_b_idx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_idx, c2_i74,
      &c2_yg_emlrtRTEI);
    c2_l_loop_ub = c2_b_idx->size[0] - 1;
    for (c2_i78 = 0; c2_i78 <= c2_l_loop_ub; c2_i78++) {
      c2_b_idx->data[c2_i78]--;
    }

    c2_i80 = c2_vk->size[0];
    c2_vk->size[0] = c2_b_idx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_vk, c2_i80,
      &c2_ch_emlrtRTEI);
    c2_n_loop_ub = c2_b_idx->size[0] - 1;
    for (c2_i84 = 0; c2_i84 <= c2_n_loop_ub; c2_i84++) {
      c2_vk->data[c2_i84] = c2_div_nzp_s32(chartInstance, c2_b_idx->data[c2_i84],
        480, 0, 1U, 0, 0);
    }

    c2_i86 = c2_varargout_4->size[0];
    c2_varargout_4->size[0] = c2_vk->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_varargout_4, c2_i86,
      &c2_dh_emlrtRTEI);
    c2_q_loop_ub = c2_vk->size[0] - 1;
    for (c2_i92 = 0; c2_i92 <= c2_q_loop_ub; c2_i92++) {
      c2_varargout_4->data[c2_i92] = c2_vk->data[c2_i92] + 1;
    }

    c2_i95 = c2_vk->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_vk, c2_i95,
      &c2_eh_emlrtRTEI);
    c2_s_loop_ub = c2_vk->size[0] - 1;
    for (c2_i97 = 0; c2_i97 <= c2_s_loop_ub; c2_i97++) {
      c2_vk->data[c2_i97] *= 480;
    }

    c2_i102 = c2_b_idx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_idx, c2_i102,
      &c2_gh_emlrtRTEI);
    c2_u_loop_ub = c2_b_idx->size[0] - 1;
    for (c2_i105 = 0; c2_i105 <= c2_u_loop_ub; c2_i105++) {
      c2_b_idx->data[c2_i105] -= c2_vk->data[c2_i105];
    }

    c2_i107 = c2_b_idx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_idx, c2_i107,
      &c2_hh_emlrtRTEI);
    c2_x_loop_ub = c2_b_idx->size[0] - 1;
    for (c2_i110 = 0; c2_i110 <= c2_x_loop_ub; c2_i110++) {
      c2_b_idx->data[c2_i110]++;
    }

    c2_i112 = c2_Intensity->size[0];
    c2_Intensity->size[0] = c2_b_idx->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_Intensity, c2_i112,
      &c2_ih_emlrtRTEI);
    c2_y_loop_ub = c2_b_idx->size[0] - 1;
    for (c2_i114 = 0; c2_i114 <= c2_y_loop_ub; c2_i114++) {
      c2_Intensity->data[c2_i114] = (real_T)c2_b_idx->data[c2_i114];
    }

    c2_i115 = c2_c->size[0];
    c2_c->size[0] = c2_varargout_4->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_b_st, c2_c, c2_i115,
      &c2_ih_emlrtRTEI);
    c2_bb_loop_ub = c2_varargout_4->size[0] - 1;
    for (c2_i117 = 0; c2_i117 <= c2_bb_loop_ub; c2_i117++) {
      c2_c->data[c2_i117] = (real_T)c2_varargout_4->data[c2_i117];
    }

    c2_i118 = c2_r->size[0];
    c2_i120 = c2_stats->size[0];
    c2_i121 = (int32_T)c2_d_k;
    if ((c2_i121 < 1) || (c2_i121 > c2_i120)) {
      emlrtDynamicBoundsCheckR2012b(c2_i121, 1, c2_i120, &c2_nf_emlrtBCI, &c2_st);
    }

    c2_r->size[0] = c2_stats->data[c2_i121 - 1].PixelValues->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_r, c2_i118,
      &c2_jh_emlrtRTEI);
    c2_i124 = c2_stats->size[0];
    c2_i125 = (int32_T)c2_d_k;
    if ((c2_i125 < 1) || (c2_i125 > c2_i124)) {
      emlrtDynamicBoundsCheckR2012b(c2_i125, 1, c2_i124, &c2_nf_emlrtBCI, &c2_st);
    }

    c2_eb_loop_ub = c2_stats->data[c2_i125 - 1].PixelValues->size[0] - 1;
    for (c2_i127 = 0; c2_i127 <= c2_eb_loop_ub; c2_i127++) {
      c2_i129 = c2_stats->size[0];
      c2_i131 = (int32_T)c2_d_k;
      if ((c2_i131 < 1) || (c2_i131 > c2_i129)) {
        emlrtDynamicBoundsCheckR2012b(c2_i131, 1, c2_i129, &c2_nf_emlrtBCI,
          &c2_st);
      }

      c2_r->data[c2_i127] = c2_stats->data[c2_i131 - 1].PixelValues->
        data[c2_i127];
    }

    c2_d3 = (real_T)c2_r->size[0];
    c2_i130 = (int32_T)c2_d3 - 1;
    for (c2_c_idx = 0; c2_c_idx <= c2_i130; c2_c_idx++) {
      c2_d_idx = (real_T)c2_c_idx + 1.0;
      c2_i134 = c2_stats->size[0];
      c2_i135 = (int32_T)c2_d_k;
      if ((c2_i135 < 1) || (c2_i135 > c2_i134)) {
        emlrtDynamicBoundsCheckR2012b(c2_i135, 1, c2_i134, &c2_ve_emlrtBCI,
          &c2_st);
      }

      c2_i137 = c2_i135 - 1;
      c2_i138 = c2_Intensity->size[0];
      c2_i140 = (int32_T)c2_d_idx;
      if ((c2_i140 < 1) || (c2_i140 > c2_i138)) {
        emlrtDynamicBoundsCheckR2012b(c2_i140, 1, c2_i138, &c2_cf_emlrtBCI,
          &c2_st);
      }

      c2_i142 = (int32_T)c2_Intensity->data[c2_i140 - 1];
      if ((c2_i142 < 1) || (c2_i142 > 480)) {
        emlrtDynamicBoundsCheckR2012b(c2_i142, 1, 480, &c2_bf_emlrtBCI, &c2_st);
      }

      c2_i145 = c2_c->size[0];
      c2_i146 = (int32_T)c2_d_idx;
      if ((c2_i146 < 1) || (c2_i146 > c2_i145)) {
        emlrtDynamicBoundsCheckR2012b(c2_i146, 1, c2_i145, &c2_cf_emlrtBCI,
          &c2_st);
      }

      c2_i148 = (int32_T)c2_c->data[c2_i146 - 1];
      if ((c2_i148 < 1) || (c2_i148 > 640)) {
        emlrtDynamicBoundsCheckR2012b(c2_i148, 1, 640, &c2_df_emlrtBCI, &c2_st);
      }

      c2_i150 = c2_stats->data[c2_i137].PixelValues->size[0];
      c2_i151 = (int32_T)c2_d_idx;
      if ((c2_i151 < 1) || (c2_i151 > c2_i150)) {
        emlrtDynamicBoundsCheckR2012b(c2_i151, 1, c2_i150, &c2_ef_emlrtBCI,
          &c2_st);
      }

      c2_stats->data[c2_i137].PixelValues->data[c2_i151 - 1] = c2_c_I[(c2_i142 +
        480 * (c2_i148 - 1)) - 1];
    }
  }

  c2_emxFree_int32_T(chartInstance, &c2_vk);
  c2_emxFree_int32_T(chartInstance, &c2_b_idx);
  c2_emxFree_int32_T(chartInstance, &c2_varargout_4);
  c2_emxFree_real_T(chartInstance, &c2_c);
  c2_d2 = (real_T)c2_stats->size[0];
  c2_i10 = (int32_T)c2_d2 - 1;
  c2_e_k = 0;
  c2_emxInit_real_T(chartInstance, c2_sp, &c2_r1, 2, &c2_wf_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, c2_sp, &c2_r2, 1, &c2_fh_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, c2_sp, &c2_b_Intensity, 1, &c2_ah_emlrtRTEI);
  while (c2_e_k <= c2_i10) {
    c2_f_k = (real_T)c2_e_k + 1.0;
    c2_i22 = c2_Intensity->size[0];
    c2_i24 = c2_stats->size[0];
    c2_i26 = (int32_T)c2_f_k;
    if ((c2_i26 < 1) || (c2_i26 > c2_i24)) {
      emlrtDynamicBoundsCheckR2012b(c2_i26, 1, c2_i24, &c2_jf_emlrtBCI, (void *)
        c2_sp);
    }

    c2_Intensity->size[0] = c2_stats->data[c2_i26 - 1].PixelValues->size[0];
    c2_st.site = &c2_fj_emlrtRSI;
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_Intensity, c2_i22,
      &c2_wg_emlrtRTEI);
    c2_i37 = c2_stats->size[0];
    c2_i40 = (int32_T)c2_f_k;
    if ((c2_i40 < 1) || (c2_i40 > c2_i37)) {
      emlrtDynamicBoundsCheckR2012b(c2_i40, 1, c2_i37, &c2_jf_emlrtBCI, (void *)
        c2_sp);
    }

    c2_d_loop_ub = c2_stats->data[c2_i40 - 1].PixelValues->size[0] - 1;
    for (c2_i46 = 0; c2_i46 <= c2_d_loop_ub; c2_i46++) {
      c2_i51 = c2_stats->size[0];
      c2_i53 = (int32_T)c2_f_k;
      if ((c2_i53 < 1) || (c2_i53 > c2_i51)) {
        emlrtDynamicBoundsCheckR2012b(c2_i53, 1, c2_i51, &c2_kf_emlrtBCI, (void *)
          c2_sp);
      }

      c2_Intensity->data[c2_i46] = c2_stats->data[c2_i53 - 1].PixelValues->
        data[c2_i46];
    }

    c2_i50 = c2_b_Intensity->size[0];
    c2_b_Intensity->size[0] = c2_Intensity->size[0];
    c2_st.site = &c2_ej_emlrtRSI;
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_b_Intensity, c2_i50,
      &c2_ah_emlrtRTEI);
    c2_f_loop_ub = c2_Intensity->size[0] - 1;
    for (c2_i56 = 0; c2_i56 <= c2_f_loop_ub; c2_i56++) {
      c2_b_Intensity->data[c2_i56] = c2_Intensity->data[c2_i56];
    }

    c2_st.site = &c2_tg_emlrtRSI;
    c2_sumIntensity = c2_b_sum(chartInstance, &c2_st, c2_b_Intensity);
    c2_i60 = c2_stats->size[0];
    c2_i62 = (int32_T)c2_f_k;
    if ((c2_i62 < 1) || (c2_i62 > c2_i60)) {
      emlrtDynamicBoundsCheckR2012b(c2_i62, 1, c2_i60, &c2_ue_emlrtBCI, (void *)
        c2_sp);
    }

    for (c2_n = 0; c2_n < 2; c2_n++) {
      c2_b_n = (real_T)c2_n + 1.0;
      c2_i69 = c2_stats->size[0];
      c2_i71 = (int32_T)c2_f_k;
      if ((c2_i71 < 1) || (c2_i71 > c2_i69)) {
        emlrtDynamicBoundsCheckR2012b(c2_i71, 1, c2_i69, &c2_ye_emlrtBCI, (void *)
          c2_sp);
      }

      c2_i76 = c2_i71 - 1;
      c2_i77 = c2_r1->size[0] * c2_r1->size[1];
      c2_r1->size[0] = c2_stats->data[c2_i76].PixelList->size[0];
      c2_r1->size[1] = 2;
      c2_st.site = &c2_ii_emlrtRSI;
      c2_emxEnsureCapacity_real_T(chartInstance, &c2_st, c2_r1, c2_i77,
        &c2_fh_emlrtRTEI);
      c2_i82 = c2_stats->size[0];
      c2_i83 = (int32_T)c2_f_k;
      if ((c2_i83 < 1) || (c2_i83 > c2_i82)) {
        emlrtDynamicBoundsCheckR2012b(c2_i83, 1, c2_i82, &c2_ye_emlrtBCI, (void *)
          c2_sp);
      }

      c2_i88 = c2_i83 - 1;
      c2_i89 = c2_stats->size[0];
      c2_i90 = (int32_T)c2_f_k;
      if ((c2_i90 < 1) || (c2_i90 > c2_i89)) {
        emlrtDynamicBoundsCheckR2012b(c2_i90, 1, c2_i89, &c2_ye_emlrtBCI, (void *)
          c2_sp);
      }

      c2_i94 = c2_i90 - 1;
      c2_r_loop_ub = c2_stats->data[c2_i88].PixelList->size[0] * c2_stats->
        data[c2_i94].PixelList->size[1] - 1;
      for (c2_i96 = 0; c2_i96 <= c2_r_loop_ub; c2_i96++) {
        c2_i99 = c2_stats->size[0];
        c2_i101 = (int32_T)c2_f_k;
        if ((c2_i101 < 1) || (c2_i101 > c2_i99)) {
          emlrtDynamicBoundsCheckR2012b(c2_i101, 1, c2_i99, &c2_mf_emlrtBCI,
            (void *)c2_sp);
        }

        c2_r1->data[c2_i96] = c2_stats->data[c2_i101 - 1].PixelList->data[c2_i96];
      }

      c2_c_n = (int32_T)c2_b_n - 1;
      c2_i100 = c2_r1->size[0] - 1;
      c2_i104 = c2_r->size[0];
      c2_r->size[0] = c2_i100 + 1;
      c2_st.site = &c2_ii_emlrtRSI;
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_r, c2_i104,
        &c2_fh_emlrtRTEI);
      c2_w_loop_ub = c2_i100;
      for (c2_i108 = 0; c2_i108 <= c2_w_loop_ub; c2_i108++) {
        c2_r->data[c2_i108] = c2_r1->data[c2_i108 + c2_r1->size[0] * c2_c_n];
      }

      c2_i109 = c2_r->size[0];
      c2_i111 = c2_Intensity->size[0];
      if (c2_i109 != c2_i111) {
        emlrtSizeEqCheck1DR2012b(c2_i109, c2_i111, &c2_c_emlrtECI, (void *)c2_sp);
      }

      c2_i113 = c2_r2->size[0];
      c2_r2->size[0] = c2_r->size[0];
      c2_st.site = &c2_ii_emlrtRSI;
      c2_emxEnsureCapacity_real_T1(chartInstance, &c2_st, c2_r2, c2_i113,
        &c2_fh_emlrtRTEI);
      c2_ab_loop_ub = c2_r->size[0] - 1;
      for (c2_i116 = 0; c2_i116 <= c2_ab_loop_ub; c2_i116++) {
        c2_r2->data[c2_i116] = c2_r->data[c2_i116] * c2_Intensity->data[c2_i116];
      }

      c2_st.site = &c2_sg_emlrtRSI;
      c2_M = c2_b_sum(chartInstance, &c2_st, c2_r2);
      c2_wc[(int32_T)c2_b_n - 1] = c2_M / c2_sumIntensity;
    }

    c2_d_stats = c2_stats->size[0];
    for (c2_i68 = 0; c2_i68 < 2; c2_i68++) {
      c2_i73 = (int32_T)c2_f_k;
      if ((c2_i73 < 1) || (c2_i73 > c2_d_stats)) {
        emlrtDynamicBoundsCheckR2012b(c2_i73, 1, c2_d_stats, &c2_af_emlrtBCI,
          (void *)c2_sp);
      }

      c2_stats->data[c2_i73 - 1].WeightedCentroid[c2_i68] = c2_wc[c2_i68];
    }

    c2_e_k++;
  }

  c2_emxFree_real_T(chartInstance, &c2_b_Intensity);
  c2_emxFree_real_T(chartInstance, &c2_r2);
  c2_emxFree_real_T(chartInstance, &c2_r);
  c2_emxFree_real_T(chartInstance, &c2_r1);
  c2_emxFree_real_T(chartInstance, &c2_Intensity);
}

static void c2_b_round(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_f_x;
  real_T c2_g_x;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_k;
  int32_T c2_nx;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_hh_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_nx = c2_e_x->size[0];
  c2_b_st.site = &c2_ih_emlrtRSI;
  c2_b = c2_nx;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_c_st.site = &c2_hc_emlrtRSI;
    c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
  }

  for (c2_k = 1; c2_k - 1 < c2_nx; c2_k++) {
    c2_b_k = c2_k - 1;
    c2_f_x = c2_e_x->data[c2_b_k];
    c2_g_x = c2_f_x;
    c2_g_x = muDoubleScalarRound(c2_g_x);
    c2_e_x->data[c2_b_k] = c2_g_x;
  }
}

static void c2_d_sort(SFc2_imagedetectorInstanceStruct *chartInstance, const
                      emlrtStack *c2_sp, c2_emxArray_real_T *c2_e_x,
                      c2_emxArray_int32_T *c2_b_idx)
{
  c2_emxArray_int32_T *c2_b_iwork;
  c2_emxArray_real_T *c2_xwork;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_e_st;
  emlrtStack c2_st;
  real_T c2_x4[4];
  real_T c2_dv[2];
  real_T c2_f_x;
  int32_T c2_idx4[4];
  int32_T c2_perm[4];
  int32_T c2_b_xwork[1];
  int32_T c2_c_iwork[1];
  int32_T c2_iv[1];
  int32_T c2_b_b;
  int32_T c2_b_i1;
  int32_T c2_b_i2;
  int32_T c2_b_i3;
  int32_T c2_b_i4;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_b_n;
  int32_T c2_b_nNaNs;
  int32_T c2_b_nNonNaN;
  int32_T c2_c_b;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_c_n;
  int32_T c2_d_k;
  int32_T c2_e_b;
  int32_T c2_e_k;
  int32_T c2_f_b;
  int32_T c2_f_k;
  int32_T c2_g_b;
  int32_T c2_g_k;
  int32_T c2_h_b;
  int32_T c2_h_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_b;
  int32_T c2_ib;
  int32_T c2_itmp;
  int32_T c2_j_b;
  int32_T c2_k;
  int32_T c2_k_b;
  int32_T c2_l_b;
  int32_T c2_loop_ub;
  int32_T c2_m;
  int32_T c2_m_b;
  int32_T c2_n;
  int32_T c2_nBlocks;
  int32_T c2_nLastBlock;
  int32_T c2_nNaNs;
  int32_T c2_nNonNaN;
  int32_T c2_n_b;
  int32_T c2_o_b;
  int32_T c2_p_b;
  int32_T c2_preSortLevel;
  int32_T c2_quartetOffset;
  int32_T c2_tailOffset;
  int32_T c2_wOffset;
  boolean_T c2_b;
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_d_b;
  boolean_T c2_d_overflow;
  boolean_T c2_e_overflow;
  boolean_T c2_f_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_md_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_e_st.prev = &c2_d_st;
  c2_e_st.tls = c2_d_st.tls;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_dv[c2_i] = (real_T)c2_e_x->size[c2_i];
  }

  c2_i1 = c2_b_idx->size[0] * c2_b_idx->size[1];
  c2_b_idx->size[0] = (int32_T)c2_dv[0];
  c2_b_idx->size[1] = 1;
  c2_emxEnsureCapacity_int32_T1(chartInstance, &c2_st, c2_b_idx, c2_i1,
    &c2_ph_emlrtRTEI);
  c2_loop_ub = (int32_T)c2_dv[0] - 1;
  for (c2_i2 = 0; c2_i2 <= c2_loop_ub; c2_i2++) {
    c2_b_idx->data[c2_i2] = 0;
  }

  c2_b = (c2_e_x->size[0] == 0);
  if (!c2_b) {
    c2_b_st.site = &c2_kh_emlrtRSI;
    c2_b_st.site = &c2_nd_emlrtRSI;
    c2_n = c2_e_x->size[0];
    c2_c_st.site = &c2_od_emlrtRSI;
    c2_b_n = c2_e_x->size[0];
    for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
      c2_x4[c2_i3] = 0.0;
    }

    for (c2_i4 = 0; c2_i4 < 4; c2_i4++) {
      c2_idx4[c2_i4] = 0;
    }

    c2_emxInit_int32_T(chartInstance, &c2_c_st, &c2_b_iwork, 1, &c2_lg_emlrtRTEI);
    c2_i5 = c2_b_iwork->size[0];
    c2_b_iwork->size[0] = c2_b_idx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_iwork, c2_i5,
      &c2_kg_emlrtRTEI);
    c2_iv[0] = c2_b_iwork->size[0];
    c2_i6 = c2_b_iwork->size[0];
    c2_b_iwork->size[0] = c2_iv[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_iwork, c2_i6,
      &c2_lg_emlrtRTEI);
    c2_c_iwork[0] = c2_b_iwork->size[0];
    c2_i7 = c2_b_iwork->size[0];
    c2_b_iwork->size[0] = c2_c_iwork[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, &c2_c_st, c2_b_iwork, c2_i7,
      &c2_mg_emlrtRTEI);
    c2_b_loop_ub = c2_c_iwork[0] - 1;
    for (c2_i8 = 0; c2_i8 <= c2_b_loop_ub; c2_i8++) {
      c2_b_iwork->data[c2_i8] = 0;
    }

    c2_emxInit_real_T1(chartInstance, &c2_c_st, &c2_xwork, 1, &c2_og_emlrtRTEI);
    c2_dv[0] = (real_T)c2_e_x->size[0];
    c2_i9 = c2_xwork->size[0];
    c2_xwork->size[0] = (int32_T)c2_dv[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_c_st, c2_xwork, c2_i9,
      &c2_ng_emlrtRTEI);
    c2_iv[0] = c2_xwork->size[0];
    c2_i10 = c2_xwork->size[0];
    c2_xwork->size[0] = c2_iv[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_c_st, c2_xwork, c2_i10,
      &c2_og_emlrtRTEI);
    c2_b_xwork[0] = c2_xwork->size[0];
    c2_i11 = c2_xwork->size[0];
    c2_xwork->size[0] = c2_b_xwork[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, &c2_c_st, c2_xwork, c2_i11,
      &c2_pg_emlrtRTEI);
    c2_c_loop_ub = c2_b_xwork[0] - 1;
    for (c2_i12 = 0; c2_i12 <= c2_c_loop_ub; c2_i12++) {
      c2_xwork->data[c2_i12] = 0.0;
    }

    c2_nNaNs = 0;
    c2_ib = 0;
    c2_d_st.site = &c2_td_emlrtRSI;
    c2_b_b = c2_b_n;
    c2_c_b = c2_b_b;
    if (1 > c2_c_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_c_b > 2147483646);
    }

    if (c2_overflow) {
      c2_e_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
    }

    for (c2_k = 1; c2_k - 1 < c2_b_n; c2_k++) {
      c2_b_k = c2_k - 1;
      c2_f_x = c2_e_x->data[c2_b_k];
      c2_d_b = muDoubleScalarIsNaN(c2_f_x);
      if (c2_d_b) {
        c2_b_idx->data[(c2_b_n - c2_nNaNs) - 1] = c2_b_k + 1;
        c2_xwork->data[(c2_b_n - c2_nNaNs) - 1] = c2_e_x->data[c2_b_k];
        c2_nNaNs++;
      } else {
        c2_ib++;
        c2_idx4[c2_ib - 1] = c2_b_k + 1;
        c2_x4[c2_ib - 1] = c2_e_x->data[c2_b_k];
        if (c2_ib == 4) {
          c2_quartetOffset = c2_b_k - c2_nNaNs;
          if (c2_x4[0] >= c2_x4[1]) {
            c2_b_i1 = 1;
            c2_b_i2 = 2;
          } else {
            c2_b_i1 = 2;
            c2_b_i2 = 1;
          }

          if (c2_x4[2] >= c2_x4[3]) {
            c2_b_i3 = 3;
            c2_b_i4 = 4;
          } else {
            c2_b_i3 = 4;
            c2_b_i4 = 3;
          }

          if (c2_x4[c2_b_i1 - 1] >= c2_x4[c2_b_i3 - 1]) {
            if (c2_x4[c2_b_i2 - 1] >= c2_x4[c2_b_i3 - 1]) {
              c2_perm[0] = c2_b_i1;
              c2_perm[1] = c2_b_i2;
              c2_perm[2] = c2_b_i3;
              c2_perm[3] = c2_b_i4;
            } else if (c2_x4[c2_b_i2 - 1] >= c2_x4[c2_b_i4 - 1]) {
              c2_perm[0] = c2_b_i1;
              c2_perm[1] = c2_b_i3;
              c2_perm[2] = c2_b_i2;
              c2_perm[3] = c2_b_i4;
            } else {
              c2_perm[0] = c2_b_i1;
              c2_perm[1] = c2_b_i3;
              c2_perm[2] = c2_b_i4;
              c2_perm[3] = c2_b_i2;
            }
          } else if (c2_x4[c2_b_i1 - 1] >= c2_x4[c2_b_i4 - 1]) {
            if (c2_x4[c2_b_i2 - 1] >= c2_x4[c2_b_i4 - 1]) {
              c2_perm[0] = c2_b_i3;
              c2_perm[1] = c2_b_i1;
              c2_perm[2] = c2_b_i2;
              c2_perm[3] = c2_b_i4;
            } else {
              c2_perm[0] = c2_b_i3;
              c2_perm[1] = c2_b_i1;
              c2_perm[2] = c2_b_i4;
              c2_perm[3] = c2_b_i2;
            }
          } else {
            c2_perm[0] = c2_b_i3;
            c2_perm[1] = c2_b_i4;
            c2_perm[2] = c2_b_i1;
            c2_perm[3] = c2_b_i2;
          }

          c2_b_idx->data[c2_quartetOffset - 3] = c2_idx4[c2_perm[0] - 1];
          c2_b_idx->data[c2_quartetOffset - 2] = c2_idx4[c2_perm[1] - 1];
          c2_b_idx->data[c2_quartetOffset - 1] = c2_idx4[c2_perm[2] - 1];
          c2_b_idx->data[c2_quartetOffset] = c2_idx4[c2_perm[3] - 1];
          c2_e_x->data[c2_quartetOffset - 3] = c2_x4[c2_perm[0] - 1];
          c2_e_x->data[c2_quartetOffset - 2] = c2_x4[c2_perm[1] - 1];
          c2_e_x->data[c2_quartetOffset - 1] = c2_x4[c2_perm[2] - 1];
          c2_e_x->data[c2_quartetOffset] = c2_x4[c2_perm[3] - 1];
          c2_ib = 0;
        }
      }
    }

    c2_wOffset = (c2_b_n - c2_nNaNs) - 1;
    if (c2_ib > 0) {
      c2_c_n = c2_ib;
      for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
        c2_perm[c2_i13] = 0;
      }

      if (c2_c_n == 1) {
        c2_perm[0] = 1;
      } else if (c2_c_n == 2) {
        if (c2_x4[0] >= c2_x4[1]) {
          c2_perm[0] = 1;
          c2_perm[1] = 2;
        } else {
          c2_perm[0] = 2;
          c2_perm[1] = 1;
        }
      } else if (c2_x4[0] >= c2_x4[1]) {
        if (c2_x4[1] >= c2_x4[2]) {
          c2_perm[0] = 1;
          c2_perm[1] = 2;
          c2_perm[2] = 3;
        } else if (c2_x4[0] >= c2_x4[2]) {
          c2_perm[0] = 1;
          c2_perm[1] = 3;
          c2_perm[2] = 2;
        } else {
          c2_perm[0] = 3;
          c2_perm[1] = 1;
          c2_perm[2] = 2;
        }
      } else if (c2_x4[0] >= c2_x4[2]) {
        c2_perm[0] = 2;
        c2_perm[1] = 1;
        c2_perm[2] = 3;
      } else if (c2_x4[1] >= c2_x4[2]) {
        c2_perm[0] = 2;
        c2_perm[1] = 3;
        c2_perm[2] = 1;
      } else {
        c2_perm[0] = 3;
        c2_perm[1] = 2;
        c2_perm[2] = 1;
      }

      c2_d_st.site = &c2_ud_emlrtRSI;
      c2_g_b = c2_ib;
      c2_h_b = c2_g_b;
      if (1 > c2_h_b) {
        c2_c_overflow = false;
      } else {
        c2_c_overflow = (c2_h_b > 2147483646);
      }

      if (c2_c_overflow) {
        c2_e_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
      }

      for (c2_d_k = 1; c2_d_k - 1 < c2_ib; c2_d_k++) {
        c2_b_k = c2_d_k;
        c2_b_idx->data[(c2_wOffset - c2_ib) + c2_b_k] = c2_idx4[c2_perm[c2_b_k -
          1] - 1];
        c2_e_x->data[(c2_wOffset - c2_ib) + c2_b_k] = c2_x4[c2_perm[c2_b_k - 1]
          - 1];
      }
    }

    c2_m = c2_nNaNs >> 1;
    c2_d_st.site = &c2_vd_emlrtRSI;
    c2_e_b = c2_m;
    c2_f_b = c2_e_b;
    if (1 > c2_f_b) {
      c2_b_overflow = false;
    } else {
      c2_b_overflow = (c2_f_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_e_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
    }

    for (c2_c_k = 1; c2_c_k - 1 < c2_m; c2_c_k++) {
      c2_b_k = c2_c_k;
      c2_itmp = c2_b_idx->data[c2_wOffset + c2_b_k];
      c2_b_idx->data[c2_wOffset + c2_b_k] = c2_b_idx->data[c2_b_n - c2_b_k];
      c2_b_idx->data[c2_b_n - c2_b_k] = c2_itmp;
      c2_e_x->data[c2_wOffset + c2_b_k] = c2_xwork->data[c2_b_n - c2_b_k];
      c2_e_x->data[c2_b_n - c2_b_k] = c2_xwork->data[c2_wOffset + c2_b_k];
    }

    if ((c2_nNaNs & 1) != 0) {
      c2_e_x->data[(c2_wOffset + c2_m) + 1] = c2_xwork->data[(c2_wOffset + c2_m)
        + 1];
    }

    c2_nNonNaN = c2_n - c2_nNaNs;
    c2_preSortLevel = 2;
    if (c2_nNonNaN > 1) {
      if (c2_n >= 256) {
        c2_nBlocks = c2_nNonNaN >> 8;
        if (c2_nBlocks > 0) {
          c2_c_st.site = &c2_pd_emlrtRSI;
          c2_i_b = c2_nBlocks;
          c2_j_b = c2_i_b;
          if (1 > c2_j_b) {
            c2_d_overflow = false;
          } else {
            c2_d_overflow = (c2_j_b > 2147483646);
          }

          if (c2_d_overflow) {
            c2_d_st.site = &c2_hc_emlrtRSI;
            c2_check_forloop_overflow_error(chartInstance, &c2_d_st);
          }

          for (c2_m_b = 1; c2_m_b - 1 < c2_nBlocks; c2_m_b++) {
            c2_n_b = c2_m_b - 1;
            c2_c_st.site = &c2_qd_emlrtRSI;
            c2_d_merge_pow2_block(chartInstance, &c2_c_st, c2_b_idx, c2_e_x,
                                  c2_n_b << 8);
          }

          c2_tailOffset = c2_nBlocks << 8;
          c2_nLastBlock = c2_nNonNaN - c2_tailOffset;
          if (c2_nLastBlock > 0) {
            c2_c_st.site = &c2_rd_emlrtRSI;
            c2_d_merge_block(chartInstance, &c2_c_st, c2_b_idx, c2_e_x,
                             c2_tailOffset, c2_nLastBlock, 2, c2_b_iwork,
                             c2_xwork);
          }

          c2_preSortLevel = 8;
        }
      }

      c2_c_st.site = &c2_sd_emlrtRSI;
      c2_d_merge_block(chartInstance, &c2_c_st, c2_b_idx, c2_e_x, 0, c2_nNonNaN,
                       c2_preSortLevel, c2_b_iwork, c2_xwork);
    }

    if ((c2_nNaNs > 0) && (c2_nNonNaN > 0)) {
      c2_c_st.site = &c2_lh_emlrtRSI;
      c2_b_nNonNaN = c2_nNonNaN - 1;
      c2_b_nNaNs = c2_nNaNs - 1;
      c2_d_st.site = &c2_mh_emlrtRSI;
      c2_k_b = c2_b_nNaNs + 1;
      c2_l_b = c2_k_b;
      if (1 > c2_l_b) {
        c2_e_overflow = false;
      } else {
        c2_e_overflow = (c2_l_b > 2147483646);
      }

      if (c2_e_overflow) {
        c2_e_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
      }

      for (c2_e_k = 1; c2_e_k - 1 <= c2_b_nNaNs; c2_e_k++) {
        c2_g_k = c2_e_k;
        c2_xwork->data[c2_g_k - 1] = c2_e_x->data[c2_b_nNonNaN + c2_g_k];
        c2_b_iwork->data[c2_g_k - 1] = c2_b_idx->data[c2_b_nNonNaN + c2_g_k];
      }

      for (c2_f_k = c2_b_nNonNaN + 1; c2_f_k > 0; c2_f_k--) {
        c2_e_x->data[c2_b_nNaNs + c2_f_k] = c2_e_x->data[c2_f_k - 1];
        c2_b_idx->data[c2_b_nNaNs + c2_f_k] = c2_b_idx->data[c2_f_k - 1];
      }

      c2_d_st.site = &c2_nh_emlrtRSI;
      c2_o_b = c2_b_nNaNs + 1;
      c2_p_b = c2_o_b;
      if (1 > c2_p_b) {
        c2_f_overflow = false;
      } else {
        c2_f_overflow = (c2_p_b > 2147483646);
      }

      if (c2_f_overflow) {
        c2_e_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_e_st);
      }

      for (c2_h_k = 1; c2_h_k - 1 <= c2_b_nNaNs; c2_h_k++) {
        c2_g_k = c2_h_k - 1;
        c2_e_x->data[c2_g_k] = c2_xwork->data[c2_g_k];
        c2_b_idx->data[c2_g_k] = c2_b_iwork->data[c2_g_k];
      }
    }

    c2_emxFree_real_T(chartInstance, &c2_xwork);
    c2_emxFree_int32_T(chartInstance, &c2_b_iwork);
  }
}

static void c2_d_merge_pow2_block(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx,
  c2_emxArray_real_T *c2_e_x, int32_T c2_offset)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  real_T c2_xwork[256];
  int32_T c2_b_iwork[256];
  int32_T c2_b;
  int32_T c2_bLen;
  int32_T c2_bLen2;
  int32_T c2_b_b;
  int32_T c2_b_j;
  int32_T c2_b_k;
  int32_T c2_blockOffset;
  int32_T c2_c_b;
  int32_T c2_c_j;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_exitg1;
  int32_T c2_f_b;
  int32_T c2_g_b;
  int32_T c2_iout;
  int32_T c2_j;
  int32_T c2_k;
  int32_T c2_nPairs;
  int32_T c2_offset1;
  int32_T c2_p;
  int32_T c2_q;
  boolean_T c2_b_overflow;
  boolean_T c2_c_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  for (c2_b = 0; c2_b < 6; c2_b++) {
    c2_bLen = 1 << (c2_b + 2);
    c2_bLen2 = c2_bLen << 1;
    c2_nPairs = 256 >> (c2_b + 3);
    c2_st.site = &c2_wd_emlrtRSI;
    c2_b_b = c2_nPairs;
    c2_c_b = c2_b_b;
    if (1 > c2_c_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_c_b > 2147483646);
    }

    if (c2_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }

    for (c2_k = 1; c2_k - 1 < c2_nPairs; c2_k++) {
      c2_b_k = c2_k - 1;
      c2_blockOffset = (c2_offset + c2_b_k * c2_bLen2) - 1;
      c2_st.site = &c2_xd_emlrtRSI;
      c2_d_b = c2_bLen2;
      c2_e_b = c2_d_b;
      if (1 > c2_e_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_e_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_b_st.site = &c2_hc_emlrtRSI;
        c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
      }

      for (c2_j = 1; c2_j - 1 < c2_bLen2; c2_j++) {
        c2_b_j = c2_j;
        c2_b_iwork[c2_b_j - 1] = c2_b_idx->data[c2_blockOffset + c2_b_j];
        c2_xwork[c2_b_j - 1] = c2_e_x->data[c2_blockOffset + c2_b_j];
      }

      c2_p = 0;
      c2_q = c2_bLen;
      c2_iout = c2_blockOffset;
      do {
        c2_exitg1 = 0;
        c2_iout++;
        if (c2_xwork[c2_p] >= c2_xwork[c2_q]) {
          c2_b_idx->data[c2_iout] = c2_b_iwork[c2_p];
          c2_e_x->data[c2_iout] = c2_xwork[c2_p];
          if (c2_p + 1 < c2_bLen) {
            c2_p++;
          } else {
            c2_exitg1 = 1;
          }
        } else {
          c2_b_idx->data[c2_iout] = c2_b_iwork[c2_q];
          c2_e_x->data[c2_iout] = c2_xwork[c2_q];
          if (c2_q + 1 < c2_bLen2) {
            c2_q++;
          } else {
            c2_offset1 = c2_iout - c2_p;
            c2_st.site = &c2_yd_emlrtRSI;
            c2_d_a = c2_p + 1;
            c2_f_b = c2_bLen;
            c2_e_a = c2_d_a;
            c2_g_b = c2_f_b;
            if (c2_e_a > c2_g_b) {
              c2_c_overflow = false;
            } else {
              c2_c_overflow = (c2_g_b > 2147483646);
            }

            if (c2_c_overflow) {
              c2_b_st.site = &c2_hc_emlrtRSI;
              c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
            }

            for (c2_c_j = c2_p + 1; c2_c_j <= c2_bLen; c2_c_j++) {
              c2_b_idx->data[c2_offset1 + c2_c_j] = c2_b_iwork[c2_c_j - 1];
              c2_e_x->data[c2_offset1 + c2_c_j] = c2_xwork[c2_c_j - 1];
            }

            c2_exitg1 = 1;
          }
        }
      } while (c2_exitg1 == 0);
    }
  }
}

static void c2_d_merge_block(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T
  *c2_e_x, int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel,
  c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real_T *c2_xwork)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_b;
  int32_T c2_bLen;
  int32_T c2_bLen2;
  int32_T c2_b_b;
  int32_T c2_b_k;
  int32_T c2_k;
  int32_T c2_nBlocks;
  int32_T c2_nPairs;
  int32_T c2_nTail;
  int32_T c2_tailOffset;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_nBlocks = c2_n >> c2_preSortLevel;
  c2_bLen = 1 << c2_preSortLevel;
  while (c2_nBlocks > 1) {
    if ((c2_nBlocks & 1) != 0) {
      c2_nBlocks--;
      c2_tailOffset = c2_bLen * c2_nBlocks;
      c2_nTail = c2_n - c2_tailOffset;
      if (c2_nTail > c2_bLen) {
        c2_st.site = &c2_ae_emlrtRSI;
        c2_d_merge(chartInstance, &c2_st, c2_b_idx, c2_e_x, c2_offset +
                   c2_tailOffset, c2_bLen, c2_nTail - c2_bLen, c2_b_iwork,
                   c2_xwork);
      }
    }

    c2_bLen2 = c2_bLen << 1;
    c2_nPairs = c2_nBlocks >> 1;
    c2_st.site = &c2_be_emlrtRSI;
    c2_b = c2_nPairs;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }

    for (c2_k = 1; c2_k - 1 < c2_nPairs; c2_k++) {
      c2_b_k = c2_k - 1;
      c2_st.site = &c2_ce_emlrtRSI;
      c2_d_merge(chartInstance, &c2_st, c2_b_idx, c2_e_x, c2_offset + c2_b_k *
                 c2_bLen2, c2_bLen, c2_bLen, c2_b_iwork, c2_xwork);
    }

    c2_bLen = c2_bLen2;
    c2_nBlocks = c2_nPairs;
  }

  if (c2_n > c2_bLen) {
    c2_st.site = &c2_de_emlrtRSI;
    c2_d_merge(chartInstance, &c2_st, c2_b_idx, c2_e_x, c2_offset, c2_bLen, c2_n
               - c2_bLen, c2_b_iwork, c2_xwork);
  }
}

static void c2_d_merge(SFc2_imagedetectorInstanceStruct *chartInstance, const
  emlrtStack *c2_sp, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_e_x,
  int32_T c2_offset, int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T
  *c2_b_iwork, c2_emxArray_real_T *c2_xwork)
{
  emlrtStack c2_b_st;
  emlrtStack c2_st;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_b_j;
  int32_T c2_c_b;
  int32_T c2_c_j;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_e_a;
  int32_T c2_exitg1;
  int32_T c2_iout;
  int32_T c2_j;
  int32_T c2_n;
  int32_T c2_offset1;
  int32_T c2_p;
  int32_T c2_q;
  int32_T c2_qend;
  boolean_T c2_b_overflow;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  if (c2_nq != 0) {
    c2_n = c2_np + c2_nq;
    c2_st.site = &c2_fe_emlrtRSI;
    c2_b = c2_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_b_st.site = &c2_hc_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
    }

    for (c2_j = 1; c2_j - 1 < c2_n; c2_j++) {
      c2_b_j = c2_j - 1;
      c2_b_iwork->data[c2_b_j] = c2_b_idx->data[c2_offset + c2_b_j];
      c2_xwork->data[c2_b_j] = c2_e_x->data[c2_offset + c2_b_j];
    }

    c2_p = 0;
    c2_q = c2_np;
    c2_qend = c2_np + c2_nq;
    c2_iout = c2_offset - 1;
    do {
      c2_exitg1 = 0;
      c2_iout++;
      if (c2_xwork->data[c2_p] >= c2_xwork->data[c2_q]) {
        c2_b_idx->data[c2_iout] = c2_b_iwork->data[c2_p];
        c2_e_x->data[c2_iout] = c2_xwork->data[c2_p];
        if (c2_p + 1 < c2_np) {
          c2_p++;
        } else {
          c2_exitg1 = 1;
        }
      } else {
        c2_b_idx->data[c2_iout] = c2_b_iwork->data[c2_q];
        c2_e_x->data[c2_iout] = c2_xwork->data[c2_q];
        if (c2_q + 1 < c2_qend) {
          c2_q++;
        } else {
          c2_offset1 = c2_iout - c2_p;
          c2_st.site = &c2_ee_emlrtRSI;
          c2_d_a = c2_p + 1;
          c2_c_b = c2_np;
          c2_e_a = c2_d_a;
          c2_d_b = c2_c_b;
          if (c2_e_a > c2_d_b) {
            c2_b_overflow = false;
          } else {
            c2_b_overflow = (c2_d_b > 2147483646);
          }

          if (c2_b_overflow) {
            c2_b_st.site = &c2_hc_emlrtRSI;
            c2_check_forloop_overflow_error(chartInstance, &c2_b_st);
          }

          for (c2_c_j = c2_p + 1; c2_c_j <= c2_np; c2_c_j++) {
            c2_b_idx->data[c2_offset1 + c2_c_j] = c2_b_iwork->data[c2_c_j - 1];
            c2_e_x->data[c2_offset1 + c2_c_j] = c2_xwork->data[c2_c_j - 1];
          }

          c2_exitg1 = 1;
        }
      }
    } while (c2_exitg1 == 0);
  }
}

static void c2_emxInit_real_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_real_T *)emlrtMallocMex(sizeof(c2_emxArray_real_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_real_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_real_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_real_T *)NULL) {
    if (((*c2_pEmxArray)->data != (real_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_real_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_creal_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_creal_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(creal_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(creal_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (creal_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_real_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_boolean_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(boolean_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (boolean_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_int32_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(int32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(int32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (int32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_real_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_real_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_real_T *)emlrtMallocMex(sizeof(c2_emxArray_real_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_boolean_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_boolean_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_boolean_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c2_emxArray_boolean_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (boolean_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_int32_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_int32_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_int32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (int32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_creal_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_creal_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_creal_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c2_emxArray_creal_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (creal_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_boolean_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_boolean_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_boolean_T *)NULL) {
    if (((*c2_pEmxArray)->data != (boolean_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_boolean_T *)NULL;
  }
}

static void c2_emxFree_int32_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_int32_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_int32_T *)NULL) {
    if (((*c2_pEmxArray)->data != (int32_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_int32_T *)NULL;
  }
}

static void c2_emxFree_creal_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_creal_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_creal_T *)NULL) {
    if (((*c2_pEmxArray)->data != (creal_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_creal_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_boolean_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(boolean_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (boolean_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_real32_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real32_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_creal_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_creal_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(creal_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(creal_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (creal_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_real32_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real32_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real32_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_real32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_creal_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_creal_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_creal_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c2_emxArray_creal_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (creal_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_boolean_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_boolean_T **c2_pEmxArray,
  int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_boolean_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c2_emxArray_boolean_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (boolean_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_real32_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_real32_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_real32_T *)NULL) {
    if (((*c2_pEmxArray)->data != (real32_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_real32_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_real32_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_real32_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_real32_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real32_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real32_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_real32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxEnsureCapacity_uint8_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_uint8_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(uint8_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(uint8_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (uint8_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_uint8_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_uint8_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_uint8_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_uint8_T *)emlrtMallocMex(sizeof
    (c2_emxArray_uint8_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (uint8_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_uint8_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  c2_emxArray_uint8_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_uint8_T *)NULL) {
    if (((*c2_pEmxArray)->data != (uint8_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_uint8_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_int32_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_emxArray_int32_T *c2_emxArray,
  int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(int32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(int32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (int32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_sBO2RC5RVZVTbundPSRqHnH(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_sBO2RC5RVZVTbundPSRqHn
  **c2_pEmxArray, int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_sBO2RC5RVZVTbundPSRqHn *)emlrtMallocMex(sizeof
    (c2_emxArray_sBO2RC5RVZVTbundPSRqHn));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (c2_sBO2RC5RVZVTbundPSRqHnH *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_int32_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_int32_T **c2_pEmxArray, int32_T
  c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_int32_T *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_int32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (int32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_sBO2RC5RVZVTbundPSRqHnH(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_emxArray_sBO2RC5RVZVTbundPSRqHn **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_sBO2RC5RVZVTbundPSRqHn *)NULL) {
    if (((*c2_pEmxArray)->data != (c2_sBO2RC5RVZVTbundPSRqHnH *)NULL) &&
        (*c2_pEmxArray)->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_sBO2RC5RVZVTbundPSRqHn *)NULL;
  }
}

static void c2_emxInitStruct_s_vX9LV7M75v5ZNol(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_s_vX9LV7M75v5ZNol5H5URkE
  *c2_pStruct, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxInit_real_T1(chartInstance, c2_sp, &c2_pStruct->RegionIndices, 1,
                     c2_srcLocation);
  c2_emxInit_int32_T(chartInstance, c2_sp, &c2_pStruct->RegionLengths, 1,
                     c2_srcLocation);
}

static void c2_emxInit_s_R6Og1x0kmqQXSF9Pwa49F(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49
  **c2_pEmxArray, int32_T c2_numDimensions, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_emxArray;
  int32_T c2_i;
  (void)chartInstance;
  *c2_pEmxArray = (c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *)emlrtMallocMex(sizeof
    (c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (c2_s_R6Og1x0kmqQXSF9Pwa49FD *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFreeStruct_s_vX9LV7M75v5ZNol(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_s_vX9LV7M75v5ZNol5H5URkE *c2_pStruct)
{
  c2_emxFree_real_T(chartInstance, &c2_pStruct->RegionIndices);
  c2_emxFree_int32_T(chartInstance, &c2_pStruct->RegionLengths);
}

static void c2_emxFree_s_R6Og1x0kmqQXSF9Pwa49F(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 **c2_pEmxArray)
{
  int32_T c2_b_i;
  int32_T c2_i;
  int32_T c2_numEl;
  if (*c2_pEmxArray != (c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *)NULL) {
    if ((*c2_pEmxArray)->data != (c2_s_R6Og1x0kmqQXSF9Pwa49FD *)NULL) {
      c2_numEl = 1;
      for (c2_i = 0; c2_i < (*c2_pEmxArray)->numDimensions; c2_i++) {
        c2_numEl *= (*c2_pEmxArray)->size[c2_i];
      }

      for (c2_b_i = 0; c2_b_i < c2_numEl; c2_b_i++) {
        c2_emxFreeStruct_s_R6Og1x0kmqQXSF9(chartInstance, &(*c2_pEmxArray)->
          data[c2_b_i]);
      }

      if ((*c2_pEmxArray)->canFreeData) {
        emlrtFreeMex((*c2_pEmxArray)->data);
      }
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *)NULL;
  }
}

static void c2_emxFreeStruct_s_R6Og1x0kmqQXSF9(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_s_R6Og1x0kmqQXSF9Pwa49FD *c2_pStruct)
{
  c2_emxFree_real_T(chartInstance, &c2_pStruct->PixelIdxList);
  c2_emxFree_real_T(chartInstance, &c2_pStruct->PixelList);
  c2_emxFree_real_T(chartInstance, &c2_pStruct->PixelValues);
}

static void c2_emxEnsureCapacity_sBO2RC5RVZVTb(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_sBO2RC5RVZVTbundPSRqHn
  *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  (void)chartInstance;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof
      (c2_sBO2RC5RVZVTbundPSRqHnH));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(c2_sBO2RC5RVZVTbundPSRqHnH) *
             (uint32_T)c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (c2_sBO2RC5RVZVTbundPSRqHnH *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxTrim_s_R6Og1x0kmqQXSF9Pwa49F(SFc2_imagedetectorInstanceStruct *
  chartInstance, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49 *c2_emxArray, int32_T
  c2_fromIndex, int32_T c2_toIndex)
{
  int32_T c2_i;
  for (c2_i = c2_fromIndex; c2_i < c2_toIndex; c2_i++) {
    c2_emxFreeStruct_s_R6Og1x0kmqQXSF9(chartInstance, &c2_emxArray->data[c2_i]);
  }
}

static void c2_emxInitStruct_s_R6Og1x0kmqQXSF9(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_s_R6Og1x0kmqQXSF9Pwa49FD
  *c2_pStruct, const emlrtRTEInfo *c2_srcLocation)
{
  c2_pStruct->Image.size[0] = 0;
  c2_pStruct->Image.size[1] = 0;
  c2_pStruct->FilledImage.size[0] = 0;
  c2_pStruct->FilledImage.size[1] = 0;
  c2_emxInit_real_T1(chartInstance, c2_sp, &c2_pStruct->PixelIdxList, 1,
                     c2_srcLocation);
  c2_emxInit_real_T(chartInstance, c2_sp, &c2_pStruct->PixelList, 2,
                    c2_srcLocation);
  c2_emxInit_real_T1(chartInstance, c2_sp, &c2_pStruct->PixelValues, 1,
                     c2_srcLocation);
  c2_pStruct->SubarrayIdx.size[0] = 0;
  c2_pStruct->SubarrayIdx.size[1] = 0;
}

static void c2_emxExpand_s_R6Og1x0kmqQXSF9Pwa4(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49
  *c2_emxArray, int32_T c2_fromIndex, int32_T c2_toIndex, const emlrtRTEInfo
  *c2_srcLocation)
{
  int32_T c2_i;
  for (c2_i = c2_fromIndex; c2_i < c2_toIndex; c2_i++) {
    c2_emxInitStruct_s_R6Og1x0kmqQXSF9(chartInstance, c2_sp, &c2_emxArray->
      data[c2_i], c2_srcLocation);
  }
}

static void c2_emxEnsureCapacity_s_R6Og1x0kmqQ(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_emxArray_s_R6Og1x0kmqQXSF9Pwa49
  *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)c2_newNumel,
      (size_t)(uint32_T)c2_emxArray->size[c2_i], c2_srcLocation, (void *)c2_sp);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof
      (c2_s_R6Og1x0kmqQXSF9Pwa49FD));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(c2_s_R6Og1x0kmqQXSF9Pwa49FD) *
             (uint32_T)c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (c2_s_R6Og1x0kmqQXSF9Pwa49FD *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }

  if (c2_oldNumel > c2_newNumel) {
    c2_emxTrim_s_R6Og1x0kmqQXSF9Pwa49F(chartInstance, c2_emxArray, c2_newNumel,
      c2_oldNumel);
  } else if (c2_oldNumel < c2_newNumel) {
    c2_emxExpand_s_R6Og1x0kmqQXSF9Pwa4(chartInstance, c2_sp, c2_emxArray,
      c2_oldNumel, c2_newNumel, c2_srcLocation);
  }
}

static void c2_emxCopyStruct_s_R6Og1x0kmqQXSF9(SFc2_imagedetectorInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_s_R6Og1x0kmqQXSF9Pwa49FD *c2_dst,
  const c2_s_R6Og1x0kmqQXSF9Pwa49FD *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  c2_dst->Area = c2_src->Area;
  c2_emxCopyMatrix_real_T(chartInstance, c2_dst->Centroid, c2_src->Centroid);
  c2_emxCopyMatrix_real_T1(chartInstance, c2_dst->BoundingBox,
    c2_src->BoundingBox);
  c2_dst->MajorAxisLength = c2_src->MajorAxisLength;
  c2_dst->MinorAxisLength = c2_src->MinorAxisLength;
  c2_dst->Eccentricity = c2_src->Eccentricity;
  c2_dst->Orientation = c2_src->Orientation;
  c2_emxCopy_boolean_T_0x0(chartInstance, &c2_dst->Image, &c2_src->Image);
  c2_emxCopy_boolean_T_0x0(chartInstance, &c2_dst->FilledImage,
    &c2_src->FilledImage);
  c2_dst->FilledArea = c2_src->FilledArea;
  c2_dst->EulerNumber = c2_src->EulerNumber;
  c2_emxCopyMatrix_real_T2(chartInstance, c2_dst->Extrema, c2_src->Extrema);
  c2_dst->EquivDiameter = c2_src->EquivDiameter;
  c2_dst->Extent = c2_src->Extent;
  c2_emxCopy_real_T(chartInstance, c2_sp, &c2_dst->PixelIdxList,
                    &c2_src->PixelIdxList, c2_srcLocation);
  c2_emxCopy_real_T1(chartInstance, c2_sp, &c2_dst->PixelList,
                     &c2_src->PixelList, c2_srcLocation);
  c2_dst->Perimeter = c2_src->Perimeter;
  c2_dst->Circularity = c2_src->Circularity;
  c2_emxCopy_real_T(chartInstance, c2_sp, &c2_dst->PixelValues,
                    &c2_src->PixelValues, c2_srcLocation);
  c2_emxCopyMatrix_real_T(chartInstance, c2_dst->WeightedCentroid,
    c2_src->WeightedCentroid);
  c2_dst->MeanIntensity = c2_src->MeanIntensity;
  c2_dst->MinIntensity = c2_src->MinIntensity;
  c2_dst->MaxIntensity = c2_src->MaxIntensity;
  c2_emxCopy_real_T_1x0(chartInstance, &c2_dst->SubarrayIdx,
                        &c2_src->SubarrayIdx);
  c2_emxCopyMatrix_real_T(chartInstance, c2_dst->SubarrayIdxLengths,
    c2_src->SubarrayIdxLengths);
}

static void c2_emxCopyMatrix_real_T(SFc2_imagedetectorInstanceStruct
  *chartInstance, real_T c2_dst[2], const real_T c2_src[2])
{
  int32_T c2_i;
  (void)chartInstance;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_dst[c2_i] = c2_src[c2_i];
  }
}

static void c2_emxCopyMatrix_real_T1(SFc2_imagedetectorInstanceStruct
  *chartInstance, real_T c2_dst[4], const real_T c2_src[4])
{
  int32_T c2_i;
  (void)chartInstance;
  for (c2_i = 0; c2_i < 4; c2_i++) {
    c2_dst[c2_i] = c2_src[c2_i];
  }
}

static void c2_emxCopy_boolean_T_0x0(SFc2_imagedetectorInstanceStruct
  *chartInstance, c2_emxArray_boolean_T_0x0 *c2_dst, const
  c2_emxArray_boolean_T_0x0 *c2_src)
{
  int32_T c2_i;
  (void)chartInstance;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_dst->size[c2_i] = c2_src->size[c2_i];
  }
}

static void c2_emxCopyMatrix_real_T2(SFc2_imagedetectorInstanceStruct
  *chartInstance, real_T c2_dst[16], const real_T c2_src[16])
{
  int32_T c2_i;
  (void)chartInstance;
  for (c2_i = 0; c2_i < 16; c2_i++) {
    c2_dst[c2_i] = c2_src[c2_i];
  }
}

static void c2_emxCopy_real_T(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T **c2_dst, c2_emxArray_real_T *
  const *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_numElDst;
  int32_T c2_numElSrc;
  c2_numElDst = 1;
  c2_numElSrc = 1;
  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    c2_numElDst *= (*c2_dst)->size[c2_i];
    c2_numElSrc *= (*c2_src)->size[c2_i];
  }

  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    (*c2_dst)->size[c2_i] = (*c2_src)->size[c2_i];
  }

  c2_emxEnsureCapacity_real_T1(chartInstance, c2_sp, *c2_dst, c2_numElDst,
    c2_srcLocation);
  for (c2_i = 0; c2_i < c2_numElSrc; c2_i++) {
    (*c2_dst)->data[c2_i] = (*c2_src)->data[c2_i];
  }
}

static void c2_emxCopy_real_T1(SFc2_imagedetectorInstanceStruct *chartInstance,
  const emlrtStack *c2_sp, c2_emxArray_real_T **c2_dst, c2_emxArray_real_T *
  const *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  int32_T c2_numElDst;
  int32_T c2_numElSrc;
  c2_numElDst = 1;
  c2_numElSrc = 1;
  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    c2_numElDst *= (*c2_dst)->size[c2_i];
    c2_numElSrc *= (*c2_src)->size[c2_i];
  }

  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    (*c2_dst)->size[c2_i] = (*c2_src)->size[c2_i];
  }

  c2_emxEnsureCapacity_real_T(chartInstance, c2_sp, *c2_dst, c2_numElDst,
    c2_srcLocation);
  for (c2_i = 0; c2_i < c2_numElSrc; c2_i++) {
    (*c2_dst)->data[c2_i] = (*c2_src)->data[c2_i];
  }
}

static void c2_emxCopy_real_T_1x0(SFc2_imagedetectorInstanceStruct
  *chartInstance, c2_emxArray_real_T_1x0 *c2_dst, const c2_emxArray_real_T_1x0
  *c2_src)
{
  int32_T c2_i;
  (void)chartInstance;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_dst->size[c2_i] = c2_src->size[c2_i];
  }
}

static void c2_emxInitMatrix_cell_wrap_46(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_cell_wrap_46 c2_pMatrix[2], const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_emxInitStruct_cell_wrap_46(chartInstance, c2_sp, &c2_pMatrix[c2_i],
      c2_srcLocation);
  }
}

static void c2_emxInitStruct_cell_wrap_46(SFc2_imagedetectorInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_cell_wrap_46 *c2_pStruct, const
  emlrtRTEInfo *c2_srcLocation)
{
  c2_emxInit_real_T1(chartInstance, c2_sp, &c2_pStruct->f1, 1, c2_srcLocation);
}

static void c2_emxFreeMatrix_cell_wrap_46(SFc2_imagedetectorInstanceStruct
  *chartInstance, c2_cell_wrap_46 c2_pMatrix[2])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_emxFreeStruct_cell_wrap_46(chartInstance, &c2_pMatrix[c2_i]);
  }
}

static void c2_emxFreeStruct_cell_wrap_46(SFc2_imagedetectorInstanceStruct
  *chartInstance, c2_cell_wrap_46 *c2_pStruct)
{
  c2_emxFree_real_T(chartInstance, &c2_pStruct->f1);
}

static int32_T c2_div_nzp_s32(SFc2_imagedetectorInstanceStruct *chartInstance,
  int32_T c2_numerator, int32_T c2_denominator, int32_T c2_EMLOvCount_src_loc,
  uint32_T c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T c2_length_src_loc)
{
  int32_T c2_quotient;
  uint32_T c2_absDenominator;
  uint32_T c2_absNumerator;
  uint32_T c2_tempAbsQuotient;
  boolean_T c2_quotientNeedsNegation;
  (void)chartInstance;
  (void)c2_EMLOvCount_src_loc;
  (void)c2_ssid_src_loc;
  (void)c2_offset_src_loc;
  (void)c2_length_src_loc;
  if (c2_numerator < 0) {
    c2_absNumerator = ~(uint32_T)c2_numerator + 1U;
  } else {
    c2_absNumerator = (uint32_T)c2_numerator;
  }

  if (c2_denominator < 0) {
    c2_absDenominator = ~(uint32_T)c2_denominator + 1U;
  } else {
    c2_absDenominator = (uint32_T)c2_denominator;
  }

  c2_quotientNeedsNegation = ((c2_numerator < 0) != (c2_denominator < 0));
  c2_tempAbsQuotient = c2_absNumerator / c2_absDenominator;
  if (c2_quotientNeedsNegation) {
    c2_quotient = -(int32_T)c2_tempAbsQuotient;
  } else {
    c2_quotient = (int32_T)c2_tempAbsQuotient;
  }

  return c2_quotient;
}

static int32_T c2__s32_s64_(SFc2_imagedetectorInstanceStruct *chartInstance,
  int64_T c2_b, int32_T c2_EMLOvCount_src_loc, uint32_T c2_ssid_src_loc, int32_T
  c2_offset_src_loc, int32_T c2_length_src_loc)
{
  int32_T c2_d_a;
  (void)c2_EMLOvCount_src_loc;
  c2_d_a = (int32_T)c2_b;
  if ((int64_T)c2_d_a != c2_b) {
    sf_data_overflow_error(chartInstance->S, c2_ssid_src_loc, c2_offset_src_loc,
      c2_length_src_loc);
  }

  return c2_d_a;
}

static void init_dsm_address_info(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_imagedetectorInstanceStruct
  *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_y = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c2_b_data = (uint8_T (*)[921600])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c2_imagedetector_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2475733085U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(75932576U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2976339477U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(454010758U);
}

mxArray *sf_c2_imagedetector_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,9);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2grayBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.Grayto8Buildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  mxSetCell(mxcell3p, 5, mxCreateString(
             "images.internal.coder.buildable.TbbhistBuildable"));
  mxSetCell(mxcell3p, 6, mxCreateString(
             "images.internal.coder.buildable.Ordfilt2Buildable"));
  mxSetCell(mxcell3p, 7, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  mxSetCell(mxcell3p, 8, mxCreateString(
             "images.internal.coder.buildable.ImregionalmaxBuildable"));
  return(mxcell3p);
}

mxArray *sf_c2_imagedetector_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2gray_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_imagedetector_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_imagedetector(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI6BcAsiqh4QILH/LtV3CgTD/E/g"
    "AC7pdCcT+En1kcn5hcklmWGp9sFJ+Zm5iempJakppckl+EMBcEAEcHGiM="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_imagedetector_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sWri0ZPdQ8Z1sjhEI0XXZpH";
}

static void sf_opaque_initialize_c2_imagedetector(void *chartInstanceVar)
{
  initialize_params_c2_imagedetector((SFc2_imagedetectorInstanceStruct*)
    chartInstanceVar);
  initialize_c2_imagedetector((SFc2_imagedetectorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_imagedetector(void *chartInstanceVar)
{
  enable_c2_imagedetector((SFc2_imagedetectorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_imagedetector(void *chartInstanceVar)
{
  disable_c2_imagedetector((SFc2_imagedetectorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_imagedetector(void *chartInstanceVar)
{
  sf_gateway_c2_imagedetector((SFc2_imagedetectorInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_imagedetector(SimStruct* S)
{
  return get_sim_state_c2_imagedetector((SFc2_imagedetectorInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_imagedetector(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c2_imagedetector((SFc2_imagedetectorInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c2_imagedetector(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_imagedetectorInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_imagedetector_optimization_info();
    }

    mdl_cleanup_runtime_resources_c2_imagedetector
      ((SFc2_imagedetectorInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c2_imagedetector(void *chartInstanceVar)
{
  mdl_start_c2_imagedetector((SFc2_imagedetectorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c2_imagedetector(void *chartInstanceVar)
{
  mdl_terminate_c2_imagedetector((SFc2_imagedetectorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_imagedetector((SFc2_imagedetectorInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_imagedetector(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_imagedetector((SFc2_imagedetectorInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc2_imagedetector((SFc2_imagedetectorInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_imagedetector_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [18] = {
    "eNrtV8tu00AUdaJSUQlKhZBACAl2sCyIBStom4caqaUBpw91U03tm3jIeMbMI21WfAFL+Aa+gR1",
    "/wWcgVrDjju2mwbGdlogKEJZcZ+xzz9z3nTqV1qaD1yLeT647zjw+L+NddZLrUrqujN3J+znnfr",
    "p+i0LchG0iSaic0ouTEF6CEsxoKniLd0UujPIuSOAeYiMhdRGboqFhlPebhnuWT+0G1AvcQBjmr",
    "6Es8bc4GyJbZHQbeepUgqebAL4OpDC9oMlIb6Sx1Ee1ALy+MmGZCQq0ayKrlto0TNOIQeMYvBZX",
    "mqDG6lQ3VxMNNX1caKa1VLknQBFGjBKea21AlAsROljDduTj3y2j0agszAuI1GsQkAGoDdqPOQW",
    "HLCdV+OGQcqKFpIQ1QlazgpO6tRnqsyl8YCUOQd3WJJB+JCjXxfF3m2hpg5NDBnU4NL1iNhdeGx",
    "v8HQpHIAv91q2JAUjSgy1euGnskMZxHK1RlkzCNA1hh8hVD+OnwC/MXswc5RKME3RQoggGsZEt1",
    "ZF0gO4tZDNhy2bmtJIxYRJsNQ0WszUGUBaFEVvT4zXCmCqEdUS0AQNgMWudaFIOS1jzcUpRvyPQ",
    "wTa9i6vBcIqBT2E1wX2aG65BBhD3nefYWH5GekZpEdYweesbG5OfJ2EtrkF2iQd5XUASqgB9Fru",
    "3mM2nysYegaiVjtXLAycZMg3lqK7h9SMh++iTkiZyaoKNaCEwVD2MJVbCtsKiKYPZWE7DecQLwL",
    "cNhjLYxLJBbI5PlG1tq1h3A6qHdVCepFFOVA1WHbahhk2oYQTbvM/FEW9KEbppj0/cC4DZRiSnv",
    "LeG/UsOm7h7XijsPFt2TufZlTPMsxO57PPBGE8lh8cZe2b3XaiW71vFX5VUbmVM7mpmn7mMnMUt",
    "4f39zfr7zq1vH+vXPr3jX78+nmX/D9Xzzf/FdH3npNGOCmcwka8Wuz6m11wO/80x/qV0rXYlXd5",
    "v+y+e7D9Ur4JGa3lvbz9aj/m+Vcr1rWb0PXl/z3Z8zLI4P6XX8tODiV0Tk4zr+Dw0pu/8FH8spO",
    "+T68uz2eRvrGTjODdFfgl/DTN5++v731uZTT7Zvz1F/9uZeN+O5/oBsd0CDrxHBzTEpuKDxkObk",
    "JN1+at5fl4554Ll/hY9//vl99t3lrl10XLOBcvNat955/efhi+bA04Gv/QH2zHruep34z875zv/",
    "3E3XT0f/4tQCyvyc0276GY+u3byv/0Ce/gCcS7GH",
    ""
  };

  static char newstr [1241] = "";
  newstr[0] = '\0';
  for (i = 0; i < 18; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c2_imagedetector(SimStruct *S)
{
  const char* newstr = sf_c2_imagedetector_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2521333753U));
  ssSetChecksum1(S,(3136821332U));
  ssSetChecksum2(S,(2512457540U));
  ssSetChecksum3(S,(888337006U));
}

static void mdlRTW_c2_imagedetector(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c2_imagedetector(SimStruct *S)
{
  SFc2_imagedetectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_imagedetectorInstanceStruct *)utMalloc(sizeof
    (SFc2_imagedetectorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_imagedetectorInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_imagedetector;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_imagedetector;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c2_imagedetector;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c2_imagedetector;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c2_imagedetector;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_imagedetector;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_imagedetector;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_imagedetector;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_imagedetector;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_imagedetector;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_imagedetector;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_imagedetector;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c2_JITStateAnimation,
    chartInstance->c2_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c2_imagedetector(chartInstance);
}

void c2_imagedetector_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c2_imagedetector(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_imagedetector(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_imagedetector(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_imagedetector_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
