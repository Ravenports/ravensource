--- src/procinfo.h.orig	2026-03-28 16:48:31 UTC
+++ src/procinfo.h
@@ -22,6 +22,9 @@ along with this program.  If not, see <h
 #ifdef HAVE_PROCESS_SYSCTL
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#ifdef __DragonFly__
+#include <sys/user.h>
+#endif
 #include <sys/proc.h>
 #include <sys/stat.h>
 #endif
