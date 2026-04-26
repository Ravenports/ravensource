--- src/s2/s2metrics.cc.orig	2025-01-07 11:51:24 UTC
+++ src/s2/s2metrics.cc
@@ -53,8 +53,8 @@ const LengthMetric kAvgAngleSpan(M_PI /
 
 const LengthMetric kMinWidth(
     S2_PROJECTION == S2_LINEAR_PROJECTION ? sqrt(2. / 3) :             // 0.816
-    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI / (2 * sqrt(2)) :        // 1.111
-    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2 * sqrt(2) / 3 :       // 0.943
+    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI / (2 * sqrt(2.0)) :      // 1.111
+    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2 * sqrt(2.0) / 3 :     // 0.943
     0);
 
 const LengthMetric kMaxWidth(kMaxAngleSpan.deriv());
@@ -67,9 +67,9 @@ const LengthMetric kAvgWidth(
     0);
 
 const LengthMetric kMinEdge(
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt(2) / 3 :          // 0.943
-    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI / (2 * sqrt(2)) :        // 1.111
-    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2 * sqrt(2) / 3 :       // 0.943
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt(2.0) / 3 :        // 0.943
+    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI / (2 * sqrt(2.0)) :      // 1.111
+    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2 * sqrt(2.0) / 3 :     // 0.943
     0);
 
 const LengthMetric kMaxEdge(kMaxAngleSpan.deriv());
@@ -82,13 +82,13 @@ const LengthMetric kAvgEdge(
     0);
 
 const LengthMetric kMinDiag(
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt(2) / 3 :          // 0.943
-    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI * sqrt(2) / 3 :          // 1.481
-    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 8 * sqrt(2) / 9 :       // 1.257
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt(2.0) / 3 :        // 0.943
+    S2_PROJECTION == S2_TAN_PROJECTION ? M_PI * sqrt(2.0) / 3 :        // 1.481
+    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 8 * sqrt(2.0) / 9 :     // 1.257
     0);
 
 const LengthMetric kMaxDiag(
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt(2) :              // 2.828
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? 2 * sqrt(2.0) :            // 2.828
     S2_PROJECTION == S2_TAN_PROJECTION ? M_PI * sqrt(2. / 3) :         // 2.565
     S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 2.438654594434021032 :  // 2.439
     0);
@@ -100,9 +100,9 @@ const LengthMetric kAvgDiag(
     0);
 
 const AreaMetric kMinArea(
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? 4 / (3 * sqrt(3)) :        // 0.770
-    S2_PROJECTION == S2_TAN_PROJECTION ? (M_PI*M_PI) / (4*sqrt(2)) :   // 1.745
-    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 8 * sqrt(2) / 9 :       // 1.257
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? 4 / (3 * sqrt(3.0)) :      // 0.770
+    S2_PROJECTION == S2_TAN_PROJECTION ? (M_PI*M_PI) / (4*sqrt(2.0)) : // 1.745
+    S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 8 * sqrt(2.0) / 9 :     // 1.257
     0);
 
 const AreaMetric kMaxArea(
@@ -115,12 +115,12 @@ const AreaMetric kAvgArea(4 * M_PI / 6);
 // This is true for all projections.
 
 const double kMaxEdgeAspect = (
-    S2_PROJECTION == S2_LINEAR_PROJECTION ? sqrt(2) :                  // 1.414
-    S2_PROJECTION == S2_TAN_PROJECTION ?  sqrt(2) :                    // 1.414
+    S2_PROJECTION == S2_LINEAR_PROJECTION ? sqrt(2.0) :                // 1.414
+    S2_PROJECTION == S2_TAN_PROJECTION ?  sqrt(2.0) :                  // 1.414
     S2_PROJECTION == S2_QUADRATIC_PROJECTION ? 1.442615274452682920 :  // 1.443
     0);
 
-const double kMaxDiagAspect = sqrt(3);                             // 1.732
+const double kMaxDiagAspect = sqrt(3.0);                           // 1.732
 // This is true for all projections.
 
 }  // namespace S2
