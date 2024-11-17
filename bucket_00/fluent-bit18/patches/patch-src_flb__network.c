--- src/flb_network.c.orig	2022-03-22 22:42:32 UTC
+++ src/flb_network.c
@@ -478,7 +478,7 @@ static int net_connect_async(int fd,
             }
 
             /* Connection is broken, not much to do here */
-            str = strerror_r(error, so_error_buf, sizeof(so_error_buf));
+            str = (char *)strerror_r(error, so_error_buf, sizeof(so_error_buf));
             flb_error("[net] TCP connection failed: %s:%i (%s)",
                       u->tcp_host, u->tcp_port, str);
             return -1;
