--- gcc/ada/adaint.h.intermediate	2022-03-06 13:30:35 UTC
+++ gcc/ada/adaint.h
@@ -365,6 +365,7 @@ extern int    __gnat_sigaltstack (const
 extern int    __gnat_sigaction   (int, const struct sigaction *, struct sigaction *);
 #endif
 #include <time.h>
+#include <sys/time.h>
 extern int    __gnat_nanosleep     (const struct timespec *, struct timespec *);
 extern int    __gnat_gettimeofday  (struct timeval *, struct timezone *);
 #include <sys/select.h>
