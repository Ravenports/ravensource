--- libshiboken/helper.cpp.orig	2025-11-18 11:43:26 UTC
+++ libshiboken/helper.cpp
@@ -24,6 +24,14 @@
 #  include <pthread.h>
 #endif
 
+#if defined(__DragonFly__)
+#  include <sys/syscall.h>
+#endif
+
+#if defined(__NetBSD__)
+#  include <lwp.h>
+#endif
+
 static std::optional<std::string> getStringAttr(PyObject *obj, const char *what)
 {
     if (PyObject_HasAttrString(obj, what) != 0) { // Check first to suppress error.
@@ -602,6 +610,10 @@ ThreadId currentThreadId()
     return GetCurrentThreadId();
 #elif defined(__APPLE_CC__)
     return reinterpret_cast<ThreadId>(pthread_self());
+#elif defined(__DragonFly__)
+    return syscall(SYS_lwp_gettid);
+#elif defined(__NetBSD__)
+    return reinterpret_cast<ThreadId>(_lwp_self());
 #else
     return pthread_self();
 #endif
