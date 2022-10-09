--- Source/WTF/wtf/FastMalloc.cpp.orig	2022-09-14 11:58:10 UTC
+++ Source/WTF/wtf/FastMalloc.cpp
@@ -201,7 +201,11 @@ void* fastAlignedMalloc(size_t alignment
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
@@ -211,7 +215,11 @@ void* tryFastAlignedMalloc(size_t alignm
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
 
