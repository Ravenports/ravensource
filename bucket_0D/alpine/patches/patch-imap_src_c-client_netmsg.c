--- imap/src/c-client/netmsg.c.orig	2022-06-03 00:14:00 UTC
+++ imap/src/c-client/netmsg.c
@@ -29,6 +29,7 @@
 
 #include <stdio.h>
 #include <errno.h>
+#include <time.h>
 extern int errno;		/* just in case */
 #include "c-client.h"
 #include "netmsg.h"
