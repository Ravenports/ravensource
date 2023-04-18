--- router/src/harness/include/mysql/harness/tty.h.orig	2023-03-16 17:22:37 UTC
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
