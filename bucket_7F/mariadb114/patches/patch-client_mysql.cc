--- client/mysql.cc.orig	2025-11-04 12:57:48 UTC
+++ client/mysql.cc
@@ -62,8 +62,8 @@ static char *server_version= NULL;
 
 extern "C" {
 #if defined(HAVE_CURSES_H) && defined(HAVE_TERM_H)
-#include <curses.h>
-#include <term.h>
+#include <ncurses/curses.h>
+#include <ncurses/term.h>
 #else
 #if defined(HAVE_TERMIOS_H)
 #include <termios.h>
@@ -82,7 +82,7 @@ extern "C" {
 #endif
 #undef SYSV				// hack to avoid syntax error
 #ifdef HAVE_TERM_H
-#include <term.h>
+#include <ncurses/term.h>
 #endif
 #endif
 #endif /* defined(HAVE_CURSES_H) && defined(HAVE_TERM_H) */
