--- src/command.c.orig	2026-09-21 04:24:48 UTC
+++ src/command.c
@@ -109,6 +109,9 @@ static TBOOLEAN pause_internal;    /* fl
 
 #ifndef _WIN32
 # include "help.h"
+# if defined __FreeBSD__ || defined __DragonFly__
+# include <sys/wait.h>
+# endif
 #endif
 
 #ifdef _WIN32
