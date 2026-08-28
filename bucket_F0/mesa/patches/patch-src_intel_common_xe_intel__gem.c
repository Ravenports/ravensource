--- src/intel/common/xe/intel_gem.c.orig	2026-08-05 21:14:26 UTC
+++ src/intel/common/xe/intel_gem.c
@@ -74,7 +74,7 @@ xe_gem_read_correlate_cpu_gpu_timestamp(
    case CLOCK_MONOTONIC_RAW:
 #endif
    case CLOCK_REALTIME:
-#ifdef CLOCK_BOOTTIME
+#if defined(CLOCK_BOOTTIME) && CLOCK_BOOTTIME != CLOCK_MONOTONIC
    case CLOCK_BOOTTIME:
 #endif
 #ifdef CLOCK_TAI
