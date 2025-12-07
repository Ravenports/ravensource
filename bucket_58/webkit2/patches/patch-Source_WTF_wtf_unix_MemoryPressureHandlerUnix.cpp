--- Source/WTF/wtf/unix/MemoryPressureHandlerUnix.cpp.orig	2025-08-11 07:56:53 UTC
+++ Source/WTF/wtf/unix/MemoryPressureHandlerUnix.cpp
@@ -28,7 +28,11 @@
 #include "config.h"
 #include <wtf/MemoryPressureHandler.h>
 
+#if OS(FREEBSD) || defined(__DragonFly__) || defined(__MidnightBSD__)
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
+#elif OS(FREEBSD) || defined(__DragonFly__) || defined(__MidnightBSD__)
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <sys/user.h>
@@ -115,7 +119,7 @@ static size_t processMemoryUsage()
     ProcessMemoryStatus memoryStatus;
     currentProcessMemoryStatus(memoryStatus);
     return (memoryStatus.resident - memoryStatus.shared);
-#elif OS(FREEBSD)
+#elif OS(FREEBSD) || defined(__DragonFly__) || defined(__MidnightBSD__)
     static size_t pageSize = sysconf(_SC_PAGE_SIZE);
     struct kinfo_proc info;
     size_t infolen = sizeof(info);
@@ -129,7 +133,11 @@ static size_t processMemoryUsage()
     if (sysctl(mib, 4, &info, &infolen, nullptr, 0))
         return 0;
 
+# ifdef __DragonFly__
+    return static_cast<size_t>(info.kp_vm_rssize - info.kp_vm_tsize) * pageSize;
+# else
     return static_cast<size_t>(info.ki_rssize - info.ki_tsize) * pageSize;
+# endif
 #elif OS(QNX)
     int fd = open("/proc/self/ctl", O_RDONLY);
     if (fd == -1)
