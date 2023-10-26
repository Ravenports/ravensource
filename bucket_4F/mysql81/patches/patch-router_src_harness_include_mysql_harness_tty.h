--- router/src/harness/include/mysql/harness/tty.h.orig	2023-10-12 11:40:36 UTC
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
