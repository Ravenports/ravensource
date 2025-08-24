--- router/src/harness/include/mysql/harness/tty.h.orig	2025-07-10 14:20:26 UTC
+++ router/src/harness/include/mysql/harness/tty.h
@@ -39,6 +39,10 @@
 #include <unistd.h>
 #endif
 
+#ifndef TABDLY
+#define TABDLY	0
+#endif
+
 class HARNESS_EXPORT Tty {
  public:
   using fd_type = int;
