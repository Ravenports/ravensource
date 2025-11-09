--- src/nfpcapd/pcaproc.h.orig	2025-11-09 17:02:56 UTC
+++ src/nfpcapd/pcaproc.h
@@ -40,6 +40,7 @@
 #endif
 #include <stdint.h>
 
+#include <sys/types.h>
 #ifdef HAVE_NET_ETHERNET_H
 #include <net/ethernet.h>
 #endif
