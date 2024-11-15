--- src/corelib/configure.cmake.orig	2024-10-01 10:46:30 UTC
+++ src/corelib/configure.cmake
@@ -164,8 +164,6 @@ std::filesystem::copy(
 # dladdr
 qt_config_compile_test(dladdr
     LABEL "dladdr"
-    LIBRARIES
-        dl
     CODE
 "#define _GNU_SOURCE 1
 #include <dlfcn.h>
