--- src/core/Alloc.cpp.orig	2019-05-31 20:03:47 UTC
+++ src/core/Alloc.cpp
@@ -21,7 +21,7 @@
 #ifdef Q_OS_MACOS
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #if defined(NDEBUG) && !defined(__cpp_sized_deallocation)
@@ -61,8 +61,6 @@ void operator delete(void* ptr) noexcept
     ::operator delete(ptr, _msize(ptr));
 #elif defined(Q_OS_MACOS)
     ::operator delete(ptr, malloc_size(ptr));
-#elif defined(Q_OS_UNIX)
-    ::operator delete(ptr, malloc_usable_size(ptr));
 #else
     // whatever OS this is, give up and simply free stuff
     std::free(ptr);
