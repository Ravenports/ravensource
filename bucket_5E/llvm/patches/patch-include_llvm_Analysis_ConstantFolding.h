$NetBSD: patch-include_llvm_Analysis_ConstantFolding.h,v 1.1 2019/01/26 21:17:20 tnn Exp $

Fix SunOS CS conflict not handled by include/llvm-c/DataTypes.h

--- include/llvm/Analysis/ConstantFolding.h.orig	2025-12-01 12:58:50 UTC
+++ include/llvm/Analysis/ConstantFolding.h
@@ -22,6 +22,10 @@
 #include "llvm/Support/Compiler.h"
 #include <stdint.h>
 
+#ifdef __sun
+#undef CS
+#endif
+
 namespace llvm {
 
 namespace Intrinsic {
