--- lib/Basic/Targets/OSTargets.h.orig	2024-10-29 10:09:39 UTC
+++ lib/Basic/Targets/OSTargets.h
@@ -187,6 +187,7 @@ protected:
     if (CCVersion == 0U)
       CCVersion = Release * 100000U + 1U;
 
+//  Builder.defineMacro("__MidnightBSD__", "3");
     Builder.defineMacro("__FreeBSD__", Twine(Release));
     Builder.defineMacro("__FreeBSD_cc_version", Twine(CCVersion));
     Builder.defineMacro("__KPRINTF_ATTRIBUTE__");
