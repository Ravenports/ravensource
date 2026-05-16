--- src/configure.cmake.orig	2026-05-08 01:18:49 UTC
+++ src/configure.cmake
@@ -7,7 +7,7 @@
 
 #### Libraries
 
-if(LINUX OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if(UNIX OR QT_FIND_ALL_PACKAGES_ALWAYS)
     # waylandclient libraries
     if(TARGET Wayland::Client)
         qt_internal_disable_find_package_global_promotion(Wayland::Client)
