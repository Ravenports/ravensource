--- storage/ndb/include/mgmapi/mgmapi.h.orig	2026-07-10 11:18:36 UTC
+++ storage/ndb/include/mgmapi/mgmapi.h
@@ -33,6 +33,7 @@
 #include <netinet/in.h>
 #endif
 
+#include <ctime>
 #include "mgmapi_config_parameters.h"
 #include "mgmapi_error.h"
 #include "ndb_logevent.h"
