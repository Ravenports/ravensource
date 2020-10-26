--- src/core/Alloc.cpp.orig	2020-10-21 20:47:02 UTC
+++ src/core/Alloc.cpp
@@ -21,7 +21,7 @@
 #include <sodium.h>
 #if defined(Q_OS_MACOS)
 #include <malloc/malloc.h>
-#elif defined(Q_OS_FREEBSD)
+#elif defined(__FreeBSD__)
 #include <malloc_np.h>
 #elif defined(HAVE_MALLOC_H)
 #include <malloc.h>
