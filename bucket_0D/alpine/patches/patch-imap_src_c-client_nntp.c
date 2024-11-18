--- imap/src/c-client/nntp.c.orig	2022-06-03 00:14:00 UTC
+++ imap/src/c-client/nntp.c
@@ -28,6 +28,7 @@
 
 #include <ctype.h>
 #include <stdio.h>
+#include <time.h>
 #include "c-client.h"
 #include "newsrc.h"
 #include "netmsg.h"
