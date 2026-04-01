--- lib/Frontend/InitPreprocessor.cpp.orig	2025-12-01 12:58:50 UTC
+++ lib/Frontend/InitPreprocessor.cpp
@@ -886,7 +886,8 @@ static void InitializePredefinedMacros(c
     Builder.defineMacro("__GNUC__", Twine(GNUCMajor));
     Builder.defineMacro("__GNUC_MINOR__", Twine(GNUCMinor));
     Builder.defineMacro("__GNUC_PATCHLEVEL__", Twine(GNUCPatch));
-    Builder.defineMacro("__GXX_ABI_VERSION", "1002");
+    // match ABI of Ravenports GCC compiler
+    Builder.defineMacro("__GXX_ABI_VERSION", "1013");
 
     if (LangOpts.CPlusPlus) {
       Builder.defineMacro("__GNUG__", Twine(GNUCMajor));
