--- Source/WTF/wtf/RAMSize.cpp.orig	2025-02-25 08:25:40 UTC
+++ Source/WTF/wtf/RAMSize.cpp
@@ -31,7 +31,7 @@
 #if OS(WINDOWS)
 #include <windows.h>
 #elif USE(SYSTEM_MALLOC)
-#if OS(LINUX) || OS(FREEBSD)
+#if !defined(__DragonFly__) && !OS(FREEBSD) && OS(LINUX)
 #include <sys/sysinfo.h>
 #elif OS(UNIX) || OS(HAIKU)
 #include <unistd.h>
@@ -60,7 +60,7 @@ static size_t computeRAMSize()
         return ramSizeGuess;
     return status.ullTotalPhys;
 #elif USE(SYSTEM_MALLOC)
-#if OS(LINUX) || OS(FREEBSD)
+#if !defined(__DragonFly__) && !OS(FREEBSD) && OS(LINUX)
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
