--- storage/perfschema/pfs_global.cc.orig	2026-05-23 15:01:06 UTC
+++ storage/perfschema/pfs_global.cc
@@ -49,6 +49,9 @@
 #ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>
 #endif
+#ifdef __MidnightBSD__
+#include <malloc_np.h>
+#endif
 
 bool pfs_initialized= false;
 
