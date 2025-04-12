--- libmate-desktop/mate-desktop-item.c.orig	2024-03-11 21:38:00 UTC
+++ libmate-desktop/mate-desktop-item.c
@@ -1586,7 +1586,7 @@ startup_timeout (void *data)
 
 #if GLIB_CHECK_VERSION(2,61,2)
 		time_t tv_sec;
-		suseconds_t tv_usec;
+		long tv_usec;
 		gint64 tv;
 
 		sn_launcher_context_get_last_active_time (sn_context, &tv_sec, &tv_usec);
