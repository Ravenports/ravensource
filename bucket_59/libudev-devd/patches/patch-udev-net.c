--- udev-net.c.orig	2024-09-20 07:46:46 UTC
+++ udev-net.c
@@ -40,6 +40,10 @@
 #define	AF_LINK	AF_PACKET
 #endif
 
+#ifndef LLINDEX
+#define LLINDEX(s) ((s)->sdl_index)
+#endif
+
 int
 udev_net_enumerate(struct udev_enumerate *ue)
 {
