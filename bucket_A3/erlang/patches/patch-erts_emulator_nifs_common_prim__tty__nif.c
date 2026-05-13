--- erts/emulator/nifs/common/prim_tty_nif.c.orig	2026-05-11 10:28:08 UTC
+++ erts/emulator/nifs/common/prim_tty_nif.c
@@ -46,17 +46,12 @@
 #include <locale.h>
 #if defined(HAVE_TERMCAP)
 #include <termios.h>
-#if defined(HAVE_NCURSES_CURSES_H)
 #include <ncurses/curses.h>
 #include <ncurses/term.h>
-#elif defined(HAVE_CURSES_H) && defined(HAVE_TERM_H)
-#include <curses.h>
-#include <term.h>
 #else
 /* We detected TERMCAP support, but could not find the correct headers to include */
 #undef HAVE_TERMCAP
 #endif
-#endif
 #ifndef __WIN32__
 #include <unistd.h>
 #include <sys/ioctl.h>
@@ -892,11 +887,7 @@ static unsigned char static_tputs_buffer
 #endif
 static unsigned char *tputs_buffer;
 
-#if defined(__sun) && defined(__SVR4) /* Solaris */
-static int tty_puts_putc(char c) {
-#else
 static int tty_puts_putc(int c) {
-#endif
 
     /* If we have a terminal that does a lot of padding, then it might be
        that a lot of text is generated here. Those types of terminals are
