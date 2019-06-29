--- src/diffviewer/ydiff.c.orig	2018-12-28 19:35:25 UTC
+++ src/diffviewer/ydiff.c
@@ -816,7 +816,7 @@ dff_execute (const char *args, const cha
     /* escape potential $ to avoid shell variable substitutions in popen() */
     file1_esc = strutils_shell_escape (file1);
     file2_esc = strutils_shell_escape (file2);
-    cmd = g_strdup_printf ("diff %s %s %s %s %s", args, extra, opt, file1_esc, file2_esc);
+    cmd = g_strdup_printf ("gdiff %s %s %s %s %s", args, extra, opt, file1_esc, file2_esc);
     g_free (file1_esc);
     g_free (file2_esc);
 
