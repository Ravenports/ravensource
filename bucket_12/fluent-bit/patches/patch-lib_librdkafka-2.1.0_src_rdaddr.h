--- lib/librdkafka-2.4.0/src/rdaddr.h.orig	2025-03-24 22:35:10 UTC
+++ lib/librdkafka-2.4.0/src/rdaddr.h
@@ -39,7 +39,7 @@
 #include <ws2ipdef.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(_AIX) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(_AIX) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/socket.h>
 #endif
 
