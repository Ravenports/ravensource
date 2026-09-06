--- cl/extern.h.orig	2007-11-18 16:43:54 UTC
+++ cl/extern.h
@@ -21,7 +21,7 @@ void *newterm __P((const char *, FILE *,
 void setupterm __P((char *, int, int *));
 #endif
 #ifdef HAVE_CURSES_TIGETSTR
-char *tigetstr();
+char *tigetstr(const char *);
 #else
 char *tigetstr __P((char *));
 #endif
