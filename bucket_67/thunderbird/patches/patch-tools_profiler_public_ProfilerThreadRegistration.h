--- tools/profiler/public/ProfilerThreadRegistration.h.orig	2023-07-07 14:39:17 UTC
+++ tools/profiler/public/ProfilerThreadRegistration.h
@@ -214,14 +214,14 @@ class ThreadRegistration {
       DataLock mDataLock;
     };
 
-    [[nodiscard]] RWOnThreadWithLock LockedRWOnThread() {
+    [[nodiscard]] RWOnThreadWithLock GetLockedRWOnThread() {
       return RWOnThreadWithLock{mThreadRegistration->mData,
                                 mThreadRegistration->mDataMutex};
     }
 
     template <typename F>
     auto WithLockedRWOnThread(F&& aF) {
-      RWOnThreadWithLock lockedData = LockedRWOnThread();
+      RWOnThreadWithLock lockedData = GetLockedRWOnThread();
       return std::forward<F>(aF)(lockedData.DataRef());
     }
 
