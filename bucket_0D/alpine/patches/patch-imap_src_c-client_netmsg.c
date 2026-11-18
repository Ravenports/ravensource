--- imap/src/c-client/netmsg.c.orig	2026-05-03 00:48:18 UTC
+++ imap/src/c-client/netmsg.c
@@ -29,6 +29,7 @@
 
 #include <stdio.h>
 #include <errno.h>
+#include <time.h>
 extern int errno;		/* just in case */
 #include "c-client.h"
 #include "netmsg.h"
