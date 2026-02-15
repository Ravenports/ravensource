--- source/spawn/ptsname_r.c.orig	2026-02-15 04:09:22 UTC
+++ source/spawn/ptsname_r.c
@@ -53,6 +53,7 @@ __ptsname_r (int fd, char *buf, size_t b
 
 #else
 
+#define _GNU_SOURCE
 #include <stdlib.h>
 
 int
