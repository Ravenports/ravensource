--- src/zmalloc.h.orig	2023-07-10 11:39:42 UTC
+++ src/zmalloc.h
@@ -73,7 +73,7 @@
 #define ZMALLOC_LIB "libc"
 
 #if !defined(NO_MALLOC_USABLE_SIZE) && \
-    (defined(__GLIBC__) || defined(__FreeBSD__) || \
+    (defined(__GLIBC__) || \
      defined(USE_MALLOC_USABLE_SIZE))
 
 /* Includes for malloc_usable_size() */
