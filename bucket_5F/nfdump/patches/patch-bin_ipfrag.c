--- bin/ipfrag.c.orig	2020-03-29 10:00:43 UTC
+++ bin/ipfrag.c
@@ -37,6 +37,7 @@
 #include <string.h>
 #include <errno.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #ifdef HAVE_NETINET_IN_SYSTM_H
 #include <netinet/in_systm.h>
 #endif
