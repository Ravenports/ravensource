--- src/vde_plug2tap.c.orig	2011-11-23 16:41:18 UTC
+++ src/vde_plug2tap.c
@@ -37,7 +37,11 @@
 #ifdef VDE_FREEBSD
 #include <sys/socket.h>
 #include <net/if.h>
+# ifdef __DragonFly__
+#include <net/tun/if_tun.h>
+# else
 #include <net/if_tun.h>
+# endif
 #endif
 
 #if defined(VDE_DARWIN) || defined(VDE_FREEBSD)
