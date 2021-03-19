--- libgnucash/engine/qoflog.cpp.orig	2020-09-27 18:52:46 UTC
+++ libgnucash/engine/qoflog.cpp
@@ -25,8 +25,6 @@
  *  02110-1301,  USA
  */
 
-extern "C"
-{
 #include <config.h>
 
 #include <platform.h>
@@ -50,7 +48,6 @@ extern "C"
 
 #undef G_LOG_DOMAIN
 #define G_LOG_DOMAIN "qof.log"
-}
 
 #include "qof.h"
 #include "qoflog.h"
