--- rtgui/thresholdselector.cc.orig	2026-01-13 18:23:55 UTC
+++ rtgui/thresholdselector.cc
@@ -1035,8 +1035,8 @@ double ThresholdSelector::shapePositionV
         (cursorId == TS_BOTTOMLEFT || cursorId == TS_BOTTOMRIGHT)
             ? precisionBottom
             : precisionTop;
-    return round(positions[cursorId] * pow(double(10), precision)) /
-           pow(double(10), precision);
+    return round(positions[cursorId] * pow(double(10), (double)precision)) /
+           pow(double(10), (double)precision);
 }
 
 void ThresholdSelector::set_tooltip_markup(const Glib::ustring &markup)
