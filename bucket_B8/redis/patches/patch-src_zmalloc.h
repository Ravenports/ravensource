--- src/zmalloc.h.orig	2026-11-22 12:33:24 UTC
+++ src/zmalloc.h
@@ -61,7 +61,7 @@
      defined(USE_MALLOC_USABLE_SIZE))
 
 /* Includes for malloc_usable_size() */
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #include <malloc_np.h>
 #else
 #ifndef _GNU_SOURCE
