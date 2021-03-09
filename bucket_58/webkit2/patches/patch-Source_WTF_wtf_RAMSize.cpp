--- Source/WTF/wtf/RAMSize.cpp.orig	2020-08-12 09:17:54 UTC
+++ Source/WTF/wtf/RAMSize.cpp
@@ -34,6 +34,9 @@
 #if OS(LINUX)
 #include <sys/sysinfo.h>
 #endif // OS(LINUX)
+# ifdef __sun__
+# include <unistd.h>
+# endif
 #else
 #include <bmalloc/bmalloc.h>
 #endif
@@ -58,6 +61,8 @@ static size_t computeRAMSize()
     struct sysinfo si;
     sysinfo(&si);
     return si.totalram * si.mem_unit;
+#elif defined __sun__
+    return (sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE));
 #else
 #error "Missing a platform specific way of determining the available RAM"
 #endif // OS(LINUX) || OS(FREEBSD)
