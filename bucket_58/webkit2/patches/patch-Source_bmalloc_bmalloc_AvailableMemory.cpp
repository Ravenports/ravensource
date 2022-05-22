--- Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2022-02-23 11:41:53 UTC
+++ Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -44,7 +44,6 @@
 #import <mach/mach_error.h>
 #import <math.h>
 #elif BOS(UNIX)
-#include <sys/sysinfo.h>
 #if BOS(LINUX)
 #include <algorithm>
 #include <fcntl.h>
@@ -159,6 +158,12 @@ static size_t computeAvailableMemory()
     // Round up the memory size to a multiple of 128MB because max_mem may not be exactly 512MB
     // (for example) and we have code that depends on those boundaries.
     return ((sizeAccordingToKernel + multiple - 1) / multiple) * multiple;
+#elif defined(__DragonFly__)
+    long pages = sysconf(_SC_PHYS_PAGES);
+    long pageSize = sysconf(_SC_PAGE_SIZE);
+    if (pages == -1 || pageSize == -1)
+        return availableMemoryGuess;
+    return pages * pageSize;
 #elif BOS(FREEBSD) || BOS(LINUX)
     struct sysinfo info;
     if (!sysinfo(&info))
@@ -210,7 +215,11 @@ MemoryStatus memoryStatus()
 
     size_t memoryFootprint = 0;
     if (!sysctl(mib, 4, &info, &infolen, nullptr, 0))
+# ifdef __DragonFly__
+        memoryFootprint = static_cast<size_t>(info.kp_vm_rssize) * vmPageSize();
+# else
         memoryFootprint = static_cast<size_t>(info.ki_rssize) * vmPageSize();
+# endif
 #endif
 
     double percentInUse = static_cast<double>(memoryFootprint) / static_cast<double>(availableMemory());
