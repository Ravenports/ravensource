--- lib/tty/tty-ncurses.c.orig	2023-08-06 13:26:05 UTC
+++ lib/tty/tty-ncurses.c
@@ -290,7 +290,7 @@ tty_shutdown (void)
 void
 tty_enter_ca_mode (void)
 {
-    if (mc_global.tty.xterm_flag && smcup != NULL)
+    if (mc_global.tty.xterm_flag)
     {
         fprintf (stdout, /* ESC_STR ")0" */ ESC_STR "7" ESC_STR "[?47h");
         fflush (stdout);
@@ -302,7 +302,7 @@ tty_enter_ca_mode (void)
 void
 tty_exit_ca_mode (void)
 {
-    if (mc_global.tty.xterm_flag && rmcup != NULL)
+    if (mc_global.tty.xterm_flag)
     {
         fprintf (stdout, ESC_STR "[?47l" ESC_STR "8" ESC_STR "[m");
         fflush (stdout);
