--- src/corelib/configure.cmake.orig	2025-05-28 10:22:57 UTC
+++ src/corelib/configure.cmake
@@ -168,8 +168,6 @@ std::filesystem::copy(
 # dladdr
 qt_config_compile_test(dladdr
     LABEL "dladdr"
-    LIBRARIES
-        dl
     CODE
 "#define _GNU_SOURCE 1
 #include <dlfcn.h>
