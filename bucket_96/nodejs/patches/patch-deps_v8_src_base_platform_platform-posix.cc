--- deps/v8/src/base/platform/platform-posix.cc.orig	2021-09-22 18:38:21 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -1031,6 +1031,7 @@ void Thread::SetThreadLocal(LocalStorage
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) && !defined(_AIX) && \
     !defined(V8_OS_SOLARIS)
+#if !defined(V8_OS_DRAGONFLYBSD)
 
 // static
 Stack::StackSlot Stack::GetStackStart() {
@@ -1056,6 +1057,7 @@ Stack::StackSlot Stack::GetStackStart()
 #endif  // !defined(V8_LIBC_GLIBC)
 }
 
+#endif  // !defined(V8_OS_DRAGONFLYBSD)
 #endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) &&
         // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
