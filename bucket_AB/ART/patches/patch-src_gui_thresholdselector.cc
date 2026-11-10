--- src/gui/thresholdselector.cc.orig	2026-11-10 09:54:54 UTC
+++ src/gui/thresholdselector.cc
@@ -1040,8 +1040,8 @@ double ThresholdSelector::shapePositionV
         (cursorId == TS_BOTTOMLEFT || cursorId == TS_BOTTOMRIGHT)
             ? precisionBottom
             : precisionTop;
-    return round(positions[cursorId] * pow(double(10), precision)) /
-           pow(double(10), precision);
+    return round(positions[cursorId] * pow(double(10), (double)precision)) /
+           pow(double(10), (double)precision);
 }
 
 void ThresholdSelector::set_tooltip_markup(const Glib::ustring &markup)
