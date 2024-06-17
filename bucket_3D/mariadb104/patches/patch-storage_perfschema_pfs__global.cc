--- storage/perfschema/pfs_global.cc.orig	2024-05-06 15:18:48 UTC
+++ storage/perfschema/pfs_global.cc
@@ -46,6 +46,9 @@
 #else
   #include <arpa/inet.h>
 #endif
+#ifdef __MidnightBSD__
+#include <malloc_np.h>
+#endif
 
 bool pfs_initialized= false;
 size_t pfs_allocated_memory= 0;
