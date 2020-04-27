--- router/src/harness/include/mysql/harness/tty.h.orig	2020-03-26 13:31:45 UTC
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
