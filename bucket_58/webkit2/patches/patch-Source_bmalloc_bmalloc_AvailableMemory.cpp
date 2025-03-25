--- Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2025-02-25 08:25:42 UTC
+++ Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -44,7 +44,7 @@
 #import <mach/mach_error.h>
 #import <math.h>
 #elif BOS(UNIX)
-#if BOS(FREEBSD) || BOS(LINUX)
+#if BOS(LINUX)
 #include <sys/sysinfo.h>
 #endif
 #if BOS(LINUX)
@@ -161,7 +161,13 @@ static size_t computeAvailableMemory()
     // Round up the memory size to a multiple of 128MB because max_mem may not be exactly 512MB
     // (for example) and we have code that depends on those boundaries.
     return ((sizeAccordingToKernel + multiple - 1) / multiple) * multiple;
-#elif BOS(FREEBSD) || BOS(LINUX)
+#elif BOS(FREEBSD) || defined(__MidnightBSD__)
+    long pages = sysconf(_SC_PHYS_PAGES);
+    long pageSize = sysconf(_SC_PAGE_SIZE);
+    if (pages == -1 || pageSize == -1)
+        return availableMemoryGuess;
+    return pages * pageSize;
+#elif BOS(LINUX)
     struct sysinfo info;
     if (!sysinfo(&info))
         return info.totalram * info.mem_unit;
@@ -212,7 +218,11 @@ MemoryStatus memoryStatus()
 
     size_t memoryFootprint = 0;
     if (!sysctl(mib, 4, &info, &infolen, nullptr, 0))
+# ifdef __DragonFly__
+        memoryFootprint = static_cast<size_t>(info.kp_vm_rssize) * vmPageSize();
+# else
         memoryFootprint = static_cast<size_t>(info.ki_rssize) * vmPageSize();
+# endif
 #endif
 
     double percentInUse = static_cast<double>(memoryFootprint) / static_cast<double>(availableMemory());
