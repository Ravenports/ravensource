--- absl/debugging/stacktrace.cc.orig	2025-06-17 14:48:08 UTC
+++ absl/debugging/stacktrace.cc
@@ -61,7 +61,7 @@
 #include <alloca.h>
 #define ABSL_INTERNAL_HAVE_ALLOCA 1
 #elif !defined(alloca)
-static void* alloca(size_t) noexcept { return nullptr; }
+static void* __builtin_alloca(size_t) noexcept { return nullptr; }
 #endif
 #endif
 #endif
@@ -158,8 +158,8 @@ ABSL_ATTRIBUTE_NOINLINE ABSL_ATTRIBUTE_N
     if constexpr (kHaveAlloca) {
       const size_t nmax = static_cast<size_t>(max_depth);
       uintptr_t* frames =
-          static_cast<uintptr_t*>(alloca(nmax * sizeof(*frames)));
-      int* sizes = static_cast<int*>(alloca(nmax * sizeof(*sizes)));
+          static_cast<uintptr_t*>(__builtin_alloca(nmax * sizeof(*frames)));
+      int* sizes = static_cast<int*>(__builtin_alloca(nmax * sizeof(*sizes)));
       size_t depth = static_cast<size_t>(Unwind<true, false>(
           result, frames, sizes, max_depth, skip_count, nullptr, nullptr));
       internal_stacktrace::FixUpStack(result, frames, sizes, nmax, depth);
@@ -178,8 +178,8 @@ GetStackTraceWithContext(void** result,
     if constexpr (kHaveAlloca) {
       const size_t nmax = static_cast<size_t>(max_depth);
       uintptr_t* frames =
-          static_cast<uintptr_t*>(alloca(nmax * sizeof(*frames)));
-      int* sizes = static_cast<int*>(alloca(nmax * sizeof(*sizes)));
+          static_cast<uintptr_t*>(__builtin_alloca(nmax * sizeof(*frames)));
+      int* sizes = static_cast<int*>(__builtin_alloca(nmax * sizeof(*sizes)));
       size_t depth = static_cast<size_t>(
           Unwind<true, true>(result, frames, sizes, max_depth, skip_count, uc,
                              min_dropped_frames));
