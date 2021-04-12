--- src/zmalloc.h.orig	2021-03-02 06:14:39 UTC
+++ src/zmalloc.h
@@ -72,7 +72,7 @@
 #ifndef ZMALLOC_LIB
 #define ZMALLOC_LIB "libc"
 #if !defined(NO_MALLOC_USABLE_SIZE) && \
-    (defined(__GLIBC__) || defined(__FreeBSD__) || \
+    (defined(__GLIBC__) || \
      defined(USE_MALLOC_USABLE_SIZE))
 #include <malloc.h>
 #define HAVE_MALLOC_SIZE 1
