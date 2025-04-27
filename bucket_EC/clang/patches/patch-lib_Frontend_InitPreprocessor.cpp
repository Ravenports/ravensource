--- lib/Frontend/InitPreprocessor.cpp.orig	2025-04-16 00:23:49 UTC
+++ lib/Frontend/InitPreprocessor.cpp
@@ -879,7 +879,8 @@ static void InitializePredefinedMacros(c
     Builder.defineMacro("__GNUC__", Twine(GNUCMajor));
     Builder.defineMacro("__GNUC_MINOR__", Twine(GNUCMinor));
     Builder.defineMacro("__GNUC_PATCHLEVEL__", Twine(GNUCPatch));
-    Builder.defineMacro("__GXX_ABI_VERSION", "1002");
+    // match ABI of Ravenports GCC compiler
+    Builder.defineMacro("__GXX_ABI_VERSION", "1013");
 
     if (LangOpts.CPlusPlus) {
       Builder.defineMacro("__GNUG__", Twine(GNUCMajor));
