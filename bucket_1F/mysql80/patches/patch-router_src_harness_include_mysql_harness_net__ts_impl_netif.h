--- router/src/harness/include/mysql/harness/net_ts/impl/netif.h.orig	2022-12-16 15:34:44 UTC
+++ router/src/harness/include/mysql/harness/net_ts/impl/netif.h
@@ -32,6 +32,8 @@
 #include <string_view>
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || \
+    defined(__DragonFly__) || \
+    defined(__NetBSD__) || \
     defined(__sun__)
 #define HAVE_IFADDRS_H
 #endif
