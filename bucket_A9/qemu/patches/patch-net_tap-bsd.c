--- net/tap-bsd.c.orig	2025-02-11 21:08:13 UTC
+++ net/tap-bsd.c
@@ -30,9 +30,16 @@
 
 #if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/ioctl.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_tap.h>
 #endif
+#if defined(__DragonFly)
+#include <sys/ioctl.h>
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/tap/if_tap.h>
+#endif
 
 #ifndef __FreeBSD__
 int tap_open(char *ifname, int ifname_size, int *vnet_hdr,
