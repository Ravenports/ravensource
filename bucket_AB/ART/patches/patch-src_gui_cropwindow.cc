--- src/gui/cropwindow.cc.orig	2026-10-15 13:01:50 UTC
+++ src/gui/cropwindow.cc
@@ -2467,10 +2467,10 @@ void CropWindow::zoomIn(bool toCursor, i
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
