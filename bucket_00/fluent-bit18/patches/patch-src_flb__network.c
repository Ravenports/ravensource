--- src/flb_network.c.orig	2022-03-22 22:42:32 UTC
+++ src/flb_network.c
@@ -478,9 +478,15 @@ static int net_connect_async(int fd,
             }
 
             /* Connection is broken, not much to do here */
-            str = strerror_r(error, so_error_buf, sizeof(so_error_buf));
-            flb_error("[net] TCP connection failed: %s:%i (%s)",
+            ret = strerror_r(error, so_error_buf, sizeof(so_error_buf));
+            if (ret == 0) {
+               str = so_error_buf;
+               flb_error("[net] TCP connection failed: %s:%i (%s)",
                       u->tcp_host, u->tcp_port, str);
+            } else {
+               flb_error("[net] TCP connection failed: %s:%i",
+                      u->tcp_host, u->tcp_port);
+            }
             return -1;
         }
     }
