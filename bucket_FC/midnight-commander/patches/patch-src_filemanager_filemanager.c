--- src/filemanager/filemanager.c.orig	2021-08-01 16:45:58 UTC
+++ src/filemanager/filemanager.c
@@ -859,7 +859,7 @@ setup_mc (void)
 #endif /* HAVE_CHARSET */
 #endif /* HAVE_SLANG */
 
-    if ((tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
+    if ((tty_baudrate () > 0 && tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
         verbose = FALSE;
 }
 
