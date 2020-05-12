--- IlmImf/ImfSystemSpecific.h.orig	2020-05-11 15:53:42 UTC
+++ IlmImf/ImfSystemSpecific.h
@@ -59,6 +59,8 @@ EXRAllocAligned (size_t size, size_t ali
     return _aligned_malloc (size, alignment);
 #elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
     return _mm_malloc (size, alignment);
+#elif defined(__sun)
+    return memalign(alignment, size);
 #elif defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)
     void* ptr = 0;
     // With fortify_source on, just doing the (void) cast trick
