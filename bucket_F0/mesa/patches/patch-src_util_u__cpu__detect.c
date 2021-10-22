Segment runs on NetBSD and OpenBSD only

--- src/util/u_cpu_detect.c.orig	2021-09-29 20:10:17 UTC
+++ src/util/u_cpu_detect.c
@@ -601,7 +601,7 @@ util_cpu_detect_once(void)
    if (available_cpus == 0) {
       const int mib[] = { CTL_HW, HW_NCPUONLINE };
       int ncpu;
-      int len = sizeof(ncpu);
+      size_t len = sizeof(ncpu);
 
       sysctl(mib, 2, &ncpu, &len, NULL, 0);
       available_cpus = ncpu;
