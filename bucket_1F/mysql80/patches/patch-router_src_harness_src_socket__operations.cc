--- router/src/harness/src/socket_operations.cc.orig	2020-06-16 16:31:03 UTC
+++ router/src/harness/src/socket_operations.cc
@@ -32,6 +32,9 @@
 #include <ifaddrs.h>
 #include <net/if.h>
 #endif
+#ifdef __DragonFly__
+#include <netinet/in.h>
+#endif
 #else
 #include <windows.h>
 #include <winsock2.h>  // gethostname
