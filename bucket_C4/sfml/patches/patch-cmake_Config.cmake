add NetBSD support

--- cmake/Config.cmake.orig	2024-12-20 23:55:10 UTC
+++ cmake/Config.cmake
@@ -35,6 +35,10 @@ elseif(CMAKE_SYSTEM_NAME MATCHES "^k?Fre
 
     # don't use the OpenGL ES implementation on FreeBSD
     set(OPENGL_ES 0)
+elseif(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
+    set(SFML_OS_NETBSD 1)
+    # XXX we want to use OPENGL_ES for some NetBSD, but which?
+    set(OPENGL_ES 0)
 elseif(CMAKE_SYSTEM_NAME MATCHES "^OpenBSD$")
     set(SFML_OS_OPENBSD 1)
 
@@ -70,6 +74,10 @@ else()
     return()
 endif()
 
+if(SFML_OS_NETBSD)
+    set(SFML_PKGCONFIG_DIR "/lib/pkgconfig")
+endif()
+
 # detect the compiler
 # Note: The detection is order is important because:
 # - Visual Studio can both use MSVC and Clang
