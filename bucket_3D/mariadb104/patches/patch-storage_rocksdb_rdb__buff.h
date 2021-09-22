--- storage/rocksdb/rdb_buff.h.orig	2021-08-02 18:07:04 UTC
+++ storage/rocksdb/rdb_buff.h
@@ -40,6 +40,8 @@
 #define be16toh(x) OSSwapBigToHostInt16(x)
 #endif
 
+#include "port/port_posix.h"
+
 /* MySQL header files */
 #include "./my_global.h"
 
