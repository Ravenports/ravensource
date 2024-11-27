--- src/nfpcapd/pcaproc.h.orig	2024-10-23 17:57:56 UTC
+++ src/nfpcapd/pcaproc.h
@@ -40,6 +40,7 @@
 #endif
 #include <stdint.h>
 
+#include <sys/types.h>
 #ifdef HAVE_NET_ETHERNET_H
 #include <net/ethernet.h>
 #endif
