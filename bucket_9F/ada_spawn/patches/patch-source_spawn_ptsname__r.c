--- source/spawn/ptsname_r.c.orig	2024-11-26 23:58:36 UTC
+++ source/spawn/ptsname_r.c
@@ -7,6 +7,9 @@
 #  define __NEEDS_PTSNAME_R__
 # endif
 #endif
+#if defined(__linux__)
+#define _GNU_SOURCE
+#endif
 
 #ifdef __NEEDS_PTSNAME_R__
 
