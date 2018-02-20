--- sal/osl/unx/system.hxx.orig	2018-02-08 14:35:19 UTC
+++ sal/osl/unx/system.hxx
@@ -106,7 +106,9 @@
 #endif
 
 #ifdef FREEBSD
-#   define  ETIME ETIMEDOUT
+#   ifndef ETIME
+#       define ETIME ETIMEDOUT
+#   endif
 #   include <pthread.h>
 #   include <sys/sem.h>
 #   include <dlfcn.h>
