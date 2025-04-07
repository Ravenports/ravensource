--- cmake/QtRpathHelpers.cmake.orig	2025-03-27 14:17:21 UTC
+++ cmake/QtRpathHelpers.cmake
@@ -8,6 +8,8 @@ function(qt_internal_get_relative_rpath_
         set(rpath_rel_base "@loader_path")
     elseif(LINUX OR SOLARIS OR FREEBSD OR HURD OR OPENBSD)
         set(rpath_rel_base "$ORIGIN")
+    elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly|MidnightBSD")
+        set(rpath_rel_base "$ORIGIN")
     else()
         set(rpath_rel_base "NO_KNOWN_RPATH_REL_BASE")
     endif()
