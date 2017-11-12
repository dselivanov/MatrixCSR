// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

// prod_csr_dense
NumericMatrix prod_csr_dense(const S4& csr_r, const SEXP& dense_m_r);
RcppExport SEXP _MatrixCSR_prod_csr_dense(SEXP csr_rSEXP, SEXP dense_m_rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const S4& >::type csr_r(csr_rSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type dense_m_r(dense_m_rSEXP);
    rcpp_result_gen = Rcpp::wrap(prod_csr_dense(csr_r, dense_m_r));
    return rcpp_result_gen;
END_RCPP
}
// prod_dense_csr
NumericMatrix prod_dense_csr(const SEXP& dense_m_r, const S4& csr_r);
RcppExport SEXP _MatrixCSR_prod_dense_csr(SEXP dense_m_rSEXP, SEXP csr_rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const SEXP& >::type dense_m_r(dense_m_rSEXP);
    Rcpp::traits::input_parameter< const S4& >::type csr_r(csr_rSEXP);
    rcpp_result_gen = Rcpp::wrap(prod_dense_csr(dense_m_r, csr_r));
    return rcpp_result_gen;
END_RCPP
}
// tcrossprod_dense_csr
NumericMatrix tcrossprod_dense_csr(const SEXP& dense_m_r, const S4& csr_r);
RcppExport SEXP _MatrixCSR_tcrossprod_dense_csr(SEXP dense_m_rSEXP, SEXP csr_rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const SEXP& >::type dense_m_r(dense_m_rSEXP);
    Rcpp::traits::input_parameter< const S4& >::type csr_r(csr_rSEXP);
    rcpp_result_gen = Rcpp::wrap(tcrossprod_dense_csr(dense_m_r, csr_r));
    return rcpp_result_gen;
END_RCPP
}
// crossprod_csr_dense
NumericMatrix crossprod_csr_dense(const S4& csr_r, const SEXP& dense_m_r);
RcppExport SEXP _MatrixCSR_crossprod_csr_dense(SEXP csr_rSEXP, SEXP dense_m_rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const S4& >::type csr_r(csr_rSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type dense_m_r(dense_m_rSEXP);
    rcpp_result_gen = Rcpp::wrap(crossprod_csr_dense(csr_r, dense_m_r));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_MatrixCSR_prod_csr_dense", (DL_FUNC) &_MatrixCSR_prod_csr_dense, 2},
    {"_MatrixCSR_prod_dense_csr", (DL_FUNC) &_MatrixCSR_prod_dense_csr, 2},
    {"_MatrixCSR_tcrossprod_dense_csr", (DL_FUNC) &_MatrixCSR_tcrossprod_dense_csr, 2},
    {"_MatrixCSR_crossprod_csr_dense", (DL_FUNC) &_MatrixCSR_crossprod_csr_dense, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_MatrixCSR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
