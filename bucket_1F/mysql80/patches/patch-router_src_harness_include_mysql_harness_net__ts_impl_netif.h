--- router/src/harness/include/mysql/harness/net_ts/impl/netif.h.orig	2021-07-01 07:53:49 UTC
+++ router/src/harness/include/mysql/harness/net_ts/impl/netif.h
@@ -31,6 +31,8 @@
 #include <string>
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || \
+    defined(__DragonFly__) || \
+    defined(__NetBSD__) || \
     defined(__sun__)
 #define HAVE_IFADDRS_H
 #endif
