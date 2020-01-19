--- src/filemanager/midnight.c.orig	2020-01-01 15:52:34 UTC
+++ src/filemanager/midnight.c
@@ -874,7 +874,7 @@ setup_mc (void)
         add_select_channel (mc_global.tty.subshell_pty, load_prompt, NULL);
 #endif /* !ENABLE_SUBSHELL */
 
-    if ((tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
+    if ((tty_baudrate () > 0 && tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
         verbose = FALSE;
 }
 
