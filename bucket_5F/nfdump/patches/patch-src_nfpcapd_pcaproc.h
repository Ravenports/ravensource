--- src/nfpcapd/pcaproc.h.orig	2026-04-28 10:09:20 UTC
+++ src/nfpcapd/pcaproc.h
@@ -38,6 +38,7 @@
 #include <stdint.h>
 #include <sys/types.h>
 
+#include <sys/types.h>
 #ifdef HAVE_NET_ETHERNET_H
 #include <net/ethernet.h>
 #endif
