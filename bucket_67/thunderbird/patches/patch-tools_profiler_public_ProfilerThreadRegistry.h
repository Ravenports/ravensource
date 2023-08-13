--- tools/profiler/public/ProfilerThreadRegistry.h.orig	2023-07-07 14:39:18 UTC
+++ tools/profiler/public/ProfilerThreadRegistry.h
@@ -177,14 +177,14 @@ class ThreadRegistry {
       ThreadRegistration::DataLock mDataLock;
     };
 
-    [[nodiscard]] RWFromAnyThreadWithLock LockedRWFromAnyThread() {
+    [[nodiscard]] RWFromAnyThreadWithLock GetLockedRWFromAnyThread() {
       return RWFromAnyThreadWithLock{mThreadRegistration->mData,
                                      mThreadRegistration->mDataMutex};
     }
 
     template <typename F>
     auto WithLockedRWFromAnyThread(F&& aF) {
-      RWFromAnyThreadWithLock lockedData = LockedRWFromAnyThread();
+      RWFromAnyThreadWithLock lockedData = GetLockedRWFromAnyThread();
       return std::forward<F>(aF)(lockedData.DataRef());
     }
 
