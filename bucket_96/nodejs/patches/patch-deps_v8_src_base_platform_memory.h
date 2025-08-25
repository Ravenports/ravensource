--- deps/v8/src/base/platform/memory.h.orig	2025-08-14 20:34:24 UTC
+++ deps/v8/src/base/platform/memory.h
@@ -21,14 +21,16 @@
 #include <malloc/malloc.h>
 #elif V8_OS_OPENBSD
 #include <sys/malloc.h>
-#elif V8_OS_ZOS
+#elif V8_OS_ZOS || V8_OS_FREEBSD || V8_OS_DRAGONFLYBSD
 #include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
 
 #if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_OPENBSD) || V8_OS_WIN
+# if !V8_OS_DRAGONFLYBSD && !V8_OS_FREEBSD && !V8_OS_NETBSD
 #define V8_HAS_MALLOC_USABLE_SIZE 1
+# endif
 #endif
 
 namespace v8::base {
