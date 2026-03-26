--- rtengine/calc_distort.cc.orig	2026-03-13 20:14:10 UTC
+++ rtengine/calc_distort.cc
@@ -59,7 +59,7 @@ int calcDistortion(unsigned char *img1,
     fl = KLTCreateFeatureList(N_FEATURES * nfactor);
     ft = KLTCreateFeatureTable(2, N_FEATURES * nfactor);
 
-    radius = sqrt(ncols * ncols + nrows * nrows) / 2.0;
+    radius = sqrt((double)(ncols * ncols + nrows * nrows)) / 2.0;
     wc = ((double)ncols) / 2.0 - 0.5;
     hc = ((double)nrows) / 2.0 - 0.5;
 
