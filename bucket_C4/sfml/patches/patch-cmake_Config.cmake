--- cmake/Config.cmake.orig	2025-04-22 13:06:02 UTC
+++ cmake/Config.cmake
@@ -35,6 +35,13 @@ elseif(CMAKE_SYSTEM_NAME MATCHES "^k?Fre
 
     # don't use the OpenGL ES implementation on FreeBSD
     set(OPENGL_ES 0)
+elseif(CMAKE_SYSTEM_NAME MATCHES "DragonFly|MidnightBSD")
+    set(SFML_OS_FREEBSD 1)
+    set(OPENGL_ES 0)
+elseif(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
+    set(SFML_OS_NETBSD 1)
+    # XXX we want to use OPENGL_ES for some NetBSD, but which?
+    set(OPENGL_ES 0)
 elseif(CMAKE_SYSTEM_NAME MATCHES "^OpenBSD$")
     set(SFML_OS_OPENBSD 1)
 
