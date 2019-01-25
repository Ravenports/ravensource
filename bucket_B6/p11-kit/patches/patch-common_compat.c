--- common/compat.c.orig	2018-11-14 13:25:33 UTC
+++ common/compat.c
@@ -38,7 +38,11 @@
  * This is needed to expose pthread_mutexattr_settype and PTHREAD_MUTEX_DEFAULT
  * on older pthreads implementations
  */
+#ifdef __sun__
+#define _XOPEN_SOURCE 600
+#else
 #define _XOPEN_SOURCE 700
+#endif
 
 #if defined(HAVE_ISSETUGID) && defined(__FreeBSD__)
 #define __BSD_VISIBLE 1
@@ -52,6 +56,7 @@
 #include <errno.h>
 #include <stdint.h>
 #include <stdlib.h>
+#include <stdint.h>
 #include <string.h>
 
 /*-
