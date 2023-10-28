--- lib/Basic/Targets/OSTargets.h.orig	2023-10-17 06:20:52 UTC
+++ lib/Basic/Targets/OSTargets.h
@@ -213,6 +213,7 @@ protected:
     if (CCVersion == 0U)
       CCVersion = Release * 100000U + 1U;
 
+//  Builder.defineMacro("__MidnightBSD__", "3");
     Builder.defineMacro("__FreeBSD__", Twine(Release));
     Builder.defineMacro("__FreeBSD_cc_version", Twine(CCVersion));
     Builder.defineMacro("__KPRINTF_ATTRIBUTE__");
@@ -425,12 +426,22 @@ protected:
     Builder.defineMacro("__unix__");
     if (Opts.POSIXThreads)
       Builder.defineMacro("_REENTRANT");
+    if (this->HasFloat128)
+      Builder.defineMacro("__FLOAT128__");
   }
 
 public:
   NetBSDTargetInfo(const llvm::Triple &Triple, const TargetOptions &Opts)
       : OSTargetInfo<Target>(Triple, Opts) {
     this->MCountName = "__mcount";
+    switch (Triple.getArch()) {
+    default:
+      break;
+    case llvm::Triple::x86:
+    case llvm::Triple::x86_64:
+      this->HasFloat128 = true;
+      break;
+    }
   }
 };
 
