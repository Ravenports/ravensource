--- lib/nghttp2-1.65.0/lib/nghttp2_net.h.orig	2025-07-09 19:11:19 UTC
+++ lib/nghttp2-1.65.0/lib/nghttp2_net.h
@@ -29,9 +29,7 @@
 #  include <config.h>
 #endif /* HAVE_CONFIG_H */
 
-#ifdef HAVE_ARPA_INET_H
 #  include <arpa/inet.h>
-#endif /* HAVE_ARPA_INET_H */
 
 #ifdef HAVE_NETINET_IN_H
 #  include <netinet/in.h>
