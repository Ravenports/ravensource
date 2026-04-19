--- src/libtinysparql/core/tracker-vtab-service.c.orig	2026-04-14 21:01:56 UTC
+++ src/libtinysparql/core/tracker-vtab-service.c
@@ -19,6 +19,7 @@
  * Author: Carlos Garnacho <carlosg@gnome.org>
  */
 #include "config.h"
+#include <strings.h>
 
 #include "tracker-vtab-service.h"
 
