--- lib/plat/unix/unix-sockets.c.orig	2025-12-03 06:15:09 UTC
+++ lib/plat/unix/unix-sockets.c
@@ -52,6 +52,14 @@
 
 #include <netinet/ip.h>
 
+#if defined(__sun) && !defined(IPV6_ADDR_PREFERENCES)
+# ifdef IPV6_SRC_PREFERENCES
+#define IPV6_ADDR_PREFERENCES IPV6_SRC_PREFERENCES
+# else
+#define IPV6_ADDR_PREFERENCES 0
+# endif
+#endif
+
 int
 lws_send_pipe_choked(struct lws *wsi)
 {
@@ -109,6 +117,7 @@ lws_plat_set_socket_options(struct lws_v
 	socklen_t optlen = sizeof(optval);
 
 #if defined(__APPLE__) || \
+    defined(__DragonFly__) || \
     defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__) || \
     defined(__OpenBSD__) || \
@@ -126,6 +135,7 @@ lws_plat_set_socket_options(struct lws_v
 			return 1;
 
 #if defined(__APPLE__) || \
+    defined(__DragonFly__) || \
     defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__) || \
     defined(__CYGWIN__) || defined(__OpenBSD__) || defined (__sun) || \
@@ -179,6 +189,7 @@ lws_plat_set_socket_options(struct lws_v
 	if (!unix_skt && setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (const void *)&optval, optlen) < 0)
 		return 1;
 #elif !defined(__APPLE__) && \
+      !defined(__DragonFly__) && \
       !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) &&        \
       !defined(__NetBSD__) && \
       !defined(__OpenBSD__) && \
@@ -239,6 +250,7 @@ lws_plat_set_socket_options_ip(lws_sockf
 #endif
 
 #if !defined(__APPLE__) && \
+      !defined(__DragonFly__) && \
       !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) &&        \
       !defined(__NetBSD__) && \
       !defined(__OpenBSD__) && \
