--- src/corr_matern32_matrix.cpp.orig	2022-10-13 01:55:18 UTC
+++ src/corr_matern32_matrix.cpp
@@ -143,7 +143,7 @@ arma::cube kernel_matern32_dC(arma::mat
   int nsum = x.n_cols;
   arma::cube dC_dparams(lenparams_D, nrow, nrow);
   double log10 = log(10.0);
-  double sqrt3 = sqrt(3);
+  double sqrt3 = sqrt(3.0);
 
   if (s2_est) {
     // dC_dparams(lenparams_D,,) = C * log10;
