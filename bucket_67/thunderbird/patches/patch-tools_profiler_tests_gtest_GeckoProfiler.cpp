--- tools/profiler/tests/gtest/GeckoProfiler.cpp.orig	2023-07-07 14:39:18 UTC
+++ tools/profiler/tests/gtest/GeckoProfiler.cpp
@@ -621,7 +621,7 @@ TEST(GeckoProfiler, ThreadRegistration_D
       EXPECT_FALSE(TR::IsDataMutexLockedOnCurrentThread());
       {
         TR::OnThreadRef::RWOnThreadWithLock rwOnThreadWithLock =
-            aOnThreadRef.LockedRWOnThread();
+            aOnThreadRef.GetLockedRWOnThread();
         EXPECT_TRUE(TR::IsDataMutexLockedOnCurrentThread());
         TestConstLockedRWOnThread(rwOnThreadWithLock.DataCRef(),
                                   beforeRegistration, afterRegistration,
@@ -1020,7 +1020,7 @@ TEST(GeckoProfiler, ThreadRegistry_DataA
         EXPECT_FALSE(TR::IsDataMutexLockedOnCurrentThread());
         {
           TRy::OffThreadRef::RWFromAnyThreadWithLock rwFromAnyThreadWithLock =
-              aOffThreadRef.LockedRWFromAnyThread();
+              aOffThreadRef.GetLockedRWFromAnyThread();
           if (profiler_current_thread_id() == testThreadId) {
             EXPECT_TRUE(TR::IsDataMutexLockedOnCurrentThread());
           }
@@ -1157,7 +1157,7 @@ TEST(GeckoProfiler, ThreadRegistration_R
             PR_Sleep(PR_MillisecondsToInterval(1));
           }
           TRy::OffThreadRef::RWFromAnyThreadWithLock rwFromAnyThreadWithLock =
-              aOffThreadRef.LockedRWFromAnyThread();
+              aOffThreadRef.GetLockedRWFromAnyThread();
           ++otherThreadReads;
           if (otherThreadReads % 1000 == 0) {
             PR_Sleep(PR_MillisecondsToInterval(1));
