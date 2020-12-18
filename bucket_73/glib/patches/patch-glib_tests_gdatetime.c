--- glib/tests/gdatetime.c.orig	2020-12-17 11:47:11 UTC
+++ glib/tests/gdatetime.c
@@ -2369,7 +2369,7 @@ test_find_interval (void)
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new ("America/Toronto");
+  tz = g_time_zone_new ("America/Toronto Eastern");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new ("Eastern Standard Time");
 #endif
@@ -2402,7 +2402,7 @@ test_adjust_time (void)
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new ("America/Toronto");
+  tz = g_time_zone_new ("America/Toronto Eastern");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new ("Eastern Standard Time");
 #endif
