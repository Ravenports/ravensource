--- router/src/routing/src/connection.h.orig	2020-03-26 13:31:45 UTC
+++ router/src/routing/src/connection.h
@@ -29,6 +29,9 @@
 #include <chrono>
 #include <condition_variable>
 #include <mutex>
+#ifdef __DragonFly__
+#include <sys/socket.h>
+#endif
 
 #include "context.h"
 #include "mysql_router_thread.h"
