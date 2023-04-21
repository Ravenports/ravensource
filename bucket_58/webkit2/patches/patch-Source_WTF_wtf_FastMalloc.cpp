--- Source/WTF/wtf/FastMalloc.cpp.orig	2023-02-20 11:57:18 UTC
+++ Source/WTF/wtf/FastMalloc.cpp
@@ -205,7 +205,11 @@ void* fastAlignedMalloc(size_t alignment
 {
     ASSERT_IS_WITHIN_LIMIT(size);
     void* p = nullptr;
+#ifdef __sun__
+    p = memalign(alignment, size);
+#else
     posix_memalign(&p, alignment, size);
+#endif
     if (UNLIKELY(!p))
         CRASH();
     return p;
@@ -215,7 +219,11 @@ void* tryFastAlignedMalloc(size_t alignm
 {
     FAIL_IF_EXCEEDS_LIMIT(size);
     void* p = nullptr;
+#ifdef __sun__
+    p = memalign(alignment, size);
+#else
     posix_memalign(&p, alignment, size);
+#endif
     return p;
 }
 
