--- src/sys.h.orig	2021-04-19 21:19:17 UTC
+++ src/sys.h
@@ -45,6 +45,10 @@
 #endif
 #include <sys/types.h>
 
+#ifdef __sun__
+#include <sys/types.h>
+#endif
+
 #if !defined(__attribute__) && (defined(__cplusplus) || !defined(__GNUC__)  || __GNUC__ == 2 && __GNUC_MINOR__ < 8)
 # define __attribute__(A)
 #endif
@@ -116,13 +120,4 @@ typedef unsigned int	u_int32_t;
 #define	REGEX		/* Use POSIX.2 regular expression functions */
 #undef	REGEXP		/* Use UNIX V8 regular expression functions */
 
-#if defined(__sun)
-extern int tgetent(char *, const char *);
-extern int tgetflag(char *);
-extern int tgetnum(char *);
-extern int tputs(const char *, int, int (*)(int));
-extern char* tgoto(const char*, int, int);
-extern char* tgetstr(char*, char**);
-#endif
-
 #endif /* _h_sys */
