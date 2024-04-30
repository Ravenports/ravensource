--- src/hotspot/share/runtime/os.cpp.orig	2024-04-29 14:34:19 UTC
+++ src/hotspot/share/runtime/os.cpp
@@ -854,7 +854,7 @@ bool os::print_function_and_library_name
   //  is worse than (raw) C-heap allocation in that case).
   char* p = buf;
   if (p == nullptr) {
-    p = (char*)::alloca(O_BUFLEN);
+    p = (char*)__builtin_alloca(O_BUFLEN);
     buflen = O_BUFLEN;
   }
   int offset = 0;
