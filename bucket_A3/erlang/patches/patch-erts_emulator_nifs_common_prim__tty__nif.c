--- erts/emulator/nifs/common/prim_tty_nif.c.orig	2026-04-23 10:09:44 UTC
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
@@ -835,11 +830,7 @@ static ERL_NIF_TERM tty_tgetstr_nif(ErlN
 static int tputs_buffer_index;
 static unsigned char tputs_buffer[1024];
 
-#if defined(__sun) && defined(__SVR4) /* Solaris */
-static int tty_puts_putc(char c) {
-#else
 static int tty_puts_putc(int c) {
-#endif
     tputs_buffer[tputs_buffer_index++] = (unsigned char)c;
     return 0;
 }
