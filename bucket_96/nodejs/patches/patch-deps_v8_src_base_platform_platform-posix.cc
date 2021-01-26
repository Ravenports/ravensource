--- deps/v8/src/base/platform/platform-posix.cc.orig	2021-01-25 23:04:44 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -1002,6 +1002,7 @@ void Thread::SetThreadLocal(LocalStorage
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) && !defined(_AIX) && \
     !defined(V8_OS_SOLARIS)
+#if !defined(V8_OS_DRAGONFLYBSD)
 
 // static
 void* Stack::GetStackStart() {
@@ -1027,6 +1028,7 @@ void* Stack::GetStackStart() {
   return nullptr;
 }
 
+#endif  // !defined(V8_OS_DRAGONFLYBSD)
 #endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) &&
         // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
