--- src/corelib/global/qgettid_p.h.orig	2025-11-12 10:17:57 UTC
+++ src/corelib/global/qgettid_p.h
@@ -40,6 +40,12 @@ static inline int qt_gettid()
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
