--- util/NativeStack.cpp.orig	2026-03-17 09:42:14 UTC
+++ util/NativeStack.cpp
@@ -17,6 +17,9 @@
 #  if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #    include <pthread_np.h>
 #  endif
+#  if defined(__sun)
+#    include <thread.h>
+#  endif
 #  if defined(SOLARIS) || defined(AIX)
 #    include <ucontext.h>
 #  endif
@@ -139,6 +142,8 @@ void* js::GetNativeStackBaseImpl() {
   pthread_attr_init(&sattr);
 #    if defined(__OpenBSD__)
   stack_t ss;
+#    elif defined (__sun)
+  stack_t ss;
 #    elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
   /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
   pthread_attr_get_np(thread, &sattr);
@@ -158,6 +163,10 @@ void* js::GetNativeStackBaseImpl() {
   rc = pthread_stackseg_np(pthread_self(), &ss);
   stackBase = (void*)((size_t)ss.ss_sp - ss.ss_size);
   stackSize = ss.ss_size;
+#    elif defined(__sun)
+  rc = thr_stksegment(&ss);
+  stackBase = ss.ss_sp;
+  stackSize = ss.ss_size;
 #    elif defined(ANDROID) && !defined(__aarch64__)
   if (gettid() == getpid()) {
     // bionic's pthread_attr_getstack prior to API 21 doesn't tell the truth
