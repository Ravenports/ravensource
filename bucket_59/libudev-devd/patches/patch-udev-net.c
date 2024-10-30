--- udev-net.c.orig	2024-09-20 07:46:46 UTC
+++ udev-net.c
@@ -27,7 +27,11 @@
 
 #include <sys/socket.h>
 #include <sys/stat.h>
+#if defined(__NetBSD__)
+#include <net/if_ether.h>
+#else
 #include <net/ethernet.h>
+#endif
 #include <net/if.h>
 #ifdef HAVE_NET_IF_DL_H
 #include <net/if_dl.h>
@@ -40,6 +44,10 @@
 #define	AF_LINK	AF_PACKET
 #endif
 
+#ifndef LLINDEX
+#define LLINDEX(s) ((s)->sdl_index)
+#endif
+
 int
 udev_net_enumerate(struct udev_enumerate *ue)
 {
