--- src/adwaita-qt/style/adwaitahelper.cpp.orig	2026-03-23 20:00:02 UTC
+++ src/adwaita-qt/style/adwaitahelper.cpp
@@ -1526,10 +1526,10 @@ void Helper::renderProgressBarBusyConten
     QRectF contentRect;
     if (horizontal) {
         contentRect = QRect(baseRect.left(), baseRect.top(), Metrics::ProgressBar_BusyIndicatorSize, baseRect.height());
-        contentRect.translate(fabs(progress - 50) / 50.0 * (baseRect.width() - contentRect.width()), 0);
+        contentRect.translate(fabs((double)progress - 50.0) / 50.0 * (baseRect.width() - contentRect.width()), 0);
     } else {
         contentRect = QRect(baseRect.left(), baseRect.top(), baseRect.width(), Metrics::ProgressBar_BusyIndicatorSize);
-        contentRect.translate(0, fabs(progress - 50) / 50.0 * (baseRect.height() - contentRect.height()));
+        contentRect.translate(0, fabs((double)progress - 50.0) / 50.0 * (baseRect.height() - contentRect.height()));
     }
 
     painter->setBrush(color);
