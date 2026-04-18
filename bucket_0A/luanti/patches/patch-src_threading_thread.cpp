--- src/threading/thread.cpp.orig	2026-02-08 11:42:38 UTC
+++ src/threading/thread.cpp
@@ -33,6 +33,8 @@ DEALINGS IN THE SOFTWARE.
 	#include <sys/prctl.h>
 #elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 	#include <pthread_np.h>
+#elif defined(__sun)
+	#include <pthread.h>
 #elif defined(__NetBSD__)
 	#include <sched.h>
 #elif defined(_MSC_VER)
@@ -221,6 +223,10 @@ void Thread::setName(const std::string &
 
 	pthread_set_name_np(pthread_self(), name.c_str());
 
+#elif defined(__sun)
+
+	pthread_setname_np(pthread_self(), name.c_str());
+
 #elif defined(__NetBSD__)
 
 	pthread_setname_np(pthread_self(), "%s", const_cast<char*>(name.c_str()));
@@ -295,7 +301,7 @@ bool Thread::bindToProcessor(unsigned in
 	return r == 0;
 #elif defined(__sun) || defined(sun)
 
-	return processor_bind(P_LWPID, P_MYID, proc_number, NULL) == 0
+	return processor_bind(P_LWPID, P_MYID, proc_number, NULL) == 0;
 
 #elif defined(_AIX)
 
