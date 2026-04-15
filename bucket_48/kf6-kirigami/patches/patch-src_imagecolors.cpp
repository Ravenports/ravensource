--- src/imagecolors.cpp.orig	2026-03-07 20:31:28 UTC
+++ src/imagecolors.cpp
@@ -250,13 +250,13 @@ static inline int squareDistance(QRgb co
     // https://en.wikipedia.org/wiki/Color_difference
     // Using RGB distance for performance, as CIEDE2000 is too complicated
     if (qRed(color1) - qRed(color2) < 128) {
-        return 2 * pow(qRed(color1) - qRed(color2), 2) //
-            + 4 * pow(qGreen(color1) - qGreen(color2), 2) //
-            + 3 * pow(qBlue(color1) - qBlue(color2), 2);
+        return 2 * pow(qRed(color1) - qRed(color2), 2.0) //
+            + 4 * pow(qGreen(color1) - qGreen(color2), 2.0) //
+            + 3 * pow(qBlue(color1) - qBlue(color2), 2.0);
     } else {
-        return 3 * pow(qRed(color1) - qRed(color2), 2) //
-            + 4 * pow(qGreen(color1) - qGreen(color2), 2) //
-            + 2 * pow(qBlue(color1) - qBlue(color2), 2);
+        return 3 * pow(qRed(color1) - qRed(color2), 2.0) //
+            + 4 * pow(qGreen(color1) - qGreen(color2), 2.0l) //
+            + 2 * pow(qBlue(color1) - qBlue(color2), 2.0);
     }
 }
 
