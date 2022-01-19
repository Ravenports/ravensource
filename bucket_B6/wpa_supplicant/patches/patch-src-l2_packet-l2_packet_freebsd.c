--- src/l2_packet/l2_packet_freebsd.c.orig	2022-01-16 20:51:29 UTC
+++ src/l2_packet/l2_packet_freebsd.c
@@ -8,7 +8,10 @@
  */
 
 #include "includes.h"
-#if defined(__APPLE__) || defined(__GLIBC__)
+#if defined(__FreeBSD__) \
+ || defined(__DragonFly__) \
+ || defined(__APPLE__) \
+ || defined(__GLIBC__)
 #include <net/bpf.h>
 #endif /* __APPLE__ */
 #include <pcap.h>
