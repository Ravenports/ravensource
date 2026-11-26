--- utmp.c.orig	2026-07-11 12:23:46 UTC
+++ utmp.c
@@ -30,6 +30,7 @@
 
 #include "utmp.h"
 
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -64,9 +65,7 @@ static struct utmpx *getutslot(slot_t);
 
 static int utmpok;
 static char UtmpName[] = UTMPXFILE;
-#ifndef UTMP_HELPER
 static int utmpfd = -1;
-#endif
 
 #undef  D_loginhost
 #define D_loginhost D_utmp_logintty.ut_host
