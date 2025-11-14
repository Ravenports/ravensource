--- src/flb_network.c.orig	2025-10-08 13:42:21 UTC
+++ src/flb_network.c
@@ -1967,7 +1967,7 @@ static int net_address_unix_socket_peer_
                                                 int output_buffer_size,
                                                 size_t *output_data_size)
 {
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__)
     unsigned int peer_credentials_size;
     struct ucred peer_credentials;
 #endif
@@ -1985,7 +1985,7 @@ static int net_address_unix_socket_peer_
         return -1;
     }
 
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__)
     peer_credentials_size = sizeof(struct ucred);
 
     result = getsockopt(fd,
@@ -2343,4 +2343,4 @@ uint64_t flb_net_htonll(uint64_t value)
 #else
     return value;
 #endif
-}
\ No newline at end of file
+}
