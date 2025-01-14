Fix SunOS includes.
Fix pid_t type.

--- src/polkit/polkitunixprocess.c.orig	2025-01-13 14:54:22 UTC
+++ src/polkit/polkitunixprocess.c
@@ -20,6 +20,11 @@
  */
 
 #include <sys/types.h>
+#ifdef HAVE_SOLARIS
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <procfs.h>
+#endif
 #ifdef HAVE_FREEBSD
 #include <sys/param.h>
 #include <sys/sysctl.h>
@@ -175,7 +180,7 @@ enum
 
 static void subject_iface_init (PolkitSubjectIface *subject_iface);
 
-static guint64 get_start_time_for_pid (gint    pid,
+static guint64 get_start_time_for_pid (pid_t    pid,
                                        GError **error);
 
 #if defined(HAVE_FREEBSD) || defined(HAVE_NETBSD) || defined(HAVE_OPENBSD)
