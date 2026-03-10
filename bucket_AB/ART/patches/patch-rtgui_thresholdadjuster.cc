--- rtgui/thresholdadjuster.cc.orig	2026-01-13 18:23:55 UTC
+++ rtgui/thresholdadjuster.cc
@@ -203,7 +203,7 @@ double ThresholdAdjuster::shapeValue(dou
 {
 
     unsigned int digit = tSelector.getPrecision();
-    return round(a * pow(double(10), digit)) / pow(double(10), digit);
+    return round(a * pow(double(10), (double)digit)) / pow(double(10), (double)digit);
 }
 
 void ThresholdAdjuster::selectorChanged()
