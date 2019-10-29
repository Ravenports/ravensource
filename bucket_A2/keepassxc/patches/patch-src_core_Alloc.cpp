--- src/core/Alloc.cpp.orig	2019-10-26 19:34:32 UTC
+++ src/core/Alloc.cpp
@@ -21,10 +21,10 @@
 #include <sodium.h>
 #if defined(Q_OS_MACOS)
 #include <malloc/malloc.h>
-#elif defined(Q_OS_FREEBSD)
+#elif defined(__FreeBSD__)
 #include <malloc_np.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #if defined(NDEBUG) && !defined(__cpp_sized_deallocation)
@@ -64,8 +64,6 @@ void operator delete(void* ptr) noexcept
     ::operator delete(ptr, _msize(ptr));
 #elif defined(Q_OS_MACOS)
     ::operator delete(ptr, malloc_size(ptr));
-#elif defined(Q_OS_UNIX)
-    ::operator delete(ptr, malloc_usable_size(ptr));
 #else
     // whatever OS this is, give up and simply free stuff
     std::free(ptr);
