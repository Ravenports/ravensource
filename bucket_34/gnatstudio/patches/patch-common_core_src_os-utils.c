--- common/core/src/os-utils.c.orig	2020-06-03 11:10:40 UTC
+++ common/core/src/os-utils.c
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #ifdef _WIN32
 #include <windows.h>
 #include <lmcons.h>
@@ -31,7 +32,7 @@
 #endif
 
 int
-__gps_subdirectories_count (name)
+__gps_subdirectories_count (char *name)
 {
   struct stat statbuf;
   int ret;
