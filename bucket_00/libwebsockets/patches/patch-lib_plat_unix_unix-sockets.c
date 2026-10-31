--- lib/plat/unix/unix-sockets.c.orig	2026-10-30 11:39:27 UTC
+++ lib/plat/unix/unix-sockets.c
@@ -80,6 +80,14 @@ lws_plat_tx_choked(struct lws *wsi)
 	return 0;
 }
 
+#if defined(__sun) && !defined(IPV6_ADDR_PREFERENCES)
+# ifdef IPV6_SRC_PREFERENCES
+#define IPV6_ADDR_PREFERENCES IPV6_SRC_PREFERENCES
+# else
+#define IPV6_ADDR_PREFERENCES 0
+# endif
+#endif
+
 int
 lws_plat_set_nonblocking(lws_sockfd_type fd)
 {
@@ -122,6 +130,7 @@ lws_plat_set_socket_options(struct lws_v
 			return 1;
 
 #if defined(__APPLE__) || \
+    defined(__DragonFly__) || \
     defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__) || \
     defined(__CYGWIN__) || defined(__OpenBSD__) || defined (__sun) || \
@@ -277,6 +286,7 @@ lws_plat_set_socket_options_ip(lws_sockf
 #endif
 
 #if !defined(__APPLE__) && \
+      !defined(__DragonFly__) && \
       !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) &&        \
       !defined(__NetBSD__) && \
       !defined(__OpenBSD__) && \
