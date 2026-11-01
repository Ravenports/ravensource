--- xwin.c.orig	2026-10-25 17:51:28 UTC
+++ xwin.c
@@ -52,7 +52,7 @@
 #define HOST_NAME_MAX MAXHOSTNAMELEN
 #endif
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__ || defined __NetBSD__
 #define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
 #endif
 
@@ -2577,6 +2577,8 @@ get_sizehints(XSizeHints * sizehints, ui
 		sizehints->min_width = sizehints->max_width = width;
 		sizehints->min_height = sizehints->max_height = height;
 	}
+
+	ui_reset_clip();
 }
 
 void
