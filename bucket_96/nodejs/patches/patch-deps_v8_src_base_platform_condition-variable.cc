--- deps/v8/src/base/platform/condition-variable.cc.orig	2025-02-13 11:53:50 UTC
+++ deps/v8/src/base/platform/condition-variable.cc
@@ -20,6 +20,7 @@ namespace base {
 
 ConditionVariable::ConditionVariable() {
 #if (V8_OS_FREEBSD || V8_OS_NETBSD || V8_OS_OPENBSD || \
+     V8_OS_DRAGONFLYBSD || \
      (V8_OS_LINUX && V8_LIBC_GLIBC))
   // On Free/Net/OpenBSD and Linux with glibc we can change the time
   // source for pthread_cond_timedwait() to use the monotonic clock.
