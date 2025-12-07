--- src/gui/configure.cmake.orig	2025-11-12 10:17:57 UTC
+++ src/gui/configure.cmake
@@ -29,7 +29,7 @@ set_property(CACHE INPUT_libpng PROPERTY
 
 #### Libraries
 qt_set01(X11_SUPPORTED LINUX OR HPUX OR FREEBSD OR NETBSD OR OPENBSD OR SOLARIS OR
-    HURD)
+    HURD OR MIDNIGHT OR DRAGONFLY)
 qt_find_package(ATSPI2 MODULE PROVIDED_TARGETS PkgConfig::ATSPI2 MODULE_NAME gui QMAKE_LIB atspi)
 qt_find_package(DirectFB PROVIDED_TARGETS PkgConfig::DirectFB MODULE_NAME gui QMAKE_LIB directfb)
 qt_find_package(Libdrm MODULE PROVIDED_TARGETS Libdrm::Libdrm MODULE_NAME gui QMAKE_LIB drm)
@@ -76,7 +76,7 @@ qt_find_package(GLESv2 MODULE
 qt_find_package(Tslib MODULE PROVIDED_TARGETS PkgConfig::Tslib MODULE_NAME gui QMAKE_LIB tslib)
 qt_find_package(WrapVulkanHeaders MODULE PROVIDED_TARGETS WrapVulkanHeaders::WrapVulkanHeaders
     MODULE_NAME gui QMAKE_LIB vulkan MARK_OPTIONAL)
-if(LINUX OR FREEBSD OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if(UNIX OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(Wayland MODULE PROVIDED_TARGETS Wayland::Server
                     MODULE_NAME gui QMAKE_LIB wayland_server)
     qt_find_package(Wayland MODULE PROVIDED_TARGETS Wayland::Client
@@ -192,7 +192,7 @@ endif()
 qt_add_qmake_lib_dependency(xrender xlib)
 
 # qt wayland client
-if(LINUX OR FREEBSD OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if(UNIX OR QT_FIND_ALL_PACKAGES_ALWAYS)
     # EGL
     if(NOT TARGET EGL::EGL)
         qt_find_package(EGL MODULE
