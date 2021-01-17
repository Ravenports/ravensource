--- arcdos.c.orig	2013-06-27 02:00:19 UTC
+++ arcdos.c
@@ -173,14 +173,13 @@ setstamp(f, date, time)		/* set a file's
 	struct tm	tm;
 	struct timeval  tvp[2];
 	int	utimes();
-	long	tmclock();
 	tm.tm_sec = (time & 31) * 2;
 	tm.tm_min = (time >> 5) & 63;
 	tm.tm_hour = (time >> 11);
 	tm.tm_mday = date & 31;
 	tm.tm_mon = ((date >> 5) & 15) - 1;
 	tm.tm_year = (date >> 9) + 80;
-	tvp[0].tv_sec = tmclock(&tm);
+	tvp[0].tv_sec = timelocal(&tm);
 	tvp[1].tv_sec = tvp[0].tv_sec;
 	tvp[0].tv_usec = tvp[1].tv_usec = 0;
 	utimes(f, tvp);
