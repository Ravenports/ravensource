--- src/ProcessResolver.cpp.orig	2024-12-06 16:07:53 UTC
+++ src/ProcessResolver.cpp
@@ -5,6 +5,11 @@
 
 #include "ProcessResolver.h"
 #include <cstring>
+#if defined(__DragonFly__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
 
 ProcessResolver::ProcessResolver(bool resolveImmediately) : m_processMap() {
 	if (resolveImmediately) {
@@ -199,7 +204,18 @@ void ProcessResolver::doResolve() {
 
 void ProcessResolver::doResolve() {
 	int n_procs;
+#  if defined(__DragonFly__)
+	size_t len;
+	struct kinfo_proc *procs_info;
+	sysctlbyname ("kern.proc.all", NULL, &len, NULL, 0);
+        procs_info = (struct kinfo_proc *) malloc (len);
+	if (sysctlbyname ("kern.proc.all", procs_info, &len, NULL, 0)) {
+		free(procs_info);
+		return;
+	}
+#  else
 	struct kinfo_proc *procs_info = kinfo_getallproc(&n_procs);
+#  endif
 	if (!procs_info) {
 #	ifndef QT_NO_DEBUG
 		qCritical("ProcessResolver: kinfo_getallproc() failed\n");
@@ -208,7 +224,11 @@ void ProcessResolver::doResolve() {
 	}
 
 	for (int i = 0; i < n_procs; ++i) {
+#  if defined(__DragonFly__)
+		addEntry(static_cast< uint64_t >(procs_info[i].kp_pid), procs_info[i].kp_comm, m_processMap);
+#  else
 		addEntry(static_cast< uint64_t >(procs_info[i].ki_pid), procs_info[i].ki_comm, m_processMap);
+#  endif
 	}
 
 	free(procs_info);
