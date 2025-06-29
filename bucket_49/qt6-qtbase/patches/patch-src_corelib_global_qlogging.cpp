--- src/corelib/global/qlogging.cpp.orig	2025-05-28 10:22:57 UTC
+++ src/corelib/global/qlogging.cpp
@@ -102,6 +102,12 @@ static int qt_gettid()
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
