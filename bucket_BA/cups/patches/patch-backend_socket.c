--- backend/socket.c.orig	2025-11-27 15:21:54 UTC
+++ backend/socket.c
@@ -293,7 +293,6 @@ main(int  argc,				/* I - Number of comm
   */
 
   fprintf(stderr, "DEBUG: Connecting to %s:%d\n", hostname, port);
-  _cupsLangPrintFilter(stderr, "INFO", _("Connecting to printer."));
 
   for (delay = 5;;)
   {
@@ -373,7 +372,6 @@ main(int  argc,				/* I - Number of comm
   }
 
   fputs("STATE: -connecting-to-device\n", stderr);
-  _cupsLangPrintFilter(stderr, "INFO", _("Connected to printer."));
 
   fprintf(stderr, "DEBUG: Connected to %s:%d...\n",
 	  httpAddrString(&(addr->addr), addrname, sizeof(addrname)),
@@ -404,7 +402,7 @@ main(int  argc,				/* I - Number of comm
       tbytes = bytes;
 
     if (print_fd != 0 && tbytes >= 0)
-      _cupsLangPrintFilter(stderr, "INFO", _("Print file sent."));
+      fputs("DEBUG: Print file sent.\n", stderr);
   }
 
   fputs("STATE: +cups-waiting-for-job-completed\n", stderr);
@@ -415,7 +413,7 @@ main(int  argc,				/* I - Number of comm
     * Shutdown the socket and wait for the other end to finish...
     */
 
-    _cupsLangPrintFilter(stderr, "INFO", _("Waiting for printer to finish."));
+    fputs("DEBUG: Waiting for printer to finish.\n", stderr);
 
     shutdown(device_fd, 1);
 
