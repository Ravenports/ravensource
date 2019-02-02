--- router/src/harness/src/socket_operations.cc.orig	2019-01-25 22:33:03 UTC
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
