--- toxcore/LAN_discovery.c.orig	2018-09-30 18:20:25.860667000 +0300
+++ toxcore/LAN_discovery.c	2018-09-30 18:21:52.362320000 +0300
@@ -119,7 +119,7 @@ static void fetch_broadcast_info(uint16_
     }
 }
 
-#elif defined(__linux__) || defined(__FreeBSD__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 
 #include <netinet/in.h>
 #include <sys/ioctl.h>
@@ -131,7 +131,7 @@ static void fetch_broadcast_info(uint16_
 #include <linux/netdevice.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <net/if.h>
 #endif
 
