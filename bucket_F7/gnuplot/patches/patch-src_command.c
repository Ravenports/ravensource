--- src/command.c.orig	2019-03-22 03:50:50 UTC
+++ src/command.c
@@ -115,6 +115,9 @@ int thread_rl_RetCode = -1; /* return co
 
 #ifndef _Windows
 # include "help.h"
+# if defined __FreeBSD__ || defined __DragonFly__
+# include <sys/wait.h>
+# endif
 #endif /* _Windows */
 
 #ifdef _Windows
