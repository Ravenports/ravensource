--- storage/rocksdb/rdb_buff.h.orig	2025-07-28 19:35:06 UTC
+++ storage/rocksdb/rdb_buff.h
@@ -40,6 +40,8 @@
 #define be16toh(x) OSSwapBigToHostInt16(x)
 #endif
 
+#include "port/port_posix.h"
+
 /* MySQL header files */
 #include "./my_global.h"
 
