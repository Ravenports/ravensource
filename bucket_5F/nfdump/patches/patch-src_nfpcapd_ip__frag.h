--- src/nfpcapd/ip_frag.h.orig	2026-04-28 10:09:20 UTC
+++ src/nfpcapd/ip_frag.h
@@ -31,10 +31,10 @@
 #ifndef _IP_FRAG_H
 #define _IP_FRAG_H 1
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
-#include <sys/types.h>
 
 void *ProcessIP6Fragment(const struct ip6_hdr *ip6, const struct ip6_frag *ip6_frag, const void *eodata, uint32_t *payloadLength, time_t when);
 
