--- src/s2/s2builder.cc.orig	2025-01-07 11:51:24 UTC
+++ src/s2/s2builder.cc
@@ -315,7 +315,7 @@ void S2Builder::Init(const Options& opti
   // error in the calculation to compare this distance against the bound.
   double d = sin(edge_snap_radius);
   edge_snap_radius_sin2_ = d * d;
-  edge_snap_radius_sin2_ += ((9.5 * d + 2.5 + 2 * sqrt(3)) * d +
+  edge_snap_radius_sin2_ += ((9.5 * d + 2.5 + 2 * sqrt(3.0)) * d +
                              9 * DBL_EPSILON) * DBL_EPSILON;
 
   // Initialize the current label set.
