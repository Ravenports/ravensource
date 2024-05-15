--- port/cpl_multiproc.cpp.orig	2024-05-07 12:53:29 UTC
+++ port/cpl_multiproc.cpp
@@ -1424,7 +1424,11 @@ int CPLGetNumCPUs()
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
