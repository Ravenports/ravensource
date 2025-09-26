--- src/pipewire/impl-node.c.orig	2025-07-23 15:42:58 UTC
+++ src/pipewire/impl-node.c
@@ -8,7 +8,9 @@
 #include <unistd.h>
 #include <errno.h>
 #include <time.h>
+#if !defined(__DragonFly__) && !defined(__FreeBSD__)
 #include <malloc.h>
+#endif
 #include <limits.h>
 
 #include "config.h"
