--- storage/rocksdb/rdb_buff.h.orig	2023-08-17 15:25:34 UTC
+++ storage/rocksdb/rdb_buff.h
@@ -40,6 +40,8 @@
 #define be16toh(x) OSSwapBigToHostInt16(x)
 #endif
 
+#include "port/port_posix.h"
+
 /* MySQL header files */
 #include "./my_global.h"
 
