--- lib/plat/unix/unix-sockets.c.orig	2025-02-28 06:41:45 UTC
+++ lib/plat/unix/unix-sockets.c
@@ -105,6 +105,7 @@ lws_plat_set_socket_options(struct lws_v
 	socklen_t optlen = sizeof(optval);
 
 #if defined(__APPLE__) || \
+    defined(__DragonFly__) || \
     defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__) || \
     defined(__OpenBSD__) || \
@@ -122,6 +123,7 @@ lws_plat_set_socket_options(struct lws_v
 			return 1;
 
 #if defined(__APPLE__) || \
+    defined(__DragonFly__) || \
     defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__) || \
     defined(__CYGWIN__) || defined(__OpenBSD__) || defined (__sun) || \
@@ -175,6 +177,7 @@ lws_plat_set_socket_options(struct lws_v
 	if (!unix_skt && setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (const void *)&optval, optlen) < 0)
 		return 1;
 #elif !defined(__APPLE__) && \
+      !defined(__DragonFly__) && \
       !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) &&        \
       !defined(__NetBSD__) && \
       !defined(__OpenBSD__) && \
@@ -233,6 +236,7 @@ lws_plat_set_socket_options_ip(lws_sockf
 #endif
 
 #if !defined(__APPLE__) && \
+      !defined(__DragonFly__) && \
       !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) &&        \
       !defined(__NetBSD__) && \
       !defined(__OpenBSD__) && \
