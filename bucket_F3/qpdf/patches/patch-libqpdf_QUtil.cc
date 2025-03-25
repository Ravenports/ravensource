--- libqpdf/QUtil.cc.orig	2025-03-09 12:28:21 UTC
+++ libqpdf/QUtil.cc
@@ -896,6 +896,9 @@ QUtil::get_current_qpdf_time()
 # if HAVE_TM_GMTOFF
     // tm_gmtoff is seconds after UTC
     int tzoff = -static_cast<int>(ltime.tm_gmtoff / 60);
+# elif defined(__FreeBSD__)
+    // On FreeBSD, timezone is a character and the next line breaks
+    int tzoff = 0;
 # elif HAVE_EXTERN_LONG_TIMEZONE
     // timezone is seconds before UTC, not adjusted for daylight saving time
     int tzoff = static_cast<int>(timezone / 60);
