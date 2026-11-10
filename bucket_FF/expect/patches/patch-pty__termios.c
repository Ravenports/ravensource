--- pty_termios.c.orig	2026-11-09 20:14:22 UTC
+++ pty_termios.c
@@ -190,7 +190,13 @@ static char slave_name[MAXPTYNAMELEN];
 #endif /* HAVE_SCO_CLIST_PTYS */
 
 #ifdef HAVE_OPENPTY
+# ifdef __linux__
 #include <pty.h>
+# elif defined(__NetBSD__)
+# include <util.h>
+# else
+# include <libutil.h>
+# endif
 static char master_name[64];
 static char slave_name[64];
 #endif
