We changed the default from level 3 to level 7, so reverse the assert
accordingly.

--- libarchive/test/test_write_filter_zstd.c.orig	2019-06-12 21:05:16 UTC
+++ libarchive/test/test_write_filter_zstd.c
@@ -142,7 +142,7 @@ DEFINE_TEST(test_write_filter_zstd)
 
 	failure("compression-level=6 wrote %d bytes, default wrote %d bytes",
 	    (int)used2, (int)used1);
-	assert(used2 < used1);
+	assert(used2 > used1);
 
 	assert((a = archive_read_new()) != NULL);
 	assertEqualIntA(a, ARCHIVE_OK, archive_read_support_format_all(a));
