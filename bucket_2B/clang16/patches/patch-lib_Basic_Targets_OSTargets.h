--- lib/Basic/Targets/OSTargets.h.orig	2023-06-10 22:58:16 UTC
+++ lib/Basic/Targets/OSTargets.h
@@ -437,12 +437,22 @@ protected:
     Builder.defineMacro("__ELF__");
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
 
