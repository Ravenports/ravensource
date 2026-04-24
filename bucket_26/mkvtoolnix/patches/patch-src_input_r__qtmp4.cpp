--- src/input/r_qtmp4.cpp.orig	2026-04-05 12:50:33 UTC
+++ src/input/r_qtmp4.cpp
@@ -1615,7 +1615,7 @@ qtmp4_reader_c::handle_display_matrix(qt
     dmx.yaw = 180;
   else
     return;
-  dmx.roll = 180 / M_PI * atan2(matrix[1][0], matrix[1][1]);
+  dmx.roll = 180 / M_PI * atan2(static_cast<double>(matrix[1][0]), static_cast<double>(matrix[1][1]));
   ignored = false;
 
   if (!dmx.yaw && !dmx.roll)
