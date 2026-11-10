--- src/gui/thresholdadjuster.cc.orig	2026-11-10 09:54:54 UTC
+++ src/gui/thresholdadjuster.cc
@@ -208,7 +208,7 @@ double ThresholdAdjuster::shapeValue(dou
 {
 
     unsigned int digit = tSelector.getPrecision();
-    return round(a * pow(double(10), digit)) / pow(double(10), digit);
+    return round(a * pow(double(10), (double)digit)) / pow(double(10), (double)digit);
 }
 
 void ThresholdAdjuster::selectorChanged()
