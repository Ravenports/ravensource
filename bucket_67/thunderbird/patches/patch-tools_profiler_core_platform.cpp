--- tools/profiler/core/platform.cpp.orig	2024-07-04 17:04:30 UTC
+++ tools/profiler/core/platform.cpp
@@ -7311,7 +7311,7 @@ void profiler_mark_thread_awake() {
     cpuId = ebx >> 24;
   }
 #  endif
-#else
+#elsif !defined(__MidnightBSD__)
   cpuId = sched_getcpu();
 #endif
 
