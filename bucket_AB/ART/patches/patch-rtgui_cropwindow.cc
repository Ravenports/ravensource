--- rtgui/cropwindow.cc.orig	2026-01-13 18:23:55 UTC
+++ rtgui/cropwindow.cc
@@ -2372,10 +2372,10 @@ void CropWindow::zoomIn(bool toCursor, i
                 int y1 =
                     cropHandler.cropParams.y + cropHandler.cropParams.h / 2;
                 double cropd =
-                    sqrt(cropHandler.cropParams.h * cropHandler.cropParams.h +
-                         cropHandler.cropParams.w * cropHandler.cropParams.w) *
+                    sqrt((double)(cropHandler.cropParams.h * cropHandler.cropParams.h +
+                         cropHandler.cropParams.w * cropHandler.cropParams.w)) *
                     zoomSteps[cropZoom].zoom;
-                double imd = sqrt(imgW * imgW + imgH * imgH);
+                double imd = sqrt((double)(imgW * imgW + imgH * imgH));
                 double d;
 
                 // the more we can see of the crop, the more gravity towards
