--- deps/v8/src/base/platform/platform-posix.cc.orig	2020-09-22 02:22:10 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -972,6 +972,7 @@ void Thread::SetThreadLocal(LocalStorage
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) && !defined(_AIX) && \
     !defined(V8_OS_SOLARIS)
+#if !defined(V8_OS_DRAGONFLYBSD)
 
 // static
 void* Stack::GetStackStart() {
@@ -997,6 +998,7 @@ void* Stack::GetStackStart() {
   return nullptr;
 }
 
+#endif  // !defined(V8_OS_DRAGONFLYBSD)
 #endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) &&
         // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
