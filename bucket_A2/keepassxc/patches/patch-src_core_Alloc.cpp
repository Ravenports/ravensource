--- src/core/Alloc.cpp.orig	2022-04-06 03:12:34 UTC
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
