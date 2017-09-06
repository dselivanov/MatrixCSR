# Faster sparse-dense matrix products

Default format for sparse matrices in R is `CSC` - compressed column sparse. However `CSR` is more mainstream in many algorithms and modern C/C++ libraries.

**MatrixCSR** package brings faster `CSR` * `dense` matrix products to R. Noticeably `CSR` * `dense` matrix products are multithreaded (thanks to [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) and [RcppEigen](https://github.com/RcppCore/RcppEigen) libraries).

In example below on my laptop with 4-core/8-thread Intel Core i7 CPU `CSR` * `dense` martix product is more than **6 times faster** then default `CSC` *  `dense` product.

```r
library(Matrix)
library(MatrixCSR)
library(microbenchmark)

set.seed(1)
nnz_share = 0.0001
n_row = 1e6
n_col = 1e5
n_row_dense = n_col
n_col_dense = 1e2

nnz = n_row * n_col * nnz_share
sp_m_coo = sparseMatrix(i = sample(n_row, nnz, TRUE), j = sample(n_col, nnz, TRUE), 
                        x = runif(nnz, TRUE), dims = c(n_row, n_col), giveCsparse = FALSE)

object.size(sp_m_coo)/1e6
# 160 Mb

sp_m_csc = as(sp_m_coo, "CsparseMatrix")
sp_m_csr = as(sp_m_coo, "RsparseMatrix")

dense_m = matrix(runif(n_row_dense * n_col_dense), nrow = n_row_dense, ncol = n_col_dense)
object.size(dense_m)/1e6
# 80 Mb


microbenchmark(
  csc_prod = sp_m_csc %*% dense_m, 
  csr_prod = sp_m_csr %*% dense_m, 
  times = 10
)
#Unit: seconds
#     expr       min        lq     mean    median        uq       max neval
# csc_prod 10.550470 10.617285 10.85617 10.713557 11.224757 11.362016    10
# csr_prod  1.627799  1.717712  1.75765  1.729939  1.774248  1.905975    10
```

# Faster truncated SVD

[irlba](https://github.com/bwlewis/irlba) package provides two of state-of the art implementations of truncated SVD solvers:

1. Implicitly-restarted Lanczos method
1. Randomized SVD

With `MatrixCSR` package second approach can be significantly accelerated for free (without any additional manual adjustments). For example on matrix from example aboce it is more than **2 times faster** than default `CSC`.

```r
library(irlba)
microbenchmark(
  # randomized SVD on CSC matrix
  SVD_CSC = svdr(x = sp_m_csc, k = 10),
  # randomized SVD on CSR matrix
  SVD_CSR = svdr(x = sp_m_csr, k = 10),
  times = 1
)
#Unit: seconds
#    expr      min       lq     mean   median       uq      max neval
# SVD_CSC 25.70179 25.70179 25.70179 25.70179 25.70179 25.70179     1
# SVD_CSR 11.61360 11.61360 11.61360 11.61360 11.61360 11.61360     1
```