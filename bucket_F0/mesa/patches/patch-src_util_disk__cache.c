--- src/util/disk_cache.c.orig	2020-06-10 18:03:01 UTC
+++ src/util/disk_cache.c
@@ -55,6 +55,10 @@
 
 #include "disk_cache.h"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC	0
+#endif
+
 /* Number of bits to mask off from a cache key to get an index. */
 #define CACHE_INDEX_KEY_BITS 16
 
