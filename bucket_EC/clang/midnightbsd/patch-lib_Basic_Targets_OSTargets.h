--- lib/Basic/Targets/OSTargets.h.intermediate	2023-08-20 02:18:42 UTC
+++ lib/Basic/Targets/OSTargets.h
@@ -218,6 +218,7 @@ protected:
     if (CCVersion == 0U)
       CCVersion = Release * 100000U + 1U;
 
+    Builder.defineMacro("__MidnightBSD__", "3");
     Builder.defineMacro("__FreeBSD__", Twine(Release));
     Builder.defineMacro("__FreeBSD_cc_version", Twine(CCVersion));
     Builder.defineMacro("__KPRINTF_ATTRIBUTE__");
