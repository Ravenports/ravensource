--- Foundation/src/Thread_POSIX.cpp.orig	2026-03-24 10:38:30 UTC
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
@@ -34,6 +40,7 @@
 #	if !defined(__EXTENSIONS__)
 #		define __EXTENSIONS__
 #	endif
+#      include <pthread.h>
 #endif
 #if POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_ANDROID || POCO_OS == POCO_OS_MAC_OS_X || POCO_OS == POCO_OS_QNX
 #	include <time.h>
@@ -362,7 +369,11 @@ long ThreadImpl::currentOsTidImpl()
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
@@ -394,6 +405,8 @@ void ThreadImpl::setCurrentNameImpl(cons
 		#endif
 	#elif (POCO_OS == POCO_OS_QNX)
 		pthread_setname_np(pthread_self(), truncateName(threadName, _NTO_THREAD_NAME_MAX).c_str());
+	#elif defined(__sun)
+		pthread_setname_np(pthread_self(), truncateName(threadName).c_str());
 	#else
 		prctl(PR_SET_NAME, truncateName(threadName).c_str());
 	#endif
@@ -421,6 +434,8 @@ std::string ThreadImpl::getCurrentNameIm
 		#endif
 	#elif (POCO_OS == POCO_OS_QNX)
 		pthread_getname_np(pthread_self(), name, nameSize);
+	#elif defined (__sun)
+		pthread_getname_np(pthread_self(), name, nameSize);
 	#else
 		prctl(PR_GET_NAME, name);
 	#endif
