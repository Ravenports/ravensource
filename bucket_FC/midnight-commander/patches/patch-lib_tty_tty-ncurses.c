--- lib/tty/tty-ncurses.c.orig	2021-01-10 11:50:16 UTC
+++ lib/tty/tty-ncurses.c
@@ -282,7 +282,7 @@ tty_shutdown (void)
 void
 tty_enter_ca_mode (void)
 {
-    if (mc_global.tty.xterm_flag && smcup != NULL)
+    if (mc_global.tty.xterm_flag)
     {
         fprintf (stdout, /* ESC_STR ")0" */ ESC_STR "7" ESC_STR "[?47h");
         fflush (stdout);
@@ -294,7 +294,7 @@ tty_enter_ca_mode (void)
 void
 tty_exit_ca_mode (void)
 {
-    if (mc_global.tty.xterm_flag && rmcup != NULL)
+    if (mc_global.tty.xterm_flag)
     {
         fprintf (stdout, ESC_STR "[?47l" ESC_STR "8" ESC_STR "[m");
         fflush (stdout);
