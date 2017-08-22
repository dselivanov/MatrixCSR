// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

// we only include RcppEigen.h which pulls Rcpp.h in for us
#include <RcppEigen.h>
using namespace Rcpp;
using namespace Eigen;
typedef Eigen::Map<Eigen::SparseMatrix<double, Eigen::RowMajor> > MSpMat_csr;
  
// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
NumericMatrix prod_csr_dense(SEXP csr, SEXP dense_m_r) {
  // Rprintf("prod_csr_dense\n");
  const MSpMat_csr sparse(as<MSpMat_csr>(csr));
  const Map<MatrixXd> dense(as<Map<MatrixXd> >(dense_m_r));
  NumericMatrix res(sparse.rows(), dense.cols());
  Map<MatrixXd>( res.begin(), res.nrow(), res.ncol()) = sparse * dense;
  return res;
}

// [[Rcpp::export]]
NumericMatrix prod_dense_csr(SEXP dense_m_r, SEXP csr_r) {
  // Rprintf("prod_dense_csr\n");
  const MSpMat_csr sparse(as<MSpMat_csr>(csr_r));
  const Map<MatrixXd> dense(as<Map<MatrixXd> >(dense_m_r));
  NumericMatrix res(dense.rows(), sparse.cols());
  Map<MatrixXd>( res.begin(), res.nrow(), res.ncol()) = dense * sparse;
  return res;
}

// [[Rcpp::export]]
NumericMatrix tcrossprod_dense_csr(SEXP dense_m_r, SEXP csr_r) {
  // Rprintf("tcrossprod_dense_csr\n");
  const MSpMat_csr sparse(as<MSpMat_csr>(csr_r));
  const Map<MatrixXd> dense(as<Map<MatrixXd> >(dense_m_r));
  NumericMatrix res(dense.rows(), sparse.rows());
  Map<MatrixXd>( res.begin(), res.nrow(), res.ncol()) = dense * sparse.transpose();
  return res;
}

// [[Rcpp::export]]
NumericMatrix crossprod_csr_dense(SEXP csr_r, SEXP dense_m_r) {
  // Rprintf("crossprod_csr_dense\n");
  const MSpMat_csr sparse(as<MSpMat_csr>(csr_r));
  const Map<MatrixXd> dense(as<Map<MatrixXd> >(dense_m_r));
  NumericMatrix res(sparse.cols(), dense.cols());
  // not sure why, but having sparse transposed materialized is much faster 
  // than product with transposed not-materialized
  Eigen::SparseMatrix<double, Eigen::RowMajor> sparse2 = sparse.transpose();
  Map<MatrixXd>( res.begin(), res.nrow(), res.ncol()) = sparse2 * dense;
  return res;
}
