--- ede-bug-tools/ede-crasher/CrashDialog.cpp.orig	2025-10-21 17:13:24.697341000 +0200
+++ ede-bug-tools/ede-crasher/CrashDialog.cpp	2025-10-21 17:13:47.077818000 +0200
@@ -86,7 +86,7 @@
 	txt_buf->append("---------- short summary ----------\n");
 
 	/* make first X version */
-	char buf[256];
+	char buf[512];
 	snprintf(buf, sizeof(buf), "\nX version: %s %i %i.%i", XServerVendor(fl_display), XVendorRelease(fl_display), XProtocolVersion(fl_display), XProtocolRevision(fl_display));
 	txt_buf->append(buf);
 
