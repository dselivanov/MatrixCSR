// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
using namespace Rcpp;
using namespace Eigen;


typedef Map< Eigen::SparseMatrix<double, Eigen::RowMajor> > MSpMat_csr;


MSpMat_csr create_eigen_csr_map(const S4 &csr) {
  IntegerVector dim = csr.slot("Dim");
  NumericVector x = csr.slot("x");
  IntegerVector p = csr.slot("p");
  IntegerVector j = csr.slot("j");
  const Map< Eigen::SparseMatrix<double, Eigen::RowMajor> > sparse(dim[0], dim[1], x.size(), p.begin(), j.begin(), x.begin());
  return(sparse);
}

// [[Rcpp::export]]
NumericMatrix prod_csr_dense(const S4 &csr_r, const SEXP &dense_m_r) {
  MSpMat_csr sparse = create_eigen_csr_map(csr_r);
  const Map<MatrixXd> dense(as<Map<MatrixXd> >(dense_m_r));
  NumericMatrix res(sparse.rows(), dense.cols());
  Map<MatrixXd>( res.begin(), res.nrow(), res.ncol()) = sparse * dense;
  return res;
}

// [[Rcpp::export]]
NumericMatrix prod_dense_csr(const SEXP &dense_m_r, const S4 &csr_r) {
  MSpMat_csr sparse = create_eigen_csr_map(csr_r);
  const Map<MatrixXd> dense(as<Map<MatrixXd> >(dense_m_r));
  NumericMatrix res(dense.rows(), sparse.cols());
  Map<MatrixXd>( res.begin(), res.nrow(), res.ncol()) = dense * sparse;
  return res;
}

// [[Rcpp::export]]
NumericMatrix tcrossprod_dense_csr(const SEXP &dense_m_r, const S4 &csr_r) {
  const MSpMat_csr sparse(as<MSpMat_csr>(csr_r));
  const Map<MatrixXd> dense(as<Map<MatrixXd> >(dense_m_r));
  NumericMatrix res(dense.rows(), sparse.rows());
  Map<MatrixXd>( res.begin(), res.nrow(), res.ncol()) = dense * sparse.transpose();
  return res;
}

// [[Rcpp::export]]
NumericMatrix crossprod_csr_dense(const S4 &csr_r, const SEXP &dense_m_r) {
  const MSpMat_csr sparse(as<MSpMat_csr>(csr_r));
  const Map<MatrixXd> dense(as<Map<MatrixXd> >(dense_m_r));
  NumericMatrix res(sparse.cols(), dense.cols());
  // not sure why, but having sparse transposed materialized is much faster 
  // than product with transposed not-materialized
  Eigen::SparseMatrix<double, Eigen::RowMajor> sparse2 = sparse.transpose();
  Map<MatrixXd>( res.begin(), res.nrow(), res.ncol()) = sparse2 * dense;
  return res;
}
