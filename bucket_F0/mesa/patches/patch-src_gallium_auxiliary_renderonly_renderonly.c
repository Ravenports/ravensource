--- src/gallium/auxiliary/renderonly/renderonly.c.orig	2023-02-08 21:05:36 UTC
+++ src/gallium/auxiliary/renderonly/renderonly.c
@@ -37,6 +37,10 @@
 #include "util/u_inlines.h"
 #include "util/u_memory.h"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 void
 renderonly_scanout_destroy(struct renderonly_scanout *scanout,
 			   struct renderonly *ro)
