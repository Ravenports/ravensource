--- src/flb_network.c.orig	2025-12-23 22:03:54 UTC
+++ src/flb_network.c
@@ -1968,7 +1968,7 @@ static int net_address_unix_socket_peer_
                                                 int output_buffer_size,
                                                 size_t *output_data_size)
 {
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__)
     unsigned int peer_credentials_size;
     struct ucred peer_credentials;
 #endif
@@ -1986,7 +1986,7 @@ static int net_address_unix_socket_peer_
         return -1;
     }
 
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__)
     peer_credentials_size = sizeof(struct ucred);
 
     result = getsockopt(fd,
@@ -2344,4 +2344,4 @@ uint64_t flb_net_htonll(uint64_t value)
 #else
     return value;
 #endif
-}
\ No newline at end of file
+}
