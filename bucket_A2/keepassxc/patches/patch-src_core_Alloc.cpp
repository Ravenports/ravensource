--- src/core/Alloc.cpp.orig	2020-01-04 14:09:38 UTC
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
