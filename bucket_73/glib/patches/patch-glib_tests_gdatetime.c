--- glib/tests/gdatetime.c.orig	2021-03-18 13:47:48 UTC
+++ glib/tests/gdatetime.c
@@ -2373,7 +2373,7 @@ test_find_interval (void)
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new ("America/Toronto");
+  tz = g_time_zone_new ("America/Toronto Eastern");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new ("Eastern Standard Time");
 #endif
@@ -2406,7 +2406,7 @@ test_adjust_time (void)
   gint i1, i2;
 
 #ifdef G_OS_UNIX
-  tz = g_time_zone_new ("America/Toronto");
+  tz = g_time_zone_new ("America/Toronto Eastern");
 #elif defined G_OS_WIN32
   tz = g_time_zone_new ("Eastern Standard Time");
 #endif
