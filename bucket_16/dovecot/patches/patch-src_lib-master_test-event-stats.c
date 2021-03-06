--- src/lib-master/test-event-stats.c.orig	2021-03-04 08:38:06 UTC
+++ src/lib-master/test-event-stats.c
@@ -13,6 +13,7 @@
 #include "stats-client.h"
 #include "test-common.h"
 #include <fcntl.h>
+#include <signal.h>
 #include <unistd.h>
 #include <signal.h>
 #include <sys/socket.h>
