--- src/runtime/interrupt.c.orig	2020-03-28 20:58:29 UTC
+++ src/runtime/interrupt.c
@@ -69,6 +69,10 @@
 #include "genesis/cons.h"
 #include "genesis/vector.h"
 
+#ifndef SIGRTMIN
+#define SIGRTMIN 50
+#endif
+
 /*
  * This is a workaround for some slightly silly Linux/GNU Libc
  * behaviour: glibc defines sigset_t to support 1024 signals, which is
