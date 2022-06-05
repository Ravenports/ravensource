--- Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2022-02-23 11:41:53 UTC
+++ Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -44,8 +44,8 @@
 #import <mach/mach_error.h>
 #import <math.h>
 #elif BOS(UNIX)
-#include <sys/sysinfo.h>
 #if BOS(LINUX)
+#include <sys/sysinfo.h>
 #include <algorithm>
 #include <fcntl.h>
 #elif BOS(FREEBSD)
@@ -159,7 +159,13 @@ static size_t computeAvailableMemory()
     // Round up the memory size to a multiple of 128MB because max_mem may not be exactly 512MB
     // (for example) and we have code that depends on those boundaries.
     return ((sizeAccordingToKernel + multiple - 1) / multiple) * multiple;
-#elif BOS(FREEBSD) || BOS(LINUX)
+#elif BOS(FREEBSD)
+    long pages = sysconf(_SC_PHYS_PAGES);
+    long pageSize = sysconf(_SC_PAGE_SIZE);
+    if (pages == -1 || pageSize == -1)
+        return availableMemoryGuess;
+    return pages * pageSize;
+#elif BOS(LINUX)
     struct sysinfo info;
     if (!sysinfo(&info))
         return info.totalram * info.mem_unit;
@@ -210,7 +216,11 @@ MemoryStatus memoryStatus()
 
     size_t memoryFootprint = 0;
     if (!sysctl(mib, 4, &info, &infolen, nullptr, 0))
+# ifdef __DragonFly__
+        memoryFootprint = static_cast<size_t>(info.kp_vm_rssize) * vmPageSize();
+# else
         memoryFootprint = static_cast<size_t>(info.ki_rssize) * vmPageSize();
+# endif
 #endif
 
     double percentInUse = static_cast<double>(memoryFootprint) / static_cast<double>(availableMemory());
