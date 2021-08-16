--- deps/v8/src/base/platform/platform-posix.cc.orig	2021-08-11 02:13:12 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -1016,6 +1016,7 @@ void Thread::SetThreadLocal(LocalStorage
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) && !defined(_AIX) && \
     !defined(V8_OS_SOLARIS)
+#if !defined(V8_OS_DRAGONFLYBSD)
 
 // static
 Stack::StackSlot Stack::GetStackStart() {
@@ -1040,6 +1041,7 @@ Stack::StackSlot Stack::GetStackStart()
   return nullptr;
 }
 
+#endif  // !defined(V8_OS_DRAGONFLYBSD)
 #endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) &&
         // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
