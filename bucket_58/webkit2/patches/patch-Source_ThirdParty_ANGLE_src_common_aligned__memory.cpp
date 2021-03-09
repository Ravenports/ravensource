--- Source/ThirdParty/ANGLE/src/common/aligned_memory.cpp.orig	2020-08-12 09:17:53 UTC
+++ Source/ThirdParty/ANGLE/src/common/aligned_memory.cpp
@@ -33,7 +33,7 @@ void *AlignedAlloc(size_t size, size_t a
 // memalign() on Android returns pointers which can safely be used with
 // free(), so we can use it instead.  Issue filed to document this:
 // http://code.google.com/p/android/issues/detail?id=35391
-#elif defined(ANGLE_PLATFORM_ANDROID)
+#elif defined(ANGLE_PLATFORM_ANDROID) || defined(__sun__)
     ptr = memalign(alignment, size);
 #else
     if (posix_memalign(&ptr, alignment, size))
