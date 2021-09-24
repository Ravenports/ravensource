--- Source/WTF/wtf/FastMalloc.cpp.orig	2021-03-25 15:14:06 UTC
+++ Source/WTF/wtf/FastMalloc.cpp
@@ -170,7 +170,11 @@ void* fastAlignedMalloc(size_t alignment
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
@@ -180,7 +184,11 @@ void* tryFastAlignedMalloc(size_t alignm
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
 
