--- libgnucash/core-utils/gnc-locale-utils.cpp.orig	2020-12-27 19:35:55 UTC
+++ libgnucash/core-utils/gnc-locale-utils.cpp
@@ -19,10 +19,7 @@
  * 51 Franklin Street, Fifth Floor    Fax:    +1-617-542-2652       *
  * Boston, MA  02110-1301,  USA       gnu@gnu.org                   *
 \********************************************************************/
-extern "C"
-{
 #include <glib.h>
-}
 #include <clocale>
 #include <boost/locale.hpp>
 #include "gnc-locale-utils.hpp"
