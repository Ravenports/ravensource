--- src/corelib/configure.cmake.orig	2026-06-04 16:29:11 UTC
+++ src/corelib/configure.cmake
@@ -243,8 +243,6 @@ std::filesystem::copy(
 # dladdr
 qt_config_compile_test(dladdr
     LABEL "dladdr"
-    LIBRARIES
-        dl
     CODE
 "#define _GNU_SOURCE 1
 #include <dlfcn.h>
