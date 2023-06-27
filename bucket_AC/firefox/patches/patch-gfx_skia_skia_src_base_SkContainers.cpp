DragonFly eventually gets malloc_usable_size, check again when sysroot updates

--- gfx/skia/skia/src/base/SkContainers.cpp.orig	2023-06-08 22:09:35 UTC
+++ gfx/skia/skia/src/base/SkContainers.cpp
@@ -14,7 +14,7 @@
 
 #if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
 #include <malloc/malloc.h>
-#elif defined(SK_BUILD_FOR_ANDROID) || (defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__))
+#elif defined(SK_BUILD_FOR_ANDROID) || (defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__) && !defined(__DragonFly__) && !defined(__FreeBSD__))
 #include <malloc.h>
 #elif defined(SK_BUILD_FOR_WIN)
 #include <malloc.h>
@@ -38,7 +38,7 @@ SkSpan<std::byte> complete_size(void* pt
     #elif defined(SK_BUILD_FOR_ANDROID) && __ANDROID_API__ >= 17
         completeSize = malloc_usable_size(ptr);
         SkASSERT(completeSize >= size);
-    #elif defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__)
+    #elif defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__) && !defined(__DragonFly__) && !defined(__FreeBSD__)
         completeSize = malloc_usable_size(ptr);
         SkASSERT(completeSize >= size);
     #elif defined(SK_BUILD_FOR_WIN)
