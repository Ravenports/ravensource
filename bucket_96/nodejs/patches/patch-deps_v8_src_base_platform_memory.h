--- deps/v8/src/base/platform/memory.h.orig	2023-01-05 21:23:27 UTC
+++ deps/v8/src/base/platform/memory.h
@@ -20,10 +20,12 @@
 #if V8_OS_DARWIN
 #include <malloc/malloc.h>
 #else  // !V8_OS_DARWIN
+# if !V8_OS_FREEBSD && !V8_OS_DRAGONFLYBSD
 #include <malloc.h>
+# endif
 #endif  // !V8_OS_DARWIN
 
-#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS) || V8_OS_WIN
+#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_DRAGONFLYBSD && !V8_OS_FREEBSD && !V8_OS_NETBSD) || V8_OS_WIN
 #define V8_HAS_MALLOC_USABLE_SIZE 1
 #endif  // (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS) || V8_OS_WIN
 
