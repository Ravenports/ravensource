--- src/flb_network.c.orig	2026-08-15 03:52:07 UTC
+++ src/flb_network.c
@@ -2031,7 +2031,7 @@ static int net_address_unix_socket_peer_
                                                 int output_buffer_size,
                                                 size_t *output_data_size)
 {
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__sun__)
     unsigned int peer_credentials_size;
     struct ucred peer_credentials;
 #endif
@@ -2049,7 +2049,7 @@ static int net_address_unix_socket_peer_
         return -1;
     }
 
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__sun__)
     peer_credentials_size = sizeof(struct ucred);
 
     result = getsockopt(fd,
