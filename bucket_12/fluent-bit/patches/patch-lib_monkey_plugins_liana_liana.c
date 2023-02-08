--- lib/monkey/plugins/liana/liana.c.orig	2023-02-01 17:09:22 UTC
+++ lib/monkey/plugins/liana/liana.c
@@ -109,7 +109,7 @@ int mk_liana_send_file(int socket_fd, in
         return len;
     }
     return ret;
-#elif defined (__FreeBSD__)
+#elif defined (__FreeBSD__) || defined(__DragonFly__)
     off_t offset = *file_offset;
     off_t len = (off_t) file_count;
 
