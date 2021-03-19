--- libgnucash/engine/gnc-date.cpp.orig	2020-11-06 01:59:34 UTC
+++ libgnucash/engine/gnc-date.cpp
@@ -26,11 +26,11 @@
 \********************************************************************/
 
 #define __EXTENSIONS__
+#include <glib.h>
 extern "C"
 {
 
 #include <config.h>
-#include <glib.h>
 #include <libintl.h>
 #include <stdlib.h>
 #include "platform.h"
