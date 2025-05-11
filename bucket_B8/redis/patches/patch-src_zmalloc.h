--- src/zmalloc.h.orig	2025-05-02 11:15:06 UTC
+++ src/zmalloc.h
@@ -58,7 +58,7 @@
      defined(USE_MALLOC_USABLE_SIZE))
 
 /* Includes for malloc_usable_size() */
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #include <malloc_np.h>
 #else
 #ifndef _GNU_SOURCE
