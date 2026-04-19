--- src/libtinysparql/core/tracker-vtab-triples.c.orig	2026-04-14 21:01:56 UTC
+++ src/libtinysparql/core/tracker-vtab-triples.c
@@ -19,6 +19,7 @@
  * Author: Carlos Garnacho <carlosg@gnome.org>
  */
 #include "config.h"
+#include <strings.h>
 
 #include "tracker-ontologies.h"
 #include "tracker-vtab-triples.h"
