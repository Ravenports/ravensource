--- src/ck-vt-monitor.c.orig	2023-08-11 16:26:44 UTC
+++ src/ck-vt-monitor.c
@@ -160,7 +160,7 @@ ck_vt_monitor_get_active (CkVtMonitor
 
 #if defined (__sun) && defined (HAVE_SYS_VT_H)
 static void
-handle_vt_active (void)
+handle_vt_active (int sig __attribute__((__unused__)))
 {
         struct vt_stat state;
         guint          num;
