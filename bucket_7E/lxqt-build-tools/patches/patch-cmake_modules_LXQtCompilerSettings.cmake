--- cmake/modules/LXQtCompilerSettings.cmake.orig	2025-11-05 11:01:38 UTC
+++ cmake/modules/LXQtCompilerSettings.cmake
@@ -160,6 +160,9 @@ if (CMAKE_COMPILER_IS_GNUCXX OR LXQT_COM
         set(NO_UNDEFINED_FLAGS "-Wl,-undefined,error")
         # -Bsymbolic* make sense for ELF only
         set(SYMBOLIC_FLAGS "")
+    elseif (${CMAKE_SYSTEM_NAME} STREQUAL "SunOS")
+        set(NO_UNDEFINED_FLAGS "-Wl,-z,defs")
+        set(SYMBOLIC_FLAGS "")
     else()
         set(NO_UNDEFINED_FLAGS "-Wl,--no-undefined")
         # -Bsymbolic-functions: replace dynamic symbols used internally in
