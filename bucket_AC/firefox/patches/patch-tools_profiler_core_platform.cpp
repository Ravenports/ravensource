--- tools/profiler/core/platform.cpp.orig	2026-04-17 17:48:12 UTC
+++ tools/profiler/core/platform.cpp
@@ -7781,6 +7781,7 @@ void profiler_mark_thread_awake() {
   }
 #    endif
 #  else
+#  elsif !defined(__MidnightBSD__)
   cpuId = sched_getcpu();
 #  endif
 #endif
