--- libgnucash/engine/qofclass.cpp.orig	2020-06-07 16:56:25 UTC
+++ libgnucash/engine/qofclass.cpp
@@ -21,10 +21,10 @@
  *                                                                  *
 \********************************************************************/
 
+#include <glib.h>
 extern "C"
 {
 #include <config.h>
-#include <glib.h>
 }
 
 #include "qof.h"
