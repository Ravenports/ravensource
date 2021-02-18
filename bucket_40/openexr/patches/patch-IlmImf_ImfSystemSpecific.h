--- IlmImf/ImfSystemSpecific.h.orig	2021-02-12 16:56:19 UTC
+++ IlmImf/ImfSystemSpecific.h
@@ -74,6 +74,8 @@ EXRAllocAligned (size_t size, size_t ali
     return _aligned_malloc (size, alignment);
 #elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
     return _mm_malloc (size, alignment);
+#elif defined(__sun)
+    return memalign(alignment, size);
 #elif defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)
     void* ptr = 0;
     // With fortify_source on, just doing the (void) cast trick
