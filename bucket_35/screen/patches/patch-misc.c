--- misc.c.orig	2025-05-15 15:31:27 UTC
+++ misc.c
@@ -34,6 +34,10 @@
 #include <sys/types.h>
 #include <sys/stat.h>		/* mkdir() declaration */
 #include <signal.h>
+#if defined(__FreeBSD__)
+#include <sys/user.h>
+#include <libutil.h>
+#endif
 #include <stdint.h>
 #include <string.h>
 #include <stdbool.h>
@@ -238,3 +242,19 @@ int AddXChars(char *buf, int len, char *
 	*p = 0;
 	return p - buf;
 }
+
+#if defined(__FreeBSD__)
+time_t
+SessionCreationTime(fifo)
+const char *fifo;
+{
+  int pid = atoi(fifo);
+  if (pid <= 0) return 0;
+
+  struct kinfo_proc * kip = kinfo_getproc(pid);
+  if (kip == 0) return 0;
+  time_t start = kip->ki_start.tv_sec;
+  free (kip);
+  return start;
+}
+#endif
