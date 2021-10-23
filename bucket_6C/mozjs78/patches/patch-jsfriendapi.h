Fix ErrorReport.h:324:46: error: 'va_list' has not been declared

--- jsfriendapi.h.orig	2021-08-04 22:22:28 UTC
+++ jsfriendapi.h
@@ -14,6 +14,7 @@
 #include "mozilla/PodOperations.h"
 #include "mozilla/UniquePtr.h"
 
+#include <stdarg.h>
 #include "jspubtd.h"
 
 #include "js/CallArgs.h"
