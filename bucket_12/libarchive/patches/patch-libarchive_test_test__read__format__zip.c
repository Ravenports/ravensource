--- libarchive/test/test_read_format_zip.c.orig	2019-06-12 21:05:16 UTC
+++ libarchive/test/test_read_format_zip.c
@@ -139,7 +139,7 @@ verify_basic(struct archive *a, int seek
 	} else {
 		assertEqualInt(ARCHIVE_FAILED, archive_read_data(a, buff, 19));
 		assertEqualString(archive_error_string(a),
-		    "Unsupported ZIP compression method (deflation)");
+		    "Unsupported ZIP compression method (8: deflation)");
 		assert(archive_errno(a) != 0);
 	}
 
@@ -162,7 +162,7 @@ verify_basic(struct archive *a, int seek
 	} else {
 		assertEqualInt(ARCHIVE_FAILED, archive_read_data(a, buff, 19));
 		assertEqualString(archive_error_string(a),
-		    "Unsupported ZIP compression method (deflation)");
+		    "Unsupported ZIP compression method (8: deflation)");
 		assert(archive_errno(a) != 0);
 	}
 	assertEqualInt(ARCHIVE_EOF, archive_read_next_header(a, &ae));
@@ -231,7 +231,7 @@ verify_info_zip_ux(struct archive *a, in
 	} else {
 		assertEqualInt(ARCHIVE_FAILED, archive_read_data(a, buff, 19));
 		assertEqualString(archive_error_string(a),
-		    "Unsupported ZIP compression method (deflation)");
+		    "Unsupported ZIP compression method (8: deflation)");
 		assert(archive_errno(a) != 0);
 	}
 	assertEqualIntA(a, ARCHIVE_EOF, archive_read_next_header(a, &ae));
@@ -302,7 +302,7 @@ verify_extract_length_at_end(struct arch
 	} else {
 		assertEqualIntA(a, ARCHIVE_FAILED, archive_read_extract(a, ae, 0));
 		assertEqualString(archive_error_string(a),
-		    "Unsupported ZIP compression method (deflation)");
+		    "Unsupported ZIP compression method (8: deflation)");
 		assert(archive_errno(a) != 0);
 	}
 
