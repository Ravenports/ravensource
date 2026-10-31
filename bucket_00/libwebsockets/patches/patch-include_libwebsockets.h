--- include/libwebsockets.h.orig	2026-10-30 11:39:27 UTC
+++ include/libwebsockets.h
@@ -249,7 +249,7 @@ typedef char lws_mutex_t;
 #include <sys/capability.h>
 #endif
 
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__QNX__) || defined(__OpenBSD__) || defined(__NuttX__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__QNX__) || defined(__OpenBSD__) || defined(__NuttX__) || defined(__DragonFly__)
 #include <sys/socket.h>
 #include <netinet/in.h>
 #endif
@@ -282,7 +282,7 @@ typedef char lws_mutex_t;
 #endif
 #endif
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/signal.h>
 #endif
 #if defined(__GNUC__)
