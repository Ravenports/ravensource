--- src/zmalloc.h.orig	2021-04-20 05:03:58 UTC
+++ src/zmalloc.h
@@ -73,7 +73,7 @@
 #define ZMALLOC_LIB "libc"
 
 #if !defined(NO_MALLOC_USABLE_SIZE) && \
-    (defined(__GLIBC__) || defined(__FreeBSD__) || \
+    (defined(__GLIBC__) || \
      defined(USE_MALLOC_USABLE_SIZE))
 
 /* Includes for malloc_usable_size() */
