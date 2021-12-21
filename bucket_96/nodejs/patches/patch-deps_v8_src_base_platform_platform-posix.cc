--- deps/v8/src/base/platform/platform-posix.cc.orig	2021-12-17 21:21:07 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -840,8 +840,13 @@ Thread::Thread(const Options& options)
     : data_(new PlatformData),
       stack_size_(options.stack_size()),
       start_semaphore_(nullptr) {
+#if V8_OS_NETBSD
+  if (stack_size_ > 0 && static_cast<size_t>(stack_size_) < sysconf(_SC_THREAD_STACK_MIN)) {
+    stack_size_ = sysconf(_SC_THREAD_STACK_MIN);
+#else
   if (stack_size_ > 0 && static_cast<size_t>(stack_size_) < PTHREAD_STACK_MIN) {
     stack_size_ = PTHREAD_STACK_MIN;
+#endif
   }
   set_name(options.name());
 }
@@ -857,7 +862,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   STATIC_ASSERT(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif V8_OS_MACOSX
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
@@ -1055,6 +1060,7 @@ void Thread::SetThreadLocal(LocalStorage
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) && !defined(_AIX) && \
     !defined(V8_OS_SOLARIS)
+#if !defined(V8_OS_DRAGONFLYBSD)
 
 // static
 Stack::StackSlot Stack::GetStackStart() {
@@ -1080,6 +1086,7 @@ Stack::StackSlot Stack::GetStackStart()
 #endif  // !defined(V8_LIBC_GLIBC)
 }
 
+#endif  // !defined(V8_OS_DRAGONFLYBSD)
 #endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) &&
         // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
