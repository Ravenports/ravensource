--- lib/saslutil.c.orig	2022-02-18 21:50:42 UTC
+++ lib/saslutil.c
@@ -56,12 +56,8 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
-#ifdef HAVE_UNISTD_H
 #include <unistd.h>
-#endif
-#ifdef HAVE_TIME_H
 #include <time.h>
-#endif
 #include "saslint.h"
 #include <saslutil.h>
 
