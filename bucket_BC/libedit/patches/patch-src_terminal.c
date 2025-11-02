--- src/terminal.c.orig	2023-08-27 07:25:53 UTC
+++ src/terminal.c
@@ -68,14 +68,6 @@ __RCSID("$NetBSD: terminal.c,v 1.46 2023
 #include <term.h>
 #endif
 
-#if defined(__sun)
-extern int tgetent(char *, const char *);
-extern int tgetflag(char *);
-extern int tgetnum(char *);
-extern int tputs(const char *, int, int (*)(int));
-extern char* tgoto(const char*, int, int);
-extern char* tgetstr(char*, char**);
-#endif
 
 #ifdef _REENTRANT
 #include <pthread.h>
