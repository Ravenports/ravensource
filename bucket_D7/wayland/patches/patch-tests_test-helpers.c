diff --git tests/test-helpers.c tests/test-helpers.c
index b2189d8..7cf47f2 100644
--- tests/test-helpers.c
+++ tests/test-helpers.c
@@ -25,6 +25,16 @@
 
 #include "config.h"
 
+#include "../config.h"
+
+#ifdef USE_LIBKVM
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <fcntl.h>
+#include <kvm.h>
+#include <limits.h>
+#endif
+
 #include <assert.h>
 #include <errno.h>
 #include <dirent.h>
@@ -43,6 +53,29 @@
 int
 count_open_fds(void)
 {
+#ifdef USE_LIBKVM
+	/* Use BSD-specific kernel memory interface */
+
+	struct kinfo_proc *kp;
+	kvm_t *kd;
+	int count;
+	char errstr[_POSIX2_LINE_MAX];
+
+	kd = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, errstr);
+	assert(kd != NULL);
+#ifdef __OpenBSD__
+	kp = kvm_getprocs(kd, KERN_PROC_PID, getpid(), sizeof(*kp), &count);
+#else
+	kp = kvm_getprocs(kd, KERN_PROC_PID, getpid(), &count);
+#endif
+	assert(kp != NULL);
+
+	/* KVM library frees memory on itself */
+	kvm_close(kd);
+	return count;
+#else
+	/* Use /proc filesystem. */
+
 	DIR *dir;
 	struct dirent *ent;
 	int count = 0;
@@ -62,6 +95,7 @@ count_open_fds(void)
 	closedir(dir);
 
 	return count;
+#endif
 }
 
 void
