--- libgnucash/engine/qof-string-cache.cpp.orig	2020-06-07 16:56:25 UTC
+++ libgnucash/engine/qof-string-cache.cpp
@@ -26,8 +26,6 @@
  *   Author: Phil Longstaff (phil.longstaff@yahoo.ca)               *
 \********************************************************************/
 
-extern "C"
-{
 #include <config.h>
 
 #include <ctype.h>
@@ -35,7 +33,6 @@ extern "C"
 #include <stdlib.h>
 #include <string.h>
 #include "qof.h"
-}
 
 /* Uncomment if you need to log anything.
 static QofLogModule log_module = QOF_MOD_UTIL;
