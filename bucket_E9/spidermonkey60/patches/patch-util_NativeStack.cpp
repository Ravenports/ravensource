--- util/NativeStack.cpp.orig	2019-09-01 13:09:39 UTC
+++ util/NativeStack.cpp
@@ -30,7 +30,7 @@ void* js::GetNativeStackBaseImpl() {
   return static_cast<void*>(pTib->StackBase);
 }
 
-#elif defined(SOLARIS)
+#elif defined(__sun__)
 
 #include <ucontext.h>
 
