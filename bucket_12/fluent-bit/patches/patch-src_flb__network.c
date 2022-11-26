--- src/flb_network.c.orig	2022-11-22 14:33:00 UTC
+++ src/flb_network.c
@@ -1801,7 +1801,7 @@ static int net_address_unix_socket_peer_
                                                 int output_buffer_size,
                                                 size_t *output_data_size)
 {
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__)
     unsigned int peer_credentials_size;
     struct ucred peer_credentials;
 #endif
@@ -1819,7 +1819,7 @@ static int net_address_unix_socket_peer_
         return -1;
     }
 
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__)
     peer_credentials_size = sizeof(struct ucred);
 
     result = getsockopt(fd,
