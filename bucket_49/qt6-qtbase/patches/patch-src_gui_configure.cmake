--- src/gui/configure.cmake.orig	2024-11-14 11:02:40 UTC
+++ src/gui/configure.cmake
@@ -29,7 +29,7 @@ set_property(CACHE INPUT_libpng PROPERTY
 
 #### Libraries
 qt_set01(X11_SUPPORTED LINUX OR HPUX OR FREEBSD OR NETBSD OR OPENBSD OR SOLARIS OR
-    HURD)
+    HURD OR MIDNIGHT OR DRAGONFLY)
 qt_find_package(ATSPI2 PROVIDED_TARGETS PkgConfig::ATSPI2 MODULE_NAME gui QMAKE_LIB atspi)
 qt_find_package(DirectFB PROVIDED_TARGETS PkgConfig::DirectFB MODULE_NAME gui QMAKE_LIB directfb)
 qt_find_package(Libdrm PROVIDED_TARGETS Libdrm::Libdrm MODULE_NAME gui QMAKE_LIB drm)
@@ -69,7 +69,7 @@ qt_find_package(GLESv2 PROVIDED_TARGETS
 qt_find_package(Tslib PROVIDED_TARGETS PkgConfig::Tslib MODULE_NAME gui QMAKE_LIB tslib)
 qt_find_package(WrapVulkanHeaders PROVIDED_TARGETS WrapVulkanHeaders::WrapVulkanHeaders
     MODULE_NAME gui QMAKE_LIB vulkan MARK_OPTIONAL)
-if((LINUX) OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if((LINUX OR FREEBSD OR DRAGONFLY OR MIDNIGHT OR NETBSD) OR QT_FIND_ALL_PACKAGES_ALWAYS)
     qt_find_package(Wayland PROVIDED_TARGETS Wayland::Server MODULE_NAME gui QMAKE_LIB wayland_server)
     qt_find_package(Wayland PROVIDED_TARGETS Wayland::Client MODULE_NAME gui QMAKE_LIB wayland_client)
 endif()
