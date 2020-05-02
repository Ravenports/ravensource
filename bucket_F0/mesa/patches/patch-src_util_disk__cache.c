--- src/util/disk_cache.c.orig	2020-05-02 12:12:14 UTC
+++ src/util/disk_cache.c
@@ -63,6 +63,10 @@ dirfd(DIR *dirp) {
 
 #include "disk_cache.h"
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC	0
+#endif
+
 /* Number of bits to mask off from a cache key to get an index. */
 #define CACHE_INDEX_KEY_BITS 16
 
