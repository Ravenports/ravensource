--- plugins/in_collectd/netprot.c.orig	2026-10-21 03:51:46 UTC
+++ plugins/in_collectd/netprot.c
@@ -35,6 +35,16 @@
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
 /* Packet fields may start at any byte offset. */
 static uint16_t be16read(const void *ptr)
 {
