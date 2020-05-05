--- src/tilda.c.orig	2020-05-03 19:20:55 UTC
+++ src/tilda.c
@@ -13,6 +13,10 @@
  * You should have received a copy of the GNU Library General Public
  * License along with this library. If not, see <http://www.gnu.org/licenses/>.
  */
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define USE_PGREP
+#include <fcntl.h>
+#endif
 #define _POSIX_SOURCE /* feature test macro for signal functions */
 #define _XOPEN_SOURCE /* feature test macro for popen */
 
@@ -232,7 +236,11 @@ nomatch:
 static GSList *getPids() {
     GSList *pids = NULL;
     FILE *ps_output;
+#ifdef USE_PGREP
+    const gchar ps_command[] = "/usr/bin/pgrep tilda";
+#else
     const gchar ps_command[] = "ps -C tilda -o pid=";
+#endif
     gchar buf[16]; /* Really shouldn't need more than 6 */
 
     if ((ps_output = popen (ps_command, "r")) == NULL) {
