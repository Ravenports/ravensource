--- ../../mfbt/Poison.cpp.orig	2019-09-01 13:09:47 UTC
+++ ../../mfbt/Poison.cpp
@@ -105,9 +105,9 @@ static void ReleaseRegion(void* aRegion,
 }
 
 static bool ProbeRegion(uintptr_t aRegion, uintptr_t aSize) {
-#ifdef XP_SOLARIS
-  if (posix_madvise(reinterpret_cast<void*>(aRegion), aSize,
-                    POSIX_MADV_NORMAL)) {
+#ifdef __sun__
+  //if (madvise(reinterpret_cast<caddr_t>(aRegion), aSize, MADV_NORMAL)) {
+  if (1) {
 #else
   if (madvise(reinterpret_cast<void*>(aRegion), aSize, MADV_NORMAL)) {
 #endif
