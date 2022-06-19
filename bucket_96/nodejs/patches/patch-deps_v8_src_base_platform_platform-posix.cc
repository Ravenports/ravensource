--- deps/v8/src/base/platform/platform-posix.cc.orig	2022-06-16 12:18:00 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -1000,8 +1000,13 @@ Thread::Thread(const Options& options)
     : data_(new PlatformData),
       stack_size_(options.stack_size()),
       start_semaphore_(nullptr) {
+#if V8_OS_NETBSD
+  if (stack_size_ > 0 && static_cast<size_t>(stack_size_) < sysconf(_SC_THREAD_STACK_MIN))
+      stack_size_ = sysconf(_SC_THREAD_STACK_MIN);
+#else
   const int min_stack_size = static_cast<int>(PTHREAD_STACK_MIN);
   if (stack_size_ > 0) stack_size_ = std::max(stack_size_, min_stack_size);
+#endif
   set_name(options.name());
 }
 
@@ -1016,7 +1021,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   STATIC_ASSERT(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif V8_OS_DARWIN
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
@@ -1214,6 +1219,7 @@ void Thread::SetThreadLocal(LocalStorage
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) && !defined(_AIX) && \
     !defined(V8_OS_SOLARIS)
+#if !defined(V8_OS_DRAGONFLYBSD)
 
 // static
 Stack::StackSlot Stack::GetStackStart() {
@@ -1239,6 +1245,7 @@ Stack::StackSlot Stack::GetStackStart()
 #endif  // !defined(V8_LIBC_GLIBC)
 }
 
+#endif  // !defined(V8_OS_DRAGONFLYBSD)
 #endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) &&
         // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
