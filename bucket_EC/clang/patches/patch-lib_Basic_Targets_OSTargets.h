--- lib/Basic/Targets/OSTargets.h.orig	2025-05-13 22:18:22 UTC
+++ lib/Basic/Targets/OSTargets.h
@@ -209,6 +209,7 @@ protected:
     if (CCVersion == 0U)
       CCVersion = Release * 100000U + 1U;
 
+//  Builder.defineMacro("__MidnightBSD__", "3");
     Builder.defineMacro("__FreeBSD__", Twine(Release));
     Builder.defineMacro("__FreeBSD_cc_version", Twine(CCVersion));
     Builder.defineMacro("__KPRINTF_ATTRIBUTE__");
