--- libgnucash/engine/qofquery.cpp.orig	2020-06-07 16:56:25 UTC
+++ libgnucash/engine/qofquery.cpp
@@ -21,8 +21,6 @@
  *                                                                  *
 \********************************************************************/
 
-extern "C"
-{
 #include <config.h>
 
 #include <sys/types.h>
@@ -30,7 +28,6 @@ extern "C"
 #include <glib.h>
 #include <regex.h>
 #include <string.h>
-}
 
 #include "qof.h"
 #include "qof-backend.hpp"
