--- xwin.c.orig	2019-06-13 12:10:15 UTC
+++ xwin.c
@@ -48,7 +48,7 @@
 #define HOST_NAME_MAX MAXHOSTNAMELEN
 #endif
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
 #endif
 
@@ -2167,6 +2167,8 @@ get_sizehints(XSizeHints * sizehints, ui
 		sizehints->min_width = sizehints->max_width = width;
 		sizehints->min_height = sizehints->max_height = height;
 	}
+
+	ui_reset_clip();
 }
 
 void
