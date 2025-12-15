--- src/nfpcapd/ip_frag.h.orig	2025-11-10 14:55:23 UTC
+++ src/nfpcapd/ip_frag.h
@@ -31,10 +31,10 @@
 #ifndef _IP_FRAG_H
 #define _IP_FRAG_H 1
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
-#include <sys/types.h>
 
 void *ProcessIP6Fragment(struct ip6_hdr *ip6, struct ip6_frag *ip6_frag, const void *eodata);
 
