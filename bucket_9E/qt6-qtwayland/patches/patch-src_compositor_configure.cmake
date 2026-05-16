--- src/compositor/configure.cmake.orig	2026-05-08 01:18:49 UTC
+++ src/compositor/configure.cmake
@@ -7,7 +7,7 @@
 
 #### Libraries
 
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if(UNIX OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(Waylandkms PROVIDED_TARGETS PkgConfig::Waylandkms MODULE_NAME waylandcompositor QMAKE_LIB wayland-kms)
 endif()
 # special case begin
