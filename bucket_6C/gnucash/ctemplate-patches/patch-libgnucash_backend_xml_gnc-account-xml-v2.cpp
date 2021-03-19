--- libgnucash/backend/xml/gnc-account-xml-v2.cpp.orig	2020-06-07 16:56:25 UTC
+++ libgnucash/backend/xml/gnc-account-xml-v2.cpp
@@ -22,8 +22,6 @@
  * Boston, MA  02110-1301,  USA       gnu@gnu.org                   *
  *                                                                  *
 \********************************************************************/
-extern "C"
-{
 #include <config.h>
 
 #include <glib.h>
@@ -31,7 +29,6 @@ extern "C"
 #include <string.h>
 #include <AccountP.h>
 #include <Account.h>
-}
 
 #include "gnc-xml-helper.h"
 #include "sixtp.h"
