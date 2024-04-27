--- src/tilda-lock-files.c.orig	2024-02-03 15:07:00 UTC
+++ src/tilda-lock-files.c
@@ -13,6 +13,10 @@
  * License along with this library. If not, see <http://www.gnu.org/licenses/>.
  */
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define USE_PGREP
+#endif
+
 #include "tilda-lock-files.h"
 
 #include "debug.h"
@@ -217,7 +221,11 @@ static struct lock_info *islockfile (con
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
