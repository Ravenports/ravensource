--- src/udprelay.c.orig	2025-01-20 03:11:47 UTC
+++ src/udprelay.c
@@ -74,6 +74,11 @@
 #define EWOULDBLOCK EAGAIN
 #endif
 
+#if !defined(__linux__)
+#define SOL_IP   IPPROTO_IP
+#define SOL_IPV6 IPPROTO_IPV6
+#endif
+
 static void server_recv_cb(EV_P_ ev_io *w, int revents);
 static void remote_recv_cb(EV_P_ ev_io *w, int revents);
 static void remote_timeout_cb(EV_P_ ev_timer *watcher, int revents);
