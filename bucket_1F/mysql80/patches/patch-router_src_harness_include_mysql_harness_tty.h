--- router/src/harness/include/mysql/harness/tty.h.orig	2019-12-09 19:53:17 UTC
+++ router/src/harness/include/mysql/harness/tty.h
@@ -37,6 +37,10 @@
 #include <unistd.h>
 #endif
 
+#ifndef TABDLY
+#define TABDLY	0
+#endif
+
 class HARNESS_EXPORT Tty {
  public:
   using fd_type = int;
