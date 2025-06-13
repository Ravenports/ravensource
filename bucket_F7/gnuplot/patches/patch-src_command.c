--- src/command.c.orig	2025-05-31 04:36:14 UTC
+++ src/command.c
@@ -109,6 +109,9 @@ static TBOOLEAN pause_internal;    /* fl
 
 #ifndef _WIN32
 # include "help.h"
+# if defined __FreeBSD__ || defined __DragonFly__
+# include <sys/wait.h>
+# endif
 #endif
 
 #ifdef _WIN32
