--- src/common/system_signal_handling.c.orig	2026-02-04 20:20:09 UTC
+++ src/common/system_signal_handling.c
@@ -76,7 +76,9 @@ static void _dt_sigsegv_handler(int para
   if((fout = g_file_open_tmp("darktable_bt_XXXXXX.txt", &name_used, NULL)) == -1)
     fout = STDOUT_FILENO; // just print everything to stdout
 
+#if !defined(__sun)
   dprintf(fout, "this is %s reporting a segfault:\n\n", darktable_package_string);
+#endif
 
   if(fout != STDOUT_FILENO) close(fout);
 
