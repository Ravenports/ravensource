--- src/hotspot/share/runtime/os.cpp.orig	2023-10-15 00:46:12 UTC
+++ src/hotspot/share/runtime/os.cpp
@@ -858,7 +858,7 @@ bool os::print_function_and_library_name
   //  is worse than (raw) C-heap allocation in that case).
   char* p = buf;
   if (p == NULL) {
-    p = (char*)::alloca(O_BUFLEN);
+    p = (char*)__builtin_alloca(O_BUFLEN);
     buflen = O_BUFLEN;
   }
   int offset = 0;
