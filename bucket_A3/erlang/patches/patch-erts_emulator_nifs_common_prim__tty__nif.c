--- erts/emulator/nifs/common/prim_tty_nif.c.orig	2023-06-28 10:02:50 UTC
+++ erts/emulator/nifs/common/prim_tty_nif.c
@@ -43,8 +43,8 @@
 #include <locale.h>
 #ifdef HAVE_TERMCAP
 #include <termios.h>
-#include <curses.h>
-#include <term.h>
+#include <ncurses/curses.h>
+#include <ncurses/term.h>
 #endif
 #ifndef __WIN32__
 #include <unistd.h>
