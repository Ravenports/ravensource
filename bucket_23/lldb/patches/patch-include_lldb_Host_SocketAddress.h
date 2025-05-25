--- include/lldb/Host/SocketAddress.h.orig	2025-05-13 22:18:22 UTC
+++ include/lldb/Host/SocketAddress.h
@@ -22,7 +22,7 @@ typedef ADDRESS_FAMILY sa_family_t;
 #include <sys/socket.h>
 #endif
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/types.h>
 #endif
 
