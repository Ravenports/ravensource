--- ../../mfbt/tests/TestPoisonArea.cpp.orig	2019-09-01 13:09:48 UTC
+++ ../../mfbt/tests/TestPoisonArea.cpp
@@ -269,8 +269,9 @@ ReleaseRegion(void* aPage)
 static bool
 ProbeRegion(uintptr_t aPage)
 {
-#ifdef XP_SOLARIS
-  return !!posix_madvise(reinterpret_cast<void*>(aPage), PageSize(), POSIX_MADV_NORMAL);
+#ifdef __sun__
+  //return !!madvise(reinterpret_cast<caddr_t>(aPage), PageSize(), MADV_NORMAL);
+  return !!0;
 #else
   return !!madvise(reinterpret_cast<void*>(aPage), PageSize(), MADV_NORMAL);
 #endif
