--- Instant/main.c.orig	1996-06-17 03:50:28 UTC
+++ Instant/main.c
@@ -73,6 +73,7 @@ static char *RCSid =
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
+#include <unistd.h>
 #include <memory.h>
 #include <errno.h>
 #include <sys/types.h>
@@ -171,7 +172,6 @@ Initialize1(
     time_t	tnow;
     struct tm	*nowtm;
     char	*cp, buf[100];
-    extern	int gethostname(char *, int);	/* not in a system .h file... */
 
     /* where we try to find data/library files */
     if (!(tpt_lib=getenv(TPT_LIB))) tpt_lib = DEF_TPT_LIB;
