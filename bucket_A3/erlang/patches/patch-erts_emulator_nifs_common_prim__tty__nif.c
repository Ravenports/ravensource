--- erts/emulator/nifs/common/prim_tty_nif.c.orig	2025-06-13 14:54:33 UTC
+++ erts/emulator/nifs/common/prim_tty_nif.c
@@ -46,12 +46,7 @@
 #include <locale.h>
 #if defined(HAVE_TERMCAP) && (defined(HAVE_TERMCAP_H) || (defined(HAVE_CURSES_H) && defined(HAVE_TERM_H)))
 #include <termios.h>
-#ifdef HAVE_TERMCAP_H
-#include <termcap.h>
-#else /* !HAVE_TERMCAP_H */
-#include <curses.h>
-#include <term.h>
-#endif
+#include <ncurses/term.h>
 #else
 /* We detected TERMCAP support, but could not find the correct headers to include */
 #undef HAVE_TERMCAP
