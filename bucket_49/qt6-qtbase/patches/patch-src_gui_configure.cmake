--- src/gui/configure.cmake.orig	2024-03-19 15:46:43 UTC
+++ src/gui/configure.cmake
@@ -29,7 +29,7 @@ set_property(CACHE INPUT_libpng PROPERTY
 
 #### Libraries
 qt_set01(X11_SUPPORTED LINUX OR HPUX OR FREEBSD OR NETBSD OR OPENBSD OR SOLARIS OR
-    HURD)
+    HURD OR MIDNIGHT OR DRAGONFLY)
 qt_find_package(ATSPI2 PROVIDED_TARGETS PkgConfig::ATSPI2 MODULE_NAME gui QMAKE_LIB atspi)
 qt_find_package(DirectFB PROVIDED_TARGETS PkgConfig::DirectFB MODULE_NAME gui QMAKE_LIB directfb)
 qt_find_package(Libdrm PROVIDED_TARGETS Libdrm::Libdrm MODULE_NAME gui QMAKE_LIB drm)
