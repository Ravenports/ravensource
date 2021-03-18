--- cmake_admin/DefaultDirs.cmake.orig	2021-03-15 19:12:51 UTC
+++ cmake_admin/DefaultDirs.cmake
@@ -53,7 +53,7 @@ set (INFO_INSTALL_DIR "share/info" CACHE
 mark_as_advanced (INFO_INSTALL_DIR) 
 
 # MAN_INSTALL_DIR - the man pages install dir
-if ( CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly")
+if ( CMAKE_SYSTEM_NAME MATCHES "nothing")
   set (MAN_INSTALL_DIR "man/man1" CACHE STRING "The man pages install dir")
 else()
   set (MAN_INSTALL_DIR "share/man/man1" CACHE STRING "The man pages install dir")
