--- src/egl/main/eglglobals.c.orig	2025-04-30 17:18:00 UTC
+++ src/egl/main/eglglobals.c
@@ -40,6 +40,10 @@
 #include "util/macros.h"
 #include "util/os_misc.h"
 
+#ifdef __DragonFly__
+#undef HAVE_MINCORE
+#endif
+
 #ifdef HAVE_MINCORE
 #include <unistd.h>
 #include <sys/mman.h>
