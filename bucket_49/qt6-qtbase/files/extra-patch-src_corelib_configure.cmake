--- src/corelib/configure.cmake.orig	2026-05-07 07:50:01 UTC
+++ src/corelib/configure.cmake
@@ -235,8 +235,6 @@ std::filesystem::copy(
 # dladdr
 qt_config_compile_test(dladdr
     LABEL "dladdr"
-    LIBRARIES
-        dl
     CODE
 "#define _GNU_SOURCE 1
 #include <dlfcn.h>
