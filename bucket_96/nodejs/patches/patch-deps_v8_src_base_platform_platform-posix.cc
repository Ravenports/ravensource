--- deps/v8/src/base/platform/platform-posix.cc.orig	2020-06-30 17:49:16 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -971,6 +971,7 @@ void Thread::SetThreadLocal(LocalStorage
 // keep this version in POSIX as most Linux-compatible derivatives will
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) && !defined(V8_OS_SOLARIS)
+#if !defined(V8_OS_DRAGONFLYBSD)
 
 // static
 void* Stack::GetStackStart() {
@@ -996,6 +997,7 @@ void* Stack::GetStackStart() {
   return nullptr;
 }
 
+#endif  // !defined(V8_OS_DRAGONFLYBSD)
 #endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) && !defined(V8_OS_SOLARIS)
 
 // static
