--- src/gui/thresholdadjuster.cc.orig	2026-10-15 13:01:50 UTC
+++ src/gui/thresholdadjuster.cc
@@ -207,7 +207,7 @@ double ThresholdAdjuster::shapeValue(dou
 {
 
     unsigned int digit = tSelector.getPrecision();
-    return round(a * pow(double(10), digit)) / pow(double(10), digit);
+    return round(a * pow(double(10), (double)digit)) / pow(double(10), (double)digit);
 }
 
 void ThresholdAdjuster::selectorChanged()
