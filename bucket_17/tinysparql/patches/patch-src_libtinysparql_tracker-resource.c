--- src/libtinysparql/tracker-resource.c.orig	2026-04-14 21:01:56 UTC
+++ src/libtinysparql/tracker-resource.c
@@ -23,6 +23,7 @@
 #include <json-glib/json-glib.h>
 
 #include <string.h>
+#include <strings.h>
 
 #include "tracker-deserializer-resource.h"
 #include "tracker-uri.h"
