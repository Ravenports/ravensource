$NetBSD: patch-src_programs_pkttyagent.c,v 1.5 2025/12/21 15:44:05 wiz Exp $

Avoid %m usage in printf.
https://github.com/polkit-org/polkit/pull/624

--- src/programs/pkttyagent.c.orig	2025-12-17 16:14:53 UTC
+++ src/programs/pkttyagent.c
@@ -20,6 +20,7 @@
  */
 
 #include <stdio.h>
+#include <errno.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <termios.h>
@@ -256,7 +257,7 @@ main (int argc, char *argv[])
     {
       if (close (opt_notify_fd) != 0)
         {
-          g_printerr ("Error closing notify-fd %d: %m\n", opt_notify_fd);
+          g_printerr ("Error closing notify-fd %d: %s\n", opt_notify_fd, g_strerror(errno));
           goto out;
         }
     }
