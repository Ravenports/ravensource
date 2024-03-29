--- src/freebsd/up-devd.c.orig	2023-07-06 08:52:27 UTC
+++ src/freebsd/up-devd.c
@@ -195,7 +195,7 @@ up_devd_event_cb (GIOChannel *source, GI
 		event[terminator] = 0;
 		up_devd_process_event(event, user_data);
 		g_free(event);
-	} else if (status == G_IO_STATUS_AGAIN) {
+	} else {
 		up_devd_init (UP_BACKEND(user_data));
 		if (up_devd_inited) {
 			int fd;
