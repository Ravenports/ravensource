--- src/res_search_async.c.orig	2020-01-17 13:59:24 UTC
+++ src/res_search_async.c
@@ -22,6 +22,9 @@
 #include <sys/uio.h>
 #include <arpa/nameser.h>
 #include <netdb.h>
+#if defined __DragonFly__ || defined __FreeBSD__
+#include <netinet/in.h>
+#endif
 
 #include <asr.h>
 #include <errno.h>
