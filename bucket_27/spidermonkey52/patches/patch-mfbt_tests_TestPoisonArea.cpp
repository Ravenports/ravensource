--- ../../mfbt/tests/TestPoisonArea.cpp.orig	2017-04-11 02:13:17 UTC
+++ ../../mfbt/tests/TestPoisonArea.cpp
@@ -266,7 +266,11 @@ ReleaseRegion(void* aPage)
 static bool
 ProbeRegion(uintptr_t aPage)
 {
+#ifdef __sun__
+  return false;
+#else
   return !!madvise(reinterpret_cast<void*>(aPage), PageSize(), MADV_NORMAL);
+#endif
 }
 
 static int
