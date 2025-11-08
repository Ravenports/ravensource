--- hwy/contrib/thread_pool/thread_pool.h.orig	2025-08-14 07:25:53 UTC
+++ hwy/contrib/thread_pool/thread_pool.h
@@ -63,7 +63,7 @@ static inline void SetThreadName(const c
 #if HWY_OS_LINUX && (!defined(__ANDROID__) || __ANDROID_API__ >= 19)
   HWY_ASSERT(0 == pthread_setname_np(pthread_self(), buf));
 #elif HWY_OS_FREEBSD
-  HWY_ASSERT(0 == pthread_set_name_np(pthread_self(), buf));
+  HWY_ASSERT(0 == pthread_setname_np(pthread_self(), buf));
 #elif HWY_OS_APPLE
   // Different interface: single argument, current thread only.
   HWY_ASSERT(0 == pthread_setname_np(buf));
