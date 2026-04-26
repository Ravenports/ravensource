--- src/corr_matern52_matrix.cpp.orig	2022-10-13 01:55:18 UTC
+++ src/corr_matern52_matrix.cpp
@@ -148,7 +148,7 @@ arma::cube kernel_matern52_dC(arma::mat
   int nsum = x.n_cols;
   arma::cube dC_dparams(lenparams_D, nrow, nrow);
   double log10 = log(10.0);
-  double sqrt5 = sqrt(5);
+  double sqrt5 = sqrt(5.0);
 
   if (s2_est) {
     // dC_dparams(lenparams_D,,) = C * log(10.0);
