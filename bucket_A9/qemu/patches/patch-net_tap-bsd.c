--- net/tap-bsd.c.orig	2018-08-02 21:48:53 UTC
+++ net/tap-bsd.c
@@ -31,9 +31,16 @@
 
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
