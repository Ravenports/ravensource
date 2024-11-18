--- src/configsys.c.orig	2024-02-03 15:07:00 UTC
+++ src/configsys.c
@@ -14,9 +14,6 @@
  * License along with this library. If not, see <http://www.gnu.org/licenses/>.
  */
 
-#define _POSIX_SOURCE /* feature test macro for fileno */
-#define _XOPEN_SOURCE /* feature test macro for fsync */
-
 #include "config.h"
 #include "debug.h"
 
