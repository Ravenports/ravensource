--- lib/librdkafka-2.10.1/src/rdaddr.h.orig	2025-09-24 14:28:05 UTC
+++ lib/librdkafka-2.10.1/src/rdaddr.h
@@ -39,7 +39,7 @@
 #include <ws2ipdef.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(_AIX) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(_AIX) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/socket.h>
 #endif
 
