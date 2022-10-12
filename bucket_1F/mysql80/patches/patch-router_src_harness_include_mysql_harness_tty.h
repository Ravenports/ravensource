--- router/src/harness/include/mysql/harness/tty.h.orig	2022-09-13 16:15:16 UTC
+++ router/src/harness/include/mysql/harness/tty.h
@@ -38,6 +38,10 @@
 #include <unistd.h>
 #endif
 
+#ifndef TABDLY
+#define TABDLY	0
+#endif
+
 class HARNESS_EXPORT Tty {
  public:
   using fd_type = int;
