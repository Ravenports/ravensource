--- hwy/contrib/thread_pool/thread_pool.h.orig	2025-10-16 11:15:22.943963000 +0200
+++ hwy/contrib/thread_pool/thread_pool.h	2025-10-16 11:32:12.701406000 +0200
@@ -30,11 +30,6 @@
 #include <thread>  // NOLINT
 #include <vector>
 
-#include "hwy/detect_compiler_arch.h"
-#if HWY_OS_FREEBSD
-#include <pthread_np.h>
-#endif
-
 #include "hwy/aligned_allocator.h"  // HWY_ALIGNMENT
 #include "hwy/auto_tune.h"
 #include "hwy/base.h"
@@ -60,10 +55,9 @@
   HWY_ASSERT(0 < chars_written &&
              chars_written <= static_cast<int>(sizeof(buf) - 1));
 
-#if HWY_OS_LINUX && (!defined(__ANDROID__) || __ANDROID_API__ >= 19)
+#if (HWY_OS_LINUX && (!defined(__ANDROID__) || __ANDROID_API__ >= 19)) || \
+  HWY_OS_FREEBSD
   HWY_ASSERT(0 == pthread_setname_np(pthread_self(), buf));
-#elif HWY_OS_FREEBSD
-  HWY_ASSERT(0 == pthread_set_name_np(pthread_self(), buf));
 #elif HWY_OS_APPLE
   // Different interface: single argument, current thread only.
   HWY_ASSERT(0 == pthread_setname_np(buf));
