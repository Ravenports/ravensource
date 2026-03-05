--- Modules/Compiler/GNU.cmake.orig	2026-01-27 16:03:47 UTC
+++ Modules/Compiler/GNU.cmake
@@ -99,7 +99,9 @@ macro(__compiler_gnu lang)
       list(APPEND __lto_flags -flto)
     endif()
 
-    if(NOT CMAKE_${lang}_COMPILER_VERSION VERSION_LESS 4.7 AND NOT APPLE)
+    if(NOT CMAKE_${lang}_COMPILER_VERSION VERSION_LESS 4.7
+	AND NOT APPLE
+	AND NOT CMAKE_SYSTEM_NAME MATCHES "SunOS")
       # '-ffat-lto-objects' introduced since GCC 4.7:
       # * https://gcc.gnu.org/onlinedocs/gcc-4.6.4/gcc/Option-Summary.html (no)
       # * https://gcc.gnu.org/onlinedocs/gcc-4.7.4/gcc/Option-Summary.html (yes)
