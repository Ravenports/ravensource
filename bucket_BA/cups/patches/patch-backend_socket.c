--- backend/socket.c.orig	2018-06-05 16:06:54 UTC
+++ backend/socket.c
@@ -297,7 +297,6 @@ main(int  argc,				/* I - Number of comm
   */
 
   fprintf(stderr, "DEBUG: Connecting to %s:%d\n", hostname, port);
-  _cupsLangPrintFilter(stderr, "INFO", _("Connecting to printer."));
 
   for (delay = 5;;)
   {
@@ -377,7 +376,6 @@ main(int  argc,				/* I - Number of comm
   }
 
   fputs("STATE: -connecting-to-device\n", stderr);
-  _cupsLangPrintFilter(stderr, "INFO", _("Connected to printer."));
 
   fprintf(stderr, "DEBUG: Connected to %s:%d...\n",
 	  httpAddrString(&(addr->addr), addrname, sizeof(addrname)),
@@ -406,7 +404,7 @@ main(int  argc,				/* I - Number of comm
                             0, backendNetworkSideCB);
 
     if (print_fd != 0 && tbytes >= 0)
-      _cupsLangPrintFilter(stderr, "INFO", _("Print file sent."));
+      fputs("DEBUG: Print file sent.\n", stderr);
   }
 
   fputs("STATE: +cups-waiting-for-job-completed\n", stderr);
@@ -417,7 +415,7 @@ main(int  argc,				/* I - Number of comm
     * Shutdown the socket and wait for the other end to finish...
     */
 
-    _cupsLangPrintFilter(stderr, "INFO", _("Waiting for printer to finish."));
+    fputs("DEBUG: Waiting for printer to finish.\n", stderr);
 
     shutdown(device_fd, 1);
 
