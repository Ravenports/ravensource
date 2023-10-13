--- erts/emulator/nifs/common/prim_tty_nif.c.orig	2023-10-11 15:12:39 UTC
+++ erts/emulator/nifs/common/prim_tty_nif.c
@@ -43,7 +43,7 @@
 #include <locale.h>
 #ifdef HAVE_TERMCAP
 #include <termios.h>
-#include <termcap.h>
+#include <ncurses/term.h>
 #endif
 #ifndef __WIN32__
 #include <unistd.h>
