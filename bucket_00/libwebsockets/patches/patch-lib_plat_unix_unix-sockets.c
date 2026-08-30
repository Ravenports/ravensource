--- lib/plat/unix/unix-sockets.c.orig	2026-07-26 14:15:43 UTC
+++ lib/plat/unix/unix-sockets.c
@@ -55,6 +55,14 @@
 
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
@@ -120,6 +128,7 @@ lws_plat_set_socket_options(struct lws_v
 	socklen_t optlen = sizeof(optval);
 
 #if defined(__APPLE__) || \
+    defined(__DragonFly__) || \
     defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__) || \
     defined(__OpenBSD__) || \
@@ -137,6 +146,7 @@ lws_plat_set_socket_options(struct lws_v
 			return 1;
 
 #if defined(__APPLE__) || \
+    defined(__DragonFly__) || \
     defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__) || \
     defined(__CYGWIN__) || defined(__OpenBSD__) || defined (__sun) || \
@@ -190,6 +200,7 @@ lws_plat_set_socket_options(struct lws_v
 	if (!unix_skt && setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (const void *)&optval, optlen) < 0)
 		return 1;
 #elif !defined(__APPLE__) && \
+      !defined(__DragonFly__) && \
       !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) &&        \
       !defined(__NetBSD__) && \
       !defined(__OpenBSD__) && \
@@ -252,6 +263,7 @@ lws_plat_set_socket_options_ip(lws_sockf
 #endif
 
 #if !defined(__APPLE__) && \
+      !defined(__DragonFly__) && \
       !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) &&        \
       !defined(__NetBSD__) && \
       !defined(__OpenBSD__) && \
