--- rtengine/iptransform.cc.orig	2026-03-13 20:14:10 UTC
+++ rtengine/iptransform.cc
@@ -712,7 +712,7 @@ void calcVignettingParams(int oW, int oH
     maxRadius = sqrt((double)(oW * oW + oH * oH)) / 2.;
 
     // vignette variables with applied strength
-    v = 1.0 + vignetting.strength * fabs(vignetting.amount) * 3.0 / 400.0;
+    v = 1.0 + vignetting.strength * fabs((double)vignetting.amount) * 3.0 / 400.0;
     b = 1.0 + vignetting.radius * 7.0 / 100.0;
     mul = (1.0 - v) / tanh(b);
 }
