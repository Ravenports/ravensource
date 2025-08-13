--- src/flb_network.c.orig	2025-07-09 19:11:19 UTC
+++ src/flb_network.c
@@ -637,9 +637,7 @@ static int net_connect_async(int fd,
             }
 
             /* Connection is broken, not much to do here */
-#if ((defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 200112L) ||    \
-     (defined(_XOPEN_SOURCE) || _XOPEN_SOURCE - 0L >= 600L)) &&     \
-  (!defined(_GNU_SOURCE))
+#if !defined(__linux__)
             ret = strerror_r(error, so_error_buf, sizeof(so_error_buf));
             if (ret == 0) {
                 str = so_error_buf;
@@ -1967,7 +1965,7 @@ static int net_address_unix_socket_peer_
                                                 int output_buffer_size,
                                                 size_t *output_data_size)
 {
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__)
     unsigned int peer_credentials_size;
     struct ucred peer_credentials;
 #endif
@@ -1985,7 +1983,7 @@ static int net_address_unix_socket_peer_
         return -1;
     }
 
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__) && !defined(__NetBSD__)
     peer_credentials_size = sizeof(struct ucred);
 
     result = getsockopt(fd,
