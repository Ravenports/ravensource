--- src/terminal.c.orig	2026-05-08 19:40:44 UTC
+++ src/terminal.c
@@ -68,14 +68,6 @@ __RCSID("$NetBSD: terminal.c,v 1.47 2025
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
