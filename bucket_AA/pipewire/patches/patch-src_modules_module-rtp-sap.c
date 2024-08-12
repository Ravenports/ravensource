--- src/modules/module-rtp-sap.c.orig	2024-02-02 13:09:07 UTC
+++ src/modules/module-rtp-sap.c
@@ -24,7 +24,7 @@
 
 #include <module-rtp/sap.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #define ifr_ifindex ifr_index
 #endif
 
