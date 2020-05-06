--- IlmImf/ImfSystemSpecific.h.orig	Tue Feb 11 00:01:19 2020
+++ IlmImf/ImfSystemSpecific.h	Wed May  6 20:25:01 2020
@@ -59,6 +59,8 @@
     return _aligned_malloc (size, alignment);
 #elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
     return _mm_malloc (size, alignment);
+#elif defined(__sun)
+    return memalign(alignment, size);
 #elif defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)
     void* ptr = 0;
     // With fortify_source on, just doing the (void) cast trick
