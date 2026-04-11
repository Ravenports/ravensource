--- Foundation/src/Thread_POSIX.cpp.intermediate	2026-04-11 19:02:50 UTC
+++ Foundation/src/Thread_POSIX.cpp
@@ -40,6 +40,7 @@
 #	if !defined(__EXTENSIONS__)
 #		define __EXTENSIONS__
 #	endif
+#	include <pthread.h>
 #endif
 #if POCO_OS == POCO_OS_LINUX || POCO_OS == POCO_OS_ANDROID || POCO_OS == POCO_OS_MAC_OS_X || POCO_OS == POCO_OS_QNX
 #	include <time.h>
@@ -404,6 +405,8 @@ void ThreadImpl::setCurrentNameImpl(cons
 		#endif
 	#elif (POCO_OS == POCO_OS_QNX)
 		pthread_setname_np(pthread_self(), truncateName(threadName, _NTO_THREAD_NAME_MAX).c_str());
+        #elif defined(__sun)
+		pthread_setname_np(pthread_self(), truncateName(threadName).c_str());
 	#else
 		prctl(PR_SET_NAME, truncateName(threadName).c_str());
 	#endif
@@ -431,6 +434,8 @@ std::string ThreadImpl::getCurrentNameIm
 		#endif
 	#elif (POCO_OS == POCO_OS_QNX)
 		pthread_getname_np(pthread_self(), name, nameSize);
+	#elif defined (__sun)
+		pthread_getname_np(pthread_self(), name, nameSize);
 	#else
 		prctl(PR_GET_NAME, name);
 	#endif
