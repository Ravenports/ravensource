--- src/nfpcapd/pcaproc.h.orig	2022-12-24 12:30:59 UTC
+++ src/nfpcapd/pcaproc.h
@@ -41,6 +41,7 @@
 #include <stdint.h>
 #endif
 
+#include <sys/types.h>
 #ifdef HAVE_NET_ETHERNET_H
 #include <net/ethernet.h>
 #endif
