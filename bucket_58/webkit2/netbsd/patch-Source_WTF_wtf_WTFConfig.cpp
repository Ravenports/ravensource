--- Source/WTF/wtf/WTFConfig.cpp.orig	2026-02-23 14:40:54 UTC
+++ Source/WTF/wtf/WTFConfig.cpp
@@ -43,12 +43,6 @@
 #include "unistd.h"
 #endif
 
-#if defined(__has_include)
-#if __has_include(<libproc.h>)
-#include <libproc.h>
-#endif // __has_include(<libproc.h>)
-#endif // defined(__has_include)
-
 #if PLATFORM(COCOA)
 #include <wtf/spi/cocoa/MachVMSPI.h>
 #include <mach/mach.h>
