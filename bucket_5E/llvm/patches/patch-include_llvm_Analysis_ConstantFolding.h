$NetBSD: patch-include_llvm_Analysis_ConstantFolding.h,v 1.1 2019/01/26 21:17:20 tnn Exp $

Fix SunOS CS conflict not handled by include/llvm-c/DataTypes.h

--- include/llvm/Analysis/ConstantFolding.h.orig	2025-01-14 09:41:02 UTC
+++ include/llvm/Analysis/ConstantFolding.h
@@ -21,6 +21,10 @@
 
 #include <stdint.h>
 
+#ifdef __sun
+#undef CS
+#endif
+
 namespace llvm {
 
 namespace Intrinsic {
