--- src/pipewire/impl-node.c.orig	2025-04-14 09:46:02 UTC
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
