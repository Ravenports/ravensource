--- libshiboken/helper.h.orig	2025-05-30 11:57:51 UTC
+++ libshiboken/helper.h
@@ -70,7 +70,11 @@ class ArrayPointer
 template <class T>
 using AutoArrayPointer = ArrayPointer<T>; // deprecated
 
+#if defined(__FreeBSD__)
+using ThreadId = pthread_t;
+#else
 using ThreadId = unsigned long long;
+#endif
 LIBSHIBOKEN_API ThreadId currentThreadId();
 LIBSHIBOKEN_API ThreadId mainThreadId();
 
