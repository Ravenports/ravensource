--- src/util/disk_cache.c.orig	2020-01-17 21:41:44 UTC
+++ src/util/disk_cache.c
@@ -59,6 +59,10 @@ dirfd(DIR *dirp) {
 
 #include "disk_cache.h"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC	0
+#endif
+
 /* Number of bits to mask off from a cache key to get an index. */
 #define CACHE_INDEX_KEY_BITS 16
 
