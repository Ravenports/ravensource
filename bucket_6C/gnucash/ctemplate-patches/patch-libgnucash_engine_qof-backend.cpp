--- libgnucash/engine/qof-backend.cpp.orig	2020-12-27 19:35:55 UTC
+++ libgnucash/engine/qof-backend.cpp
@@ -22,11 +22,12 @@
  *                                                                  *
 \********************************************************************/
 
+#include <config.h>
+#include "qof.h"
 extern "C"
 {
 
 #include <config.h>
-#include "qof.h"
 #include <gnc-path.h>
 #include "gncla-dir.h"
 }
