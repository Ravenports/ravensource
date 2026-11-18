--- imap/src/c-client/nntp.c.orig	2026-05-03 00:48:18 UTC
+++ imap/src/c-client/nntp.c
@@ -28,6 +28,7 @@
 
 #include <ctype.h>
 #include <stdio.h>
+#include <time.h>
 #include "c-client.h"
 #include "newsrc.h"
 #include "netmsg.h"
