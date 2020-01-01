--- libarchive/archive_write_add_filter_zstd.c.orig	2019-12-30 01:39:54 UTC
+++ libarchive/archive_write_add_filter_zstd.c
@@ -96,7 +96,7 @@ archive_write_add_filter_zstd(struct arc
 	f->free = &archive_compressor_zstd_free;
 	f->code = ARCHIVE_FILTER_ZSTD;
 	f->name = "zstd";
-	data->compression_level = 3; /* Default level used by the zstd CLI */
+	data->compression_level = 7;
 #if HAVE_ZSTD_H && HAVE_LIBZSTD
 	data->cstream = ZSTD_createCStream();
 	if (data->cstream == NULL) {
