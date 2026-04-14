--- Source/ZenLib/Thread.cpp.orig	2026-04-14 13:28:54 UTC
+++ Source/ZenLib/Thread.cpp
@@ -4,6 +4,7 @@
  *  be found in the License.txt file in the root of the source tree.
  */
 
+#include <cstdint>
 //---------------------------------------------------------------------------
 #include "ZenLib/PreComp.h"
 #ifdef __BORLANDC__
@@ -519,7 +520,7 @@ Thread::returnvalue Thread::ForceTermina
 {
     //Terminating (not clean)
     #if !defined(__ANDROID_API__)
-    pthread_cancel((pthread_t)ThreadPointer);
+    pthread_cancel((pthread_t)(uintptr_t)ThreadPointer);
     #endif
 
     //Configuring
