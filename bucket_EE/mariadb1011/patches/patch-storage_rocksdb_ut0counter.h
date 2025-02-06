--- storage/rocksdb/ut0counter.h.orig	2025-01-30 11:01:25 UTC
+++ storage/rocksdb/ut0counter.h
@@ -30,6 +30,12 @@ Created 2012/04/12 by Sunny Bains
 
 #ifdef _WIN32
 #define get_curr_thread_id() GetCurrentThreadId()
+#elif defined __FreeBSD__
+#include <pthread_np.h>
+#define get_curr_thread_id() pthread_getthreadid_np()
+#elif defined __DragonFly__
+#include <sys/syscall.h>
+#define get_curr_thread_id() syscall(SYS_lwp_gettid)
 #else
 #define get_curr_thread_id() pthread_self()
 #endif
