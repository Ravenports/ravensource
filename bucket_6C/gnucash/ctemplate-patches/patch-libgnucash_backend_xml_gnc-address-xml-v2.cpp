--- libgnucash/backend/xml/gnc-address-xml-v2.cpp.orig	2020-06-07 16:56:25 UTC
+++ libgnucash/backend/xml/gnc-address-xml-v2.cpp
@@ -21,14 +21,11 @@
  * Boston, MA  02110-1301,  USA       gnu@gnu.org                   *
  *                                                                  *
 \********************************************************************/
-extern "C"
-{
 #include <config.h>
 
 #include <glib.h>
 #include <stdlib.h>
 #include <string.h>
-}
 #include "gnc-xml-helper.h"
 
 #include "sixtp.h"
