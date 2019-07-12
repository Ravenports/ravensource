--- libarchive/test/test_read_format_zip_traditional_encryption_data.c.orig	2019-06-12 21:05:16 UTC
+++ libarchive/test/test_read_format_zip_traditional_encryption_data.c
@@ -130,7 +130,7 @@ DEFINE_TEST(test_read_format_zip_traditi
 		assertEqualInt(ARCHIVE_FAILED,
 		    archive_read_data(a, buff, sizeof(buff)));
 		assertEqualString(archive_error_string(a),
-		    "Unsupported ZIP compression method (deflation)");
+		    "Unsupported ZIP compression method (8: deflation)");
 		assert(archive_errno(a) != 0);
 	}
 	
@@ -148,7 +148,7 @@ DEFINE_TEST(test_read_format_zip_traditi
 		assertEqualInt(ARCHIVE_FAILED,
 		    archive_read_data(a, buff, sizeof(buff)));
 		assertEqualString(archive_error_string(a),
-		    "Unsupported ZIP compression method (deflation)");
+		    "Unsupported ZIP compression method (8: deflation)");
 		assert(archive_errno(a) != 0);
 	}
 	
