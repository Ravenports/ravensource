--- lib/monkey/plugins/liana/liana.c.orig	2025-04-23 22:41:14 UTC
+++ lib/monkey/plugins/liana/liana.c
@@ -122,7 +122,7 @@ int mk_liana_send_file(struct mk_plugin
         return len;
     }
     return ret;
-#elif defined (__FreeBSD__)
+#elif defined (__FreeBSD__) || defined(__DragonFly__)
     off_t offset = *file_offset;
     off_t len = (off_t) file_count;
 
