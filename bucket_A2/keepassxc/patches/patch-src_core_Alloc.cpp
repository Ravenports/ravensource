--- src/core/Alloc.cpp.orig	2024-06-19 21:32:55 UTC
+++ src/core/Alloc.cpp
@@ -20,7 +20,7 @@
 #include <cstdlib>
 #if defined(Q_OS_MACOS)
 #include <malloc/malloc.h>
-#elif defined(Q_OS_FREEBSD)
+#elif defined(__FreeBSD__)
 #include <malloc_np.h>
 #elif defined(HAVE_MALLOC_H)
 #include <malloc.h>
