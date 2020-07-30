Fix SunOS includes.
Fix pid_t type.

--- src/polkit/polkitunixprocess.c.orig	2019-05-03 11:41:10 UTC
+++ src/polkit/polkitunixprocess.c
@@ -24,6 +24,11 @@
 #endif
 
 #include <sys/types.h>
+#ifdef HAVE_SOLARIS
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <procfs.h>
+#endif
 #ifdef HAVE_FREEBSD
 #include <sys/param.h>
 #include <sys/sysctl.h>
@@ -164,7 +169,7 @@ enum
 
 static void subject_iface_init (PolkitSubjectIface *subject_iface);
 
-static guint64 get_start_time_for_pid (gint    pid,
+static guint64 get_start_time_for_pid (pid_t    pid,
                                        GError **error);
 
 #if defined(HAVE_FREEBSD) || defined(HAVE_NETBSD) || defined(HAVE_OPENBSD)
