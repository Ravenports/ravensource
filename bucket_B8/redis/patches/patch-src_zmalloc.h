--- src/zmalloc.h.orig	2026-05-25 09:26:50 UTC
+++ src/zmalloc.h
@@ -61,7 +61,7 @@
      defined(USE_MALLOC_USABLE_SIZE))
 
 /* Includes for malloc_usable_size() */
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #include <malloc_np.h>
 #else
 #ifndef _GNU_SOURCE
