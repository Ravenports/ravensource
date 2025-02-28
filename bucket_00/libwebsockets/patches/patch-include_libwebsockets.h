--- include/libwebsockets.h.orig	2023-11-20 06:27:02 UTC
+++ include/libwebsockets.h
@@ -142,7 +142,7 @@ typedef int suseconds_t;
 #include <sys/capability.h>
 #endif
 
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__QNX__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__QNX__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #include <sys/socket.h>
 #include <netinet/in.h>
 #endif
@@ -169,7 +169,7 @@ typedef int suseconds_t;
 #endif
 #endif
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/signal.h>
 #endif
 #if defined(__GNUC__)
