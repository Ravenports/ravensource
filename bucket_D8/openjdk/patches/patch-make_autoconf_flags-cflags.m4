--- make/autoconf/flags-cflags.m4.orig	2024-04-29 14:34:19 UTC
+++ make/autoconf/flags-cflags.m4
@@ -37,7 +37,7 @@ AC_DEFUN([FLAGS_SETUP_SHARED_LIBS],
   if test "x$TOOLCHAIN_TYPE" = xgcc; then
     # Default works for linux, might work on other platforms as well.
     SHARED_LIBRARY_FLAGS='-shared'
-    SET_EXECUTABLE_ORIGIN='-Wl,-rpath,\$$ORIGIN[$]1'
+    SET_EXECUTABLE_ORIGIN='-Wl,-z,origin -Wl,-rpath,\$$ORIGIN[$]1'
     SET_SHARED_LIBRARY_ORIGIN="-Wl,-z,origin $SET_EXECUTABLE_ORIGIN"
     SET_SHARED_LIBRARY_NAME='-Wl,-soname=[$]1'
     SET_SHARED_LIBRARY_MAPFILE='-Wl,-version-script=[$]1'
