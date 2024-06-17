--- storage/perfschema/pfs_global.cc.orig	2024-05-08 18:05:56 UTC
+++ storage/perfschema/pfs_global.cc
@@ -49,6 +49,9 @@
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
 #endif
+#ifdef __MidnightBSD__
+#include <malloc_np.h>
+#endif
 
 bool pfs_initialized= false;
 
