--- src/xshmfenceint.h.orig	2018-02-26 17:26:59 UTC
+++ src/xshmfenceint.h
@@ -23,6 +23,7 @@
 #ifndef _XSHMFENCEINT_H_
 #define _XSHMFENCEINT_H_
 
+#include <fcntl.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/mman.h>
@@ -32,6 +33,10 @@
 #include "xshmfence_futex.h"
 #endif
 
+#if HAVE_SEMAPHORE
+#include "xshmfence_semaphore.h"
+#endif
+
 #if HAVE_PTHREAD
 #include "xshmfence_pthread.h"
 #endif
