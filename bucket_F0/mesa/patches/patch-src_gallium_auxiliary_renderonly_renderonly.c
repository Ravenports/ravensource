--- src/gallium/auxiliary/renderonly/renderonly.c.orig	2021-04-21 17:41:10 UTC
+++ src/gallium/auxiliary/renderonly/renderonly.c
@@ -37,6 +37,10 @@
 #include "util/u_inlines.h"
 #include "util/u_memory.h"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC	0
+#endif
+
 struct renderonly *
 renderonly_dup(const struct renderonly *ro)
 {
