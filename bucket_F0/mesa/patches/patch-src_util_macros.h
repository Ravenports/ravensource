--- src/util/macros.h.orig	2023-03-08 18:37:09 UTC
+++ src/util/macros.h
@@ -451,7 +451,7 @@ typedef int lock_cap_t;
 #endif
 
 /* TODO: this could be different on non-x86 architectures. */
-#define CACHE_LINE_SIZE 64
+#define MESA_CACHE_LINE_SIZE 64
 
 #define DO_PRAGMA(X) _Pragma (#X)
 
