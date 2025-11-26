--- src/core/Alloc.cpp.orig	2025-03-02 22:31:21 UTC
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
