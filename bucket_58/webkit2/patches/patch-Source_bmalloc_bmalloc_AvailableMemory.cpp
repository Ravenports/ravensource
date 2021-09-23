Add DragonFly support
FreeBSD 11 doesn't have sysinfo.h like DragonFly doesn't

--- Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2021-09-01 09:16:51 UTC
+++ Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -47,10 +47,15 @@
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
-#include <sys/sysinfo.h>
 #include <sys/types.h>
 #include <sys/user.h>
 #endif
@@ -169,7 +174,7 @@ static size_t computeAvailableMemory()
     return ((sizeAccordingToKernel + multiple - 1) / multiple) * multiple;
 #elif BOS(LINUX)
     return LinuxMemory::singleton().availableMemory;
-#elif BOS(FREEBSD)
+#elif 0
     struct sysinfo info;
     if (!sysinfo(&info))
         return info.totalram * info.mem_unit;
@@ -223,7 +228,11 @@ MemoryStatus memoryStatus()
 
     size_t memoryFootprint = 0;
     if (!sysctl(mib, 4, &info, &infolen, nullptr, 0))
+# ifdef __DragonFly__
+        memoryFootprint = static_cast<size_t>(info.kp_vm_rssize) * vmPageSize();
+# else
         memoryFootprint = static_cast<size_t>(info.ki_rssize) * vmPageSize();
+# endif
 
     double percentInUse = static_cast<double>(memoryFootprint) / static_cast<double>(availableMemory());
 #endif
