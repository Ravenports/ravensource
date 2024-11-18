--- src/flb_network.c.orig	2024-11-04 22:36:47 UTC
+++ src/flb_network.c
@@ -551,9 +551,6 @@ static int net_connect_async(int fd,
             }
 
             /* Connection is broken, not much to do here */
-#if ((defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 200112L) ||    \
-     (defined(_XOPEN_SOURCE) || _XOPEN_SOURCE - 0L >= 600L)) &&     \
-  (!defined(_GNU_SOURCE))
             ret = strerror_r(error, so_error_buf, sizeof(so_error_buf));
             if (ret == 0) {
                 str = so_error_buf;
@@ -562,9 +559,6 @@ static int net_connect_async(int fd,
                 flb_errno();
                 return -1;
             }
-#else
-            str = strerror_r(error, so_error_buf, sizeof(so_error_buf));
-#endif
             flb_error("[net] TCP connection failed: %s:%i (%s)",
                       u->tcp_host, u->tcp_port, str);
             return -1;
@@ -1871,7 +1865,7 @@ static int net_address_unix_socket_peer_
                                                 int output_buffer_size,
                                                 size_t *output_data_size)
 {
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__)
     unsigned int peer_credentials_size;
     struct ucred peer_credentials;
 #endif
@@ -1889,7 +1883,7 @@ static int net_address_unix_socket_peer_
         return -1;
     }
 
-#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD)
+#if !defined(FLB_SYSTEM_MACOS) && !defined(FLB_SYSTEM_FREEBSD) && !defined(__DragonFly__)
     peer_credentials_size = sizeof(struct ucred);
 
     result = getsockopt(fd,
