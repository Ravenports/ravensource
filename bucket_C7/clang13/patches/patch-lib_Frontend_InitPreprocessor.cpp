--- lib/Frontend/InitPreprocessor.cpp.orig	2022-01-20 21:31:59 UTC
+++ lib/Frontend/InitPreprocessor.cpp
@@ -661,7 +661,8 @@ static void InitializePredefinedMacros(c
     Builder.defineMacro("__GNUC__", Twine(GNUCMajor));
     Builder.defineMacro("__GNUC_MINOR__", Twine(GNUCMinor));
     Builder.defineMacro("__GNUC_PATCHLEVEL__", Twine(GNUCPatch));
-    Builder.defineMacro("__GXX_ABI_VERSION", "1002");
+    // match ABI of Ravenports GCC compiler
+    Builder.defineMacro("__GXX_ABI_VERSION", "1013");
 
     if (LangOpts.CPlusPlus) {
       Builder.defineMacro("__GNUG__", Twine(GNUCMajor));
