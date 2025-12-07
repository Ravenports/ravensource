--- Source/ThirdParty/skia/src/ports/SkMemory_malloc.cpp.orig	2025-08-11 07:56:53 UTC
+++ Source/ThirdParty/skia/src/ports/SkMemory_malloc.cpp
@@ -16,7 +16,11 @@
 #if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
 #include <malloc/malloc.h>
 #elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX)
+# if defined(__FreeBSD__)
+#include <malloc_np.h>
+# elif !defined(__DragonFly__)
 #include <malloc.h>
+# endif
 #elif defined(SK_BUILD_FOR_WIN)
 #include <malloc.h>
 #endif
@@ -123,6 +127,8 @@ size_t sk_malloc_size(void* addr, size_t
     #if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
         // TODO: remove the max, when the chrome implementation of malloc_size doesn't return 0.
         completeSize = std::max(malloc_size(addr), size);
+    #elif defined(__NetBSD__)
+	// leave completeSize == size
     #elif defined(SK_BUILD_FOR_ANDROID) && __ANDROID_API__ >= 17
         completeSize = malloc_usable_size(addr);
         SkASSERT(completeSize >= size);
