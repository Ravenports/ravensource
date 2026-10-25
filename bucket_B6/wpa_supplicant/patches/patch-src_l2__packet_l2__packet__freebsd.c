--- src/l2_packet/l2_packet_freebsd.c.orig	2026-08-07 13:10:53 UTC
+++ src/l2_packet/l2_packet_freebsd.c
@@ -8,7 +8,11 @@
  */
 
 #include "includes.h"
-#if defined(__APPLE__) || defined(__GLIBC__)
+#if defined(__FreeBSD__) \
+ || defined(__DragonFly__) \
+ || defined(__NetBSD__) \
+ || defined(__APPLE__) \
+ || defined(__GLIBC__)
 #include <net/bpf.h>
 #endif /* __APPLE__ */
 #include <pcap.h>
@@ -20,7 +24,9 @@
 #include <sys/sysctl.h>
 #endif /* __sun__ */
 
+#if !defined(__NetBSD__)
 #include <net/ethernet.h>
+#endif
 #include <net/if.h>
 #include <net/if_dl.h>
 #include <net/route.h>
