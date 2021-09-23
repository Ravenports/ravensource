--- Source/WTF/wtf/unix/MemoryPressureHandlerUnix.cpp.orig	2021-09-01 09:16:49 UTC
+++ Source/WTF/wtf/unix/MemoryPressureHandlerUnix.cpp
@@ -28,7 +28,11 @@
 #include "config.h"
 #include <wtf/MemoryPressureHandler.h>
 
+#if OS(FREEBSD) || defined(__DragonFly__)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <unistd.h>
 #include <wtf/Logging.h>
 #include <wtf/MainThread.h>
@@ -37,7 +41,7 @@
 
 #if OS(LINUX)
 #include <wtf/linux/CurrentProcessMemoryStatus.h>
-#elif OS(FREEBSD)
+#elif OS(FREEBSD) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <sys/user.h>
@@ -112,7 +116,7 @@ static size_t processMemoryUsage()
     ProcessMemoryStatus memoryStatus;
     currentProcessMemoryStatus(memoryStatus);
     return (memoryStatus.resident - memoryStatus.shared);
-#elif OS(FREEBSD)
+#elif OS(FREEBSD) || defined(__DragonFly__)
     static size_t pageSize = sysconf(_SC_PAGE_SIZE);
     struct kinfo_proc info;
     size_t infolen = sizeof(info);
@@ -126,7 +130,11 @@ static size_t processMemoryUsage()
     if (sysctl(mib, 4, &info, &infolen, nullptr, 0))
         return 0;
 
+# ifdef __DragonFly__
+    return static_cast<size_t>(info.kp_vm_rssize - info.kp_vm_tsize) * pageSize;
+# else
     return static_cast<size_t>(info.ki_rssize - info.ki_tsize) * pageSize;
+# endif
 #else
 #error "Missing a platform specific way of determining the memory usage"
 #endif
