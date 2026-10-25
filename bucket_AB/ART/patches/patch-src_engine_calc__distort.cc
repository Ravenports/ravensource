--- src/engine/calc_distort.cc.orig	2026-10-15 13:01:50 UTC
+++ src/engine/calc_distort.cc
@@ -62,7 +62,7 @@ int calcDistortion(unsigned char *img1,
     fl = KLTCreateFeatureList(N_FEATURES * nfactor);
     ft = KLTCreateFeatureTable(2, N_FEATURES * nfactor);
 
-    radius = sqrt(ncols * ncols + nrows * nrows) / 2.0;
+    radius = sqrt((double)ncols * ncols + nrows * nrows) / 2.0;
     wc = ((double)ncols) / 2.0 - 0.5;
     hc = ((double)nrows) / 2.0 - 0.5;
 
