--- storage/ndb/include/mgmapi/mgmapi.h.orig	2026-11-06 09:09:05 UTC
+++ storage/ndb/include/mgmapi/mgmapi.h
@@ -35,6 +35,7 @@
 #include <netinet/in.h>
 #endif
 
+#include <ctime>
 #include "mgmapi_config_parameters.h"
 #include "mgmapi_error.h"
 #include "ndb_logevent.h"
