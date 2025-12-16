--- gio/glocalfile.c.orig	2025-12-08 15:46:06 UTC
+++ gio/glocalfile.c
@@ -1273,6 +1273,7 @@ g_local_file_query_info (GFile
  * https://docs.oracle.com/cd/E86824_01/html/E54765/faccessat-2.html
  */
 #if defined(HAVE_FACCESSAT) && !defined(__FreeBSD__) && !defined(__ANDROID__) && \
+    !defined(__DragonFly__) && \
     !defined(__OpenBSD__) && !defined(__sun__)
 static gboolean
 g_local_file_query_exists (GFile        *file,
@@ -3259,6 +3260,7 @@ g_local_file_file_iface_init (GFileIface
   iface->monitor_file = g_local_file_monitor_file;
   iface->measure_disk_usage = g_local_file_measure_disk_usage;
 #if defined(HAVE_FACCESSAT) && !defined(__FreeBSD__) && !defined(__ANDROID__) && \
+    !defined(__DragonFly__) && \
     !defined(__OpenBSD__) && !defined(__sun__)
   iface->query_exists = g_local_file_query_exists;
 #endif
