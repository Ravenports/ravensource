--- src/filemanager/filemanager.c.orig	2023-01-21 16:51:33 UTC
+++ src/filemanager/filemanager.c
@@ -856,7 +856,7 @@ setup_mc (void)
 #endif /* HAVE_CHARSET */
 #endif /* HAVE_SLANG */
 
-    if ((tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
+    if ((tty_baudrate () > 0 && tty_baudrate () < 9600) || mc_global.tty.slow_terminal)
         verbose = FALSE;
 }
 
