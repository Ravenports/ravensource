--- router/src/harness/src/socket_operations.cc.orig	2020-03-26 13:31:45 UTC
+++ router/src/harness/src/socket_operations.cc
@@ -42,6 +42,9 @@
 #include <ifaddrs.h>
 #include <net/if.h>
 #endif
+#ifdef __DragonFly__
+#include <netinet/in.h>
+#endif
 #else
 #include <windows.h>
 #include <winsock2.h>
