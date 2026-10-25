--- src/gui/thresholdselector.cc.orig	2026-10-15 13:01:50 UTC
+++ src/gui/thresholdselector.cc
@@ -1039,8 +1039,8 @@ double ThresholdSelector::shapePositionV
         (cursorId == TS_BOTTOMLEFT || cursorId == TS_BOTTOMRIGHT)
             ? precisionBottom
             : precisionTop;
-    return round(positions[cursorId] * pow(double(10), precision)) /
-           pow(double(10), precision);
+    return round(positions[cursorId] * pow(double(10), (double)precision)) /
+           pow(double(10), (double)precision);
 }
 
 void ThresholdSelector::set_tooltip_markup(const Glib::ustring &markup)
