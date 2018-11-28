$NetBSD: patch-js_src_threading_posix_Thread.cpp,v 1.1 2018/05/11 19:18:35 jperkin Exp $

Support SunOS.

--- threading/posix/Thread.cpp.orig	2017-04-11 02:13:21 UTC
+++ threading/posix/Thread.cpp
@@ -159,6 +159,8 @@ js::ThisThread::SetName(const char* name
   rv = 0;
 #elif defined(__NetBSD__)
   rv = pthread_setname_np(pthread_self(), "%s", (void*)name);
+#elif defined(__sun)
+  rv = 0;
 #else
   rv = pthread_setname_np(pthread_self(), name);
 #endif
