--- src/flb_network.c.orig	2026-04-14 17:27:00 UTC
+++ src/flb_network.c
@@ -2016,7 +2016,7 @@ static int net_address_unix_socket_peer_
                                                 int output_buffer_size,
                                                 size_t *output_data_size)
 {
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__sun__)
     unsigned int peer_credentials_size;
     struct ucred peer_credentials;
 #endif
@@ -2034,7 +2034,7 @@ static int net_address_unix_socket_peer_
         return -1;
     }
 
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__sun__)
     peer_credentials_size = sizeof(struct ucred);
 
     result = getsockopt(fd,
