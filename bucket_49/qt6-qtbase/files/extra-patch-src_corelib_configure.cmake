--- src/corelib/configure.cmake.orig	2025-08-11 04:54:51 UTC
+++ src/corelib/configure.cmake
@@ -221,8 +221,6 @@ std::filesystem::copy(
 # dladdr
 qt_config_compile_test(dladdr
     LABEL "dladdr"
-    LIBRARIES
-        dl
     CODE
 "#define _GNU_SOURCE 1
 #include <dlfcn.h>
