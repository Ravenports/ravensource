--- libshiboken/helper.h.orig	2025-11-18 11:43:26 UTC
+++ libshiboken/helper.h
@@ -69,7 +69,13 @@ class ArrayPointer
 template <class T>
 using AutoArrayPointer = ArrayPointer<T>; // deprecated
 
+#if defined(__FreeBSD__)
+using ThreadId = pthread_t;
+#elif defined(__NetBSD__)
+using ThreadId = int;
+#else
 using ThreadId = unsigned long long;
+#endif
 LIBSHIBOKEN_API ThreadId currentThreadId();
 LIBSHIBOKEN_API ThreadId mainThreadId();
 
