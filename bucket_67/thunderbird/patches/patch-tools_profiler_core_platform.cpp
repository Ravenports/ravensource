commit 45a7951cb6a9b1735b9b6cec89db69b5933715c7
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>
Date:   Mon Mar 28 21:54:35 2022 +0200

    FreeBSD can use sched_getcpu() from 1400046/1300524 on

File gcc13-fix.patch of Package MozillaThunderbird
https://build.opensuse.org/package/view_file/openSUSE:Factory/MozillaThunderbird/gcc13-fix.patch?expand=1

--- tools/profiler/core/platform.cpp.orig	2023-07-07 14:39:18 UTC
+++ tools/profiler/core/platform.cpp
@@ -115,6 +115,20 @@
 #  include <cpuid.h>
 #endif
 
+#if defined(GP_OS_freebsd)
+#include <sys/param.h>
+// "after making CPU_SET macros compatible with glibc"
+#  if __FreeBSD_version > 1400045 || (__FreeBSD_version > 1300523 && __FreeBSD_version < 1400000)
+#  include <sched.h>
+#  else
+#    if __x86_64__ || __i386__
+// similar cpuid_count() trick as on Darwin, using LLVM
+// but not for all CPUs
+#      include <cpuid.h>
+#    endif
+#  endif
+#endif
+
 #if defined(GP_OS_windows)
 #  include <processthreadsapi.h>
 
@@ -1106,7 +1120,7 @@ class ActivePS {
         continue;
       }
       ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock lockedThreadData =
-          offThreadRef.LockedRWFromAnyThread();
+          offThreadRef.GetLockedRWFromAnyThread();
       MOZ_RELEASE_ASSERT(array.append(ProfiledThreadListElement{
           profiledThreadData->Info().RegisterTime(),
           lockedThreadData->GetJSContext(), profiledThreadData}));
@@ -4050,7 +4064,7 @@ void SamplerThread::Run() {
 
             if (threadStackSampling) {
               ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock
-                  lockedThreadData = offThreadRef.LockedRWFromAnyThread();
+                  lockedThreadData = offThreadRef.GetLockedRWFromAnyThread();
               // Suspend the thread and collect its stack data in the local
               // buffer.
               mSampler.SuspendAndSampleAndResumeThread(
@@ -4764,7 +4778,7 @@ static ProfilingStack* locked_register_t
             aLock, aOffThreadRef.UnlockedConstReaderCRef().Info());
     if (threadProfilingFeatures != ThreadProfilingFeatures::NotProfiled) {
       ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock
-          lockedRWFromAnyThread = aOffThreadRef.LockedRWFromAnyThread();
+          lockedRWFromAnyThread = aOffThreadRef.GetLockedRWFromAnyThread();
 
       ProfiledThreadData* profiledThreadData = ActivePS::AddLiveProfiledThread(
           aLock, MakeUnique<ProfiledThreadData>(
@@ -5629,7 +5643,7 @@ static void locked_profiler_start(PSLock
         ActivePS::ProfilingFeaturesForThread(aLock, info);
     if (threadProfilingFeatures != ThreadProfilingFeatures::NotProfiled) {
       ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock lockedThreadData =
-          offThreadRef.LockedRWFromAnyThread();
+          offThreadRef.GetLockedRWFromAnyThread();
       ProfiledThreadData* profiledThreadData = ActivePS::AddLiveProfiledThread(
           aLock, MakeUnique<ProfiledThreadData>(info));
       lockedThreadData->SetProfilingFeaturesAndData(threadProfilingFeatures,
@@ -5853,7 +5867,7 @@ void profiler_ensure_started(PowerOfTwo3
     }
 
     ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock lockedThreadData =
-        offThreadRef.LockedRWFromAnyThread();
+        offThreadRef.GetLockedRWFromAnyThread();
 
     lockedThreadData->ClearProfilingFeaturesAndData(aLock);
 
@@ -6196,7 +6210,7 @@ static void locked_unregister_thread(
   // thread that is in the process of disappearing.
 
   ThreadRegistration::OnThreadRef::RWOnThreadWithLock lockedThreadData =
-      aOnThreadRef.LockedRWOnThread();
+      aOnThreadRef.GetLockedRWOnThread();
 
   ProfiledThreadData* profiledThreadData =
       lockedThreadData->GetProfiledThreadData(lock);
@@ -6520,6 +6534,19 @@ void profiler_mark_thread_awake() {
     cpuId = ebx >> 24;
   }
 #  endif
+#elif defined(GP_OS_freebsd) 
+#  if __FreeBSD_version > 1400045 || (__FreeBSD_version > 1300523 && __FreeBSD_version < 1400000)
+  cpuId = sched_getcpu();
+#  elif defined(__amd64__)
+  unsigned int eax, ebx, ecx, edx;
+  __cpuid_count(1, 0, eax, ebx, ecx, edx);
+  // Check if we have an APIC.
+  if ((edx & (1 << 9))) {
+    // APIC ID is bits 24-31 of EBX
+    cpuId = ebx >> 24;
+  }
+#  endif
+// the fallthrough is cpuID = 0
 #else
   cpuId = sched_getcpu();
 #endif
@@ -6717,7 +6744,7 @@ void profiler_clear_js_context() {
         // The profiler mutex must be locked before the ThreadRegistration's.
         PSAutoLock lock;
         ThreadRegistration::OnThreadRef::RWOnThreadWithLock lockedThreadData =
-            aOnThreadRef.LockedRWOnThread();
+            aOnThreadRef.GetLockedRWOnThread();
 
         if (ProfiledThreadData* profiledThreadData =
                 lockedThreadData->GetProfiledThreadData(lock);
