--- router/src/harness/include/mysql/harness/net_ts/impl/netif.h.orig	2021-04-23 15:06:40 UTC
+++ router/src/harness/include/mysql/harness/net_ts/impl/netif.h
@@ -31,6 +31,7 @@
 #include <string>
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || \
+    defined(__DragonFly__) || \
     defined(__sun__)
 #define HAVE_IFADDRS_H
 #endif
