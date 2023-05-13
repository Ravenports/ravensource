--- storage/perfschema/pfs_global.cc.orig	2023-05-05 11:04:43 UTC
+++ storage/perfschema/pfs_global.cc
@@ -49,6 +49,9 @@
 #ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>
 #endif
+#ifdef __MidnightBSD__
+#include <malloc_np.h>
+#endif
 
 bool pfs_initialized= false;
 
