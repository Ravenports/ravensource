--- src/core/screen.c.orig	2024-02-16 21:06:54 UTC
+++ src/core/screen.c
@@ -2668,7 +2668,7 @@ collect_timed_out_foreach (void *element
   double elapsed;
 
   time_t tv_sec;
-  suseconds_t  tv_usec;
+  long  tv_usec;
   gint64 tv;
 
   sn_startup_sequence_get_last_active_time (sequence, &tv_sec, &tv_usec);
