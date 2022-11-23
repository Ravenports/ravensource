--- deps/v8/src/base/platform/platform-posix.cc.orig	2022-11-14 02:26:05 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -54,7 +54,9 @@
 #include <mach/mach.h>
 #include <malloc/malloc.h>
 #else
+# if !V8_OS_FREEBSD && !V8_OS_DRAGONFLYBSD
 #include <malloc.h>
+# endif
 #endif
 
 #if V8_OS_LINUX
@@ -71,7 +73,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_OPENBSD || V8_OS_SOLARIS
+#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_OPENBSD || V8_OS_SOLARIS || V8_OS_DRAGONFLYBSD
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
@@ -133,7 +135,7 @@ int GetFlagsForMemoryPermission(OS::Memo
   int flags = MAP_ANONYMOUS;
   flags |= (page_type == PageType::kShared) ? MAP_SHARED : MAP_PRIVATE;
   if (access == OS::MemoryPermission::kNoAccess) {
-#if !V8_OS_AIX && !V8_OS_FREEBSD && !V8_OS_QNX
+#if !V8_OS_AIX && !V8_OS_FREEBSD && !V8_OS_QNX && !V8_OS_DRAGONFLYBSD
     flags |= MAP_NORESERVE;
 #endif  // !V8_OS_AIX && !V8_OS_FREEBSD && !V8_OS_QNX
 #if V8_OS_QNX
@@ -1064,8 +1066,13 @@ Thread::Thread(const Options& options)
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
 
@@ -1080,7 +1087,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   static_assert(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif V8_OS_DARWIN
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
@@ -1228,6 +1235,7 @@ void Thread::SetThreadLocal(LocalStorage
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) && !defined(_AIX) && \
     !defined(V8_OS_SOLARIS)
+#if !defined(V8_OS_DRAGONFLYBSD)
 
 // static
 Stack::StackSlot Stack::GetStackStart() {
@@ -1253,6 +1261,7 @@ Stack::StackSlot Stack::GetStackStart()
 #endif  // !defined(V8_LIBC_GLIBC)
 }
 
+#endif  // !defined(V8_OS_DRAGONFLYBSD)
 #endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) &&
         // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
