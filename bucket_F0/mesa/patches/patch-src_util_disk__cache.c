--- src/util/disk_cache.c.orig	2020-04-22 21:36:59 UTC
+++ src/util/disk_cache.c
@@ -56,6 +56,10 @@
 
 #include "disk_cache.h"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC	0
+#endif
+
 /* Number of bits to mask off from a cache key to get an index. */
 #define CACHE_INDEX_KEY_BITS 16
 
