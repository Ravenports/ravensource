--- src/filemanager/midnight.c.orig	2020-07-05 17:38:53 UTC
+++ src/filemanager/midnight.c
@@ -870,7 +870,7 @@ setup_mc (void)
         add_select_channel (mc_global.tty.subshell_pty, load_prompt, NULL);
 #endif /* !ENABLE_SUBSHELL */
 
-    if ((tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
+    if ((tty_baudrate () > 0 && tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
         verbose = FALSE;
 }
 
