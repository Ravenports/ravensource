--- lib/chunkio/deps/crc32/crc32.c.orig	2020-11-24 18:24:33 UTC
+++ lib/chunkio/deps/crc32/crc32.c
@@ -31,7 +31,7 @@
 #  define htole16(x) (x)
 #  define be16toh(x) ntohs(x)
 #  define le16toh(x) (x)
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #  include <sys/endian.h>
 #elif defined(__sun) || defined(sun)
 # include <sys/byteorder.h>
