--- src/lib-master/test-event-stats.c.orig	2023-09-14 13:17:46 UTC
+++ src/lib-master/test-event-stats.c
@@ -13,6 +13,7 @@
 #include "stats-client.h"
 #include "test-common.h"
 #include <fcntl.h>
+#include <signal.h>
 #include <unistd.h>
 #include <signal.h>
 #include <sys/socket.h>
