--- src/util/exe_path.cc.orig	2020-08-12 19:30:44 UTC
+++ src/util/exe_path.cc
@@ -15,7 +15,7 @@
 #include <windows.h>
 
 #include "base/win/win_util.h"
-#elif defined(OS_FREEBSD)
+#elif defined(OS_FREEBSD) || defined(OS_DRAGONFLY)
 #include <limits.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
@@ -57,7 +57,7 @@ base::FilePath GetExePath() {
   return base::FilePath(system_buffer);
 }
 
-#elif defined(OS_FREEBSD)
+#elif defined(OS_FREEBSD) || defined(OS_DRAGONFLY)
 
 base::FilePath GetExePath() {
   int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
