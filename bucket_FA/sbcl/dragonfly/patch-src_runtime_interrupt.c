--- src/runtime/interrupt.c.orig	2019-03-31 13:43:24 UTC
+++ src/runtime/interrupt.c
@@ -68,6 +68,10 @@
 #include "genesis/simple-fun.h"
 #include "genesis/cons.h"
 
+#ifndef SIGRTMIN
+#define SIGRTMIN 50
+#endif
+
 /*
  * This is a workaround for some slightly silly Linux/GNU Libc
  * behaviour: glibc defines sigset_t to support 1024 signals, which is
