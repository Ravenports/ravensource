--- src/filemanager/filemanager.c.orig	2023-08-06 13:26:05 UTC
+++ src/filemanager/filemanager.c
@@ -850,7 +850,7 @@ setup_mc (void)
 #endif /* HAVE_CHARSET */
 #endif /* HAVE_SLANG */
 
-    if ((tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
+    if ((tty_baudrate () > 0 && tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
         verbose = FALSE;
 }
 
