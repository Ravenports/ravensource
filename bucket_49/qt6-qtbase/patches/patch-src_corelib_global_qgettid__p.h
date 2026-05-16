--- src/corelib/global/qgettid_p.h.orig	2026-05-07 07:50:01 UTC
+++ src/corelib/global/qgettid_p.h
@@ -41,6 +41,12 @@ static inline int qt_gettid()
     pthread_threadid_np(NULL, &tid);
     return tid;
 }
+#elif defined __MidnightBSD__
+#  include <pthread_np.h>
+static inline int qt_gettid()
+{
+    return pthread_getthreadid_np();
+}
 #elif defined(Q_OS_FREEBSD_KERNEL) && defined(__FreeBSD_version) && __FreeBSD_version >= 900031
 #  include <pthread_np.h>
 static inline int qt_gettid()
