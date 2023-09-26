--- Source/WTF/wtf/FastMalloc.cpp.orig	2023-08-09 08:49:39 UTC
+++ Source/WTF/wtf/FastMalloc.cpp
@@ -189,7 +189,11 @@ void* fastAlignedMalloc(size_t alignment
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
@@ -199,7 +203,11 @@ void* tryFastAlignedMalloc(size_t alignm
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
 
