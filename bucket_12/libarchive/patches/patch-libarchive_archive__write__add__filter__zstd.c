--- libarchive/archive_write_add_filter_zstd.c.orig	2025-11-17 22:04:25 UTC
+++ libarchive/archive_write_add_filter_zstd.c
@@ -84,7 +84,7 @@ struct private_data {
 /* If we don't have the library use default range values (zstdcli.c v1.4.0) */
 #define CLEVEL_MIN -99
 #define CLEVEL_STD_MIN 0 /* prior to 1.3.4 and more recent without using --fast */
-#define CLEVEL_DEFAULT 3
+#define CLEVEL_DEFAULT 7
 #define CLEVEL_STD_MAX 19 /* without using --ultra */
 #define CLEVEL_MAX 22
 
