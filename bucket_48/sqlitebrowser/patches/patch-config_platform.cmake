--- config/platform.cmake.orig	2026-11-07 00:41:11 UTC
+++ config/platform.cmake
@@ -10,12 +10,11 @@ if(NOT WIN32)
     list(APPEND PLATFORM_LIBS pthread)
 endif()
 
-if(UNIX AND NOT ${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD")
+if(LINUX)
     list(APPEND PLATFORM_LIBS dl)
 endif()
 
 # add extra library path for MacOS and FreeBSD
-set(EXTRAPATH APPLE OR ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
 if(EXTRAPATH)
     list(PREPEND CMAKE_PREFIX_PATH /usr/local/opt/sqlite/lib)
     list(PREPEND CMAKE_PREFIX_PATH /usr/local/opt/sqlitefts5/lib)
