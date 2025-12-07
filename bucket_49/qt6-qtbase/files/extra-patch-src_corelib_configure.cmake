--- src/corelib/configure.cmake.orig	2025-11-12 10:17:57 UTC
+++ src/corelib/configure.cmake
@@ -228,8 +228,6 @@ std::filesystem::copy(
 # dladdr
 qt_config_compile_test(dladdr
     LABEL "dladdr"
-    LIBRARIES
-        dl
     CODE
 "#define _GNU_SOURCE 1
 #include <dlfcn.h>
