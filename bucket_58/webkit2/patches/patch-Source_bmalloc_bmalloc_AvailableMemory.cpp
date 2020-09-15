--- Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2020-08-12 09:17:57 UTC
+++ Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -47,6 +47,12 @@
 #if BOS(LINUX)
 #include <algorithm>
 #include <fcntl.h>
+#elif defined(__DragonFly__)
+#include "VMAllocate.h"
+#include <sys/sysctl.h>
+#include <sys/kinfo.h>
+#include <sys/types.h>
+#include <sys/user.h>
 #elif BOS(FREEBSD)
 #include "VMAllocate.h"
 #include <sys/sysctl.h>
@@ -169,7 +175,7 @@ static size_t computeAvailableMemory()
     return ((sizeAccordingToKernel + multiple - 1) / multiple) * multiple;
 #elif BOS(LINUX)
     return LinuxMemory::singleton().availableMemory;
-#elif BOS(FREEBSD)
+#elif BOS(FREEBSD) && !defined(__DragonFly__)
     struct sysinfo info;
     if (!sysinfo(&info))
         return info.totalram * info.mem_unit;
@@ -223,7 +229,11 @@ MemoryStatus memoryStatus()
 
     size_t memoryFootprint = 0;
     if (!sysctl(mib, 4, &info, &infolen, nullptr, 0))
+# ifdef __DragonFly__
+        memoryFootprint = static_cast<size_t>(info.kp_vm_rssize) * vmPageSize();
+# else
         memoryFootprint = static_cast<size_t>(info.ki_rssize) * vmPageSize();
+# endif
 
     double percentInUse = static_cast<double>(memoryFootprint) / static_cast<double>(availableMemory());
 #endif
