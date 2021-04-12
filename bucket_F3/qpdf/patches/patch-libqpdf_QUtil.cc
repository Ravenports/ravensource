--- libqpdf/QUtil.cc.orig	2021-03-11 17:59:41 UTC
+++ libqpdf/QUtil.cc
@@ -905,7 +905,11 @@ QUtil::get_current_qpdf_time()
                     static_cast<int>(ltime.tm_hour),
                     static_cast<int>(ltime.tm_min),
                     static_cast<int>(ltime.tm_sec),
+# if defined(__FreeBSD__)
+                    static_cast<int>(ltime.tm_gmtoff / 60));
+# else
                     static_cast<int>(timezone / 60));
+# endif
 #endif
 }
 
