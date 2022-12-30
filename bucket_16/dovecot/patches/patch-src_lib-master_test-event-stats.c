--- src/lib-master/test-event-stats.c.orig	2022-12-21 08:49:12 UTC
+++ src/lib-master/test-event-stats.c
@@ -13,6 +13,7 @@
 #include "stats-client.h"
 #include "test-common.h"
 #include <fcntl.h>
+#include <signal.h>
 #include <unistd.h>
 #include <signal.h>
 #include <sys/socket.h>
