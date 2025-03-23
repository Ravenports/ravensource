--- Foundation/src/Thread_POSIX.cpp.orig	2025-02-12 17:01:49 UTC
+++ Foundation/src/Thread_POSIX.cpp
@@ -24,7 +24,13 @@
 
 
 #if POCO_OS == POCO_OS_FREE_BSD
+# if defined(__DragonFly__)
+#    include <sys/syscall.h>
+#    include <unistd.h>
+# endif
+# if defined(__FreeBSD__)
 #    include <sys/thr.h>
+# endif
 #    include <pthread_np.h>
 #    include <osreldate.h>
 #endif
@@ -414,7 +420,11 @@ long ThreadImpl::currentOsTidImpl()
 #elif POCO_OS == POCO_OS_MAC_OS_X
 	id = ::pthread_mach_thread_np(::pthread_self());
 #elif POCO_OS == POCO_OS_FREE_BSD
+# if defined(__DragonFly__)
+	id = syscall(SYS_lwp_gettid);
+# else
 	if (0 != thr_self(&id)) id = 0;
+# endif
 #endif
 	return id;
 }
