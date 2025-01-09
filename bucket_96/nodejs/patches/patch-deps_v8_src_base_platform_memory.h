--- deps/v8/src/base/platform/memory.h.orig	2025-01-07 13:00:22 UTC
+++ deps/v8/src/base/platform/memory.h
@@ -21,11 +21,13 @@
 #include <malloc/malloc.h>
 #elif V8_OS_ZOS
 #include <stdlib.h>
+#elif V8_OS_FREEBSD || V8_OS_DRAGONFLYBSD
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
 
-#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS) || V8_OS_WIN
+#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_DRAGONFLYBSD && !V8_OS_FREEBSD && !V8_OS_NETBSD) || V8_OS_WIN
 #define V8_HAS_MALLOC_USABLE_SIZE 1
 #endif
 
