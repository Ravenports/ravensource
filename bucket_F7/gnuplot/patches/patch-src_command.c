--- src/command.c.orig	2022-11-01 21:03:33 UTC
+++ src/command.c
@@ -113,6 +113,9 @@ static int thread_rl_RetCode = -1; /* re
 
 #ifndef _WIN32
 # include "help.h"
+# if defined __FreeBSD__ || defined __DragonFly__
+# include <sys/wait.h>
+# endif
 #endif
 
 #ifdef _WIN32
