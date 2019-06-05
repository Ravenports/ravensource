--- lib/Frontend/InitPreprocessor.cpp.orig	2019-02-12 11:02:43 UTC
+++ lib/Frontend/InitPreprocessor.cpp
@@ -575,7 +575,8 @@ static void InitializePredefinedMacros(c
     Builder.defineMacro("__GNUC_MINOR__", "2");
     Builder.defineMacro("__GNUC_PATCHLEVEL__", "1");
     Builder.defineMacro("__GNUC__", "4");
-    Builder.defineMacro("__GXX_ABI_VERSION", "1002");
+    // match ABI of Ravenports GCC compiler
+    Builder.defineMacro("__GXX_ABI_VERSION", "1013");
   }
 
   // Define macros for the C11 / C++11 memory orderings
