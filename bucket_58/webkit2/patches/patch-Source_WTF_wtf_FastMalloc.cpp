--- Source/WTF/wtf/FastMalloc.cpp.orig	2020-08-12 09:17:54 UTC
+++ Source/WTF/wtf/FastMalloc.cpp
@@ -160,7 +160,11 @@ void* fastAlignedMalloc(size_t alignment
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
@@ -170,7 +174,11 @@ void* tryFastAlignedMalloc(size_t alignm
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
 
