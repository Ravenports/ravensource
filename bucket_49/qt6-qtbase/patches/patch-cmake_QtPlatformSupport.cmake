--- cmake/QtPlatformSupport.cmake.orig	2026-05-07 07:50:01 UTC
+++ cmake/QtPlatformSupport.cmake
@@ -43,6 +43,18 @@ else()
     set(OPENBSD 0)
 endif()
 
+if(CMAKE_SYSTEM_NAME STREQUAL "DragonFly")
+    set(DRAGONFLY 1)
+else()
+    set(DRAGONFLY 0)
+endif()
+
+if(CMAKE_SYSTEM_NAME STREQUAL "MidnightBSD")
+    set(MIDNIGHT 1)
+else()
+    set(MIDNIGHT 0)
+endif()
+
 if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
     set(FREEBSD 1)
 else()
@@ -87,7 +99,7 @@ else()
     set(WEBOS 0)
 endif()
 
-if(APPLE OR OPENBSD OR FREEBSD OR NETBSD)
+if(APPLE OR OPENBSD OR FREEBSD OR NETBSD OR DRAGONFLY OR MIDNIGHT)
     set(BSD 1)
 else()
     set(BSD 0)
