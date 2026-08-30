--- metrics.c.orig	2026-08-26 08:59:34 UTC
+++ metrics.c
@@ -19,6 +19,7 @@
 #include <event2/event.h>
 #include <event2/http.h>
 #include <ctype.h>
+#include <inttypes.h>
 
 #include "nsd.h"
 #include "xfrd.h"
