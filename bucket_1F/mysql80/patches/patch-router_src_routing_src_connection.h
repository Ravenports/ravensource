--- router/src/routing/src/connection.h.orig	2019-04-13 11:46:31 UTC
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
