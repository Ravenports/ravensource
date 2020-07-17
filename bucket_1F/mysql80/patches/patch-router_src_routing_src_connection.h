--- router/src/routing/src/connection.h.orig	2020-06-16 16:31:03 UTC
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
