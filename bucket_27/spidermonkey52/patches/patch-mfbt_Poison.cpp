--- ../../mfbt/Poison.cpp.orig	2017-04-11 02:13:16 UTC
+++ ../../mfbt/Poison.cpp
@@ -129,11 +129,15 @@ ReleaseRegion(void* aRegion, uintptr_t a
 static bool
 ProbeRegion(uintptr_t aRegion, uintptr_t aSize)
 {
+#ifdef __sun__   //not easily available on Solaris 10
+  return false;
+#else
   if (madvise(reinterpret_cast<void*>(aRegion), aSize, MADV_NORMAL)) {
     return true;
   } else {
     return false;
   }
+#endif
 }
 
 static uintptr_t
