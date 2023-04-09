--- src/corelib/global/qlogging.cpp.orig	2023-03-14 08:29:43 UTC
+++ src/corelib/global/qlogging.cpp
@@ -103,6 +103,12 @@ static int qt_gettid()
     pthread_threadid_np(NULL, &tid);
     return tid;
 }
+#elif defined __MidnightBSD__
+#  include <pthread_np.h>
+static int qt_gettid()
+{
+    return pthread_getthreadid_np();
+}
 #elif defined(Q_OS_FREEBSD_KERNEL) && defined(__FreeBSD_version) && __FreeBSD_version >= 900031
 #  include <pthread_np.h>
 static int qt_gettid()
