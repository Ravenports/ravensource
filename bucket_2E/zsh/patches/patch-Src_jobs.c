--- Src/jobs.c.orig	2026-05-31 18:18:32 UTC
+++ Src/jobs.c
@@ -727,6 +727,12 @@ printhhmmss(double secs)
 	fprintf(stderr,           "%.3f",              secs);
 }
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__MidnightBSD__)
+#define ravBSD 1
+#else
+#define ravBSD 0
+#endif
+
 static void
 printtime(struct timeval *real, child_times_t *ti, char *desc)
 {
@@ -751,15 +757,20 @@ printtime(struct timeval *real, child_ti
     /* go ahead and compute these, since almost every TIMEFMT will have them */
     elapsed_time = real->tv_sec + real->tv_usec / 1000000.0;
 
+    long clktck = get_clktck();
 #ifdef HAVE_GETRUSAGE
     user_time = ti->ru_utime.tv_sec + ti->ru_utime.tv_usec / 1000000.0;
     system_time = ti->ru_stime.tv_sec + ti->ru_stime.tv_usec / 1000000.0;
     total_time = user_time + system_time;
+# if ravBSD
+    percent = 100.0 * total_time / elapsed_time;
+    total_time *= (double) clktck;
+# else
     percent = 100.0 * total_time
 	/ (real->tv_sec + real->tv_usec / 1000000.0);
+# endif
 #else
     {
-	long clktck = get_clktck();
 	user_time    = ti->ut / (double) clktck;
 	system_time  = ti->st / (double) clktck;
 	percent      =  100.0 * (ti->ut + ti->st)
@@ -894,7 +905,11 @@ printtime(struct timeval *real, child_ti
 # define MAXRSS_IN_KB(x) (x)
 #endif
 	    case 'M':
+#if ravBSD
 		fprintf(stderr, "%ld", MAXRSS_IN_KB(ti->ru_maxrss));
+#else
+		fprintf(stderr, "%ld", MAXRSS_IN_KB(ti->ru_maxrss / 1024));
+#endif
 		break;
 #endif
 #ifdef HAVE_STRUCT_RUSAGE_RU_MAJFLT
