$NetBSD: patch-include_llvm_Analysis_ConstantFolding.h,v 1.1 2019/01/26 21:17:20 tnn Exp $

Fix SunOS CS conflict not handled by include/llvm-c/DataTypes.h

--- include/llvm/Analysis/ConstantFolding.h.orig	2021-04-06 16:38:18 UTC
+++ include/llvm/Analysis/ConstantFolding.h
@@ -19,6 +19,10 @@
 #ifndef LLVM_ANALYSIS_CONSTANTFOLDING_H
 #define LLVM_ANALYSIS_CONSTANTFOLDING_H
 
+#ifdef __sun
+#undef CS
+#endif
+
 namespace llvm {
 class APInt;
 template <typename T> class ArrayRef;
