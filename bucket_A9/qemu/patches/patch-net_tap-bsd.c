--- net/tap-bsd.c.orig	2019-11-14 18:06:20 UTC
+++ net/tap-bsd.c
@@ -32,9 +32,16 @@
 
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
 
 #if defined(__OpenBSD__)
 #include <sys/param.h>
