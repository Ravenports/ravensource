--- port/cpl_multiproc.cpp.orig	2025-11-07 23:18:14 UTC
+++ port/cpl_multiproc.cpp
@@ -1365,7 +1365,11 @@ int CPLGetNumCPUs()
     nCPUs = 1;
 #endif
 
-#ifdef HAVE_SCHED_GETAFFINITY
+#if defined(HAVE_SCHED_GETAFFINITY) \
+ && defined(CPU_ALLOC) \
+ && defined(CPU_ALLOC_SIZE) \
+ && defined(CPU_ZERO_S) \
+ && defined(CPU_COUNT_S)
     if (nCPUs > 1)
     {
         cpu_set_t *set = CPU_ALLOC(nCPUs);
