--- storage/perfschema/pfs_global.cc.orig	2025-01-28 18:36:06 UTC
+++ storage/perfschema/pfs_global.cc
@@ -49,6 +49,9 @@
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
 #endif
+#ifdef __MidnightBSD__
+#include <malloc_np.h>
+#endif
 
 bool pfs_initialized= false;
 
