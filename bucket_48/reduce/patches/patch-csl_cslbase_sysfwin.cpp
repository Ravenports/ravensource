--- csl/cslbase/sysfwin.cpp.orig	2023-09-20 08:45:28 UTC
+++ csl/cslbase/sysfwin.cpp
@@ -759,13 +759,18 @@ uint64_t read_clock_cycles()
     QueryThreadCycleTime(GetCurrentThread(), &tt);
     return static_cast<uint64_t>(
         (tt - threadClockBase)*clock_cycle_calibration);
-#else // Windows
+#elif defined __linux__
 // There is no tidy guarantee about the resolution of the clock used
 // here on any particular platform.
     struct std::timespec tt;
     clock_gettime(CLOCK_MONOTONIC_RAW, &tt);
     return 1.0e9*static_cast<double>(tt.tv_sec) +
            static_cast<double>(tt.tv_nsec);
+#else
+    struct std::timespec tt;
+    clock_gettime(CLOCK_MONOTONIC, &tt);
+    return 1.0e9*static_cast<double>(tt.tv_sec) +
+           static_cast<double>(tt.tv_nsec);
 #endif // Windows
 }
 
