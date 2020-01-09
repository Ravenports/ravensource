--- bin/ipfrag.c.orig	2019-08-14 09:04:35 UTC
+++ bin/ipfrag.c
@@ -37,6 +37,7 @@
 #include <string.h>
 #include <errno.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #ifdef HAVE_NETINET_IN_SYSTM_H
 #include <netinet/in_systm.h>
 #endif
