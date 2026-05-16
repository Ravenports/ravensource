--- src/gui/configure.cmake.orig	2026-05-07 07:50:01 UTC
+++ src/gui/configure.cmake
@@ -28,7 +28,7 @@ set_property(CACHE INPUT_libpng PROPERTY
 
 
 #### Libraries
-if(LINUX OR HPUX OR FREEBSD OR NETBSD OR OPENBSD OR SOLARIS OR HURD)
+if(LINUX OR HPUX OR FREEBSD OR NETBSD OR OPENBSD OR SOLARIS OR DRAGONFLY OR MIDNIGHT OR HURD)
     set(X11_SUPPORTED 1)
 else()
     set(X11_SUPPORTED 0)
@@ -100,7 +100,7 @@ qt_find_package(GLESv2 MODULE
 qt_find_package(Tslib MODULE PROVIDED_TARGETS PkgConfig::Tslib MODULE_NAME gui QMAKE_LIB tslib)
 qt_find_package(WrapVulkanHeaders MODULE PROVIDED_TARGETS WrapVulkanHeaders::WrapVulkanHeaders
     MODULE_NAME gui QMAKE_LIB vulkan MARK_OPTIONAL)
-if(LINUX OR FREEBSD OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if(UNIX OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(Wayland MODULE PROVIDED_TARGETS Wayland::Server
                     MODULE_NAME gui QMAKE_LIB wayland_server)
     qt_find_package(Wayland MODULE PROVIDED_TARGETS Wayland::Client
@@ -217,7 +217,7 @@ endif()
 qt_add_qmake_lib_dependency(xrender xlib)
 
 # qt wayland client
-if(LINUX OR FREEBSD OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if(UNIX OR QT_FIND_ALL_PACKAGES_ALWAYS)
     # EGL
     if(NOT TARGET EGL::EGL)
         qt_find_package(EGL MODULE
