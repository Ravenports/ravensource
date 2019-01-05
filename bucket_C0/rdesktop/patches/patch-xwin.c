--- xwin.c.orig	2018-12-18 11:30:46 UTC
+++ xwin.c
@@ -2160,6 +2160,8 @@ ui_resize_window()
 		XFreePixmap(g_display, g_backstore);
 		g_backstore = bs;
 	}
+
+	ui_reset_clip();
 }
 
 RD_BOOL
