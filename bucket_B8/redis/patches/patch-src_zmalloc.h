--- src/zmalloc.h.orig	2022-09-21 19:42:01 UTC
+++ src/zmalloc.h
@@ -73,7 +73,7 @@
 #define ZMALLOC_LIB "libc"
 
 #if !defined(NO_MALLOC_USABLE_SIZE) && \
-    (defined(__GLIBC__) || defined(__FreeBSD__) || \
+    (defined(__GLIBC__) || \
      defined(USE_MALLOC_USABLE_SIZE))
 
 /* Includes for malloc_usable_size() */
