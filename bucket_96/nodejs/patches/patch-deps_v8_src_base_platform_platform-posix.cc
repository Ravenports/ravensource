--- deps/v8/src/base/platform/platform-posix.cc.orig	2021-03-03 05:40:17 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -1012,6 +1012,7 @@ void Thread::SetThreadLocal(LocalStorage
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) && !defined(_AIX) && \
     !defined(V8_OS_SOLARIS)
+#if !defined(V8_OS_DRAGONFLYBSD)
 
 // static
 void* Stack::GetStackStart() {
@@ -1037,6 +1038,7 @@ void* Stack::GetStackStart() {
   return nullptr;
 }
 
+#endif  // !defined(V8_OS_DRAGONFLYBSD)
 #endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) &&
         // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
