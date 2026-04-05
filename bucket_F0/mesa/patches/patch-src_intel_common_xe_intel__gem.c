--- src/intel/common/xe/intel_gem.c.orig	2026-03-18 15:54:10 UTC
+++ src/intel/common/xe/intel_gem.c
@@ -71,7 +71,7 @@ xe_gem_read_correlate_cpu_gpu_timestamp(
    case CLOCK_MONOTONIC_RAW:
 #endif
    case CLOCK_REALTIME:
-#ifdef CLOCK_BOOTTIME
+#if defined(CLOCK_BOOTTIME) && CLOCK_BOOTTIME != CLOCK_MONOTONIC
    case CLOCK_BOOTTIME:
 #endif
 #ifdef CLOCK_TAI
