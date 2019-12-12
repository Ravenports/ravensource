--- threading/posix/Thread.cpp.orig	2019-09-01 13:09:20 UTC
+++ threading/posix/Thread.cpp
@@ -160,6 +160,8 @@ void js::ThisThread::SetName(const char*
   rv = 0;
 #elif defined(__NetBSD__)
   rv = pthread_setname_np(pthread_self(), "%s", (void*)name);
+#elif defined(__sun__)
+  rv = 0;
 #else
   rv = pthread_setname_np(pthread_self(), name);
 #endif
