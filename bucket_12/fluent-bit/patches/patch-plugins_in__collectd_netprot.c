--- plugins/in_collectd/netprot.c.orig	2026-02-19 03:26:01 UTC
+++ plugins/in_collectd/netprot.c
@@ -34,6 +34,16 @@
 #include "netprot.h"
 #include "typesdb.h"
 
+#if defined __sun__
+#include <sys/byteorder.h>
+#define be16toh(x) BE_16(x)
+#define be32toh(x) BE_32(x)
+#define be64toh(x) BE_64(x)
+#define le16toh(x) LE_16(x)
+#define le32toh(x) LE_32(x)
+#define le64toh(x) LE_64(x)
+#endif
+
 #define be16read(x) (be16toh(*(uint16_t *) (x)))
 #define be32read(x) (be32toh(*(uint32_t *) (x)))
 #define be64read(x) (be64toh(*(uint64_t *) (x)))
