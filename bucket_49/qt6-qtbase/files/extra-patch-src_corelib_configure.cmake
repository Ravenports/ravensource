--- src/corelib/configure.cmake.orig	2024-11-14 11:02:40 UTC
+++ src/corelib/configure.cmake
@@ -180,8 +180,6 @@ std::filesystem::copy(
 # dladdr
 qt_config_compile_test(dladdr
     LABEL "dladdr"
-    LIBRARIES
-        dl
     CODE
 "#define _GNU_SOURCE 1
 #include <dlfcn.h>
