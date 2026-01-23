--- router/src/harness/include/mysql/harness/net_ts/impl/netif.h.orig	2025-12-17 13:14:47 UTC
+++ router/src/harness/include/mysql/harness/net_ts/impl/netif.h
@@ -33,6 +33,8 @@
 #include <string_view>
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || \
+    defined(__DragonFly__) || \
+    defined(__NetBSD__) || \
     defined(__sun__)
 #define HAVE_IFADDRS_H
 #endif
